#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
 char unMapper (string temp){
    int a=0;   
    for(int i=0;i<temp.size();i++){
        a=a<<1;
        if(temp[i]=='r') a=(a|1);

    }

    return a+'a';
 }
 string decrypt(string encoded,int k){
    string decoded;
    for(int i=0;i<encoded.size();i+=k){
        decoded.push_back(unMapper(encoded.substr(i,k)));
    }
return  decoded;
    
 } 
int main()
{
    string encrypted  ;int k;
    cout<<" enter your encrypted message ";
    cin>>encrypted ;
    cout <<" enter integer key (>=5,<=32)";
    cin>>k;
    cout<<"decryped message "<<decrypt(encrypted,k)<<endl;

}