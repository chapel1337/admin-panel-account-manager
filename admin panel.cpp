#include <iostream>
#include <string>
#include <windows.h>

// written by chapel1337
// started making this yesterday night (9/27/2022), but was being crushed by homework
// finished making this also at night on 9/28/2022 (today)
// my largest and most ambitious project yet™
// 475 lines
// probably could've made this into multiple linked files
// i recommend running this with administrator permissions enabled for it to fully work

using std::cout; using std::string; using std::cin;

bool firstOpen{ false };
string returnFunction{};

char menuResponse{};
string quitResponse{};
char accountsResponse{};
char settingsResponse{};

string accountName{};
string renameAccountResponse{};

string accountPassword{};
string changePasswordResponse{};

string deletedAccount{};
string deleteAccountResponse{};

string textColor{};
string backgroundColor{};
string colorResponse{};

string title{};
string titleResponse{}; // just realized i could've made a universal response, oh well : ( (lol)

string colorsList[]{ "black", "blue", "green", "aqua", "red", "purple", "yellow", "white", "gray", "light blue", "light green", "light aqua", "light red", "light purple", "light yellow", "bright white"};

std::string read()
{
    std::string s{};
    std::getline(std::cin >> std::ws, s);
    return s;
}

void clear()
{
    system("cls");
}

void menu();
void back();
void settings();

void invalidInput()
{
    clear();
    cout << "invalid input\n";

    Sleep(1000);
    back();
}

void renameAccount()
{
    clear();

    cout << "new account name: \n";
    accountName = read();

    clear();

    cout << "are you sure you want to change your account name? (y/n)\n";
    cin >> renameAccountResponse;

    if (renameAccountResponse == "y" || renameAccountResponse == "yes")
    {
        clear();

        // std::system(("wmic useraccount where name='%USERNAME%' call rename '" + accountName + "'").c_str());
        
        cout << "renamed account, name is now: " << "'" << accountName << "'\n";

        returnFunction = "account";
        back();
    }
    else if (renameAccountResponse == "n" || renameAccountResponse == "no")
    {
        returnFunction = "account";
        back();
    }
    else
    {
        returnFunction = "renameAccount";
        invalidInput();
    }
}

void changeAccountPassword()
{
    clear();

    cout << "new account password: \n";
    accountPassword = read();

    clear();

    cout << "are you sure you want to change your account password? (y/n)\n";
    cin >> changePasswordResponse;

    if (changePasswordResponse == "y" || changePasswordResponse == "yes")
    {
        clear();

        // std::system(("net user %USERNAME% '" + accountPassword + "'").c_str());

        cout << "changed password, it's now: " << "'" << accountPassword << "'\n";

        returnFunction = "account";
        back();
    }
    else if (changePasswordResponse == "n" || changePasswordResponse == "no")
    {
        returnFunction = "account";
        back();
    }
    else
    {
        returnFunction = "changePassword";
        invalidInput();
    }
}

void deleteAccount()
{
    clear();

    cout << "account to be deleted: \n";
    deletedAccount = read();

    clear();

    cout << "are you sure you want to delete this account? (y/n)\n";
    cin >> deleteAccountResponse;

    if (deleteAccountResponse == "y" || deleteAccountResponse == "yes")
    {
        clear();

        // std::system(("net user '" + deletedAccount + "' /delete").c_str());

        cout << "account deleted, the account was: " << "'" << deletedAccount << "'\n";

        returnFunction = "account";
        back();
    }
    else if (changePasswordResponse == "n" || changePasswordResponse == "no")
    {
        returnFunction = "account";
        back();
    }
    else
    {
        returnFunction = "deleteAccount";
        invalidInput();
    }
}

void accountResponseHandler()
{
    switch (accountsResponse)
    {
    case '1':
        renameAccount();
    break;

    case '2':
        changeAccountPassword();
    break;

    case '3':
        deleteAccount();
    break;

    case '4':
        returnFunction = "menu";
        back();
    break;

    default:
        cout << "invalid input\n";
        menu();
    break;
    }
}

void account()
{
    clear();

    cout << "account\n\n";

    cout << "1. rename account\n";
    cout << "2. change account password\n";
    cout << "3. delete an account\n";  
    cout << "4. back\n";
    cin >> accountsResponse;

    accountResponseHandler();
}

