#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=100005,logN=18;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,m,a[N],Log[N];
int f[N][logN];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	Log[0]=-1;
	for(int i=1;i<=n;i++){
		f[i][0]=a[i];
		Log[i]=Log[i>>1]+1;
	}
	for(int j=1;j<=logN;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
        }
    }
	for(int i=1;i<=m;i++){
        int x,y,s;
        scanf("%d %d",&x,&y);
        s=Log[y-x+1];
        printf("%d\n",min(f[x][s],f[y-(1<<s)+1][s]));
    }
    return 0;
}

