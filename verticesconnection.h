#ifndef VERTICESCONNECTION_H
#define VERTICESCONNECTION_H

#include <QLabel>
#include "identifiedobject.h"


class VerticesConnection : public QLabel, public IdentifiedObject
{
    Q_OBJECT
public:
    explicit VerticesConnection(QWidget *parent = nullptr);
protected:
    QPixmap pixmap;
};

#endif // VERTICESCONNECTION_H
