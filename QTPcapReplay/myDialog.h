#ifndef MYDIALOG_H
#define MYDIALOG_H

//#include <QtWidgets\QDialog>
//#include <QtWidgets\QMainWindow>

#include "ui_myDialog.h"
class MYDialog : public QDialog
{
	Q_OBJECT

public:
	MYDialog(QWidget *parent = 0);
	~MYDialog();

private:
	Ui::MYDialogClass ui;
};

#endif