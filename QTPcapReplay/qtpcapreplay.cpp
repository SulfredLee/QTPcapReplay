#include "qtpcapreplay.h"

QTPcapReplay::QTPcapReplay(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	/* Connects  */
	m_jobReplay = new JobReplay;
	m_jobReplay->SetPcapReplay(this);
	m_jobReplay->SetUI(&ui);

	//BUTTONACT(ui.removeFileButton, removeFile());
	connect(ui.removeFileButton, SIGNAL(pressed()), this, SLOT(removeFile()));
	connect(ui.exitAppButton, SIGNAL(pressed()), this, SLOT(onFileExit()));
	connect(ui.actionFiles, SIGNAL(triggered()), this, SLOT(onFileOpen()));
	connect(ui.actionFrom_Folder, SIGNAL(triggered()), this, SLOT(onFolderOpen()));
	connect(ui.actionClose, SIGNAL(triggered()), this, SLOT(onFileExit()));
	connect(ui.actionNew_Window, SIGNAL(triggered()), this, SLOT(onNewWindow()));
	connect(ui.actionNew_Window_Dynamic, SIGNAL(triggered()), this, SLOT(onNewWindowDynamic()));
	connect(ui.actionScheduler, SIGNAL(triggered()), this, SLOT(onSchedulerDynamic()));
	connect(ui.startReplayButton, SIGNAL(pressed()), m_jobReplay, SLOT(StartReplay()));
	connect(ui.pauseReplayButton, SIGNAL(pressed()), this, SLOT(onPause()));
	connect(ui.stopReplayButton, SIGNAL(pressed()), this, SLOT(StopPlaying()));
	connect(m_jobReplay, SIGNAL(updateProgress(const int&)), this, SLOT(getProgress(int)));
	connect(m_jobReplay, SIGNAL(updateNextPacketNumber(const QString&)), this, SLOT(getNextPacketNumber(QString)));
	connect(m_jobReplay, SIGNAL(updateCurrentPlayingFile(const QString&)), this, SLOT(getCurStatus(QString)));
	connect(m_jobReplay, SIGNAL(updatePlayingStatus(const bool&)), this, SLOT(updatePlayingStatus(bool)));
	connect(&(m_SchedulerTimer.m_timer), SIGNAL(timeout()), this, SLOT(handleTimeout()));
	connect(&(m_NetSpeedMeasure), SIGNAL(UpdateNetSpeed(double)), this, SLOT(updateNetSpeedMeasure(double)));
	connect(&(m_PacketTimeReportor), SIGNAL(UpdateTimeReport(QString)), this, SLOT(PrintTimeReport(QString)));
	connect(m_jobReplay, SIGNAL(sendMessageBox(const QString&)), this, SLOT(showMessageBox(const QString&)));
	connect(ui.regularReplayButton, SIGNAL(pressed()), m_jobReplay, SLOT(startRegularReplay()));
	connect(m_jobReplay, SIGNAL(updateRegularReplayingStatus(const bool&)), this, SLOT(updateRegularReplayingStatus(bool)));
	connect(m_jobReplay, SIGNAL(sendUpdateRegularButtonText(const QString&)), this, SLOT(updateRegularButtonText(const QString&)));
	connect(ui.actionSave_Config, SIGNAL(triggered()), this, SLOT(save_config_setting()));
	connect(ui.actionLoad_Config, SIGNAL(triggered()), this, SLOT(load_config_setting()));

	ui.progressBar->setValue(0);

	if (InitAdapterName() == 1)
		exit(0);

	m_playerTimer = new PlayerTimer;
	m_threadPool = new threadPool(2);
	m_threadPool->submit(m_playerTimer);

	// Modify display
	ui.curPcapPackage->setText(QString(""));
	ui.StatusReportLabel->setText(QString(""));
	ui.schedulerStatus->setText(QString("Scheduler Stop"));
	ui.schedulerStatus->setStyleSheet("QLabel { background-color : red; color : black; }");
	ui.pauseReplayButton->setDisabled(true);
	ui.stopReplayButton->setDisabled(true);
	ui.offSet_lineEdit->setText("0");
	ui.speed_LineEdit->setText("1");
	ui.netSpeedMon->setText("");
	ui.packetTimeLabel->setText("");

	// Status
	m_bPlaying = false;
	m_bBeforePlay = true;

	
	m_openFilePath = QDir::currentPath();

	// net speed measurement

	// icon
	//m_icon.addFile("C:\NGN2\NGN2011\App\QTPcapReplay\QTPcapReplay\test.bmp");
	//this->setWindowIcon(m_icon);
}

