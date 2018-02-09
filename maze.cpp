#include <iostream>
#include "MazePerson.h"
#define FAST 200
#define NORMAL 400
#define SLOW 800
using namespace std;


int main()
{
    int map[10][10] = {
        { 8,8,8,8,8,8,8,8,0,8 },
		{ 8,0,0,0,0,8,0,0,0,8 },
		{ 8,0,8,8,8,0,8,0,8,8 },
		{ 8,0,0,0,8,0,8,0,0,8 },
		{ 8,0,8,0,8,0,0,8,0,8 },
		{ 8,0,8,0,0,0,0,8,0,8 },
		{ 8,0,0,0,8,8,0,8,0,8 },
		{ 8,0,8,0,8,0,0,0,0,8 },
		{ 8,0,0,8,8,0,8,8,0,8 },
		{ 8,8,0,8,8,8,8,8,8,8 },
    };
    MazePerson person;
    person.setSpeed(NORMAL);
    person.maze.drawMap(map);
    person.setPersonPosi(2, 9);
	person.Start();
	cout << "Success!" << endl;
	system("pause");
    return 0;
}
