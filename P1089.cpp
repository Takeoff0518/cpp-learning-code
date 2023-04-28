#include<iostream>
#include<cstdio>
#define N 15
using namespace std;
int a[N];
int money_hand=0,money_mom=0,money_cost;
int main(){
    for(int i=1;i<=12;i++){
        cin>>a[i];
    }
    for(int i=1;i<=12;i++){
        money_hand+=300;
        money_hand-=a[i];
        if(money_hand<0){
            printf("-%d",i);
            return 0;
        }
        money_mom+=money_hand/100;
        money_hand=money_hand%100;
    }
    printf("%d",money_mom*120+money_hand);
    return 0;
}