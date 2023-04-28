#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int x,y,z,n;
ll ans=0,maxx=-INF;
bool vis[N];
struct node{
	int a,b,c;
}s[N];
void debug(){
	for(int i=1;i<=n;i++){
		printf("%d ",vis[i]);
	}
	puts("");
}
void dfsc(int xx,int re){
	//printf("c:%d %d %d\n",xx,re,ans);
	//debug();
	if(re==z){
		//cout<<ans<<endl; 
		maxx=max(maxx,ans);
		return;
	}
	if(xx==n+1) return;
	if(!vis[xx+1]){
		vis[xx+1]=1;
		ans+=s[xx+1].c;
		dfsc(xx+1,re+1);
		ans-=s[xx+1].c;
		vis[xx+1]=0;
	}
	dfsc(xx+1,re);
}
void dfsb(int xx,int re){
	//printf("b:%d %d %d\n",xx,re,ans);
	if(re==y){
		dfsc(0,0);
		return;
	}
	if(xx==n+1) return;
	if(!vis[xx+1]){
		vis[xx+1]=1;
		ans+=s[xx+1].b;
		dfsb(xx+1,re+1);
		ans-=s[xx+1].b;
		vis[xx+1]=0;
	}
	dfsb(xx+1,re);	
}
void dfsa(int xx,int re){
	//printf("a:%d %d %d\n",xx,re,ans);
	if(re==x){
		dfsb(0,0);
		return;
	}
	if(xx==n+1) return;
	//x->x+1
	if(!vis[xx+1]){
		vis[xx+1]=1;
		ans+=s[xx+1].a;
		dfsa(xx+1,re+1);
		ans-=s[xx+1].a;
		vis[xx+1]=0;
	}
	dfsa(xx+1,re);
}


int main(){
	scanf("%d %d %d",&x,&y,&z);
	n=x+y+z;
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&s[i].a,&s[i].b,&s[i].c);		
	}
	dfsa(0,0);
	cout<<maxx<<endl;
    return 0;
}
