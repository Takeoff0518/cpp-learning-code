#include<cstdio>
#include<iostream>
#include<cstring>
#define N 2002
#define mem(_KEY) memset(_KEY,0,sizeof(_KEY))
using namespace std;
int f[N][N];
char a[N],b[N];
inline int Min(int a,int b,int c){
	return min(a,min(b,c));
}
int main(){
	cin>>a>>b;
	//mem(f);
	int k=max(strlen(a),strlen(b));
	for(int i=0;i<=k;i++)
		f[i][0]=f[0][i]=i;
	for(int i=1;i<=strlen(a);i++)
		for(int j=1;j<=strlen(b);j++){
			if(a[i-1]==b[j-1])//²»²Ù×÷ 
				f[i][j]=f[i-1][j-1];
			else
				f[i][j]=Min(f[i-1][j],f[i-1][j-1],f[i][j-1])+1;
		}
	printf("%d\n",f[strlen(a)][strlen(b)]);
	return 0;
}
