#include<iostream>
using namespace std;
int main()
{    
   //process
  int p;
  cout<<"Enter the no. of processes\n\n";
  cin>>p;
	int at[p],wt[p],et[p],ct[p],tat[p],avgwt=0;
	cout<<"Enter Arrival time \n\n";
	for(int i=0;i<p;i++) cin>>at[i];
	cout<<"Enter burst time\n\n";
	for(int i=0;i<p;i++) 
	cin>>et[i];
	
	//Completion time
	ct[0]=et[0];
	for(int i=1;i<p;i++) 
	{
		if(at[i]>ct[i-1])
		ct[i]=at[i]+et[i];
		else
		ct[i]=ct[i-1]+et[i];
	}
	
	//turn around time
		for(int i=0;i<p;i++)
	tat[i]=ct[i]-at[i];
	
	//waiting time	
	for(int i=0;i<p;i++)
	wt[i]=tat[i]-et[i];
	
	//Result
	cout<<"complition time"<<"\t"<<"total arrival time"<<"\t"<<"waiting time\n"<<endl;
	for(int i=0;i<p;i++)
	cout<<ct[i]<<"\t\t\t"<<tat[i]<<"\t\t\t"<<wt[i]<<endl;
}
