#ifndef SCREENSAVER_H
#define SCREENSAVER_H

#include <QWidget>
#include <phonon>


class VideoFullScreen: public Phonon::VideoPlayer
{
    Q_OBJECT
public:
    VideoFullScreen(QWidget *parent = 0);
    ~VideoFullScreen();

private slots:
    void playAgain();
protected:
    bool event(QEvent *e);

    QString m_sPath;
};


#endif // SCREENSAVER_H
