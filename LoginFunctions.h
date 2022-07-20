#ifndef MAIN_CPP_LOGINLIB_H
#define MAIN_CPP_LOGINLIB_H


#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <conio.h> // for using getch function

using namespace std;
struct userInformation
{
    string name, mobileNumber, email, userName, password;
};

void Register(fstream& dataFile, userInformation& user);
void checkInformation(fstream& dataFile, userInformation& user);
bool checkEmailFormat(string& checkEmail);
bool checkMobileFormat(string& checkMobile);
bool checkNameFormat(string& checkName);
void displayLettersAllowed();
string checkRepeatedPassword(string password);
bool checkStrongPassword(string password);
string coverPassword();
string encryptPassword(string password);

string Login(fstream& dataFile, userInformation& user, map<string, userInformation> &fileInformation);
void loadFileInformation(fstream& dataFile, map<string, userInformation> &fileInformation);

void ChangePassword(fstream& dataFile, userInformation& user, map<string, userInformation> &fileInformation);


#endif //MAIN_CPP_LOGINLIB_H
