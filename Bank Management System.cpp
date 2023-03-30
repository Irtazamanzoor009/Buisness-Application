#include <iostream>
#include <fstream>
#include <cmath>
#include <conio.h>
using namespace std;

// Menus
void clearScreen();
void Getch();
void outerMenu();
void welcomeMenu();
void companyHeader();
string SignMenu();
string SignMenuOption;
string choice;
string UserMenu();
string AdminMenu();
string modifyMenu();
string modifyoption;

// sign functions
void User_signUp();
void Admin_signUp();
int GetIndex();

// file handling
void storeAdminData();
void storeUserData();
void readAdminData();
void readUserData();
string getLine(string word, int field);
void storeFeedback();
void readFeedback();
void storeContact();
void readContact();
void storeZakat();
void readZakat();

string name;
string password;
string role;
string pin;
string returnRole();
string error = "Error! Invalid Entity";
int viewindex();
int checkIndex = viewindex();
bool isValidCNIC();
bool checkAccountType();

// user arrays
const int user_size = 10;
string usernames[user_size];
string userPasswords[user_size];
string userRoles[user_size];
string accountType[user_size];
int InitialAmount[user_size];
string CNIC[user_size];
int userCount = 0;
string accounttype;
int initial_amount = 0;
bool isValidUsername();
void UserInterface();
string user_option;
string cnic;
bool CheckCNIC();
bool Checkamount();

// admin arrays
const int admin_size = 10;
string adminnames[admin_size];
string adminPasswords[admin_size];
string adminRoles[admin_size];
int adminCount = 0;
void AdminInterface();
string admin_option;
string Email;
string contactNumber;
char infoOption;
string error1 = "Please enter only Y/N.";
string price;
// admin functionalities
void detailsOfUser();
string deleteaccountName;
void deleteAccountError();
void deleteAccount();
bool checkaccountforDeletion();
void checkZakatBalance();
string modification;
string newname;
void modifyAccount();
void modifyAccountError();
bool checkModification();
void viewFeedback();
void EditContact();
bool checkInfoOption();
void InfoOptionCancelled();
bool checkContactNumber();
bool checkEmial();
string EnteredEmail;
string EnteredContactNumber;

// user functionalities
void ViewInfo();
int deposit_amount;
void InvalidPIN();
void depositAmount();
void depositAmountError();
int withdraw_amount = 0;
void withdrawAmount();
void withdrawAmountError();
void CheckBalanceInquiry();
bool checkWithdraw();
char zakatoption;
int zakat_count;
bool checkzaqatoption();
int zakatamm[user_size];
int zakat = 0;
int Zakat;
void deductzakatAmount();
void deductzakatAmounterror();
int feedbackCount = 0;
string feedbackName[100];
string feedback;
string feedbackarr[100];
void giveFeedback();
//bool Checamount();
char choicefeedback;
void storefeedback();
void operationCancell();
void confirmFeedback();
string ignore;
bool checkInitialAmount();
void ChangeName();
void ChangeCNIC();
void ChangePIN();
void ModifyInformation();
void changeInformation();
int indexx;
int viewIndex();
int index;
string pIN;
bool checkchoices();
char changepasswordchoice;

