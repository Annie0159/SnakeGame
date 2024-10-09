#include <iostream>
#include<windows.h>
#include<conio.h>
#include<vector>

#include "Snake.h"
#include "Food.h"

#define WIDTH 50
#define HEIGHT 30

using namespace std;

Snake snake({WIDTH/2,HEIGHT/2});
Food food;
void board()
{
    vector<COORD> snakeBody=snake.getSnakeBody();
    for(int i=0;i<=HEIGHT+1;i++)
    {
        cout<<"\t\t";
        for(int j=0;j<=WIDTH+1;j++)
        {
            if(i==0||i==HEIGHT+1 ||j==0||j==WIDTH+1)
            {
                cout<<"#";
            }
            else if(i==food.getFoodPos().Y && j==food.getFoodPos().X)
            {
                cout<<"*";
            }
            else
            {
                bool found=false;
                for(int k=0;k<snakeBody.size();k++)
                {
                    if(i==snakeBody[k].Y && j==snakeBody[k].X)
                    {
                        found=true;
                        cout<<"O";
                        break;
                    }
                }
                    if(!found)
                        cout<<' ';
            }
        }
        cout<<endl;
    }
}
int main()
{
    while(true)
    {
        Sleep(100);
        board();
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
        if(kbhit())
        {
            switch(getch())
            {
            case 72:
                snake.setDir('u');
                break;
            case 80:
                snake.setDir('d');
                break;
            case 77:
                snake.setDir('r');
                break;
            case 75:
                snake.setDir('l');
            }
        }
        snake.moveSnake();
        if(snake.collided())
        {
         cout<<"GAME OVER";
            break;
        }
        if(snake.eaten(food.getFoodPos()))
        {
            snake.grow();
            food.setFood();
        }
    }
    return 0;
}
