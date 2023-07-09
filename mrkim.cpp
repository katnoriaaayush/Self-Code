#include<bits/stdc++.h>

using namespace std;

int N;
int answer;

typedef struct
{
    int x;int y;
}Point;

int dist(Point i,Point j)
{
    int distance=abs(i.x-j.x)+abs(j.y-i.y);
    return distance;
}

void calcDistance(int nodes,int value,Point src, Point loc[],bool visited[])
{
    if(nodes == N)
    {
        int d=value+dist(src,loc[N+1]);
        if(d<answer)
            answer=d;
        return;
    }

    for(int i=1;i<=N;i++)
    {
        if(!visited[i])
        {
            visited[i]=true;
            calcDistance(nodes+1,value+dist(src,loc[i]),loc[i],loc,visited);
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
    int srcx,srcy,destx,desty;
    cin >> srcx >> srcy >> destx >> desty;

    Point loc[N];
    bool visited[N];

        loc[0].x=srcx;  loc[0].y=srcy;
        loc[N+1].x=destx;   loc[N+1].y=desty;

    for(int i=1;i<=N;i++)
    {
        visited[i]=false;
        cin>>loc[i].x >> loc[i].y;
    }
    answer=INT_MAX;
    calcDistance(0,0,loc[0],loc,visited);
    cout<<answer<<endl;

  }
}