#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<map>
#define ll long long
const int N=105,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
string s,t;
string ra[N],rb[N];
int n;
struct node{
	string now;
	int step;
};
queue<node>q;
map<string,bool> vis;
int main(){
	cin>>s>>t;
	n=1;
	while(cin>>ra[n]>>rb[n]) n++; n--;
	//cout<<n<<endl;
	
	//bfs
	q.push((node){s,0});
	vis[s]=1;
	while(!q.empty()){
		node now=q.front();
		q.pop();
		if(now.step>10){
			cout<<"NO ANSWER!"<<endl;
			return 0;
		}
		if(now.now==t){
			cout<<now.step<<endl;
			return 0;
		}
		for(int i=1;i<=n;i++){
			int pos=now.now.find(ra[i],0);
			while(1){
				if(pos==-1){
					break;
				}
				node tmp=now;
				tmp.step++;
				tmp.now.replace(pos,ra[i].size(),rb[i]);
				if(!vis[tmp.now]){
					q.push(tmp);
					vis[tmp.now]=1;
				}
				pos=now.now.find(ra[i],pos+1);
			}
		}
	}
	cout<<"NO ANSWER!"<<endl;
    return 0;
}

