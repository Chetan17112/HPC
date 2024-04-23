#include <iostream>
#include <vector>
#include <omp.h>
#include <queue>
using namespace std;
class Graph{
int V;//Number of vertices
vector<vector<int>> adj;
public:
    Graph(int V):V(V),adj(V){}
    //add an edge to graph
    void addEdge(int v,int w){
    adj[v].push_back(w);
    }
    //parallel depth-first search
    void parallelDFS(int startVertex){
    vector<bool>visited(V,false);
    parallelDFSUtil(startVertex,visited);
    }
    void parallelDFSUtil(int v,vector<bool>&visited){
    visited[v]=true;
    cout<<v<<" ";

    #pragma omp parallel for
    for (int i=0;i<adj[v].size();++i)
    {
        int n = adj[v][i];
        if(!visited[n]){
            parallelDFSUtil(n,visited);
        }
    }
    }
void parallelBFS(int startVertex)
{
    vector<bool> visited(V,false);
    queue<int>q;
    visited[startVertex] = true;
    visited[startVertex]=true;
    q.push(startVertex);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        cout<<v<<" ";
        #pragma omp parallel for
        for (int i =0;i<adj[v].size();++i)
        {
            int n = adj[v][i];
            if(!visited[n])
            {
                visited[n]= true;
                q.push(n);
            }
        }
    }

}
};

int main()
{
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,5);
    g.addEdge(3,6);
    cout<<"BFS";
    g.parallelBFS(0);
    cout<<endl;
    cout<<"DFS";
    g.parallelDFS(0);
    cout<<endl;

}

