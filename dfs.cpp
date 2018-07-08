#include<iostream>

using namespace std;

const int SZ = 999;
int adjMat[SZ][SZ], N, E;
int col[SZ], dis[SZ], fin[SZ], par[SZ], vt;

void DFSvisit( int u ) {
    cout << u << " ";
    col[u] = 1;
    dis[u] = ++vt;
    for( int v = 0; v < N; v++ ) {
        if( adjMat[u][v] == 1 && col[v] == 0 ) {
            par[v] = u;
            DFSvisit( v );
        }
    }
    fin[u] = ++vt;
    col[u] = 2;
}

void DFS(int i) {
    for(  i = 0; i < N; i++ ) {
        col[i] = 0;
        par[i] = -1;
    }
    vt = 0;
    for(  i = 0; i < N; i++ ) {
        if( col[i] == 0 ) {
            DFSvisit( i );
        }
    }
}

int main() {
    int st;
    for( int i = 0; i < SZ; i++ ) {
        for( int j = 0; j < SZ; j++ ) {
            adjMat[i][j] = 0;
        }
    }
    cout<<"Enter Number of Vertices and edges:"<<endl;
    cin >> N >> E;


    cout<<"starting Node"<<endl;
    cin>>st;

    cout<<"Enter the edge connections:"<<endl;


    for( int i = 0; i < E; i++ ) {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;
    }
    cout << endl;
    for( int i = 0; i < N; i++ ) {
        for( int j = 0; j < N; j++ ) {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << "DFS visiting order: ";
    DFS(st);


    cout << endl << endl;
    cout << "node\t col\t dist\t fin\t par" << endl;
    for( int i = 0; i < N; i++ ) {
        cout << i << "\t " << col[i]<< "\t " << dis[i] << "\t " << fin[i] << "\t " << par[i] << endl;
    }
    cout << endl;


    return 0;
}
/*
7 7
0
0 1
0 2
0 3
1 4
1 5
2 6
6 5
*/
