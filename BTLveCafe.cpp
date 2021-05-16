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
void quantitativestatistics (Hatcafe *hatcafe,int sohatcafe);
void namestatistics (Hatcafe *hatcafe,int sohatcafe);
void remove (Hatcafe *hatcafe,int &sohatcafe, char ma[10]);
void outprint (FILE *file,char *path,Hatcafe *hatcafe,int sohatcafe);
void menu (Hatcafe *hatcafe,int sohatcafe,char ma[10],FILE *file, char *path);
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
void enter (Hatcafe *hatcafe){
    fflush(stdin);
    printf ("Nhap Ma Hat: ");
    gets(hatcafe->ma);
    printf ("Nhap Ten Hat: ");
    gets(hatcafe->ten);
    printf ("Nhap Loai Hat: ");
    gets(hatcafe->loai);
    printf ("Nhap Ten Vung Trong: ");
    gets(hatcafe->tenvungtrong);
    printf ("Nhap Khoi Luong Hat: ");
    scanf("%d",&hatcafe->khoiluong);
    printf ("Nhap Gia Hat: ");
    scanf("%d",&hatcafe->gia);
}
void enter (Hatcafe *hatcafe,int &sohatcafe){
    do {
    printf ("\n\n\t\t\t\t\t\t\tNhap Khoi Luong Hat Trong Kho: ");
    scanf("%d",&sohatcafe);
        if (sohatcafe <= 0||sohatcafe > MAX){
            printf ("Xin Vui Long Nhap Lai!");
            printf ("\nNhap Khoi Luong Hat Trong Kho: ");
            scanf("%d",&sohatcafe);
        }
    }while (sohatcafe <= 0||sohatcafe > MAX);
    hatcafe = (Hatcafe*)realloc(hatcafe,(sohatcafe)*sizeof(Hatcafe));
    for (int i = 0; i < sohatcafe ; i++){
        printf ("\n\n--------------------------------");
        printf ("\nNhap thong tin Hat %d\n",i+1);
        enter(&*(hatcafe+i));
    }
}
void print (Hatcafe *hatcafe){
    printf ("\nMa Hat: %-4s||Ten Hat: %-25s||Loai Hat: %-15s||Ten Vung Trong: %-20s||Khoi Luong: %-3d||Gia: %-6d",hatcafe->ma,hatcafe->ten,hatcafe->loai,hatcafe->tenvungtrong,hatcafe->khoiluong,hatcafe->gia);
}
void print (Hatcafe *hatcafe, int sohatcafe){
    printf ("\n============================================================================LIST==============================================================================");
    for (int i = 0; i < sohatcafe ; i++){
        print(hatcafe+i);
        printf ("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------");
    }
}
