#include "MazePerson.h"
#include <iostream>
using namespace std;

MazePerson::MazePerson(char c,int count)   // ���캯��
{
    p_Shape = c;
    this->count = count;
}
MazePerson::~MazePerson()  // ��������
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
void MazePerson::Gotoxy(int x,int y)  // ��ͬ����ǰ���ĺ���
{
    COORD cd;
    cd.X = x;
    cd.Y = y;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle,cd);
}
void MazePerson::Start()   // ��ʼ����
{
    p_Direction = 1;    // Ĭ�Ͽ�ʼ����ת
    while(maze.inBorder(p_Position.X,p_Position.Y))
    {// ���һֱ���Թ�����һֱ����ȥ��ֱ���߳��Թ�
        Turn(p_Position.X,p_Position.Y,maze);   // �жϵ�ǰλ����Ҫ���ת�򣬲��Ҹı�p_Position.X��p_Positon.Y��ֵ
        move(); // �����Ƶ��Ǹ�λ��
    }
}

void MazePerson::move()
{
    Gotoxy(p_LastPosition.X,p_LastPosition.Y);  // �ѵ�ǰλ�õ��ַ�����
    cout<<' ';
    count++;
    Gotoxy(p_Position.X,p_Position.Y);  // ���µ�λ������ַ�
    if(maze.inBorder(p_Position.X,p_Position.Y))
        cout<<p_Shape;
    Gotoxy(0,10);
    cout<<"������"<<count<<endl;
    cout<<"��ǰλ��Ϊ��("<<p_Position.X<<','<<p_Position.Y<<')'<<endl;
    Sleep(speed);
    p_LastPosition.X = p_Position.X;
    p_LastPosition.Y = p_Position.Y;
}

void MazePerson::Turn(int x,int y,MazeMap maze)    // ת�亯��
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
        {// ���������ת
            p_Direction = (p_Direction + 3)%4;
            p_Position.X = d_x;
            p_Position.Y = d_y;
        }else if(maze.m_Map[w_y][w_x] == ' '||!maze.inBorder(w_y,w_x))
        {// �������ֱ��
            p_Position.X = w_x;
            p_Position.Y = w_y;
        }else if(maze.m_Map[a_y][a_x] == ' ')
        {// �������������
            p_Direction = (p_Direction + 1)%4;
            p_Position.X = a_x;
            p_Position.Y = a_y;
        }else{//ֻ�ܺ���
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
