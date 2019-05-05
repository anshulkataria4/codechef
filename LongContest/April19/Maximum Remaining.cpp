
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int max=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(max<=arr[i]){
            max=arr[i];
        }
    }
    cout<<max;
    int res=0;
    for(int i=0;i<n;i++){
        if((arr[i]%max) >=res ){
            res=(arr[i]%max);
        }
    }
    cout<<res;

    return 0;
}
