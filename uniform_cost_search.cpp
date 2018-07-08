#include<iostream>
#include<utility>
#include<queue>
using namespace std;
const int s=9999;
const int mat=9999;
int node,edge,adjMat[s][s],dist[s],parent[s];
int start,fin,path[s];
void init()
{
    for(int i=0;i<s;i++)
    {
        parent[i]=-1;
        dist[i]=mat;
        for(int j=0;j<s;j++)
        {
            adjMat[i][j]=mat;
        }
    }
}
void input()
{
    cout<<"Input number of nodes and edges"<<endl;
    cin>>node>>edge;
    cout<<"Input edge to edge connection and Path cost: "<<endl;
    for(int i=0;i<edge;i++)
    {
        int u,v,path_cost;
        cin>>u>>v>>path_cost;
        adjMat[u][v]=path_cost;
    }
}
void print()
{
    cout<<"Total Cost:"<<dist[fin]<<endl;
    int i=0;
    while(1)
    {
        path[i]=fin;
        fin=parent[fin];
        if(start==path[i])
            break;
        i++;
    }
    cout<<"Path:";
    while(i>=0)
    {
        cout<<path[i]<<" ";
        i--;
    }
}
void ucs()
{
    dist[start]=0;
    pair<int,int> p;
    priority_queue<pair<int,int> >pq;
    p.first=0;
    p.second=start;
    pq.push(p);
    while(!pq.empty())
    {
        p=pq.top();
        pq.pop();
        int u=p.second;
        for(int v=0;v<node;v++)
        {
            if(adjMat[u][v]!=mat)
            {
                if(dist[v]>dist[u]+adjMat[u][v])
                {
                    dist[v]=dist[u]+adjMat[u][v];
                    parent[v]=u;
                    p.first=dist[v];
                    p.second=v;
                    pq.push(p);
                }
            }
        }
    }
}
int main()
{
    init();
    input();
    cout<<"Start node: ";
    cin>>start;
    cout<<"Goal Node: ";
    cin>>fin;
    ucs();
    print();
    return 0;
}
/*
9 15
0 1 1
1 2 2
2 0 7
2 3 4
8 2 6
4 3 1
1 8 4
3 6 2
8 5 3
4 8 5
4 7 0
5 7 8
6 7 6
5 6 2
7 8 1
1 7
*/
