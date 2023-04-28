#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<queue>
#define INF 0x3f3f3f3f
#define ll long long
#define N 10005
#define M 10005
using namespace std;
int n,m,len;
map<string,bool> mp;
string s;
struct node{
	string now;
	int step;
};queue<node> q;
inline bool check(string str){
	for(int i=0;i<=len/2;i++){
		if(str[i]!=str[len-i-1])
			return 0;
	}
	return 1;
}
void bf(){
	cin>>s;
    len=s.size();
    q.push((node){s,0});
    mp[s]=1; 
    while(!q.empty()){
    	node now=q.front(); 
    	q.pop();
    	//cout<<"top="<<now.now<<' '<<check(now.now)<<endl;
    	if(check(now.now)){
    		cout<<now.step<<endl;
    		return;
		}
		for(int i=0;i<len-1;i++){
			string tmp=now.now;
			swap(tmp[i],tmp[i+1]);
			if(!mp[tmp]){
				mp[tmp]=1;
				//cout<<tmp<<' '<<now.step+1<<endl;
				q.push((node){tmp,now.step+1});
			}
		}
		//cout<<"---"<<endl;
	}
	cout<<"-1"<<endl;
}
int main(){
    bf();
    return 0;
}
