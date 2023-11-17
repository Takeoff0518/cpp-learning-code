#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
ll MAX( ll a, ll b ){
	return a > b ? a : b;
}

ll MIN( ll a, ll b ){
	return a < b ? b : a;
}

inline ll read(){
	ll num = 0;
	ll x = 1;
	char ch = getchar();
	while( !isdigit(ch) ){
		if( ch == '-' )
			x = -1;
		ch = getchar();
	}
	while( isdigit(ch) ){
		num = num * 10 + ch - '0';
		ch = getchar();
	}
	return num * x;
}
struct edge{
	int v,w;
};
vector<edge> e[20005];
int n,m;
ll dis[20005];
int cnt[20005];
bool vis[20005];

bool SPFA(){
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	cnt[1] = 1;
	while( !q.empty() ){
		int x = q.front();
			q.pop();
			if( dis[x] == inf ) continue;
			for( auto ed : e[x] ){
				int y = ed.v;
				int w = ed.w;
				if( dis[y] > dis[x] + w ){
					dis[y] = dis[x] + w;
					if( !vis[y] ){
						q.push( y );
						vis[y] = 1;
						cnt[y]++;
						if( cnt[y] >= n )
							return false;
					}
				}
			}
		}
		
}

int main(){

	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);

	int T;
	cin >> T;
	while( T-- ){

		cin >> n >> m;
		for( int i = 1; i <= m; i++ ){
			int u,v,w;
			cin >> u >> v >> w;
			e[u].push_back({v,w});
			if( w < 0 ) continue;
			e[v].push_back({u,w});
		}

		for( int i = 1; i <= n; i++ )
			dis[i] = inf;
		dis[1] = 0;

		if( SPFA() )
			cout << "NO" << endl;
		else
			cout << "YES" << endl;

		for( int i = 1; i <= n; i++ )
			e[i].clear();

		for( int i = 1; i <= n; i++ )
			vis[i] = 0;
	}



	return 0;
}


