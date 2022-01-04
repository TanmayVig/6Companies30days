#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        map<int,int> rem;
        for(int i=0;i<nums.size();i++){
            rem[(nums[i]%k)]++;
        }
        for(int i=0;i<nums.size();i++){
            int rem1 = nums[i]%k;
            // rem[rem1]--;
            int rem2 = k-rem1;
            // cout<<rem[rem1]<<endl;
            if(rem1==0 && rem[rem1]%2!=0){
                // cout<<rem1<<" "<<rem2<<endl;
                return false;
            }
            else if(rem1==rem2 && rem[rem1]%2!=0){
                return false;
            } 
            else if(rem1!=0 && rem[rem1]!=rem[rem2]){
                return false;
            }
        }
        return true;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}