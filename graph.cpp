#include "graph.h"
#include <QDebug>

Graph::Graph()
{

}

void Graph::addVertex(Vertex *vertex)
{
    //qDebug() << vertex << vertex->getId();

    this->vertices.push_back(vertex);
}

void Graph::addConnection(VerticesConnection *connection)
{
    //qDebug() << connection << connection->getId();

    this->connections.push_back(connection);
}

Vertex* Graph::getVertex(int id)
{
    for(int i = 0; i < (int)this->vertices.size(); i++)
    {
        if (vertices.at(i)->getId() == id)
        {
            return vertices.at(i);
        }
    }
    return nullptr;
}

VerticesConnection* Graph::getConnection(int id)
{
    for(int i = 0; i < (int)this->connections.size(); i++)
    {
        if (connections.at(i)->getId() == id)
        {
            return connections.at(i);
        }
    }
    return nullptr;
}

QVector<Vertex*> Graph::getVertices()
{
    return vertices;
}

QVector<VerticesConnection*> Graph::getConnections()
{
    return connections;
}
