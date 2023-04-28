#include<iostream>
#include<cstdio>
#include<cstring>
#define ull unsigned long long
#define ll long long
#define N 10005
using namespace std;
int read(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-')
		f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f; 
}
inline void write(int n){
	if(n==0)
		return;
	write(n/10);
	putchar(n%10+'0');
}
int main(){
	return 0;
}

