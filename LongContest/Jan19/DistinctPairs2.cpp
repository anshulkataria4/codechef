//Distinct Pairs Problem Code: DPAIRS
//Fairly Easy Optimization
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
    long pos[4];
    // find min in a
    long a_min=0;
    for(long i=0;i<n;i++){
        if(a[a_min]>=a[i]){
            a_min=i;
        }
    }
    pos[0]=a_min;
    // find max in a
    long a_max=0;
    for(long i=0;i<n;i++){
        if(a[a_max]<=a[i]){
            a_max=i;
        }
    }
    pos[1]=a_max;
    //find min in b
    long b_min=0;
    for(long i=0;i<m;i++){
        if(b[b_min]>=b[i]){
            b_min=i;
        }
    }
    pos[2]=b_min;
    // find max in b
    long b_max=0;
    for(long i=0;i<m;i++){
        if(b[b_max]<=b[i]){
            b_max=i;
        }
    }
    pos[3]=b_max;
    //cout<< " max and min are "<<a[a_max]<<" "<<a[a_min]<<" values for b: "<<b[b_max]<<" "<<b[b_min]<<endl;
    for(long i=0;i<4;i++){
        a_min=pos[i];
        int l;
        if(i<2){
            l=m;
        }
        else{
            l=n;
        }
        for(long j=0;j<l;j++){
            //cout<<"count "<<count<<endl;
            if(count <= 0){
                break;
            }
            long sum=0;
            if(i<2){
                sum=a[a_min]+b[j];
            }
            else
            sum=a[j]+b[a_min];
            //cout<<"sum###"<<sum<<endl;
            if (umap.find(sum) == umap.end()) {
                umap[sum]=1;
             //   cout<<"sum###"<<sum<<endl;
                count--;
                if(i<2){
                    res[index].push_back(a_min);
                    res[index].push_back(j);
                }else{
                    res[index].push_back(j);
                    res[index].push_back(a_min);
                }
                index++;
            }


        }
    }

    for(long i=0;i<len;i++){
        cout<<res[i][0]<<" "<<res[i][1]<<endl;
    }

	return 0;
}
