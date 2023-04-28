// luogu-judger-enable-o2
#include <iostream>
#include <cstdio>
#include <cctype>

using namespace std;

int L;

double ans=0.0000;

string str;

pair <string,double> score[]=
{
    make_pair("H",1),
    make_pair("C",12),
    make_pair("N",14),
    make_pair("O",16),
    make_pair("F",19),
    make_pair("Na",23),
    make_pair("Mg",24),
    make_pair("Al",27),
    make_pair("Si",28),
    make_pair("P",31),
    make_pair("S",32),
    make_pair("Cl",35.5),
    make_pair("K",39),
    make_pair("Ca",40),
    make_pair("Mn",55),
    make_pair("Fe",56),
    make_pair("Cu",64),
    make_pair("Zn",65),
    make_pair("Ag",108),
    make_pair("I",127),
    make_pair("Ba",137),
    make_pair("Hf",178.5),
    make_pair("Pt",195),
    make_pair("Au",197),
    make_pair("Hg",201),
};

void Solve_H2O()
{
    int pos=str.find('~');
    if (pos!=-1)
    {
        int tot=0;
        for (int i=pos+1;isdigit(str[i]);i++)
            tot=tot*10+str[i]-48;
        if (tot==0)
            tot=1;
        ans=ans+tot*1.0*18;
        str.erase(pos,100);
    }
}

double getmass(string s)
{
    for (int i=0;;i++)
        if (s==score[i].first)
            return score[i].second;
}

double solve(int x)
{
    double now=0,sum=0;
    while (str[x]!=')')
    {
        //cout << x << " " << str[x] << endl;
        if (str[x]>='A' && str[x]<='Z')
        {
            sum+=now;
            now=0;
            if (str[x+1]>='a' && str[x+1]<='z')
            {
                now=getmass(str.substr(x,2));
                x=x+2;
            }
            else
            {
                now=getmass(str.substr(x,1));
                x++;
            }
        }
        else if (str[x]=='(')
        {
            sum+=now;
            now=0;
            int layer=1;
            int y=x+1;
            while (layer)
            {
                if (str[y]=='(')
                    layer++;
                if (str[y]==')')
                    layer--;
                y++;
            }
            now=solve(x+1);
            x=y;
        }
        else if (str[x]=='_')
        {
            x=x+2;
            int c=0;
            while (isdigit(str[x]))
                c=c*10+str[x++]-48;
            now*=c;
            x++;
        }
    }
    return sum+now;
}

int main()
{
    cin >> str;
    Solve_H2O();
    str+=')';
    cout << ans+solve(0) << endl;
    return 0;
}
