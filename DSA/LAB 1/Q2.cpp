#include <iostream>
using namespace std;


struct Student
{
    int roll, sem;
    char name[30], dept[20], email[40];
    float cgpa;
};

int main()
{
    Student s[100], temp;
    int n = 0, ch, i, j, roll;
    bool found;

    do
    {
      
        cout << "1.Add 2.Search 3.Update 4.Delete 5.Display Sorted 6.CGPA>=8 7.Exit\n";
        cin >> ch;

        switch (ch)
        {
        
        case 1:
            cout << "Roll Name Dept Sem CGPA Email:\n";
            cin >> s[n].roll >> s[n].name >> s[n].dept >> s[n].sem >> s[n].cgpa >> s[n].email;
            n++;
            break;

        // Search Student
        case 2:
            found = false;
            cout << "Enter Roll: ";
            cin >> roll;

            for (i = 0; i < n; i++)
                if (s[i].roll == roll)
                {
                    cout << "found "<< endl;
                    found = true;
                }

            if (!found)
                cout << "Not Found\n";
            break;

        // Update Student
        case 3:
           
            cout << "Enter Roll: ";
            cin >> roll;

            
                    cout << "New Sem CGPA Email:\n";
                    cin >> s[i].sem >> s[i].cgpa >> s[i].email;
                   
            break;

        // Delete Student
        case 4:
            
            cout << "Enter Roll: ";
            cin >> roll;

                if (s[i].roll == roll)
                {
                    for (j = i; j < n - 1; j++)
                        s[j] = s[j + 1];
                    n--;
                 
                    break;
                }

            break;

        // Display Sorted Records
        case 5:
            for (i = 0; i < n - 1; i++)
                for (j = i + 1; j < n; j++)
                    if (s[i].roll > s[j].roll)
                    {
                        temp = s[i];
                        s[i] = s[j];
                        s[j] = temp;
                    }

            for (i = 0; i < n; i++)
                cout << s[i].roll << " " << s[i].name 
                      << endl;
            break;

        // Display CGPA >= 8
        case 6:
            for (i = 0; i < n; i++)
                if (s[i].cgpa >= 8)
                    cout << s[i].roll << " "
                         << s[i].cgpa << endl;
            break;

        // Exit
        case 7:
            cout << "Exit\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (ch != 7);

    return 0;
}