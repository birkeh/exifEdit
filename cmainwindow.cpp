#include "cmainwindow.h"
#include "ui_cmainwindow.h"

#include <QSettings>
#include <QCloseEvent>


cMainWindow::cMainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::cMainWindow)
{
	ui->setupUi(this);
}


cMainWindow::~cMainWindow()
{
	delete ui;
}

void cMainWindow::closeEvent(QCloseEvent *event)
{
	QSettings	settings;
	settings.setValue("main/width", QVariant::fromValue(size().width()));
	settings.setValue("main/height", QVariant::fromValue(size().height()));
	settings.setValue("main/x", QVariant::fromValue(x()));
	settings.setValue("main/y", QVariant::fromValue(y()));
	if(this->isMaximized())
		settings.setValue("main/maximized", QVariant::fromValue(true));
	else
		settings.setValue("main/maximized", QVariant::fromValue(false));

//	QList<qint32>	sizes	= ui->m_lpSplitter->sizes();

//	for(int x = 0;x < sizes.count();x++)
//		settings.setValue(QString("main/splitter%1").arg(x+1), QVariant::fromValue(sizes[x]));

//	m_lpFilterPanel->saveSettings();

	event->accept();
}
