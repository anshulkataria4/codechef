#include <iostream>
#include <vector>
#include <queue>
using namespace std;





int main(){
    int t;
    long k=0;
    cin>>t;
    while(t--){
        vector<vector<long>> adjList;
        vector<long> list;
        vector<long> safelist;
        long long n,x;
        cin>>n>>x;
        adjList.resize(n);
        list.resize(n);
        safelist.resize(n);
        for(int i=0;i<n;i++){
            long node;
            cin>>node;
            list[i]=node;
            safelist[i]=0;
        }
        for(int i=0;i<n-1;i++){
            long node1,node2;
            cin>>node1>>node2;
            if(node1<node2){
                adjList[node1].push_back(node2);
            }
            else{
                adjList[node2].push_back(node1);
            }
        }
        vector<bool> visited(n,false);








    }

    return 0;
}
