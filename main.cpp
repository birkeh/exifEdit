#include "cmainwindow.h"

#include <QApplication>

#include <QSettings>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	a.setApplicationVersion("1.0");
	a.setApplicationDisplayName("exifEdit");
	a.setOrganizationName("WIN-DESIGN");
	a.setOrganizationDomain("windesign.at");
	a.setApplicationName("pictureexifEdit");

	QSettings		settings;

	cMainWindow w;

	if(settings.value("main/maximized").toBool())
		w.showMaximized();
	else
		w.show();

	return a.exec();
}
