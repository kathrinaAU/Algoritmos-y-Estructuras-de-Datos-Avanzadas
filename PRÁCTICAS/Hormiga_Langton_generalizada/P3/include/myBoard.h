#ifndef MYBOARD_H
#define MYBOARD_H

using namespace std;
#include <cstdlib>
#include <iostream>
using namespace std;

class myBoard{
private:
    int width;
	int height;
	char **m_board;

public:
    myBoard();
    myBoard(int cols, int rows);

    int getCols();
    int getRows();

    char getColor(int x, int y);
	void setColor(int x, int y, char color);
    void Bordes();
    void Muro();
};


#endif