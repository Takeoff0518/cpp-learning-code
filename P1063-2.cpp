#include<iostream>
#include<cstdio>
#define NUM 210
#define FOR(a,b,c) for( int a = b;a <= c;a++ )
using namespace std;

int n;
int m;
int a[NUM];
long long dp[NUM][NUM];

long long dfs( int l,int r ){
	if( l == r ) return 0;
	if( r-l == 1 ){
//		printf( "l = %d,r = %d,dp[l][r] = %d\n",l,r,a[l]*a[r]*a[(r%n)+1] );
		return dp[l][r] = a[l]*a[r]*a[(r%n)+1];
	} 
	if( dp[l][r] ){
//		printf( "l = %d,r = %d,dp[l][r] = %d\n",l,r,dp[l][r] );
		return dp[l][r];
	} 
	
	long long qian = dfs( l+1,r ),hou = dfs( l,r-1 );
	if( qian > hou ){
		dp[l][r] = a[l] * qian;
	}else{
		dp[l][r] = hou * a[(r%n)+1];
	}
//	printf( "l = %d,r = %d,dp[l][r] = %d -> qian = %d,hou = %d\n",l,r,dp[l][r],qian,hou );
	return dp[l][r];
	
}

int main(){
	
	cin >> n;
	m = n<<1;
	FOR( i,1,n ){
		cin >> a[i];
		a[i+n] = a[i];
	}
	//定义dp[NUM][NUM]为从第i个到第j个珠子可以搞出来的最大能量
	//可以往前也可以往后
	
	long long ans = 0;
//	cout << endl << endl;
	FOR( i,1,n ){
		ans = max( dfs(i,i+n-1),ans );
//		printf( "_________ans = %d,dfs = %d\n",ans,dfs(i,i+n-1) );
	}
//	cout << dfs( 1,n );
//	cout << endl;
//	FOR( i,1,n ){
//		FOR( j,i+1,n ){
//			printf( "i = %d,j = %d,dp[i][j] = %d\n",i,j,dp[i][j] );
//		}
//	}

//	cout << endl;
	cout << ans;
	
	return 0;
}





