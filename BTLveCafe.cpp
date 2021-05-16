#include <stdio.h>>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

struct Hatcafe{
    char ma [10];
    char ten[20];
    char loai[30];
    char tenvungtrong[20];    
    int khoiluong;
    int gia;
};
void enter (Hatcafe *hatcafe);
void enter (Hatcafe *hatcafe, int &sohatcafe); 
void print (Hatcafe *hatcafe);
void print (Hatcafe *hatcafe,int sohatcafe); 
void searchbyname (Hatcafe *hatcafe,int sohatcafe);
int total (Hatcafe *hatcafe,int sohatcafe);
void arrangebynumber (Hatcafe *hatcafe,int sohatcafe);
void arrangebyname (Hatcafe *hatcafe,int sohatcafe);
void quantitativestatistics (Hatcafe *hatcafe,int sohatcafe);//thong kê theo so luong
void namestatistics (Hatcafe *hatcafe,int sohatcafe);//thong kê theo tên sách
void remove (Hatcafe *hatcafe,int &sohatcafe, char ma[10]);//Nhap mã can xóa tu bàn phím tu dó xóa nhung thông tin liên quan den mã sách dó
void outprint (FILE *file,char *path,Hatcafe *hatcafe,int sohatcafe);//Xuat nhung quyen sách ra file nhi phân
void menu (Hatcafe *hatcafe,int sohatcafe,char ma[10],FILE *file, char *path);//menu de lua chon
int main (){
    Hatcafe *hatcafe;
    FILE *file;
    int sohatcafe;
    char ma[10];   
    char *path = "./src/BTLTT/outfile/print.out";
    hatcafe = (Hatcafe *)malloc(sizeof(Hatcafe));
    enter (hatcafe,sohatcafe);
    menu (hatcafe,sohatcafe,ma,file,path);
    if(hatcafe != NULL)
    free (hatcafe);
    return 0;
}