main()
{

    clearScreen();
    outerMenu();
    welcomeMenu();
    Getch();
    companyHeader();

    readAdminData();
    readUserData();
    readFeedback();
    readContact();
    readZakat();

    while (choice != "3")
    {

        companyHeader();
        choice = SignMenu();
        if (choice == "1") // sign in
        {

            companyHeader();
            cout << "----------------Sign In Menu----------------" << endl
                 << endl;
            cout << " ";
            getline(cin, ignore);
            cout << "Enter Username: ";
            getline(cin, name);
            cout << "Enter Password: ";
            cin >> password;
            string result = returnRole();
            if (adminCount == 0 && userCount == 0)
            {
                cout << "No account created yet.." << endl;
                Getch();
            }
            else
            {
                if (result == "User" || result == "user")
                {
                    UserInterface();
                }
                else if (result == "Admin" || result == "admin")
                {
                    AdminInterface();
                }
                else
                {
                    cout << error << endl;
                    Getch();
                }
            }
        }
        if (choice == "2") // sign up menu
        {

            companyHeader();
            cout << "-----------------Sign Up Menu-------------" << endl
                 << endl;
            //cout << "";
            getline(cin, ignore);
            cout << "Enter Username: ";
            getline(cin, name);
            cout << "Enter Password: ";
            cin >> password;
            cout << "Enter Role: ";
            cin >> role;
            // string role = userInput("role");
            bool result = isValidUsername();
            if (result == true)
            {
                if ((role == "User" || role == "user"))
                {
                    // user sign up
                    // further requirements for user
                    cout << "Enter CNIC: ";
                    cin >> cnic;
                    if (CheckCNIC()) // check length of cnic
                    {
                        if (isValidCNIC()) // check that cnic is already in use or not
                        {
                            cout << "Enter your initial Amount: ";
                            cin >> price;
                            initial_amount = stoi(price);
                            bool checkamount = Checkamount();
                            if (checkamount == true)
                            {
                                if (initial_amount > 0)
                                {
                                    cout << "Enter Your account type(c/s): ";
                                    cin >> accounttype;
                                    if (checkAccountType()) // check account type true or not
                                    {
                                        User_signUp();
                                        storeUserData();
                                        cout << "Signed up successfully " << endl;
                                        Getch();
                                    }
                                    else
                                    {

                                        cout << "Error! Invalid Account Type " << endl;
                                        Getch();
                                    }
                                }
                                else
                                {
                                    cout << "Error! Invalid amount" << endl;
                                    Getch();
                                }
                            }
                            else
                            {
                                cout << "Error! Invalid amount" << endl;
                                Getch();
                            }
                        }
                        else
                        {
                            cout << "Error! CNIC already exist" << endl;
                            Getch();
                        }
                    }
                    else
                    {
                        cout << "Error! Invalid CNIC" << endl;
                        Getch();
                    }
                }

                else if (role == "Admin" || role == "admin")
                {

                    Admin_signUp();
                    storeAdminData();
                    cout << "Admin Signed Up successfully" << endl;
                    Getch();
                }
                else
                {
                    cout << "Invalid role" << endl;
                    Getch();
                }
            }
            else
            {
                cout << "User already exist" << endl;
                Getch();
            }
        }
    }
}

// ************************ File Handling ********************

void storeAdminData() // store the data of Admin in File
{
    fstream data;
    data.open("Admin.txt", ios::app);
    {
        data << name << ",";
        data << password << ",";
        data << role << endl;
    }
    data.close();
}

void readAdminData() // Read data of Admin from File
{
    string word1;
    fstream data;
    data.open("Admin.txt", ios::in);
    if (data)
    {

        while (!(data.eof()))
        {
            getline(data, word1);
            adminnames[adminCount] = getLine(word1, 1);
            adminPasswords[adminCount] = getLine(word1, 2);
            adminRoles[adminCount] = getLine(word1, 3);
            adminCount++;
        }
    }
    data.close();
}

void storeUserData() // Store the data of user in File
{
    fstream data1;

    data1.open("Users.txt", ios::out);
    {
        for (int i = 0; i < userCount; i++)
        {

            data1 << usernames[i] << ",";
            data1 << userPasswords[i] << ",";
            data1 << userRoles[i] << ",";
            data1 << accountType[i] << ",";
            data1 << InitialAmount[i] << ",";
            data1 << CNIC[i] << endl;
        }
    }
    data1.close();
}

void readUserData() // Read the data of user from file
{
    string word;
    fstream data1;
    data1.open("Users.txt", ios::in);
    if (data1)
    {
        while (!data1.eof())
        {
            getline(data1, word);
            if (word == "")
            {
                break;
            }
            usernames[userCount] = getLine(word, 1);
            userPasswords[userCount] = getLine(word, 2);
            userRoles[userCount] = getLine(word, 3);
            accountType[userCount] = getLine(word, 4);
            InitialAmount[userCount] = stoi(getLine(word, 5));
            CNIC[userCount] = getLine(word, 6);
            userCount++;
        }
    }
    data1.close();
}

string getLine(string word, int field) // Read the commas holder file and display data
{
    int commaCount = 1;
    string item = "";
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] == ',')
        {
            commaCount = commaCount + 1;
        }

        else if (commaCount == field)
        {
            item = item + word[i];
        }
    }
    return item;
}

void storeFeedback() // Store feedback in file
{
    fstream data;
    data.open("Feedback.txt", ios::app);
    {
        data << name << ",";
        data << feedback << endl;
    }
    data.close();
}

void readFeedback() // read feedback from file
{
    string word;
    fstream data;
    data.open("Feedback.txt", ios::in);
    if (data)
    {
        while (!(data.eof()))
        {
            getline(data, word);
            if (word == "")
                break;

            name = getLine(word, 1);
            feedback = getLine(word, 2);
            cout << "Name: " << name << endl;
            cout << "Feedback: " << feedback << endl;
        }
    }
    data.close();
}

