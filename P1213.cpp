#include<iostream>
#include<cstdio>
#include<cstring>
#define N 10005
using namespace std;
int ans[N],a[100];
int main(){
    for(int i=1;i<=9;i++){
        cin>>a[i];
        a[i]/=3;
    }
    for(int i=0;i<=3;i++){
        for(int j=0;j<=3;j++){
            for(int k=0;k<=3;k++){
                for(int l=0;l<=3;l++){
                    for(int m=0;m<=3;m++){
                        for(int n=0;n<=3;n++){
                            for(int o=0;o<=3;o++){
                                for(int p=0;p<=3;p++){
                                    for(int q=0;q<=3;q++){
                                        if((i+j+l)%4==(4-a[1])%4
                                        && (i+j+k+m)%4==(4-a[2])%4
                                        && (j+k+n)%4==(4-a[3])%4
                                        && (i+l+m+o)%4==(4-a[4])%4
                                        && (i+k+m+o+q)%4==(4-a[5])%4
                                        && (k+m+n+q)%4==(4-a[6])%4
                                        && (l+o+p)%4==(4-a[7])%4
                                        && (m+o+p+q)%4==(4-a[8])%4
                                        && (n+p+q)%4==(4-a[9])%4){
                                            ans[1]=i;
                                            ans[2]=j;
                                            ans[3]=k;
                                            ans[4]=l;
                                            ans[5]=m;
                                            ans[6]=n;
                                            ans[7]=o;
                                            ans[8]=p;
                                            ans[9]=q;
                                            for(int i=1;i<=9;i++){
                                                if(ans[i]){
                                                    for(int j=1;j<=ans[i];j++){
                                                        cout<<i<<' ';
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}