
#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int CountWays(string str){
		    const unsigned int mod = 1000000007;
		    long long count=0;
		    if(str.size()<1 || str[0]=='0') return 0;
		    if(str.length()==1) return 1;
		    int p1=1,p2=1;
		    for(int i=1;i<str.size();i++){
		        int dp1 = str[i]-'0';
		        int dp2 = (str[i-1]-'0')*10 + dp1;
		        count=0;
		        if(dp1>0) count = p1%mod;
		        if(dp2>9 && dp2<=26) count = (count + p2)%mod;
		        p2 = p1;
		        p1 = count;
		    }
		  
		    return count%mod;
		}

};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
