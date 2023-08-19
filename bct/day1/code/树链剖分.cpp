int dfn[MAXN],cnt,top[MAXN],dep[MAXN],F[MAXN],siz[MAXN],b_son[MAXN];
void dfs1(int u,int fa)
{
	dep[u]=dep[fa]+1;F[u]=fa;siz[u]=1;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[b_son[u]]<siz[v])
			b_son[u]=v;
	}
}
void dfs2(int u,int Top)
{
	top[u]=Top;dfn[u]=++cnt;
	if(b_son[u])
		dfs2(b_son[u],Top);
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa||v==b_son[u])
			continue;
		dfs2(v,v);
	}
}
void update(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[x]<dep[y])
			swap(x,y);
		//修改[dfn[top[x]],dfn[x]]这一段区间
		x=F[top[x]]; 
	}
	if(dep[x]<dep[y]) swap(x,y);
	//修改[dfn[y],dfn[x]]这一段区间 
}
