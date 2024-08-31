#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// unordered_map<char,string>mp;
string mapper(char a,int k){
    int n=a-'a';
string s;
for(int i=0;i<k;i++){
    if((n>>i)&1) s.push_back('r');
    else s.push_back('t');

}
reverse(s.begin(),s.end());
return s ;
}
 string encrypt(string msg,int k){
  string ans="";
  for(auto i:msg){
    ans+=mapper(i,k);

  }
  return ans;
 }
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
    string msg ;int k;
    cin>>msg>>k;
    cout<<encrypt(msg,k)<<endl;
    cout<<decrypt(encrypt(msg,k),k)<<endl;
}