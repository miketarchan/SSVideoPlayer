#include "configdlg.h"
#include "ui_configdlg.h"
#include <QFileDialog>
#include <QSettings>
#include <QMessageBox>

configDlg::configDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::configDlg)
{
    ui->setupUi(this);

    QSettings setting(QDir::homePath() + "/.muhasjo/screensaver/settings.ini", QSettings::IniFormat);
    m_sPath = setting.value("Global/FilePath").value<QString>();
    if(!m_sPath.isEmpty()){
        ui->lineEdit_2->setText(m_sPath);
        playVideo();
    }
}

configDlg::~configDlg()
{
    delete ui;
}




void configDlg::playVideo()
{
    ui->videoPlayer_2->showFullScreen();
    ui->videoPlayer_2->play(Phonon::MediaSource(m_sPath));
    ui->videoPlayer_2->setVolume(float(0));

}


void configDlg::on_pushButton_2_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Video File"),
                                                    "", tr("AVI files (*.avi);;MPEG files (*.mpg)"));
    if(!filePath.isEmpty()){
        m_sPath = filePath;

        QSettings setting(QDir::homePath() + "/.muhasjo/screensaver/settings.ini", QSettings::IniFormat);
        setting.setValue("Global/FilePath", filePath);

        ui->lineEdit_2->setText(filePath);
        playVideo();
    }
}
void configDlg::AboutQt()
{
    qApp->aboutQt();
}

void configDlg::Aboutme()
{
    QMessageBox msg;
    msg.setText("created by: muhasjo @gmail.com");
    msg.exec();
}


