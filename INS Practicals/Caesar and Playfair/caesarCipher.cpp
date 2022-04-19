#include <bits/stdc++.h>
using namespace std;

string readFile(string filename)
{
    string line;
    ifstream fin;
    fin.open(filename);

    if (fin.fail())
    {
        throw std::runtime_error("Failed to open file");
    }
    // Execute a loop until EOF (End of File)
    while (fin)
    {
        // Read a Line from File
        getline(fin, line);
        cout << "\nText From the File: " << line << "\n";
        return line;
    }

    // Close the file
    fin.close();
}

void saveFile(string filename, string line)
{
    ofstream fout;

    // by default ios::out mode, automatically deletes
    // the content of file. To append the content, open in ios:app
    // fout.open("sample.txt", ios::app)
    fout.open(filename);
    if (fout.fail())
    {
        throw std::runtime_error("Failed to open file");
    }
    // Execute a loop If file successfully opened
    while (fout)
    {
        fout << line << endl;
        break;
    }

    // Close the File
    fout.close();
}

string Encrypt(string msg, int key)
{
    char ch;
    for (int i = 0; msg[i] != '\0'; ++i)
    {
        ch = msg[i];
        // encrypt for lowercase letter
        if (ch >= 'a' && ch <= 'z')
        {
            ch = (ch - 'a' + key) % 26 + 'a';
            msg[i] = ch;
        }
        // encrypt for uppercase letter
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = (ch - 'A' + key) % 26 + 'A';
            msg[i] = ch;
        }
    }
    return msg;
    // printf("Encrypted message: %s", msg);
    // cout << "Encrypted Message: " << msg;
}

string Decrypt(string msg, int key)
{
    char ch;
    for (int i = 0; msg[i] != '\0'; ++i)
    {
        ch = msg[i];
        // decrypt for lowercase letter
        if (ch >= 'a' && ch <= 'z')
        {
            ch = (ch - 'a' - key + 26) % 26 + 'a';
            msg[i] = ch;
        }
        // decrypt for uppercase letter
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = (ch - 'A' - key + 26) % 26 + 'A';
            msg[i] = ch;
        }
    }
    return msg;
}

void CryptAnalysis()
{
    string plainText, decrypted;
    string msg = readFile("encrypted.txt");
    int count = 0;
    plainText = readFile("sample.txt");
    for (int i = 0; i < 26; i++)
    {
        decrypted = Decrypt(msg, i);
        count++;
        if (plainText == decrypted)
            break;
    }
    cout << "\n Attacker will take " << count << " steps to decrypt the message";
}

int main()
{
    srand(time(0));
    string msg, file, encrypted, decrypted;
    int i, j, length, choice = 1, key;
    key = rand() % 10;
    cout << "---------------------Encrypt/Decrypt----------------------------";
    cout << "\n\nEnter the Message file name:";
    cin >> file;
    msg = readFile(file);

    // cout << "\nEnter key: ";
    // cin >> key; //take the key as input
    cout << "\nGenerated Key is: " << key << "\n";
    length = msg.length();
    // cout << length;
    while (choice != 0)
    {

        cout << "\nEnter your choice \n0. Exit \n1. Encryption \n2. Decryption \n3. Crypt Analysis \n";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "\nSee you next time!";
            break;
        case 1:
            encrypted = Encrypt(msg, key);
            cout << "\nEncrypted Message: " << encrypted << "\n";
            saveFile("encrypted.txt", encrypted);
            break;
        case 2:
            msg = readFile("Encrypted.txt");
            decrypted = Decrypt(msg, key);
            cout << "\nDecrypted message: " << decrypted << "\n";
            saveFile("decrypted.txt", decrypted);
            break;
        case 3:
            CryptAnalysis();
            break;

        default:
            cout << "Choose valid Option.";
            break;
        }
    }
}