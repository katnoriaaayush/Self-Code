#include<vector>
#include<iostream>
#include<climits>

using namespace std;

typedef struct
{
    int x; int y;
}Point;

int N; int answer;
int dirx[] = { 0,1,0,-1 };
int diry[] = { 1,0,-1,0 };

void printPath(vector<vector<int>> path)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValid(Point p)
{
    if (p.x >= 0 && p.x < N && p.y >= 0 && p.y < N)
        return true;
    else
        return false;
}

void solve(int value, Point src, Point dest, vector<vector<int>>& path, vector<vector<bool>> &visited, vector<vector<int>> matrix)
{
    if (src.x == dest.x && src.y == dest.y)
    {
        if (value > answer)
        {
            answer = value;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (visited[i][j] == true)
                        path[i][j] = 3;
                    else
                        path[i][j] = matrix[i][j];
                }
            }
            return;
        }
        
    }

    for (int i = 0; i < 4; i++)
    {
        Point np;
        np.x = src.x + dirx[i];
        np.y = src.y + diry[i];

        if (isValid(np)&&!visited[np.x][np.y] && matrix[np.x][np.y] != 1 )
        {
            visited[np.x][np.y] = true;
            if (matrix[np.x][np.y] == 2)
                solve(value + 1, np, dest, path, visited, matrix);
            else
                solve(value, np, dest, path, visited, matrix);
            visited[np.x][np.y] = false;
        }
    }

}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> N;
        vector<vector<int>> matrix(N+1, vector<int>(N+1, 0));
        vector<vector<bool>> visited(N+1, vector<bool>(N+1, false));
        vector<vector<int>> path(N, vector<int>(N, 0));

        Point src, dest;
        src.x = 0;    src.y = 0;
        dest.x = N - 1; dest.y = N - 1;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> matrix[i][j];
            }
        }
        answer = INT_MIN;

        visited[src.x][src.y]=true;

        if (matrix[0][0] == 2)
            solve(1, src, dest, path, visited, matrix);
        else
            solve(0, src, dest, path, visited, matrix);

        cout << "Answer: " << answer << endl;
        printPath(path);

    }
}