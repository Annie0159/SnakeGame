#include "Food.h"
#include<ctime>
#include<windows.h>
#include<stdlib.h>

#define WIDTH 50
#define HEIGHT 30
Food::Food()
{
    srand(time(NULL));
    setFood();
}
void Food::setFood()
{
    foodPos.X=rand()%WIDTH +1;
    foodPos.Y=rand()%HEIGHT +1;
}

COORD Food::getFoodPos()
{
    return foodPos;

}
