#include <windows.h>
#include "MazeMap.h"

class MazePerson
{
public:
    MazePerson(char c = 'O',int count = 0);   // ���캯��
    ~MazePerson();  // ��������
    void Start();   // ��ʼ����
    void Turn(int x,int y,MazeMap maze);    // ת�亯��
    void Gotoxy(int x,int y);
    void setPersonPosi(int x, int y);
    void move();
    void setSpeed(int speed);
    MazeMap maze;
private:
    char p_Shape;   // �˵���״
    int p_Direction;    // �˵ĳ���
    COORD p_Position;   // �˵ĵ�ǰλ��
    COORD p_LastPosition; // �˵�ǰһ��λ��
    int count;  // �ǲ�
    int speed;
};
