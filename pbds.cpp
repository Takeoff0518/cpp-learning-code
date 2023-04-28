#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define N (1005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Tree;
Tree x;
int getval(int k){
	Tree::iterator it=x.find_by_order(k-1);
	if(it!=x.end())
		return *it;
	else
		return INF;
}
int getord(int k){
	return x.order_of_key(k)+1; 
}
int main(){
	while(1){
		string opt;
		int t;
		cin>>opt>>t;
		if(opt=="1") x.insert(t);
		else if(opt=="2") cout<<getval(t)<<endl;
		else if(opt=="3") cout<<getord(t)<<endl;
	}
    return 0;
}
//F**k CCF!!!!!

