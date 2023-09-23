#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int main(){
    
    return 0;
}
/*
这里有一个 3×3 的方格，每个方格中有 1 到 9 的数字，范围包括 1 和 9。位于从顶部数第 i 行和从左数第 j 列（1≤i≤3,1≤j≤3）的方格包含数字 c_i,j。

同一个数字可能会出现在不同的方格中，但不能连续出现在垂直、水平或对角线上的三个方格中。更具体地说，保证 c_i,j 满足以下所有条件：

1. 不满足 c_i,1 = c_i,2 = c_i,3，对于任何 1≤i≤3。
2. 不满足 c_1,j = c_2,j = c_3,j，对于任何 1≤j≤3。
3. 不满足 c_1,1 = c_2,2 = c_3,3。
4. 不满足 c_3,1 = c_2,2 = c_1,3。

Takahashi 会以随机顺序看到每个方格中的数字。只有当存在一条线（垂直、水平或对角线），满足以下条件时，他会感到失望：

他看到的前两个方格包含相同的数字，但最后一个方格包含不同的数字。

找出 Takahashi 在看到所有方格中的数字而不感到失望的概率。

这个问题的解决方案可能需要一些概率论知识和计算。你可以使用组合和排列的概念来计算不失望的情况，然后除以总的排列数来得到概率。不失望的情况包括不满足上述条件的排列。你可以编写程序来模拟这个问题并计算概率，或者使用数学方法来解决它。
*/