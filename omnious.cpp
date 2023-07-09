#include<bits/stdc++.h>

using namespace std;

//vector<int> invalid;

void solve(int low,int high, int count, int times, int hide[])
{
	
	for(int i=low;i<=high;i++)
	{
		
		int c=0;
		int temp=i;
		while(temp)
		{
			int rem=temp%10;
			for(int j=0;j<count;j++)
			{
				if(rem==hide[j])
				{
					c++;
				}
			}
			temp=temp/10;
		}
		if(c>=times)
		{
			cout<<i<<" ";
		}
	}
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
	//invalid.clear();
	int low,high;
	int times;
	int count;
	cin >> low>>high >> count;
	cin >> times;
	int hide[count];
	for(int i=0;i<count;i++)
	{
		cin >> hide[i];
	}
	solve(low,high,count,times,hide);
	//for(auto i:invalid)
	{
		//cout<<invalid[i]<<" ";
	}
	cout<<endl;
  }
}