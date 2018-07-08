#include<iostream>
using namespace std;
int main()
{
    int n,i,bTime[20],tmp_arr[20],taTime[20],wTime[20],tq,count=0,temp,k=0;
    float m,j;
    cout<<"Enter number of process: ";
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"Enter process "<<i<<" burst time: ";
        cin>>bTime[i];
        tmp_arr[i]=bTime[i];
    }
    cout<<"Enter time quantum: ";
    cin>>tq;
    cout<<"0 ";

    do{
        for(i=0; i<n; i++)
        {
            temp=tq;
            if(tmp_arr[i]==0)
            {
                count++;
                continue;
            }
            else if(tmp_arr[i]>tq)
            {
                tmp_arr[i]=tmp_arr[i]-tq;
            }
            else if(tmp_arr[i]>=0)
            {
                temp=tmp_arr[i];
                tmp_arr[i]=0;
            }

            k=k+temp;
            taTime[i]=k;
            cout<<"p"<<i<<" "<<k<<" ";

        }

        if(n==count)
            break;

    }while(1);
    cout<<endl<<endl<<"Process\t\tWaiting Time\t\tTurnaround Time"<<endl;
    for(i=0; i<n; i++)
    {
        wTime[i]=taTime[i]-bTime[i];
        cout<<"  P"<<i<<"\t\t   "<<wTime[i]<<"\t\t\t    "<<taTime[i]<<endl;

    }
    cout<<"-----------------------------------------------------------"<<endl;
    for(i=0;i<n;i++)
    {
        m=m+wTime[i];
        j=j+taTime[i];
    }
    m=m/n;
    j=j/n;
    cout<<"Average waiting time: "<<m<<endl;
    cout<<"Average turn-around time: "<<j<<endl;
    cout<<endl<<endl;

}