void changeColor()
{
    std::system(("color " + textColor + backgroundColor).c_str());

    cout << "changed text color to " << textColor << " and background color to " << backgroundColor;
    Sleep(2000);

    returnFunction = "settings";
    back();
}

void listColors()
{
    for (int i{ 0 }; i <= 8; i++)
    {
        cout << colorsList[i] << ": " << i << '\n';
    }

    char character = 'a';
    for (int i{ 0 }; i <= 7; i++)
    {
        cout << colorsList[i + 8] << ": " << character << '\n';

        character++;
    }
    cout << '\n';
}

void settingsTitle()
{
    clear();

    cout << "what do you want the title to be?\n";
    title = read();

    clear();

    cout << "are you sure you want to change the title?\n";
    titleResponse = read();

    if (titleResponse == "yes" || titleResponse == "y")
    {
        clear();

        std::system(("title " + title).c_str());

        cout << "changed title to " << title << '\n';
        Sleep(2000);

        returnFunction = "settings";
        back();
    }
    else if (titleResponse == "no" || titleResponse == "n")
    {
        returnFunction = "settingsTitle";
        back();
    }
    else
    {
        returnFunction = "settings";
        invalidInput();
    }
}

void settingsColor()
{
    clear();

    listColors();

    cout << "text color?\n";
    textColor = read();

    clear();

    listColors();

    cout << "background color?\n";
    backgroundColor = read();

    clear();

    cout << "are you sure you want to change the color?\n";
    colorResponse = read();

    if (colorResponse == "yes" || colorResponse == "y")
    {
        changeColor();
    }
    else if (colorResponse == "no" || colorResponse == "n")
    {
        returnFunction = "settingsColor";
        back();
    }
    else
    {
        returnFunction = "settings";
        invalidInput();
    }
}

void settingsResponseHandler()
{
    switch (settingsResponse)
    {
    case '1':
        settingsColor();
    break;

    case '2':
        settingsTitle();
    break;

    case '3':
        returnFunction = "menu";
        back();
    break;

    default:
        returnFunction = "settings";
        settings();
        break;
    }
}

void settings()
{
    clear();

    cout << "settings\n\n";

    cout << "1. change color scheme\n";
    cout << "2. change title\n";
    cout << "3. back\n";
    cin >> settingsResponse;

    settingsResponseHandler();
}

void quit()
{
    clear();

    cout << "are you sure you want to quit? (y/n)\n";
    cin >> quitResponse;

    if (quitResponse == "yes" || quitResponse == "y")
    {
        clear();

        cout << "ok, exiting\n";
        Sleep(1000);

        exit(0);
    }
    else if (quitResponse == "no" || quitResponse == "n")
    {
        returnFunction = "menu";
        back();
    }
    else
    {
        returnFunction = "quit";
        invalidInput();
    }
}

void menuResponseHandler()
{
    switch (menuResponse)
    {
    case '1':
        account();
    break;

    case '2':
        settings();
    break;

    case '3':
        quit();
    break;

    default:
        cout << "invalid input\n";
        menu();
    break;
    }
}

void back()
{
    if (returnFunction == "menu")
    {
        menu();
    }
    else if (returnFunction == "quit")
    {
        quit();
    }

    else if (returnFunction == "account")
    {
        account();
    }
    else if (returnFunction == "renameAccount")
    {
        renameAccount();
    }
    else if (returnFunction == "changePassword")
    {
        changeAccountPassword();
    }
    else if (returnFunction == "deleteAccount")
    {
        deleteAccount();
    }

    else if (returnFunction == "settings")
    {
        settings();
    }
    else if (returnFunction == "settingsColor")
    {
        settingsColor();
    }
    else if (returnFunction == "settingsTitle")
    {
        settingsColor();
    }
    else
    {
        std::cerr << "invalid function\n";
        Sleep(1000);

        invalidInput();
    }
    returnFunction = "";
}

void menu()
{
    clear();

    cout << "welcome to the admin panel!\n\n";

    cout << "1. accounts\n";
    cout << "2. settings\n";
    cout << "3. quit\n";
    cin >> menuResponse;

    menuResponseHandler();
}

int main()
{
    std::system("title admin panel");

    cout << "admin panel\n";
    cout << "written by chapel1337\n";

    Sleep(2000);
    clear();

    menu();
}
