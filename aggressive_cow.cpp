#include<bits/stdc++.h>

using namespace std;

bool check(int mid, int pos, int cows, int matrix[])
{
    int curr_cows=1;
    int left=0;

    for(int i=1;i<pos;i++)
    {
        if(matrix[i]-matrix[left]>=mid)
        {
            left=i;
            curr_cows++;
            if(curr_cows==cows)
                return true;
        }
    }
    return false;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int pos;
    cin >> pos;
    int matrix[pos];
    for(int i=0;i<pos;i++)
    {
        cin>>matrix[i];
    }

    sort(matrix,matrix+pos);

    int cows;
    cin >> cows;

    int l=0;
    int r=matrix[pos-1]-matrix[l]+1;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(check(mid,pos,cows,matrix))
            l=mid;
        else
            r=mid-1;
    }
    cout<<"Answer: "<<l;
  }
}