#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "SettingsDialog.h"
#include "ui_SettingsDialog.h"


#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionOpen_triggered()
{
    QString selfilter = tr("IF Files (*.sim *.bin)");
    QString title = "Select IF File";
    QString directory = "D:\\";
    QString fileName = QFileDialog::getOpenFileName(
            this,
            title,
            directory,
            tr("IF Files (*.sim *.bin);;All Files (*.*)" ),
            &selfilter
    );

    ui->textBrowser->append("Opened: " + fileName);


    //run_fastgps();
}

void MainWindow::on_actionLoad_Configuration_File_triggered()
{
    if(read_config_file() == 0)
        ui->textBrowser->append("Sucessfully Read Configuration File.");
    else
        ui->textBrowser->append("Could Not Read Configuration File.");
}

void MainWindow::on_actionSettings_triggered()
{
    SettingsDialog sd;
    sd.exec();
}
