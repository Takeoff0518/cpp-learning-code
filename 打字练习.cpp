
#include<bits/stdc++.h>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#define KEY_DOWN(VK_NONAME)((GetAsyncKeyState(VK_NONAME)&0x8000)?1:0)
using namespace std;
int to(float a) {if(a>0) return int(a+0.5);else if(a<0) return int(-a-0.5);if(a==0) return 0;}
void Setpos(float x,float y){int xx=to(x),yy=to(y);COORD pos;pos.X=yy*2,pos.Y=xx;SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);}
int T9_Color[10]={0,-40,-30,-31,-50,-20,-21,-60,-10,-11};  //2.0 ��ɫ���� 
int U3_Color[10]={0,-1,-70,-71};  //���ϵ��� 
int L8_Color[10]={0,-60,-40,-20,-10,-50,-11,-21,-30};
int B26_Color[30],L26_Color[30],FJ_Color[30]; //Board��������ɫ 
void Slow(char *p) {while(1){if(*p!=0) printf("%c",*p++);else break;if(!kbhit()) Sleep(50);}}
void Slow_F(char *p) {while(1){if(*p!=0) printf("%c",*p++);else break;if(!kbhit()) Sleep(10);}}
void Color(int a){
#define SCT SetConsoleTextAttribute
#define GSH GetStdHandle(STD_OUTPUT_HANDLE)
#define WHITE FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE
    if(a==0) SCT(GSH,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);if(a==10) SCT(GSH,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);if(a==20) SCT(GSH,FOREGROUND_INTENSITY|FOREGROUND_GREEN);if(a==30) SCT(GSH,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);if(a==40) SCT(GSH,FOREGROUND_INTENSITY|FOREGROUND_RED);if(a==50) SCT(GSH,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);if(a==60) SCT(GSH,FOREGROUND_INTENSITY|FOREGROUND_BLUE);if(a==70) SCT(GSH,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    if(a==71) SCT(GSH,FOREGROUND_INTENSITY);if(a==11) SCT(GSH,FOREGROUND_GREEN|FOREGROUND_BLUE);if(a==21) SCT(GSH,FOREGROUND_GREEN);if(a==31) SCT(GSH,FOREGROUND_RED|FOREGROUND_BLUE);if(a==41) SCT(GSH,FOREGROUND_RED);if(a==51) SCT(GSH,FOREGROUND_RED|FOREGROUND_GREEN);if(a==61) SCT(GSH,FOREGROUND_BLUE);if(a==-1) SCT(GSH,BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE);if(a==1) SCT(GSH,0);if(a==-10) SCT(GSH,BACKGROUND_INTENSITY|BACKGROUND_GREEN|BACKGROUND_BLUE);if(a==-20) SCT(GSH,BACKGROUND_INTENSITY|BACKGROUND_GREEN);if(a==-30) SCT(GSH,BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_BLUE);
    if(a==-40) SCT(GSH,BACKGROUND_INTENSITY|BACKGROUND_RED|WHITE);if(a==-50) SCT(GSH,BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN);if(a==-60) SCT(GSH,BACKGROUND_INTENSITY|BACKGROUND_BLUE|WHITE);if(a==-70) SCT(GSH,BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE);if(a==-71) SCT(GSH,BACKGROUND_INTENSITY|WHITE);if(a==-11) SCT(GSH,BACKGROUND_GREEN|BACKGROUND_BLUE|WHITE);if(a==-21) SCT(GSH,BACKGROUND_GREEN|WHITE);if(a==-31) SCT(GSH,BACKGROUND_RED|BACKGROUND_BLUE|WHITE);if(a==-41) SCT(GSH,BACKGROUND_RED|WHITE);if(a==-51) SCT(GSH,BACKGROUND_RED|BACKGROUND_GREEN|WHITE);if(a==-61) SCT(GSH,BACKGROUND_BLUE|WHITE);
}
struct TYPPER{
    char name;
    int left,up;//�������ң����ϵ��� 
    float x,y;//y�Ǻ��� 
}T[50],Ta[50];//Ta:all,T:��ĸ 
int N[50];//����ĸ��Ӧ 
void Initialization_TYPPER(){
    char T1[50]="*QWERTYUIOP[]";//��ĸ1len=10+2 
    char T2[50]="*ASDFGHJKL;'";//��ĸ2len=9+2 
    char T3[50]="*ZXCVBNM,./";//��ĸ3len=7+3
    int tl=0,tal=0;
    for(int j=1;j<=3;j++) for(int i=1;i<=12;i++){
        char t0;
        if(j==1) t0=T1[i];if(j==2) t0=T2[i];if(j==3) t0=T3[i];
        if(t0>='A'&&t0<='Z'){tl++;T[tl].name=t0;T[tl].left=i;T[tl].up=j;T[tl].x=4*j-1;T[tl].y=4*i-1;if(j==2) T[tl].y+=1;if(j==3) T[tl].y+=3;N[t0-'A'+1]=tl;}
        if(t0!=0){tal++;Ta[tal].name=t0;Ta[tal].left=i;Ta[tal].up=j;Ta[tal].x=4*j-1;Ta[tal].y=4*i-1;if(j==2) Ta[tal].y+=1;if(j==3) Ta[tal].y+=3;
        }
    }
    B26_Color['W'-'A'+1]=T9_Color[2];B26_Color['A'-'A'+1]=T9_Color[2];B26_Color['S'-'A'+1]=T9_Color[2];B26_Color['D'-'A'+1]=T9_Color[2];B26_Color['Q'-'A'+1]=T9_Color[1];B26_Color['E'-'A'+1]=T9_Color[4];B26_Color['R'-'A'+1]=T9_Color[4];B26_Color['T'-'A'+1]=T9_Color[4];B26_Color['Y'-'A'+1]=T9_Color[4];B26_Color['F'-'A'+1]=T9_Color[5];B26_Color['G'-'A'+1]=T9_Color[5];B26_Color['H'-'A'+1]=T9_Color[5];B26_Color['Z'-'A'+1]=T9_Color[3];B26_Color['X'-'A'+1]=T9_Color[3];B26_Color['C'-'A'+1]=T9_Color[3];B26_Color['V'-'A'+1]=T9_Color[3];B26_Color['B'-'A'+1]=T9_Color[6];for(char i='I';i<='P';i++) B26_Color[i-'A'+1]=T9_Color[9];B26_Color['U'-'A'+1]=T9_Color[7];B26_Color['I'-'A'+1]=T9_Color[7];B26_Color['O'-'A'+1]=T9_Color[7];
    //B26_Color���� 
    for(int i=1;i<=26;i++){if(T[i].left<=5) L26_Color[T[i].name-'A'+1]=L8_Color[i];
    if(T[i].left<=5) L26_Color[T[i].name-'A'+1]=L8_Color[T[i].left];
    else if(T[i].up==1&&T[i].left>=6) L26_Color[T[i].name-'A'+1]=L8_Color[max(5,T[i].left-2)];
    else if(T[i].up==2&&T[i].left>=6) L26_Color[T[i].name-'A'+1]=L8_Color[T[i].left-1];
    else if(T[i].up==3&&T[i].left>=6) L26_Color[T[i].name-'A'+1]=L8_Color[T[i].left];
    }
    //L26_Color���� 
}
void TEST_FJ();void TEACH_Board_TEST(int a);void TEACH_Board_Left();void TEACH_Board_Right();void TEACH_Board_Mid();void TEACH_Board_Remember();void TEACH_Board_Word();

#define PSK Setpos(T[i].x,T[i].y),cout<<"       ";Setpos(T[i].x+1,T[i].y),cout<<"   "<<T[i].name<<"   ";Setpos(T[i].x+2,T[i].y),cout<<"       "
void Print_Single_Key_Char(char a) {int i=N[a-'A'+1];Color(-70);PSK;}
void Print_Single_Key_Int(int i) {Color(-70);PSK;}
void Print_Single_Key_Char_C(char a,int color) {int i=N[a-'A'+1];Color(color);PSK;}
void Print_Single_Key_Int_C(int i,int color) {Color(color);PSK;}
void Print_Local_Key_C(char local,char name,int color) {if(local>'a'&&local<'z')local+='A'-'a';if(local<'A'||local>'Z') return;int i=N[local-'A'+1];Color(color);Setpos(T[i].x,T[i].y),cout<<"       ";Setpos(T[i].x+1,T[i].y),cout<<"   "<<name<<"   ";Setpos(T[i].x+2,T[i].y),cout<<"       ";}
void Print_Hole_TYPPER_Key(){for(int i=1;i<=26;i++)Print_Single_Key_Int(i);}
void Print_Hole_TYPPER_Key_S(int sleep) {for(int i=1;i<=26;i++)Print_Single_Key_Int(i),Sleep(sleep);}
void Print_Hole_TYPPER_Key_L26() {for(int i=1;i<=26;i++) Print_Single_Key_Int_C(i,L26_Color[T[i].name-'A'+1]);}
void Print_Hole_TYPPER_Key_B26() {for(int i=1;i<=26;i++) Print_Single_Key_Int_C(i,B26_Color[T[i].name-'A'+1]);}
void Print_Hole_TYPPER_Key_L26_S(int sleep) {for(int i=1;i<=26;i++) Print_Single_Key_Int_C(i,L26_Color[T[i].name-'A'+1]),Sleep(sleep);}
void Print_Hole_TYPPER_Key_B26_S(int sleep) {for(int i=1;i<=26;i++) Print_Single_Key_Int_C(i,B26_Color[T[i].name-'A'+1]),Sleep(sleep);}

int UP=2;

void Print_Frame(){for(int i=UP;i<=min(39,UP+13);i++){Setpos(i,2);Color(-1);if(i==UP+13)Color(-71);for(int j=1;j<=83;j++) printf(" ");}}
void Print_Frame_Line(int color){int i=15; Setpos(i,2);Color(color);for(int j=1;j<=83;j++) printf(" ");}
void Print_Frame_Line_FJ(int color){int i=16; Setpos(i,2);Color(color);for(int j=1;j<=83;j++) printf(" ");}
void Print_Hole_TYPPER(){Print_Frame();Print_Hole_TYPPER_Key();}
void Print_Hole_TYPPER_Board(){Print_Frame();for(int i=1;i<=26;i++) Print_Single_Key_Char_C('A'-1+i,B26_Color[i]);}
void Print_Hole_TYPPER_Finger(){Print_Frame();for(int i=1;i<=26;i++) Print_Single_Key_Char_C('A'-1+i,L26_Color[i]);}
void Spark_Key(char a,int color,int sleep){Print_Single_Key_Char_C(a,color);Sleep(sleep);Print_Single_Key_Char_C(a,-71);Sleep(sleep);Print_Single_Key_Char_C(a,color);Sleep(sleep);Print_Single_Key_Char_C(a,-71);Sleep(sleep);Print_Single_Key_Char_C(a,color);Sleep(sleep*2);}
void Spark_Key_Right(char a,int color,int sleep){int c=-20;Print_Single_Key_Char_C(a,color);Sleep(sleep);Print_Single_Key_Char_C(a,-20);Sleep(sleep);Print_Single_Key_Char_C(a,color);Sleep(sleep);Print_Single_Key_Char_C(a,-20);Sleep(sleep);Print_Single_Key_Char_C(a,color);Sleep(sleep*2);}
void Spark_Key_Wrong(char a,int color,int sleep){Print_Single_Key_Char_C(a,color);Sleep(sleep);Print_Single_Key_Char_C(a,-41);Sleep(sleep);Print_Single_Key_Char_C(a,color);Sleep(sleep);Print_Single_Key_Char_C(a,-41);Sleep(sleep);Print_Single_Key_Char_C(a,color);Sleep(sleep*2);}
void Print_Hole_TYPPER_Dark(){for(char i=1;i<=26;i++) Print_Single_Key_Int_C(i,-71),Sleep(20);}
void Print_Hole_TYPPER_None(){for(char i=1;i<=30;i++) {if(i>=4&&i<=30) Print_Local_Key_C(i+'A'-1-4,'?',-70);if(i>=1&&i<=26) Print_Local_Key_C(i+'A'-1,'?',-71);Sleep(20);}}
void Print_String_Key_Char(char a[100]){char t=0;for(int i=0;i<=99;i++){if(a[i]!=0) t=a[i];else break;if(t>='a'&&t<='z') t+='A'-'a';if(t>='A'&&t<='Z') Print_Single_Key_Char(t);}}
void Print_String_Key_Char_C(char a[100],int color){char t=0;for(int i=0;i<=99;i++){if(a[i]!=0) t=a[i];else break;if(t>='a'&&t<='z') t+='A'-'a';if(t>='A'&&t<='Z') Print_Single_Key_Char_C(t,color);}}
void Print_String_Key_Char_C_S(char a[100],int color,int sleep){char t=0;for(int i=0;i<=99;i++){if(a[i]!=0) t=a[i];else break;if(t>='a'&&t<='z') t+='A'-'a';if(t>='A'&&t<='Z') Print_Single_Key_Char_C(t,color);Sleep(sleep);}}

void Slow_Frame(int x0,int y0,int x1,int y1){Color(0);
    for(int i=y0;i<=y1;i++) Setpos(x0,i),printf("*"),Sleep(2);
    for(int i=x0;i<=x1;i++) Setpos(i,y0),printf("*"),Setpos(i,y1),printf("*"),Sleep(2);
    for(int i=y0;i<=y1;i++) Setpos(x1,i),printf("*"),Sleep(2);
}void Frame(int x0,int y0,int x1,int y1){Color(0);
    for(int i=y0;i<=y1;i++) Setpos(x0,i),printf("*");
    for(int i=x0;i<=x1;i++) Setpos(i,y0),printf("*"),Setpos(i,y1),printf("*");
    for(int i=y0;i<=y1;i++) Setpos(x1,i),printf("*");
}
void Dark_Frame(int x0,int y0,int x1,int y1){Color(0);for(register int i=x0;i<=x1;i++)for(register int j=y0;j<=y1;j++) Setpos(i,j),printf("  ");}
void Dark_Frame_L(int x0,int y0,int x1,int y1){Color(0);for(register int j=y1;j>=y0;j--) Dark_Frame(x0,j,x1,j),Sleep(5);}
int Step_X(int x0,int y0,int x1,int y1,int step,int stepmax) {float s=(x1-x0)*1.0/stepmax*1.0;return int(x0+s*step);}
int Step_Y(int x0,int y0,int x1,int y1,int step,int stepmax) {float s=(y1-y0)*1.0/stepmax*1.0;return int(y0+s*step);}
void Light_L8(int colornum){for(int i=1;i<=26;i++){if(L26_Color[i]==L8_Color[colornum])Spark_Key(i+'A'-1,L8_Color[colornum],30);}}

void TYPPER_UP(){
    UP=38;int Ti=0;
    for(int i=1;i<=26;i++){T[i].x+=36;}
    while(UP>2)
    {Ti++;
        Print_Frame();
        Print_Hole_TYPPER_Key();
        if(UP+14<39) Dark_Frame(UP+14,0,42,39);

        UP-=3;
        for(int i=1;i<=26;i++){T[i].x-=3;}

        Sleep(10);
    }
    Color(0);system("cls");
    Initialization_TYPPER();
    Print_Hole_TYPPER();
}
void Point(){for(int i=0;i<=36;i+=3) for(int j=0;j<=42;j+=7)Setpos(i,j),cout<<'*'<<'('<<i<<','<<j<<')';for(int i=1;i<=34;i+=3) for(int j=3;j<=39;j+=7)Setpos(i,j),cout<<'*'<<'('<<i<<','<<j<<')';}
void Light_String_T9(char a[100],int color){char t=0;for(int i=0;i<=99;i++){if(a[i]!=0) t=a[i];else break;if(t>='a'&&t<='z') t+='A'-'a';if(t>='A'&&t<='Z') Spark_Key(t,T9_Color[color],30);}}
void Print_Board_Name(){
Dark_Frame(2,25,8,40);
Slow_Frame(1,26,9,44);
    Setpos(3,25+3),Color(T9_Color[1]),Slow_F(" QWER ");Sleep(100);
    Setpos(3,30+3),Color(T9_Color[4]),Slow_F(" ERTY ");Sleep(100);
    Setpos(3,35+3),Color(T9_Color[7]),Slow_F(" UIOP ");Sleep(100);
    Setpos(5,26+3),Color(T9_Color[2]),Slow_F(" ASDF ");Sleep(100);
    Setpos(5,31+3),Color(T9_Color[5]),Slow_F(" FGHJ ");Sleep(100);
    Setpos(5,36+3),Color(T9_Color[8]),Slow_F(" JKL; ");Sleep(100);
    Setpos(7,28+3),Color(T9_Color[3]),Slow_F(" ZXCV ");Sleep(100);
    Setpos(7,33+3),Color(T9_Color[6]),Slow_F(" BNM, ");Sleep(100);
}
void TEACH_Board_Remember(){Initialization_TYPPER();
    Slow_Frame(1,1,9,36);
    Setpos(3,3);Slow("�п�������ü��̱����Ǽ����ѵ�����");Sleep(500);
    Setpos(5,3);Slow("û�й�ϵ���������������֪һ��");Sleep(500);
    Setpos(7,3);Slow("�ȴ����˽�һ�¼��̵ķ����ɣ�");
    for(int i=1;i<=26;i++){T[i].x+=8;}
    Light_String_T9("WASD",2); Setpos(23,4),Slow_F("���� WASD ����������4399��С��Ϸ��������Ӧ�öԴ����ǳ����˽⣡");
    Light_String_T9("Q",1);     Setpos(25,4),Slow_F("���������Ϸ��� Q ����Ϊ̫�������ˣ����Ա���������ôƫԶ�ĵط�...");
    Light_String_T9("ZXCV",3); Setpos(27,4),Slow_F("λ�ڼ������½ǵ� Ctrl �������ž���ʹ�õ��Ե��˶����᲻��Ϥ...");
    Light_String_T9("ERTY",4); Setpos(29,4),Slow_F("�ڼ��̵����Ϸ����ۼ���һ��Ӣ�ĵ��ʵġ���ĸ��׺��(-er,-ty)");
    Light_String_T9("FGH",5); Setpos(31,4),Slow_F("�ں�׺���·��������� F G H ������ĸ���ţ�������ͽ� �м�(G)�� �ɣ�");
    Light_String_T9("B",6);     Setpos(33,4),Slow_F("���ˣ������������·�����ĸ B ");
    Light_String_T9("UIO",7);Light_String_T9("P",9); Setpos(35,4),Slow_F("���׺����ԣ��ڼ��̵����Ϸ���Ԫ��������ĩ��P��β����Qң���Ӧ");
    Light_String_T9("JKLNM",8);Setpos(37,4),Slow_F("���̵����·�����һ��������ĸ�����һ������򣬴� J �� M �����ǾͰ������� MJ ���ɡ�");
    Sleep(500);
    Color(-50); Setpos(33,29);Slow("   "),system("pause");
    Dark_Frame_L(10,2,37,45);
    Dark_Frame(2,2,8,23);
    Setpos(3,3);Slow("��ʵ�㿴�����Ѿ������������һ���˽��˲�����");Sleep(500);
    Setpos(5,3);Slow("����������Ҫ���ģ�ֻ�����ǽ���Щ����ķ���ϵͳ�ش����������ˡ�");Sleep(500);
    Setpos(7,3);Slow("�����������ǾͿ�ʼѧϰ���������ķ����ɣ�");
    Print_Board_Name();
    Light_String_T9("QWER",1);Setpos(23,4),Slow_F("���ĸ���ĸ��ֱ�ǡ��ο�ʼ�ĵط������Ǳ��߱�������ġ���ʵ������Բ����һ����ǰ��λ����Ī������Ϳ��Լǵú��εġ�Anyway��Ҫ���벻���ھ������������ô����");
    T[N['E'-'A'+1]].x--;T[N['R'-'A'+1]].x--;
    Light_String_T9("ERTY",4);Setpos(25,4),Slow_F("�����ϵĺ�׺����������RTY����ʳָ���ϣ�Y������Ҫ�����ְ�����ʵ��Y��Bһ�����Ǽ��������ѹ���������������ĸ�����������������塱�����˸о����ÿھ�Ҳ�ܼǣ�");
    Light_String_T9("UIOP",7);Setpos(27,4),Slow_F("�����ϵ�Ԫ�����������˸�P���ڼ����P��Qλ������ңң��ԣ�ң���Ӧ����һ�������ء�����Ԫ������ʳָU��ָI����ָO���������ר�ŵ������ϰ������P����Сָ���Ƶ�Ψһ��ĸ�أ�");
    Light_String_T9("ASDF",2);Setpos(29,4),Slow_F("A��  S�¶�/����  D�ң���˳����Σ�F��ʳָ��������ĸ��ASDF��������ָ��������ĸ��");
    T[N['F'-'A'+1]].x--;
    Light_String_T9("FGHJ",5);Setpos(31,4),Slow_F("����������G�������С���GH���������ʣ�FGHJ�����ĸ���ĸ����ʳָ���أ������ļ������ģ�����������F��J��������Ӧ����С͹��ָʾ��");
    T[N['J'-'A'+1]].x--;
    Light_String_T9("JKL",8);Setpos(33,4),Slow_F("��JKL����Сָ��ʼû�¸��ˣ�ע��������Ȼ��������ĸ��������ָ������");
    Light_String_T9("ZXCV",3);Setpos(35,4),Slow_F("�����µ�Ctrl��������˳����Ҫ��˵�˰ɣ�");
    Light_String_T9("BNM",6);Setpos(37,4),Slow_F("������ĸ�����е�����BMW���� г����������������ע�������Ѿ����������ˣ�BNM����������ʳָ���Ƶ����򣡣���ָ��������ָ���Сָ�ٺţ�������ǳ��򲻽̡���");
    Sleep(500);
    Color(-50); Setpos(35,27);Slow("   "),system("pause");
    Dark_Frame_L(10,0,39,45);
    Dark_Frame(2,2,8,24);
    Setpos(3,3);Slow("���������ˣ�");Sleep(500);
    Setpos(5,3);Slow("������ѧ���Ǵ���ӡ�󣬼ǲ���Ҳû��ϵ��");Sleep(500);
    Setpos(7,3);Slow("������Ϊ��ģ����Ǵ��ж��⿪ʼ��");
system("cls");
}
void Print_String_C(char a[30],int c){Print_String_Key_Char_C(a,c);}
void Print_String_T9(char a[30],int c){Print_String_Key_Char_C(a,T9_Color[c]);}
void Spark_String_T9(char a[30],int c){Print_String_T9(a,c);Sleep(30);Print_String_C(a,-71);Sleep(30);Print_String_T9(a,c);Sleep(30);Print_String_C(a,-71);Sleep(30);Print_String_T9(a,c);Sleep(30);Print_String_C(a,-71);Sleep(30);Print_String_T9(a,c);Sleep(60);}
void TEACH_Board_Mid(){Initialization_TYPPER();
    Slow_Frame(1,1,9,33);
    Setpos(3,3);Slow("��ϲͨ����������������������ѧϰ�м䲿�ְɣ�");Sleep(500);
    Setpos(5,3);Slow("��ʵ�ϣ��м䲿�����Ѿ����������ˣ�");Sleep(500);
    Setpos(7,3);Slow("����Ѹ�ٵ�����һ�£�");
    Sleep(500);
    char Ch[13]="TY  GH  BN  ";int x0[12],y0[12],x1[12],y1[12],c[12];
    for(int i=0;i<=11;i++){if(Ch[i]==' ')continue;char a=Ch[i];int j=N[a-'A'+1];T[j].x+=8;}
    Print_String_Key_Char_C_S("TGB",T9_Color[4],30);Print_String_Key_Char_C_S("YHN",T9_Color[6],30);Sleep(800);
    for(int i=0;i<=11;i++){if(Ch[i]==' ')continue;char a=Ch[i];int j=N[a-'A'+1];x0[i]=T[j].x;y0[i]=T[j].y;if(i<4) x1[i]=19;else if(i<8) x1[i]=23;else x1[i]=27;if(i%4==0) y1[i]=3;if(i%4==1) y1[i]=7;if(i%4==2) y1[i]=11;if(i%4==3) y1[i]=15;x1[i]+=2,y1[i]+=3;c[i]=T9_Color[(i%4)*2+4];}
    int step=0,stepmax=7;
    while(step<stepmax)
    {
        step++;
        for(int i=0;i<=11;i++){
            char a=Ch[i];int j=N[a-'A'+1];
            Print_Single_Key_Int_C(j,1);
            T[j].x=Step_X(x0[i],y0[i],x1[i],y1[i],step,stepmax);
            T[j].y=Step_Y(x0[i],y0[i],x1[i],y1[i],step,stepmax);
            Print_Single_Key_Int_C(j,c[i]);
        }
        Sleep(50);
    }
Print_String_Key_Char_C_S("TGB",T9_Color[4],30);Print_String_Key_Char_C_S("YHN",T9_Color[6],30);
    Sleep(800);
    Spark_String_T9("TY",4);
    Setpos(11,2),Slow("  �м�������TY  ");Color(0),printf(" �� �� ��ERTY�ĺ��沿�֡� �� �� T �� Y ��");
    Sleep(500);Spark_String_T9("GH",5);
    Setpos(13,2),Slow("  �м�������GH  ");Color(0),printf(" �� �� ��FGHJ���м䲿�֡� �� �� G �� H ��");
    Sleep(500);Spark_String_T9("BN",6);
    Setpos(15,2),Slow("  �м�������BN  ");Color(0),printf(" �� �� ��BNM����ǰ�˲��֡��� �� B �� N ��");
    Sleep(500);Color(T9_Color[7]);
    Setpos(17,2),Slow("  ...������ TGB ������ YHN �� ");Color(0),printf(" �� �� Ҫ����Ļ�����Ҫ�ھ��Ļ����Ǿ����֡��򹷰��������֡��ջ��㡱��");
    Sleep(500);
    Slow_Frame(19,21,33,43);
    Setpos(21,23);Slow("TY GH BN TGB YHN����ס����");Sleep(500);
    Setpos(23,23);Slow("�²��˳٣����������������̲��ԣ�");Sleep(500);
    Setpos(25,23);Slow("����֮�����Ǿͽ���");Sleep(500);
    Setpos(27,24);Slow("�����̱���ƪ ֮ ���տ��顱��");Sleep(500);
    Color(-50); Setpos(31,23);Slow("   ���������ʼ   ");
    Color(0),Setpos(7,3),system("pause");
}
void TEACH_Board_Right(){Initialization_TYPPER();
    Slow_Frame(1,1,9,33);
    Setpos(3,3);Slow("��ϲͨ���������������Ѿ����°�������ˣ����ͣ�");Sleep(500);
    Setpos(5,3);Slow("��������֣����ּ�����Ȼ�٣������׻��״��ѶȽϴ�");Sleep(500);
    Setpos(7,3);Slow("���ɣ������ǿ�ʼѧϰ���ּ��̣�");
    Sleep(500);
    char Ch[13]="UIOPJKL M   ";int x0[12],y0[12],x1[12],y1[12],c[12];
    for(int i=0;i<=11;i++){if(Ch[i]==' ')continue;char a=Ch[i];int j=N[a-'A'+1];T[j].x+=8;}
    Print_String_Key_Char_C_S("UIOP",T9_Color[7],30);Print_String_Key_Char_C_S("JKL",T9_Color[8],30);Print_String_Key_Char_C_S("M",T9_Color[9],30);
    Dark_Frame(2,2,8,32);
    Setpos(3,3);Slow("��������ֱߵļ���");Sleep(500);
    Setpos(5,3);Slow("ͬ������������Ӳ���ǲ��е�...");Sleep(500);
    Setpos(7,3);Slow("�������ٴΰ�ÿ�������䵽��ָ��");
    for(int i=0;i<=11;i++){if(Ch[i]==' ')continue;char a=Ch[i];int j=N[a-'A'+1];x0[i]=T[j].x;y0[i]=T[j].y;if(i<4) x1[i]=19;else if(i<8) x1[i]=23;else x1[i]=27;if(i%4==0) y1[i]=3;if(i%4==1) y1[i]=7;if(i%4==2) y1[i]=11;x1[i]+=2;if(i%4==3) y1[i]=15;c[i]=T9_Color[i/4+1+7];}
    int step=0,stepmax=7;
    while(step<stepmax)
    {
        step++;
        for(int i=0;i<=11;i++){
            char a=Ch[i];int j=N[a-'A'+1];
            Print_Single_Key_Int_C(j,1);
            T[j].x=Step_X(x0[i],y0[i],x1[i],y1[i],step,stepmax);
            T[j].y=Step_Y(x0[i],y0[i],x1[i],y1[i],step,stepmax);
            Print_Single_Key_Int_C(j,c[i]);
        }
        Sleep(50);
    }
Print_String_Key_Char_C_S("UIOP",-70,30);Print_String_Key_Char_C_S("JKL",-70,30);Print_String_Key_Char_C_S("M",-70,30);
    Sleep(800);
    Spark_String_T9("UIOP",7);
    Setpos(11,2),Slow("  ����������Ԫ����P  ");Color(0),printf(" �� �� ���������ú����з�����ʳ�=��ʳָ��U��������ҽ��=����ָ��I����������ָ�ֽл�ָ��=����ָ��O������Сָ���P��=...");
    Sleep(500);Spark_String_T9("JKL",8);
    Setpos(13,2),Slow("  �����������������  ");Color(0),printf(" �� �� ����������������ĸ J K L ����ʳ����ʱ������=��ʳָ��J�������п���=����ָ��K��������ָ��������=����ָ��L����Сָû�¸ɣ�");
    Sleep(500);Spark_String_T9("M",9);
    Setpos(15,2),Slow("  ����������M  ");Color(0),printf(" �� �� BNM����һ���֣�������������������ָ���ƣ���Ҫ�ǰ���������ɡ������á�Ҳû������...");
    Sleep(500);T[N['U'-'A'+1]].x--;T[N['J'-'A'+1]].x--;T[N['M'-'A'+1]].x--;Spark_String_T9("UJM",5);
    Setpos(17,2),Slow("  ����ʳָ����ʳ��ָ  ");Color(0),printf(" �� �� ����Ψһ�ھ������޾��ס�����ʳָ�����ֺܴ���Բ����Թ�棺�������ʲô������Ȼ���ޣ������ף���ʲô�����������");
    Sleep(500);
    Slow_Frame(19,21,33,43);
    Setpos(21,23);Slow("�����׻��״�һ��Ҫ����Ŷ");Sleep(500);
    Setpos(23,23);Slow("��˵��ھ����������(zhi)��(zhang)...");Sleep(500);
    Setpos(25,23);Slow("��������������Ǽ�����䣬���þ��У�");Sleep(500);
    Setpos(27,23);Slow("UIOP JKL M UJM ����ס����");Sleep(500);
    Setpos(29,23);Slow("��ס�˺����Ǿ���һ�����̲��ԣ�");Sleep(500);
    Color(-50); Setpos(31,23);Slow("   ���������ʼ   ");
    Color(0),Setpos(3,3),system("pause");
}
void TEACH_Board_Left(){Initialization_TYPPER();
    Slow_Frame(1,1,9,30);
    Setpos(3,3);Slow("Ҫ֪����ֻҪ���̱��ĺã������ٶ���Ȼ��");Sleep(500);
    Setpos(5,3);Slow("��Ȼ����������Ӳ�������γɼ������");Sleep(500);
    Setpos(7,3);Slow("�������������򽫰������ٴΣ���ȷ�ر����������̣�");
    Sleep(500);
    char Ch[13]="QWERASDFZXCV";int x0[12],y0[12],x1[12],y1[12],c[12];
    for(int i=0;i<=11;i++){char a=Ch[i];int j=N[a-'A'+1];T[j].x+=8;}
    Print_String_Key_Char_C_S("QWER",T9_Color[1],30);Print_String_Key_Char_C_S("ASDF",T9_Color[2],30);Print_String_Key_Char_C_S("ZXCV",T9_Color[3],30);
    Dark_Frame(2,2,8,28);
    Setpos(3,3);Slow("��������ֱߵļ���");Sleep(500);
    Setpos(5,3);Slow("��������Ӳ���ǲ��е�...");Sleep(500);
    Setpos(7,3);Slow("�����ǰ�ÿ�������䵽��ָ��");
    for(int i=0;i<=11;i++){char a=Ch[i];int j=N[a-'A'+1];x0[i]=T[j].x;y0[i]=T[j].y;if(i<4) x1[i]=19;else if(i<8) x1[i]=23;else x1[i]=27;if(i%4==3) y1[i]=3;if(i%4==2) y1[i]=7;if(i%4==1) y1[i]=11;if(i%4==0) y1[i]=15;x1[i]+=2;c[i]=T9_Color[i/4+1];}
    int step=0,stepmax=7;
    while(step<stepmax)
    {
        step++;
        for(int i=0;i<=11;i++){
            char a=Ch[i];int j=N[a-'A'+1];
            Print_Single_Key_Int_C(j,1);
            T[j].x=Step_X(x0[i],y0[i],x1[i],y1[i],step,stepmax);
            T[j].y=Step_Y(x0[i],y0[i],x1[i],y1[i],step,stepmax);
            Print_Single_Key_Int_C(j,c[i]);
        }
        Sleep(50);
    }
Print_String_Key_Char_C("QWER",T9_Color[1]);Print_String_Key_Char_C("ASDF",T9_Color[2]);Print_String_Key_Char_C("ZXCV",T9_Color[3]);    
    Sleep(800);
    Light_L8(4);
    Setpos(11,2),Slow("  ����ʳָ����ָ  ");Color(0),printf(" �� �� R F V ...�����о��е����ص���ĸ�������������˷��㡱");
    Sleep(500);Light_L8(3);
    Setpos(13,2),Slow("  ������ָ����ָ  ");Color(0),printf(" �� �� ����������������ĸ C D E ��C������ĸ���ŵ�������������������Ե��");
    Sleep(500);Light_L8(2);
    Setpos(15,2),Slow("  ������ָ����ָ  ");Color(0),printf(" �� �� ������ĸ�ֱ��� W S X����������...����(sha)��(cha)...");
    Sleep(500);Light_L8(1); 
    Setpos(17,2),Slow("  ����Сָ����ָ  ");Color(0),printf(" �� �� �����Ƶ�������ĸ������ƫԶ����ĸ����ǰͷ�����ͷ��������");
    Sleep(500);
    Slow_Frame(19,21,33,43);
    Setpos(21,23);Slow("�����ÿ����ָ�Ķ�Ӧ����");Sleep(500);
    Setpos(23,23);Slow("��˵��ھ��������(zhi)��(zhang)...");Sleep(500);
    Setpos(25,23);Slow("��������������Ǽ�����䣬���þ��У�");Sleep(500);
    Setpos(27,23);Slow("RFV EDC WSX QAZ ����ס����");Sleep(500);
    Setpos(29,23);Slow("��ס�˺����Ǿ���һ�����̲��ԣ�");Sleep(500);
    Color(-50); Setpos(31,23);Slow("   ���������ʼ   ");
    Color(0),Setpos(3,3),system("pause");
}
void Print_Left(){Print_String_Key_Char("QWERASDFZXCV");}
void Print_Left_C(){Print_String_Key_Char_C("QWER",T9_Color[1]);Print_String_Key_Char_C("ASDF",T9_Color[2]);Print_String_Key_Char_C("ZXCV",T9_Color[3]);}
void Spark_Left(){Print_Left_C();Sleep(60);Print_Left();Sleep(60);Print_Left_C();Sleep(60);Print_Left();Sleep(60);Print_Left_C();Sleep(60);Print_Left();Sleep(60);}
void Slow_Left(){Print_String_Key_Char_C_S("QWER",T9_Color[1],30);Print_String_Key_Char_C_S("ASDF",T9_Color[2],30);Print_String_Key_Char_C_S("ZXCV",T9_Color[3],30);}
void Print_Right(){Print_String_Key_Char("UIOPJKLM");}
void Print_Right_C(){Print_String_Key_Char_C("UIOP",T9_Color[7]);Print_String_Key_Char_C("JKL",T9_Color[8]);Print_String_Key_Char_C("M",T9_Color[9]);}
void Spark_Right(){Print_Right_C();Sleep(60);Print_Right();Sleep(60);Print_Right_C();Sleep(60);Print_Right();Sleep(60);Print_Right_C();Sleep(60);Print_Right();Sleep(60);}
void Slow_Right(){Print_String_Key_Char_C_S("UIOP",T9_Color[7],30);Print_String_Key_Char_C_S("JKL",T9_Color[8],30);Print_String_Key_Char_C_S("M",T9_Color[9],30);}
void Print_Mid(){Print_String_Key_Char("YHNUJM");}
void Print_Mid_C(){Print_String_Key_Char_C("YHN",T9_Color[4]);Print_String_Key_Char_C("UJM",T9_Color[6]);}
void Spark_Mid(){Print_Mid_C();Sleep(60);Print_Mid();Sleep(60);Print_Mid_C();Sleep(60);Print_Mid();Sleep(60);Print_Mid_C();Sleep(60);Print_Mid();Sleep(60);}
void Slow_Mid(){Print_String_Key_Char_C_S("YHN",T9_Color[4],30);Print_String_Key_Char_C_S("UJM",T9_Color[6],30);}
void Spark_All(){Print_Hole_TYPPER_Key_B26();Sleep(30);Print_Hole_TYPPER_Key();Sleep(30);Print_Hole_TYPPER_Key_B26();Sleep(30);Print_Hole_TYPPER_Key();Sleep(30);Print_Hole_TYPPER_Key_B26();Sleep(30);Print_Hole_TYPPER_Key();Sleep(30);}
void Slow_All(){Print_Hole_TYPPER_Key_B26_S(15);}

bool Q[30];//�ʹ�û�� 
int Rightmax,Right_Count;
void Print_Right_Count(int x,int y){
    Setpos(x,y),Color(-70);for(int i=1;i<=Rightmax+2;i++)cout<<"  ";
    Setpos(x+1,y),Color(-70);cout<<"  ";Color(20);for(int i=1;i<=Right_Count;i++)cout<<"��";Color(0),cout<<"  ";Setpos(x+1,y+1+Rightmax),Color(-70);cout<<"  ";
    Setpos(x+2,y),Color(-70);for(int i=1;i<=Rightmax+2;i++)cout<<"  ";
}
#define PLK Setpos(x,y),cout<<"       ";Setpos(x+1,y),cout<<"   "<<a<<"   ";Setpos(x+2,y),cout<<"       "
void Print_Located_Key_Char(char a,int x,int y) {int i=N[a-'A'+1];Color(-70);PLK;}
void Print_Located_Key_Char_C(char a,int x,int y,int color) {int i=N[a-'A'+1];Color(color);PLK;}
void Jump_Que(char Que){Dark_Frame(22,3,22,6);Print_Located_Key_Char_C(Que,19,3,-50);Sleep(30);Dark_Frame(21,3,21,6);Print_Located_Key_Char_C(Que,18,3,-50);Sleep(40);Dark_Frame(18,3,18,6);Print_Located_Key_Char_C(Que,19,3,-50);Sleep(30);Dark_Frame(19,3,19,6);Print_Located_Key_Char(Que,20,3);Color(0);Setpos(19,3);cout<<"Quiz:";}
bool String_Belong(char a,char b[40]){if(a>'a'&&a<'z') a+='A'-'a';for(int i=0;i<40;i++){if(b[i]>'a'&&b[i]<'z') b[i]+='A'-'a';if(b[i]==a) return 1;if(b[i]==0) break;}return 0;}
void Tips(char Que,int a){Color(0);
    if(a==1){
        Setpos(23,25);Slow(" Tips1:");
        Setpos(24,26);
        R1:int r=rand()%15;
        if(r==0&&String_Belong(Que,"WASD")) {Slow("������WASD��");return;}
        if(r==1&&String_Belong(Que,"QWER")) {Slow("������QWER��");return;}
        if(r==2&&String_Belong(Que,"ASDF")) {Slow("������ASDF��");return;}
        if(r==3&&String_Belong(Que,"ZXCV")) {Slow("������Ctrl����ZXCV��");return;}
        if(r==4&&String_Belong(Que,"ERTY")) {Slow("�����ں�׺����ERTY��");return;}
        if(r==5&&String_Belong(Que,"UIO")) {Slow("������Ԫ������UIO��");return;}
        if(r==6&&String_Belong(Que,"FGH")) {Slow("��������G����FGH��");return;}
        if(r==7&&String_Belong(Que,"JKLNM")) {Slow("������MJ����J~M��");return;}
        if(r==8&&String_Belong(Que,"QAZPL")) {Slow("���ڱ߽���");return;}
        if(r==9&&String_Belong(Que,"TYUGHB")) {Slow("���Ǽ����м�������֮һ");return;}
        if(r==10&&String_Belong(Que,"QWERASDFZXCVTG")) {Slow("��Ҫ�����ְ�");return;}
        if(r==10&&String_Belong(Que,"YUIOPHJKLNM")) {Slow("��Ҫ�����ְ�");return;}
        if(r==11&&String_Belong(Que,"QWERTYUIOP")) {Slow("���ڼ�������һ��");return;}
        if(r==12&&String_Belong(Que,"ASDFGHJKL")) {Slow("���ڼ����м�һ��");return;}
        if(r==13&&String_Belong(Que,"ZXCVBNM")) {Slow("���ڼ�������һ��");return;}
        goto R1; 
    }
    if(a==2){
        Setpos(25,25);Slow(" Tips2:");
        Setpos(26,26);
        R2:int r=rand()%3;
        if(String_Belong(Que,"QAZ")) {Slow("�����������֮һ��QAZ��");return;}
        if(String_Belong(Que,"WSX")) {Slow("���ڡ������ɡ��WSX��");return;}
        if(String_Belong(Que,"EDC")) {Slow("����������Ե�֣�EDC��");return;}
        if(String_Belong(Que,"RFV")) {Slow("������ѧ,���˷��㡱��RFV��");return;}
        if(r==0&&String_Belong(Que,"BNM")) {Slow("���ڡ��������BNM��");return;}
        if(r==1&&String_Belong(Que,"TGB")) {Slow("���ڡ��򹷰����TGB��");return;}
        if(r==2&&String_Belong(Que,"YHN")) {Slow("���ڡ��ջ��㡱�YHN��");return;}
        if(r==2&&String_Belong(Que,"UJM")) {Slow("���ڡ��޾��ס��UJM��");return;}
        if(r==1&&String_Belong(Que,"UJ")) {Slow("���ڡ�ʳ��ʳ�����UJ��");return;}
        if(String_Belong(Que,"IK")) {Slow("���ڡ���ҽ�п����IK��");return;}
        if(String_Belong(Que,"OL")) {Slow("���ڡ���ָ�������OL��");return;}
        if(String_Belong(Que,"P")) {Slow("���� Q ң���Ӧ");return;}
        goto R2; 
    }
    if(a==3){
        Setpos(27,25);Slow(" Tips3:");
        Setpos(28,26);
        if(String_Belong(Que,"Q")) {Slow("���������Ͻ�Ŷ����Сָ����");return;}
        if(String_Belong(Que,"W")) {Slow("����������ָ�Ϸ���");return;}
        if(String_Belong(Que,"E")) {Slow("����������ָ�Ϸ���");return;}
        if(String_Belong(Que,"R")) {Slow("��������ʳָ�Ϸ���");return;}
        if(String_Belong(Que,"T")) {Slow("��������ʳָ���Ϸ���");return;}
        if(String_Belong(Que,"P")) {Slow("��������Сָ�Ϸ���");return;}
        if(String_Belong(Que,"O")) {Slow("����������ָ�Ϸ���");return;}
        if(String_Belong(Que,"I")) {Slow("����������ָ�Ϸ���");return;}
        if(String_Belong(Que,"U")) {Slow("��������ʳָ�Ϸ���");return;}
        if(String_Belong(Que,"H")) {Slow("��������ʳָ��ߣ�");return;}
        if(String_Belong(Que,"G")) {Slow("��������ʳָ�ұߣ�");return;}
        if(String_Belong(Que,"Y")) {Slow("���ڼ����Ϸ������룬���ѹ�����");return;}
        if(String_Belong(Que,"B")) {Slow("���ڼ����·������룬���ѹ�����");return;}
        if(String_Belong(Que,"A")) {Slow("������������Сָ�����أ�");return;}
        if(String_Belong(Que,"S")) {Slow("��������������ָ�����أ�");return;}
        if(String_Belong(Que,"D")) {Slow("��������������ָ�����أ�");return;}
        if(String_Belong(Que,"F")) {Slow("������������ʳָ�����أ�");return;}
        if(String_Belong(Que,"L")) {Slow("��������������ָ�����أ�");return;}
        if(String_Belong(Que,"K")) {Slow("��������������ָ�����أ�");return;}
        if(String_Belong(Que,"J")) {Slow("������������ʳָ�����أ�");return;}
        if(String_Belong(Que,"Z")) {Slow("��������Сָ���棡");return;}
        if(String_Belong(Que,"X")) {Slow("����������ָ���·���");return;}
        if(String_Belong(Que,"C")) {Slow("��������ʳָ���·���");return;}
        if(String_Belong(Que,"V")) {Slow("��������ʳָ���·���");return;}
        if(String_Belong(Que,"N")) {Slow("��������ʳָ���·���");return;}
        if(String_Belong(Que,"M")) {Slow("��������ʳָ���·���");return;}
    }
}
struct Firework{float x,y,vx,vy;int color;}F[10000];int fl;
void None_Firework(){fl=0;memset(F,0,sizeof(F));}
void Creat_Firework_U(int x0,int y0,int x1,int y1){
    int S=(x1-x0+1)*(y1-y0+1);
    int p=3;//�ܶ� 
    for(int i=x0;i<=x1;i++)for(int j=y0;j<=y1;j++) {fl++;F[fl].x=i+1,F[fl].y=j,F[fl].vx=-(rand()%26+5)/10.0,F[fl].vy=(rand()%41-20)/10.0;F[fl].color=10*(1+rand()%5+1);int r2=rand()%2;if(r2==1) F[fl].color++;}
    for(int i=1;i<=S*(p-1);i++) {int rx=rand()%(x1-x0+1)+x0,ry=rand()%(y1-y0+1)+y0;fl++;F[fl].x=rx,F[fl].y=ry,F[fl].vx=-(rand()%16+5)/5.0,F[fl].vy=(rand()%41-20)/10.0;F[fl].color=10*(1+rand()%6+1);int r2=rand()%4;if(r2==1) F[fl].color++;}
}
void Creat_Firework_R(int x,int y){fl++;F[fl].x=x,F[fl].y=y,F[fl].vx=(rand()%41-30)/15.0;F[fl].vy=(rand()%16+5)/5.0;F[fl].color=10*(1+rand()%6+1);int r2=rand()%4;if(r2==1) F[fl].color++;}
void Go_Firework(){
    for(int i=1;i<=fl;i++)
    {Setpos(F[i].x,F[i].y),Color(-F[i].color);printf("  ");}
    int up=1,down=38,left=1,right=45;
    float less=0.95,g=0.4;
    for(int i=1;i<=fl;i++)
    {
        F[i].vx+=g;F[i].x+=F[i].vx,F[i].y+=F[i].vy;
        if(F[i].x<up) F[i].x=up,F[i].vx*=-less;
        if(F[i].y<left) F[i].y=left,F[i].vy*=-less;
        if(F[i].x>down) F[i].x=down,F[i].vx*=-less;
        if(F[i].y>right) F[i].y=right,F[i].vy*=-less;
    }
    for(int i=1;i<=fl;i++)
    {Setpos(F[i].x,F[i].y),Color(F[i].color);
    int r2=rand()%4,r3=rand()%3,r4=rand()%8;
    if(r4==0) {printf("  ");continue;}if(r4==1) Color(50);
    if(r3==0) {if(r2==0) printf("��");if(r2==1) printf("��");if(r2==2) printf("��");if(r2==3) printf("��");}
    else {if(r2==0) printf("��");if(r2==1) printf("��");if(r2==2) printf("��");if(r2==3) printf("��");}
    }
}
void TEACH_Board_TEST(int a){//a==1:Left  2:Right  3:Mid  4: All
    Initialization_TYPPER();
    TYPPER_UP();
    if(a==1) Slow_Left(),Spark_Left();
    if(a==2) Slow_Right(),Spark_Right();
    if(a==3) Slow_Mid(),Spark_Mid();
    if(a==4) Slow_All(),Spark_All();
    Print_Hole_TYPPER_None();
    Slow_Frame(17,24,30,43);
    Setpos(19,27);
    if(a==4) Slow("��ӭ�㣡��ս�ߣ���ӭ����"),Setpos(20,27),Slow("�����̱���ƪ ֮ ���տ��顱����");else Slow("���������ʾ�ļ���"),Sleep(200),Setpos(21,27),Slow("�۴�������ͨ�أ�");
    if(a==4) Setpos(22,26),Slow("������ʱ���Զ����ţ�Խ��Խ�죡����");else Setpos(22,27),Slow("������ʱ���Զ����ţ�");Sleep(500);
    Slow_Frame(17,2,23,21);
    memset(Q,0,sizeof(Q));int Que=0,Ft=0,Ti=0,Cleantime=5,t_last_clean,tstart,Tip[4];
    Right_Count=0;Rightmax=10;if(a==4) Rightmax=20;
    Print_Right_Count(20,8);
    while(Right_Count<Rightmax)
    {if(a==4&&Right_Count<=9) Cleantime=5;else if(a==4&&Right_Count<=16) Cleantime=4;else if(a==4) Cleantime=3; 
        Que++;
        if(a==1&&Que>=12) Que=0,memset(Q,0,sizeof(Q));
        if(a==2&&Que>=8) Que=0,memset(Q,0,sizeof(Q));
        if(a==3&&Que>=6) Que=0,memset(Q,0,sizeof(Q));
        if(a==4&&Que>=26) Que=0,memset(Q,0,sizeof(Q));
        Q1:char Que=rand()%26+'A';
        if(Q[Que-'A'+1]==1) goto Q1;
        if(a==1) if(T[N[Que-'A'+1]].left>4) goto Q1;//��֤Ϊǰ���� 
        if(a==2) if(T[N[Que-'A'+1]].left<7) goto Q1;//��֤Ϊ������ 
        if(a==3) if(T[N[Que-'A'+1]].left<=4||T[N[Que-'A'+1]].left>=7) goto Q1;//��֤Ϊ�м����� 
        Q[Que-'A'+1]=1;
        memset(Tip,0,sizeof(Tip));Dark_Frame(23,25,29,42);
    Jump_Que(Que);
        tstart=clock();
    while(1)
    {
        Ti=clock();
    if(Right_Count==0) t_last_clean=Ti;
        if((Ti-t_last_clean)/1000>=Cleantime&&Right_Count>0) Right_Count--,t_last_clean=clock(),Print_Right_Count(20,8); 
        if((Ti-tstart)/1000.0>=1.5&&Tip[1]==0) Tips(Que,1),Tip[1]=1; 
        if((Ti-tstart)/1000.0>=3.5&&Tip[2]==0) Tips(Que,2),Tip[2]=1; 
        if((Ti-tstart)/1000.0>=6&&Tip[3]==0) Tips(Que,3),Tip[3]=1; 
    Color(0);Setpos(19,14);cout<<"Left time:"<<Cleantime-(Ti-t_last_clean)/1000<<' ';
        if(Ft==1) Print_Frame_Line(-71);if(Ft>=1) Ft--;
        char Ans=0;
        if(kbhit()){Ans=_getch();if(Ans>='a'&&Ans<='z')Ans+='A'-'a';if(Ans<'A'||Ans>'Z')Ans=0;}
        if(Ans==Que)
        {
    Print_Located_Key_Char_C(Que,20,3,-20);
            Print_Frame_Line(-20);Ft=10;
            Spark_Key_Right(Ans,L26_Color[Ans-'A'+1],100);
            Print_Local_Key_C(Ans,'?',-70);
            Right_Count++;
            Print_Right_Count(20,8);
            break;
        }
        else if(Ans!=0) 
        {
            Print_Frame_Line(-40);Ft=10;
            Spark_Key_Wrong(Ans,L26_Color[Ans-'A'+1],100);
            Print_Local_Key_C(Ans,'?',-70);
            Print_Right_Count(20,8);
        }
    }
    }
    tstart=clock();int Fl=0;None_Firework();
    while(Ti-tstart<5000)
    {
        Ti=clock();
        if(Ti-tstart<1500) Creat_Firework_R(20,8+Rightmax);
        else if(Fl==0) Creat_Firework_U(20,7,20,9+Rightmax),Fl=1;
        Go_Firework();
        Sleep(50);
    }
    Dark_Frame_L(0,0,39,45);
}
float Sin(int i){return sin(3.1416*i/180);}
float Cos(int i){return cos(3.1416*i/180);}
float Tan(int i){return tan(3.1416*i/180);}
float Si[361],Co[361],Oven[361][3];
void Initialization_Image(){
    for(int i=0;i<=360;i++) Si[i]=Sin(i),Co[i]=Cos(i);
    for(int i=0;i<=360;i++) Oven[i][1]=Sin(i),Oven[i][2]=4*Cos(i);
}
int ArcTan(float xa,float ya,float xo,float yo){//������ʵ���ݼ���
//���ã���ʵ����ȡtan 
//        90
//180--------------0
//        270
    float Xa=ya,Ya=-xa,Xo=yo,Yo=-xo;float Ax=Xa-Xo,Ay=Ya-Yo;
    if(Ay==0&&Ax==0) return 0;//Ĭ�Ϸ����� 
    if(Ay==0&&Xa<Xo) return 180;if(Ay==0&&Xa>Xo) return 0;
    if(Ax==0&&Ya>Yo) return 90;if(Ax==0&&Ya<Yo) return 270;//ֱ������ϵ������ 
    float A=Ay/Ax,Ans;
    for(int i=-89;i<=89;i++) {if(Tan(i)>=A) {Ans=i;break;}}
    if(Ans<0) Ans+=180;
    if(Ya>Yo) return Ans;//��һ2���� 
    if(Ya<Yo) return Ans+180;//��34���� 
}
int Fdx=19,Fdy=25,Fr=10,Fmx=9,Fmy=12;//���ģ�10,13 
int FJ[19][25]={
{0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
{0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0},
{0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0},
{0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,1,1,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,0},
{0,0,1,1,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,2,2,0,2,2},
{0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0},
{0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,2,2,0,0,0},
{1,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,2,2,0,0,0},
{0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0},
{0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0},
{0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0},
{0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0},
{0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0},
{0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0}
};
int FJ1[50][50],FJ2[50][50];
void Print_FJ(int midx,int midy){
    int sx=midx-Fmx+1,sy=midy-Fmy+1;memset(FJ1,0,sizeof(FJ1));memset(FJ2,0,sizeof(FJ2));
    for(int i=0;i<Fdx;i++)
    for(int j=0;j<Fdy;j++){
        int x=sx+i,y=sy+j;
        if(FJ[i][j]==1) Setpos(x,y),Color(-50),cout<<"  ",FJ1[x][y]=1;
        if(FJ[i][j]==2) Setpos(x,y),Color(-20),cout<<"  ",FJ1[x][y]=2;
    }
}
float Dis(float xa,float ya,float xo,float yo){return sqrt((xa-xo)*(xa-xo)+(ya-yo)*(ya-yo));}
int Spin_x(int angle,float xa,float ya,float xo,float yo){int a=ArcTan(xa,ya,xo,yo);a+=angle;int l=Dis(xa,ya,xo,yo);int Ax=Cos(a)*l,Ay=Sin(a)*l;return xo+Ax;}
int Spin_y(int angle,float xa,float ya,float xo,float yo){int a=ArcTan(xa,ya,xo,yo);a+=angle;int l=Dis(xa,ya,xo,yo);int Ax=Cos(a)*l,Ay=Sin(a)*l;return yo+Ay;}
char QA1[8][2][100]={
{{" �� QWER �����ڼ������  "},{"      ���Ͻ�      "}}, 
{{" �� ZXCV �����ڼ������  "},{"      ���·�      "}}, 
{{" �� BNM �����ڼ������   "},{"     ����ƫ��     "}}, 
{{" �� UIOP �����ڼ������  "},{"      ���Ͻ�      "}}, 
{{" �� JKL �����ڼ������   "},{"     �����ҷ�     "}}, 
{{" �� FGH �����ڼ������   "},{"       ����       "}}, 
{{" �� ERTY �����ڼ������  "},{"     ����ƫ��     "}}, 
{{" �� ASDF �����ڼ������  "},{"     ������     "}}
};
char QA2[9][2][100]={
{{"ERTY"},{"   ���Ϸ�����׺��   "}}, 
{{"UIOP"},{"   ���Ͻǣ�Ԫ����   "}}, 
{{"ZXCV"},{"   ���·���Ctrl��   "}}, 
{{"ASDF"},{"  ������,��ָ����  "}}, 
{{"AWSD"},{"  ������, AWSD ��  "}}, 
{{"QWER"},{"   ���Ͻ�, QWER ��   "}}, 
{{"JKL*"},{"  �����ҷ�,��ָ����  "}}, 
{{"BNM*"},{"  ����ƫ��,��ʳָ��  "}}, 
{{"FGHJ"},{"    ���룬�м���    "}}, 
};
bool FJ_Ans,FJ_Q;
void FJ_question(int kind){
    if(kind==1){
        Qq:int q=rand()%8;if(Q[q]==1) goto Qq;Q[q]=1;
        FJ_Ans=rand()%2;
        Ww:int w=rand()%8;if (w==q) goto Ww;
        Setpos(9,7);cout<<QA1[q][0];
        Setpos(11,13);Color(FJ_Color['F'-'A'+1]);if(FJ_Ans==0) cout<<QA1[q][1];else cout<<QA1[w][1];
        Setpos(11,26);Color(FJ_Color['J'-'A'+1]);if(FJ_Ans==1) cout<<QA1[q][1];else cout<<QA1[w][1];
    }
    if(kind==2){
        Qq2:int q=rand()%9;if(Q[q]==1) goto Qq2;Q[q]=1;
        Aa:int r=rand()%4;char a=QA2[q][0][r];if(a=='*') goto Aa; 
        Ww2:int w=rand()%9;if(w==q) goto Ww2;if(String_Belong(a,QA2[w][0])==1) goto Ww2;
        FJ_Ans=rand()%2;
        Setpos(9,7);cout<<"   ���� �� "<<a<<" �� ���ڣ�  ";
        Setpos(11,13);Color(FJ_Color['F'-'A'+1]);if(FJ_Ans==0) cout<<QA2[q][1];else cout<<QA2[w][1];
        Setpos(11,26);Color(FJ_Color['J'-'A'+1]);if(FJ_Ans==1) cout<<QA2[q][1];else cout<<QA2[w][1];
    }
}
void Creat_FJ(int midy,int up,int down){//19,22
    float midx=(up+down)*1.0/2;
    int angle=0,aa=58;float smallr=1;
    while(aa>0){
        if(smallr<=10) smallr+=1;

    float small=smallr*1.0/Fr;
    int sx=midx-Fmx+1,sy=midy-Fmy+1;
    for(int i=0;i<Fdx;i++)
    for(int j=0;j<Fdy;j++){
        if(FJ[i][j]==0)continue;
        int x=sx+i,y=sy+j;
        int xx=Spin_x(angle,x,y,sx+Fmx,sy+Fmy);
        int yy=Spin_y(angle,x,y,sx+Fmx,sy+Fmy);
        int Ax=xx-(Fmx+sx),Ay=yy-(Fmy+sy);
        float ax=Ax*small+(Fmx+sx),ay=Ay*small+(Fmy+sy);
        if(FJ[i][j]==1) FJ1[to(ax)][to(ay)]=1;
        if(FJ[i][j]==2) FJ1[to(ax)][to(ay)]=2;
    }
    for(int i=0;i<50;i++)for(int j=0;j<50;j++){
        if(FJ1[i][j]!=FJ2[i][j]){
        if(FJ1[i][j]==0||aa==1) Setpos(i,j),Color(0),cout<<"  ";
        else if(FJ1[i][j]==1) Setpos(i,j),Color(-50),cout<<"  ";
        else if(FJ1[i][j]==2) Setpos(i,j),Color(-20),cout<<"  ";
        }FJ2[i][j]=FJ1[i][j];
    }memset(FJ1,0,sizeof(FJ1));

        angle+=aa;aa--;if(aa<40) aa-=2;
        Sleep(20);
    }
    Print_FJ(midx,midy);Sleep(500);
    int Wall1=0,Wall2=46;
    while(Wall1<midy||Wall2>midy){
        for(int i=up;i<=down;i++){
            Setpos(i,Wall1);if(FJ1[i][Wall1]==0) Color(-50),cout<<"  ";else Color(0),cout<<"  ";
            Setpos(i,Wall2);if(FJ1[i][Wall2]==0) Color(-20),cout<<"  ";else Color(0),cout<<"  ";
        }if(Wall1<midy) Wall1++;
        if(Wall2>midy) Wall2--;
        Sleep(5);
    }
}
void TEST_FJ(){Initialization_TYPPER();
    Creat_FJ(22,18,39);
    Dark_Frame_L(0,0,17,45);
    Slow_Frame(3,5,16,41);
    Setpos(5,7);Slow("׼����");Sleep(500); Slow("��ʼ��");Sleep(500); Slow("���⣡");Sleep(500); 
    Setpos(5,7);Slow_F("�ж����ͣ�������ʳָ����F��ѡ����߻�ɫѡ���J��ѡ���ұ���ɫѡ��") ;
    Setpos(7,29);Slow("�������۴�������ͨ�أ�");
    Setpos(8,29);Slow("�� ����ʱ���Զ����� ��");Sleep(500);

    int f=N['F'-'A'+1],j=N['J'-'A'+1];T[f].y+=4;T[j].y-=3;FJ_Color['F'-'A'+1]=T9_Color[4];FJ_Color['J'-'A'+1]=T9_Color[6];

    Setpos(7,8);printf("Question:");
    memset(Q,0,sizeof(Q));int Que=0,Ft=0,Ti=0,Cleantime=10,t_last_clean,tstart,Tip[4];
    Right_Count=0;Rightmax=12;
    Print_Right_Count(13,7);
    while(Right_Count<Rightmax)
    {
        Que++;if(Right_Count<=4) FJ_question(1);else FJ_question(2);
        if(Que>=7) Que=0,memset(Q,0,sizeof(Q));

        tstart=clock();
    while(1)
    {
        Ti=clock();
    if(Right_Count==0) t_last_clean=Ti;
        if((Ti-t_last_clean)/1000>=Cleantime&&Right_Count>0) Right_Count--,t_last_clean=clock(),Print_Right_Count(13,7);
    Color(0);Setpos(13,23);cout<<"Left time:"<<Cleantime-(Ti-t_last_clean)/1000<<' ';
        if(Ft==1) Print_Frame_Line_FJ(-71);if(Ft>=1) Ft--;
        char Ans=0;
        if(kbhit()){Ans=_getch();if(Ans=='f'||Ans=='F')Ans=1;else if(Ans=='j'||Ans=='J')Ans=2;else Ans=0;}
        if(Ans==FJ_Ans+1)
        {if(Ans==1) Ans='F';if(Ans==2) Ans='J';
            Print_Frame_Line_FJ(-20);Ft=10;
            Spark_Key_Right(Ans,FJ_Color[Ans-'A'+1],100);
            Print_Local_Key_C(Ans,Ans,-70);
            Right_Count++;
            Print_Right_Count(13,7);
            break;
        }
        else if(Ans!=0) 
        {if(Ans==1) Ans='F';if(Ans==2) Ans='J';
            Print_Frame_Line_FJ(-40);Ft=10;
            Spark_Key_Wrong(Ans,FJ_Color[Ans-'A'+1],100);
            Print_Local_Key_C(Ans,Ans,-70);
            if(Right_Count>0) Right_Count--; 
            Print_Right_Count(13,7);
        }
    }
    }
    tstart=clock();int Fl=0;None_Firework();
    while(Ti-tstart<5000)
    {
        Ti=clock();
        if(Ti-tstart<1500) Creat_Firework_R(13,7+Rightmax);
        else if(Fl==0) Creat_Firework_U(13,7,13,9+Rightmax),Fl=1;
        Go_Firework();
        Sleep(50);
    }
    Dark_Frame_L(0,0,39,45);
}

struct TYPE_WORD{
    char C_name[1000],E_name[1000];//e��ƴ�� 
    int C_last,E_last;//-----------E_name,���㿪ʼ�� 
    int to_be_write;//-----------���㿪ʼ�� 
    int writing;//�Ƿ��������� 
    int error;//�Ƿ��Ѿ���� 
}W[1000];
int Word_num;int Start_x=5,Start_y=5,Start_Gap=3;
void Creat_Word(char c[500],char e[500],int i){for(int j=0;j<500;j++){W[i].C_name[j]=c[j];if(c[j]==0&&W[i].C_last==0) {W[i].C_last=j-1;}if(e[j]==0&&W[i].E_last==0) {W[i].E_last=j-1;}else W[i].E_name[j]=e[j];}W[i].to_be_write=W[i].writing=W[i].error=0;}
void Print_Single_Word(int i){int where=i,x,y;y=Start_y;x=Start_x+(where-1)*Start_Gap;if(W[i].error==0) Color(-20); else Color(-70); Setpos(x-1,y);int Long_Word=0;if(W[i].E_last>=20) Long_Word=1;int S=0,E=W[i].E_last;if(Long_Word==1) S=max(S,W[i].to_be_write-5),E=min(S+20,W[i].E_last);for(int j=S;j<=E;j++){if(j>=W[i].to_be_write||W[i].writing==0) Color(0);if(W[i].writing==1) printf("%c",W[i].E_name[j]);else printf(" ");}Color(0);printf(" ");Setpos(x,y);cout<<W[i].C_name;}
void Print_Empty_Word(int i){int where=i,x,y;y=Start_y;x=Start_x+(where-1)*Start_Gap;Color(0); Setpos(x-1,y);cout<<"                             ";Setpos(x,y);for(int j=0;j<=W[i].C_last;j++) cout<<" ";}
void Delete_Single_Word(int i){memset(W[i].C_name,0,sizeof(W[i].C_name));memset(W[i].E_name,0,sizeof(W[i].E_name));W[i].E_last=W[i].C_last=W[i].to_be_write=W[i].writing=W[i].error=0;}
void Delete_All_Word(){for(int i=1;i<=Word_num;i++) Print_Empty_Word(i),Delete_Single_Word(i);Word_num=0;}
void Print_Gold_Word(int i){int where=i,x,y;y=Start_y;x=Start_x+(where-1)*Start_Gap;Color(-50); Setpos(x-1,y);int Long_Word=0;if(W[i].E_last>=20) Long_Word=1;int S=0,E=W[i].E_last;if(Long_Word==1) S=max(S,W[i].to_be_write-5),E=min(S+20,W[i].E_last);for(int j=S;j<=E;j++){printf("%c",W[i].E_name[j]);}Color(0);printf(" ");Setpos(x,y);cout<<W[i].C_name;Sleep(100);}
void Print_All_Word(){for(int i=1;i<=Word_num;i++) Print_Single_Word(i);}
void Slow_Print_All_Word(){for(int i=1;i<=Word_num;i++) {Print_Single_Word(i);if(Word_num<=3) Sleep(700);else Sleep(50);}}
void Add_Word_Letter(char c[200],char e[200],int i){int l=W[i].E_last,lc=W[i].C_last;bool eend=0,endc=0;
for(int j=0;j<200;j++){lc++;W[i].C_name[lc]=c[j];if(c[j]==0&&endc==0) {W[i].C_last=lc-1;endc=1;}}
for(int j=0;j<200;j++){l++;W[i].E_name[l]=e[j];if(e[j]==0&&eend==0) {W[i].E_last=l-1;eend=1;if(W[i].E_last>=20) Print_Empty_Word(i);}}Print_Single_Word(i);}
int Choose;
void Word_Skill(int a){Choose=a;}
void Delete_Read_Board(){for(int i=1;i<=Word_num;i++){W[i].to_be_write=W[i].writing=W[i].error=0;}}
void Delete_Error(){for(int i=1;i<=Word_num;i++){W[i].writing=1;W[i].error=0;}}
bool Check_All_Error(){bool error;for(int i=1;i<=Word_num;i++){if(W[i].error==0) return 0;}return 1;}
void Check_Letter(char a){
    if(Check_All_Error()) return;
    for(int i=1;i<=Word_num;i++){
        if(W[i].error==0&&W[i].E_name[W[i].to_be_write]==a){
            if(W[i].to_be_write==W[i].E_last){
                Print_Gold_Word(i);
                Word_Skill(i);
                Delete_Read_Board();
            }
            else W[i].to_be_write++,W[i].writing=1;
        }
        else if(W[i].error==0&&W[i].to_be_write!=0&&W[i].E_name[W[i].to_be_write]!=a) W[i].error=1;
    }
}
void Word_Reader(){Print_All_Word();
    while(Choose==0)
    {
        char Ans=0;
        if(kbhit()){
            if(KEY_DOWN(8))
            {
                if(Check_All_Error()) Delete_Error();
                else Delete_Read_Board();
            }
            else {char Ans=_getch();
            if(Ans>='A'&&Ans<='Z') Ans=Ans-'A'+'a';
            if(Ans>='a'&&Ans<='z') Check_Letter(Ans);
            }
        Print_All_Word();
        }
    } 
}
void Add_Level_Word(int level){
if(level==4){
    int r=rand()%9;
    if(r==0) Add_Word_Letter("ai ","ai",1);
    if(r==1) Add_Word_Letter("ei ","ei",1);
    if(r==2) Add_Word_Letter("ao ","ao",1);
    if(r==3) Add_Word_Letter("ou ","ou",1);
    if(r==4) Add_Word_Letter("ia ","ia",1);
    if(r==5) Add_Word_Letter("ie ","ie",1);
    if(r==6) Add_Word_Letter("ua ","ua",1);
    if(r==7) Add_Word_Letter("uo ","uo",1);
    if(r==8) Add_Word_Letter("ue ","ue",1);
}
if(level==6){
    int r=rand()%4;
    if(r==0) Add_Word_Letter("iao ","iao",1);
    if(r==1) Add_Word_Letter("iou ","iou",1);
    if(r==2) Add_Word_Letter("uai ","uai",1);
    if(r==3) Add_Word_Letter("uei ","uei",1);
}
if(level==8){
    int r=rand()%15;
    if(r==0) Add_Word_Letter("an ","an",1);
    if(r==1) Add_Word_Letter("ian ","ian",1);
    if(r==2) Add_Word_Letter("uan ","uan",1);
    if(r==3) Add_Word_Letter("ang ","ang",1);
    if(r==4) Add_Word_Letter("en ","en",1);
    if(r==5) Add_Word_Letter("eng ","eng",1);
    if(r==6) Add_Word_Letter("in ","in",1);
    if(r==7) Add_Word_Letter("ing ","ing",1);
    if(r==8) Add_Word_Letter("un ","un",1);
    if(r==9) Add_Word_Letter("ung ","ung",1);
    if(r==10) Add_Word_Letter("iang ","iang",1);
    if(r==11) Add_Word_Letter("uang ","uang",1);
    if(r==12) Add_Word_Letter("ueng ","ueng",1);
    if(r==13) Add_Word_Letter("ong ","ong",1);
    if(r==14) Add_Word_Letter("iong ","iong",1);
}
}
void Shinning(){
    for(int i=0;i<=8;i++)
    {
        system("color 1A");Sleep(10);
        system("color 2B");Sleep(10);
        system("color 3C");Sleep(10);
        system("color 4D");Sleep(10);
        system("color 5D");Sleep(10);
        system("color 6E");Sleep(10);
        system("color 7F");Sleep(10);
    }system("color 0F");system("cls");
}
void Start_Level(int level){
#define DCS Delete_All_Word();Choose=0;Setpos(13,3);if(level>0) cout<<"Level "<<level<<" : "
//if(level<=3) Choose=1;
if(level==0) {DCS;
Start_x=16;Start_y=5;Start_Gap=2;Word_num=12;
Creat_Word("��ʼ  ��һ���������н̳̣���ѧ���Ƽ���","kaishi",1);
Creat_Word("����ʶ�ǣ�����ϰ��","jian",2);
Creat_Word("  ����ϰ��","wu",3);
Creat_Word("ʶ�ǲ��ԣ�ȫ���̣���ϰ�Ƽ���","shi",4);
Creat_Word("�̾���ϰ������ĸ��ϰ��","duan",5);
Creat_Word("  �̳̣����֣�","jiaochengzuo",6);
Creat_Word("  �̳̣����֣�","jiaochengyou",7);
Creat_Word("  �̳̣����룩","jiaochengzhong",8);
Creat_Word("  ���ԣ��ж��⣩","ceshipan",9);
Creat_Word("  ���ԣ����֣�","ceshizuo",10);
Creat_Word("  ���ԣ����֣�","ceshiyou",11);
Creat_Word("  ���ԣ����룩","ceshizhong",12);
}
    if(level==1) {DCS;cout<<"������    ";Start_x=17;Start_y=5;Word_num=1;Creat_Word("����������","shishishuruwo",1);}
    if(level==2) {DCS;cout<<"��ĸƪ 1 - ��Ԫ��  ";Start_x=17;Word_num=1;Creat_Word("a o e i u ��(v) �������飩","aoeiuvaoeiuvaoeiuv",1);}
    if(level==3) {DCS;cout<<"��ĸƪ 2 - ����ĸ���ϣ�  ";Start_x=17;Word_num=1;Creat_Word("ai ei ao ou ia ie ua uo ue ��ÿ�������飩","aiaiaieieieiaoaoaoouououiaiaiaieieieuauauauouououeueue",1);}
    if(level==4) {DCS;cout<<"��ĸƪ 2 - ����ĸ���ϣ�"<<endl<<"      ��С���̣������������ĸ���ӿ�����׷�ϴ�������ʱ��Ϸ���������������¿�ʼ��ս����";Start_x=17;Word_num=1;Creat_Word("","",1);for(int i=1;i<=5;i++) Add_Level_Word(level);}
    if(level==5) {DCS;cout<<"��ĸƪ 2 - ����ĸ���£�"<<endl<<"                                                                                      ";Start_x=17;Word_num=1;Creat_Word("iao iou uai uei��ÿ�������飩","iaoiaoiaoiouiouiouuaiuaiuaiueiueiuei",1);}
    if(level==6) {DCS;cout<<"��ĸƪ 2 - ����ĸ���£�"<<endl<<"      ��С���̣������������ĸ���ӿ�����׷�ϴ�������ʱ��Ϸ���������������¿�ʼ��ս����";Start_x=17;Word_num=1;Creat_Word("","",1);for(int i=1;i<=4;i++) Add_Level_Word(level);} 
    if(level==7) {DCS;cout<<"��ĸƪ 3 - ����ĸ "<<endl<<"                                                                                          ";Start_x=17;Word_num=1;Creat_Word("an ian uan ang en eng in ing un uen iang uang ueng ong iong��ÿ����һ��ͺã���","anianuanangenenginingunuenianguanguengongiong",1);}
    if(level==8) {DCS;cout<<"��ĸƪ 3 - ����ĸ "<<endl<<"      ��С���̣������������ĸ���ӿ�����׷�ϴ�������ʱ��Ϸ���������������¿�ʼ��ս����";Start_x=17;Word_num=1;Creat_Word("","",1);for(int i=1;i<=4;i++) Add_Level_Word(level);}
    if(level==9) {DCS;cout<<"��һ����ĸ��ɣ�"<<endl<<"                                                                                          ";Start_x=17;Word_num=1;Creat_Word("","",1);char aa[3],bb[3];for(int i=1;i<=26;i++) aa[0]='a'-1+i,bb[0]='A'-1+i,Add_Word_Letter(bb,aa,1);}
    if(level==10) {DCS;cout<<"�ٴ򼸾仰�����Ǿͽ����մ�����     ";Start_x=17;Word_num=1;Creat_Word("Welcome to use Blind TYPPER","welcometouseblindtypper",1);}
    if(level==11) {DCS;cout<<"�ٴ� 10 �仰�����Ǿͽ����մ�����     ";Start_x=17;Word_num=1;Creat_Word("���ߣ�TSzza","zuozhetszza",1);}
    if(level==12) {DCS;cout<<"�ٴ� 9 �仰�����Ǿͽ����մ�����     ";Start_x=17;Word_num=1;Creat_Word("��л��Crab_Dave���Ƴ����Ÿ磬Sam������","mingxiecrabdavetangchaoxuangesamguaishou",1);}
    if(level==13) {DCS;cout<<"�ٴ� 8 �仰�����Ǿͽ����մ�����     ";Start_x=17;Word_num=1;Creat_Word("�ڽ���֮ǰ�����߻��м��仰Ҫ����","zaijieshuzhiqianzuozhehaiyoujijuhuayaojiang",1);}
    if(level==14) {DCS;cout<<"�ٴ� 7 �仰�����Ǿͽ����մ�����     ";Start_x=17;Word_num=1;Creat_Word("ä�򿿵Ĳ���һʱ��ѵ�������ǳ־õĹ���","mangdakaodebushiyishidexunliangengshichijiudegonggu",1);}
    if(level==15) {DCS;cout<<"�ٴ� 6 �仰�����Ǿͽ����մ�����     ";Start_x=17;Word_num=1;Creat_Word("��ƽʱ����ʱ������ʶ�������̣��������ͣ�����ʹ���ڵ�Ŭ�����׷�","zaipingshidazishixiayishibukanjianpanbaochishouxingcainengshixianzaidenulibubaifei",1);}
    if(level==16) {DCS;cout<<"�ٴ� 5 �仰�����Ǿͽ����մ�����     ";Start_x=17;Word_num=1;Creat_Word("�ǳ��������ܴ��ص����ϣ����δ���������ʱ��ʱ��������ٴν��й���"," ",1);}
    if(level==17) {DCS;cout<<"�ٴ� 4 �仰�����Ǿͽ����մ�����     ";Start_x=17;Word_num=1;Creat_Word("����İ汾���ܻ�����£���ȡ���°汾��ַ��luogu.com.cn/blog/z1e2k3i4/","chengxudebanbenkenenghaihuigengxinhuoquzuixinbanbenwangzhiluogucomcnblogzeki",1);}
    if(level==18) {DCS;cout<<"�ٴ� 3 �仰�����Ǿͽ����մ�����     ";Start_x=17;Word_num=1;Creat_Word("...","",1);Print_All_Word();Sleep(1000);Choose=1;}
    if(level==19) {DCS;cout<<"�ٴ� 2 �仰�����Ǿͽ����մ�����     ";Start_x=17;Start_y=2;Word_num=1;Creat_Word("���ڣ�����Ҫ���������Ǹ�ΰ���˲�䣬�����������ʹ�����㽫��ʦ������������Ĵ��ţ�","zhongyuzhongyuyaolaidaolemanageweidadeshunjianchengxujiangwanchengtadeshimingnijiangchushimaichuxinshijiededamen",1);}
    if(level==20) {DCS;cout<<"�ٴ� 1 �仰�����Ǿͽ����մ�����     ";Start_x=17;Start_y=5;Word_num=1;Creat_Word("���ɣ����ɣ���׼�����������մ�����׼���ɣ���ʦ�ɣ�","laibalaibanizhunbeihaolemazuizhongcitiaozhunbeibachushiba",1);}
    if(level==21) {DCS;cout<<"���մ������ˣ���                   ";system("color 6E");Start_x=17;Word_num=1;Creat_Word("�ң�׼�����ˣ������ɣ���","wozhunbeihaolejieshuba",1);}
}
void Go_Level_Word(int level){
    Start_Level(level);Slow_Print_All_Word();
int T,t_last_add;float Speed;
    if(level==4) Speed=1.1;
    else Speed=1.2;
t_last_add=clock();
    while(Choose==0)
    {
        T=clock();
if(level==4||level==6||level==8) {if(((T-t_last_add)/1000>=Speed)&&W[1].error==0) t_last_add=clock(),Add_Level_Word(level);if(W[1].E_last>=50) {W[1].error=1;Sleep(500);Print_Empty_Word(1);Start_Level(level);}}
        char Ans=0;
        if(kbhit()){
            if(KEY_DOWN(8)) {Print_Empty_Word(1);Start_Level(level);}
            else {char Ans=_getch();
            if(Ans>='A'&&Ans<='Z') Ans=Ans-'A'+'a';
            if(Ans>='a'&&Ans<='z') Check_Letter(Ans);
            }
        Print_All_Word();
        }
    } 
}
void TEACH_Board_Word(){Initialization_TYPPER();//Ang  +   Sentense
    Slow_Frame(1,1,11,33);
    Setpos(3,3);Slow("�ã��ã��ã����������ͼ򵥶��ˣ�");Sleep(500);
    Setpos(5,3);Slow("ֻҪ�ٰѳ�����ĸʲô����һ�£��̳̾ͽ����ˣ�");Sleep(500);
    Setpos(7,3);Slow("���ͣ���������û�в����ˣ�");Sleep(500);
    Setpos(9,3);Slow("��ͨ����ؿ������Ǿͳ�ʦ����");Sleep(1000);
    Dark_Frame(2,2,10,32);
    Setpos(3,3);Slow("���򽲽⣺");Sleep(500);
    Setpos(5,3);Slow("1�����������ӦȫƴСд��ĸ����ͨ��");Sleep(500);
    Setpos(7,3);Slow("2������;������󣬴���������ɫ����ʱֻ��ͨ����Backspace��");
    Setpos(9,3);Slow("  �����ȫ�ģ����¿�ʼ���룡");Sleep(500);
    for(int i=1;i<=21;i++){Go_Level_Word(i);} 
}
void Start(){Color(-T9_Color[4]); 
    system("mode con cols=30 lines=9");
    Setpos(2,3);cout<<"Blind TYPPER 1.0.0"; 
    Setpos(3,3);cout<<"      ��������һ�棩"; 
    Setpos(4,3);cout<<"         ���ߣ�TSzza"; 
    Setpos(6,3);Color(T9_Color[4]); cout<<"   ���������ʼ   ";
    char a=_getch();Color(0);
}
int main()
{
    CONSOLE_CURSOR_INFO cursor_info={1,0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
    srand((unsigned)time(NULL));
    Start();
    system("mode con cols=92 lines=41");
STA:system("cls");
    Initialization_TYPPER();//��ʼ��
//    Print_Hole_TYPPER();
    Frame(1,1,13,33);
    Setpos(3,3);Slow_F("�� Ŀ¼ �� ����ѡ����򽲽⣺��������������");
    Setpos(5,3);Slow_F("1�����������ӦȫƴСд��ĸ����ѡ���м���ѡ��ֻ�������֡�");Sleep(500);
    Setpos(7,3);Slow_F("2������;������󣬴���������ɫ����ʱֻ��ͨ����Backspace��");
    Setpos(9,3);Slow_F("  �����ȫ�ģ����¿�ʼ���룡");Sleep(500);
    Setpos(11,3);Slow_F("3��������ƴ�����뷨��Ctrl + �ո� �����л���");Sleep(500);
Go_Level_Word(0);system("color 6E");Sleep(50);system("color 0F");system("cls");
if(Choose==1){
    TEACH_Board_Remember();
    TEST_FJ();
    TEACH_Board_Left();
    TEACH_Board_TEST(1);
    TEACH_Board_Right();
    TEACH_Board_TEST(2);
    TEACH_Board_Mid();
    TEACH_Board_TEST(3);
    TEACH_Board_TEST(4);
    TEACH_Board_Word();
}
if(Choose==2){
    TEACH_Board_Remember();
    TEST_FJ();
    TEACH_Board_Left();
    TEACH_Board_TEST(1);
    TEACH_Board_Right();
    TEACH_Board_TEST(2);
    TEACH_Board_Mid();
    TEACH_Board_TEST(3);
    TEACH_Board_TEST(4);
}
if(Choose==3){
    TEACH_Board_Remember();
    TEACH_Board_Left();
    TEACH_Board_Right();
    TEACH_Board_Mid();
}
if(Choose==4) TEACH_Board_TEST(4);
if(Choose==5) TEACH_Board_Word();
if(Choose==6) TEACH_Board_Left();
if(Choose==7) TEACH_Board_Right();
if(Choose==8) TEACH_Board_Mid();
if(Choose==9) TEST_FJ();
if(Choose==10) TEACH_Board_TEST(1);
if(Choose==11) TEACH_Board_TEST(2);
if(Choose==12) TEACH_Board_TEST(3);
    Shinning();
goto STA;
Sleep(50000);
    return 0;
}
/*
void Level_Shi(){system("cls");
    Setpos(2,2);Color(0);
    Slow("");
    Delete_All_Word();Choose=0;Word_num=5;
    int i=1;Choose=0;Creat_Word("һЩ��û��������","yixieshimeiyourenzuo",1);Word_Reader();
    i++;Choose=0;Creat_Word("һЩ��û��������","yixierenmeiyoushizuo",2);Delete_Single_Word(i-1);Delete_Single_Word(i-1);Word_Reader();
    i++;Choose=0;Creat_Word("һЩû���������������µ������£�","yixiemeiyoushizuodeyilunzuoshidezuodeshi",3);Delete_Single_Word(i-1);Word_Reader();
    i++;Choose=0;Creat_Word("�������µ�����û�£�","yilunzuoshidezongshimeishi",4);Delete_Single_Word(i-1);Word_Reader();
    i++;Choose=0;Creat_Word("һЩ���µ�������������£�","yixiezuoshidezongyouzuobuwandeshi",i);Delete_Single_Word(i-1);Word_Reader();
    i=1;Choose=0;Creat_Word("һЩû�������Ĳ����²����£�","yixiemeiyoushizuodebuzuoshibuaishi",i);Delete_Single_Word(i-1);Word_Reader();
    i++;Choose=0;Creat_Word("һЩ��������������ȴ���鷳�£�","yixieyoushizuodezuoleshiqueyoumafanshi",i);Delete_Single_Word(i-1);Word_Reader();
//  i++;Choose=0;Creat_Word("һЩ��û��������һЩ��û��������","yixieshimeiyoure",i);Delete_Single_Word(i-1);Word_Reader();
//  i++;Choose=0;Creat_Word("һЩ��û��������һЩ��û��������","yixieshimeiyoure",i);Delete_Single_Word(i-1);Word_Reader();
//  i++;Choose=0;Creat_Word("һЩ�����µ��ڿ���˼���£������µ��������£���Ҷ��������ǲ������µ����£�","yixiebuzuoshide",i);Delete_Single_Word(i-1);Word_Reader();
//  i++;Choose=0;Creat_Word("���µ������������ģ������µĲ����¿��ġ�","zuoshidezuobuchengshi",i);Delete_Single_Word(i-1);Word_Reader();
    Level_();
}
*/
