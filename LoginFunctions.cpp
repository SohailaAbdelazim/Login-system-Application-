#include "loginlib.h"

//______________________________________REGISTER__________________________________________
void Register(fstream& dataFile ,userInformation& user)
{
    cout << "Please, enter your name: \n";
    cin.sync();
    cin.clear();
    getline(cin, user.name);

    while (checkNameFormat(user.name) == false)
    {
        cout << "Invalid format of name, please enter correct format name:" << "\n";
        cin.sync();
        cin.clear();
        getline(cin, user.name);
    }

    cout << "Please, enter your mobile phone: \n";
    cin >> user.mobileNumber;

    while(( user.mobileNumber.length() < 11)||( user.mobileNumber.length() > 11))
    {
        cout << "Invalid number, please enter correct number length (11 digits):" << "\n";
        cin >>  user.mobileNumber;
    }
    while (checkMobileFormat( user.mobileNumber) == false)
    {
        cout << "Invalid format of mobile number, please enter correct format:" << "\n";
        cin >>  user.mobileNumber;
    }

    cout << "Please, enter your Email: \n";
    cin >> user.email;

    while (checkEmailFormat(user.email) == false)
    {
        cout << "Invalid format of email, please enter correct format:" << "\n";
        cin >> user.email;
    }

    cout << "Please, enter the username: \n";
    cin >> user.userName;

    cout << "Please, enter your password\n";
    displayLettersAllowed();
    user.password = checkRepeatedPassword(user.password);
    while (checkStrongPassword(user.password) == false){
        displayLettersAllowed();
        user.password = checkRepeatedPassword(user.password);
    }

    checkInformation(dataFile,user);
    user.password = encryptPassword(user.password);
    dataFile.open("Data.txt", ios::app);
    dataFile << user.name << '\n' << user.mobileNumber << '\n' << user.email << '\n' << user.userName << '\n'
             << user.password << '\n';
    dataFile.close();
    cout << "Register is Successful, please press 0 to exit. \n ";
    string exit;
    cin >> exit;
    while (exit != "0"){
        cout << "Please press 0 to exit.\n";
    }
}

void checkInformation(fstream& dataFile, userInformation& user)
{
    vector<string> text;
    string line;
    dataFile.open("Data.txt");

    while(!dataFile.eof()){
        dataFile >> line;
        text.push_back(line);
    }
    dataFile.close();

    if (text.size() == 0)
    {
        while (find(text.begin(),text.end(),user.userName) != text.end()) {
            cout << "Already Exist, Please enter new ID: \n";
            cin >> user.userName;
        }
        while (find(text.begin(),text.end(),user.email) != text.end()){
            cout << "Already Exist, Please enter new email: \n";
            cin >> user.email;
            checkEmailFormat(user.email);
        }
    }
}

bool checkEmailFormat(string& checkEmail)
{
    regex emailFormat("[A-Za-z0-9#!%$‘&+*–/=?^_`{|}~]+(.?)[A-Za-z0-9#!%$‘&+*–/=?^_`{|}~]+@[A-Za-z]+(-?)[A-Za-z0-9]+(.)(com|edu|net)");
    return regex_match(checkEmail,emailFormat);
}

bool checkMobileFormat(string& checkMobile)
{
    regex mobileFormat("(010|011|012|015)[0-9]+");
    return regex_match(checkMobile,mobileFormat);
}

bool checkNameFormat(string &checkName)
{
    regex nameFormat("[A-Za-z' -]+");
    return regex_match(checkName, nameFormat);
}

void displayLettersAllowed()
{
    cout << "Your password must contain and be in the following format:\n"
            "- At least 8 characters\n"
            "- contain each one of the following: uppercase, lowercase, numeric and special characters.\n"
            "- The allowed special characters are ~ ! @ # $ % ^ * _ = +  { } / ; : , . ?  [no spaces allowed!]\n";
}

string checkRepeatedPassword(string password)
{
    string repeatedPassword;

    cout << "Please enter your password : \n";
    password = coverPassword();
    cout << "Please re enter your password : \n";
    repeatedPassword = coverPassword();

    while (password != repeatedPassword)
    {
        cout << "Invalid, the two passwords entered are not equal.\nplease re enter your passwords\n";
        cout << "Please enter your password : \n";
        password = coverPassword();
        cout << "Please re enter your password : \n";
        repeatedPassword = coverPassword();
    }

    return password;
}

