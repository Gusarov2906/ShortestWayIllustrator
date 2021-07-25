#ifndef TOOLSTATEOBJECT_H
#define TOOLSTATEOBJECT_H

enum ToolState {SelectingTool = 0, MoveTool, AddVertexTool, AddConnectionTool};

class ToolStateObject
{
public:
    ToolStateObject();
    ToolState toolState;
};

#endif // TOOLSTATEOBJECT_H
