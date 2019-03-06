//Different Neighbours Problem Code: DIFNEIGH

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> difngb(vector<vector<int>> v,int *k, int curRow, int curCol, int m, int n){
    int rowDir[] = {+2, 0, -2, 0, -1, -1, +1, +1};
    int colDir[] = {0, -2, 0, +2, -1, +1, +1, -1};
    if(v[curRow][curCol]==0){
        int value=1;
        //check the possible values
        bool canplace=true;

        while(1){
            canplace=true;
            for(int p=0;p<8;p++){
                int nextRow = curRow + rowDir[p];
                int nextCol = curCol + colDir[p];
                if((nextRow >=0) && nextRow <n){
                    if((nextCol>=0) && nextCol < m){
                        if(value==v[nextRow][nextCol]){
                            canplace=false;
                            break;
                        }
                    }
                }
            }
            if(canplace==true){
                v[curRow][curCol]=value;
                if(value> *k){
                    *k=value;
                }
                return v;
            }
            value++;

        }

    }
    else{
        return v;
    }
}

int main() {
    int t,n,m;
    //vector<vector<int>> v;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<vector<int>> v;
        int k=0;
        v.resize(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v[i].push_back(0);
            }
        }
        int l=0;
        if((m>1 && n>1) &&( m<3 || n<3)){
            l=3;
        }
        else
        if ((m>2) && (n>2)) {
            l=4;
        }
//function to call and fill the vector
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v=difngb(v,&k,i,j,m,n);
                //backtrack
                if(k>l){
                     v[i-1][j]++;
                    for(int p=i-1;p<=i && p<n ;i--){
                        for(int q=j+1;q <=j && q<m;j--){
                            v[p][q]=0;
                        }
                    }
                    i=i-1;
                    j=j+1;
                    k=l;
                }
            }
        }

//print the result
        cout<<k<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }

    }
    return 0;
}
