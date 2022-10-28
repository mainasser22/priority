#include<bits/stdc++.h>
#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    struct process
    {
        int id,arrival_time,burst_time,priority,waiting_time;
    };
    process *arr;
    int num;
    cout<<"Enter number of processes :\n";
    cin>>num;
    arr=new process[num];
    cout<<"\t Priority \t Arrival time \t Burst time \n";
    for(int i=0; i<num; i++)
    {
        arr[i].id=i+1;
        cout<<"P"<<arr[i].id<<"\t";
        cin>>arr[i].priority>>arr[i].arrival_time>>arr[i].burst_time;
    }

    process temp;

    for(int i =0; i<num-1; i++)
    {
        for (int j = i+1; j < num ; j++)
        {
            if (arr[i].priority > arr[j].priority||arr[i].priority == arr[j].priority && arr[i].arrival_time > arr[j].arrival_time)
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;

            }
        }
    }

    arr[0].waiting_time=0;
    int tot=0;
    for(int i=1; i<num; i++)
    {
        //arr[i].waiting_time=arr[i-1].burst_time+arr[i-1].waiting_time;

        tot+=arr[i-1].burst_time;
        arr[i].waiting_time=tot-arr[i].arrival_time;

    }

    cout<<"---------------------------------------------------------------------- \n";
    cout<<"The Sequence of processes will be & Waiting time for each process:"<<"\n \n";

    cout<<"\t Priority \t Arrival time \t Burst time \t Waiting time\n";
    for(int i=0; i<num; i++)
    {
        cout<<"P"<<arr[i].id<<"\t \t"<<arr[i].priority<<"\t \t"<<arr[i].arrival_time<<"\t \t"<<arr[i].burst_time<<"\t \t"<<arr[i].waiting_time<<"\n";

    }
    cout<<"---------------------------------------------------------------------- \n";

    cout<<" Gantt chart \n";
    for(int i=0; i<num; i++)
    {
        cout<<setw(arr[i].burst_time)<<"P"<<arr[i].id<<"\t";
    }

    cout<<"\n 0";
    tot=0;
    for(int i=0; i<num; i++)
    {
        tot+=arr[i].burst_time;
        cout<<setfill('-')<<setw(arr[i].burst_time*2)<<tot;

    }
     cout<<"\n";
    double sum =0;
    for(int i=0; i<num; i++)
    {
        sum+=arr[i].waiting_time;
    }
    cout<<"\n";
    cout<<"Average waiting time ="<<sum<<"/"<<num<<"="<<sum/num<<"\n";
    delete []arr;

    return 0;
}















