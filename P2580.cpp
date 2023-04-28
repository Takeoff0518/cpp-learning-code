#include<iostream>
#include<cstdio>
#define N 10005*50
using namespace std;
int son[N][26],cnt[N],idx;
int n,m;
void insert(char str[]){
    int p=0;
    for(int i=0;str[i];i++){
        int u=str[i]-'a';
        if(!son[p][u]){
            son[p][u]=++idx;
        }
        p=son[p][u];
    }
    cnt[p]++;
}
int query(char str[]){
    int p=0;
    for(int i=0;str[i];i++){
        int u=str[i]-'a';
        if(!son[p][u]){
            return 0;
        }else{
            p=son[p][u];//走到下一个结点
        }
    }
    return cnt[p];
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        char str[N];
        scanf("%s",&str);
        insert(str);
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        char str[N];
        scanf("%s",&str);
        int t=query(str);
        if(t==0){
            puts("WRONG");
        }else if(t==1){
            puts("OK");
            insert(str);
        }else{
            puts("REPEAT");
        }
    }
//    cout<<"  ";
//    for(int i='a';i<='z';i++){
//    	cout<<(char)i<<' ';
//	} 
//	cout<<endl;
//    for(int i=0;i<=10;i++){
//    	cout<<i<<":";
//    	for(int j=0;j<26;j++){
//    		cout<<son[i][j]<<' ';
//		}
//		cout<<endl;
//	}
    return 0;
}
