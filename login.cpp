#include <iostream>
#include <string>
#include <fstream>
#include "HashTable.cpp"
using namespace std;

/// <summary>
/// DataType class stores the account info
/// </summary>
class accInfo 
{
public:
    
    /// <summary>
    /// base constructor
    /// </summary>
    accInfo()
    {
        key = "";
        pass = "";
        user = "";
    }

    /// <summary>
    /// parameterized constructor
    /// </summary>
    /// <param name="use"></param>
    /// <param name="pas"></param>
    accInfo(string use, string pas)
    {
        key = "";
        user = use;
        pass = pas;
    }

    /// <summary>
    /// copy function copies one data item to another
    /// </summary>
    /// <param name="other"></param>
    void copy(const accInfo& other)
    {
        this->pass = other.pass;
        this->user = other.user;
    }

    /// <summary>
    /// authenticates the username and password entered
    /// </summary>
    /// <param name="aUser"></param>
    /// <param name="aPass"></param>
    /// <returns></returns>
    bool authenticate(string aUser, string aPass)
    {
        if (user == aUser && pass == aPass)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /// <summary>
    /// sets the key 
    /// </summary>
    /// <param name="newKey"></param>
    void setKey(const string& newKey)
    {
        key = newKey;
    }

    /// <summary>
    /// returns the key
    /// </summary>
    /// <returns></returns>
    string getKey() const
    {
        return key;
    }
    
    /// <summary>
    /// funtion converts the string into a concatenated unsigned int
    /// </summary>
    /// <param name="keyValue"></param>
    /// <returns></returns>
    unsigned int hash(const string& keyValue) const
    {
        unsigned int hashedKey = 0;

        for (int i = 0; i < keyValue.length(); ++i)
        {  
            hashedKey = hashedKey + keyValue[i];
        }

        return hashedKey;
    }

    /// <summary>
    /// returns the username
    /// </summary>
    /// <returns></returns>
    string getUser() const
    {
        return user;
    }

    /// <summary>
    /// returns the password
    /// </summary>
    /// <returns></returns>
    string getPass() const
    {
        return pass;
    }

private:
    /// <summary>
    /// key data member
    /// </summary>
    string key;

    /// <summary>
    /// password data member
    /// </summary>
    string pass;
    
    /// <summary>
    /// username data member
    /// </summary>
    string user;
   
};

int main()
{
	/// <summary>
	/// input file stream for the password.dat file
	/// </summary>
	/// <returns></returns>
	ifstream accFile("password.dat");

    /// <summary>
    /// stores the username from the file input
    /// </summary>
    /// <returns></returns>
    string username;

    /// <summary>
    /// stores the password from the file input
    /// </summary>
    /// <returns></returns>
    string password;

    /// <summary>
    /// sentinel value for while loop
    /// </summary>
    /// <returns></returns>
    bool log = false;

    /// <summary>
    /// stores continue option from user
    /// </summary>
    /// <returns></returns>
    string cont; 

    /// <summary>
    /// hashtable with datatype accinfo and size of 10
    /// </summary>
    /// <returns></returns>
    HashTable<accInfo, string> accHashTable(10);

	/// <summary>
	/// file handling
	/// </summary>
	/// <returns></returns>
	if (accFile.is_open())
	{
        /// <summary>
        /// file reading
        /// </summary>
        /// <returns></returns>
        while (accFile >> username && accFile >> password)
        {
            /// <summary>
            /// creates an accinfo object with data from the file
            /// </summary>
            /// <returns></returns>
            accInfo accountInput(username, password);

            /// <summary>
            /// sets the key for the object
            /// </summary>
            /// <returns></returns>
            accountInput.setKey(username);

            /// <summary>
            /// inserts the data item into the table 
            /// </summary>
            /// <returns></returns>
            accHashTable.insert(accountInput);
        }
        cout << "Account Database Sucessfully Uploaded" << endl;
        accFile.close();

        
        /// <summary>
        /// while loop containing the log in system 
        /// </summary>
        /// <returns></returns>
        while (!log)
        {
            cout << "Would you like to log in? (Enter Y to continue)";
            cin >> cont;

            if (cont == "Y" || cont == "y")
            {
                /// <summary>
                /// user input for the username 
                /// </summary>
                /// <returns></returns>
                string inputUsername;

                /// <summary>
                /// user input for the password
                /// </summary>
                /// <returns></returns>
                string inputPassword;


                cout << "Username: ";
                cin >> inputUsername;
                cout << "Password: ";
                cin >> inputPassword;

                /// <summary>
                /// temporary accinfo object used for retrieval 
                /// </summary>
                /// <returns></returns>
                accInfo temp(inputUsername, inputPassword); //temp DataType to store retrieved DataType
                temp.setKey(inputUsername);

                /// <summary>
                /// stores the retrieved data item into temp if found 
                /// </summary>
                /// <returns></returns>
                accHashTable.retrieve(temp.getKey(), temp);

                /// <summary>
                /// authentication of the username and password, successful if found and failure if not 
                /// </summary>
                /// <returns></returns>
                if (temp.authenticate(inputUsername, inputPassword))
                {
                    cout << "Authentication Successful" << endl;
                }
                else
                {
                    cout << "Authentication Failed" << endl;
                }
            }
            else
            {
                log = true;
            }
        }
        
	}
    else
    {
        cout << "unable to open file" << endl;
    }
}