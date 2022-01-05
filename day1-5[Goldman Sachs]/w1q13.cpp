#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    string unfold(string s, int &i,int len){
        string st = "";
        int num=0;
        for(;i<len;i++){
            if(s[i]>='0' && s[i]<='9'){
                num= num*10 + (s[i]-'0');
            }else if(s[i]=='['){
                i++;
                string temp = unfold(s,i,len);
                while(num--){
                    st = st + temp;
                }
                num=0;
            }else if(s[i]==']'){
                return st;
            }else{
                st = st + s[i];
            }
        }
    }
    string decodedString(string s){
        int st= 0;
        return unfold(s,st,s.length());
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}