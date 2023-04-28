#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>
#include<climits>
#include<vector>
#include<queue>
using namespace std;
#define ll long long
#define maxn 1145140
#define inf (1145141919810)
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
inline ll read()
{
    ll w=1,x=0;
    char ch=getchar();
    while(ch<'0' || ch > '9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch-'0');ch=getchar();}
    return x*w;
}
ll n,q;
ll base[maxn];
ll t[(maxn<<2)+10],tag1[(maxn<<2)+10],tag2[(maxn<<2)+10];
void pushup(ll rt)
{
    t[rt]=(t[ls(rt)] > t[rs(rt)]) ? t[ls(rt)]:t[rs(rt)];
   // cout<<114514<<endl;
}
void build(ll rt,ll l,ll r)
{
    ll mid=(l+r)>>1;
    if(l==r)
    {
        t[rt]=base[r];
        //cout<<114514<<endl;
        return;
    }
    build(ls(rt),l,mid);
    build(rs(rt),mid+1,r);
    pushup(rt);
}
void pushdown(ll rt)
{
    if(tag1[rt]!=-inf)
    {
        //t[rt]=tag1[rt];
        tag1[ls(rt)]=tag1[rt];
        tag1[rs(rt)]=tag1[rt];
        t[ls(rt)]=tag1[rt];
        t[rs(rt)]=tag1[rt];
        tag2[ls(rt)]=0;
        tag2[rs(rt)]=0;
        tag1[rt]=-inf;
    }
    if(tag2[rt])
    {
    	/*
		what are you f**king doing???
		*/
        //t[rt]+=tag2[rt];
        tag2[ls(rt)]+=tag2[rt];
        tag2[rs(rt)]+=tag2[rt];
        t[ls(rt)]+=tag2[rt];
        t[rs(rt)]+=tag2[rt];
//        tag2[ls(rt)]+=tag2[ls(rt)];
//        tag2[rs(rt)]+=tag2[rs(rt)];
        tag2[rt]=0;
    }
}
void update1(ll rt,ll ql,ll qr,ll l,ll r,ll mubiao)
{
    if(ql<=l && r<=qr)
    {
        t[rt]=mubiao;
        tag1[rt]=mubiao;
        tag2[rt]=0;
        return;
    }
    ll mid=(l+r)>>1;
    pushdown(rt);
    if(ql<=mid)
    {
        update1(ls(rt),ql,qr,l,mid,mubiao);
    }
    if(qr>mid)
    {
        update1(rs(rt),ql,qr,mid+1,r,mubiao);
    }
    pushup(rt);
}
void update2(ll rt,ll ql,ll qr,ll l,ll r,ll mubiao)
{
    if(ql<=l && r<=qr)
    {
        pushdown(rt);
        t[rt]+=mubiao;
        tag2[rt]+=mubiao;
        return;
    }
    ll mid=l+r>>1;
    pushdown(rt);
    if(ql<=mid)
    {
        update2(ls(rt),ql,qr,l,mid,mubiao);
    }
    if(qr>mid)
    {
        update2(rs(rt),ql,qr,mid+1,r,mubiao);
    }
    pushup(rt);
}
ll query(ll rt,ll l,ll r,ll ql,ll qr)
{
    if(ql<=l && r<=qr)
    {
        return t[rt];
    }
    ll mid=(l+r)>>1;
    ll res=-inf;
    pushdown(rt);
    if(ql<=mid)
    {
        ll next=query(ls(rt),l,mid,ql,qr);
        res=(res>next) ? res:next;
    }
    if(qr>mid)
    {
        ll next=query(rs(rt),mid+1,r,ql,qr);
        res=(res>next) ? res:next;
    }
    return res;
}
int main()
{
    n=read(),q=read();
    for(int i=1;i<=n;i++)
    {
        base[i]=read();
    }
    build(1,1,n);
    //cout<<114514<<endl;
    for(int i=1;i<=(maxn<<2);i++)
    {
        tag1[i]=-inf;
        tag2[i]=0;
    }
    //cout<<114514<<endl;
    for(int i=1;i<=q;i++)
    {
        ll type=read();
        if(type==1)
        {
            ll l=read(),r=read(),x=read();
            update1(1,l,r,1,n,x);
        }
        if(type==2)
        {
            ll l=read(),r=read(),x=read();
            update2(1,l,r,1,n,x);
        }
        if(type==3)
        {
            ll l=read(),r=read();
            printf("%lld\n",query(1,1,n,l,r));
        }
    }
    return 0;
}
