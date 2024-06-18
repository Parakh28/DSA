#include <iostream>
using namespace std;
int main() {
    int n,a;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    a=INT_MIN;
    for(int i =0 ; i<n ; i++){
        if(a<arr[i]){
            a=arr[i];
            cout<<a<<" ";
        }
    }   
    
    
        
    

    return 0;
}