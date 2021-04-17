#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QDebug>
#include <QEventLoop>

#include "fastgps.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow *ui;

    char Buffer[256];
    //fastgps.cpp
    int run_fastgps();
    int read_config_file();
    void update_acq_log();
    void update_tracking_log();
    void update_nav_log();

    //Nav.cpp
    int LeastSquaresPosition(void);
    unsigned int PVT_Solution(int num_chans);
    unsigned int calc_pseudoranges();
    unsigned int WAAS_corrections(unsigned int chan);
    double CalculateDelayCorrection(int chan);
    int ReadWAASFile(double phi_pp_deg,double lambda_pp_deg,double *IGP_points);
    void CalculateAzEl(double RxXYZ[3], double SatXYZ[3], double *A,double *E);
    void nav_init();
    int GetSVInfo(struct s_SV_Info *sv, char *infileXname);
    unsigned int ProcessEphemeris(unsigned int week, double secs,
                                  unsigned int sv, nav_info_t *Eph);
    //dop_pos.cpp
    int DopplerPosition(void);
    int CalcDopplerPosition(s_nav_packet_dopp *pkt);
    void update_debug_log3(int num_points);
    void update_nav_log3(void);

    //snap_shop.cpp
    int SingleEpochPosition(void);
    int CalcSingleEpochPosition(s_nav_packet *pkt,int signal);
    int GetSVInfo2(double *PosVelClk, int prn, int gpsweek, double gpssecs, char *infileXname);
    void update_debug_log(int num_points);
    void update_nav_log2(void);
    double predicted_doppler(int gpsweek, double gpssecs,int prn,double *rxpos,double *rxvel);


private slots:
    void on_actionExit_triggered();
    void on_actionOpen_triggered();

    void on_actionLoad_Configuration_File_triggered();

    void on_actionSettings_triggered();

private:
    QThread thread;



};
#endif // MAINWINDOW_H
