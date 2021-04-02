/**
 * @file fcfs1.cpp
 * @author Basav Bamrah
 * @brief First Come First Serve CPU algo  
 * @version 0.1
 * 
 */
#include <iostream>
using namespace std;


void wating_time(int bt[],int wt[],int n)
{
    wt[0]=0;
    for(int i=1;i<n;i++)
    {
        wt[i]=bt[i-1]+wt[i-1];
    }

}

void turnAround(int bt[],int wt[],int tard[],int n)
{
    for(int i=0;i<n;i++)
        tard[i]=bt[i]+wt[i];
}

void avgTime(int bt[],int wt[],int tard[],int n)
{
    float avgwt=0.0;
    float avgtat=0.0;
    for(int i=0;i<n;i++)
    {
        avgtat+=tard[i];
        avgwt+=wt[i];
    }
    cout<<"Average Wating time: "<<avgwt/n<<endl;
    cout<<"Average Turn around time: "<<avgtat/n<<endl;
}
void disp(int p[],int bt[],int wt[],int tard[],int n)
{
    cout<<"PROCESSES   BURST TIME   WATING TIME   TURN AROUND TIME\n";
    for(int i=0; i<n;i++)
    {
        cout << " " << p[i]<< "\t\t" << bt[i] <<"\t "<< wt[i] <<"\t\t " << tard[i] <<endl;
    }
}
int main()
{
    int n;
    cout<< " enter the number of processes:\n";
    cin>>n;
    cout<<"Enter the burst time for each\n";
    int p[n],bt[n],wt[n];
    int tard[n];
    for(int i=0;i<n;i++)
    {
        p[i]=i+1;
        cin>>bt[i];
    }
    wating_time(bt,wt,n);
    turnAround(bt,wt,tard,n);
    disp(p,bt,wt,tard,n);
    avgTime(bt,wt,tard,n);

}
