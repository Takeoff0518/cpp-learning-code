#include <iostream>
#include<string>
using namespace std;
int a[2005][2005],tmpj;
int f[2005][2005],ans=0x3f3f3f3f;
int main(){
//	ios::sync_with_stdio(false);	
    int n,maxn,minn;
    cin>>n;
    maxn=n*(n+1)/2;
    minn=1;
    for(int i=1;i<=n;i++){
    	tmpj=0;
        if(i<=2){
            for(int j=1;j<=i;j++){
//                cout<<maxn<<" ";
                a[i][++tmpj]=maxn;
                maxn--;
            }
//            cout<<endl;
        }else if(i>=3&&i<=n/2+1){
            if(i%2==1){
//                cout<<maxn-1<<" ";
                a[i][++tmpj]=maxn-1;
                maxn++;
                for(int j=2;j<=i-1;j++){
//                    cout<<minn<<" ";
                    a[i][++tmpj]=minn;
                    minn++;
                }
//                cout<<maxn<<endl;
                a[i][++tmpj]=maxn;
            }else{
//                cout<<maxn-1<<" ";
                a[i][++tmpj]=maxn-1;
                maxn--;
                for(int j=2;j<=i-1;j++){
//                    cout<<minn<<" ";
                    a[i][++tmpj]=minn;
                    minn++;
                }
//                cout<<maxn<<endl;
                a[i][++tmpj]=maxn;
            }
        }else if(i<=n-1){
            for(int j=1;j<=i-(n/2+1)+1;j++){
//                cout<<maxn<<" ";
                a[i][++tmpj]=maxn;
                maxn--;
            }
            for(int j=1;j<=n-i;j++){
//                cout<<minn<<" ";
                a[i][++tmpj]=minn;
                minn++;
            }
            for(int j=1;j<=i-(n/2+1)+1;j++){
//                cout<<maxn<<" ";
                a[i][++tmpj]=maxn;
                maxn--;
            }
//            cout<<endl;
        }else{
            for(int j=1;j<=n;j++){
//                cout<<maxn<<" ";
                a[i][++tmpj]=maxn;
                maxn--;
            }
        }
    }
//    cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			f[i][j]=max(f[i-1][j],f[i-1][j-1])+a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		ans=min(ans,f[n][i]);
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			printf("%d ",a[i][j]);
		}
		puts("");
	}
}

