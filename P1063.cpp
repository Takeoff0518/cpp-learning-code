#include<iostream>
#define N 202
using namespace std;
int f[N][N],a[N],n; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){ 
		cin>>a[i];
		a[i+n]=a[i];
	} 
	for(int len=1;len<=n+1;len++){
		for(int i=1;i+len-1<=2*n;i++){
			int j=i+len-1;
			for(int k=i+1;k<j;k++){
				f[i][j]=max(f[i][j],f[i][k]+f[k][j]+a[i]*a[j]*a[k]);
			} 
		} 
	}
	int maxx=-0x3f3f3f3f;
	for(int i=1;i<=n;i++)
		maxx=max(maxx,f[i][i+n]);
	cout<<maxx<<endl; 
	return 0;
}