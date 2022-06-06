#include<iostream>
#include<algorithm>
using namespace std;
int binarySearch(int a[],int n,int k)
{
   
     int s=1,m,e=n;
     while(s<e)
     {
         m=(s+e)/2;
         if(a[m]<k)
         {
             e=m-1;
         }
         else if(a[m]>k)
         {
             s=m+1;
         }
         else{
             return m;
         }
     }
     return -1;
}
int main()
{     
    int n;
    cout<<"Enter the no. of elements:";
    cin>>n;
    int a[n];
    cout<<"Enter "<<n<<" elements only:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }   
    int k;
    cout<<"Enter key to search:";
    cin>>k;
    int ind=binarySearch(a,n,k);
    if(ind!=-1)
    {
        cout<<k<<" is found at "<<ind<<" position";
    }
    else{
        cout<<k<<" is not found";
    }
    return 0;
}