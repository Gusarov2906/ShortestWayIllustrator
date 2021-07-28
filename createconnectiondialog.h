#ifndef CREATECONNECTIONDIALOG_H
#define CREATECONNECTIONDIALOG_H

#include <QDialog>

namespace Ui {
class CreateConnectionDialog;
}

class CreateConnectionDialog : public QDialog
{
    Q_OBJECT
public:
    CreateConnectionDialog(int from, int to, QWidget *parent = nullptr);
    ~CreateConnectionDialog();

signals:
    void createConnection(int, int, int);
private slots:
    void on_createButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::CreateConnectionDialog *ui;
    int lenghtOfWay;
    int wayFrom;
    int wayTo;
};

#endif // CREATECONNECTIONDIALOG_H
