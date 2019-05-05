//Fencing Problem Code: FENCE
#//Fencing Problem Code: FENCE
#include<iostream>
#include<vector>
using namespace std;

long getthecost(vector<vector<long>> v, int n, int m, int x, int y){
    long cost=0;
    //cout<<"x,y is "<<x<<","<<y<<endl;
    int x1,y1,x2,y2,x3,y3,x4,y4;
    bool up=false, left=false, down=false, right=false;
    x1=x-1;y1=y;
    x2=x;y2=y-1;
    x3=x+1;y3=y;
    x4=x;y4=y+1;
    //cout<<x1<<","<<y1<<" "<<x2<<","<<y2<<" "<<x3<<","<<y3<<" "<<x4<<","<<y4<<endl;
    if( (x1>0) && (v[x1].empty() == 0) ){
        for(int i=0;i<v[x1].size();i++){
            if(v[x1][i]==y1){
                up=true;
    //            cout<<"up"<<endl;
            }
        }
    }
    if(  (y2>0) && (v[x2].empty()== 0)){
        for(int i=0;i<v[x2].size();i++){
            if(v[x2][i]==y2){
                left=true;
    //            cout<<"left"<<endl;
            }
        }
    }
    if( ( x3 <= n ) && (v[x3].empty()==0)){
        for(int i=0;i<v[x3].size();i++){
            if(v[x3][i]==y3){
                down=true;
    //            cout<<"down"<<endl;
            }
        }
    }
    if( (y4 <= m ) && (v[x4].empty()==0)){
        for(int i=0;i<v[x4].size();i++){
            if(v[x4][i]==y4){
                right=true;
    //            cout<<"right"<<endl;
            }
        }
    }
    if(up==false){
        cost++;
    }
    if(left==false){
        cost++;
    }
    if(down==false){
        cost++;
    }
    if(right==false){
        cost++;
    }
	//cout<<"cost of this is "<<cost<<endl;
    return cost;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<long>> v;
        vector<vector<int>> input;
        long long n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        input.resize(k);
        v.resize(n+1);
        int p,q;
        for(int i=0;i<k;i++){
            cin>>p>>q;
            input[i].push_back(p);
            input[i].push_back(q);
            v[p].push_back(q);
        }
        long long totalcost=0;
        for(int i=0;i<k;i++){
            int x=input[i][0];
            int y=input[i][1];
            long val=getthecost(v,n,m,x,y);
            totalcost+=val;

        }

        cout<<totalcost<<endl;
    }
    return 0;
}
