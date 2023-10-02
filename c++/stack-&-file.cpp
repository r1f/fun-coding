#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<ctime>
#include <fstream>

using namespace std;
int variant;

struct stack
{
	int info;
	stack* next;
}*begin, *t;


stack* inStack(stack* p, int in)
{
	stack* t = new stack;
	t->info = in;
	t->next = p;
	return t;
}

void view(stack* p)
{
	ofstream file;
	file.open("result.txt");
	file << "Variant - " << variant << endl;
	stack* t = p;
	while (t != NULL)
	{
		file << " " << t->info << endl;
		cout << " " << t->info << endl;
		t = t->next;
	}
	file.close();
}

int main()
{
	stack* inStack(stack*, int);
	void view(stack*);
	srand(time(NULL));
	int index, in, code, value, max;
	cout << "Input your variant = ";
	cin >> variant;
	max = 2 * variant + 5;
	for (index = 0; index < max;index++)
	{
		in = rand() & 21 - 10;
		begin = inStack(begin, in);
	}
	while (true)
	{
		cout << "Add\t - 1.\nView\t - 2.\nExit\t - 0. " << endl;
		cin >> code;
		switch (code)
		{
		case 1:
			cout << "Input the value = ";
			cin >> value;
			for (index = 0; index <= value; index++)
			{
				in = rand() & 21 - 10;
				begin = inStack(begin, in);
			}
			if (code == 1)
			{
				cout << "Stack = " << value << " elements" << endl;
			}
			else
			{
				cout << "Add " << value << endl;
			}
			break;
		case 2:
			if (!begin)
			{
				cout << "Stack is empty" << endl;
				view(begin);
				break;
			}
			cout << "----Stack----" << endl;
			view(begin);
			break;
		case 0:
			system("pause");
			return 0;
		}
	}
}