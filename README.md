# Game2048
C ile Yazılan Konsol da Oynanan 2048 Oyunu İndirmek İçin Tıkla  ---> [2048game.exe](https://github.com/enesaks/Game2048/raw/master/cmake-build-debug/2048game.exe)

2048 Oyunun Main Kodları  [Main](https://github.com/enesaks/Game2048/blob/master/main.c)

![2048game](https://github.com/enesaks/Game2048/assets/98012557/53ed97e5-cc61-418e-ab7a-b1a11b0a8b3f)


# Game2048 Kodları

Ekrana Matrisi Bastırmak İçin Olan Kod 

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
        for (j = 0; j < 4; ++j)
        {
            printf("%4d ",map[i][j]);
        }
        printf("\n\n");
    }
    }
 
Oyun Kaydırıldığında Rastgele 2 veya 4 atar


    void rastgelesayiatama()//matrisin bos kismina rastgele 2 veya 4 atar.
    {
    int i,j;
    sayac3 = 0;
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            if(map[i][j] != 0)
            {sayac3++;}
        }
    }
    srand(time(NULL)); //her seferinde random deger atamak icin.
    int a=0,b=0,rastgelesayi,c =NULL;
    c = randnum(0,2); //Random olarak 2 mi 4 mu seciliyor.

    if(c == 1)
    {rastgelesayi = 4;}
    else
    {rastgelesayi = 2;}

    a = randnum(0,3);
    b = randnum(0,3);
    if(sayac3 != 16)
    {
        do {
            if (map[a][b] == 0) {
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
    }
    
Sayıları Kadırmak İçin     
'Bu fonksiyon sadece sola kaydırır diğer yönler için matrisi döndürmeiyi kulanıcaz.'

    void kaydirma()//sayilari sola kaydirmak icin.
    {
    int temp,i,j,k;
    sayac2 = 0;
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
            else//Oyuncunun yanıp yanmadıgını anlamak icin.
            {sayac2++;}
        }
    }
    }

Matrisi Döndürmek İçin
'İçine aldığı imputa göre matrisi çevirmek için.'

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

Matrisi kaydırdığımığızda aynı olan sayıları toplamak için olan kod

    void toplama()//yan yana ayni olan sayilari toplamak icin.
    {
    int i,j;
    sayac1 =0;
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
            else//Oyuncunun yanıp yanmadıgını anlamak icin.
            {sayac1++;}
        }
    }
   }
   
Oyunun Main Kodu 
'Switch yapısı kulanılarak W A S D tuşları yardımıyla oynamamızı sağlıyo'

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
        oyunbitme();
        kontrol();

    }while (tus != 113); // q = 113 cikis icin
    return 0;
    }

