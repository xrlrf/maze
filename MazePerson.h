#include <windows.h>
#include "MazeMap.h"

class MazePerson
{
public:
    MazePerson(char c = 'O',int count = 0);   // 构造函数
    ~MazePerson();  // 析构函数
    void Start();   // 开始函数
    void Turn(int x,int y,MazeMap maze);    // 转弯函数
    void Gotoxy(int x,int y);
    void setPersonPosi(int x, int y);
    void move();
    void setSpeed(int speed);
    MazeMap maze;
private:
    char p_Shape;   // 人的形状
    int p_Direction;    // 人的朝向
    COORD p_Position;   // 人的当前位置
    COORD p_LastPosition; // 人的前一个位置
    int count;  // 记步
    int speed;
};
