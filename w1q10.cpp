#include<bits/stdc++.h>
#define N 100000
using namespace std;


int main(){
    int arr[N];
    memset(arr,0,sizeof(arr));
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    priority_queue<int, vector<int>,greater<int>> heap;
    for(int i=0;i<N;i++){
        if(heap.size()<=10){
            heap.push(arr[i]);
        }else{
            if(heap.top()<arr[i]){
                heap.pop();
                heap.push(arr[i]);
            }
        }
    }
    while(heap.size()){
        cout<<heap.top()<<" ";
        heap.pop();
    }
    return 0;
}