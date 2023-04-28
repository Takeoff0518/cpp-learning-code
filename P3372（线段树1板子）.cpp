#include<iostream>
#include<cstdio>
#define ll long long
#define N 100010
using namespace std;
int a[N],n,m;
#define lson(xxx) xxx<<1
#define rson(xxx) xxx<<1|1
//存图
//线段树要用结构体存储 
struct tree{
	int l,r;//l，r代表该节点维护的区间范围
	long long data,lazy;//pre代表该节点维护的值，add与懒标记有关 
}t[4*N];
//建树 
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;//以p为编号的节点维护的区间为l到r
	if(l==r){//l=r的话，这个区间就只有一个数，直接让区间维护的值等于a[i]
		t[p].data=a[l];
		return;
	}
	//否则维护的值等于左儿子加右儿子
	int mid=l+r>>1;
	build(lson(p),l,mid);
	build(rson(p),mid+1,r);
	t[p].data=t[lson(p)].data+t[rson(p)].data;
}
//懒标记（延迟标记）
/*懒标记的精髓就是打标记和下传操作，
由于我们要做的操作是区间加一个数，
所以我们不妨在区间进行修改时为该区间打上一个标记，
就不必再修改他的儿子所维护区间，等到要使用该节点的儿子节点维护的值时，
再将懒标记下放即可，可以节省很多时间，对于每次区间修改和查询，
将懒标记下传，可以节省很多时间*/
void spread(int p){
	if(t[p].lazy){//如果懒标记不为0，就将其下传，修改左右儿子维护的值
		t[lson(p)].data+=t[p].lazy*(t[lson(p)].r-t[lson(p)].l+1);
		t[rson(p)].data+=t[p].lazy*(t[rson(p)].r-t[rson(p)].l+1);
		//为该节点的左右儿子打上标记
		t[lson(p)].lazy+=t[p].lazy;
		t[rson(p)].lazy+=t[p].lazy;
		t[p].lazy=0;//下传之后将该节点的懒标记清0
	}	
} 
//区间修改
/* 考虑将一个区间加上一个数，我们可以从根节点不断向下查找，
当发现我们要修改的区间覆盖了当前节点时，我们就把这个区间给修改，
并打上懒标记（由于懒标记存在，我们就不必再修改他的儿子节点），
否则下传懒标记，继续向下找 */
void change(int p,int x,int y,int z){
	if(x<=t[p].l && y>=t[p].r){//被覆盖的话，就对其进行修改
		t[p].data+=(ll)z*(t[p].r-t[p].l+1);
		t[p].lazy+=z;//打上懒标记
		return;
	}
	//如果发现没有被覆盖，那就需要继续向下找，
	//考虑儿子所维护的区间可能因为懒标记的存在而没有修改，因此将懒标记下放
	spread(p);
	int mid=t[p].l+t[p].r>>1;
	if(x<=mid)//如果要修改的区间覆盖了左儿子，就修改左儿子
		change(lson(p),x,y,z);
	if(y>mid)//如果要修改的区间覆盖了右儿子，就修改右儿子
		change(rson(p),x,y,z);
	t[p].data=t[lson(p)].data+t[rson(p)].data;//最终维护的值等于左儿子的值+右儿子的值    
}
//区间查询
/*考虑询问一个区间的和，依旧是从根节点向下查找，
当发现该节点被覆盖时，就返回维护的值，否则下传懒标记，
查询左右儿子，累加答案*/ 
ll ask(int p,int x,int y){
	if(x<=t[p].l && y>=t[p].r)//如果被覆盖，就返回维护的值
		return t[p].data;
	spread(p);//下传懒标记，并查询左右儿子
	int mid=t[p].l+t[p].r>>1;
	ll ans=0;//累加答案，返回左右儿子的和
	if(x<=mid)
		ans+=ask(lson(p),x,y);
	if(y>mid)
		ans+=ask(rson(p),x,y);
	return ans;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int q,x,y,z;
		scanf("%d",&q);
		if(q==1){//加 
			scanf("%d %d %d",&x,&y,&z);
			change(1,x,y,z);
		}else{//查询 
			scanf("%d %d",&x,&y);
			printf("%lld\n",ask(1,x,y));
		}
	}
	return 0;
}