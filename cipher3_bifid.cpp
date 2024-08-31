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
// cout<<row<<" "<<col<<endl;
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
for(auto i: anomyous)cout<<i<<' ';
    
        for( int i=0;i<anomyous.size();i+=2){
            encodedMessage.push_back(keySquare[ (anomyous[i])*5+anomyous[i+1]]);
            // cout<<encodedMessage<<" ";
        }
            // cout<<encodedMessage<<" ";


        return encodedMessage;
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
        // for(auto i:coordinates) cout<<i<<" ";
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
     
        for(auto i:row)cout<<i<<" ";
        cout<<endl;
    
        for(auto i:col)cout<<i<<" ";

for(int b=0;b<row.size();b++){
    decodedMessage.push_back(keySquare[(row[b])*5+col[b]]);
}


        return decodedMessage;
    }
};

int main() {
    // Example usage
    string key = "AYUSH";
    BifidCipher bifidCipher(key,7);

    string message = "ROUNDTABLE";
    // int key = 2;
    string encodedMessage = bifidCipher.encode(message);
    cout<<endl;
    string decodedMessage = bifidCipher.decode(encodedMessage);

    cout << "Original Message: " << message << endl;
    cout << "Encoded Message: " << encodedMessage << endl;
    cout << "Decoded Message: " << decodedMessage << endl;

    return 0;
}
