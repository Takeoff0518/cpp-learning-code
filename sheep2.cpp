#include<bits/stdc++.h>
#define MAXN 5000010
using namespace std;
int pre[MAXN],q,n,m,ans[MAXN];
int c[MAXN];
bool self[MAXN];
struct node{
        int st,ed,v;
}Edge[MAXN];
struct Query{
        int ed,id;
};
vector<Query> Q[MAXN];
bool cmpEdge(node A,node B){
        return A.v<B.v;
}
int Find(int x){
        while(1){
                if(pre[x]==x)return x;
                x=pre[x];
        }
}
void merge(int x,int y,int val){
        int fx=Find(x),fy=Find(y);
        if(fx==fy)return;
        if(Q[fx].size()>Q[fy].size())swap(fx,fy);
        pre[fx]=fy;
        for(int i=0;i<Q[fx].size();i++){
                int t=Q[fx][i].ed,id=Q[fx][i].id;
                if(ans[id]!=-1)continue;
                int ft=Find(t);
                if(ft==fy)ans[id]=val;
        }
        for(int i=0;i<Q[fx].size();i++)Q[fy].push_back(Q[fx][i]);
}
int main() {
        memset(ans,-1,sizeof(ans));
        scanf("%d %d",&n,&m);scanf("%d",&q);
        for(int i=1;i<=m;i++){
                int st,ed,v;
                scanf("%d %d %d",&st,&ed,&v);
                Edge[i].st=st,Edge[i].ed=ed,Edge[i].v=v;
        }
        sort(Edge+1,Edge+1+m,cmpEdge);
        
        for(int i=1;i<=q;i++){
                int x,y;
                scanf("%d %d",&x,&y);
                if(x==y) self[i]=1;
                Q[x].push_back((Query){y,i});
                Q[y].push_back((Query){x,i});
                scanf("%d",&c[i]);
        }
        for(int i=1;i<=n;i++)pre[i]=i;
        for(int i=1;i<=m;i++)merge(Edge[i].st,Edge[i].ed,Edge[i].v);
//        for(int i=1;i<=q;i++) printf("%d ",ans[i]);
//        puts("");
		for(int i=1;i<=q;i++){
			if(self[i]) puts("Yes");
        	else if(ans[i]==-1 || ans[i]>c[i]) puts("No");
        	else puts("Yes");
		}
        return 0;
}

