#ifndef QTPCAPREPLAY_H
#define QTPCAPREPLAY_H

#pragma comment(lib, "Ws2_32.lib")

#include <QtWidgets/QMainWindow>
#include <QtCore/qdir.h>
#include <QtCore/qdiriterator.h>
#include <QtCore/qthread.h>
#include <QtWidgets/qerrormessage.h>
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <qdebug.h>

#include "ui_qtpcapreplay.h"
#include "pcap.h"
#include "myDialog.h"
#include "PlayerTimer.h"
#include "threadPool.h"
#include "Scheduler.h"
#include "SchedulerTimer.h"
#include "NetSpeedMeasurement.h"
#include "PacketTimeReportor.h"

#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>


#define CONFIG_FILE L".\\QTPcapReplay.ini"

class QTPcapReplay;

class JobReplay : public QThread
{
	Q_OBJECT

public:
	JobReplay(QObject *parent = 0);
	~JobReplay();

	void SetPcapReplay(QTPcapReplay * PcapReplay);
	void SetUI(Ui::QTPcapReplayClass * ui);
	bool IsRegularReplaying(){ m_mutex.lock(); bool result = m_bStartRegularReplay; m_mutex.unlock(); return result; }

	void run(); // inherit from QThread
private:
	Ui::QTPcapReplayClass * m_ui;
	QTPcapReplay * m_PcapReplay;
	bool m_bStartReplay;
	bool m_bStartRegularReplay;
	QMutex m_mutex;
	bool m_abort;
signals:
	void updateProgress(const int& progress);
	void updateNextPacketNumber(const QString& line);
	void updateCurrentPlayingFile(const QString& line);
	void updatePlayingStatus(const bool& inStatus);
	void updateRegularReplayingStatus(const bool& inStatus);
	void sendMessageBox(const QString& line);
	void sendUpdateRegularButtonText(const QString& line);
public slots:
	void StartReplay();
	void startRegularReplay();
};

class QTPcapReplay : public QMainWindow
{
	Q_OBJECT

public:
	QTPcapReplay(QWidget *parent = 0);
	~QTPcapReplay();

	int InitAdapterName();
	std::string GetAdapterName();
	void ReplayFile(const std::string& fileName);
	void RegularReplayFile(const std::string& fileName);

	void startReplay();
	void startRegularReplay();
	int SetOutputAdapter();
	void setting_schdule_detail();
private:
	Ui::QTPcapReplayClass ui;

	pcap_if_t *m_alldevs;
	pcap_if_t *m_d;
	std::string m_adapterName;
	pcap_t * m_Adapter;

	std::map<int, int> m_NumIP2NumInterFace;
	const UINT32 PCAPGOBLEHEADERSIZE = 24;
	const UINT32 PCAPLOCALHEADERSIZE = 16;
	PlayerTimer * m_playerTimer;
	threadPool * m_threadPool;
	double m_speed;
	bool m_bPlaying;
	bool m_bBeforePlay;
	bool m_bFirstFileOfReplayList;
	bool m_bOnlyFirstFileOffSet;
	SchedulerTimer m_SchedulerTimer;
	double m_offSet;

	JobReplay * m_jobReplay;
	Scheduler m_dialogScheduler;

	QIcon m_icon;
	QString m_openFilePath;

	QStringList m_fileNames;

	// net speed measurement
	NetSpeedMeasurement m_NetSpeedMeasure;
	PacketTimeReportor m_PacketTimeReportor;

	std::ifstream::pos_type FileSize(const std::string& filename);
	void SendPcaket(UINT32 dataLen, unsigned char const * data);
	void GetBitPerSec(double bit, std::string& line, int step);
	int sf_difftime(const tm& first, const tm& second);

private slots:
	void onFileOpen();
	void onItemActivated();
	void onFileExit();
	void onFolderOpen();
	void onPause();
	void removeFile();
	void onNewWindow(); // after you open a new dialog, you can only interate with the new dialog
	void onNewWindowDynamic(); // after you open a new dialog, you can interate with both the new dialog and the main window
	void getProgress(int progress);
	void getNextPacketNumber(QString line);
	void getCurStatus(QString line);
	void updatePlayingStatus(bool bPlaying);
	void updateRegularReplayingStatus(bool bPlaying);
	void StopPlaying();
	void onSchedulerDynamic();
	void handleTimeout();
	void updateNetSpeedMeasure(double speed);
	void PrintTimeReport(QString timeReport);
	void showMessageBox(const QString& line);
	void updateRegularButtonText(const QString& line);
	void save_config_setting();
	void load_config_setting();
};

#endif // QTPCAPREPLAY_H
