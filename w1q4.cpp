#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}



string encode(string src)
{     
    int j=0;
    string s="";
    for(int i=0;i<src.size()-1;i++){
        // cout<<"loop";
      if(src[i]!=src[i+1]){
          
          s+=src[i]+to_string(i-j+1);
          j=i+1;
      }
    }
    int l = src.size()-1;
      if(src[l]==src[l-1]){
          
        s+=src[l]+to_string(l-j+1);  
      } 
      else{
        // cout<<"y";  
        // cout<<src[l];
        s+=src[l];
        s+="1";
      } 
      return s;
}