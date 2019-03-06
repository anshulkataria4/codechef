//problem code MAXEP
//Binary Search
//more partially correct with opmtimized scenario

#include<iostream>
using namespace std;

int main()
{
    int coin=1000;
    int n,c;
    cin>>n>>c;
     int last_zero=0,last_one=0;
    int left=1,right=n;
    bool first=1;
    while(coin>0){
        //cout<<"coin value= "<<coin<<endl;
        int res;
        //cout<<"left= "<<left<<" and right= "<<right<<endl;
        if(first){
            first=0;
            int t=1;
            int tres;
            while(coin && (t < n)){
                coin--;
                cout<<1<<" "<<t<<endl;
                cin>>tres;
                if(tres==1){
                    if(t > 1){
                        last_one=t;
                        last_zero=t/2;
                        left=t/2;
                        right=t;
                        coin=coin-c;
                        cout<<2<<endl;
                        break;
                    }
                    else{
                        cout<<3<<" "<<1<<endl;
                        return 0;
                    }

                }
                else{
                    t=t*2;
                    if(t>=n){
                        left=t/2;
                        right=n;
                        break;
                    }
                }
            }
        }
        int mid=(left+right)/2;
        cout<<1<<" "<<mid<<endl;
        coin--;
        cin>>res;
        if(res==0){
            last_zero=mid;
            if(right-mid==1){
                cout<<3<<" "<<right<<endl;
                break;
            }
            else
            left=mid;
        }
        else
            if(res==1){
                last_one=mid;
                if(right==left){
                    cout<<3<<" "<<right<<endl;
                    break;
                }
                else
                    if(last_zero>0 && mid-last_zero==1){
                    cout<<3<<" "<<mid<<endl;
                    break;
                }
                else
                    if(mid==1 && left==mid){
                    cout<<3<<" "<<mid<<endl;
                    break;
                }
                else
                {
                    cout<<2<<endl;
                    coin=coin-c;
                    right=mid;
                }
            }
    }

    return 0;

}
