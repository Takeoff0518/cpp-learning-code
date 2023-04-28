#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=15,M=1005,n=9;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
char g[N][N];
struct node{
	int x,y;
}s[N];
int idx;
inline int dis(node x,node y){
	return (x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y);
}
bool check(node i,node j,node k,node l){
	if(dis(i,l) == dis(i,k) && dis(k,j) == dis(i,k) && dis(j,l) == dis(j,k) && dis(l,i) == dis(l,j) && dis(i,j) == dis(k,l)) return 1;
	if(dis(i,k) == dis(i,j) && dis(j,i) == dis(j,l) && dis(l,j) == dis(l,k) && dis(k,i) == dis(k,l) && dis(i,l) == dis(k,j)) return 1;
	if(dis(i,j) == dis(i,l) && dis(j,i) == dis(j,k) && dis(k,j) == dis(k,l) && dis(l,i) == dis(l,k) && dis(i,k) == dis(j,l)) return 1;
	return 0;
}
int ans=0;
int main(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
			if(g[i][j]=='#'){
				s[++idx]={(node){i,j}};
			}
		}
	}
	for(int i=1;i<=idx;i++){
		for(int j=i+1;j<=idx;j++){
			for(int k=j+1;k<=idx;k++){
				for(int l=k+1;l<=idx;l++){
					//cout<<i<<j<<k<<l<<endl;
					if(check(s[i],s[j],s[k],s[l])){
						ans++;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
    return 0;
}
//F**k CCF!!!!!

