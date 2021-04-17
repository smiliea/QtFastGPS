#include "TThread.h"

TThread::TThread(QWidget *parent) : QMainWindow(parent)
{

}
void TThread::run()
{
    qDebug() << "Thread Started...";

}
