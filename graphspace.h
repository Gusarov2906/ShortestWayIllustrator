#ifndef GRAPHSPACE_H
#define GRAPHSPACE_H

#include <QWidget>
#include <QScrollArea>
#include "graph.h"
#include "toolstateobject.h"

class GraphSpace : public QScrollArea, public ToolStateObject
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

    Vertex* mainSelect;
    Vertex* prevSelect;

    int prevId;
    bool isLastSelectNull;

public slots:
    void getNewToolState(int);
    void getMainSelect(int);
    void createConnection(int, int, int);
signals:
    void sendNewToolState(int);
    void updateNumOfConnections(int);
    void updateNumOfNotConnectingsVertices(int);
    void updateNnumOfVertices(int);
    void openCreateConnectionDialog(int, int);
};

#endif // GRAPHSPACE_H