QTPcapReplay::~QTPcapReplay()
{

}

void QTPcapReplay::PrintTimeReport(QString timeReport)
{
	ui.packetTimeLabel->setText(timeReport);
}

void QTPcapReplay::showMessageBox(const QString& line)
{
	QMessageBox::StandardButton reply;
	reply = QMessageBox::warning(this, "Message", line, QMessageBox::Ok);
}

void QTPcapReplay::updateNetSpeedMeasure(double speed)
{
	//std::stringstream line;
	//line
	//	<< left << std::setw(15) << speed
	//	<< left << std::setw(15) << speed * 8
	//	<< left << std::setw(15) << (double)speed / 1000
	//	<< left << std::setw(15) << (double)(speed * 8) / 1000
	//	<< left << std::setw(15) << (double)speed / 1000 / 1000
	//	<< left << std::setw(15) << (double)(speed * 8) / 1000 / 1000 << "\r";
	//line << speed;
	std::string line;
	GetBitPerSec(speed * 8, line, 0);

	ui.netSpeedMon->setText(line.c_str());
}

void QTPcapReplay::GetBitPerSec(double bit, std::string& line, int step)
{
	if (step >= 4)
		return;

	line = std::to_string(bit);
	switch (step)
	{
	case 0:
		line += " Bit/sec";
		break;
	case 1:
		line += " KBit/sec";
		break;
	case 2:
		line += " MBit/sec";
		break;
	case 3:
		line += " GBit/sec";
		break;
	default:
		break;
	}

	int newBit = bit / 1000;
	if (newBit > 0)
		GetBitPerSec(bit / 1000, line, step + 1);
	
}

