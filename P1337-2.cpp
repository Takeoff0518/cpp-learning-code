#include <bits/stdc++.h>
#define down 0.996//���콵�� 

using namespace std;

int n;
struct node{
int x;
int y;
int w;
}object[2005];//������������� 
double ansx,ansy,answ;//���մ� 
double energy(double x,double y)//��������ѧ֪ʶ,�����ܺ�ԽСԽ�ȶ� 
{
   double r=0,dx,dy;
   for (int a=1;a<=n;a++)
   {
      dx=x-object[a].x;
      dy=y-object[a].y;
      r+=sqrt(dx*dx+dy*dy)*object[a].w;
   }
      return r;
}
void sa()//ģ���˻� 
{
   double t=3000;//�¶�Ҫ�㹻�� 
   while (t>1e-15)//�Դ���0 
   {
      double ex=ansx+(rand()*2-RAND_MAX)*t;//��������µĴ� 
      double ey=ansy+(rand()*2-RAND_MAX)*t;
      double ew=energy(ex,ey);
      double de=ew-answ;
      if (de<0)//����˴𰸸��ţ��ͽ��� 
      {
         ansx=ex;
         ansy=ey;
         answ=ew;
      }
      else if(exp(-de/t)*RAND_MAX>rand())//������ݶ���ʽ���ʽ��� 
      {
         ansx=ex;
         ansy=ey;
      }
      t*=down;
   }
}
void solve()//���ܼ����˻�,���ӵõ����Ž�ĸ��� 
{
   sa();
   sa();
   sa();
   sa();
}
int main() {
cin>>n;
for (int a=1;a<=n;a++)
{
   scanf("%d%d%d",&object[a].x,&object[a].y,&object[a].w);
   ansx+=object[a].x;
   ansy+=object[a].y;
}
ansx/=n;//��ƽ������Ϊ��ʼ�� 
ansy/=n;
answ=energy(ansx,ansy);
solve();
printf("%.3lf %.3lf\n",ansx,ansy);//��������� 
    return 0;
}

