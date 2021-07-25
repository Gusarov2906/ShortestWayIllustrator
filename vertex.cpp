#include "vertex.h"
#include <QDebug>
#include <QDir>

Vertex::Vertex(QWidget *parent) : QLabel(parent), ToolStateObject()
{
    //this->move(100, 100);
    this->setPixmap(QPixmap(":/circle.png"));
    this->setGeometry(0, 0, 100, 100);
    this->setPixmap(this->pixmap()->scaled(this->size().width(),this->size().height()));
    //this->setText("a");
    //qDebug() << this->x() << this->y();
}

Vertex::Vertex(QPoint coordinates, QWidget *parent) : QLabel(parent), ToolStateObject()
{
    this->setGeometry(coordinates.x()-25, coordinates.y()-25, 50, 50);

    this->setPixmap(QPixmap(":/blue_circle_with_line.png"));
    this->setPixmap(this->pixmap()->scaled(this->size().width(),this->size().height()));

    this->labelText = new QLabel(this);
    this->labelText->setText(QString::number(this->id));
    this->labelText->setFont(QFont("Times", 12, QFont::ExtraBold));
    this->labelText->setStyleSheet("QLabel { color : white;}");
    this->labelText->setAlignment(Qt::AlignCenter);
    this->labelText->setGeometry(0,0,50,50);

    this->show();
}

void Vertex::focusInEvent(QFocusEvent *event)
{
    //qDebug() << "focusInEvent";
    Q_UNUSED(event);
    this->setPixmap(QPixmap(":/blue_circle.png"));
    this->setPixmap(this->pixmap()->scaled(this->size().width(),this->size().height()));
}

void Vertex::focusOutEvent(QFocusEvent *event)
{
    //qDebug() << "focusInEvent";
    Q_UNUSED(event);
    this->setPixmap(QPixmap(":/red_circle.png"));
    this->setPixmap(this->pixmap()->scaled(this->size().width(),this->size().height()));
}

void Vertex::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if (this->toolState == ToolState::SelectingTool)
    {
        //qDebug() << "setFocus";
        this->setFocus();
    }
}

void Vertex::getNewToolState(int state)
{
    //qDebug() << "getNewToolState" << "id" << id << "state" << state;
    this->toolState = ToolState(state);
}
