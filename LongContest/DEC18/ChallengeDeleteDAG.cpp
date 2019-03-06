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
	//printGraph(graph, N);

    while(!q.empty()){
        if(q.size()>=2){
            int i=q.front();
            for(int k=0;k<graph.inList[i].size();k++){
                cout<<"when two leafs"<<graph.adjList[inList[i]][k];
                //cout<<"when two leafs"<<graph.adjList[inList[j]][k];
            }
        }
    }

	return 0;
}
