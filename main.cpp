#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <Windows.h>

#include "SpriteHolder.h"
#include "TextureLoader.h"
#include "Player.h"
#include "PlayerController.h"
#include "LoadController.h"
#include "BulletController.h"
#include "EnemyController.h"

#include "EnemyShip.h"
#include "SmallFighter.h"
#include "Medivac.h"

#include <conio.h>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
	LoadController::LoadTextures(); // these are just textures of our objects

	// actual objects are created here
	SpriteHolder SebamusSprite(LoadController::ShipTexturesArray[0], LoadController::ShipTexturesArray[0].Get_x(), LoadController::ShipTexturesArray[0].Get_y(), 90, 1);	// Our SpriteLoader is using texture from TextureArray

	Player * Sebamus = new Player(SebamusSprite.GetSize_x(), SebamusSprite.GetSize_y());	// our HERO and all his logics
	SmallFighter * Statek = new SmallFighter(300, 300, 0.2, 100, 2.5, 1, 1, 90, 1);
	Medivac * Statek1 = new Medivac(400, 400, 0.15, 100, 2, 1, 1, 90, 1);

	EnemyController::InsertNewEnemyShip(Statek);
	EnemyController::InsertNewEnemyShip(Statek1);

	

	

	RenderWindow MainWindow(VideoMode(800, 600, 32), "SebaCraft"/*, Style::Fullscreen*/); // main window. Need to think about the proper size


	Clock timer;
	float accumulator = 0;
	float timeStep = 0.0166f; // 60FPS

	
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

			SebamusSprite.MySprite.setPosition(static_cast<float>(Sebamus->Get_x_Position()), static_cast<float>(Sebamus->Get_y_Position()));
			SebamusSprite.MySprite.setRotation(Sebamus->Get_Rotation());

			EnemyController::MoveEnemyShips(Sebamus);

			Statek->Get_MyGraph()->MySprite.setPosition(static_cast<float>(Statek->Get_x_Position()), static_cast<float>(Statek->Get_y_Position()));
			Statek->Get_MyGraph()->MySprite.setRotation(Statek->Get_Rotation());
			Statek1->Get_MyGraph()->MySprite.setPosition(static_cast<float>(Statek1->Get_x_Position()), static_cast<float>(Statek1->Get_y_Position()));
			Statek1->Get_MyGraph()->MySprite.setRotation(Statek1->Get_Rotation());
			for (int i = 0; i < BulletController::ArrayOfBullets.size(); i++)
			{
				BulletController::ArrayOfBullets[i]->GetBulletGraph()->MySprite.setPosition(static_cast<float>(BulletController::ArrayOfBullets[i]->GetPosition_x()),
																						   static_cast<float>(BulletController::ArrayOfBullets[i]->GetPosition_y()));
				BulletController::ArrayOfBullets[i]->GetBulletGraph()->MySprite.setRotation(BulletController::ArrayOfBullets[i]->GetRotation());
				
			}


			PlayerController::Moving(*Sebamus); // controls movements of the player
			PlayerController::Shooting(*Sebamus);
			BulletController::MoveBullets();

			MainWindow.clear();
			MainWindow.draw(SebamusSprite.MySprite);
			for (int i = 0; i < EnemyController::ArrayOfEnemies.size(); i++)
			{
				MainWindow.draw(EnemyController::ArrayOfEnemies[i]->Get_MyGraph()->MySprite);
			}
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