void storeContact() // Store the contact info in file
{
    fstream data;
    data.open("Contact.txt", ios::out);
    {
        data << EnteredEmail << ",";
        data << EnteredContactNumber << endl;
    }
    data.close();
}

void readContact() // Read the contact info in file
{
    string word;
    fstream data;
    data.open("Contact.txt", ios::in);

    if (data)
    {
        while (!(data.eof()))
        {
            getline(data, word);
            if (word == "")
                break;

            EnteredEmail = getLine(word, 1);
            EnteredContactNumber = getLine(word, 2);
            cout << "Email: " << EnteredEmail << endl;
            cout << "Contact: " << EnteredContactNumber << endl;
        }
    }
    data.close();
}

void storeZakat() // store zakat in file
{
    
    fstream data;
    data.open("zakat.txt", ios::out);
    {
        data << zakat;
    }
    data.close();
}

void readZakat() // Read zakat in file
{

    string word;
    fstream data;
    data.open("zakat.txt", ios::in);

    if (data)
    {
        while (!(data.eof()))
        {
            getline(data, word);
            cout << "Zakat: " << zakat;
        }
    }

    data.close();
}

//**************************** Admin / Users ***********************

string AdminMenu() // Display the admin Menu
{
    cout << "--------------Admin Interface--------------" << endl
         << endl;
    cout << "1. View details of user" << endl;
    cout << "2. Delete an account" << endl;
    cout << "3. Modify an account" << endl;
    cout << "4. Check zakat balance" << endl;
    cout << "5. View Feedbacks" << endl;
    cout << "6. Edit Contact" << endl;
    cout << "7. Go back" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Select your option...";
    cin >> admin_option;
    return admin_option;
}

void AdminInterface() // Displays admin interface
{

    string admin_choice;
    while (admin_choice != "7")
    {

        companyHeader();
        admin_choice = AdminMenu();
        if (admin_choice == "1") // view details of user
        {
            companyHeader();
            cout << "---------------View Details--------------" << endl
                 << endl;
            detailsOfUser();
            cout << endl;
            Getch();
        }
        if (admin_choice == "2") // delete account
        {
            companyHeader();
            cout << "--------------Delete Account-----------" << endl
                 << endl;
            cout << "";
            getline(cin, ignore);
            cout << "Enter account name to delete: ";
            getline(cin, deleteaccountName);
            bool checkDeletionAccount = checkaccountforDeletion();
            if (checkDeletionAccount == true)
            {
                deleteAccount();
                storeUserData();
                cout << "Account has been deleted successfully."<<endl;
            }
            else
            {
                deleteAccountError();
            }
            Getch();
        }
        if (admin_choice == "3") // modify an account
        {
            companyHeader();
            cout << "------------Account Modification------------" << endl
                 << endl;
            cout << "Enter account name for modification: ";
            cin >> modification;
            bool checkAccountPresent = checkModification();
            if (checkAccountPresent == true)
            {
                modifyAccount();
                storeUserData();
            }
            else
            {
                modifyAccountError();
            }
        }
        if (admin_choice == "4") // check zakat balance
        {
            companyHeader();
            cout << "---------------Zakat Balance-------------" << endl
                 << endl;
            checkZakatBalance();
            storeZakat();
            Getch();
        }
        if (admin_choice == "5") // show feedbacks
        {
            companyHeader();
            cout << "--------------View Feedback-------------" << endl
                 << endl;
            readFeedback();
            viewFeedback();
            Getch();
        }
        if (admin_choice == "6") // Edit Contact
        {
            companyHeader();
            cout << "----------------Edit Contact info-----------------" << endl
                 << endl;
            cout << "Email: " << EnteredEmail << endl;
            cout << "Contact: " << EnteredContactNumber << endl;
            cout << "Are you want to change info: ";
            cin >> infoOption;
            if (infoOption == 'y' || infoOption == 'Y')
            {
                EditContact();
                storeContact();
            }
            else if (infoOption == 'n' || infoOption == 'N')
            {
                InfoOptionCancelled();
                Getch();
            }
            else
            {
                cout << "Error! Invalid Entity" << endl;
                Getch();
            }
        }
    }
}

