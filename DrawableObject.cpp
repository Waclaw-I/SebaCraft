#include "DrawableObject.h"

#include <iostream>
using namespace std;

SpriteHolder * DrawableObject::GetMyGraph() { return myGraph; }

void DrawableObject::SetMyGraph(SpriteHolder * graph)
{
	myGraph = graph;
}

DrawableObject::~DrawableObject()
{
	
}