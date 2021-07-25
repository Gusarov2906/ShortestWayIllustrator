#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "toolstateobject.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public ToolStateObject
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    int numOfConnections;
    int numOfNotConnectingsVertices;
    int numOfVertices;
private slots:
    void on_selectToolButton_clicked();
    void on_moveToolButton_clicked();
    void on_addVertexToolButton_clicked();
    void on_addConnectionToolButton_clicked();

    void updateNumOfConnections(int);
    void updateNumOfNotConnectingsVertices(int);
    void updateNnumOfVertices(int);
private:
    Ui::MainWindow *ui;

signals:
    void sendNewToolState(int);
};
#endif // MAINWINDOW_H
