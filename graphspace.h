#ifndef GRAPHSPACE_H
#define GRAPHSPACE_H

#include <QWidget>

#include "graph.h"
#include "toolstateobject.h"

class GraphSpace : public QWidget, public ToolStateObject
{
    Q_OBJECT
public:
    explicit GraphSpace(QWidget *parent = nullptr);
    void addVertex(Vertex* vertex);
    void addConnection(VerticesConnection* connection);
protected:
    Graph* graph;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

public slots:
    void getNewToolState(int);
signals:
    void sendNewToolState(int);

};

#endif // GRAPHSPACE_H
