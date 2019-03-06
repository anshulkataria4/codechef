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
    vector<vector<int>> r;
    bool first=true;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<vector<int>> v;
        int k=0;
        int t=0;
        v.resize(n);
        r.resize(50);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v[i].push_back(0);
            }
        }
        if(first){
            for(int i=0;i<50;i++){
                for(int j=0;j<50;j++){
                    r[i].push_back(0);
                }
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
        int backtrackcount=0;
//function to call and fill the vector
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v=difngb(v,&k,i,j,m,n);
                if(k>l && l!=4 && l!=0){
                     v[i-1][j+1]=l;
                    bool firsttry=true;
                    for(int p=i-1;p<n ;p++){
                    for(int q=0;q<m;q++){
                            if(firsttry){
                                q=j+2;
                                firsttry=false;
                            }
                            if(q<m && p<n)
                            v[p][q]=0;
                            backtrackcount++;
                    }
                    }
                    i=i-1;
                    j=j+1;
                    k=l;

                }
            }
        }
        if(first){
            for(int i=0;i<50;i++){
                for(int j=0;j<50;j++){
                    r=difngb(r,&t,i,j,50,50);
                }
            }
        }


//print the result
        if(k>4){
            cout<<4<<endl;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout<<r[i][j];
                    if(j!=m-1){
                    cout<<" ";
                    }
                }
                cout<<endl;
            }

        }
        else{
            cout<<k<<endl;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout<<v[i][j];
                    if(j!=m-1){
                    cout<<" ";
                    }
                }
                cout<<endl;
            }
        }
        first=false;

    }
    return 0;
}
