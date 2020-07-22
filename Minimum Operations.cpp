#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin>>t;
    int * arr = new int[10001];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    
    for(int i=3;i<10001;i++){
        int x = arr[i-1];
        if(i%2==0){
            x = min(x,arr[i/2]);
        }
        arr[i] = x+1;
    }
    while(t--){
        int n;
        cin>>n;
        cout<<arr[n]<<endl;
    }
    
    
    return 0;
}