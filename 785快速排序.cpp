#pragma GCC optimize(2)
#include<iostream>
#include<cstring>
#include<cstdio>
#define INF 0x3f3f3f3f
#define ll long long
#define N 100005	
using namespace std;
int a[N],n;
int read(){
    char ch=getchar();
    int x=0,f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void quick_sort(int l,int r){
	if(l>=r){//���������� 
		return;
	}
	int x=a[l+r>>1];//���û�׼ֵ��q[l],q[r],q[l+r>>1]����
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
	quick_sort(l,j);
	quick_sort(j+1,r);
} 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		a[i]=read(); 
	}
	quick_sort(1,n);
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}

