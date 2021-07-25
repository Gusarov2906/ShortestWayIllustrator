#ifndef IDENTIFIEDOBJECT_H
#define IDENTIFIEDOBJECT_H


class IdentifiedObject
{
public:
    IdentifiedObject();
    int getId();
protected:
    int id;
    static int idIncrement;
};

#endif // IDENTIFIEDOBJECT_H
