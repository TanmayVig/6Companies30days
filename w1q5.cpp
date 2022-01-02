#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

class Solution{
public:	

	ull getNthUglyNo(int n) {
	    set<ull> s;
	   // memset(arr,0,sizeof(arr));
	    s.insert(1);
	    n--;
	    while(n-->0){
	       // cout<<"loop";
	        auto i = s.begin();
	        s.erase(i); ull t = *i;
	        s.insert(2*t);
	        s.insert(3*t);
	        s.insert(5*t);
	    }
	    return *s.begin();
	}
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}