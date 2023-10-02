#include <iostream>
#include <windows.h>

using namespace std;

HANDLE letter = GetStdHandle(STD_INPUT_HANDLE);

struct stack
{
	int data;
	stack* next;
};
stack* top;

stack* add(stack* p, int in)
{
	stack* t = new stack;
	t->data = in;
	t->next = p;
	return t;
}

void deleteTop(stack** p)
{
	if (*p == NULL)
	{
		cout << "Stack is already clear!" << endl << endl;
		exit;
	}
	stack* t;	
	if (*p != NULL) 
	{
		t = *p;
		*p = (*p)->next;
		delete t;
		cout << "The top was removed" << endl << endl;
	}
}

void deleteStack(stack** p)
{
	if (*p == NULL)
	{
		cout << "Stack is already clear!" << endl<<endl;
		exit;
	}
	stack* t;
	if (*p != NULL)
	{
		while (*p != NULL)
		{
			t = *p;
			*p = (*p)->next;
			delete t;
		}
		cout << "Stack was deleted!" << endl << endl;
	}
}

void show(stack* p)
{
	stack* t = p;
	while (t != NULL) 
	{
		cout << " " << t->data << endl;
		t = t->next;
	}
	if (top == NULL)
	{
		cout << "Stack is already clear!" << endl<<endl;
	}
}

stack* exchange(stack* top, int val)
{
	if (top == NULL)
	{
		cout << "Stack is empty" << endl;
		return top;
	}
	stack* t = top->next, * head = top, * value = top;
	int temp;
	while (t != NULL)
	{
		if (t->data == val)
		{
			value = t;
			break;
		}
		t = t->next;
	}
	if (value != t) cout <<endl<< "Enter the value which is already in the stack!"<<endl;
	temp = value->data;
	value->data = head->data;
	head->data = temp;
}

void waitDigits(int& a)
{
	const int count = 10;
	INPUT_RECORD IR[count];
	DWORD read;
	while (PeekConsoleInputA(letter, IR, count, &read)) 
	{
		for (int i = 0; i < read; i++)
			if (IR[i].EventType == KEY_EVENT && isdigit(IR[i].Event.KeyEvent.wVirtualKeyCode)) 
			{
				cin >> a;
				return;
			}
		FlushConsoleInputBuffer(letter);
	}
}

int main()
{
	int value=0, option, num;
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	system("color 02");
	do
	{
		cout << "1. Create the stack" << endl;
		cout << "2. Add an elements in stack" << endl;
		cout << "3. Delete the stack" << endl;
		cout << "4. Delete the top" << endl;
		cout << "5. Show the stack" << endl;
		cout << "6. Swap" << endl;
		cout << "7. About program" << endl;
		cout << "0. Exit" << endl;
		cout << "Operation is ";
		waitDigits(option);
		cout << endl;
		switch (option)
		{
		case 0:
			cout << endl << "Thanks for using our program! Have a good day!"<<endl;
			break;
		case 1:
			cout << "Amount : ";
			waitDigits(num);
			for (int i = 0; i < num; i++)
			{
				cout << "Value : ";
				waitDigits(value);
				top = add(top, value);
			}
			cout << endl;
			break;
		case 2:
			cout << "Amount : ";
			waitDigits(num);
			for (int i = 0; i < num; i++)
			{
				cout << "Value : ";
				waitDigits(value);
				top = add(top, value);
			}
			cout << endl;
			break;
		case 3:
			deleteStack(&top);
			break;
		case 4:
			deleteTop(&top);
			break;
		case 5:
			if (top != NULL)
			{
				cout << "--STACK--" << endl;
			}
			show(top);
			if (top != NULL)
			{
				cout << "---------" << endl;
			}
			break;
		case 6:
			if (top == NULL)
			{
				cout << "Stack is already clear!" << endl << endl;
				break;
			}
			cout << "Value : ";
			waitDigits(value);
			top=exchange(top, value);
			cout << endl;
			break;
		case 7:
			cout << "This program was made by Vlad" << endl;
			cout << "Version 2.0 by 08.12.20" << endl << endl;
			break;
		default: cout << "You have entered a wrong value! Please enter the correct value." << endl<<endl;
		}
	} while (option != 0);
}