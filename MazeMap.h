
class MazeMap
{
public:
    MazeMap();
    ~MazeMap();
    void drawMap(int map[][10]);     // ���ݷ�װ����
    bool inBorder(int x,int y);    // �Թ��߽��麯��
public:
    char m_Map[10][10];
};
