#pragma once

#include "SpriteHolder.h"
#include "TextLabel.h"

class DrawableObject
{
public:
	SpriteHolder * GetMyGraph();
	TextLabel * GetHpBar();
	void SetMyGraph(SpriteHolder *);

	virtual ~DrawableObject();

protected:
	SpriteHolder * myGraph;
	TextLabel * hpBar;

};