#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<ctime>

using namespace std;
int col;
struct TREE
{
	int dann;
	TREE* pLeft;
	TREE* pRight;
};

TREE* maketree(int n)
{
	srand(time(NULL));
	TREE* ptr;
	int nLeft, nRight, m=n;
	if (n==0)
	{
		return NULL;
	}
	nLeft = n / 2;
	nRight = n - nLeft - 1;
	ptr = new(TREE);
	for (int i = 0; i < m; i++)
	{
		ptr->dann = rand() % 20 - 10;
	}
	ptr->pLeft = maketree(nLeft);
	ptr->pRight = maketree(nRight);
	col++;
	return(ptr);
}

void gotoxy(int xPos, int yPos)
{
	COORD scrn;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xPos;
	scrn.Y = yPos;
	SetConsoleCursorPosition(hOutput, scrn);
}

void print(TREE* ptr, int x, int y) 
{
	static int level = 0;
	if (ptr!=NULL)
	{
		level++;
		int delta = 80 / (2 << (level + 1));
		gotoxy(x, y);
		cout << ptr->dann;
		int savedlevel = level;
		print(ptr->pRight, x - delta, y + 1);
		level = savedlevel;
		print(ptr->pLeft, x + delta, y + 1);
	}
}

int main()
{
	TREE* ptr;
	int n, variant;
	cout << "Enter the variant: ";
	cin >> variant;
	n = 2 * variant + 10;
	ptr = maketree(n);
	print(ptr, 20, 2);
	cout <<endl<<"The amount of knots: "<< col;
	return 0;
}