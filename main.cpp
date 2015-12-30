#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <Windows.h>

#include "SpriteHolder.h"
#include "TextureLoader.h"
#include "Player.h"
#include "PlayerController.h"
#include "LoadController.h"
#include "BulletController.h"

#include "EnemyShip.h"

#include <conio.h>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
	LoadController::LoadTextures(); // these are just textures of our objects

	// actual objects are created here
	SpriteHolder SebamusSprite(LoadController::ShipTexturesArray[0], LoadController::ShipTexturesArray[0].Get_x(), LoadController::ShipTexturesArray[0].Get_y(), 90, 1);	// Our SpriteLoader is using texture from TextureArray
	SpriteHolder SmallFighterSprite(LoadController::ShipTexturesArray[2], LoadController::ShipTexturesArray[2].Get_x(), LoadController::ShipTexturesArray[2].Get_y(), 90, 1);

	Player Sebamus(SebamusSprite.GetSize_x(), SebamusSprite.GetSize_y());	// our HERO and all his logics
	EnemyShip Statek(SmallFighterSprite.GetSize_x(), SmallFighterSprite.GetSize_y());

	

	

	RenderWindow MainWindow(VideoMode(800, 600, 32), "SebaCraft"); // main window. Need to think about the proper size


	Clock timer;
	float accumulator = 0;
	float timeStep = 0.015f;

	
	while (MainWindow.isOpen())
	{
		accumulator += timer.restart().asSeconds();

		if (accumulator >= timeStep)
		{

			Event zdarzenie;		// escape controller, lol. I should put it inside GameController later
			while (MainWindow.pollEvent(zdarzenie))
			{
				if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape) MainWindow.close();
				if (zdarzenie.type == Event::Closed) MainWindow.close();
			}

			SebamusSprite.MySprite.setPosition(static_cast<float>(Sebamus.Get_x_Position()), static_cast<float>(Sebamus.Get_y_Position()));
			SebamusSprite.MySprite.setRotation(Sebamus.Get_Rotation());

			SmallFighterSprite.MySprite.setPosition(static_cast<float>(Statek.Get_x_Position()), static_cast<float>(Statek.Get_y_Position()));
			SmallFighterSprite.MySprite.setRotation(Statek.Get_Rotation());
			for (int i = 0; i < BulletController::ArrayOfBullets.size(); i++)
			{
				BulletController::ArrayOfBullets[i]->GetBulletGraph()->MySprite.setPosition(static_cast<float>(BulletController::ArrayOfBullets[i]->GetPosition_x()),
																						   static_cast<float>(BulletController::ArrayOfBullets[i]->GetPosition_y()));
				
			}



			PlayerController::Moving(Sebamus); // controls movements of the player
			PlayerController::Shooting(Sebamus);
			BulletController::MoveBullets();
			Statek.FollowPlayer(Sebamus);
			Statek.Move();

			MainWindow.clear();
			MainWindow.draw(SebamusSprite.MySprite);
			MainWindow.draw(SmallFighterSprite.MySprite);
			for (int i = 0; i < BulletController::ArrayOfBullets.size(); i++)
			{
				MainWindow.draw(BulletController::ArrayOfBullets[i]->GetBulletGraph()->MySprite); // this ll land at DisplayController
				
			}



			MainWindow.display();
			accumulator -= timeStep;
		}
	}
	return 0;
}
