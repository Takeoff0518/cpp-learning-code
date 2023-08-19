struct Seg 
{
	int root[MAXN],tot,val[MAXN*20],lc[MAXN*20],rc[MAXN*20];
	void build(int &x,int l,int r)
	{
		x=++tot;
		if(l==r)
		{
			val[x]=read();
			return;
		}
		build(lc[x],l,mid);
		build(rc[x],mid+1,r);
		return;
	}
	void update(int pre,int &x,int l,int r,int p,int v)
	{
		x=++tot;
		if(l==r)
		{
			val[x]=v;
			return;
		}
		if(p<=mid)
		{
			rc[x]=rc[pre];
			update(lc[pre],lc[x],l,mid,p,v);
		}
		else
		{
			lc[x]=lc[pre];
			update(rc[pre],rc[x],mid+1,r,p,v);
		}
	}
	int query(int x,int l,int r,int p)
	{
		if(l==r) return val[x];
		if(p<=mid) return query(lc[x],l,mid,p);
		else return query(rc[x],mid+1,r,p);
	}
}a;

