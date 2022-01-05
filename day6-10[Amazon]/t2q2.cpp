#include<bits/stdc++.h>
using namespace std;

int longestMountain(vector<int>& arr) {
    int n=arr.size();
    if(n<3) return 0;
    int l=0,r=0,count=0,p=0;
    bool up = arr[0]<arr[1];
    bool was_down = true;
    for(int i=0;i<n-1;i++){
        up = arr[i]<arr[i+1];
        if(up){
            if(was_down){
                l=p=r=i;
                was_down= false;
            }
            r++;
            p++;   
        }else if(arr[i]==arr[i+1]){
            r=l=p=i+1;
        }else{
            if(l!=p){
                r++;
                if((r-l+1)>=3)count=max(count,r-l+1);
            }
            was_down = true;
        }
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<longestMountain(arr)<<endl;
    return 0;
}