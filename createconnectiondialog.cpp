#include "createconnectiondialog.h"
#include "ui_createconnectiondialog.h"

CreateConnectionDialog::CreateConnectionDialog(int from, int to, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateConnectionDialog)
{
    ui->setupUi(this);
    ui->fromValueLabel->setText(QString::number(from));
    ui->toValueLabel->setText(QString::number(to));
}

CreateConnectionDialog::~CreateConnectionDialog()
{
    delete ui;
}
