/*
Author: Alejandro Navarro
Title: Platform
Description: header file of the class platform
Date Created: 11-2-2018
Date Last Modified: 11-18-2018
*/

#include <iostream>
#include <SDL.h>
#include "SDL_Plotter.h"
#include "platform.h"
#include "player.h"
#include "Tool.h"

using namespace std;

int main(int argc, char ** argv)
{

    int rows = 800; //multiple of 10
    int cols = 1120; //multiple of 14

    SDL_Plotter plot(rows, cols, true);
    platform plat(plot, rows, cols);
    Player player(plot, plat);

    //Initial sound
    plot.initSound("GameMusic.wav");

    Timer pTime(2);

    int airTime = 0, speed = 5;

    while(player.isAlive())
    {
      //Play sound
      plot.playSound("GameMusic.wav");

      //PLAYER CONTROL **********************************************************
      //jumping
      if(player.isJumping())
      {
        //Jumping
        if(!plat.touchPlatform(player.getX(), player.getY() - 1, player.getHeight(), player.getWidth()) && airTime < 200)
        {
          if(pTime.isComplete())
          {
            player.movePlayer(plot, player.getX(), player.getY() - 1);
            airTime++;
            pTime.reset();
          }
        }
        else
        {
         player.setJump(false);
         airTime = 0;
         speed = 5;
        }
      }
      //gravity
      else if(!plat.touchPlatform(player.getX(), player.getY() + 1, player.getHeight(), player.getWidth()))
      {
        if(pTime.isComplete())
        {
          player.movePlayer(plot, player.getX(), player.getY() + 1);
          pTime.reset();
        }
      }

      if(plot.kbhit())
      {
        //Jump
        if(plot.getKey() == UP_ARROW)
        {
          player.setJump(true);
        }
        //Move Right
        else if(plot.getKey() == RIGHT_ARROW)
        {
          if(!plat.touchPlatform(player.getX() + speed, player.getY(), player.getHeight(), player.getWidth()))
          {
            player.movePlayer(plot, player.getX() + speed, player.getY());
          }
        }
        //Move Left
        else if(plot.getKey() == LEFT_ARROW)
        {
          if(!plat.touchPlatform(player.getX() - speed, player.getY(), player.getHeight(), player.getWidth()))
          {
            player.movePlayer(plot, player.getX() - speed, player.getY());
          }
        }
        if(plot.getKey() == 'Q')
          player.setAlive(false);
      }

    //END OF PLAYER ***********************************************************
  }


  return 0;

}
