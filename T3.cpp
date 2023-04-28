#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
#define ls(xxx) xxx<<1
#define rs(xxx) xxx<<1|1
struct Tree{
    int l,r;
    ll data,lazy;
    int c[33];
}t[4*N];
int a[N],n;
void build(int p,int l,int r){
    t[p].l=l;
    t[p].r=r;
    if(l==r){
        for(int i=0;i<31;i++){
            if((a[l]>>i)&1){
                t[p].c[i]=1;
            }
        }
        return;
    }
    int mid=l+r>>1;
    build(ls(p),1,mid);
    build(rs(p),mid+1,n);
    for(int i=0;i<31;i++){
        t[p].c[i]=t[ls(p)].c[i]+t[rs(p)].c[i];
    }
}
int spread(int p,int l,int r){
    int mid=(l+r)>>1;
	for(int i=0;i<20;i++)
		if((t[p].lazy>>i)&1){//区间取反 
			t[ls(p)].c[i]=(mid-l+1)-t[ls(p)].c[i];
			t[rs(p)].c[i]=(r-mid)-t[rs(p)].c[i];
		}
	t[ls(p)].lazy^=t[p].lazy;
	t[rs(p)].lazy^=t[p].lazy;
	t[p].lazy=0;
}
void update(int L,int R,int p,int l,int r,int v){
    if(R<l||r<L)
        return;
	if(l<=L && R<=r){
		for(int i=0;i<20;i++) 
			if((v>>i)&1)
                t[p].c[i]=(R-L+1)-t[p].c[i];
		t[p].lazy^=v;
		return;
	}
	int mid=(L+R)>>1;
	spread(p,L,R);//下传标记 
	update(L,mid,ls(p),l,r,v);
	update(mid+1,R,rs(p),l,r,v);
	for(int i=0;i<31;i++){
        t[p].c[i]=t[ls(p)].c[i]+t[rs(p)].c[i];
    }
}
ll query(int L,int R,int p,int l,int r){
    // if(R<l||r<L)return 0;
	// if(l<=L && R<=r){
	// 	long long ret=0,Pow=1;
	// 	for(int i=0;i<20;i++){//求和 
	// 		ret+=Pow*cnt[cur][i];
	// 		Pow<<=1;
	// 	}
	// 	return ret;
	// }
	// int mid=(L+R)>>1;
	// down(L,R,cur);
	// return query(L,mid,ls(cur),l,r)+query(mid+1,R,rs(cur),l,r);
    if(R<l || r<L){
        return 0;
    }
    if(l<=L && R<=r){
        
    }
}
int main(){
    
    return 0;
}