void detailsOfUser() // displays the data of all users
{
    cout << "Name "
         << "\t\t"
         << "Account Type "
         << "\t"
         << "Amount"
         << "\t\t"
         << "CNIC"
         << "\t\t"
         << endl;
    cout << "______________________________________________________________________" << endl
         << endl;
    if (userCount == 0)
    {
        cout << "No account present" << endl;
        cout << endl;
    }
    else
    {
        for (int i = 0; i < userCount; i++)
        {
            cout << usernames[i] << "\t\t" << accountType[i] << "\t\t" << InitialAmount[i] << "\t\t" << CNIC[i] << endl;
        }
    }
}

void deleteAccount() // delete the account of users
{
    for (int i = 0; i < userCount; i++)
    {
        if (deleteaccountName == usernames[i])
        {
            for (int j = i; j < userCount; j++)
            {
                usernames[j] = usernames[j + 1];
                accountType[j] = accountType[j + 1];
                InitialAmount[j] = InitialAmount[j + 1];
            }
            userCount--;
        }
    }
}

void modifyAccount() // modify the account of user
{
    int count = 0;
    for (int i = 0; i < userCount; i++)
    {
        if (modification == usernames[i])
        {
            cout << "Enter new Account Type(c/s): ";
            cin >> accounttype;
            if (accounttype == "c" || accounttype == "s")
            {
                count = 1;
                accountType[i] = accounttype;
                break;
            }
        }
    }
    if (count == 1)
    {
        cout << "Account has been modified" << endl;
        Getch();
    }
    else if (count != 1)
    {
        cout << "Error! Invalid Account Type" << endl;
        Getch();
    }
}

void modifyAccountError()
{
    cout << "Error! Account not found" << endl;
}

void checkZakatBalance() // check the zakat balance
{
    int zakat = 0;
    cout << "Total Zakat Amount is: ";

    for (int i = 0; i < zakat_count; i++)
    {

        zakat = zakat + zakatamm[i];
    }
    cout << zakat;
    
    cout << endl;
}

void viewFeedback() // view feedback entered by user
{
    for (int i = 0; i < feedbackCount; i++)
    {
        cout << "UserName: " << feedbackName[i] << endl;
        cout << "FeedBack: " << feedbackarr[i] << endl;
    }
}

void EditContact() // Edit the contact Us information
{
    cout << " ";
    getline(cin, ignore);
    cout << "Enter new Email: ";
    getline(cin, Email);
    bool EmailCheck = checkEmial();
    if (EmailCheck == true)
    {
        EnteredEmail = Email;

        cout << "Enter new contact number: ";
        getline(cin, contactNumber);
        bool checkcontact = checkContactNumber();
        if (checkcontact == false)
        {
            cout << "Error! Invalid Number" << endl;
            Getch();
        }
        else
        {
            EnteredContactNumber = contactNumber;
            cout << "Your Contact Info has been Updated" << endl;
            Getch();
        }
    }
    else
    {
        cout << "Error! Invalid Email." << endl;
        Getch();
    }
}

string UserMenu() // Displays the user menu
{

    cout << "--------------User Interface-------------" << endl
         << endl;
    cout << "1. View Info" << endl;
    cout << "2. Deposit Amount" << endl;
    cout << "3. Withdraw Amount" << endl;
    cout << "4. Balance Inquiry" << endl;
    cout << "5. Zakat Deduction" << endl;
    cout << "6. Modify Account" << endl;
    cout << "7. Contact Us" << endl;
    cout << "8. Give Feedback" << endl;
    cout << "9. Go back" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Select your option...";
    cin >> user_option;
    return user_option;
}

