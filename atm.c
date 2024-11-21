#include <stdio.h>
#include <time.h>

int main() {
    int pin = 1881, girilenPin, denemeSayisi = 0;
    const int maxDeneme = 3;
    int islem, tutar, bakiye = 3800;
    char isim[30];
    char islem_bidaha = 'e';
    time_t now;
    time(&now);

    struct tm *local = localtime(&now);
    printf("Saat %02d:%02d:%02d\n", local->tm_hour, local->tm_min, local->tm_sec);

    while (denemeSayisi < maxDeneme) {
        printf("Lutfen 4 haneli pin kodunuzu giriniz:\n");
        scanf("%d", &girilenPin);

        if (girilenPin == pin) {
            printf("\nPin kodu dogru! Islem yapabilirsiniz.\n");
            break;
        } else {
            printf("Pin kodunuz yanlis, lutfen tekrar deneyiniz.\n");
            denemeSayisi++;
        }
        if (denemeSayisi == maxDeneme) {
            printf("\nMaksimum deneme sayisina ulasildi. Lutfen isleminizi sonlandiriniz.\n");
            return 0;
        }
    }

    do {
        printf("\nLutfen yapmak istediginiz islemi seciniz:\n1=Para Cekme\n2=Para yatirma\n3=Havale/EFT/FAST\n4=Bakiye Sorgulama\n5=Kart Iade\n");
        printf("\nIslem seciniz:");
        scanf("%d", &islem);

        switch (islem) {
            case 1:
                do {
                    printf("\nBakiyeniz = %d\n", bakiye);
                    printf("Cekmek istediginiz tutari giriniz: \n");
                    scanf("%d", &tutar);

                    if (tutar > bakiye) {
                        printf("Yetersiz miktar girdiniz, lutfen tekrar deneyiniz.\n");
                    }
                } while (tutar > bakiye);

                bakiye -= tutar;
                printf("Yeni bakiyeniz = %d", bakiye);
                break;

            case 2:
                printf("\nBakiyeniz = %d\n", bakiye);
                printf("Yatirmak istediginiz tutari giriniz: \n");
                scanf("%d", &tutar);
                bakiye = bakiye + tutar;
                printf("Yeni bakiyeniz = %d", bakiye);
                break;

            case 3:
                printf("\nBakiyeniz = %d\n", bakiye);
                printf("Havale yapmak istediginiz kisinin ismini ve gondereceginiz tutari yaziniz:\n");
                scanf("%s%d", isim, &tutar);
                if (tutar <= bakiye) {
                    printf("\n%s kisisine %dTL basariyla gonderilmistir.\n", isim, tutar);
                    bakiye -= tutar;
                    printf("\nYeni bakiyeniz = %d", bakiye);
                } else {
                    printf("Yuksek miktar girdiniz!\n");
                }
                break;

            case 4:
                printf("\nBakiyeniz = %d\n", bakiye);
                break;

            case 5:
                printf("Kartinizi almayi unutmayin!\n");
                islem_bidaha = 'h'; 
                break;

            default:
                printf("\nSectiginiz rakamda islem yoktur lutfen tekrar deneyiniz.");
        }

        if (islem != 5) { 
            printf("\n\nYapmak istediginiz baska bir islem var mi? (e/h): \n");
            getchar();
            scanf("%c", &islem_bidaha);
        }
    } while (islem_bidaha == 'e' || islem_bidaha == 'E');

    return 0;
}

