#include<bits/stdc++.h>

using namespace std;

int N,M;
vector<int> bipartite;
bool dfs(int node, int parent, int color, int visited[],vector<int> graph[])
{
    visited[node]=color;
    if(color==1)
    {
        bipartite.push_back(node);
    }
    for(auto nbr: graph[node])
    {
        if(!visited[nbr])
        {
            bool subprob=dfs(nbr,node,3-color,visited,graph);
            if(!subprob)
                return false;
        }
        else if(nbr!=parent && visited[nbr]==color)
            return false;
    }
    return true;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    cin >> N >> M;
    vector<int> graph[N+1];
    int visited[N+1]={0};
    bipartite.clear();
    bool ans;
    while(M--)
    {
        int x,y;
        cin >> x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i=0;i<N;i++)
    {
        if(!visited[i])
        {
            ans=dfs(i,-1,1,visited,graph);
            if(ans==true)
                break;
        }
    }
    if(ans==true)
    {
        cout<<"Bipartite Graph\n";
        for(auto i:bipartite)
            cout<<i<<" ";
        cout<<endl;
    }
    else
    {
        cout<<"Not Bipartite\n";
    }
  }
}
