#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

string gcdOfStrings(string str1, string str2) {
    return (str1+str2==str2+str1) ? str1.substr(0,gcd(str1.length(),str2.length())) : "";
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<gcdOfStrings(s1,s2)<<endl;
    return 0;
}
