#include<bits/stdc++.h>

using namespace std;

bool dfs(int node, bool visited[],vector<bool> &stack, vector<int> graph[])
{
  visited[node]=true;
  stack[node]=true;

  for(auto nbr : graph[node])
  {
    if(!visited[nbr])
    {
      bool subprob=dfs(nbr,visited,stack,graph);
        if(subprob==true)
          return true;
    }
    else if(stack[nbr])
      return true;
  }
  stack[node]=false;
  return false;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int N,M;
    cin >> N >>M;
    vector<int> graph[N+1];
    bool visited[N+1]={false};
    vector<bool> stack(N,false);
    bool ans,flag;

    while(M--)
    {
      int x,y;
      cin >> x>>y;
      graph[x].push_back(y);
    } 

    for(int i=0;i<N;i++)
    {
      if(!visited[i])
      {
        ans=dfs(i,visited,stack,graph);
        if(ans)
          flag=true;
      }
    }
    if(flag)
      cout<<"Cycle Present\n";
    else
      cout<<"Cycle Not Present\n";
  }
}