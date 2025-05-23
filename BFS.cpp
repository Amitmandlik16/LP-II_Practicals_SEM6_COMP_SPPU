#include <bits/stdc++.h>
using namespace std;
 
class Graph
{
    int v,e,**adj;
    public:
    Graph(int v,int e);
    void newEdge(int start,int e);
    void BFS(int start);
 
};
 
Graph::Graph(int v,int e)
{
    this->v=v;
    this->e=e;
    adj=new int*[v];
    for(int row=0;row<v;row++)
    {
        adj[row]=new int[v];
        for(int column=0;column<v;column++)
        adj[row][column]=0;
    }
}
 
void Graph::newEdge(int start,int e)
{
    adj[start][e]=1;
    adj[e][start]=1;
}
 
void Graph::BFS(int start)
{
    vector<bool> visited(v,false);
    vector<int> q;
    q.push_back(start);
    visited[start]=true;
    int vis;
    while(!q.empty())
    {
        vis=q[0];
        cout<<vis<<" ";
        q.erase(q.begin());
        for(int i=0;i<v;i++)
        if(adj[vis][i]==1 && (!visited[i]))
        {
            q.push_back(i);
            visited[i]=true;
        }
    }
}
 
int main()
{
    int v=8,e=9;
    Graph G(v,e);
    G.newEdge(0,1);
    G.newEdge(0,2);
    G.newEdge(1,3);
    G.newEdge(2,4);
    G.newEdge(3,4);
    G.newEdge(2,6);
    G.newEdge(6,7);
    G.newEdge(5,4);
 
    G.BFS(0);
}