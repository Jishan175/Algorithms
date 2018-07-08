#include <iostream>

using namespace std;


int Graph[100][100];

int vertices, edges;
int u, v, w;
int i, j;

void InputGraph()
{
    cout<<"Enter vertices and Edges: "<<endl;
    cin>>vertices;
    cin>>edges;

    for(i = 0; i <= vertices; ++i)
        for(j = 0; j <= vertices; ++j)
            Graph[i][j] = 0;

    cout<<"Enter (u,v)"<<endl;

    for(i = 1; i <= edges; ++i)
    {

        cin>>u;
        cin>>v;
        Graph[u][v] = 1;
    }
}

void PrintGraph()
{

    cout<<endl;

    cout<<"Graph:\n";

    for(j = 1; j <= vertices; ++j)
    {
        cout<<"    "<<j<<" ";
    }
    cout<<"\n   --------------";
    cout<<endl;

    for(i = 1; i <=vertices; ++i)
    {
        cout<<i<<"|";
        for(j = 1; j <= vertices; ++j)
        {
            cout<<"  ";
            cout<<Graph[i][j];
            cout<< "   ";

        }
        cout<<endl;
    }

}

int main()
{

    cout<<"Directed Graph:\n";

    InputGraph();
    PrintGraph();

    return 0;
}
