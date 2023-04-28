#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#define INF 0x3f3f3f3f
#define ll long long
#define N 1000005
#define M 1005
using namespace std;
int n,m,q,sq;
int a[N],bel[N];
int st[M],ed[M],size[M],mark[M];
vector<int> v[M];//排序后的数组
void update(int b){//更新排序后的数组 
	for(int i=0;i<=size[b];i++){
		v[b][i]=a[st[b]+i];
	}
	sort(v[b].begin(),v[b].end());
}
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main(){
	n=read();m=read();
	//初始化块状数组
	sq=sqrt(n);//计算块长 
	for(int i=1;i<=sq;i++){//计算每个块的首尾下标 
		st[i]=n/sq*(i-1)+1;
		ed[i]=n/sq*i;
	}
	ed[sq]=n;//将结尾不整的块放入最后一个块中
	for(int i=1;i<=sq;i++){
		for(int j=st[i];j<=ed[i];j++){
			bel[j]=i;//确定每个数属于哪个块 
		}
	}
	for(int i=1;i<=sq;i++){
		size[i]=ed[i]-st[i]+1;//计算块长 
	}
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=sq;i++){
		for(int j=st[i];j<=ed[i];j++){
			v[i].push_back(a[j]);
		}
	}
	for(int i=1;i<=sq;i++){
		sort(v[i].begin(),v[i].end());//块内排序 
	}
	while(m--){
		char opt[100000];
		int l,r,k;
		scanf("%s",opt);
		l=read();r=read();k=read();
		if(*opt=='M'){
			if(bel[l]==bel[r]){//如果同属一个块就暴力 
				for(int i=l;i<=r;i++){
					a[i]+=k;
				}
				update(bel[l]);
				continue;
			}
			//对零散块进行暴力处理
			for(int i=l;i<=ed[bel[l]];i++){
				a[i]+=k;
			}
			for(int i=st[bel[r]];i<=r;i++){
				a[i]+=k;
			}
			update(bel[l]);
			update(bel[r]);
			for(int i=bel[l]+1;i<=bel[r]-1;i++){//对整块打标记 
				mark[i]+=k;
			}
		}else{
			int tot=0;
			if(bel[l]==bel[r]){
				for(int i=l;i<=r;i++){
					if(a[i]+mark[bel[l]]>=k){//如果同属一个块就暴力 
						tot++;
					}
				}
				printf("%d\n",tot);
				continue;
			}
			for(int i=l;i<=ed[bel[l]];i++){
				if(a[i]+mark[bel[l]]>=k){
					tot++;
				}
			}
			for(int i=st[bel[r]];i<=r;i++){
				if(a[i]+mark[bel[r]]>=k){
					tot++;
				}
			}
			for(int i=bel[l]+1;i<=bel[r]-1;i++){
				tot+=v[i].end()-lower_bound(v[i].begin(),v[i].end(),k-mark[i]);
			}
			printf("%d\n",tot);
		}
	}
	return 0;
}