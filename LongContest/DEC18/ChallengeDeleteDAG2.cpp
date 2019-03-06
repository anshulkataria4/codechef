// (Challenge) Delete DAG problem code= DLDAG
// solution is simple but Implementation is messy


#include <iostream>
#include <vector>
#include <queue>
using namespace std;



// data structure to store graph edges
struct Edge {
	int src, dest;
};

// class to represent a graph object
class Graph
{
public:
	// construct a vector of vectors to represent an adjacency list
	vector<vector<int>> adjList;
    vector<vector<int>> inList;

	// Graph Constructor
	Graph(vector<Edge> const &edges, int N)
	{
		// resize the vector to N elements of type vector<int>
		adjList.resize(N);
        inList.resize(N);

		// add edges to the directed graph
		for (auto &edge: edges)
		{
			// insert at the end
			adjList[edge.src].push_back(edge.dest);
            inList[edge.dest].push_back(edge.src);

			// Uncomment below line for undirected graph
			// adjList[edge.dest].push_back(edge.src);
		}
	}
};
queue<int> leafs(Graph graph,int n)
{
    queue <int> q;
    // to find all the leaf nodes
    for(int i=0; i<n;i++){
        if(graph.adjList[i].empty()){
            q.push(i);
        }
    }

    return q;
}


// print adjacency list representation of graph
void printGraph(Graph const& graph, int N)
{
	for (int i = 0; i < N; i++)
	{
		// print current vertex number
		cout << i << " --> ";

		// print all neighboring vertices of vertex i
		for (int v : graph.inList[i])
			cout << v << " ";
		cout << endl;
	}
}
void printGraphl(Graph const& graph, int N)
{
	for (int i = 0; i < N; i++)
	{
		// print current vertex number
		cout << i << " --> ";

		// print all neighboring vertices of vertex i
		for (int v : graph.adjList[i])
			cout << v << " ";
		cout << endl;
	}
}

// Graph Implementation using STL
int main()
{
	// vector of graph edges as per above diagram.
	// Please note that initialization vector in below format will
	// work fine in C++11, C++14, C++17 but will fail in C++98.
	vector<Edge> edges;

	// Number of nodes in the graph
	int N,e;
    cin>>N>>e;
    int i=0;
    while(e--){
        int s,d;
        cin>>s>>d;
    edges.push_back(Edge());
        //cout<<"i "<<i<<" ";
        edges[i].src=s-1;
        edges[i].dest=d-1;
        //cout<<"src:"<<edges[i].src<<" dest:"<<edges[i].dest<<endl;
        i++;

    }

	// construct graph
	Graph graph(edges, N);

    //get leaf nodes
    queue <int> q;
    q=leafs(graph,N);
    // cout<<"leaf vertices"<<endl;
    // while(!q.empty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }
    // cout<<endl;

	// print adjacency list representation of graph
	//printGraphl(graph, N);
//    cout<<"#################"<<endl;
   // printGraph(graph, N);
	int res=0;
    vector<vector<int>> resv;
    resv.resize(N);
    while(q.size()){

		if(q.size() > 1){
			res++;
            int i=q.front();
            q.pop();
			int b=q.front();
			q.pop();
          //  cout<<" the values popped from q ="<<i+1<<" "<<b+1<<endl;
            int j= graph.inList[i].size();
         //   cout<<" size of j "<<j<<endl;
            for(int k=0 ;k < j;k++){
              //  cout<<"inward leafs node "<<graph.inList[i][k]<<" ";
              //  cout<<"deleteing the edge from "<<graph.inList[i][k]<<" "<<i<<endl;
                int lsize=graph.adjList[graph.inList[i][k]].size();
              //  cout<<" size of the L "<<lsize<<endl;
                for(int l=0; l < lsize; l++){
                    if(graph.adjList[graph.inList[i][k]][l]==i){
                        graph.adjList[graph.inList[i][k]].erase(graph.adjList[graph.inList[i][k]].begin()+l);
                    }

                    if(graph.adjList[graph.inList[i][k]].empty()){
              //         cout<<" found the next leaf node############ "<<graph.inList[i][k]+1<<endl;
                       q.push(graph.inList[i][k]);
                    }

                }


            }
			j= graph.inList[b].size();
         //   cout<<" size of b "<<j<<endl;
            for(int k=0 ;k < j;k++){
             //   cout<<"inward leafs node "<<graph.inList[b][k]<<" ";
              //  cout<<"deleteing the edge from "<<graph.inList[b][k]<<" "<<b<<endl;
                int lsize=graph.adjList[graph.inList[b][k]].size();
             //   cout<<" size of the L "<<lsize<<endl;
                for(int l=0; l < lsize; l++){
                    if(graph.adjList[graph.inList[b][k]][l]==b){
                        graph.adjList[graph.inList[b][k]].erase(graph.adjList[graph.inList[b][k]].begin()+l);
                    }

                    if(graph.adjList[graph.inList[b][k]].empty()){
           //            cout<<" found the next leaf node############ "<<graph.inList[b][k]+1<<endl;
                       q.push(graph.inList[b][k]);
                    }

                }
            }
            //resv.resize(res);
            resv[res].push_back(2);
            resv[res].push_back(i+1);
            resv[res].push_back(b+1);
		//	cout<<2<<" "<<i+1<<" "<<b+1<<endl;
		}
		else
        {
			res++;
			int i=q.front();
            q.pop();
          //  cout<<" the values popped from q ="<<i<<endl;
            int j= graph.inList[i].size();
           // cout<<" size of j "<<j<<endl;
            for(int k=0 ;k < j;k++){
            //    cout<<"inward leafs node "<<graph.inList[i][k]<<" ";
            //    cout<<"deleteing the edge from "<<graph.inList[i][k]<<" "<<i<<endl;
                int lsize=graph.adjList[graph.inList[i][k]].size();
            //    cout<<" size of the L "<<lsize<<endl;
                for(int l=0; l < lsize; l++){
                    if(graph.adjList[graph.inList[i][k]][l]==i){
                        graph.adjList[graph.inList[i][k]].erase(graph.adjList[graph.inList[i][k]].begin()+l);
                    }

                    if(graph.adjList[graph.inList[i][k]].empty()){
             //          cout<<" found the next leaf node############ "<<graph.inList[i][k]+1<<endl;
                       q.push(graph.inList[i][k]);
                    }

                }
            }

            //resv.resize(res);
            resv[res].push_back(1);
            resv[res].push_back(i+1);
			//cout<<1<<" "<<i+1<<endl;

		}

       // cout<<endl;
    }
   // cout<<"############total deletion "<<res<<endl;
   // cout<<"##############final"<<endl;
    cout<<res;
    for (int i = 0; i <= res; i++)
	{
		// print current vertex number
		//cout << i << " --> ";

		// print all neighboring vertices of vertex i
		for (int v : resv[i])
			cout << v << " ";
		cout << endl;
	}

//    printGraphl(graph, N);


	return 0;
}
