//problem code MAXEP
//Binary Search
//partially correct

#include<iostream>
using namespace std;

int main()
{
    int coin=1000;
    int n,c;
    cin>>n>>c;
    int left=1,right=n;
    while(coin>0){
        //cout<<"coin value= "<<coin<<endl;
        int res;
        //cout<<"left= "<<left<<" and right= "<<right<<endl;
        int mid=(left+right)/2;
        cout<<1<<" "<<mid<<endl;
        coin--;
        cin>>res;
        if(res==0){
            if(right-mid==1){
                cout<<3<<" "<<right<<endl;
                break;
            }
            else
            left=mid;
        }
        else
            if(res==1){
                if(right==left){
                    cout<<3<<" "<<right<<endl;
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
