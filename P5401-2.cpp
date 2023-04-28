#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
char str[1000002];
int strto[1000002];
int ans[1000002];
int t[1000002];
bool vis[1000002];
vector<int>pos[100000]; 
int snum=0;
int spos;
unsigned long long tot=0;
void solve(int l,int r){
	if(l==r)
	    return;
	int mid=(l+r)/2;
	solve(l,mid);
	solve(mid+1,r);
	int i=l;
	int k=l;
	int j=mid+1;
	while(i<=mid && j<=r){
		if(ans[i]<=ans[j]){
			t[k]=ans[i];
			k++;
			i++;
		}
		else{
			t[k]=ans[j];
			k++;
			j++;
			tot+=mid-i+1;
		}
	}
	while(i<=mid){
		t[k]=ans[i];
		i++;
		k++;
	} 
	while(j<=r){
		t[k]=ans[j];
		k++;
		j++;
	}
	for(int i=l;i<=r;i++){
		ans[i]=t[i];
	}
}
int main(){
	scanf("%s",str+1);
	memset(vis,true,sizeof(vis));
	int len=strlen(str+1);
	for(int i=1;i<=len;i++){
		strto[i]=str[i]-'A'+1;
		pos[strto[i]].push_back(i);
	}
	for(int i=1;i<=26;i++){
		if(pos[i].size()%2==1){
			snum++;
			if(snum>1){
		        putchar('-');
		        putchar('1');
		        return 0;
		    }
			spos=pos[i][pos[i].size()/2];
			vis[spos]=false;
			ans[len/2+1]=spos; 
		}
	}
    int s=1;
    int l=1;
    int r=len;
    while(s<=len && l<=r){ 
    	if(!vis[s]){
    		s++;
    		continue;
		}
		ans[l]=s;
		vis[s]=false;
		l++;
		ans[r]=pos[strto[s]][pos[strto[s]].size()-1];
		vis[ans[r]]=false; 
		pos[strto[s]].erase(pos[strto[s]].end()-1);
		r--;
		s++;
	}
	solve(1,len);
	printf("%llu",tot);
	return 0;
} 