#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define ll long long
#define PII pair<int,int>
const int N=505,M=10005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
struct E{
    int nxt,to,v;
}edge[M];
int head[N],num_edge;
void add(int from,int to,int dis){
    num_edge++;
    edge[num_edge].nxt=head[from];
    edge[num_edge].to=to;
    edge[num_edge].v=dis;
    head[from]=num_edge;
}
int n,m,w,t;
bool vis[N];
int dis[N],cnt[N];
queue<int> q;
// bool SPFA(int s){
// 	dis[s]=0,vis[s]=1;
//     q.push(s);
//     while(!q.empty()){
//         int t=q.front(); q.pop();
//         vis[t]=0;
//         for(int i=head[t];i;i=edge[i].nxt){
//             int j=edge[i].to;
//             if(dis[j]>dis[t]+edge[i].dis){
//                 dis[j]=dis[t]+edge[i].dis;
//                 if(vis[j]==0){
//                     vis[j]=1;
//                     q.push(j);
//                 }
//             }
//         }
//     }
// }
bool SPFA(int s){
    dis[s]=0,vis[s]=1;
    q.push(s); cnt[s]++;
    while(!q.empty()){
        int t=q.front(); q.pop();
        vis[t]=0;
        for(int i=head[t];i;i=edge[i].nxt){
            int j=edge[i].to;
            if(dis[j]>dis[t]+edge[i].v){
                dis[j]=dis[t]+edge[i].v;
                if(vis[j]==0){
                    vis[j]=1;
                    q.push(j); cnt[j]++;
                    
                }
                if(cnt[j]>n) return 1;
            }
        }
    }
    return 0;
}
int main(){
	scanf("%d",&t);
	while(t--){
        memset(head,0,sizeof(head));
        memset(cnt,0,sizeof(cnt));
        memset(dis,0x3f,sizeof(dis));
        memset(vis,false,sizeof(vis));
        num_edge=0;
		scanf("%d %d %d",&n,&m,&w);
        // puts("m");
		for(int i=1,u,v,ww;i<=m;i++){
			scanf("%d %d %d",&u,&v,&ww);
            add(u,v,ww); add(v,u,ww);
		}
        // puts("w");
        for(int i=1,u,v,ww;i<=w;i++){
            scanf("%d %d %d",&u,&v,&ww);
            add(u,v,-ww);
        }
        
        if(SPFA(1)) puts("YES");
        else puts("NO");
        // puts("cnt:");
        // for(int i=1;i<=n;i++){
        //     printf("%d ",cnt[i]);
        // }
        // puts("\n-----");
	}
    return 0;
}
//F**k CCF!!!!!

