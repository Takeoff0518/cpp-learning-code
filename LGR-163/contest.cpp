#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,t;
int a[N],b[N],sum;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a[i],&b[i]);
        sum+=(100/a[i])*b[i];
    }
//    cout<<sum<<endl;
    scanf("%d",&t);
    if(sum>=t){
    	printf("Already Au.\n");
    	return 0;
	}
	for(int i=1;i<=n;i++){
		int rest=(100/a[i])*(a[i]-b[i]),
			d=t-sum;
//		printf("I %d %d\n",rest,d);
		if(d>rest){
			printf("NaN\n");
		}else{
			printf("%d\n",(d+100/a[i])/(100/a[i]));
		}
	}
    return 0;
}
