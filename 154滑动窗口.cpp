#include<iostream>
#include<cstring>
#include<cstdio>
#define N 1000005
using namespace std;
int n,n;
int a[N],q[N];
int front,rear;
int main(){
    scanf("%d %d",&n,&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    front=0,rear=-1;
    for(int i=0;i<n;i++){
        if(front<=rear && i-n+1>q[front]){
            front++;
        }
        while(front<=rear && a[q[rear]]>=a[i]){
            rear--;
        }
        q[++rear]=i;
        if(i>=n-1){
            printf("%d ",a[q[front]]);
        }
        
    }
    puts("");
    front=0,rear=-1;
    for(int i=0;i<n;i++){
        if(front<=rear && i-n+1>q[front]){
            front++;
        }
        while(front<=rear && a[q[rear]]<=a[i]){
            rear--;
        }
        q[++rear]=i;
        if(i>=n-1){
            printf("%d ",a[q[front]]);
        }
        
    }
    return 0;
}