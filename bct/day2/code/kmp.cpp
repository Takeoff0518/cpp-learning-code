#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<bitset>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<map>

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=1e6+5;
int n,m,next[N];
char s1[N],s2[N];

int main()
{
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	n=strlen(s1+1);
	m=strlen(s2+1);
    next[0]=-1;
	for(int i=1;i<=m;++i)
	{
		int now=next[i-1];
		while(now!=-1&&s2[now+1]!=s2[i])
			now=next[now];
		next[i]=now+1;
	}
	int j=0;
	for(int i=1;i<=n;++i)
	{
		while(j&&s2[j+1]!=s1[i])
			j=next[j];
		if(s2[j+1]==s1[i])
			j++;
		if(j==m)
		{
			printf("%d\n",i-j+1);
			j=next[j];
		}
	}
	for(int i=1;i<=m;++i)
		printf("%d ",next[i]);
	return 0;
} 
