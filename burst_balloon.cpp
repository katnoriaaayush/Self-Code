#include<bits/stdc++.h>

using namespace std;

typedef struct
{
    int index;
    int number;
}balloon;

int N;
int answer=INT_MIN;

int calcPoints(balloon path[],balloon matrix[])
{
    balloon dup[N];
    for(int i=0;i<N;i++)
    {
        dup[i]=matrix[i];
    }

    int l,r,n;
    
    int score=0;

    for(int i=0;i<N;i++)
    {
        l=-1;r=-1;
        n=1;
        int curr_value=path[i].number;
        int curr_index=path[i].index;

        while(curr_index-n>=0)
        {
            if(dup[curr_index-n].number!=-1)
            {
                l=curr_index-n;
                break;
            }
            n++;
        }

        n=1;

        while(curr_index+n<N)
        {
            if(dup[curr_index+n].number!=-1)
            {
                r=curr_index+n;
                break;
            }
            n++;
        }
        

        if(l==-1 && r==-1)
            score+=dup[curr_index].number;
        if(l!=-1 && r!=-1)
            score+=dup[l].number*dup[r].number;
        if(l!=-1 && r==-1)
            score+=dup[l].number;
        if(l==-1 && r!=-1)
            score+=dup[r].number;

        dup[curr_index].number=-1;
    }    
    return score;
}

void solvePoints(int nodes,  balloon path[],bool visited[], balloon matrix[])
{
    if(nodes == N)
    {
        int value=calcPoints(path,matrix);
        if(value>answer)
            answer=value;
    }

    for(int i=0;i<N;i++)
    {
        if(!visited[i])
        {
            visited[i]=true;
            path[nodes]=matrix[i];
            solvePoints(nodes+1,path,visited,matrix);
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

    balloon matrix[N];
    balloon path[N];
    bool visited[N];

    for(int i=0;i<N;i++)
    {
        cin>>matrix[i].number;
        matrix[i].index=i;
    }
    
    solvePoints(0,path,visited,matrix);
    cout<<"Answer: "<< answer<<endl;
  }
}