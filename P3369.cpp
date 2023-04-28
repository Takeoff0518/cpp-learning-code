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
typedef tree<int,null_type,greater<int>,rb_tree_tag,tree_order_statistics_node_update> Tree;
Tree x;
int n;
int getval(int k){//查询排名为k的数的值 
	Tree::iterator it=x.find_by_order(k-1);
	if(it!=x.end()) return *it;
	else return -1; 
}

int main(){

    return 0;
}
//F**k CCF!!!!!

