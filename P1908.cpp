#include<iostream>
#include<cstdio>
#define N 500005
using namespace std;
int n,a[N],b[N];long long ans;
void mergesort(int l,int r){
	int mid=(l+r)>>1;
	if(l==r)
		return;
	
	mergesort(l,mid);
	mergesort(mid+1,r);
	int i=l,j=mid+1,t=l;
	while(i<=mid && j<=r){
		if(a[i]>a[j]){
			ans+=mid-i+1;
			b[t++]=a[j++];
		}else{
			b[t++]=a[i++];
		}
	}
	while(i<=mid){
		b[t++]=a[i++];
	}
	while(j<=r){
		b[t++]=a[j++];
	}
	for(int k=l;k<=r;k++)
		a[k]=b[k];
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	mergesort(1,n);
//	for(int i=1;i<=n;i++)
//		for(int j=i+1;j<=n;j++)
//			if(a[i]>a[j])
//				ans++;
	cout<<ans;
	return 0;
}
