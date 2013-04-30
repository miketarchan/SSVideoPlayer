#ifndef CONFIGDLG_H
#define CONFIGDLG_H

#include <QMainWindow>

namespace Ui {
    class configDlg;
}

class configDlg : public QMainWindow
{
    Q_OBJECT

public:
    explicit configDlg(QWidget *parent = 0);
    ~configDlg();
    void playVideoFullScreen();


private slots:
    void on_pushButton_2_clicked();
    void AboutQt();
    void Aboutme();



private:
    void playVideo();

private:
    Ui::configDlg *ui;

    QString m_sPath;
};

#endif // CONFIGDLG_H
