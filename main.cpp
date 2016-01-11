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
#include "DisplayController.h"


#include "EnemyShip.h"
#include "SmallFighter.h"
#include "Medivac.h"
#include "SpaceStation.h"

#include <conio.h>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
	LoadController::LoadTextures(); // these are just textures of our objects

	// actual objects are created here

	// Our SpriteLoader is using texture from TextureArray

	SpriteHolder Background1(LoadController::BackgroundTextureArray[0], LoadController::BackgroundTextureArray[0].Get_x(), LoadController::BackgroundTextureArray[0].Get_y(), 0, 1.2);
	SpriteHolder Background2(LoadController::BackgroundTextureArray[1], LoadController::BackgroundTextureArray[1].Get_x(), LoadController::BackgroundTextureArray[1].Get_y(), 0, 0.5);

	Background1.MySprite.setPosition(0, 0);
	Background2.MySprite.setPosition(0, 0);

	Player * Sebamus = new Player();	// our HERO and all his logics

	SpaceStation * Station = new SpaceStation(0.1, 2);

	//Station->SpawnMedivac();
	Station->SpawnSmallFighter();

	

	RenderWindow MainWindow(VideoMode(1366, 768, 32), "SebaCraft"/*, Style::Fullscreen*/); // main window. Need to think about the proper size (doesn't matter when in Fullscreen mode)



	View OurCamera;

	OurCamera = MainWindow.getDefaultView();
	OurCamera.setViewport(FloatRect(0, 0, 0.8, 0.8));

	


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

			Sebamus->GetLevelOneGraph()->MySprite.setPosition(Sebamus->Get_x_Position(), Sebamus->Get_y_Position());
			Sebamus->GetLevelOneGraph()->MySprite.setRotation(Sebamus->Get_Rotation());

			Background1.MySprite.setPosition(Sebamus->Get_x_Position(), Sebamus->Get_y_Position());
			Background2.MySprite.setPosition( (Sebamus->Get_x_Position()* 0.8), (Sebamus->Get_y_Position() *0.8) );

			Station->Get_MyGraph()->MySprite.setRotation(Station->Get_Rotation());

			Station->RotateRight();

			Station->SpawnSmallFighter();
			Station->SpawnMedivac();

			OurCamera.setCenter(Sebamus->Get_x_Position(), Sebamus->Get_y_Position()); // Camera
			MainWindow.setView(OurCamera);

			EnemyController::MoveEnemyShips(Sebamus);

			for (int i = 0; i < EnemyController::ArrayOfEnemies.size(); i++)
			{
				EnemyController::ArrayOfEnemies[i]->Get_MyGraph()->MySprite.setPosition(static_cast<float>(EnemyController::ArrayOfEnemies[i]->Get_x_Position()),
																						static_cast<float>(EnemyController::ArrayOfEnemies[i]->Get_y_Position()));

				EnemyController::ArrayOfEnemies[i]->Get_MyGraph()->MySprite.setRotation(EnemyController::ArrayOfEnemies[i]->Get_Rotation());
			}

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
			MainWindow.draw(Background1.MySprite);
			MainWindow.draw(Background2.MySprite);
			MainWindow.draw(Station->Get_MyGraph()->MySprite);
			MainWindow.draw(Sebamus->GetLevelOneGraph()->MySprite);
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
