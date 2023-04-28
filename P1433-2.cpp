#include<stdio.h>
#include<math.h>
int n;
double a[20],b[20],dp[65000][20];
bool vis[20];
double ans=1e9;
double dis(int x,int y){
	sqrt((a[x]-a[y])*(a[x]-a[y])+(b[x]-b[y])*(b[x]-b[y]));//���빫ʽ
}
void dfs(int x,int from,double now,int b){
	if(now>ans) return; //��֦
	if(x==n){
		ans=ans<now?ans:now;
		return;
	}
	for(register int i=1;i<=n;i++){
		if(!vis[i]){
			int p=b+(1<<(i-1));//״ѹ��״̬
			if(dp[p][i]!=0&&dp[p][i]<=now+dis(from,i)) continue;//�ж�����+�Ż�
			vis[i]=1;
			dp[p][i]=now+dis(from,i);
			dfs(x+1,i,dp[p][i],p);
			vis[i]=0;//����
		}
	}
}
main(){
	scanf("%d",&n);
	for(register int i=1;i<=n;i++)
		scanf("%lf%lf",&a[i],&b[i]);
	dfs(0,0,0,0);
	printf("%.2lf\n",ans);
	return 0;
	
}

