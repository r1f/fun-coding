#include <iostream>
#include <string>
#include <fstream>

using namespace std;


struct STUDENT
{
    string name;
    int group;
    double marks[4];
    double test[4];
    double rating = 0.0;
};

int main()
{
    STUDENT student[20];
    int n;
    cout << "Enter the amout of students ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1;
        cout << endl << "Enter name of student : ";
        cin >> student[i].name;
        cout << endl << "Group : ";
        cin >> student[i].group;
        cout << endl << "1.Physics mark : ";
        cin >> student[i].marks[0];
        cout << endl << "2.Chemistry mark : ";
        cin >> student[i].marks[1];
        cout << endl << "3.Higher mathematics mark : ";
        cin >> student[i].marks[2];
        cout << endl << "4.Programming mark : ";
        cin >> student[i].marks[3];
        cout <<endl<< "Test 1: ";
        cin >> student[i].test[0];
        cout << endl << "Test 2: ";
        cin >> student[i].test[1];
        cout << endl << "Test 3: ";
        cin >> student[i].test[2];
        cout << endl << "Test 4: ";
        cin >> student[i].test[3];

    }
    ofstream file;
    file.open("result.txt");
    file << "Academic failure : " << endl << endl;
    for (int j = 0; j < n; j++)
    {
        for (int i2 = 0; i2 < 4;i2++)
        {
            if (student[j].marks[i2] < 4 || student[j].test[i2] < 4)
            {
                file << "NAME : " << student[j].name << endl;
                file << "GROUP : " << student[j].group << endl;
                i2 = 4;
            }
        }
        for (int i1 = 0; i1 < 4; i1++)
        {
            if (student[j].marks[i1] < 4)
            {
                 switch (i1)
                {
                case 0:
                    file << "Fail exam is Physics: " << student[j].marks[i1] << endl;
                    break;
                case 1:
                    file << "Fail exam is Chemistry: " << student[j].marks[i1] << endl;
                    break;
                case 2:
                    file << "Fail exam is Higher mathematics: " << student[j].marks[i1] << endl;
                    break;
                case 3:
                    file << "Fail exam is Programming: " << student[j].marks[i1] << endl;
                    break;
                default:
                    break;
                }
            }
        }
        for (int j1 = 0; j1 < 4; j1++)
        {
            if (student[j].test[j1] < 4)
            {
                switch (j1)
                {
                case 0:
                    file << "Fail test is " << j1+1 << " : " << student[j].test[j1] << endl;
                    break;
                case 1:
                    file << "Fail test is " << j1+1 << " : " << student[j].test[j1] << endl;
                    break;
                case 2:
                    file << "Fail test is " << j1+1 << " : " << student[j].test[j1] << endl;
                    break;
                case 3:
                    file << "Fail test is " << j1+1 << " : " << student[j].test[j1] << endl;
                    break;
                default:
                    break;
                }
            }
        }
    }
    int enteredGroup;
    cout << "Enter the group : " << endl;
    cin >> enteredGroup;
    file << endl << "Group " << enteredGroup << endl << endl;
        for (int i = 0; i < n; i++)
    {
        if (student[i].group == enteredGroup)
        {
            file << "NAME : " << student[i].name << endl;
            file << "GROUP : " << student[i].group << endl;
            student[i].rating = (student[i].marks[0] + student[i].marks[1] + student[i].marks[2] + student[i].marks[3]
                +student[i].test[0]+student[i].test[1]+ student[i].test[2] + student[i].test[3] ) / 8;
            file << "RAITING : " << student[i].rating << endl;
        }
    }
    file.close();
    return 0;
}
