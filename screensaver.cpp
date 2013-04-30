#include <QWidget>
#include "screensaver.h"
#include <QFileDialog>
#include <QSettings>
#include <QEvent>
#include <phonon>


VideoFullScreen::VideoFullScreen(QWidget *parent ):Phonon::VideoPlayer(parent)
{
    QSettings setting(QDir::homePath() + "/.muhasjo/screensaver/settings.ini", QSettings::IniFormat);
    m_sPath = setting.value("Global/FilePath").value<QString>();
    if(!m_sPath.isEmpty()){

        setCursor(Qt::BlankCursor);

        play(m_sPath);
        showFullScreen();
        connect(this, SIGNAL(finished()),this, SLOT(playAgain()));

    }
}

VideoFullScreen::~VideoFullScreen()
{
    disconnect(this, SIGNAL(finished()),this, SLOT(playAgain()));
}

bool VideoFullScreen::event(QEvent *e)
{
    if( e->type() == QEvent::MouseButtonPress || e->type() == QEvent::KeyPress){
        close();
    }
    return Phonon::VideoPlayer::event(e);

}

void VideoFullScreen::playAgain()
{
    load(m_sPath);
    play();
}
