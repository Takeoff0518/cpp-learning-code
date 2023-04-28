#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<map> 
#define ll long long
const int N=25,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,_0x0005;
map<string,int> mp;
string mp2[N];
struct trie{
	int son[N][10],cnt[N],idx;
	trie(){
		memset(son,-1,sizeof(son));
		memset(cnt,-1,sizeof(cnt));
		idx=0;
	}
}t[N];
void ins(int idx,char str[]){
	int p=0;
	for(int i=strlen(str)-1;i>=0;i--){
		int u=str[i]-'0';
		if(t[idx].son[p][u]==-1)
			t[idx].son[p][u]=++t[idx].idx;
		p=t[idx].son[p][u];
	}
	t[idx].cnt[p]++;
}
void dfs(int idx,int p){
	bool f=0;
	for(int i=0;i<10;i++){
		if(t[idx].son[p][i]!=-1){
			f=1;
			printf("%d",i);
			dfs(idx,t[idx].son[p][i]);
		}
	}
	if(f) printf(" ");
}
void debug(int idx){
//	cout<<"  ";
//	for(int i=0;i<10;i++){
//		cout<<i<<' ';
//	}
//	cout<<endl;
	for(int i=1;i<=t[idx].idx;i++){
		cout<<i<<":";
		for(int j=0;j<10;j++){
			cout<<t[idx].son[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		string name;
		cin>>name;
		if(mp[name]==0){
			mp[name]=++_0x0005;
			mp2[_0x0005]=name;
		}
		int t;
		cin>>t;
		for(int j=1;j<=t;j++){
			char number[25];
			cin>>number;
			ins(mp[name],number);
		}
	}
	for(int i=1;i<=_0x0005;i++){
		debug(i);
	}
	for(int i=1;i<=_0x0005;i++){
		cout<<mp2[i]<<' ';
		dfs(i,0);
		puts("");
	}
    return 0;
}

