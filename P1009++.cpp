#include<iostream>
#include<cstring>
#include<algorithm>
#define MAXN 5000
using namespace std;
struct bigInt {
	int len, a[MAXN];
	bigInt(int x=0) {              //构造函数，默认时为零
		memset(a, 0, sizeof(a));
		for (len = 1; x; len++)
			a[len] += x % 10, x /= 10;
		len--;
	}
	int &operator[](int i) {
		return a[i];
	}
	void flatten(int L) {		//处理进位
		len = L;
		for (int i = 1; i < len; i++)
			a[len + 1] += a[len] / 10, a[len] %= 10;
		for (; !a[len];)
			len--;
	}
	void print() {
		for (int i = max(1,len); i >= 1; i--)
			cout << a[i];
	}
};
bigInt &operator +(bigInt a, bigInt b) {    //高精加高精
	bigInt c;
	int len = max(a.len, b.len);
	for (int i = 1; i <= len; i++)
		c[i] = a[i] + b[i];
	c.flatten(len+1);
	return c;
}

bigInt& operator*(bigInt a, int b) {		//高精乘低精
	bigInt c;
	int len=a.len;
	for (int i = 1; i <= len; i++)
		c[i] = a[i] *b;
	c.flatten(len + 10);					//int 最多10位（long long 最多19位）
	return c;
}
int main() {
	bigInt ans(0), fac(1);					//ans是阶乘之和，fac是阶乘
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		fac = fac * i;
	    ans = ans+fac;
    }
	ans.print();
	return 0;
}