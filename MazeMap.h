
class MazeMap
{
public:
    MazeMap();
    ~MazeMap();
    void drawMap(int map[][10]);     // 数据封装函数
    bool inBorder(int x,int y);    // 迷宫边界检查函数
public:
    char m_Map[10][10];
};
