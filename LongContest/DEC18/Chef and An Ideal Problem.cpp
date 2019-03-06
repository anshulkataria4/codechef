//problem code : CHEFIDEAL
//Very Easy


#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    int x;
    srand(time(NULL));
    x=(rand() %3)+1;
    cout<<x<<endl;
    int y;
    cin>>y;
    cout<<y<<endl;
    if((x+y) == 5)
        cout<<1<<endl;
    else
        if((x+y) == 4)
            cout<<2<<endl;
        else
        cout<<3<<endl;

}
