
#include <iostream>
#include <vector>

using namespace std;
int int main() {
        int t;
        cin>>t;
        while(t--){
            int d;
            cin>>d;
            vector<vector<int>> days;
            vector<vector<int>> problems;
            vector<vector<int>> probsolved;
            days.resize(d);
            problems.resize(d);
            probsolved.resize(d);
            int i,j;
            int sum=0;
            for (int k=0;k<d;k++){
                cin>>i>>j;
                days[k].push_back(i);
                problems[k].push_back(j);
                sum+=j;
                probsolved[k].push_back(sum);

            }
            int q;
            cin>>q;
            while (q--) {
                int m,n;
                int mid=d/2;
                cin>>m>>n;
                bool found=false;
                bool unsolved=true;
                while(mid<d){
                    if(days[mid][0]<m){
                        //check upper and lower
                        if(days[mid+1][0]>m){
                            if(problems[mid][0]>= n){
                                cout<<"Go Camp";
                                break;
                            }
                        }
                        mid=(mid+d)/2;

                    }
                    else
                    if(days[mid][0]>m){
                        mid=(d-mid)/2;
                    }
                    else{

                    }

                }
            }
        }
    return 0;
}
