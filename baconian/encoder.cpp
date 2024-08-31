#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
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

int main()
{
    string msg ;int k;
    cout<<" enter your message ";
    cin>>msg;
    cout <<" enter integer key (>=5,<=32)";
    cin>>k;
    cout<<"encrypted message "<<encrypt(msg,k)<<endl;

}