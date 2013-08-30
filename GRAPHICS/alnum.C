
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

struct character
{
char letter;
int n;
int points[10][4];
};

void drawChar(struct character s,int size,int x,int y)
{
int i;
for(i=0;i<s.n;i++)line(x+size*s.points[i][0],y+size*s.points[i][1],x+size*s.points[i][2],y+size*s.points[i][3]);
return;
}

main()
{
int gdriver=DETECT,gmode,i;
char ch,c;
struct character alphabet[]={
			    
			     {'0',4,{0,0,7,0,7,0,7,7,7,7,0,7,0,7,0,0}},
			     {'1',1,{0,0,0,7}},
			     {'2',5,{0,0,7,0,7,0,7,3,7,3,0,3,0,3,0,7,0,7,7,7,}},
			     {'3',4,{0,0,7,0,7,0,7,7,7,7,0,7,0,3,7,3}},
			     {'4',4,{0,0,0,3,0,3,7,3,7,3,7,7,7,0,7,3}},
			     {'5',5,{0,0,7,0,0,0,0,3,0,3,7,3,7,3,7,7,7,7,0,7}},
			     {'6',5,{0,0,7,0,0,0,0,7,0,7,7,7,7,7,7,3,7,3,0,3}},
			     {'7',2,{0,0,7,0,7,0,7,7}},
			     {'8',5,{0,0,7,0,0,3,7,3,0,7,7,7,0,0,0,7,7,0,7,7}},
			     {'9',4,{0,0,7,0,7,0,7,7,0,0,0,3,0,3,7,3}},
			     {'A',3,{0,7,3,0,3,0,7,7,2,3,5,3}},
			     {'B',8,{0,0,0,7,0,0,5,0,5,0,7,2,7,2,5,4,5,4,0,4,5,4,7,6,7,6,5,7,5,7,0,7}},
			     {'C',3,{7,0,0,0,0,0,0,7,0,7,7,7}},
			     {'D',4,{0,0,7,0,7,0,7,7,7,7,0,7,2,0,2,7}},
			     {'E',4,{0,0,7,0,0,4,6,4,0,7,7,7,0,0,0,7}},
			     {'F',3,{0,0,7,0,0,4,6,4,0,0,0,7}}
			    };
initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
while(1)
{
printf("Enter the character\n");
scanf("\n%c",&ch);
switch(ch)
{
case '0':drawChar(alphabet[0],5,100,100);
	 break;
case '1':drawChar(alphabet[1],5,100,100);
	 break;
case '2':drawChar(alphabet[2],5,100,100);
	 break;
case '3':drawChar(alphabet[3],5,100,100);
	 break;
case '4':drawChar(alphabet[4],5,100,100);
	 break;
case '5':drawChar(alphabet[5],5,100,100);
	 break;
case '6':drawChar(alphabet[6],5,100,100);
	 break;
case '7':drawChar(alphabet[7],5,100,100);
	 break;
case '8':drawChar(alphabet[8],5,100,100);
	 break;
case '9':drawChar(alphabet[9],5,100,100);
	 break;
case 'A':drawChar(alphabet[10],5,100,100);
	 break;
case 'B':drawChar(alphabet[11],5,100,100);
	 break;
case 'C':drawChar(alphabet[12],5,100,100);
	 break;
case 'D':drawChar(alphabet[13],5,100,100);
	 break;
case 'E':drawChar(alphabet[14],5,100,100);
	 break;
case 'F':drawChar(alphabet[15],5,100,100);
	 break;
case 'Z':exit(0);
	 break;
}
getch();
clrscr();
cleardevice();
}
getch();
return;
}