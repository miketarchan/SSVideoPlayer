#include <QtGui/QApplication>
#include "screensaver.h"
#include <configdlg.h>
#include <QMessageBox>
#include <QFileDialog>
#include <QSettings>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString str; str = QString("%1").arg(argv[1]);
    str.toLower();

    ///fullscreen mode
    if( str.contains( QString("/s")) ){
        QSettings setting(QDir::homePath() + "/.muhasjo/screensaver/settings.ini", QSettings::IniFormat);

        QString  sPath = setting.value("Global/FilePath").value<QString>();
        if(sPath.isEmpty()) exit(0);



        VideoFullScreen * screen = new VideoFullScreen();
        QObject::connect(screen, SIGNAL(destroyed()), &a, SLOT(quit()));
        ///preview mode
    } else if( str == QString("/p")){

		//TODO mayby;
		exit(0);

		///config mode
    } else if(  str.contains( QString("/c"))){

		configDlg *w =new configDlg();
		w->setAttribute(Qt::WA_DeleteOnClose);
		w->show();
		QObject::connect(w, SIGNAL(destroyed()), &a, SLOT(quit()));
    } else{

        exit(0);
    }

    return a.exec();
}
