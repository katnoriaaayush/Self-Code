#include<bits/stdc++.h>

using namespace std;

typedef struct
{
    int x;int y;
}Point;

typedef struct
{
    Point p1;
    Point p2;
    int cost;
}wormhole;

int N;
Point src,dest;
int answer;

int calcDist(Point i, Point j)
{
    int answer=abs(i.x-j.x)+abs(i.y-j.y);
    return answer;
}

void minCost(Point src,int value,bool visited[], wormhole hole[])
{
    if(answer>value+calcDist(src,dest))
    {
        answer=value+calcDist(src,dest);
    }

    for(int i=0;i<N;i++)
    {
        if(!visited[i])
        {
            visited[i]=true;
            minCost(hole[i].p2,value+calcDist(src,hole[i].p1)+hole[i].cost,visited,hole);
            minCost(hole[i].p1,value+calcDist(src,hole[i].p2)+hole[i].cost,visited,hole);
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
    cin >>src.x >> src.y>>dest.x >> dest.y;

    wormhole hole[N];
    bool visited[N]={false};

    for(int i=0;i<N;i++)
    {
        cin >> hole[i].p1.x >> hole[i].p1.y >> hole[i].p2.x >> hole[i].p2.y >> hole[i].cost;
    }
    answer=INT_MAX;
    minCost(src,0,visited,hole);
    cout<<"Answer: "<<answer<<endl;
  }
}