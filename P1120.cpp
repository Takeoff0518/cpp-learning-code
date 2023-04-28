#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,m,a[N],nxt[N],_0x0005,al,ar,ans=INF;
bool flag=0,vis[N];
void dfs(int len,int x,int last,int rest){
//	if(x==cnt+1){
//		flag=true;
//		return;
//	}
	if(rest==0){
		if(x==m){
			flag=1;
			return;
		}
		for(int i=1;i<=_0x0005;i++){
			if(!vis[i]){
				vis[i]=1;
				dfs(len,x+1,i,len-a[i]);
				vis[i]=0;
				if(flag) return;
				break;
			}
		}
	}
	int l=last+1,r=_0x0005,mid;
	while(l<r){
		mid=l+r>>1;
		if(a[mid]<=rest){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	for(int i=l;i<=_0x0005;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(len,x,i,rest-a[i]);
			vis[i]=0;
			if(flag){
				return;
			}
			if(rest==a[i] || rest==len){
				return;
			}
			i=nxt[i];
			if(i==_0x0005){
				return;
			}
		}
	}
}
inline bool cmp(int x,int y){
	return x>y;
} 
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	int tmp;
    	scanf("%d",&tmp);
    	if(tmp<=50){
    		a[++_0x0005]=tmp;
    		ar+=tmp;
		}
	}
	sort(a+1,a+_0x0005+1,cmp);
	al=a[1];
	nxt[_0x0005]=_0x0005;
	for(int i=_0x0005-1;i>=1;i--){
		if(a[i]==a[i+1]){
			nxt[i]=nxt[i+1];
		}else{
			nxt[i]=i;
		}
	}
	for(int i=al;i<=ar/2;i++){
		if(ar%i==0){
			flag=0;
			m=ar/i;
			vis[1]=1;
			dfs(i,1,1,i-a[1]);
			vis[1]=0;
			if(flag){
				printf("%d\n",i);
				return 0;
			}
		}
	}
	printf("%d\n",ar); 
    return 0;
}
