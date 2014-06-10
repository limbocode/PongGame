/*
 * Game: Pong Game.
 * Author: Rafael Campos Nunes.
 * License: Apache v2.
 *
 * Fell free to contact me on
 * Email: rafaelnunes737@hotmail.com
 * Github: https://github.com/rafaelcn
 *
 * Also you can contact me on IRC(freenode.net server) my nickname is: ranu.
 */

#ifndef BALL_H
#define BALL_H

#include <SDL2/SDL.h>

#include "paddle.hpp"
#include "sdl_audio.h"

/*Forward class declaration because of the circular #include(The header guard
 * was not working in this case).
 */
class Pong;

class Ball
{
    //Velocity of the ball on the screen.
    double xVelocity, yVelocity;

    /* The surface that will be used to be filled with the image of the ball
     * (ball.bmp).
     */
    SDL_Surface* ballSurface;
    //The texture of the ball(ball.bmp).
    SDL_Texture* ballTexture;
    //The renderer that the ballTexture will use to draw on the screen.
    SDL_Renderer* ballRenderer;
    //SDL_Rect that will represent the size of the ball on the screen.
    SDL_Rect* ballRect;

    bool collision(SDL_Rect* rectangle1, SDL_Rect* rectangle2);


public:
    /* I'll do not use the member initialization to the constructors due to the
     * hight number of arguments  passed  to  the  constructor,  so  it will be
     * initialized on the ball.cpp */
    Ball();
    Ball(SDL_Surface* ballImage, SDL_Renderer** ballRenderer, float xCor,
         float yCor, int width, int height);
    ~Ball();

    void show();
    void move(SDL_Rect* player1, SDL_Rect* player2, Pong* pongObject,
              AudioWrapper* audio);
    void updateGameScore(Paddle* player1, Paddle* player2);

    double getXVelocity();
    double getYVelocity();

    void setXVelocity(double xVelocity);
    void setYVelocity(double yVelocity);

    SDL_Rect* getBallRect();
};

#endif
