#include <iostream>

using namespace std;

int main()
{
  char str[100];
  int buff, keyLast = 0;  int item = 0;
  cout << "Enter a string: " << endl;
  cin.get(str, 100);

  while (str[item] == ' ' && str[item] != '\0')
    item++;
    buff = 0;
  while (str[item] != '\0') {
    if (str[item] != ' ' && buff == 0)
    {
      tmp = 1;
      keyLast++;
    }
    else if (str[item] == ' ')
      buff = 0;
    item++;
  }
  cout << "Number of last word is :" << keyLast;
  return 0;
}