void UserInterface() // user menu
{

    string user_choice;
    while (user_choice != "9")
    {

        companyHeader();
        user_choice = UserMenu();
        if (user_choice == "1") // view info
        {
            companyHeader();
            cout << "------------View Info-----------" << endl
                 << endl;

            ViewInfo();

            Getch();
        }
        if (user_choice == "2") // deposit amount
        {

            companyHeader();

            cout << "----------------Deposit Amount--------------- " << endl
                 << endl;
            cout << "Enter your deposit Amount: ";
            cin >> deposit_amount;
            if (deposit_amount > 0)
            {

                depositAmount();
                storeUserData();
            }
            else
            {
                depositAmountError();
            }

            Getch();
        }
        if (user_choice == "3") // withdraw amount
        {
            companyHeader();
            cout << "-------------Withdraw Amount-------------" << endl
                 << endl;

            bool checkAmount = checkWithdraw();

            cout << "Enter the amount you want to withdraw: ";
            cin >> withdraw_amount;
            if (checkAmount == true)
            {

                withdrawAmount();
                storeUserData();
            }
            else
            {

                withdrawAmountError();
            }

            Getch();
        }
        if (user_choice == "4") // check balance Inquiry
        {

            companyHeader();
            cout << "------------Check Balance Inquiry------------" << endl
                 << endl;

            CheckBalanceInquiry();

            Getch();
        }
        if (user_choice == "5") // zakat deduction
        {
            companyHeader();
            cout << "---------------Zakat Deduction----------------" << endl
                 << endl;
            cout << "Are you want to deduct zakat or sadqat: ";
            cin >> zakatoption;
            bool isValidZakatOption = checkzaqatoption();
            if (isValidZakatOption == true)
            {

                deductzakatAmount();
            }
            else
            {
                deductzakatAmounterror();
            }
            Getch();
        }
        if (user_choice == "6") // Modify Account
        {
            companyHeader();
            changeInformation();
            storeUserData();
        }
        if (user_choice == "7") // contact Us
        {
            companyHeader();
            cout << "-----------------Contact Us------------------" << endl
                 << endl;
            cout << "Feel free to contact us" << endl;
            cout << endl;
            cout << "Email: " << EnteredEmail << endl;
            cout << "Contact Number: " << EnteredContactNumber << endl;
            Getch();
        }
        if (user_choice == "8") // give feedback
        {
            companyHeader();
            cout << "----------------Give Feedback----------------" << endl
                 << endl;
            giveFeedback();
            Getch();
        }
    }
}

void InvalidPIN()
{
    cout << "Invalid PIN" << endl;
}

void ViewInfo() // displays all the information about account to user
{
    int count = 0;
    index = viewIndex();
    {
        cout << "Name: " << usernames[index] << endl;
        cout << "CNIC: " << CNIC[index] << endl;
        cout << "Password: " << userPasswords[index] << endl;
        // cout << "Amount: " << InitialAmount[index] << endl;
    }
}

void depositAmount() // deposit the amount in account
{
    index = viewIndex();
    {

        InitialAmount[index] += deposit_amount;
        cout << "Your amount has been deposited" << endl;
    }
}

void depositAmountError()
{
    cout << "You have entered Invalid Amount" << endl;
}

void withdrawAmount() // withdraw ammount in account
{
    index = viewIndex();
    {

        InitialAmount[index] -= withdraw_amount;
        cout << "Your amount " << withdraw_amount << " has been withdrawn" << endl;
    }
}

bool checkWithdraw() // it check wether the amount entered by the user is valid or not
{
    bool flag = false;
    if (withdraw_amount <= InitialAmount[checkIndex])
    {
        flag = true;
        // break;
    }
    return flag;
}

void withdrawAmountError()
{
    cout << "You don't have enough amount";
}

void CheckBalanceInquiry() // check the balance inquiry
{
    index = viewIndex();
    {
        cout<<"Your balance is: ";
        cout << InitialAmount[index]<<endl;
    }
}

