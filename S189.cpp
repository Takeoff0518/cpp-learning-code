#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<map>
#define N (200005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define P(xxx,yyy) make_pair(xxx,yyy)
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
const int dx[4]={0,0,-1,1};
const int dy[4]={1,-1,0,0};
//               U  D L R
char s[N];
ll k,ans;
int n,opt[N];
map<PII,bool> mp;
bool e1=1,e2=1,e3=1,e4=1;
int cnt_U,cnt_D,cnt_L,cnt_R;
void solve1(){
//	if(e1){
//		ans=cnt_L*k+1;
//		return;
//	}
	int lans=0;
	int sme=1;
	int x=0,y=0;
	mp[P(0,0)]=1,ans=1;
	while(k--){
		int tmpans=0;
//		printf("round:%d\n",k);
		for(int i=1;i<=n;i++){
			x=x+dx[opt[i]],y=y+dy[opt[i]];
			PII now=P(x,y);
//			printf("goto:(%d,%d),val=%d\n",x,y,!mp[now]);
			if(mp[now]==0){
				mp[now]=1;
				tmpans++;
			}
		}
		//cout<<tmpans<<endl;
		if(tmpans!=lans){
			lans=tmpans;
			ans+=tmpans;
			sme=1;
		}else{
//			ans+=tmpans*k;
//			return;
			if(sme==3){
				ans+=tmpans*(k+1);
				return;
			}else{
				sme++;
				ans+=tmpans;
				lans=tmpans;
			}
		}
	}
}
//void solve(){
//	
//}
int main(){
//	freopen("ex_a4.in","r",stdin);
//	freopen("ex_a4.out","w",stdout);
	cin>>(s+1);
	cin>>k;
	n=strlen(s+1);
//	cout<<n<<endl;
	for(int i=1;i<=n;i++){
		switch(s[i]){
			case 'U': opt[i]=0,cnt_U++; break;
			case 'D': opt[i]=1,cnt_D++; break;
			case 'L': opt[i]=2,cnt_L++; break;
			case 'R': opt[i]=3,cnt_R++; break;
		}
		if(s[i]!='L' && s[i]!='R') e1=0;
		
	}
//	if(cnt_U!=cnt_D ||cnt_U!=cnt_L || cnt_U!=cnt_R 
//	|| cnt_D!=cnt_L || cnt_D!=cnt_R 
//	|| cnt_L!=cnt_R) e3=0;
	solve1();
	printf("%lld\n",ans); 
    return 0;
}
//F**k CCF!!!!!

