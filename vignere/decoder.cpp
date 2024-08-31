// C++ code to implement Vigenere Cipher
#include<bits/stdc++.h>
using namespace std;

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

int main()
{
	string keyword = "AyUsh";
   


	string cipher_text;
        cin>>cipher_text;

	string key = generateKey(cipher_text, keyword);
	cout << "Ciphertext : "
		<< cipher_text << "\n";

	cout << "Original/Decrypted Text : "
		<< originalText(cipher_text, key)<<endl;;
	return 0;
    }

