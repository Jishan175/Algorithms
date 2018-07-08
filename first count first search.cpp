#include<iostream>
using namespace std;

int main()
{

    int n,prcs[20],wTime[20],aTime[20],bTime[20],taTime[20],i,j;

    cout<<"Enter the number(maximum 20) of process: ";
    cin>>n;
    cout<<endl<<" ENTER PROCESS ARRIVAL TIME & BURST TIME "<<endl;

    for(i=0;i<n;i++)
    {
        cout<<"Process ";
        cin>>prcs[i];
        cout<<" arrival time: ";
        cin>>aTime[i];
        cout<<" Burst time: ";
        cin>>bTime[i];
        cout<<endl;
    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
          if(aTime[i]>aTime[j])
          {
              int temp=aTime[i];
              int temp2=prcs[i];
              int temp3=bTime[i];

              aTime[i]=aTime[j];
              prcs[i]=prcs[j];
              bTime[i]=bTime[j];
              aTime[j]=temp;
              prcs[j]=temp2;
              bTime[j]=temp3;
          }
        }
    }
    wTime[0]=0;
    for(i=1;i<n;i++)
    {
        wTime[i]=0;
        for(j=0;j<n;j++)
            wTime[i]=aTime[i]-bTime[j];
    }

    cout<<"Arrival Time\t\tProcess\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time"<<endl;
    for(i=0;i<n;i++)
    {
        taTime[i]=bTime[i]+wTime[i];
        cout<<aTime[i]<<"\t\t\t"<<prcs[i]<<"\t\t\t"<<bTime[i]<<"\t\t\t"<<wTime[i]<<"\t\t\t"<<taTime[i];
        cout<<endl;
    }


}

