#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1000005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
char s1[N],s2[N];
int n,m;
int nxt[N];
int main(){
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	n=strlen(s1+1),m=strlen(s2+1);
	nxt[0]=-1;
	for(int i=1;i<=m;i++){
		int now=nxt[i-1];
		// ǰ��׺����ͬ��
		while(now!=-1 && s2[now+1]!=s2[i])
			// ��ǰ���� 
			now=nxt[now];
		nxt[i]=now+1;
	}
	int j=0;
	for(int i=1;i<=n;i++){
		// ���ʧ�� ����ô�Ͳ����������ֱ�����Լ���ƥ�� 
		while(j && s2[j+1]!=s1[i]) j=nxt[j];
		// ���ƥ�䣬���������� 
		if(s2[j+1]==s1[i]) j++;
		// ȫ��ƥ�����
		if(j==m){
			printf("%d\n",i-j+1);
			j=nxt[j];
		} 
	}	
	for(int i=1;i<=m;i++)
		printf("%d ",nxt[i]);
    return 0;
}

