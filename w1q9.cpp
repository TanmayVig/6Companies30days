#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    void reverse(int (&arr)[9],int s,int e){
        for(int i=s;i<=(s+e)/2;i++){
            swap(arr[i],arr[e-(i-s)]);
        }
        // for(int i=s;i<=e;i++){
        //     cout<<arr[i];
        // }
    }
    string printMinNumberForPattern(string s){
        // string str = "";
        int arr[]={1,2,3,4,5,6,7,8,9};
        int si=0,count=0;
        bool block=false;
        for(int i = 0;i<s.size();i++){
            // cout<<s[i];
            if(s[i]=='D'){
                count++;
                if(!block){
                    si = i;block = !block;
                }
            }
            else if(s[i]=='I'){
                if(block){
                    reverse(arr,si, si+count);
                    count = 0;
                    block = !block;
                }
            }
        }
        // cout<<count<<si<<block;
        if(block){
            reverse(arr,si, si+count);;
        }
        string st = "";
        for(int i=0;i<=s.size();i++){
            // cout<<arr[i];
            st=st+to_string(arr[i]);
        }
        return st;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
}