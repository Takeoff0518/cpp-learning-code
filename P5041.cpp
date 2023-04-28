#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector> 
#define ll long long
const int N=1000005,M=100005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
char str[N];
int strto[N],ans[N],t[N];
bool vis[N];
vector<int> pos[M];
int snum,spos;
ll cnt=0;
void merge_sort(int l,int r){
	int mid=(l+r)>>1;
	if(l==r) return;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	int i=l,j=mid+1,k=l;
	while(i<=mid && j<=r){
		if(ans[i]>ans[j]){
			cnt+=mid-i+1;
			t[k++]=ans[j++];
		}else
			t[k++]=ans[i++];
	}
	while(i<=mid) t[k++]=ans[i++];
	while(j<=r) t[k++]=ans[j++];
	for(int i=l;i<=r;i++) ans[i]=t[i];
} 
int main(){
	cin>>str+1;
	memset(vis,1,sizeof(vis));
	int len=strlen(str+1);
	for(int i=1;i<=len;i++){
		strto[i]=str[i]-'A'+1;
		pos[strto[i]].push_back(i);
	}
	for(int i=1;i<=26;i++){
		if(pos[i].size()%2==1){
			snum++;
			if(snum>1){
				puts("-1");
				return 0;
			}
			spos=pos[i][pos[i].size()/2];
			vis[spos]=0;
			ans[len/2+1]=spos;
		}
	}
	int s=1,l=1,r=len;
	while(s<=len && l<=r){
		if(!vis[s]){
			s++;
			continue;
		}
		ans[l]=s,vis[s]=0;
		l++;
		ans[r]=pos[strto[s]][pos[strto[s]].size()-1];
		vis[ans[r]]=0;
		pos[strto[s]].erase(pos[strto[s]].end()-1);
		r--,s++;
	}
	merge_sort(1,len);
	cout<<cnt<<endl;
    return 0;
}
//F**k CCF!!!!!

