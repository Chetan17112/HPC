#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<omp.h>
using namespace std;
void add_node(vector<vector <int>> &g,int u,int v){
g[u].push_back(v);
g[v].push_back(u);

}
void showq(queue<int> gq)
{
    queue<int> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}
void p_BFS(vector<vector <int>> &g,int s_node){
    vector <bool> visited(g.size(),false);
    queue<int> q;
    visited[s_node] = true;
    q.push(s_node);
    cout<<"BFS:";
    while(!q.empty()){
    int curr_node = q.front();
    q.pop();
    cout<<curr_node<<" ";
    for(int ad_node:g[curr_node]){
        if(!visited[ad_node]){
            q.push(ad_node);
            visited[ad_node] = true;

        }
    }
    }
    cout<<endl;

}l
void p_DFS(vector<vector <int>> &g,int s_node){
    vector <bool> visited(g.size(),false);
    stack<int> q;
    visited[s_node] = true;
    q.push(s_node);
    cout<<"DFS";
    while(!q.empty()){
    int curr_node = q.top();
    q.pop();
    cout<<curr_node<<" ";
    for(int ad_node:g[curr_node]){
        if(!visited[ad_node]){
            q.push(ad_node);
            visited[ad_node] = true;

        }
    }
    }
    cout<<endl;

}
int main(){
    vector<vector <int>> g1(10);
    add_node(g1,0, 1);
    add_node(g1,0, 2);
    add_node(g1,1, 3);
    add_node(g1,1, 4);


    /*for(int i = 0;i<g1.size();++i){
            cout<<i<<"Connected to:";
        for(int E:g1[i]){
            cout<<E<<" ";
        }
        cout<<endl;
    }*/
    p_BFS(g1,0);
    p_DFS(g1,0);
return 0;}
