#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include<iostream>

using namespace std;
int n,m;

vector<pair<int,int> > v[10005];

void add(int x,int y,int z){
	v[x].push_back(make_pair(y,z));
}

bool vis[10005];
int d[10005];

int s;

int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	// for(int i=0;i<v[1].size();i++){
	// 	printf("%d %d\n",v[1][i].first, v[1][i].second);
	// } 

	//chu zhi
	memset(d, 0x3f, sizeof d);
	d[s] = 0;
	for(int i=1;i<=n;i++){
		int mn = 0x3f3f3f3f;
		int pos = 0;
		for(int j=1;j<=n;j++){
			if(!vis[j] && d[j]<mn){
				mn = d[j];
				pos = j;
			}
		}
		if(!pos){
			break;
		}
		int x=pos;
		vis[pos] = true;
		for(int j=0;j<v[x].size();j++){
			int y=v[x][j].first;
			int w=v[x][j].second;
			if(vis[y]) continue;
			if(d[y] > d[x]+w){
				// d[y] <= d[x]+w
				d[y] = d[x]+w;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{  
		if(d[i]==2147483648)
		 cout<<2147483647<<" ";
		else cout<<d[i]<<" ";
	}
	/*
5 6
2 1 10
1 3 12
1 4 60
5 1 7
3 2 20
3 4 32
	*/

	return 0;
}