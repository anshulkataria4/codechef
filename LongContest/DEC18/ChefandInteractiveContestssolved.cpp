//problem code : CHFINTRO
//very very very cheap

#include <iostream>
using namespace std;
int main()
{
    int n,r;
    cin>>n>>r;
    while(n--)
    {
        int rating;
        cin>>rating;
        if(rating>=r)
            cout<<"Good boi"<<endl;
        else
            cout<<"Bad boi"<<endl;
    }
    return 0;
}
