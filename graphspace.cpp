#include "graphspace.h"
#include <QMouseEvent>
#include <QDebug>

GraphSpace::GraphSpace(QWidget *parent) : QWidget(parent), ToolStateObject()
{
    this->graph = new Graph();
}

void GraphSpace::addVertex(Vertex *vertex)
{
    this->graph->addVertex(vertex);
}

void GraphSpace::mousePressEvent(QMouseEvent *event)
{
    switch (this->toolState) {
    case ToolState::SelectingTool:
    {
        if(event->buttons() & Qt::LeftButton)
        {
            //qDebug() << "here";
            //QWidget::mousePressEvent(event);
        }
        break;
    }
    case ToolState::MoveTool:
    {
        break;
    }
    case ToolState::AddVertexTool:
    {
        break;
    }
    case ToolState::AddConnectionTool:
    {
        break;
    }
    default:
    {
        qDebug() << "handle toolState error!";
    }
    }
}

void GraphSpace::mouseMoveEvent(QMouseEvent *event)
{
    switch (this->toolState) {
    case ToolState::SelectingTool:
    {
        if(event->buttons() & Qt::LeftButton)
        {
        }
        break;
    }
    case ToolState::MoveTool:
    {
        break;
    }
    case ToolState::AddVertexTool:
    {
        break;
    }
    case ToolState::AddConnectionTool:
    {
        break;
    }
    default:
    {
        qDebug() << "handle toolState error!";
    }
    }
}

void GraphSpace::mouseReleaseEvent(QMouseEvent *event)
{
    switch (this->toolState) {
    case ToolState::SelectingTool:
    {
        break;
    }
    case ToolState::MoveTool:
    {
        break;
    }
    case ToolState::AddVertexTool:
    {
        if(event->button() == Qt::LeftButton)
        {
            Vertex* ver = new Vertex(event->pos(), this);
            ver->getNewToolState(this->toolState);
            connect(this, &GraphSpace::sendNewToolState, ver, &Vertex::getNewToolState);
            this->addVertex(ver);
            break;
        }
    }
    case ToolState::AddConnectionTool:
    {
        break;
    }
    default:
    {
        qDebug() << "handle toolState error!";
    }
    }
}

void GraphSpace::getNewToolState(int toolState)
{
    this->toolState = ToolState(toolState);
    emit sendNewToolState(toolState);
    //qDebug() << ToolState(toolState);
}