int QTPcapReplay::InitAdapterName()
{
	
	char errbuff[PCAP_ERRBUF_SIZE];

	/* Retrieve the device list on the local machine */
	if (pcap_findalldevs(&m_alldevs, errbuff) == -1)
	{
		QString line;
		line = QString("%1%2").arg("Error in pcap_findalldevs: ", errbuff);
		QErrorMessage err(this);
		err.showMessage(QString("%1%2").arg("Error in pcap_findalldevs: ", errbuff));

		QMessageBox::StandardButton reply;
		reply = QMessageBox::warning(this, "Message", line, QMessageBox::Ok);
		return -1;
	}

	int numInterFace = 0;
	int numIP = 0;
	bool bHasInterface = false;
	for (m_d = m_alldevs; m_d; m_d = m_d->next)
	{
		bHasInterface = true;
		for (pcap_addr_t *a = m_d->addresses; a != NULL; a = a->next) 
		{
			if (a->addr->sa_family == AF_INET)
			{
				m_NumIP2NumInterFace[numInterFace] = numIP++;

				std::string line;
				std::string interfaceIP;
				interfaceIP = inet_ntoa(((struct sockaddr_in*)a->addr)->sin_addr);
				line += interfaceIP;
				line += " ";

				line += m_d->name;
				line += " ";
				if (m_d->description)
					line += m_d->description;
				else
					line += "(No description available)";

				ui.IPComboBox->addItem(QString::fromStdString(line));


			}
		}
		numInterFace++;
	}

	if (!bHasInterface)
	{
		QString line = "Please try running cmd.exe by administrator.\nType sc start npf\nThen restart this app.";
		QMessageBox::StandardButton reply;
		reply = QMessageBox::warning(this, "Message", line, QMessageBox::Ok);
		return 1;
	}

	return 0;
}
void QTPcapReplay::removeFile()
{
	int i = ui.listWidget->currentRow();
	if (i != -1)
	{
		QListWidgetItem *temp = ui.listWidget->takeItem(i);
		delete temp;
	}
}
void QTPcapReplay::onFileOpen()
{
	QStringList fileNames = QFileDialog::getOpenFileNames(this,
		tr("Open Pcap"), m_openFilePath, tr("Pcap Files (*.pcap)"));
	m_fileNames = fileNames;
	if (fileNames.length() == 0)
		return;

	QFileInfo fileInfo(fileNames.front());
	m_openFilePath = fileInfo.filePath();

	for (int i = 0; i < fileNames.length(); i++)
	{
		ui.listWidget->addItem(fileNames[i]);
	}
	ui.listWidget->setCurrentRow(0);
}
void QTPcapReplay::onItemActivated()
{

}
void QTPcapReplay::onFileExit()
{
	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, "Message", "Quit?",
		QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes) {
		updatePlayingStatus(false);
		while (!m_playerTimer->IsStop())
			Sleep(1);
		QApplication::quit();
	}
}
void QTPcapReplay::onFolderOpen()
{
	QString path = QFileDialog::getExistingDirectory(this, "", m_openFilePath, QFileDialog::ShowDirsOnly);

	if (path == "")
		return;
	m_openFilePath = path;
	QDirIterator it(path, QStringList() << "*.pcap", QDir::Files, QDirIterator::Subdirectories);
	m_fileNames.clear();
	while (it.hasNext())
	{
		m_fileNames.push_back(it.next());

		ui.listWidget->addItem(it.next());
		ui.listWidget->setCurrentRow(0);
	}
}
void QTPcapReplay::onNewWindow()
{
	MYDialog dialog;
	dialog.setModal(true);
	dialog.exec();
}
void QTPcapReplay::onNewWindowDynamic()
{
	MYDialog * pDialog = new MYDialog();
	pDialog->show();
}
void QTPcapReplay::startReplay()
{
	// prepare information for replay
	m_adapterName = GetAdapterName();
	if (SetOutputAdapter() == -1)
		return;
	m_bBeforePlay = false;
	if (ui.speed_LineEdit->text() == "")
	{
		ui.speed_LineEdit->setText(QString::number(1));
	}
	m_speed = std::stod(ui.speed_LineEdit->text().toUtf8().constData());
	if (m_speed <= 0)
	{
		m_speed = 1;
		ui.speed_LineEdit->setText(QString::number(1));
	}
	m_offSet = std::stod(ui.offSet_lineEdit->text().toUtf8().constData());

	
	m_bOnlyFirstFileOffSet = ui.onlyFirstFile_checkbox->isChecked();

	emit m_jobReplay->updatePlayingStatus(true);
	while (m_playerTimer->IsStop())
		Sleep(1);


	for (int i = ui.listWidget->currentRow(); i < ui.listWidget->count(); i++)
	{
		if (i < 0)
			break;
		m_bFirstFileOfReplayList = i == 0 ? true : false;
		if (m_playerTimer->IsStop())
			break;
		QListWidgetItem *item = ui.listWidget->item(i);
		std::string fileName = item->text().toUtf8().constData();
		ui.listWidget->setCurrentRow(i);
		ReplayFile(fileName);
	}
	ui.listWidget->setCurrentRow(0);
	emit m_jobReplay->updatePlayingStatus(false);
}
void QTPcapReplay::startRegularReplay()
{
	// prepare information for replay
	m_adapterName = GetAdapterName();
	if (SetOutputAdapter() == -1)
		return;
	m_bBeforePlay = false;
	if (ui.speed_LineEdit->text() == "")
	{
		ui.speed_LineEdit->setText(QString::number(1));
	}
	// we only do speed as 1 under regular replay
	m_speed = 1;
	ui.speed_LineEdit->setText(QString::number(1));
	m_offSet = std::stod(ui.offSet_lineEdit->text().toUtf8().constData());


	m_bOnlyFirstFileOffSet = ui.onlyFirstFile_checkbox->isChecked();

	emit m_jobReplay->updateRegularReplayingStatus(true);
	while (m_playerTimer->IsStop())
		Sleep(1);


	for (int i = ui.listWidget->currentRow(); i < ui.listWidget->count(); i++)
	{
		if (i < 0)
			break;
		m_bFirstFileOfReplayList = i == 0 ? true : false;
		if (m_playerTimer->IsStop())
			break;
		QListWidgetItem *item = ui.listWidget->item(i);
		std::string fileName = item->text().toUtf8().constData();
		ui.listWidget->setCurrentRow(i);
		RegularReplayFile(fileName);
	}
	ui.listWidget->setCurrentRow(0);
	emit m_jobReplay->updateRegularReplayingStatus(false);
}
int QTPcapReplay::sf_difftime(const tm& first, const tm& second)
{
	int iDiffSec = 0;

	iDiffSec += (first.tm_hour - second.tm_hour) * 3600;
	iDiffSec += (first.tm_min - second.tm_min) * 60;
	iDiffSec += (first.tm_sec - second.tm_sec);

	return iDiffSec;
}
void QTPcapReplay::RegularReplayFile(const std::string& fileName)
{
	char errbuff[PCAP_ERRBUF_SIZE];
	pcap_t * pcap = pcap_open_offline(fileName.c_str(), errbuff);
	if (pcap == NULL)
	{
		//QErrorMessage err(this);
		//char line[1024];
		//sprintf(line, "Error: %s\n", errbuff);
		//err.showMessage(QString(line));
		QString line;
		line = QString("%1%2").arg("Error: ", errbuff);

		emit m_jobReplay->sendMessageBox(line);
		return;
	}

	struct pcap_pkthdr *header;
	const u_char *data;
	double firstArrivalTime;

	UINT32 curFileSize = FileSize(fileName);
	UINT32 curSentSize = PCAPGOBLEHEADERSIZE;
	UINT32 packetCounter = 0;
	int nProgress = -1;

	{
		// update status
		QString line = QString("%1: %2").arg("Now Playing File", fileName.c_str());
		emit m_jobReplay->updateCurrentPlayingFile(line);
	}
	while (int returnValue = pcap_next_ex(pcap, &header, &data) >= 0)
	{
		long m_packetArrivalSec = header->ts.tv_sec;
		long m_packetArrivalmicroseconds = header->ts.tv_usec;
		double arrivalTime = m_packetArrivalSec + m_packetArrivalmicroseconds*0.000001;
		double shiftArrivalTime = arrivalTime;
		
		if (m_bOnlyFirstFileOffSet && m_bFirstFileOfReplayList)
			shiftArrivalTime += m_offSet;
		else if (!m_bOnlyFirstFileOffSet)
			shiftArrivalTime += m_offSet;

		time_t packetArrivalTime = (int)shiftArrivalTime;
		time_t nowTime = time(0);
		tm nowTime_tm = *localtime(&nowTime);
		tm packetArrivalTime_tm = *localtime(&packetArrivalTime);
		
		//char tmbuf[64], buf[64];
		//strftime(tmbuf, sizeof tmbuf, "%Y-%m-%d,%H:%M:%S", &nowTime_tm);
		//strftime(tmbuf, sizeof tmbuf, "%Y-%m-%d,%H:%M:%S", &packetArrivalTime_tm);

		double seconds = sf_difftime(nowTime_tm, packetArrivalTime_tm);
		while (!(seconds < 2 && seconds >= 0)) // we here have a 2 sec buffer
		{
			nowTime = time(0);
			nowTime_tm = *localtime(&nowTime);
			seconds = sf_difftime(nowTime_tm, packetArrivalTime_tm);
			Sleep(1);

			if (!m_jobReplay->IsRegularReplaying())
			{
				emit m_jobReplay->updateProgress((int)(0));
				return;
			}
		}
		if (!m_jobReplay->IsRegularReplaying())
		{
			emit m_jobReplay->updateProgress((int)(0));
			return;
		}

		SendPcaket(header->len, data);
		curSentSize += header->len + PCAPLOCALHEADERSIZE;

		// net speed measurement
		m_NetSpeedMeasure.AddSentLen(header->len);
		// packet time report
		m_PacketTimeReportor.InsertPacketTime(arrivalTime);

		float progress = (float)curSentSize / (float)curFileSize;

		if (nProgress != (int)(progress * 100))
		{
			emit m_jobReplay->updateProgress((int)(progress * 100));
			nProgress++;
		}

		packetCounter++;
	}
	emit m_jobReplay->updateProgress((int)(0));
}
std::ifstream::pos_type QTPcapReplay::FileSize(const std::string& filename)
{
	std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
	return in.tellg();
}
void QTPcapReplay::ReplayFile(const std::string& fileName)
{
	char errbuff[PCAP_ERRBUF_SIZE];
	pcap_t * pcap = pcap_open_offline(fileName.c_str(), errbuff);
	if (pcap == NULL)
	{
		//QErrorMessage err(this);
		//char line[1024];
		//sprintf(line, "Error: %s\n", errbuff);
		//err.showMessage(QString(line));
		QString line;
		line = QString("%1%2").arg("Error: ", errbuff);

		emit m_jobReplay->sendMessageBox(line);
		return;
	}

	struct pcap_pkthdr *header;
	const u_char *data;
	bool isFirstPacket = true;
	double firstArrivalTime;

	UINT32 curFileSize = FileSize(fileName);
	UINT32 curSentSize = PCAPGOBLEHEADERSIZE;
	UINT32 packetCounter = 0;
	double sendEndTime;
	int nProgress = -1;

	{
		// update status
		QString line = QString("%1: %2").arg("Now Playing File", fileName.c_str());
		emit m_jobReplay->updateCurrentPlayingFile(line);
	}
	while (int returnValue = pcap_next_ex(pcap, &header, &data) >= 0)
	{
		long m_packetArrivalSec = header->ts.tv_sec;
		long m_packetArrivalmicroseconds = header->ts.tv_usec;
		double arrivalTime = m_packetArrivalSec + m_packetArrivalmicroseconds*0.000001;

		if (isFirstPacket)
		{
			m_playerTimer->ResetTimer(); // every time we read a new file, we have to reset the playerTimer to zero
			firstArrivalTime = arrivalTime;
			sendEndTime = firstArrivalTime + m_playerTimer->GetCurTime() * m_speed;
			isFirstPacket = false;
		}
		if (m_bOnlyFirstFileOffSet && m_bFirstFileOfReplayList)
			arrivalTime += m_offSet;
		else if (!m_bOnlyFirstFileOffSet)
			arrivalTime += m_offSet;

		bool sentFinish = false;
		UINT32 curPacketPosition = 0;
		while (!sentFinish)
		{
			bool isPaused = false;
			while (m_playerTimer->IsPause())
			{
				isPaused = true;
				if (curPacketPosition != packetCounter)
				{
					curPacketPosition = packetCounter;
				}
				QString line = QString("%1: %2").arg("Next Package", QString::number(curPacketPosition + 1));
				emit m_jobReplay->updateNextPacketNumber(line);
				line = QString("%1: %2").arg("Now Pause, File", fileName.c_str());
				emit m_jobReplay->updateCurrentPlayingFile(line);
				

				// handle change speed during pause
				m_playerTimer->ResetTimer(); // every time we read a new file, we have to reset the playerTimer to zero
				firstArrivalTime = arrivalTime;
				sendEndTime = firstArrivalTime + m_playerTimer->GetCurTime() * m_speed;

				Sleep(1);
				if (m_playerTimer->IsStop())
					return;
			}
			if (isPaused)
			{
				QString line;
				line = QString("%1: %2").arg("Now Playing, File", fileName.c_str());
				emit m_jobReplay->updateCurrentPlayingFile(line);
				emit m_jobReplay->updateNextPacketNumber("");
			}
			if (m_playerTimer->IsStop())
				return;

			if (arrivalTime <= sendEndTime)
			{
				SendPcaket(header->len, data);

				curSentSize += header->len + PCAPLOCALHEADERSIZE;

				// net speed measurement
				m_NetSpeedMeasure.AddSentLen(header->len);
				// packet time report
				m_PacketTimeReportor.InsertPacketTime(arrivalTime);

				float progress = (float)curSentSize / (float)curFileSize;

				if (nProgress != (int)(progress * 100))
				{
					emit m_jobReplay->updateProgress((int)(progress * 100));
					nProgress++;
				}

				packetCounter++;

				sentFinish = true;
			}
			else
			{
				sendEndTime = firstArrivalTime + m_playerTimer->GetCurTime() * m_speed;
				Sleep(1);
			}
		}
	}
	emit m_jobReplay->updateProgress((int)(0));
}
void QTPcapReplay::getNextPacketNumber(QString line)
{
	ui.curPcapPackage->setText(line);
}
void QTPcapReplay::getCurStatus(QString line)
{
	ui.StatusReportLabel->setText(line);
}
void QTPcapReplay::updatePlayingStatus(bool bPlaying)
{
	m_bPlaying = bPlaying;
	if (m_bPlaying)
	{
		ui.startReplayButton->setDisabled(true);
		ui.pauseReplayButton->setDisabled(false);
		ui.stopReplayButton->setDisabled(false);
		ui.removeFileButton->setDisabled(true);
		ui.listWidget->setDisabled(true);
		ui.speed_LineEdit->setDisabled(true);
		ui.IPComboBox->setDisabled(true);
		ui.mainToolBar->setDisabled(true);
		ui.regularReplayButton->setDisabled(true);
		m_playerTimer->SetStop(false);
		ui.offSet_lineEdit->setDisabled(true);
		ui.onlyFirstFile_checkbox->setDisabled(true);
		m_PacketTimeReportor.InsertPacketTime(0);
	}
	else
	{
		ui.startReplayButton->setDisabled(false);
		m_playerTimer->SetStop(true);
		ui.pauseReplayButton->setDisabled(true);
		ui.stopReplayButton->setDisabled(true);
		ui.removeFileButton->setDisabled(false);
		ui.listWidget->setDisabled(false);
		ui.speed_LineEdit->setDisabled(false);
		ui.IPComboBox->setDisabled(false);
		ui.mainToolBar->setDisabled(false);
		ui.offSet_lineEdit->setDisabled(false);
		ui.onlyFirstFile_checkbox->setDisabled(false);
		ui.regularReplayButton->setDisabled(false);
		if (m_Adapter && !m_bBeforePlay)
			pcap_close(m_Adapter);
		if (m_playerTimer->IsPause())
			m_playerTimer->SetPause();
		m_Adapter = NULL;
		ui.progressBar->setValue(0);
		ui.curPcapPackage->setText("");
		ui.StatusReportLabel->setText("");
	}
}
void QTPcapReplay::updateRegularReplayingStatus(bool bPlaying)
{
	m_bPlaying = bPlaying;
	if (m_bPlaying)
	{
		ui.startReplayButton->setDisabled(true);
		ui.pauseReplayButton->setDisabled(true);
		ui.stopReplayButton->setDisabled(true);
		ui.removeFileButton->setDisabled(true);
		ui.listWidget->setDisabled(true);
		ui.speed_LineEdit->setDisabled(true);
		ui.IPComboBox->setDisabled(true);
		ui.mainToolBar->setDisabled(true);
		ui.regularReplayButton->setDisabled(false);
		m_playerTimer->SetStop(false);
		ui.offSet_lineEdit->setDisabled(true);
		ui.onlyFirstFile_checkbox->setDisabled(true);
		m_PacketTimeReportor.InsertPacketTime(0);
	}
	else
	{
		ui.startReplayButton->setDisabled(false);
		m_playerTimer->SetStop(true);
		ui.pauseReplayButton->setDisabled(true);
		ui.stopReplayButton->setDisabled(true);
		ui.removeFileButton->setDisabled(false);
		ui.listWidget->setDisabled(false);
		ui.speed_LineEdit->setDisabled(false);
		ui.IPComboBox->setDisabled(false);
		ui.mainToolBar->setDisabled(false);
		ui.offSet_lineEdit->setDisabled(false);
		ui.onlyFirstFile_checkbox->setDisabled(false);
		ui.regularReplayButton->setDisabled(false);
		if (m_Adapter && !m_bBeforePlay)
			pcap_close(m_Adapter);
		if (m_playerTimer->IsPause())
			m_playerTimer->SetPause();
		m_Adapter = NULL;
		ui.progressBar->setValue(0);
		ui.curPcapPackage->setText("");
		ui.StatusReportLabel->setText("");
	}
}
void QTPcapReplay::StopPlaying()
{
	updatePlayingStatus(false);
}
void QTPcapReplay::save_config_setting()
{	
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), m_openFilePath + QString("untitled.dat"), tr("Config Files (*.dat)"));
	QFileInfo fileInfo(fileName);
	m_openFilePath = fileInfo.filePath();

	QFile file(fileName);
	file.open(QIODevice::WriteOnly);
	QDataStream out(&file);   // we will serialize the data into the file

	out << m_dialogScheduler.GetDate();
	out << m_dialogScheduler.GetTime();
	out << m_dialogScheduler.GetWeeklySelection();
	out << m_dialogScheduler.IsWeeklySchedu();
	out << m_dialogScheduler.IsOneTimeSchedu();
	out << m_dialogScheduler.IsSchedularEnable();
	out << m_fileNames;
	out << m_openFilePath;

	file.close();
}
void QTPcapReplay::load_config_setting()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Config"), m_openFilePath, tr("Config Files (*.dat)"));
	QFileInfo fileInfo(fileName);
	m_openFilePath = fileInfo.filePath();

	QFile file(fileName);
	file.open(QIODevice::ReadOnly);
	QDataStream in(&file);   // we will serialize the data into the file

	QDate tempDate;
	QTime tempTime;
	QVector<bool> tempWeeklySelection;
	bool tempWeeklySchedu, tempOneTimeSchedu, tempSchedularEnable;
	in >> tempDate;
	in >> tempTime;
	in >> tempWeeklySelection;
	in >> tempWeeklySchedu;
	in >> tempOneTimeSchedu;
	in >> tempSchedularEnable;
	in >> m_fileNames;
	in >> m_openFilePath;

	file.close();

	m_dialogScheduler.SetDate(tempDate);
	m_dialogScheduler.SetTime(tempTime);
	m_dialogScheduler.SetWeeklySelection(tempWeeklySelection);
	m_dialogScheduler.SetWeeklySchedu(tempWeeklySchedu);
	m_dialogScheduler.SetOneTimeSchedu(tempOneTimeSchedu);
	m_dialogScheduler.SetSchedularEnable(tempSchedularEnable);

	for (int i = 0; i < m_fileNames.length(); i++)
	{
		ui.listWidget->addItem(m_fileNames[i]);
	}
	ui.listWidget->setCurrentRow(0);

	setting_schdule_detail();
}
void QTPcapReplay::setting_schdule_detail()
{
	if (m_dialogScheduler.IsSchedularEnable())
	{
		m_SchedulerTimer.setTimer(m_dialogScheduler.GetDate(), m_dialogScheduler.GetTime(), m_dialogScheduler.GetWeeklySelection(), m_dialogScheduler.IsWeeklySchedu(),
			m_dialogScheduler.IsOneTimeSchedu());
		QString line;
		line += "Scheduler Running   ";
		if (m_dialogScheduler.IsOneTimeSchedu())
		{
			char dateChar[64];
			sprintf_s(dateChar, 64, "%d/%02d/%02d", m_dialogScheduler.GetDate().year(), m_dialogScheduler.GetDate().month(), m_dialogScheduler.GetDate().day());
			line += dateChar;
			line += "   ";
			//char timeChar[32];			
			//sprintf_s(timeChar, 32, "%02d:%02d   ", m_dialogScheduler.GetTime().hour(), m_dialogScheduler.GetTime().minute());
			//line += timeChar;
			line += m_dialogScheduler.GetTime().toString();
			line += "  ";
			//line += std::to_string(dialog.GetTime().hour()).c_str();
			//line += std::to_string(dialog.GetTime().minute()).c_str();
		}
		else
		{
			//char timeChar[32];
			//sprintf_s(timeChar, 32, "%02d:%02d   ", m_dialogScheduler.GetTime().hour(), m_dialogScheduler.GetTime().minute());
			//line += timeChar;
			line += m_dialogScheduler.GetTime().toString();
			line += "  ";
			//line += std::to_string(dialog.GetTime().hour()).c_str();
			//line += std::to_string(dialog.GetTime().minute()).c_str();
			line += " ";
			for (int i = 0; i < m_dialogScheduler.GetWeeklySelection().size(); i++)
			{
				if (m_dialogScheduler.GetWeeklySelection()[i])
				{
					switch (i)
					{
					case 0:
						line += "Sunday   ";
						break;
					case 1:
						line += "Monday   ";
						break;
					case 2:
						line += "Tuesday   ";
						break;
					case 3:
						line += "Wednesday   ";
						break;
					case 4:
						line += "Thursday   ";
						break;
					case 5:
						line += "Friday   ";
						break;
					case 6:
						line += "Saturday   ";
						break;
					default:
						break;
					}
				}
			}
		}
		ui.schedulerStatus->setText(line);
		ui.schedulerStatus->setStyleSheet("QLabel { background-color : green; color : black; }");
	}
	else
	{
		ui.schedulerStatus->setText(QString("Scheduler Stop"));
		ui.schedulerStatus->setStyleSheet("QLabel { background-color : red; color : black; }");
	}
}
void QTPcapReplay::onSchedulerDynamic()
{

	m_dialogScheduler.setModal(true);
	
	m_dialogScheduler.exec();

	setting_schdule_detail();
}
void QTPcapReplay::handleTimeout()
{
	if (m_SchedulerTimer.IsOneTimeSchedu())
	{
		m_jobReplay->StartReplay();
		m_SchedulerTimer.m_timer.stop();
		return;
	}
	if (m_SchedulerTimer.IsWeeklySchedu() && m_SchedulerTimer.IsTodayRun())
	{
		m_jobReplay->StartReplay();
	}
	m_SchedulerTimer.ReStartForNextDay();
}
void QTPcapReplay::SendPcaket(UINT32 dataLen, unsigned char const * data)
{
	///* Send down the packet */
	if (pcap_sendpacket(m_Adapter,	// Adapter
		data,				// buffer with the packet
		dataLen				// size
		) != 0)
	{
		fprintf(stderr, "\nError sending the packet: %s\n", pcap_geterr(m_Adapter));
		return;
	}
}
int QTPcapReplay::SetOutputAdapter()
{
	char errbuff[PCAP_ERRBUF_SIZE];
	/* Open the adapter */
	if ((m_Adapter = pcap_open_live(m_adapterName.c_str(),		// name of the device
		65536,			// portion of the packet to capture. It doesn't matter in this case 
		1,				// promiscuous mode (nonzero means promiscuous)
		1000,			// read timeout
		errbuff			// error buffer
		)) == NULL)
	{
		QErrorMessage err(this);
		char line[1024];
		sprintf(line, "Unable to open the adapter. %s is not supported by WinPcap", m_adapterName.c_str());
		err.showMessage(QString(line));
		return -1;
	}
	return 0;
}
std::string QTPcapReplay::GetAdapterName()
{
	int numIP = ui.IPComboBox->currentIndex();
	int numInterFace = m_NumIP2NumInterFace[numIP];

	/* Jump to the selected adapter */
	int i;
	for (m_d = m_alldevs, i = 0; i< numInterFace; m_d = m_d->next, i++);

	return m_d->name;
}
void QTPcapReplay::getProgress(int progress)
{
	ui.progressBar->setValue(progress);
}
void QTPcapReplay::onPause()
{
	if (m_playerTimer->IsPause())
	{
		
		QString line = ui.StatusReportLabel->text();
		line.replace(QString("Pause"), QString("Playing"));
		ui.StatusReportLabel->setText(line);

		ui.speed_LineEdit->setDisabled(true);
		m_speed = std::stod(ui.speed_LineEdit->text().toUtf8().constData());
		if (m_speed <= 0)
		{
			m_speed = 1;
			ui.speed_LineEdit->setText(QString::number(1));
		}
		
		m_playerTimer->SetPause();
		ui.curPcapPackage->setText(QString(""));
		ui.pauseReplayButton->setText(QString("Pause"));
	}
	else
	{
		m_playerTimer->SetPause();
		ui.speed_LineEdit->setDisabled(false);
		ui.pauseReplayButton->setText(QString("Continue"));
	}
	
}
void QTPcapReplay::updateRegularButtonText(const QString& line)
{
	ui.regularReplayButton->setText(line);
}

