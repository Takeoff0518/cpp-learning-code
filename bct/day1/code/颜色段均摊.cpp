struct seg
{
	int l,r,w1,w2;
	//w1是颜色，w2是权值
	bool operator < (const seg &x)const
	{
		return l<x.l;
	}
};

set<seg> sg;

auto split(int x)
{
	if(x>n) return odt.end();
	auto it=--sg.upper_bound(seg{x,0,0,0});
	if(it->l==x) return it;
	int l=it->l,r=it->r;
	int w1=it->w1,w2=it->w2;
	sg.erase(it);
	sg.insert(seg{l,x-1,w1,w2});
	return sg.insert(seg{x,r,w1,w2}).first;
}

void assign(int l,int r,int w1,int w2)
{
	auto itr=split(r+1),itl=split(l);
	for(auto i=itl;i!=itr;)
	{
		auto tmp=i;
		//do something
		++i;sg.erase(tmp);
	}
	odt.insert((seg){l,r,w1,w2});
}
