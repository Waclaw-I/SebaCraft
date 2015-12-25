#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <Windows.h>

#include "SpriteHolder.h"
#include "TextureLoader.h"
#include "Player.h"
#include "PlayerController.h"
#include "LoadController.h"

#include "EnemyShip.h"

#include <conio.h>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
	LoadController Loader(2);

	Loader.LoadTextures(); // these are just textures of our objects

	// actual objects are created here
	SpriteHolder SebamusSprite(Loader.TexturesArray[0], Loader.TexturesArray[0].Get_x(), Loader.TexturesArray[0].Get_y(), 90, 1);	// Our SpriteLoader is using texture from TextureArray

	Player Sebamus;	// our HERO and all his logics
	EnemyShip Statek(1,0.0001, 0.1,1,0.1,300,300,1,1,1);

	SpriteHolder StatekSprite(Loader.TexturesArray[1], Loader.TexturesArray[1].Get_x(), Loader.TexturesArray[1].Get_y(), 90, 1);
	

	RenderWindow MainWindow(VideoMode(800, 600, 32), "SebaCraft"); // main window. Need to think about the proper size

	
	while (MainWindow.isOpen())
	{

		Event zdarzenie;		// escape controller, lol. I should put it inside GameController later
		while (MainWindow.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape) MainWindow.close();
			if (zdarzenie.type == Event::Closed) MainWindow.close();
		}

		SebamusSprite.MySprite.setPosition(static_cast<float>(Sebamus.Get_x_Position()), static_cast<float>(Sebamus.Get_y_Position()));
		SebamusSprite.MySprite.setRotation(Sebamus.Get_Rotation());

		StatekSprite.MySprite.setPosition(static_cast<float>(Statek.Get_x_Position()), static_cast<float>(Statek.Get_y_Position()));
		StatekSprite.MySprite.setRotation(Statek.Get_Rotation());

		
		PlayerController::Moving(Sebamus); // controls movements of the player
		Statek.FollowPlayer(Sebamus);
		//Statek.Accelerate();
		Statek.Move();
		
		MainWindow.clear();
		MainWindow.draw(SebamusSprite.MySprite);	
		MainWindow.draw(StatekSprite.MySprite);


		MainWindow.display();
	}
	return 0;
}
