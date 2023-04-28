#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#define ll long long
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,x,y;
int a[N];
bool f=0;
void dfs(int k,int xx,int yy){
	//printf("->%d:(%d,%d)\n",k,xx,yy);
	
	if(k==k+2){
		if(xx==x && yy==y){
			//f=1;
			puts("Yes");
			exit(0);
		}
		return;
	}
	if(k%2==0){
		dfs(k+1,xx+a[k],yy);
		dfs(k+1,xx-a[k],yy);
	}else{
		dfs(k+1,xx,yy+a[k]);
		dfs(k+1,xx,yy-a[k]);	
	}
} 
int main(){
	cin>>n>>x>>y;
	for(int i=2;i<=n+1;i++){
		cin>>a[i];
	}
	dfs(3,a[2],0);
//	int x1=0,y1=0;
//	for(int i=2;i<=n+1;i++){
//		if(i%4==0){
//			x1-=a[i];
//		}else if(i%4==1){
//			y1-=a[i];
//		}else if(i%4==2){
//			x1+=a[i];
//		}else{
//			y1+=a[i];
//		}
//		cout<<x1<<','<<y1<<endl;
//	}
//	//cout<<x1<<' '<<y1<<endl;
//	if(x1==x && y1==y){
//		puts("Yes");
//	}else{
//		puts("No");
//	}
	puts("No");
    return 0;
}

