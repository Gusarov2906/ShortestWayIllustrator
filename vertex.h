#ifndef VERTEX_H
#define VERTEX_H

#include <QWidget>
#include <QLabel>
#include <QGraphicsItem>

#include "identifiedobject.h"
#include "toolstateobject.h"

class Vertex : public QLabel, public IdentifiedObject, public ToolStateObject
{
    Q_OBJECT
public:
    explicit Vertex(QWidget *parent = nullptr);
    Vertex(QPoint coordinates, QWidget *parent = nullptr);
    void makeSelected();
    void makeUnselected();
protected:
    //QPixmap* pixmap;
    int name;
    QLabel* labelText;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void focusInEvent(QFocusEvent* e) override;
    void focusOutEvent(QFocusEvent* e) override;
public slots:
    void getNewToolState(int );
signals:
    void sendMainSelect(int );
};

#endif // VERTEX_H
