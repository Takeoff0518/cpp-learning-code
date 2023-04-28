#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#define N (1005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
struct node{
	ll w,c;
	bool operator < (const node &x) const{
		return x.c>c;
	}
};
set<node> s;
ll ans_w,ans_c;
int main(){
	int opt,w,c; 
	while(scanf("%d",&opt)!=EOF){
		if(opt==-1) break;
		if(opt==1){
			scanf("%d %d",&w,&c);
			s.insert((node){w,c});
		}else if(opt==2){
			if(s.size()) s.erase(--s.end());
		}else{
			if(s.size()) s.erase(s.begin());
		}
	}
	for(set<node>::iterator it=s.begin();it!=s.end();it++){
		//printf("%lld %lld\n",(*it).w,(*it).c);
		ans_w+=(*it).w,ans_c+=(*it).c;
	}
	printf("%lld %lld",ans_w,ans_c);
    return 0;
}
//F**k CCF!!!!!

