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

private:
    Ui::CreateConnectionDialog *ui;
};

#endif // CREATECONNECTIONDIALOG_H
