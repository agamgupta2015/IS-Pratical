#include <iostream>
#include <string>

using namespace std;

string railFenceEncrypt(string plaintext, int key) {
    string ciphertext;
    for (int i = 0; i < key; i++) {
        for (int j = i; j < plaintext.length(); j += 2 * (key - 1)) {
            ciphertext += plaintext[j];
            if (i != 0 && i != key - 1 && j + 2 * (key - i - 1) < plaintext.length()) {
                ciphertext += plaintext[j + 2 * (key - i - 1)];
            }
        }
    }
    return ciphertext;
}

string railFenceDecrypt(string ciphertext, int key) {
    string plaintext(ciphertext.length(), ' ');
    int pos = 0;
    for (int i = 0; i < key; i++) {
        for (int j = i; j < ciphertext.length(); j += 2 * (key - 1)) {
            plaintext[j] = ciphertext[pos++];
            if (i != 0 && i != key - 1 && j + 2 * (key - i - 1) < ciphertext.length()) {
                plaintext[j + 2 * (key - i - 1)] = ciphertext[pos++];
            }
        }
    }
    return plaintext;
}

int main() {
    string plaintext, ciphertext, decryptedtext;
    int key;
    char choice;
    do {
        cout << "\nEnter the plaintext: ";
        getline(cin, plaintext);
        cout << "Enter the key: ";
        cin >> key;

        cout<<"Enter your choice\n1.Encryption\n2.Decryption\n";
        int ch;
        cin>>ch;
        switch(ch){
        	case 1:
        		ciphertext = railFenceEncrypt(plaintext, key);
                cout << "Encrypted text: " << ciphertext << endl;
            break;
        
            case 2:
        	    decryptedtext = railFenceDecrypt(plaintext, key);
                cout << "Decrypted text: " << decryptedtext << endl;
        }

        cout << "\n\nDo you want to continue? (y/n): ";
        cin >> choice;
        cin.ignore();
    } while (choice == 'y');

    return 0;
}

