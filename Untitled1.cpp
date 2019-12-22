#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void kelimeBul(char **matris, char *girdi);
int sag(char **matris, char *girdi, int y, int x);
int assagi(char **matris, char *girdi, int y, int x);
int sol(char **matris, char *girdi, int y, int x);
int yukari(char **matris, char *girdi, int y, int x);
int main()
{
    char *matris[10], girdi[10], a;
    
    FILE *file;
    
	for(int i = 0; i < 10;i++)
		girdi[i] = '\0';
	
	for(int i = 0; i < 10; i++){
		matris[i] = new char [10];
	}
	// dosya açma...
	if ((file = fopen ("dosya.txt", "r")) == NULL) {
	    printf("Dosya açma hatası!");
	    exit(1);
	}
	
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
        	a = fgetc(file);
        	if(a == '\n')
				matris [i][j] = fgetc(file);
			else
				matris [i][j] = a;
        }
	}
	
	fclose(file);// dosya kapama...
	
	
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            printf("%c ", matris[i][j]);
        }
        printf("\n");
	}
	while(true){
		printf("\n\n\t Lutfen aradiginiz kelimeyi giriniz : ");
		scanf("%s", girdi);
		kelimeBul(matris, girdi);
		printf("\n");
	}
}

void kelimeBul(char **matris, char *girdi){
	int sayac = 0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(girdi[0] == matris[i][j]){
            	int k = sag(matris, girdi, i, j);
				if(k){
					printf("\n Sag    : Baslangic index = (%d, %d), Bitis index = (%d, %d)", j, i, k/10, k%10);
					sayac++;
				}
	            k = assagi(matris, girdi, i, j);
				if(k){
					printf("\n Assagi : Baslangic index = (%d, %d), Bitis index = (%d, %d)", j, i, k/10, k%10);
					sayac++;
				}
	            k = sol(matris, girdi, i, j);
				if(k){
					printf("\n Sol    : Baslangic index = (%d, %d), Bitis index = (%d, %d)", j, i, k/10, k%10);
					sayac++;
				}
	            k = yukari(matris, girdi, i, j);
				if(k){
					printf("\n Yukari : Baslangic index = (%d, %d), Bitis index = (%d, %d)", j, i, k/10, k%10);
					sayac++;
				}
			}
        }
	}
	printf("\nKelime Sayisi : %d", sayac);
}

int sag(char **matris, char *girdi, int y, int x){
	int gUzunlugu = 0, i;
	bool tr = true;
	for(int i = 0; i < 10;i++){
		if(girdi[i] == '\0')
			break;
		else
			gUzunlugu++;
	}
	for(i = x + 1; i< 10; i++){
		if(gUzunlugu <= i - x){
			break;
		}
		else if(matris[y][i] != girdi[i - x]){
			tr = false;
			break;
		}
	}
	if(gUzunlugu > 10 - x)
		tr = false;
	if(tr)
		return ((i - 1) * 10) + y;
	else
		return 0;
}

int assagi(char **matris, char *girdi, int y, int x){
	int gUzunlugu = 0, i;
	bool tr = true;
	for(int i = 0; i < 10;i++){
		if(girdi[i] == '\0')
			break;
		else
			gUzunlugu++;
	}
	for(i = y + 1; i< 10; i++){
		if(gUzunlugu <= i - y){
			break;
		}
		else if(matris[i][x] != girdi[i - y]){
			tr = false;
			break;
		}
	}
	if(gUzunlugu > 10 - y)
		tr = false;
	if(tr)
		return (x * 10) + i - 1;
	else
		return 0;
}

int sol(char **matris, char *girdi, int y, int x){
	int gUzunlugu = 0, i;
	bool tr = true;
	for(int i = 0; i < 10;i++){
		if(girdi[i] == '\0')
			break;
		else
			gUzunlugu++;
	}
	for(i = x - 1; i > 0; i--){
		if(gUzunlugu <= x - i){
			break;
		}
		else if(matris[y][i] != girdi[x - i]){
			tr = false;
			break;
		}
	}
	if(gUzunlugu > x + 1)
		tr = false;
	if(tr)
		return ((i + 1) * 10) + y;
	else
		return 0;
}

int yukari(char **matris, char *girdi, int y, int x){
	int gUzunlugu = 0, i;
	bool tr = true;
	for(int i = 0; i < 10;i++){
		if(girdi[i] == '\0')
			break;
		else
			gUzunlugu++;
	}
	for(i = y - 1; i< 10; i--){
		if(gUzunlugu <= y - i){
			break;
		}
		else if(matris[i][x] != girdi[y - i]){
			tr = false;
			break;
		}
	}
	if(gUzunlugu > y + 1)
		tr = false;
	if(tr)
		return (x * 10) + i + 1;
	else
		return 0;
}



