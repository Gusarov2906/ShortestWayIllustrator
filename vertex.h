#ifndef VERTEX_H
#define VERTEX_H

#include <QWidget>
#include <QLabel>
#include "identifiedobject.h"
#include "toolstateobject.h"

class Vertex : public QLabel, public IdentifiedObject, public ToolStateObject
{
    Q_OBJECT
public:
    explicit Vertex(QWidget *parent = nullptr);
    Vertex(QPoint coordinates, QWidget *parent = nullptr);
protected:
    //QPixmap* pixmap;
    int name;
    QLabel* labelText;

    void mousePressEvent(QMouseEvent *event) override;

    void focusInEvent(QFocusEvent* e) override;
    void focusOutEvent(QFocusEvent* e) override;
public slots:
    void getNewToolState(int );
signals:

};

#endif // VERTEX_H
