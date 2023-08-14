#include<iostream>
#include"console.h"
#include <cstdlib>
#include <string>
#include <cmath>
#include <conio.h>
using namespace std;
struct moto
{
 char kytu;
 int mau;
};
moto buffer[25][77];
void gano(int x,int y,char c,int mamau=13)
{
 buffer[y][x].kytu=c;
 buffer[y][x].mau=mamau;
}
void khoi_tao_buffer()
{
 for(int i=0;i<25;i++)
  for(int j=0;j<77;j++)
   gano(j,i,' ');
}
void ve_ban_co()
{
 for(int i=0;i<25;i++)
 {
  if(i%2==0)
  {
   for(int j=0;j<77;j++)
    if(j%4==0) gano(j,i,197);
    else gano(j,i,196);
  }
  else
  {
   for(int j=0;j<77;j++)
    if(j%4==0) gano(j,i,179);
  }
 }
}
char ban_co[12][19];
void khoi_tao_ban_co()
{
 for(int i=0;i<12;i++)
  for(int j=0;j<19;j++)
   ban_co[i][j]=' ';
}
void hien_thi(int x,int y)
{
 //reset buffer
 khoi_tao_buffer();
 //ve ban co len buffer
 ve_ban_co();
 //in cac quan co cua ban co len buffer
 for(int i=0;i<12;i++)
  for(int j=0;j<19;j++)
   gano(2+j*4,1+i*2,ban_co[i][j]);
 //in con tro len buffer
 gano(x-1,y,buffer[y][x-1].kytu,176);
 gano(x,y,buffer[y][x].kytu,176);
 gano(x+1,y,buffer[y][x+1].kytu,176);
 //in buffer ra console
 gotoXY(0,0);
 for(int i=0;i<25;i++)
 {
  for(int j=0;j<77;j++)
  {
   TextColor(buffer[i][j].mau);
   putchar(buffer[i][j].kytu);
  }
  if(i<24) putchar('\n');
 }
}
int dieu_khien(int &x,int &y,int &nguoi)
{
 int key=inputKey();
 if(key==key_Up && y>=3){ y-=2;return 1;}
 else if(key==key_Down && y<=21){ y+=2;return 1;}
 else if(key==key_Left && x>=6){ x-=4;return 1;}
 else if(key==key_Right&& x<=70){ x+=4;return 1;}
 else if(key==13)
 {
  if(nguoi==1 && ban_co[(y-1)/2][(x-2)/4]==' ')
  {
   ban_co[(y-1)/2][(x-2)/4]='X';
   nguoi=0;
   return 1;
  }
  else if(ban_co[(y-1)/2][(x-2)/4]==' ')
  {
   ban_co[(y-1)/2][(x-2)/4]='O';
   nguoi=1;
   return 1;
  }
  return 0;
 }
 return 0;
}
int xet_thang_thua(int x ,int y)
{
 int dem,i,j,h,c;
 c=(x-2)/4;
 h=(y-1)/2;
 if(ban_co[h][c]==' ') return 2;
 //xet hang ngang
 dem=0;
 for(j=c;j>=0;j--){
  if(ban_co[h][j]!=ban_co[h][c]) break;
  else dem++;
 }
 for(j=c+1;j<19;j++){
  if(ban_co[h][j]!=ban_co[h][c]) break;
  else dem++;
 }
 if(dem>=5)
 {
  if(ban_co[h][c]=='X') return 1;
  else return 0;
 }
 //xet hang doc
 dem=0;
 for(int i=h;i>=0;i--){
  if(ban_co[i][c]!=ban_co[h][c]) break;
  else dem++;
 }
 for(i=h+1;i<12;i++){
  if(ban_co[i][c]!=ban_co[h][c]) break;
  else dem++;
 }
 if(dem>=5)
 {
  if(ban_co[h][c]=='X') return 1;
  else return 0;
 }
 //xet duong cheo len
 dem=0;
 for(i=h,j=c;i>=0 && j<19;i--,j++){
  if(ban_co[i][j]!=ban_co[h][c]) break;
  else dem++;
 }
 for(i=h+1,j=c-1;i<12,j>=0;i++,j--){
  if(ban_co[i][j]!=ban_co[h][c]) break;
  else dem++;
 }
 if(dem>=5)
 {
  if(ban_co[h][c]=='X') return 1;
  else return 0;
 }
 //xet duong cheo xuong
 dem=0;
 for(i=h,j=c;i<120 && j<19;i++,j++){
  if(ban_co[i][j]!=ban_co[h][c]) break;
  else dem++;
 }
 for(i=h-1,j=c-1;i>=0,j>=0;i--,j--){
  if(ban_co[i][j]!=ban_co[h][c]) break;
  else dem++;
 }
 if(dem>=5){
  if(ban_co[h][c]=='X') return 1;
  else return 0;
 }
 for(i=0;i<12;i++)
  for(j=0;j<19;j++)
   if(ban_co[i][j]==' ') return 2;
 return 3;
}
//

}
