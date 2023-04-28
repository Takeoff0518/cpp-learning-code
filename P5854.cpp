#include<iostream>
#include<cstdio>
#define N 10000005
#define ll long long
using namespace std;
int n,fa[N],ls[N],rs[N],st[N],top;
int a[N];
ll l,r;
int read(){
    char ch=getchar();
    int x=0,f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void build(int n){
    for(int i=1;i<=n;i++){
        int k=top;
        while(k && a[st[k]]>a[i]){
            k--;
        }
        if(k){
            rs[st[k]]=i;
        }
        if(k<top){
            ls[i]=st[k+1];
        }
        st[++k]=i;
        top=k;
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    build(n);
    for(int i=1;i<=n;i++){
        l^=1ll*i*(ls[i]+1),r^=1ll*i*(rs[i]+1);
    }
    printf("%lld %lld",l,r);
    return 0;
}