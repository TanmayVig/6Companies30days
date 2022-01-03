#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int f[n+1];
        memset(f,0,sizeof(f));
        int a=-1,b=-1;
        for(int i=0;i<n;i++){
            f[arr[i]]++;
        }
        // for(int i=1;i<=n;i++) cout<<f[i]<<" ";
        // cout<<endl;
        for(int i=1;i<=n;i++){
            if(f[i]==0 && a==-1) a=i;
            if(f[i]>1 && b==-1) b=i;
            // if(a!=-1 && b!=-1) break;
        }
        int *ans=new int[2];
        ans[0]=b;ans[1]=a;
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}