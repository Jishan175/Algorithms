#include<iostream>

using namespace std;

const int size = 10;
int N, E, mat[size][size], color[10];


void bfs(int u, int dest)
 {
    queue <int> Q;

    color[u] = 1; //visited
    Q.push( u );

    while( !Q.empty() )
    {
        u = Q.front();
        Q.pop();
        cout << u << "->";

        if(u==dest)
            break;

        for(int v = 0; v<N; v++)
        {
            if(mat[u][v] == 1 && color[v] == 0)
            {
                color[v] = 1;
                Q.push(v);
            }
        }

    }
    //cout<<dest;
}

int main()
{
    for(int i = 0; i<size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            mat[i][j] = 0;
        }
    }
    cout<<"Number Of Nodes and Edges"<<endl;

    cin >> N >> E;

    cout<<"Show the relation between edges"<<endl;

    for(int i = 0; i<E; i++)
    {
        int u, v;
        cin >> u >> v;

        mat[u][v] = 1;
        mat[v][u] = 1;
    }


    for( int i = 0; i < N; i++ )
    {
        color[i] = 0;

    }

    int src,des;
    cout<<"starting and goal node"<<endl;
    cin>> src >> des;
    cout<<"BFS"<<endl;
    bfs(src,des);

    return 0;
}
/*
5 6
0 1
0 2
0 3
4 2
2 3
3 0
*/
/*
6 6
1 2
1 4
4 3
4 5
3 6
5 6
*/


