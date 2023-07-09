#include<bits/stdc++.h>

using namespace std;

bool cycleCheck(int node, int parent, bool visited[], vector<int> graph[])
{
    visited[node]=true;

    for(auto nbr: graph[node])
    {
        if(!visited[nbr])
        {
            bool subprob=cycleCheck(nbr, node, visited, graph);
                if(subprob)
                    return true;
        }
        else if(nbr!=parent)
            return true;
    }
    return false;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int N,M;
    cin >> N >> M;

    vector<int> graph[N+1];
    bool visited[N+1]={false};
    bool ans=false;
    bool flag=false;
    while(M--)
    {
        int x,y;
        cin>> x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i=0;i<N;i++)
    {
        if(!visited[i])
        {
            ans=cycleCheck(i,-1,visited,graph);
            if(ans==true)
                flag=true;
        }
    }
    if(flag)
        cout<<"Cycle Present\n";
    else
        cout<<"Cycle not present\n";
  }
}