#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=10005*50,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int son[N][26],cnt[N],idx;
int n,m;
void add(char str[]){
	int p=0;
	for(int i=0;str[i];i++){
		int u=str[i]-'a';
		if(!son[p][u]){
			son[p][u]=++idx;
		}
		p=son[p][u];
	}
}
int query(char str[]){
	int p=0;
	for(int i=0;str[i];i++){
		int u=str[i]-'a';
		if(!son[p][u]){
			return 0;
		}else{
			p=son[p][u];
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		
	}
    return 0;
}
/*
cout<<"  ";
    for(int i='a';i<='z';i++){
    	cout<<(char)i<<' ';
	} 
	cout<<endl;
    for(int i=0;i<=10;i++){
    	cout<<i<<":";
    	for(int j=0;j<26;j++){
    		cout<<son[i][j]<<' ';
		}
		cout<<endl;
	}
*/
//F**k CCF!!!!!

