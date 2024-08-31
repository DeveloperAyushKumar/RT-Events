#include <iostream>
#include <cctype>
#include <vector>

using namespace std;

class BifidCipher {
private:
    string keySquare;
    int keyInt;

public:
    BifidCipher(const string& key,int key2) {
        generateKeySquare(key);
        keyInt=key2;
    }

    // Function to generate the key square
    void generateKeySquare(const string& key) {
        keySquare = "";
        vector<bool> used(26, false);

        // Add the key to the key square
        for (char c : key) {
            if (isalpha(c) && !used[toupper(c) - 'A']) {
                keySquare += toupper(c);
                used[toupper(c) - 'A'] = true;
            }
        }

        // Fill in the remaining letters of the alphabet
        for (char c = 'A'; c <= 'Z'; c++) {
            if (c != 'J' && !used[c - 'A']) {
                keySquare += c;
            }
        }
    }

    // Function to encode a message using the Bifid cipher with grouping
    string encode(const string& message) {
        string encodedMessage ;
        vector<int> rowCoordinates;
        vector<int> colCoordinates;

        // Get the coordinates for each letter in the message
        for (char c : message) {
            if (isalpha(c)) {
                int index = keySquare.find(toupper(c));
                int row = index / 5 ;
                int col = index % 5 ;
                rowCoordinates.push_back(row);
                colCoordinates.push_back(col);
            }
        }

        // Group coordinates based on the key
        vector<int> anomyous ;
        int i=0,j=0;
        while(i<rowCoordinates.size()){
            for(int a=0;a<keyInt&& i<rowCoordinates.size();a++,i++) anomyous.push_back(rowCoordinates[i]);
            for(int a=0;a<keyInt &&j<rowCoordinates.size();a++,j++) anomyous.push_back(colCoordinates[j]);

        }
// for(auto i: anomyous)cout<<i<<' ';
    
        for( int i=0;i<anomyous.size();i+=2){
            encodedMessage.push_back(keySquare[ (anomyous[i])*5+anomyous[i+1]]);
            // cout<<encodedMessage<<" ";
        }
            // cout<<encodedMessage<<" ";


        return encodedMessage;
    }
};

int main() {
    // Example usage
    string key;
    cout<<"Enter Key ";
    cin>>key;
    cout<<"Enter period";
    int period;
    cin>>period;

    BifidCipher bifidCipher(key,period);
cout<<"Enter message ";
    string message ;
    cin>>message;
    string encodedMessage = bifidCipher.encode(message);

    cout << "Original Message: " << message << endl;
    cout << "Encoded Message: " << encodedMessage << endl;

    return 0;
}

