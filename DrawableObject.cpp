#include "DrawableObject.h"

SpriteHolder * DrawableObject::GetMyGraph() { return myGraph; }

void DrawableObject::SetMyGraph(SpriteHolder * graph)
{
	myGraph = graph;
}