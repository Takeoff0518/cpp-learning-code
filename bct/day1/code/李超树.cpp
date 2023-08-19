struct Line
{
	double k,b;
}a[MAXN];

double f(int id,int v);

struct Seg
{
	int val[MAXN*4];
	void modifi(int x,int l,int r,int L,int R,int v)
	{
		if(L<=l&&r<=R)
		{
			update(x,l,r,v);
			return;
		}
		if(L<=mid) modifi(lc,l,mid,L,R,v);
		if(mid+1<=R) modifi(rc,mid+1,r,L,R,v);
	}
	void update(int x,int l,int r,int v)
	{
		if(l==r)
		{
			if(f(v,l)>f(val[x],l))
				val[x]=v;
			return;
		}
		if(a[v].k>a[val[x]].k)
		{
			if(f(v,mid)>f(val[x],mid))
				update(lc,l,mid,val[x]),val[x]=v;
			else update(rc,mid+1,r,v);
		}
		if(a[v].k<a[val[x]].k)
		{
			if(f(v,mid)>f(val[x],mid))
				update(rc,mid+1,r,val[x]),val[x]=v;
			else update(lc,l,mid,v);
		}
	}
	int query(int x,int l,int r,int v)
	{
		int res=val[x];
		double mx=f(val[x],v);
		if(l==r) return res;
		if(v<=mid)
		{
			int tmp=query(lc,l,mid,v);
			if(f(tmp,v)>mx) mx=f(tmp,v),res=tmp;
		}
		else
		{
			int tmp=query(rc,mid+1,r,v);
			if(f(tmp,v)>mx) mx=f(tmp,v),res=tmp;
		}
		return res;
	}
}tr;
