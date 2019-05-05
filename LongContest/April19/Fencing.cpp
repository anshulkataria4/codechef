//Fencing Problem Code: FENCE
#//Fencing Problem Code: FENCE
#include<iostream>
#include<vector>
using namespace std;

int getthecost(vector<vector<int>> v, int n, int m, int x, int y){
    int val=v[x][y];
    long cost=0;
    if(val==1){
        if(x-1>=0){
            if(v[x-1][y]==0){
                cost++;
            }
        } else{
            cost++;
        }
        if(y-1>=0){
            if(v[x][y-1]==0){
                cost++;
            }
        } else{
            cost++;
        }
        if(x+1<n){
            if(v[x+1][y]==0){
                cost++;
            }
        } else{
            cost++;
        }
        if(y+1 < m){
            if(v[x][y+1]==0){
                cost++;
            }
        } else{
            cost++;
        }

    }

    // if(val==0){
    //     if((x-1>=0) && (x+1 < n) && (y-1 >=0) && (y+1 < m)){
    //         if((v[x-1][y]==1) && (v[x][y-1]==1) && (v[x+1][y]==1)  && (v[x][y+1]==1) ){
    //             cost=4;
    //         }
    //     }
    //
    // }
    return cost;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> v;
        long long n,m;
        cin>>n>>m;
        v.resize(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v[i].push_back(0);
            }
        }
        int k;
        cin>>k;
        int p,q;
        for(int i=0;i<k;i++){
            cin>>p>>q;
            v[p-1][q-1]=1;
        }
        long long totalcost=0;
        for(int x=0;x<n;x++){
            for(int y=0;y<m;y++){
                long val= getthecost(v,n,m,x,y);
                totalcost+=val;
            }
        }

        cout<<totalcost<<endl;
    }
    return 0;
}
