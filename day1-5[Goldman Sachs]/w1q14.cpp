#include<iostream>
#include<vector>
using namespace std;

const int min(int a, int b){
    return (a>b) ? b : a;
}
int minSubArrayLen(int target, vector<int>& nums) {
    int l=0,r=0,min_count=INT_MAX,sum=0;
    while(l<=r){
        if(l==0 && r>=nums.size()) return 0;
        else{
            if(sum!=target && l==r) r++;
            if(sum<target){
                sum+=nums[++r];
            }else if(sum>target){
                sum-=nums[++l];
            }else{
                min_count=min(min_count,r-l+1);
            }
        }
    }
    return min_count==INT_MAX ? 0 : min_count;
}

int main(){
    int target = 0,size=0;
    vector<int> v;
    cin>>target>>size;
    for(int i=0;i<size;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    cout<<minSubArrayLen(target,v);
    return 0;
}