#ifndef SNAKE_H
#define SNAKE_H
#include<windows.h>
#include<vector>

#define WIDTH 50
#define HEIGHT 30
using namespace std;
class Snake
{
private:
    COORD pos;
    int len;
    char dir;
    vector<COORD> snakeBody;
public:
    Snake(COORD pos);
    COORD getSnakepos();
    void setDir(char c);
    void moveSnake();
    bool collided();
    bool eaten(COORD FoodPos);
    void grow();
    vector<COORD> getSnakeBody();
};

#endif // SNAKE_H
