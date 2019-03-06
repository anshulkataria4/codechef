//Distinct Pairs Problem Code: DPAIRS
//Brute Force Approach

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int main()
{
    long n,m;
    cin>>n>>m;
    vector<long> a;
    vector<long> b;
    a.resize(n);
    b.resize(m);
    long input;
    for(int i=0;i<n;i++){
        cin>>input;
        a[i]=input;
    }
    for(int i=0;i<m;i++){
        cin>>input;
        b[i]=input;
    }
    long len=n+m-1;
   // cout<<"length "<<len<<endl;
    vector<vector<long>> res;
    unordered_map<long, bool> umap;
    res.resize(len);
    long count=len;
    long index=0;
    for(long i=0;i<n;i++){
        for(long j=0;j<m;j++){
            //cout<<"count "<<count<<endl;
            if(count <= 0){
                break;
            }
            long sum=a[i]+b[j];
            //cout<<"sum###"<<sum<<endl;
            if (umap.find(sum) == umap.end()) {
                umap[sum]=1;
                count--;
                res[index].push_back(i);
                res[index].push_back(j);
                index++;
            }


        }
    }

    for(long i=0;i<len;i++){
        cout<<res[i][0]<<" "<<res[i][1]<<endl;
    }

	return 0;
}
