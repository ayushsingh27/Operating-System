#include<iostream>
using namespace std;
main()
{ int n;
  cout<<"Enter the number of Processes ";
  cin>>n;
  float a[n],et[n],ct[n],tat[n],w[n];
  float tata=0,wt=0;
  cout<<"Enter Arrival Time Of all the processes respectively "<<endl;
  for(int i=0;i<n;i++)   cin>>a[i];
  cout<<"Enter Execution Time Of all the processes respectively "<<endl;
  for(int i=0;i<n;i++) cin>>et[i];
  ct[0]=et[0];
  for(int i=1;i<n;i++)
  { if(ct[i-1]>a[i]) ct[i]=ct[i-1]+et[i];
    else ct[i]=a[i]+et[i];
  }
  for(int i=0;i<n;i++) 
  tat[i]=ct[i]-a[i];
  for(int i=0;i<n;i++) 
  w[i]=tat[i]-et[i];
  cout<<" Completion Time Of all the processes respectively are "<<endl;
  for(int i=0;i<n;i++) cout<<ct[i]<<"\n";
  cout<<"Turn Around Time Of all the processes respectively are "<<endl;
  for(int i=0;i<n;i++) 
  {tata=(tata+tat[i]);
  cout<<tat[i]<<"\n";
  }
  cout<<" Avg TAT = "<<(tata/n)<<endl<<" Waiting Time Of all the processes respectively are "<<endl;
  for(int i=0;i<n;i++) 
  {
  cout<<w[i]<<"\n";
  wt=(wt+w[i]);
  }
  cout<<"Avg Waiting Time = "<<(wt/n);
}

