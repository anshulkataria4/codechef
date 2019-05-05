//Fencing Problem Code: FENCE
//Fencing Problem Code: FENCE
#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        unordered_map<long, bool> umap;
        long long n,m;
        cin>>n>>m;
        long long k;
        cin>>k;
        long long p,q;
        for(int i=0;i<k;i++){
            cin>>p>>q;
            long long key= ((p-1)*m)+q;
            if(umap.find(key)==umap.end()){
                umap[key]=true;
            }

        }
        long long last=n*m;
        cout<<"last + m="<<last+m<<endl;
        long long totalcost=k*4;
        long long v1,v2,v3,v4;
        for (auto x : umap) {
            long long key= x.first ;
            cout<<key<<endl;
            v1=key-m;
            v2=key-1;
            v3=key+m;
            v4=key+1;
            if(key%m==0){
                v4=0;
            }
            if(key%m==1){
                v2=0;
            }
            if(umap.find(v1)!=umap.end()){
                totalcost--;
            }
            if(umap.find(v2)!=umap.end()){
                totalcost--;
            }
            if(umap.find(v3)!=umap.end()){
                totalcost--;
            }
            if(umap.find(v4)!=umap.end()){
                totalcost--;
            }


        }

        cout<<totalcost<<endl;
    }
    return 0;
}
