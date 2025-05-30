#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int **adj,v,e;
    bool *visited;
    public:
    Graph(int v,int e);
    void printGraph();
    void newEdge(int start,int end);
    void BFS(int start);

};

Graph::Graph(int v,int e)
{
    this->v=v;
    this->e=e;
    adj=new int* [v];
    visited=new bool[v];
    for(int i=0;i<v;i++)
    {
        adj[i]=new int [v];

        visited[i]=false;
        for(int j=0;j<v;j++)
        {
            adj[i][j]=0;
        }
    }
}

void Graph::printGraph()
{
    cout<<"  ";
    for(int i=0;i<v;i++)
    {
        cout<<i<<" ";
    }
    cout<<"\n------------------------------------------"<<endl;
    for(int i=0;i<v;i++)
    {
        cout<<i<<"|";
        for(int j=0;j<v;j++)
        {
            if(i==j)
            {
                cout<<"*"<<" ";
            }
            else
            {
                cout<<adj[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

void Graph::newEdge(int start,int end)
{
    adj[start][end]=1;
    adj[end][start]=1;
}

void Graph::BFS(int start)
{
    vector <int> q;
    int vis;
    q.push_back(start);
    visited[start]=true;
    while(!q.empty())
    {
        vis=q[0];
        q.erase(q.begin());
        cout<<vis<<" ";
        for(int i=0;i<v;i++)
        {
            if(adj[vis][i]==1 && visited[i]==false)
            {
                q.push_back(i);
                visited[i]=true;
            }
        }
    }

    
}

int main()
{
    int vertices=8;
    int edges=8;
    Graph g=Graph(vertices,edges);
    g.newEdge(0,1);
    g.newEdge(0,2);
    g.newEdge(1,4);
    g.newEdge(1,7);
    g.newEdge(1,3);
    g.newEdge(2,5);
    g.newEdge(2,6);
    cout<<"Graph is"<<endl;
    g.printGraph();
    cout<<"\nBFS is=>";
    g.BFS(0);
    return 0;
}