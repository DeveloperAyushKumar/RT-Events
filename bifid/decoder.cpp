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

 // Function to decode a message using the Bifid cipher with grouping
    string decode(const string& message) {
        string decodedMessage ;
        vector<int>coordinates;
         for (char c : message) {
            if (isalpha(c)) {
                int index = keySquare.find(toupper(c));
                int row = index / 5 ;
                int col = index % 5 ;

                coordinates.push_back(row);
                coordinates.push_back(col);
            }
        }
        cout<<endl;
        vector<int> row;
        vector<int> col;

        int i=0;
        while(i<coordinates.size()){
            if(coordinates.size()-i>=2*keyInt){
                for(int j=0;j<keyInt;j++,i++) row.push_back(coordinates[i]);
                for(int j=0;j<keyInt;j++,i++) col.push_back(coordinates[i]);
            }
            else { int len =coordinates.size()-i;
                   for(int j=0;j<len/2;j++,i++) row.push_back(coordinates[i]);
                for(int j=0;j<len/2;j++,i++) col.push_back(coordinates[i]);
            }
        }
     

for(int b=0;b<row.size();b++){
    decodedMessage.push_back(keySquare[(row[b])*5+col[b]]);
}


        return decodedMessage;
    }
};

int main() {
    // Example usage
    string key ;
    cout<<"Enter key ";
    cin>>key;
    int period;
    cout<<"Enter period ";
    cin>>period;
    BifidCipher bifidCipher(key,period);
    string encodedMessage ;
    cout<<"Enter encoded message ";
    cin>>encodedMessage;
    string decodedMessage = bifidCipher.decode(encodedMessage);

    cout << "Encoded Message: " << encodedMessage << endl;
    cout << "Decoded Message: " << decodedMessage << endl;

    return 0;
}
