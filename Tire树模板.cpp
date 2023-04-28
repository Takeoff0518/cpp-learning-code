#include<iostream>
#include<cstdio>
#define N 200005
using namespace std;
int son[N][26],cnt[N],idx;
void insert(char str[]){
    int p=0;
    for(int i=0;str[i];i++){//根节点开始，从前往后遍历
        int u=str[i]-'a';//a~z -> 0~25
        if(!son[p][u]){//如果p这个结点不存在u这个儿子
            son[p][u]=++idx;//创建
        }
        p=son[p][u];//走到下一个结点
    }
    cnt[p]++;//以p结尾的单词个数+1
}
int query(char str[]){
    int p=0;
    for(int i=0;str[i];i++){
        int u=str[i]-'a';
        if(!son[p][u]){//如果p这个结点不存在u这个儿子
            return 0;//返回
        }else{
            p=son[p][u];//走到下一个结点
        }
    }
    return cnt[p];//返回以p结尾的单词个数
}
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        char opt[2],str[N];
        scanf("%s %s",&opt,&str);
        if(opt[0]=='I'){
            insert(str);
        }else{
            printf("%d\n",query(str));
        }
    }
    return 0;
}