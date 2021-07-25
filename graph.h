#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
#include "verticesconnection.h"
#include "vector"

class Graph
{
public:
    Graph();
    void addVertex(Vertex* vertex);
    void addConnection(VerticesConnection* connection);
    Vertex* getVertex(int id);
    VerticesConnection* getConnection(int id);
    QVector<Vertex*> getVertices();
    QVector<VerticesConnection*> getConnections();
protected:
    QVector<Vertex*> vertices;
    QVector<VerticesConnection*> connections;
};

#endif // GRAPH_H
