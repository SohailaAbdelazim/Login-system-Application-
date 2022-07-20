
// Last Modification Date: 13/05/2022
// Author1  Sohaila Abdelazim Khalifa 
// Author2  Basmala Mohamed Sayed Gad   
// Author3  Hadeer Abdelnasser        
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
