#include<iostream>
#include<stdio.h>

using namespace std;

struct WORKER
{
	char Name[20], lastName[20];
	char post[20];
	int enterYear;
	WORKER *next;
};

WORKER* head=0;
WORKER* current;

void SortByYear() {
	WORKER* temp, * temp2, * pos1, * pos2;
	if (head == NULL)
		return;

	for (bool go = true; go; ) 
	{
		go = false;
		pos1 = temp = head;
		pos2 = head->next;

		while (pos2 != NULL) 
		{
			if (pos1->enterYear < pos2->enterYear) 
			{
				if (temp == pos1)
				{
					head = pos2;
				}
				else
				{
					temp->next = pos2;
				}
				pos1->next = pos2->next;
				pos2->next = pos1;

				temp2 = pos1, pos1 = pos2, pos2 = temp2;
				go = true;
			}
			temp = pos1;
			pos1 = pos1->next;
			pos2 = pos2->next;
		}
	}
}

int main()
{
	int c;
	double average=0.0;
	int col=0;
	cout << "Enter the information about worker? (1/0)" << endl;;
	cin >> c;
	cout << endl;
	while (c == 1)
	{
		if (head)
		{
			current->next = new WORKER;
			current = current->next;
		}
		else
		{
			head = new WORKER;
			current = head;
		}
		cout << "Enter the information:" << endl;;
		cout << "Last Name: ";
		cin >> current->lastName;
		cout << "Name: ";
		cin >> current->Name;
		cout << "Post: ";
		cin >> current->post;
		cout << "Enter Year: ";
		cin >> current->enterYear;
		average += current->enterYear;
		col++;
		current->next = 0;
		cout << endl << "Enter the information about worker? 1/0" << endl;;
		cin >> c;
	}
	SortByYear();
	if (head)
	{
		cout << endl << "The workers list: " << endl;
		current = head;
		while (current != 0)
		{
			cout << "Last name: " << current->lastName << endl;
			cout << "Name: " << current->Name << endl;
			cout << "Post: " << current->post << endl;
			cout << "Enter Year: " << current->enterYear << endl << endl;;
			current = current->next;
		}
	}
	average = average / col;
	if (head)
	{
		cout <<endl<< "The workers who haveragee enter year less then averagearage: " << endl;
		current = head;
		while (current != 0)
		{
			if(current->enterYear<average)
			{
				cout << "Last name: " << current->lastName << endl;
				cout << "Enter Year: " << current->enterYear << endl;
			}
			current = current->next;
		}
	}
	return 0;
}