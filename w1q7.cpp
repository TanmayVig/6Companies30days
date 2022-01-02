#include<iostream>

using namespace std;

int main(){
    int n=5,m=8,k=2;
    if(m<=n-k+1){
        cout<< m+k-1;
    }else{
        m=m-(n-k+1);
        cout<< ((m%n==0) ? n : m%n );
    }

}