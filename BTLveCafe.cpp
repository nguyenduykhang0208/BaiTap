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

}
void searchbyname (Hatcafe *hatcafe, int sohatcafe){
    char name [20];
    int count = 0;
    fflush(stdin);
    printf ("\nNhap Ten Hat Can Tim: ");
    gets (name);
    for (int i = 0; i < sohatcafe ; i++){
        if (strcmp (name,(hatcafe+i)->ten) == 0){
            printf ("\nMa Hat: %-4s||Ten Hat: %-25s||Loai Hat: %-15s||Ten Vung Trong: %-20s||Khoi Luong: %-3d||Gia: %-6d",(hatcafe+i)->ma,(hatcafe+i)->ten,(hatcafe+i)->loai,(hatcafe+i)->tenvungtrong,(hatcafe+i)->khoiluong,(hatcafe+i)->gia);
            printf ("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------");
            count ++;
        }
    }
    if(count == 0){
        printf("\nKhong Co Hat Do Trong Kho!");
    }
}
int total (Hatcafe *hatcafe, int sohatcafe){
    int sum = 0;
    for(int i = 0; i < sohatcafe;i ++){
        sum +=((hatcafe+i)->khoiluong);
    }
    return sum;
}
void arrangebynumber (Hatcafe *hatcafe, int sohatcafe){
    Hatcafe temp ;
    for (int i = 0; i < sohatcafe-1; i++){
        for(int j = i+1; j < sohatcafe; j++){
            if ((hatcafe+i)->khoiluong > (hatcafe+j)->khoiluong){
                temp = *(hatcafe+i);
                *(hatcafe+i) = *(hatcafe+j);
                *(hatcafe+j) = temp;
            }
        }
    }
}
void arrangebyname (Hatcafe *hatcafe, int sohatcafe){
    Hatcafe temp;
    for (int i = 0; i < sohatcafe-1; i++){
        for(int j = i+1; j < sohatcafe; j++){
            if (strcmp((hatcafe+i)->ten,(hatcafe+j)->ten) > 0){
                temp = *(hatcafe+i);
                *(hatcafe+i) = *(hatcafe+j);
                *(hatcafe+j) = temp;
            }
        }
    }
}
void quantitativestatistics (Hatcafe *hatcafe, int sohatcafe){
    printf ("\nKhoi Luong Hat Co Trong Kho La: %d",total(hatcafe,sohatcafe));
    printf ("\nTrong Do Co :");
    arrangebynumber (hatcafe,sohatcafe);
    for(int i = 0; i < sohatcafe ; i++){
        printf ("\nKhoi Luong %-3d Ten Hat: %-25s ||Ma Hat: %-4s||Loai Hat: %-15s||Ten Vung Trong: %-20s||Gia: %-6d",(hatcafe+i)->khoiluong,(hatcafe+i)->ten,(hatcafe+i)->ma,(hatcafe+i)->loai,(hatcafe+i)->tenvungtrong,(hatcafe+i)->gia);
        printf ("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------");
    }
}
void namestatistics (Hatcafe *hatcafe, int sohatcafe){
    arrangebyname (hatcafe,sohatcafe);
    for(int i = 0; i < sohatcafe ; i++){
        printf ("\nTen Hat: %-25s||Khoi Luong: %-3d||Ma Hat: %-4s||Loai Hat: %-15s||Ten Vung Trong: %-20s||Gia: %-6d",(hatcafe+i)->ten,(hatcafe+i)->khoiluong,(hatcafe+i)->ma,(hatcafe+i)->loai,(hatcafe+i)->tenvungtrong,(hatcafe+i)->gia);
        printf ("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------");
    }
}
void remove (Hatcafe *hatcafe, int &sohatcafe, char ma[10]){
    bool check = false;
    printf("\nNhap Ma Hat Muon Xoa: ");
    fflush(stdin);
    gets (ma);
    // Dich chuyen mang
    for(int i = 0; i < sohatcafe ; i++){
        if (strcmp (ma,(hatcafe+i)->ma) == 0){
            for (int j = i; j < sohatcafe - 1;j++){
                *(hatcafe+j) = *(hatcafe+j+1);
                check = true;
            } 
            sohatcafe--;
        }
    }
    if (check){
        printf ("\nXoa Hat Thanh Cong!");
    }
    else printf ("\nMa Hat Khong Ton Tai!");
}
void menu (Hatcafe *hatcafe,int sohatcafe,char ma[10],FILE *file, char *path){
    int choice ;
    char k,c ;
    do{
        printf("\n\t\t\t\t\t=======================MENU======================\n");
        printf("\t\t\t\t\t**\t1.Xuat Danh Sach Da Nhap\t        **\n");
        printf("\t\t\t\t\t**\t2.Thong Ke Hat Theo Khoi Luong\t        **\n");
        printf("\t\t\t\t\t**\t3.Thong Ke Hat Theo Ten (A->Z)   	**\n");
        printf("\t\t\t\t\t**\t4.Tim Loai Hat Theo Ten\t        	**\n");
        printf("\t\t\t\t\t**\t5.Xoa Theo Ma Hat\t\t        **\n");
        printf("\t\t\t\t\t**\t6.Xuat Ra File Nhi Phan\t\t        **\n");
        printf("\t\t\t\t\t=================================================\n");
        printf("\t\t\t\t\t\t\t  Your Choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1: print(hatcafe,sohatcafe);
                break;
            case 2:quantitativestatistics(hatcafe,sohatcafe);
                break;
            case 3:namestatistics(hatcafe,sohatcafe);
                break;
            case 4:searchbyname(hatcafe,sohatcafe);
                break;
            case 5:remove(hatcafe,sohatcafe,ma);
                   print (hatcafe,sohatcafe);
                break;
            case 6: outprint (file,path,hatcafe,sohatcafe);
                break;
            default: printf ("\nLua Chon Khong Hop Le! Xin Vui Long Nhap Lai: ");
                break;
        }
        printf("\nDo You Want To Exit ?(esc)");
        k = getch();
        c = k;
    }while(c != 27);
}
void outprint (FILE *file,char *path,Hatcafe *hatcafe,int sohatcafe){
    char *mode = "ab";//NOTE: a:Khi chua có file se tao ra file neu có rr se ghi tiep theo ,b: là binarynumber(nhi phân)
    //mo file 
    file = fopen (path,mode);
    fprintf (file,"Cac Thong Tin Ve Loai Hat Cafe Cuoi Cung La:");
    fprintf (file,"\n============================================================================LIST==============================================================================");
    for (int i = 0; i < sohatcafe ; i++){
        fprintf (file,"\nMa Hat: %-4s||Ten Hat: %-25s||Loai Hat: %-15s||Ten Vung Trong: %-20s||Khoi Luong: %-3d||Gia: %-6d",(hatcafe+i)->ma,(hatcafe+i)->ten,(hatcafe+i)->loai,(hatcafe+i)->tenvungtrong,(hatcafe+i)->khoiluong,(hatcafe+i)->gia);
        fprintf (file,"\n--------------------------------------------------------------------------------------------------------------------------------------------------------------");
    }
    fclose (file);
}
