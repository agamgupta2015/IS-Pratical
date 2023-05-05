#include <iostream>
#include <vector>

using namespace std;

// Calculates the parity bit for a given data vector
int calculateParityBit(vector<int>& data) {
    int parityBit = 0;
    for (int i = 0; i < data.size(); i++) {
        parityBit ^= data[i];
    }
    return parityBit;
}

// Main function
int main() {
    vector<int> data;
    int n;
    cout << "Enter the number of bits in the data: ";
    cin >> n;

    cout << "Enter the data bits (separated by spaces): ";
    for (int i = 0; i < n; i++) {
        int bit;
        cin >> bit;
        data.push_back(bit);
    }

    cout<<"Sender : "<<endl;
    cout << "Data : ";
    for(int i = 0; i < data.size(); i++){
        cout << data[i] << " ";
    }
    cout << endl;

    int parityBit = calculateParityBit(data);

    // Introduce an error in the data
    int errorIndex;
    cout << "Enter the index of the bit to flip (0-indexed): ";
    cin >> errorIndex;
    data[errorIndex] ^= 1;

    cout << endl << "Receiver : " << endl;

    cout << "Data with error: ";
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    int newParityBit = calculateParityBit(data);
    if (newParityBit == parityBit) {
        cout << "No error detected" << endl;
    } else {
        cout << "Error detected" << endl;
    }

    return 0;
}


