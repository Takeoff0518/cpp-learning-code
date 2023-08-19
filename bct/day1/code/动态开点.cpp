int ch[MAXN][2],val[MAXN],cnt;
void update(int &x,int l,int r,int p,int v)
{
	if(!x) x=++cnt;
	if(l==r)
	{
		val[x]+=v;
		return;
	}
	int mid=((l+r)>>1);
	if(p<=mid) update(ch[x][0],l,mid,p,v);
	else update(ch[x][1],mid+1,r,p,v);
	val[x]=val[ch[x][0]]+val[ch[x][1]];
}
int query(int x,int l,int r,int L,int R)
{
	if(!x) return E;
	if(L<=l&&r<=R) return val[x];
	int res=0;
	int mid=((l+r)>>1);
	if(L<=mid) res+=query(ch[x][0],l,mid,L,R);
	if(mid+1<=R) res+=query(ch[x][1],mid+1,r,L,R);
	return res;
}
