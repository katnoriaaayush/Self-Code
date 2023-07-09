#include<bits/stdc++.h>

using namespace std;

int n,k;
int result=0;

void minStones(int arr[])
{
    for(int i=0;i<k;i++)
    {
        int min=arr[i];
        for(int j=i;j<n;j++)
        {
            arr[j]-=min;
            result+=min;
        }
    }
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    cin >>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }   
    sort(arr,arr+n);
    cin >> k;
    minStones(arr);
    cout<<result<<endl;
  }
}