#include "MazeMap.h"
#include<iostream>
using namespace std;

MazeMap::MazeMap()
{

}
MazeMap::~MazeMap()
{

}
void MazeMap::drawMap(int map[][10])     // ���ݷ�װ����
{
    for(int i = 0 ; i < 10 ; i++)
    {
        for(int j = 0 ; j < 10 ; j++)
        {
            if(map[i][j] == 0)
                m_Map[i][j] = ' ';
            else
                m_Map[i][j] = 'H';
        }
    }
    for(int i = 0 ; i < 10 ; i++)
    {
        for(int j = 0 ; j < 10 ; j++)
            cout<<m_Map[i][j];
        cout<<endl;
    }
}
bool MazeMap::inBorder(int x,int y)    // �Թ��߽��麯��
{
    if(x < 10 && y < 10 && x >= 0 && y >= 0)
        return true;
    return false;
}
