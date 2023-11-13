#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<queue>
#define N (2000005)
#define M (505)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int t,n,m,k,a[N];
deque<int> st[M<<1];
vector<PII > ans; 
int id[M<<1]; // 维护所在栈编号，局面未出现则为 0
void opt_1(int s){
	ans.push_back({s,0});
}
void opt_2(int s,int t){
	ans.push_back({s,t});
}
int sp_idx;
queue<int> em_q;
bool simple(int x){
	int s=id[x];
	if(!s){
		if(em_q.empty()) return 0;
		id[x]=s=em_q.front();
		em_q.pop(); opt_1(s);
		st[s].push_back(x);
	}else{
		id[x]=0;
		em_q.push(s);
		if(x==st[s].back()){
			opt_1(s);
			st[s].pop_back();
		}else{
			opt_1(sp_idx);
			opt_2(sp_idx,s);
			st[s].pop_front();
		}
	}
	return 1;
} 
void solve(){
	memset(id,0,sizeof(id));
	ans.clear();
	sp_idx=n;
	while(!em_q.empty()) em_q.pop();
	for(int i=1;i<n;i++){
		em_q.push(i); em_q.push(i);
	}
	for(int i=1;i<=m;i++) if(!simple(a[i])){
		int p=a[i],r=i+1,x=a[r];
		for(;r<=m && x!=p && st[id[x]].back()==x;++r,x=a[r]);
		if(x==p){
			opt_1(sp_idx);
			for(int j=i+1;j<r;j++) simple(a[j]);
			opt_1(sp_idx);
		}else{
			int s=id[x],y=st[s].back();
			bool is_y_evn=1;
			for(int j=i+1;j<r;j++)
				if(a[j]==y) is_y_evn=!is_y_evn;
			if(is_y_evn){
				opt_1(s);
				st[s].push_back(p);
				for(int j=i+1;j<r;j++){
					if(a[j]==y) opt_1(sp_idx);
					else simple(a[j]);
				}
				opt_1(sp_idx); opt_2(sp_idx,s);
				st[s].pop_front();
				id[x]=0,id[p]=s;
			}else{
				opt_1(sp_idx);
				st[sp_idx].push_back(p);
				for(int j=i+1;j<r;j++){
					if(a[j]==y) opt_1(s);
					else simple(a[j]); 
				}
				opt_1(s);
				st[s].clear();
				id[x]=id[y]=0;
				id[p]=sp_idx;
				em_q.push(sp_idx);
				sp_idx=s;
			}
		}
		i=r;
	}
	printf("%d\n",(int)ans.size());
	for(PII i:ans){
		if(i.second) printf("2 %d %d\n",i.first,i.second);
		else printf("1 %d\n",i.first);
	}
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&n,&m,&k);
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i]);
		}
		solve();
	}
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

