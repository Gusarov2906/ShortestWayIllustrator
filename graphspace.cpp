#include "graphspace.h"
#include <QMouseEvent>
#include <QDebug>

GraphSpace::GraphSpace(QWidget *parent) : QScrollArea(parent), ToolStateObject()
{
    this->graph = new Graph();
    this->setWidget(new QWidget());
    this->mainSelect = nullptr;
    this->prevSelect = nullptr;
    this->isLastSelectNull = true;
    this->prevId = -1;
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
            Vertex* ver = new Vertex(event->pos(), this->widget());
            ver->getNewToolState(this->toolState);
            connect(this, &GraphSpace::sendNewToolState, ver, &Vertex::getNewToolState);
            connect(ver, &Vertex::sendMainSelect, this, &GraphSpace::getMainSelect);
            this->addVertex(ver);
            emit updateNumOfNotConnectingsVertices(1);
            break;
        }
    }
    case ToolState::AddConnectionTool:
    {
        if(event->button() == Qt::RightButton)
        {
            if (mainSelect != nullptr)
            {
                mainSelect->clearFocus();
                mainSelect->makeUnselected();
                mainSelect = nullptr;
            }
            if (prevSelect != nullptr)
            {
                prevSelect->makeUnselected();
                prevSelect = nullptr;
            }
        }
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

void GraphSpace::getMainSelect(int id)
{
    //qDebug() << "d" << id;
    switch (this->toolState) {
    case ToolState::SelectingTool:
    {
        mainSelect = this->graph->getVertex(id);
        if (this->graph->getVertex(id) != nullptr)
        {
            this->graph->getVertex(id)->setFocus();
        }
        qDebug() << mainSelect;
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
        qDebug() << "id" << id;
        if (prevId != id)
        {
            if (prevSelect == nullptr)
            {
                prevSelect = graph->getVertex(id);
                prevSelect->makeSelected();
            }
            else
            {
                if(mainSelect != nullptr && mainSelect != prevSelect)
                {
                    prevSelect->makeUnselected();
                    prevSelect = &*mainSelect;
                }
                if (graph->getVertex(id) != nullptr)
                {
                    if (graph->getVertex(id) != mainSelect)
                    {
                        mainSelect = graph->getVertex(id);
                        mainSelect->makeSelected();
                    }
                }
                //qDebug() << mainSelect << prevSelect;
            }


            if (mainSelect != nullptr && prevSelect != nullptr && mainSelect!=prevSelect)
            {
                //qDebug() << "New connection" << prevSelect->getId() << "to" << mainSelect->getId();

                emit openCreateConnectionDialog(prevSelect->getId(), mainSelect->getId());
                //mainSelect->makeSelected();
                //mainSelect = nullptr;
    //            mainSelect->clearFocus();
    //            mainSelect = nullptr;
    //            prevSelect->makeUnselected();
    //            prevSelect = nullptr;
            }
        }
        prevId = id;
        //qDebug() << mainSelect;
        break;
    }
    default:
    {
        qDebug() << "handle toolState error!";
    }
    }
}

void GraphSpace::createConnection(int from, int to, int lenght)
{
    qDebug() << "create from" << graph->getVertex(from) << graph->getVertex(from)->getId() << "to" << graph->getVertex(to)<< graph->getVertex(to)->getId() << "len" << lenght;
}

