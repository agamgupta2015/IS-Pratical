#include <bits/stdc++.h>

using namespace std;

string keyword = "";

string generate_key(int n)
{
    string key = "";

    for (int i = 0; i < n; i++)

        return key;
}

string encrypt()
{
    string msg = "", ct = "", key = "";
    char t;
    int n;
    srand(time(NULL));
    cout << "Enter the length of message" << endl;
    cin >> n;
    cout << "\nEnter the message in Binary" << endl;
    for (int i = 0; i < n; i++)
    {
        
        cin >> t;
        if (t == '0' || t == '1')
        {
            char ke = (rand() % 2) + 48;
            char c = ((int(t) - 48) ^ (int(ke) - 48)) + 48;
            msg += t;
            key += ke;
            ct += c;
//            cout << "Message = " << t << endl;
//            cout << "Key = " << ke << endl;
//            cout << "Encrypted Message = " << c << endl;
        }
        else
        {
            cout << "Invalid Input" << endl;
            return key;
        }
    }
//    cout << "\nFinal Message = " << msg << endl;

    cout<<"\n\t"<<msg<<endl;
    cout<<"\t"<<key<<"\n";
    cout<<"\t";
    for (int i = 0; i < n; i++){
    	cout<<"-";
	}
    cout<<"\n\t"<<ct<<endl;
    cout << "\nRandom Key Used = " << key << endl;
    cout << "Encrypted Message = " << ct << endl;
    return key;
}

void decrypt(string key)
{
    string ct = "", pt = "";
    char t;
    int n = key.length();
    int k = 0;
    cout << "\nEnter the ciphertext in Binary" << endl;
    for (int i = 0; i < n; i++)
    {
        
        cin >> t;
        if (t == '0' || t == '1')
        {
            char ke = key[k];
            char p = ((int(t) - 48) ^ (int(ke) - 48)) + 48;
            ct += t;
            pt += p;
//            cout << "CT = " << t << endl;
//            cout << "Key = " << ke << endl;
//            cout << "Decrypted Text = " << p << endl;
            k++;
        }
        else
        {
            cout << "Invalid Input" << endl;
            return;
        }
    }
//    cout << "\nFinal Cipher Text = " << ct << endl;

    cout<<"\n\t"<<ct<<endl;
    cout<<"\t"<<key<<"\n";
    cout<<"\t";
    for (int i = 0; i < n; i++){
    	cout<<"-";
	}
    cout<<"\n\t"<<pt<<endl;
    
    cout << "\nKey Used = " << key << endl;
    cout << "Decrypted Text = " << pt << endl;
}

int main()
{
    char choice;
    do
    {
        int ch;
        cout << "\nEnter your choice\n1. Encryption\n2. Decryption" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            keyword = encrypt();
            break;
        }
        case 2:
        {
            if (keyword == "")
            {
                cout << "Enter the Key" << endl;
                getline(cin >> ws, keyword);
            }
            decrypt(keyword);
            break;
        }
        default:
            cout << "Wrong Choice Enterred" << endl;
            break;
        }
        cout << "Do you want to continue? (Y/N)" << endl;
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return 1;
}
