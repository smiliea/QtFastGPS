#include "SettingsDialog.h"
#include "ui_SettingsDialog.h"

#include "MainWindow.h"

#include <QtDebug>

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_SettingsDialog_accepted()
{
    qDebug() << "Accepted";
}
