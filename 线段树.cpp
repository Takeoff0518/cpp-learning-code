#include<iostream>
#include<cstring>
#include<cstdio>
#define INF 0x3f3f3f3f
#define ll long long
#define N 10005
#define M 10005
using namespace std;
struct _{
    int l,r;
    int data;
    int lson,rson;
};
int a[4*N];
_ t[4*N];
int count;//一共有count个结点
int build(int l,int r){
    ++count;//建一个结点
    t[count].l=l;
    t[count].r=r;
    if(l==r){//如果不能再拆了
        t[count].data=a[l];
        return count;
    }
    int m=(l+r)>>1;
    t[count].lson=build(l,m);
    t[count].rson=build(m+1,r);
    //用左右子树的数据代替自己
    //[l,r]=[l,m]+[m+1,r]
    t[count].data=max(t[t[count].lson].data,\
                      t[t[count].rson].data);//左右子树的最大值的最大值
    return count;
}
int query(int root,int l,int r){
    if(l==t[root].l && r==t[root].r){
        return t[root].data;
    }
    if(r<=t[t[root].lson].r){
        return query(t[root].lson,l,r);
    }
    if(r>=t[t[root].lson].l){
        return query(t[root].rson,l,r);
    }
    int ql=query(t[root].lson,l,t[t[root].lson].r);
    int qr=query(t[root].rson,t[t[root].rson].l,r);
    return max(ql,qr);
}
void update(int node,int i,int v){
    if(t[node].l==t[node].r){
        t[node].data=v;
        return;
    }
    if(i<=t[t[node].lson].r){//找左儿子
        update(t[node].lson,i,v);
    }else{
        update(t[node].rson,i,v);
    }
}
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int root=build(1,n);

    return 0;
}