#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ToolStateObject()
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this, &MainWindow::sendNewToolState, ui->graphSpace, &GraphSpace::getNewToolState);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_selectToolButton_clicked()
{
    this->toolState = ToolState::SelectingTool;
    emit sendNewToolState(this->toolState);
}

void MainWindow::on_moveToolButton_clicked()
{
    this->toolState = ToolState::MoveTool;
    emit sendNewToolState(this->toolState);
}

void MainWindow::on_addVertexToolButton_clicked()
{
    this->toolState = ToolState::AddVertexTool;
    emit sendNewToolState(this->toolState);
}

void MainWindow::on_addConnectionToolButton_clicked()
{
    this->toolState = ToolState::AddConnectionTool;
    emit sendNewToolState(this->toolState);
}
