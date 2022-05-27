#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#define randnum(min, max) ((rand() % (int) (((max) + 1) - (min))) + (min))

int map[4][4] ={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};//Ana map.
int mapTemp[4][4]; //Dondurme icin.
int mapTemp2[4][4] ={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};//kontrol  icin.
int skor = 0,sayac = 0;
char tus;

void harita()//Matrisi ekrana basmak icin.
{
    int i,j;
    system("CLS");
    system("color 9f");
    printf(" \n Sag: D   Sol: A   Yukari: W   Asagi: S \n");
    printf(" Yeniden Baslamak Icin : R   Cikmak Icin : Q\n");
    printf(" Puan : %d\n",skor);
    printf("\n");
    for (i = 0; i < 4; ++i)
    {
        //printf("  |--------------------------------|\n");
        for (j = 0; j < 4; ++j)
        {
            printf("%4d ",map[i][j]);
        }
        printf("\n\n");
    }


}

void rastgelesayiatama()//matrisin bos kismina rastgele 2 veya 4 atar.
{
    srand(time(NULL)); //her seferinde random deger atamak icin.
    int a=0,b=0,rastgelesayi,c =NULL;
    c = randnum(0,2); //Random olarak 2 mi 4 mu seciliyor.

    if(c == 1)
    {rastgelesayi = 4;}
    else
    {rastgelesayi = 2;}

    a = randnum(0,3);
    b = randnum(0,3);
    do
    {
        if (map[a][b] == 0)
        {
            map[a][b] = rastgelesayi;
            return;
        } else {
            a = randnum(0, 3);
            b = randnum(0, 3);
            continue;
        }
    } while (map[a][b] != 0);


    map[a][b] = rastgelesayi;



}

void oyunbitme()
{
    printf("Haraket edicek yer kalmadı...\n");
    printf("-----KAYBETINIZ-----\n\n");
    printf("Skorunuz : %d\n",skor);
    printf("Tekrar Baslamak Icin 'R' basiniz.");
    tus = getch();
}

void kaydirma()//sayilari sola kaydirmak icin.
{
    int temp,i,j,k;
    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            if(map[i][j] == 0)
            {
                for ( k=j+1; k < 4; ++k)
                {
                    if(map[i][k] != 0)
                    {
                        temp = map[i][j];
                        map[i][j] = map[i][k];
                        map[i][k] = temp;
                        break;
                    }
                }
            }
        }
    }
}

void toplama()//yan yana ayni olan sayilari toplamak icin.
{
    int i,j;
    for  (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            if(map[i][j] == map[i][j+1])
            {
                map[i][j] *=2;
                skor += map[i][j];
                map[i][j+1] = 0;
            }
            if else()
        }
    }
}

void dondurme(int yon)//Matrisi dondurmek icin.
{
    switch (yon)
    {

        int j,i,k;
        case 0: //bos
            break;
        case 1: //yukarı için "W" 90 derece yukarı
        {
            for (i = 0; i < 4; ++i)
            {
                k =4;
                for (j = 0; j < 4; ++j)
                {
                    k--;
                    mapTemp[k][i] = map[i][j];
                }
            }
            for (i = 0; i < 4; ++i)
            {
                for (j = 0; j < 4; ++j)
                {

                    map[i][j] = mapTemp[i][j];
                }
            }

        }
            break;
        case 2://asağı için "S" 90 derece aşağı
        {
            k = 4;
            for (i = 0; i < 4; ++i)
            {
                k--;
                for (j = 0; j < 4; ++j)
                {
                    mapTemp[j][k] = map[i][j];
                }
            }
            for (i = 0; i < 4; ++i)
            {
                for (j = 0; j < 4; ++j)
                {

                    map[i][j] = mapTemp[i][j];
                }
            }

        }
            break;
        case 3://sağ için "D" 180 derece sağa
        {

            for ( i = 0; i < 4; ++i)
            {
                k = 4;
                for ( j = 0; j < 4; ++j)
                {
                    k--;
                    mapTemp[i][k] = map[i][j];
                }
            }
            for (i = 0; i < 4; ++i)
            {
                for (j = 0; j < 4; ++j)
                {

                    map[i][j] = mapTemp[i][j];
                }
            }
        }
            break;
    }

}

void kontrol()//islem yapamadiginda rastgele sayı gelmesin diye.
{
    int kontrol1= 0,i,j;
    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            if(map[i][j]==mapTemp2[i][j])
            {kontrol1++;}
        }
    }
    if(kontrol1 != 16)
    {
        printf("%d",kontrol1);
        rastgelesayiatama();
    }
    for (i = 0; i < 4; ++i) {
        for ( j = 0; j < 4; ++j) {
            mapTemp2[i][j] = map[i][j];
        }
    }
}

void info()//Oyun hakinda bilgilendirme.
{
    system("CLS");
    system("color 9f");
    printf("Oyunun Amaci :\n");
    printf("W,A,S,D Tuslarini kulanarak karolari dort yonde hareket\netirebilirsiniz:yukari,asagi,sola ve saga.\nTahtadaki tum sayilar duvara carpincaya kadar o yone kayar\nve eger birbirlerine carparlarsa,ayni degere sahiplerse\niki sayi birlestirilir.\nHer sayi, Hamle basina yanlizca bir kez birlestirilicektir.\nHer harekette yeni bir sayi 2 veya 4 belirir. \nTahtada 2048 varsa kazandiniz,ancak tahta doldugunda\nkaybedersiniz ve hamle yapamazsiniz.\n\n");
    printf("Oyuna baslamak icin bir tusa basiniz...");
    getchar();
}

void winkontrol()//Oyuncunun 2048 e ulaşıp ulaşmadığını kontrol eder.
{
    int i,j;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if(sayac == 1)
            {
                printf("Tebrikler Oyunu Kazandiniz.\nDevam etmek icin enter'a  basiniz...\n");
                getchar();
                sayac++;
                break;
            }
            else if(map[i][j] == 2048)
            {
                sayac++;
            }
        }
    }
}



int main()
{

    info();
    harita();
    rastgelesayiatama();

    do {
        harita();
        winkontrol();
        tus = getch();

        switch (tolower(tus)) {
            case 97: // a = 97 sola gitmek icin.
            {
                kaydirma();
                toplama();
                kaydirma();
            }
                break;
            case 115:// s = 115 asagıya gitmek icin.
            {
                dondurme(2);
                kaydirma();
                toplama();
                kaydirma();
                dondurme(1);
            }
                break;
            case 119:// w = 119 yukarıya gitmek icin.
            {
                dondurme(1);
                kaydirma();
                toplama();
                kaydirma();
                dondurme(2);
            }
                break;
            case 100:// d = 100 saga gitmek icin.
            {
                dondurme(3);
                kaydirma();
                toplama();
                kaydirma();
                dondurme(3);
            }
                break;
            case 114:// r = 114 yeniden baslatmak icin.
            {
                int i,j;
                for ( i = 0; i < 4; ++i) {
                    for ( j = 0; j < 4; ++j) {
                        map[i][j] = 0;
                    }
                }
                skor = 0;
                rastgelesayiatama();
            }
                break;
        }
        kontrol();


    }while (tus != 113); // q = 113 cikis icin

    return 0;
}
