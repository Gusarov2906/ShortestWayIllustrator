#include "createconnectiondialog.h"
#include "ui_createconnectiondialog.h"

#include <QIntValidator>
#include <QString>

CreateConnectionDialog::CreateConnectionDialog(int from, int to, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateConnectionDialog)
{
    ui->setupUi(this);
    ui->fromValueLabel->setText(QString::number(from));
    ui->toValueLabel->setText(QString::number(to));
    ui->lenghtOfWayTextEdit->setValidator(new QIntValidator(0, 5000, this));

    this->wayFrom = from;
    this->wayTo = to;
}

CreateConnectionDialog::~CreateConnectionDialog()
{
    delete ui;
}

void CreateConnectionDialog::on_createButton_clicked()
{
    if (ui->lenghtOfWayTextEdit->text() != "")
    {
        lenghtOfWay = (ui->lenghtOfWayTextEdit->text()).toInt();
        emit createConnection(wayFrom, wayTo, lenghtOfWay);
        this->close();
    }
    else
    {
        ui->lenghtOfWayTextEdit->setPlaceholderText("Please write a non negative number");
    }
}

void CreateConnectionDialog::on_cancelButton_clicked()
{
    this->close();
}
