/*
Author: Alejandro Navarro
Title: Player
Description: header of the Player class
Date Created: 11-20-2018
Date Last Modified: 11-20-2018
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <SDL.h>
#include <ctime>
#include "Tool.h"
#include "SDL_Plotter.h"
#include "platform.h"

using namespace std;

class Player
{
  private:
  Point position;
  int height, width;
  SDL_Surface* imageSurf;
  bool alive, jump;
  int lives;



  public:

  /*
  description: default constructor for Player object.
  return: none
  precondition: The two arguements passed should contain the address of
                SDL_Plotter and platform.
                platform has to be initialized using SDL_Plotter first before
                initializing a Player object.
  postcondition: A Player object is created.
  */
  Player(SDL_Plotter& plot, platform& plat);

  /*
  description: displays the player in a new location on the screen.
  return: void
  precondition: plot has to exist. x and y need to be valid integers.
  postcondition: the player will appear in a different location on the screen.
  */
  void movePlayer(SDL_Plotter& plot, int x, int y);

  /*
  description: returns the height of the image in pixels.
  return: int
  precondition: the image in the Player object needs to be valid and exist.
  postcondition: Everything remains the same in the Player class.
  */
  int getHeight() const;

  /*
  description: returns the width of the image in pixels.
  return: int
  precondition: the image in the Player object needs to be valid and exist.
  postcondition: Everything remains the same in the Player class.
  */
  int getWidth() const;

  /*
  description: returns the x position.
  return: int
  precondition: the position object in the player objects needs to exist.
  postcondition: everything remians the same.
  */
  int getX() const;

  /*
  description: returns the y position.
  return: int
  precondition: the position object in the player objects needs to exist.
  postcondition: everything remians the same.
  */
  int getY() const;

  /*
  description: returns true if the player is alive.
  return: bool
  precondition: the player object has to exist.
  postcondition: everything in the player object ramians the same.
  */
  bool isAlive() const;

  /*
  description: returns true if the player is jumping
  return: bool
  precondition: the player object has to exist.
  postcondition: everything in the player object ramians the same.
  */
  bool isJumping() const;

  /*
  description: changes the state of alive in the player object.
  return: void
  precondition: the player object has to exist.
  postcondition: everything in the player object ramians the same.
  */
  void setAlive(bool a);

  /*
  description: changes the attribute that determines if the player is jumping.
  return: void
  precondition: the player object has to exist.
  postcondition: everything in the player object ramians the same.
  */
  void setJump(bool j);

  /*
  description:
  return:
  precondition:
  postcondition:
  */
  int getLives() const;

  /*
  description:
  return:
  precondition:
  postcondition:
  */
  void die();

  /*
  description:
  return:
  precondition:
  postcondition:
  */
  bool touchEnemy();

};

#endif //PLAYER_H