bool checkStrongPassword(string password)
{
    bool alphaC = false , alphaS = false  , digit = false  , specialC = false;

    while ( password.length() < 8 ){
        cout << "Not strong enough ! , please enter password with at least 8 characters : \n";
        password = coverPassword();
    }


    for (int i = 0; i < password.length(); ++i) {
        if (isalpha(password[i])){
            if( password[i] <=  90  && password[i] >= 65 ){
                alphaC = true ;
            }
            else if ( password[i] <=  122  && password[i] >= 97 ){
                alphaS = true ;
            }
        }
        else if (isdigit(password[i]) ){
            digit = true ;
        }
        else if (ispunct(password[i]) ) {

            specialC = true ;
        }

    }
    if ( (alphaC == true) && (alphaS == true) && (digit == true ) && (specialC == true) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

string coverPassword()
{
    char character;
    string pass;
    character = _getch();

    while(character != '\r'){
        if (isalpha(character) || isdigit(character) || ispunct(character)){
            cout << '*';
            pass += character;
        }
        else if (character == '\b') {
            cout << "\b \b";
            pass.pop_back();
        }
        character = _getch();
    }
    cout << "\n";
    return pass;
}

string encryptPassword(string password)
{
    char letters[] = {'A',  'B',  'C', 'D', 'E',  'F',  'G',  'H',  'I',  'J', 'K', 'L',
                      'M', 'N', 'O', 'P','Q', 'R', 'S', 'T', 'U', 'V',
                      'W', 'X', 'Y', 'Z','a', 'b', 'c', 'd', 'e', 'f',
                      'g', 'h', 'i', 'j', 'k','l', 'm', 'n', 'o', 'p',
                      'q', 'r', 's', 't', 'u','v', 'w', 'x', 'y', 'z' ,
                      '0', '1', '2', '3', '4','5', '6', '7', '8',
                      '9', '~', '!', '@', '#','$', '%', '^', '*',
                      '_', '=', '+', '{', '}',';', ':', ',', '.', '?' };

    string encryptedPassword = "";

    for (int i = 0; i < password.length(); i++)
    {
        for (int j = 0; j < 79 ; ++j)
        {
            if (password[i] == letters[j])
            {

                int index = (j + 1) % 79;
                encryptedPassword += letters[index];
            }
        }
    }

    password = encryptedPassword;
    return password;
}




//______________________________________LOGIN__________________________________________
string Login(fstream& dataFile, userInformation& user, map<string, userInformation> &fileInformation)
{
    loadFileInformation(dataFile, fileInformation);
    string loginUserName, loginPassword;

    int i = 0;
    while (i<3){
        cout << "Please Enter your information to login: \n";
        cout << "Username: ";
        cin  >> loginUserName;
        cout << "Password: ";
        loginPassword = coverPassword();
        loginPassword = encryptPassword(loginPassword);

        string originalPassword;
        originalPassword = fileInformation[loginUserName].password;

        if ((fileInformation.count(loginUserName) == 1) && (originalPassword == loginPassword)){
            cout << "Successful Login, welcome " << fileInformation[loginUserName].name << " :) \n";
            break;
        }
        else
        {
            cout << "Failed Login, Try again.\n";
        }
        i++;
    }
    if (i == 3)
    {
        cout << "YOUR ACCESS IS DENIED FROM THE SYSTEM.\n";
    }
    string exit;
    cout << "Please press 0.\n";
    cin >> exit;
    while (exit != "0"){
        cout << "Please press 0.\n";
    }
    return loginUserName;
}

void loadFileInformation(fstream& dataFile, map<string, userInformation> &fileInformation)
{
    dataFile.open("Data.txt");
    userInformation temp;

    while (!dataFile.eof())
    {
        getline(dataFile,temp.name);
        getline(dataFile,temp.mobileNumber);
        getline(dataFile,temp.email);
        getline(dataFile,temp.userName);
        getline(dataFile,temp.password);
        fileInformation.insert({temp.userName,temp});
    }
    dataFile.close();
}




//______________________________________CHANGE PASSWORD__________________________________________
void ChangePassword(fstream& dataFile, userInformation& user, map<string, userInformation> &fileInformation)
{
    string userName = Login(dataFile,user,fileInformation);

    string oldPassword, newPassword, repeatedNewPassword;
    cout << "Please, enter the old password.\n";
    oldPassword = coverPassword();
    oldPassword = encryptPassword(oldPassword);


    while (oldPassword != fileInformation[userName].password){
        cout << "Wrong old password, please re enter your password : \n";
        oldPassword = coverPassword();
        oldPassword = encryptPassword(oldPassword);
    }

    displayLettersAllowed();
    cout << "Please, enter the newly desired password: \n";

    newPassword = checkRepeatedPassword(newPassword);
    checkStrongPassword(newPassword);
    newPassword = encryptPassword(newPassword);


    fileInformation[userName].password = newPassword;

    dataFile.open("Data.txt", ios::out);

    for (auto element:fileInformation) {
        dataFile << fileInformation[element.first].name << "\n" << fileInformation[element.first].mobileNumber << "\n" << fileInformation[element.first].email
                 << "\n" << fileInformation[element.first].userName << "\n" << fileInformation[element.first].password << "\n";
    }
    dataFile.close();
}
