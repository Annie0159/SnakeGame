#include "Snake.h"
#include<windows.h>
#include<vector>
#define WIDTH 50
#define HEIGHT 30
Snake::Snake(COORD pos)
{
    this->pos=pos;
    len=1;
    snakeBody.push_back(pos);
}
COORD Snake:: getSnakepos()
{
    return pos;
}
void Snake::moveSnake()
{
    switch(dir)
    {
    case 'u':
        pos.Y--;
        break;
    case 'd':
        pos.Y++;
        break;
    case 'l':
        pos.X--;
        break;
    case 'r':
        pos.X++;
        break;
    }
    snakeBody.push_back(pos);
    if(snakeBody.size()>len)
        snakeBody.erase(snakeBody.begin());
}
void Snake::setDir(char c)
{
    dir=c;
}
bool Snake::collided()
{
    if(pos.X==0 || pos.Y==0 || pos.X==WIDTH+1 ||pos.Y==HEIGHT+1)
    {
        return true;
    }
    return false;
}

bool Snake::eaten(COORD FoodPos)
{
    if(FoodPos.X==pos.X && FoodPos.Y==pos.Y)
    {
        return true;
    }
    return false;
}

void Snake::grow()
{
    len++;
}

vector<COORD> Snake:: getSnakeBody()
{
    return snakeBody;
}
