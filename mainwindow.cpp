#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ToolStateObject()
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    numOfConnections = 0;
    numOfNotConnectingsVertices = 0;
    numOfVertices = 0;

    ui->numOfConnections->setText(QString::number(numOfConnections));
    ui->numOfNotConnectingVertices->setText(QString::number(numOfNotConnectingsVertices));
    ui->numOfVertices->setText(QString::number(numOfVertices));

    connect(this, &MainWindow::sendNewToolState, ui->graphSpace, &GraphSpace::getNewToolState);
    connect(ui->graphSpace, &GraphSpace::updateNumOfConnections, this, &MainWindow::updateNumOfConnections);
    connect(ui->graphSpace, &GraphSpace::updateNumOfNotConnectingsVertices, this, &MainWindow::updateNumOfNotConnectingsVertices);
    connect(ui->graphSpace, &GraphSpace::updateNnumOfVertices, this, &MainWindow::updateNnumOfVertices);
    connect(ui->graphSpace, &GraphSpace::openCreateConnectionDialog, this, &MainWindow::openCreateConnectionDialog);
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

void MainWindow::updateNumOfConnections(int val)
{
    this->numOfConnections += val;
    ui->numOfConnections->setText(QString::number(numOfConnections));
}

void MainWindow::updateNumOfNotConnectingsVertices(int val)
{
    this->numOfNotConnectingsVertices += val;
    ui->numOfNotConnectingVertices->setText(QString::number(numOfNotConnectingsVertices));
}

void MainWindow::updateNnumOfVertices(int val)
{
    this->numOfVertices += val;
    ui->numOfVertices->setText(QString::number(numOfVertices));
}

void MainWindow::openCreateConnectionDialog(int from, int to)
{
    if (createConnectionDialog != nullptr)
    {
        delete  createConnectionDialog;
    }
    createConnectionDialog = new CreateConnectionDialog(from, to, this);
    connect(createConnectionDialog, &CreateConnectionDialog::createConnection, ui->graphSpace, &GraphSpace::createConnection);
    createConnectionDialog->show();
}
