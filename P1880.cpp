#include<iostream>
#define N 102
#define INF 0x3f3f3f3f
using namespace std;
int fmax[2*N][2*N],fmin[2*N][2*N];
int main(){
	int n,a[2*N],qz[2*N]={0};
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i+n]=a[i];
	}
	for(int i=1;i<=2*n;i++)
		qz[i]=qz[i-1]+a[i];
	for(int len=2;len<=n;len++){
		for(int i=1;i<=2*n-len+1;i++){
			int j=i-1+len;
			fmin[i][j]=INF;
			for(int k=i;k<j;k++){
				fmax[i][j]=max(fmax[i][j],fmax[i][k]+fmax[k+1][j]+qz[j]-qz[i-1]);
				fmin[i][j]=min(fmin[i][j],fmin[i][k]+fmin[k+1][j]+qz[j]-qz[i-1]);
			}
		}
	}
	int maxx=0,minn=INF;
	for(int i=1;i<=n;i++){//枚举左端点 
		maxx=max(maxx,fmax[i][i+n-1]);
		minn=min(minn,fmin[i][i+n-1]); 
	}
	cout<<minn<<endl<<maxx;
	return 0;
} 