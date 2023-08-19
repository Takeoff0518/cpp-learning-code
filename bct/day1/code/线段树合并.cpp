struct Seg
{
	int lc[MAXN*20],rc[MAXN*20],cnt,rt[MAXN],val[MAXN*20];
	void update(int &x,int l,int r,int p,int v)
	{
		if(!x) x=++cnt;
		if(l==r)
		{
			val[x]+=v;
			return;
		}
		if(p<=mid) update(lc[x],l,mid,p,v);
		else update(rc[x],mid+1,r,p,v);
		val[x]=val[lc[x]]+val[rc[x]];
	}
	int merge(int x,int y,int l,int r)
	{
		if(!x||!y) return x+y;
		if(l==r)
		{
			val[x]+=val[y];
			return x;
		}
		lc[x]=merge(lc[x],lc[y],l,mid);
		rc[x]=merge(rc[x],rc[y],mid+1,r);
		val[x]=val[lc[x]]+val[rc[x]];
		return x;
	}
	int query(int x,int l,int r,int p)
	{
		if(!x) return 0;
		if(l==r) return val[x].x;
		if(p<=mid) return query(lc[x],l,mid,p);
		else return query(rc[x],mid+1,r,p);
	}
}sum;
