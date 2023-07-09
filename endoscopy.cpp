 #include<bits/stdc++.h>

using namespace std;

typedef struct
{
    bool left; bool right;
    bool up; bool down;
}Node;

typedef struct
{
    int x;int y;int d;
}Point;

int matrix[1000][1000];
Node pipes[1000][1000];
bool visited[1000][1000];

int N,M;
int xpos,ypos,len;
int c=1;

int dirx[]={0,1,0,-1};
int diry[]={1,0,-1,0};

bool isValid(int x,int y)
{
    if(x>=0 && x<N && y>=0 && y<M)
        return true;
    else
    return false;
}

void solve()
{
    Point src;
    src.x=xpos;
    src.y=ypos;
    src.d=1;
    visited[xpos][ypos]=true;
    queue<Point> q;
    q.push(src);

    if(matrix[xpos][ypos]==0)
    {
        c=0;
        return;
    }

    while(!q.empty())
    {
        Point p,np;
        p=q.front();
        q.pop();

        if(!visited[p.x+1][p.y]&& isValid(p.x+1,p.y) &&p.d<len && pipes[p.x][p.y].down && pipes[p.x+1][p.y].up)
        {
            visited[p.x+1][p.y]=true;
            np.x=p.x+1;
            np.y=p.y;
            np.d=p.d+1;
            c++;
            q.push(np);
            
        }
        if(!visited[p.x-1][p.y]&& isValid(p.x-1,p.y) &&p.d<len && pipes[p.x][p.y].up && pipes[p.x-1][p.y].down)
        {
            visited[p.x-1][p.y]=true;
            np.x=p.x-1;
            np.y=p.y;
            np.d=p.d+1;
            c++;
            q.push(np);
            
        }
        if(!visited[p.x][p.y+1]&& isValid(p.x,p.y+1) &&p.d<len && pipes[p.x][p.y].right && pipes[p.x][p.y+1].left)
        {
            visited[p.x][p.y+1]=true;
            np.x=p.x;
            np.y=p.y+1;
            np.d=p.d+1;
            c++;
            q.push(np);
            
        }
        if(!visited[p.x][p.y-1]&& isValid(p.x,p.y-1) &&p.d<len && pipes[p.x][p.y].left && pipes[p.x][p.y-1].right)
        {
            visited[p.x][p.y-1]=true;
            np.x=p.x;
            np.y=p.y-1;
            np.d=p.d+1;
            c++;
            q.push(np);
            
        }
    }
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    c=1;
    cin >> N>>M;
    cin >> xpos >> ypos>>len;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> matrix[i][j];
            visited[i][j]=false;
            
            if(matrix[i][j]==1)
            {
                pipes[i][j].up=true;
                pipes[i][j].down=true;
                pipes[i][j].left=true;
                pipes[i][j].right=true;
            }
            else if(matrix[i][j]==2)
            {
                pipes[i][j].up=true;
                pipes[i][j].down=true;
                pipes[i][j].left=false;
                pipes[i][j].right=false;
            }
            else if(matrix[i][j]==3)
            {
                pipes[i][j].up=false;
                pipes[i][j].down=false;
                pipes[i][j].left=true;
                pipes[i][j].right=true;
            }
            else if(matrix[i][j]==4)
            {
                pipes[i][j].up=true;
                pipes[i][j].down=false;
                pipes[i][j].left=false;
                pipes[i][j].right=true;
            }
            else if(matrix[i][j]==5)
            {
                pipes[i][j].up=false;
                pipes[i][j].down=true;
                pipes[i][j].left=false;
                pipes[i][j].right=true;
            }
            else if(matrix[i][j]==6)
            {
                pipes[i][j].up=false;
                pipes[i][j].down=true;
                pipes[i][j].left=true;
                pipes[i][j].right=false;
            }
            else if(matrix[i][j]==7)
            {
                pipes[i][j].up=true;
                pipes[i][j].down=false;
                pipes[i][j].left=true;
                pipes[i][j].right=false;
            }
            else
            {
                 pipes[i][j].up=false;
                pipes[i][j].down=false;
                pipes[i][j].left=false;
                pipes[i][j].right=false;
            }
        }
    }
    
    solve();
    cout<<c<<endl;
  }
}

/*
2 
5 6 2 1 3 
0 0 5 3 6 0 
0 0 2 0 2 0 
3 3 1 3 7 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
5 6 2 2 6 
3 0 0 0 0 3 
2 0 0 0 0 6 
1 3 1 1 3 1 
2 0 2 0 0 2 
0 0 4 3 1 1

*/