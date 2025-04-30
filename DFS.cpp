#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v,e,**adj;
    public:
    Graph(int vertexs,int edges);
    void printGraph();
    void newEdge(int start,int end);
    void dfs(int start);
};

Graph::Graph(int v,int e)
{
    this->v=v;
    this->e=e;
    adj=new int*[v];
    for(int i=0;i<v;i++)
    {
        adj[i]=new int[v];
        for(int j=0;j<v;j++)
        {
            adj[i][j]=0;
        }
    }
}

void Graph::printGraph()
{
    cout<<"\nPrinting the Graph"<<endl<<"  ";
    for(int i=0;i<v;i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"------------------------"<<endl;
    
    for(int i=0;i<v;i++)
    {
        cout<<i<<"|";
        for(int j=0;j<v;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Graph::newEdge(int start,int end)
{
    adj[start][end]=1;
    adj[end][start]=1;
}

void Graph::dfs(int start)
{
    cout<<"DFS of the graph is"<<endl;

    vector<bool>visited (v,false);
    stack<int> s;

    s.push(start);
    visited[start]=true;

    while(!s.empty())
    {
        int a=s.top();
        s.pop();
        cout<<a<<" ";
        for(int i=v-1;i>=0;i--)
        {
            if((adj[a][i]==1) && (visited[i]==false) )
            {
                s.push(i);
                visited[i]=true;
            }
        }
    }
}

int main()
{
    int v=8,e=8;
    Graph g(v,e);
    g.newEdge(0,1);
    g.newEdge(0,2);
    g.newEdge(1,3);
    g.newEdge(2,4);
    g.newEdge(2,6);
    g.newEdge(6,7);
    g.newEdge(3,5);
    g.newEdge(5,4);
    g.printGraph();
    g.dfs(0);
}