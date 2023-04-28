#pragma GCC optimize(2) 
#include<iostream>
#define INF 0x3f3f3f3f
#define ll long long
#define N 10005
#define M 10005
using namespace std;
int n,a[N];
void qsort(int l,int r){
	if(l>=r){
		return;
	}
	int x=a[l+r>>1];
	int i=l-1,j=r+1;
	while(i<j){
		do{
			i++;
		}while(a[i]<x);
		do{
			j--;
		}while(a[j]>x);
		if(i<j){
			swap(a[i],a[j]);
		}
	}
	qsort(l,j);
	qsort(j+1,r);
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	qsort(1,n);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}
	return 0;
}

