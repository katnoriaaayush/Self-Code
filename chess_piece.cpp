#include<vector>
#include<iostream>
#include<queue>

using namespace std;

typedef struct
{
    int x; int y; int level;
}Point;

int N, M;
Point src, dest;
int ans=-1;

int dirx[] = { 1,1,-1,-1,2,2,-2,-2 };
int diry[] = { 2,-2,2,-2,1,-1,1,-1 };

bool isValid(Point p)
{
    if (p.x > 0 && p.x <= N && p.y > 0 && p.y <= N)
        return true;
    else
        return false;
}

void solve(vector<vector<bool>> &visited)
{
    visited[src.x][src.y] = true;
    src.level = 0;
    queue <Point> q;
    q.push(src);

    while (!q.empty())
    {
        Point p, np;
        p = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            np.x = p.x + dirx[i];
            np.y = p.y + diry[i];

            if (np.x == dest.x && np.y == dest.y)
            {
                visited[np.x][np.y]=true;
                return;
            }

            else if (isValid(np) && !visited[np.x][np.y])
            {
                visited[np.x][np.y] = true;
                np.level = p.level + 1;
                ans = np.level;
                q.push(np);
            }
        }

    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> N >> M;
        cin >> src.x >> src.y >> dest.x >> dest.y;

        vector<vector<bool>> visited(N + 1, vector<bool>(M + 1, false));

        solve(visited);
        if(!visited[dest.x][dest.y]){
            cout<<"-1"<<endl;
            
        }
        else 
        cout << ans << endl;
    }
}