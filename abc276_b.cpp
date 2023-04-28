#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define ll long long
const int N=100005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
vector<int> s[N];
int n,m;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d %d",&u,&v);
		s[u].push_back(v);
		s[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		sort(s[i].begin(),s[i].end());
		printf("%d ",s[i].size());
		for(vector<int>::iterator j=s[i].begin();j!=s[i].end();j++){
			printf("%d ",*j);
		}
		puts("");
	}
    return 0;
}
//F**k CCF!!!!!

