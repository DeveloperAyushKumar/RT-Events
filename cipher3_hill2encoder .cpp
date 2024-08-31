#include<iostream>
#include<vector>
#include<string>
using namespace std;
void fillIt (vector<vector<int>>& v, string s ){
    int n=s.size();
    int idx=0;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            v[i][j]=s[idx]-'a';
            idx++;
            idx%=n;
        }
    }
}
void fillIt(<vector<int>& v, string s ){
    int n=s.size();
    int idx=0;
    for(int i=0;i<v.size();i++){
     
            v[i]=s[idx]-'a';
            idx++;
            idx%=n;
        }
    
}
vector<int> product(vector<vector<int>>& mat,vector<int> &vec){
    int n=vec.size()
    vector<int >res(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res[i]+=mat[i][j]*vec[j]
            res[i]%=26;
        }
    }
return res;
}
void fillout(vector<int> & v,string & s){
    for(auto i: v) s.push_back((char)(i +'a'));
}

stirng  encoder(string mseg,string key ){
    int n=mesg.size();
    vector<vector<int>> helper(n,vector<int>(n));
    fillIt(helper,mseg);
    vector<int> vec(n);
    fillIt(vec,key);
     vector<int>result (n);
     result=product(helper,vec);
     string encoded;
     fillout(result,encoded);
     return encoded ;
     
}

int main()
{
string mesg,key;
    
    cin>> mesg>> key;
cout <<encoder(mseg,key);

}