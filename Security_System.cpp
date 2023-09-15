#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    int a, i = 0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word2;
    string cred[2], cp[2];
    cout << "|-------------------|" << endl;
    cout << "|  Security System  |" << endl;
    cout << "|-------------------|" << endl;
    cout << "|1. Register        |" << endl;
    cout << "|2. Login           |" << endl;
    cout << "|3. Change Password |" << endl;
    cout << "|4. End Program     |" << endl;
    cout << "|-------------------|" << endl
         << endl;

    do
    {
        cout << endl
             << endl;
        cout << "Enter the choice :-" << endl;
        cin >> a;
        switch (a)
        {
        case 1:
        {
            cout << "|---------------------------|" << endl;
            cout << "|          Register         |" << endl;
            cout << "|---------------------------|" << endl
                 << endl;
            cout << "  Enter the user name :-" << endl;
            cin >> name;
            cout << " Please enter the password :- " << endl;
            cin >> password0;
            cout << " Please enter the your age :-" << endl;
            cin >> age;

            ofstream of1;
            of1.open("Securuity_system.txt");
            if (of1.is_open())
            {
                of1 << name << "\t";
                of1 << password0;
                cout << " Registration is successfull " << endl;
            }
            break;
        }

        case 2:
        {
            cout << "|---------------|" << endl;
            cout << "|1.Login        |" << endl;
            cout << "|---------------|" << endl;

            ifstream of2;
            of2.open("file.txtx");
            cout << " Please enter the user name " << endl;
            cin >> user;
            cout << "enter the password " << endl;
            cin >> pass;
            if (of2.is_open())
            {
                while (!of2.eof())
                {
                    while (getline(of2, text))
                    {
                        istringstream iss(text);
                        iss >> word;
                        cred[i] = word;
                        i++;
                    }
                    if (user == cred[0] && pass == cred[1])
                    {
                        cout << "-----login--complete------ " << endl
                             << endl;
                        cout << "-----Details------" << endl;
                        cout << " Username :- " + user << endl;
                        cout << " Password :- " + pass << endl;
                        cout << "Age :- " + age << endl;
                    }
                    else
                    {
                        cout << endl
                             << endl;
                        cout << "---Incorrect Credential---" << endl;
                        cout << "|=============================|" << endl;
                        cout << "|1. Press 2 to login          |" << endl;
                        cout << "|2. Press 3 to Change Password|" << endl;
                        cout << "|=============================|" << endl;
                        break;
                    }
                }
            }
            break;
        }
        case 3:
        {
            i = 0;
            cout << "---change Password-----" << endl;
            ifstream of0;
            of0.open("file.txt");
            cout << " Enter the old password " << endl;
            cin >> old;
            if (of0.is_open())
            {
                while (of0.eof())
                {
                    while (getline(of0, text))
                    {
                        istringstream iss(text);
                        iss >> word;
                        cp[i] = word;
                    }
                    if (old == cp[1])
                    {
                        of0.close();
                        ofstream of1;
                        if (of1.is_open())
                        {
                            cout << "Enter your new password " << endl;
                            cin >> password1;
                            cout << "Enter the password again " << endl;
                            cin >> password2;
                            if (password1 == password2)
                            {
                                of1 << cp[0] << "\n";
                                of1 << password2;
                                cout << " Password change successfully " << endl;
                            }
                            else
                            {
                                of1 << cp[0] << "\n";
                                of1 << old;

                                cout << "Password is not matched " << endl;
                            }
                        }
                    }
                    else
                    {
                        cout << "Please enter the valid password " << endl;
                    }
                }
            }

            break;
        }
        case 4:
        {
            cout << "--------Thank you------- " << endl;
            break;
        }
        default:
        {
            cout << "Please Enter right choice " << endl;
        }
    }
    }
     while (a<4);
    return 0;
}