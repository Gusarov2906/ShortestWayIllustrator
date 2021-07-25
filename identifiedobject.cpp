#include "identifiedobject.h"

int IdentifiedObject::idIncrement = 0;

IdentifiedObject::IdentifiedObject()
{
    id = idIncrement;
    idIncrement++;
}

int IdentifiedObject::getId()
{
    return id;
}
