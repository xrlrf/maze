#include "MazePerson.h"
#include <iostream>
using namespace std;

MazePerson::MazePerson(char c,int count)   // 构造函数
{
    p_Shape = c;
    this->count = count;
}
MazePerson::~MazePerson()  // 析构函数
{

}
void MazePerson::setPersonPosi(int x, int y)
{
    p_Position.X = x;
    p_Position.Y = y;
    p_LastPosition.X = x;
    p_LastPosition.Y = y;
    Gotoxy(p_Position.X,p_Position.Y);
    cout<<p_Shape;
}
void MazePerson::Gotoxy(int x,int y)  // 向不同方向前进的函数
{
    COORD cd;
    cd.X = x;
    cd.Y = y;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle,cd);
}
void MazePerson::Start()   // 开始函数
{
    p_Direction = 1;    // 默认开始向右转
    while(maze.inBorder(p_Position.X,p_Position.Y))
    {// 如果一直在迷宫，则一直走下去，直到走出迷宫
        Turn(p_Position.X,p_Position.Y,maze);   // 判断当前位置需要如何转向，并且改变p_Position.X和p_Positon.Y的值
        move(); // 讲人移到那个位置
    }
}

void MazePerson::move()
{
    Gotoxy(p_LastPosition.X,p_LastPosition.Y);  // 把当前位置的字符消掉
    cout<<' ';
    count++;
    Gotoxy(p_Position.X,p_Position.Y);  // 在新的位置添加字符
    if(maze.inBorder(p_Position.X,p_Position.Y))
        cout<<p_Shape;
    Gotoxy(0,10);
    cout<<"步数："<<count<<endl;
    cout<<"当前位置为：("<<p_Position.X<<','<<p_Position.Y<<')'<<endl;
    Sleep(speed);
    p_LastPosition.X = p_Position.X;
    p_LastPosition.Y = p_Position.Y;
}

void MazePerson::Turn(int x,int y,MazeMap maze)    // 转弯函数
{
    int w_x,w_y,a_x,a_y,s_x,s_y,d_x,d_y;
    switch(p_Direction)
    {
    case 0:
        w_x = x; w_y = y-1;a_x = x-1;a_y = y;s_x = x;s_y = y+1;d_x = x+1;d_y = y;
        break;
    case 1:
        w_x = x-1; w_y = y;a_x = x;a_y = y+1;s_x = x+1;s_y = y;d_x = x;d_y = y-1;
        break;
    case 2:
        w_x = x; w_y = y+1;a_x = x+1;a_y = y;s_x = x;s_y = y-1;d_x = x-1;d_y = y;
        break;
    case 3:
        w_x = x+1; w_y = y;a_x = x;a_y = y-1;s_x = x-1;s_y = y;d_x = x;d_y = y+1;
        break;
    default:;
    }
    if(maze.inBorder(x,y))
        if(maze.m_Map[d_y][d_x] == ' ')
        {// 如果可以右转
            p_Direction = (p_Direction + 3)%4;
            p_Position.X = d_x;
            p_Position.Y = d_y;
        }else if(maze.m_Map[w_y][w_x] == ' '||!maze.inBorder(w_y,w_x))
        {// 如果可以直行
            p_Position.X = w_x;
            p_Position.Y = w_y;
        }else if(maze.m_Map[a_y][a_x] == ' ')
        {// 如果可以向左走
            p_Direction = (p_Direction + 1)%4;
            p_Position.X = a_x;
            p_Position.Y = a_y;
        }else{//只能后退
            p_Direction = (p_Direction + 2)%4;
            p_Position.X = s_x;
            p_Position.Y = s_y;
        }
    else{
        p_Position.X = x;
        p_Position.Y = y;
    }

}

void MazePerson::setSpeed(int speed)
{
    this->speed = speed;
}
