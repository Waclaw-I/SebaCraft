#pragma once

#include "SpriteHolder.h"

class DrawableObject
{
public:
	SpriteHolder * GetMyGraph();
	void SetMyGraph(SpriteHolder *);

protected:
	SpriteHolder * myGraph;

};