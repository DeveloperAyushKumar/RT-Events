// C++ code to implement Vigenere Cipher
#include<bits/stdc++.h>
using namespace std;

// This function generates the key in
// a cyclic manner until it's length isn't
// equal to the length of original text
string generateKey(string str, string key)
{
	int x = str.size();

	for (int i = 0; ; i++)
	{
		if (x == i)
			i = 0;
		if (key.size() == str.size())
			break;
		key.push_back(key[i]);
	}
	return key;
}

// This function returns the encrypted text
// generated with the help of the key
string cipherText(string str, string key)
{
	string cipher_text;

	for (int i = 0; i < str.size(); i++)
	{ 
		// converting in range 0-25
        char x;
        if('A'<=str[i]&&str[i]<='Z'){
            if('A'<=key[i]&& key[i]<='Z')	 x = (str[i] + key[i]-'A'-'A') %26;
            else 	 x = (str[i] + key[i] -'a'-'A') %26;
            x+='A';
	// cout<<x<<" ";


        }
         else {
            if('A'<=key[i]&& key[i]<='Z')	 x = (str[i] + key[i]-'a'-'A') %26;
            else 	 x = (str[i] + key[i]-'a'-'a') %26;
            x+='a';
	// cout<<x<<" ";


        }
	

	// cout<<x<<" ";

		cipher_text.push_back(x);
	}
	return cipher_text;
}

// This function decrypts the encrypted text
// and returns the original text
string originalText(string cipher_text, string key)
{
	string orig_text;

	for (int i = 0 ; i < cipher_text.size(); i++)
	{
		       char x;
        if('A'<=cipher_text[i]&&cipher_text[i]<='Z'){
            if('A'<=key[i]&& key[i]<='Z')	 x = (cipher_text[i] - key[i]+26 ) %26;
            else 	 x = (cipher_text[i] - key[i]+'a'-'A'+26) %26;
            x+='A';

        }
         else {
            if('A'<=key[i]&& key[i]<='Z')	 x = (cipher_text[i] - key[i]-'a'+'A' +26) %26;
            else 	 x = (cipher_text[i] - key[i]+26) %26;
            x+='a';

        }
	
		orig_text.push_back(x);
	}
	return orig_text;
}

// Driver program to test the above function
int main()
{ int n;
    // vector<string> strs;
    cin>>n;
	string str;
	string keyword = "AyUsh";
   
        cin>>str;
	string key = generateKey(str, keyword);


	string cipher_text = cipherText(str, key);

	cout << "Ciphertext : "
		<< cipher_text << "\n";

	cout << "Original/Decrypted Text : "
		<< originalText(cipher_text, key)<<endl;;
    
	return 0;
}
