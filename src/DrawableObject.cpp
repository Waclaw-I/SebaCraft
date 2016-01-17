#include "DrawableObject.h"

#include <iostream>
using namespace std;

SpriteHolder * DrawableObject::GetMyGraph() { return myGraph; }
TextLabel * DrawableObject::GetHpBar() { return hpBar; }

void DrawableObject::SetMyGraph(SpriteHolder * graph)
{
	myGraph = graph;
}

DrawableObject::~DrawableObject()
{
	
}