#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define int ll 
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int t,id;
int n,m,c,f;
bool g[N][N];
int p[N][N];
#define len first
#define idx second 
inline PII ccnt(int &st,int &ed,vector<PII> &rec){
//	printf("goto: st=%d, ed=%d\n",st,ed);
//	printf("len: ");
//	for(auto it=rec.begin();it!=rec.end();it++){
//		printf("%d ",(*it).first);
//	}
//	printf("\nidx:");
//	for(auto it=rec.begin();it!=rec.end();it++){
//		printf("%d ",(*it).second);
//	}
//	puts("");
	//̫��ֱ�ӷ��� 
	if(rec.size()<=1) return {0,0};
	int pre=0;
	int cnt_c=0,cnt_f=0;
	//��¼ǰ׺�� 
	pre=rec.front().len;
	for(auto it=rec.begin()+1;it!=rec.end();it++){
		auto before=it-1;
		int tpre=pre;
		//�տ�һ�У�����һ�еĻ�������һ�� 
		if((*it).idx-(*before).idx<=1){
			tpre-=(*before).len;
		}
		//ͳ��
		cnt_c+=tpre*(*it).len;
		cnt_f+=tpre*(*it).len*(ed-(*it).idx);
		cnt_c%=mod,cnt_f%=mod;
		pre+=(*it).len;
	}
//	printf("ans_c+=%d, ans_f+=%d\n",cnt_c,cnt_f);
	return {cnt_c,cnt_f};
}
inline void solve(){
	int ans_c=0,ans_f=0;
	scanf("%lld %lld %lld %lld",&n,&m,&c,&f);
	for(int i=1;i<=n;i++){
		char s[N];
		scanf("%s",s+1);
		for(int j=1;j<=m;j++){
			if(s[j]=='1') g[i][j]=1;
			else g[i][j]=0;
		}
	}
	//����ǰ׺������
	/*
		001 210
		010 101
		000 321
		000 321
	*/
	memset(p,0,sizeof(p));
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if(!g[i][j]) p[i][j]=p[i][j+1]+1;
		}
	}
	int st=0,ed=0;
	vector<PII> rec;
	/*first:���ȣ�ǰ׺��-1��
	 second:λ�ã�����λ�ã�*/
	 /*
		001 210
		010 101
		000 321
		000 321
		first  1 2 2
		second 1 3 4
	*/
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
//			printf("bl: (%d,%d)\n",i,j);
			//û���ϰ� 
			if(!g[i][j]){
				//������ù�����ʼ���죨ע���һ��ҲҪ��¼�� 
				//��������죬�ͼ�������+��¼ 
				//��¼>1�������Ժ�������� 
				if(!st){
					st=i;
				}
				if(p[i][j]>1){
					rec.push_back({p[i][j]-1,i});
				}
			//���ϰ�������ڼ�¼������Ȼ������
			//�������ܵ���β��
			}
			if((g[i][j] && st) || i==n){ 
				//������βʱ����¼���һ��0������
				//���һ�����ϰ�ʱ��Ҫ-1 
				if(i==n && !g[i][j]) ed=i;
				//�����ϰ�ʱ����¼��һ��1����һλ���ǵ�-1 
				else ed=i-1;
				PII tans=ccnt(st,ed,rec);
				ans_c+=tans.first;
				ans_f+=tans.second;
				ans_c%=mod,ans_f%=mod; 
				rec.clear();
				st=ed=0;
			}
		}
	}
	printf("%lld %lld\n",c*ans_c%mod,f*ans_f%mod);
}
signed main(){
//	freopen("plant15.in","r",stdin);
//	freopen("p/lant15.out","w",stdout);
	scanf("%lld %lld",&t,&id);
	while(t--) solve(); 
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808 
*/
