#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=55,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n;
char s[N];
int f[N][N];
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++){
        f[i][i]=1;
    }
    for(int len=1;len<n;len++){
        for(int i=1;i+len<=n;i++){
            int j=i+len;
            if(s[i]==s[j]){
                f[i][j]=min(f[i+1][j],f[i][j-1]);
            }else{
                for(int k=i;k<j;k++){
                    f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
                }
            }
            
        }
    }
    printf("%d\n",f[1][n]);
    return 0;
}