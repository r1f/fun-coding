#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string str[255];
	int num;
	cout << "Enter the amount of strings : ";
	cin >> num;
	cout << "Enter the string : ";
	for (int i = 0; i < num; i++)
	{
		cin >> str[i];
	}
	ofstream file;
	file.open("result.txt");
	for (int i = 0; i < num; i++)
	{
		file << str[i] << endl;
	}
	file.close();
	return 0;
}