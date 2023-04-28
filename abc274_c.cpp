#include<iostream>
#include<cstring>
#include<cstdio>
const int N=800005;
using namespace std;
int n,a[N];
int fa[N],f[N];
int findfa(int x){
	if(x==1) return 0;
	if(f[x]!=-1) return f[x]; //���仯����
	f[x]=1+findfa(fa[x]);
	return f[x];
} 
int main(){
	scanf("%d",&n);
	memset(f,-1,sizeof(f));
	fa[1]=1,f[1]=0; //ע���ʼ��
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		fa[i*2]=a[i],fa[i*2+1]=a[i];
	}
	for(int i=1;i<=2*n+1;i++)
		printf("%d\n",findfa(i));
    return 0;
}