JobReplay::JobReplay(QObject *parent)
	: QThread(parent)
{
	m_bStartReplay = false;
	m_bStartRegularReplay = false;
	m_abort = false;
	start();
}
JobReplay::~JobReplay()
{
	m_mutex.lock();
	m_abort = true;
	m_mutex.unlock();

	wait();
}
void JobReplay::StartReplay()
{
	m_mutex.lock();
	m_bStartReplay = true;
	m_mutex.unlock();
}
void JobReplay::SetPcapReplay(QTPcapReplay * PcapReplay)
{
	m_PcapReplay = PcapReplay;
}
void JobReplay::SetUI(Ui::QTPcapReplayClass * ui)
{
	m_ui = ui;
}

void JobReplay::run() // inherit from task
{
	while (!m_abort)
	{
		if (m_bStartReplay)
		{
			m_PcapReplay->startReplay();
			m_mutex.lock();
			m_bStartReplay = false;
			m_mutex.unlock();
		}
		else if (m_bStartRegularReplay)
		{
			m_PcapReplay->startRegularReplay();
			Sleep(1000);
		}
		else
		{
			Sleep(1);
		}
	}
}

void JobReplay::startRegularReplay()
{
	m_mutex.lock();
	if (!m_bStartRegularReplay)
	{
		m_bStartRegularReplay = true;
		sendUpdateRegularButtonText(QString("Stop Regular Replay"));
	}
	else
	{
		m_bStartRegularReplay = false;
		sendUpdateRegularButtonText(QString("Regular Replay"));
	}
	m_mutex.unlock();
}