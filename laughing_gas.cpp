#include<bits/stdc++.h>

using namespace std;

typedef struct
{
    int x;int y;int d;
}Point;

int N,M;
int matrix[100][100];
bool visited[100][100];
Point src;
int ans=1;

int dirx[]={0,1,0,-1};
int diry[]={1,0,-1,0};

bool isValid(Point p)
{
    if(p.x>=0 && p.y<N && p.y>=0 && p.y<M)
        return true;
    else
        return false;
}

void bfs()
{
    visited[src.x][src.y]=true;
    queue <Point> q;
    q.push(src);

    while(!q.empty())
    {
        Point p,np;
        p=q.front();
        q.pop();

        for(int i=0;i<4;i++)
        {
            np.x=p.x+dirx[i];
            np.y=p.y+diry[i];

            if(!visited[np.x][np.y]&&matrix[np.x][np.y]==1&&isValid(np))
            {
                np.d=p.d+1;
                ans=np.d;
                visited[np.x][np.y]=true;
                q.push(np);
            }
        }
    }
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >>matrix[i][j]; 
            visited[i][j]=false;
        }
    }
    int a,b;
    cin >> a >> b;
    src.x=a-1;
    src.y=b-1;
    src.d=1;
    bfs();
    cout<<ans<<endl;
  }
}