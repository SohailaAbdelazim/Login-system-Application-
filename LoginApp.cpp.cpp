// FCAI – Programming 1 – 2022 - Assignment 4.
// Program Name: CS112-203-2nd - S9,10 -20210090-20210492-20211109-A4- LoginApp.cpp
// Last Modification Date: 13/05/2022
// Author1 and ID and Group: Basmala Mohamed Sayed Gad  ID: 20210090  Group: s10 - Functions : 1 - 5
// Author2 and ID and Group: Sohaila Abdelazim Khalifa  ID: 20210492  Group: s10 - Functions : 6 - 10
// Author3 and ID and Group: Hadeer Abdelnasser         ID: 20211109  Group: s10 - Functions : 11 - 15
// Teaching Assistant: Afaf Abdelmonem
/* Purpose: The purpose of this program is to allow a new user to register in the system or to login to the system as
   he already registered earlier , or he can change his password .*/

#include "loginlib.h"


// userInformation ---> main struct
// information ---> passing parameter struct
// user ---> parameter struct of functions

int main() {
    map<string, userInformation> fileInformation;
    fstream file;
    userInformation information;
    string choice;
    while(true) {
        cout
                << " ________________________________________________________________________________" << "\n"
                << "|                                                                                " << "|" << "\n"
                << "|_________________________ Welcome To SBH LOGIN SYSTEM __________________________" << "|" << "\n"
                << "|"                       << "-- Please select an option :                                                    " << "|" << "\n"
                << "|"                       << "1. Register                                                                     " << "|" << "\n"
                << "|"                       << "2. login                                                                        " << "|" << "\n"
                << "|"                       << "3. change password                                                              " << "|" << "\n"
                << "|"                       << "4. Exit                                                                         " << "|" << "\n"
                << "|________________________________________________________________________________" << "|" << "\n" ;

        cin >> choice;

        if (choice == "1" )
        {
            Register(file,information);
        }

        else if (choice == "2" )
        {
            Login(file,information,fileInformation);
        }

        else if (choice == "3" )
        {
            ChangePassword(file,information,fileInformation);
        }

        else if (choice == "4" )
        {
            string s ;
            cout << "Thank you for using SBH Login system ! \n" << " We hope you had an enjoyable experience with us! \n";
            cout << "please press 0 to terminate the program. \n";
            cin >> s ;
            break ;
        }

        else
        {
            cout << "Please enter valid choice: " << "\n";
            cin >> choice;
        }

    }

    return 0;

}
