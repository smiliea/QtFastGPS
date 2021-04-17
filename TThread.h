#ifndef TTHREAD_H
#define TTHREAD_H

#include <QMainWindow>
#include <QThread>
#include <QDebug>

#include "fastgps.h"

class TThread : public QMainWindow, public QThread
{
public:
    explicit TThread(QWidget *parent = nullptr);
    int run_fastgps();
    void run();

signals:


};

#endif // TTHREAD_H
