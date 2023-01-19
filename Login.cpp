#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int c;
    cout << "\t\t\t_________________________________________\n\n\n";
    cout << "\t\t\t         Welcome to login page           \n\n\n";
    cout << "\t\t\t__________        MENU        ___________\n\n\n";
    cout << endl;
    cout << "\t| Press 1 to login          |" << endl;
    cout << "\t| Press 2 to register       |" << endl;
    cout << "\t| Press 3 to reset password |" << endl;
    cout << "\t| Press 4 to exit           |" << endl;
    cout << "\n\t\t\t Please enter your choice : ";
    cin >> c;
    cout << endl;
    
    //list of options for user to choose from
    switch(c)
    {
        case 1:
            login();
            break;

        case 2:
            registration();
            break;

        case 3:
            forgot();
            break;

        case 4:
            cout << "\t\t\t Thank you \n\n";
            break;

        default:
            system("cls");
            cout << "\t\t\t Please select from the options given above \n";
            main();

    }
    
}
    //login function
    void login()
    {
        int count;
        string userId, password, id, pass;
        system("cls");
        cout << "\t\t\t Please enter username and password: " << endl;
        cout << "\t\t\t USERNAME ";
        cin >> userId;
        cout << "\t\t\t PASSWORD ";
        cin >> password;

        ifstream input("records.txt");

        //check if id and password exist in records.txt
        while(input>>id>>pass)
        {
            if(id==userId && pass==password)
            {
                count=1;
                system("cls");
            }
        }
        input.close();

        if(count==1)
        {
            cout << userId << "\n Login succesfull! \n";
            main();
        }
        else
        {
            cout << "\n LOGIN ERROR 404 \n Please check your username or password \n";
            main();
        }
    }

    //registration function
    void registration()
    {
        string ruserId, rpassword, rid, rpass;
        system("cls");
        cout << "\t\t\t Enter username: ";
        cin >> ruserId;
        cout << "\t\t\t Enter password: ";
        cin >> rpassword;

        //record id and password in text file once registered
        ofstream f1("records.txt", ios::app);
        f1 << ruserId << ' ' << rpassword << endl;
        system("cls");
        cout << "\n\t\t\t Registration successfull! \n";
        main();

    }

    //forgot password function
    void forgot()
    {
        int option;
        system("cls");
        cout << "\t\t\t Please follow these steps to find your username and password";
        cout << "Press 1 to search your id by username" << endl;
        cout << "Press 2 to go back to main menu " << endl;
        cout << "\t\t\t Enter your choice :" ;
        cin >> option;

        switch (option)
        {
            //search password based on id in records.txt file
           case 1:
           {
                int count = 0;
                string suserId,sId,spass;
                cout << "\n\t\t\t Enter username you remembered: ";
                cin >> suserId;

                ifstream f2("records.txt");
                while(f2>>sId>>spass)
                {
                    if(sId==suserId)
                    {
                        count = 1;
                    }
                }
                f2.close();
                if(count==1)
                {
                    cout << "\n\n Your account is found! \n";
                    cout << "\n\n Your password is: " << spass;
                    main();
                }
                else
                {
                    cout << "\n\t Sorry! Your account is not found \n";
                    main();
                }
                break;
           }


            //return back to main menu
           case 2:
           {
                main();
           }

           default:
                cout << "\t\t\t Wrong choice! Please try again" << endl;
                forgot();

        }
    }
