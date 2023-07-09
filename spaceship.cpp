#include<bits/stdc++.h>

using namespace std;

void updateMatrix(int row, int matrix[][5])
{
    if(row<0)
        return;
    int upLimit=max(0,row-4);
    for(int i=row;i>=upLimit;i--)
    {
        for(int j=0;j<5;j++)
        {
            if(matrix[i][j]==2)
                matrix[i][j]=0;
        }
    }
}

int findMaxPoints(int row,int col,int bombs,int matrix[][5])
{
    if(row<=0 || col<0 || col>=5)
    {
        return 0;
    }
    int answer=0;
    if(row>0 && matrix[row-1][col]!=2)
        answer=max(answer,(matrix[row-1][col]==1?1:0)+findMaxPoints(row-1,col,bombs,matrix));
    if(row>0 && col>0 && matrix[row-1][col-1]!=2)
        answer=max(answer,(matrix[row-1][col-1]==1?1:0)+findMaxPoints(row-1,col-1,bombs,matrix));
    if(row>0 && col<4 && matrix[row-1][col+1]!=2)
        answer=max(answer,(matrix[row-1][col+1]==1?1:0)+findMaxPoints(row-1,col+1,bombs,matrix));
    if(answer==0 && bombs>0)
    {
        updateMatrix(row-1,matrix);
        answer=findMaxPoints(row,col,bombs-1,matrix);
    }
    return answer;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
       int row;
       cin >> row;
       int matrix[row+2][5];
       for(int i=0;i<row;i++)
       {
        for(int j=0;j<5;j++)
        {
            cin >> matrix[i][j];
        }
       }
       int ans=findMaxPoints(row,2,1,matrix);
       cout<<"Answer: "<<ans<<endl;
  }
}