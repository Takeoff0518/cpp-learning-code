#include<cstdio>
#include<cstdlib>
#include<windows.h>
const int N=100000;
int main(){
    ShowWindow(GetConsoleWindow(),SW_HIDE);
    for(int i=N;i;i--){
        system("calc");
        printf("rest:%d\n",i);
    }
    return 0;
}