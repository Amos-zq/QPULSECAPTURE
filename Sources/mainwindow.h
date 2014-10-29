#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//------------------------------------------------------------------------------------------------------

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QString>
#include <QLayout>
#include <QLabel>
#include <QThread>
#include <QStatusBar>
#include <QMenuBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopServices>
#include <QProcess>
#include <QFile>
#include <QTextStream>

#include "qimagewidget.h"
#include "qopencvprocessor.h"
#include "qvideocapture.h"
#include "about.h"
#include "qharmonicprocessor.h"
#include "qsettingsdialog.h"
#include "qeasyplot.h"

//------------------------------------------------------------------------------------------------------

#define MS_INTERVAL 1000
#define LIMIT_OF_DIALOGS_NUMBER 5

//------------------------------------------------------------------------------------------------------
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void contextMenuEvent(QContextMenuEvent *event);
    void closeEvent(QCloseEvent *);

public slots:
    bool openvideofile(); // for video file open
    bool opendevice(); // for video device open
    void opendeviceresolutiondialog();
    void opendevicesettingsdialog();
    void createPlotDialog();
    void callDirectShowSdialog();
    void show_about();
    void show_help();
    void onpause();
    void onresume();
    void configure_and_start_session();
    void make_record_to_file(qreal signalValue, qreal meanRed, qreal meanGreen, qreal meanBlue, qreal freqValue, qreal snrValue);

private:
    void createActions();
    void createMenus();
    void createTimers();
    void createThreads();
    QImageWidget *pt_display;
    QVBoxLayout *pt_mainLayout;
    QLabel *pt_infoLabel;
    QAction *pt_openSessionAct;
    QAction *pt_exitAct;
    QAction *pt_aboutAct;
    QAction *pt_helpAct;
    QAction *pt_pauseAct;
    QAction *pt_resumeAct;
    QAction *pt_deviceResAct;
    QAction *pt_deviceSetAct;
    QAction *pt_DirectShowAct;
    QAction *pt_openPlotDialog;
    QMenu *pt_fileMenu;
    QMenu *pt_optionsMenu;
    QMenu *pt_deviceMenu;
    QMenu *pt_helpMenu;
    QVideoCapture *pt_videoCapture;
    QOpencvProcessor *pt_opencvProcessor;
    QThread *pt_improcThread;
    QThread *pt_harmonicThread;
    QHarmonicProcessor *pt_harmonicProcessor;
    QTimer m_timer;
    QDialog *pt_dialogSet[LIMIT_OF_DIALOGS_NUMBER];
    quint8 m_dialogSetCounter;
    QFile m_saveFile;
    QTextStream m_textStream;
    static const char *QPlotDialogName[];
private slots:
    void decrease_dialogSetCounter();
    void closeAllDialogs();
};
//------------------------------------------------------------------------------------------------------
#endif // MAINWINDOW_H
