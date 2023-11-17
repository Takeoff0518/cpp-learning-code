#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#define N (500005)
#define M (1000005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (1000000007)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
ll fpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int s[N];//��uΪ���ڵ�������ڱ���
int e[N];//˫��ͨ����u�еı���
int n,m;
struct E{
	int nxt,to;
}e1[M],e2[M];
int h1[N],h2[N],idx1,idx2;
void add1(int from,int to){
	e1[++idx1].nxt=h1[from];
	e1[idx1].to=to;
	h1[from]=idx1;
}
void add2(int from,int to){
	e2[++idx2].nxt=h2[from];
	e2[idx2].to=to;
	h2[from]=idx2;
}
//siz: ˫��ͨ����u�еĵ���
int dfn[N],low[N],timestamp,siz[N],id[N],scc_cnt;
stack<int> st;
bool inst[N];
void dfs(int u,int fa){
	s[u]=e[u];
	for(int i=h2[u];i;i=e2[i].nxt){
		int j=e2[i].to;
		if(j==fa) continue;
		dfs(j,u); s[u]+=s[j]+1;
	}
}
int f[N][2],ans;
void dp(int u,int fa){
	for(int i=h2[u];i;i=e2[i].nxt){
		int j=e2[i].to;
		if(j==fa) continue;
		dp(j,u);
		int t0=0,t1=0;
		//xɨ��y֮ǰ������û�б�Ӫ������y��Ҳû�У������߿�ѡ�ɲ�ѡ
		t0=(t0+f[u][0]*f[j][0]*2)%mod;
		//x����֮ǰ�б�Ӫ������y��Ҳû�У������߿�ѡ�ɲ�ѡ
		t1=(t1+f[u][1]*f[j][0]*2)%mod;
		//x����֮ǰ�б�Ӫ������y��Ҳ�У������߱���ѡ
		t1=(t1+f[u][1]*f[j][1])%mod;
		//x����֮ǰû�б�Ӫ������y��Ҳ�У������߱���ѡ
		t1=(t1+f[u][0]*f[j][1])%mod;
		f[u][0]=t0;
		f[u][1]=t1;
	}
	if(u==1) ans=(ans+f[u][1])%mod;
	else ans=(ans+f[u][1]*fpow(2,s[1]-s[u]-1))%mod;
}
void tarjan(int u){
	dfn[u]=low[u]=++timestamp;
	st.push(u); inst[u]=1;
	for(int i=h1[u];i;i=e1[i].nxt){
		int j=e1[i].to;
		if(!dfn[j]){
			tarjan(j);
			low[u]=min(low[u],low[j]);
		}else if(inst[j]){
			low[u]=min(low[u],dfn[j]);
		}
	}
	if(dfn[u]==low[u]){
		int y; scc_cnt++;
		do{
			y=st.top(); st.pop(); inst[y]=0;
			id[y]=scc_cnt; siz[scc_cnt]++;
		}while(y!=u);
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d %d",&u,&v);
		add1(u,v); add1(v,u);
	}
	tarjan(1);
	for(int i=1;i<=n;i++){
		for(int tt=h1[i];tt;tt=e1[tt].nxt){
			int j=e1[tt].to;
//			puts("awa");
			if(id[i]!=id[j]){
				add2(id[i],id[j]);
				add2(id[j],id[i]);
			}
			else e[id[i]]++;
		}
	}
	for(int i=1;i<=scc_cnt;i++){
		e[i]>>=1;
		f[i][0]=fpow(2,e[i]);
		f[i][1]=fpow(2,siz[i]+e[i])-f[i][0];
	}
	dfs(1,0); dp(1,0);
	printf("%d\n",ans);
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

