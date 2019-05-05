//Friend or Girlfriend Problem Code: STRCH
#include<iostream>
using namespace std;

int main() {
    /* code */
    int t;
    cin>>t;
    while(t--){
        long n;
        cin>>n;
        string s;
        cin>>s;
        char c;
        cin>>c;
        bool flag=false;
        long long res=0;
        long long size=0;

        for(int i=0;i<n;i++){

                if(str[i]==c){
                    flag=true;
                    res+=(size*(size+1))/2;
                    size=0;
                }else if(flag==true && i==n-1){
                    size++;
                    res+=(size*(size+1))/2;
                    size=0;
                }else{
                    size++;
                }
            }

            if(flag==true)
                res=((n*(n+1))/2)-res;
            else
                res=0;
            cout<<res<<endl;

    }
    return 0;
}
