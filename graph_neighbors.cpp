#include<iostream>
using namespace std;
int nodes, edges, x,y,s_node;
int i,j;
int Graph[100][100];
void neighbore(int n)
{
    cout<<"Neighbors of node: "<<n<<endl;

    for( j=1; j<=nodes; j++)
    {
        if(Graph[n][j]== 1)
            cout<<j<<endl;
        else
        {
            cout<<"0";
            break;
        }
    }

}
int main()
{
    cout<<"How many nodes? "<<endl;
    cin>>nodes;
    for( i=1; i<=nodes; i++)
        for( j=1; j<=nodes; j++)
        {
            Graph[i][j]=0;
        }

    cout<<"How many edges? ";
    cin>>edges;
    for(i=1; i<=edges; i++)
    {
        cout<<"Enter node x and y for edge "<<i<<endl;
        cin>>x>>y;
        Graph[x][y]=1;
    }
    cout<<"Enter your node"<<endl;
    cin>>s_node;
    neighbore(s_node);


    return 0;

}
