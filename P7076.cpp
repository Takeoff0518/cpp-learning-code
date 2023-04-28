#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=1e6+5,M=1e6+5;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,m,c,k,_0x0005;
int vis[N],d[N];
inline bool check(int x,int k){
    return (x>>k)&1;
}
int main(){
    scanf("%d %d %d %d",&n,&m,&c,&k);
    for(int i=1;i<=n;i++){
    	unsigned ll a;
        cin>>a;
        for(int j=k-1;j>=0;j--){
        	vis[j]|=(a<<j)&1;
		}
    }
    for(int i=1,p,q;i<=m;i++){
        scanf("%d %d",&p,&q);
        if(!vis[p]){
        	d[p]=1;
		}
    }
    for(int i=0;i<k;i++){
    	if(d[i]){
    		_0x0005++;
		}
	}
	if(k-_0x0005==64){
		if(n){
			cout<<(unsigned ll)(-n)<<endl;
		}else{
			cout<<"18446744073709551616"<<endl;
		}
	}else{
		cout<<(1ull<<(k-_0x0005))-n<<endl;
	}
    
    return 0;
}
