#include<bits/stdc++.h>

using namespace std;

int N;
int matrix[12][12];
int answer;

void calcDistance(int nodes,int src, int value, bool visited[])
{
    if(nodes==N-1)
    {
        if(matrix[src][0]!=0)
        {
            int d=value+matrix[src][0];
            if(d<answer)
                answer=d;
        }
        else
            answer = -1;

    }

    for(int i=1;i<N;i++)
    {
        if(!visited[i]&&matrix[src][i]!=0)
        {
            visited[i]=true;
            calcDistance(nodes+1,i,value+matrix[src][i],visited);
            visited[i]=false;
        }
    }
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    cin >> N;

    bool visited[12];

    for(int i=0;i<N;i++)
    {
        visited[i]=false;
        for(int j=0;j<N;j++)
        {
            cin >> matrix[i][j];
        }
    }
    answer=INT_MAX;
    calcDistance(0,0,0,visited);
    cout<<answer<<endl;
  }
}