bool checkzaqatoption() // check zakat option wether it is true or not
{
    if (zakatoption == 'Y' || zakatoption == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void deductzakatAmount() // it deducts the zakat amount
{
    index = viewIndex();
    {
zakat_count = 0;
        zakatamm[index] = (InitialAmount[index] * 2.5) / 100;
        InitialAmount[index] -= zakatamm[index];
        zakat_count++;
        storeUserData();
        cout << "Your zakat ammount has been deducted" << endl;

    }
}

void deductzakatAmounterror()
{
    cout << "Error! Invalid Entity" << endl;
}

string modifyMenu()
{

    cout << " 1.  Change Name" << endl;
    cout << " 2.  Change CNIC" << endl;
    cout << " 3.  Change PIN" << endl;
    cout << " 4.  Go back" << endl;
    cout << "------------------------------------" << endl;
    cout << "Select your option...";
    cin >> modifyoption;
    return modifyoption;
}

void ChangeName() // it changes the name of user
{
    companyHeader();
    cout << "---------------Change Name--------------" << endl
         << endl;
    int count = 0;

    for (int i = 0; i < userCount; i++)
    {

        cout << "Enter new name: ";
        cin >> name;
        bool isvalidname = isValidUsername();
        if (isvalidname == true)
        {
            count = 1;
            usernames[i] = name;
            break;
        }
    }

    if (count == 1)
    {
        cout << "Name has been changed successfully" << endl;
        Getch();
    }
    else if (count != 1)
    {
        cout << "Error! User Already exist" << endl;
        Getch();
    }
}

void changeInformation()
{
    indexx = viewIndex();
    if (indexx == -1)
    {
        cout << "Account not found" << endl;
        Getch();
    }
    else
    {
        ModifyInformation();
    }
}

void ModifyInformation() // it modifies the information of user
{
    string modifychoice;
    while (modifychoice != "4")
    {
        companyHeader();
        cout << "------------Account Modification--------------" << endl
             << endl;

        modifychoice = modifyMenu();
        if (modifychoice == "1") // change name
        {
            changepasswordchoice;
            cout << "Do you want to change your password(y/n): ";
            cin >> changepasswordchoice;
            if (checkchoices())
            {
                ChangeName();
            }
            else
            {
                cout << "Operation has been cancelled" << endl;
                Getch();
            }
        }
        if (modifychoice == "2") // change CNIC
        {
            changepasswordchoice;
            cout << "Do you want to change your password(y/n): ";
            cin >> changepasswordchoice;
            if (checkchoices())
            {
                ChangeCNIC();
            }
            else
            {
                cout << "Operation has been cancelled" << endl;
                Getch();
            }
        }
        if (modifychoice == "3") // change PIN
        {
            changepasswordchoice;
            cout << "Do you want to change your password(y/n): ";
            cin >> changepasswordchoice;
            if (checkchoices())
            {
                ChangePIN();
            }
            else
            {
                cout << "Operation has been cancelled" << endl;
                Getch();
            }
        }
    }
}

void ChangeCNIC() // changes the CNIC of user
{
    companyHeader();
    cout << "-------------Change CNIC-------------" << endl
         << endl;
    int count = 0;
    cout << " ";
    getline(cin, ignore);
    cout << "Ener new CNIC: ";
    getline(cin, cnic);
    bool checkCnic = CheckCNIC();   // give length
    bool validcnic = isValidCNIC(); // CNIC exist or not
    if (validcnic == false)
    {
        cout << "Error! This CNIC already exist" << endl;
        Getch();
    }
    if (validcnic == true && checkCnic == true)
    {
        CNIC[indexx] = cnic;
        cout << "Your CNIC has been changed successfully" << endl;
        Getch();
    }
    if (checkCnic == false)
    {
        cout << "Error! Invalid CNIC" << endl;
        Getch();
    }
}

void ChangePIN() // changes the PIN of user
{
    companyHeader();
    cout << "-----------Chnage PIN-----------" << endl
         << endl;
    int count = 0;
    for (int i = 0; i < userCount; i++)
    {
        cout << "Enter new Password: ";
        cin >> password;
        count = 1;
        userPasswords[i] = password;
    }
    if (count == 1)
    {
        cout << "PIN has been changed successfully" << endl;
        Getch();
    }
}

void giveFeedback() // allows user to give feedback
{
    cout << "Your feedback is important for us" << endl;
    getline(cin, ignore);
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your feedback here: ";
    getline(cin, feedback);
    cout << "Are you want to give your feedback(y/n): ";
    cin >> choicefeedback;
    confirmFeedback();
}

void confirmFeedback() // ask the user to send comment or not
{

    if (choicefeedback == 'y')
    {
        storefeedback();
        storeFeedback();
    }
    else if (choicefeedback == 'n')
    {
        operationCancell();
    }
}

void operationCancell()
{
    cout << "The operation has been cancelled" << endl;
}

void storefeedback() // it stores the feedback in arrays
{
    feedbackName[feedbackCount] = name;
    feedbackarr[feedbackCount] = feedback;
    feedbackCount++;
    cout << "Thank you for your feedback" << endl;
}

// *******************Sign Up***********************

void User_signUp() // user data store in arrays
{
    usernames[userCount] = name;
    userPasswords[userCount] = password;
    userRoles[userCount] = role;
    accountType[userCount] = accounttype;
    InitialAmount[userCount] = initial_amount;
    CNIC[userCount] = cnic;
    userCount++;
}

void Admin_signUp() // admin data stores in arrays
{

    adminnames[adminCount] = name;
    adminPasswords[adminCount] = password;
    adminRoles[adminCount] = role;
    adminCount++;
}

string returnRole() // it returns role after checking that name or password is valid
{
    for (int i = 0; i < userCount; i++)
    {
        if (name == usernames[i] && password == userPasswords[i])
        {

            return userRoles[i];
            break;
        }
    }
    for (int i = 0; i < adminCount; i++)
    {
        if (name == adminnames[i] && password == adminPasswords[i])
        {

            return adminRoles[i];
            break;
        }
    }
    return error;
}

// ************************* Validations *************************

bool checkaccountforDeletion() // check the existing account
{
    bool flag = false;
    for (int i = 0; i < userCount; i++)
    {
        if (deleteaccountName == usernames[i])
        {
            flag = true;
            break;
        }
    }
    return flag;
}

void deleteAccountError()
{
    cout << "Error! Account not found";
}

bool checkModification() // check the name of user before modification
{
    bool flag = false;
    for (int i = 0; i <= userCount; i++)
    {
        if (modification == usernames[i])
        {
            flag = true;
        }
    }
    return flag;
}

int viewIndex()
{
    int index;
    for (int i = 0; i < userCount; i++)
    {
        if (name == usernames[i])
        {
            index = i;
        }
    }
    return index;
}

bool checkContactNumber() // check tha character and length of contactnumber
{
    int count = 0;
    bool flag = false;
    int lenghtOfContactNumber = contactNumber.length();
    if (lenghtOfContactNumber == 11)
    {
        for (int i = 0; i < 11; i++)
        {

            if (contactNumber[i] >= 48 && contactNumber[i] <= 57)
            {
                count++;
            }
        }
        if (count == 11)
        {
            flag = true;
        }
    }
    else
    {
        flag = false;
    }
    return flag;
}

bool checkEmial() // check the email validation
{
    bool flag = false;
    int lengthOfEmail = Email.length();
    for (int i = 0; i < lengthOfEmail; i++)
    {
        if (Email[i] == '@')
        {
            flag = true;
            break;
        }
    }
    return flag;
}

bool checkAccountType() // check the accounttype is valid or not
{
    bool flag = false;
    if (accounttype == "c" || accounttype == "s")
    {
        flag = true;
    }
    return flag;
}

bool checkInfoOption()
{
    if (infoOption == 'y' || infoOption == 'Y')
    {
        return true;
    }
    else if (infoOption == 'n' || infoOption == 'N')
    {
        return false;
    }
}

void InfoOptionCancelled()
{
    cout << "Your operation has been cancelled" << endl;
}

bool checkInitialAmount()
{
    bool flag = false;
    string str = to_string(initial_amount);
    int lengthOfInitialAmount = str.length();
    for (int i = 0; i < lengthOfInitialAmount; i++)
    {

        if (str[i] >= 0 && str[i] <= 9)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

bool CheckCNIC() // check the character and length of CNIC
{
    int count = 0;
    bool flag = false;
    int lengthOfCNIC = cnic.length();
    if (lengthOfCNIC == 13)
    {
        for (int i = 0; i < 13; i++)
        {
            if (cnic[i] >= 48 && cnic[i] <= 57)
            {
                count++;
            }
        }
        if (count == 13)
        {
            flag = true;
        }
    }
    else
    {
        flag = false;
    }

    return flag;
}

bool Checkamount()
{
    int count = 0;
    bool flag = false;
    int lengthOfamount = price.length();
    for (int i = 0; i < lengthOfamount; i++)
    {
        for (char j = '0'; j <= '9'; j++)
        {
            if (j == price[i])
            {
                count++;
                // flag = true;
            }
        }
    }

    if (count == lengthOfamount)
    {
        flag = true;
    }

    return flag;
}

bool isValidCNIC() // check that CNIC is valid or not
{
    bool flag = true;
    for (int i = 0; i < userCount; i++)
    {
        if (cnic == CNIC[i])
        {
            flag = false;
        }
    }
    return flag;
}

bool isValidUsername() // Check that username is valid or not
{
    bool flag = true;
    for (int i = 0; i < userCount; i++)
    {
        if (name == usernames[i])
        {
            flag = false;
        }
    }
    for (int i = 0; i < adminCount; i++)
    {
        if (name == adminnames[i])
        {
            flag = false;
        }
    }
    return flag;
}

bool checkchoices()
{
    bool flag = false;
    if (changepasswordchoice == 'y' || changepasswordchoice == 'Y')
    {
        flag = true;
    }
    return flag;
}

int viewindex()
{
    int index1 = -1;
    for (int i = 0; i < userCount; i++)
    {
        if (password == userPasswords[i] && name == usernames[i])
        {
            index1 = i;
        }
    }
    return index1;
}

// *************************** others ************************

string SignMenu()
{
    cout << "------------------------------------" << endl;
    cout << " 1.  Sign In" << endl;
    cout << " 2.  Sign Up" << endl;
    cout << " 3.  Exit" << endl;
    cout << "------------------------------------" << endl;
    cout << "Select your option..." << endl;
    cin >> SignMenuOption;
    return SignMenuOption;
}

void companyHeader()
{
    clearScreen();
    cout << "    *********************************************************************    " << endl;
    cout << "    *********************** ALL CITIZENS BANK ***************************   " << endl;
    cout << "    *********************************************************************   " << endl;
    cout << endl;
}

void outerMenu()
{

    cout << "  /$$$$$$  /$$       /$$              /$$$$$$  /$$$$$$ /$$$$$$$$ /$$$$$$ /$$$$$$$$ /$$$$$$$$ /$$   /$$  /$$$$$$  " << endl;
    cout << " /$$__  $$| $$      | $$             /$$__  $$|_  $$_/|__  $$__/|_  $$_/|_____ $$ | $$_____/| $$$ | $$ /$$__  $$ " << endl;
    cout << "| $$  \\ $$| $$      | $$            | $$  \\__/  | $$     | $$     | $$       /$$/ | $$      | $$$$| $$| $$  \\__/" << endl;
    cout << "| $$$$$$$$| $$      | $$            | $$        | $$     | $$     | $$      /$$/  | $$$$$   | $$ $$ $$|  $$$$$$ " << endl;
    cout << "| $$__  $$| $$      | $$            | $$        | $$     | $$     | $$     /$$/   | $$__/   | $$  $$$$ \\____  $$" << endl;
    cout << "| $$  | $$| $$      | $$            | $$    $$  | $$     | $$     | $$    /$$/    | $$      | $$\\  $$$ /$$  \\ $$" << endl;
    cout << "| $$  | $$| $$$$$$$$| $$$$$$$$      |  $$$$$$/ /$$$$$$   | $$    /$$$$$$ /$$$$$$$$| $$$$$$$$| $$ \\  $$|  $$$$$$/" << endl;
    cout << "|__/  |__/|________/|________/       \\______/ |______/   |__/   |______/|________/|________/|__/  \\__/ \\______/ " << endl;

    cout << "                               /$$$$$$$   /$$$$$$  /$$   /$$ /$$   /$$             " << endl;
    cout << "                              | $$__  $$ /$$__  $$| $$$ | $$| $$  /$$/            " << endl;
    cout << "                              | $$  \\ $$| $$  \\ $$| $$$$| $$| $$ /$$/                   " << endl;
    cout << "                              | $$$$$$$ | $$$$$$$$| $$ $$ $$| $$$$$/                   " << endl;
    cout << "                              | $$__  $$| $$__  $$| $$  $$$$| $$  $$                  " << endl;
    cout << "                              | $$  \\ $$| $$  | $$| $$\\  $$$| $$\\  $$                   " << endl;
    cout << "                              | $$$$$$$/| $$  | $$| $$ \\  $$| $$ \\  $$                  " << endl;
    cout << "                              |_______/ |__/  |__/|__/  \\__/|__/  \\__/    " << endl;
}

void welcomeMenu()
{
    cout << endl
         << endl
         << endl;
    cout << "          /$$      /$$ /$$$$$$$$ /$$        /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$ " << endl;
    cout << "         | $$  /$ | $$| $$_____/| $$       /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/" << endl;
    cout << "         | $$ /$$$| $$| $$      | $$      | $$  \\__/| $$  \\ $$| $$$$  /$$$$| $$      " << endl;
    cout << "         | $$/$$ $$ $$| $$$$$   | $$      | $$      | $$  | $$| $$ $$/$$ $$| $$$$$   " << endl;
    cout << "         | $$$$_  $$$$| $$__/   | $$      | $$      | $$  | $$| $$  $$$| $$| $$__/   " << endl;
    cout << "         | $$$/ \\  $$$| $$      | $$      | $$    $$| $$  | $$| $$\\  $ | $$| $$      " << endl;
    cout << "         | $$/   \\  $$| $$$$$$$$| $$$$$$$$|  $$$$$$/|  $$$$$$/| $$ \\/  | $$| $$$$$$$$" << endl;
    cout << "         |__/     \\__/|________/|________/ \\______/  \\______/ |__/     |__/|________/" << endl;
}

void clearScreen()
{
    system("cls");
}

void Getch()
{
    cout << "Press any key to continue..." << endl;
    getch();
}