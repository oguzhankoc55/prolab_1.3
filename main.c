#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct dugum{                                          //Bagli listeyi olusturmak icin kullanilan struct
	int adet;                                          //Metinde gecen kelimelerin kac defa tekrarladiklarinin degerini tutar 
	char *S_kelime;                                    //Metinde gecen kelimelerin adreslerini tutar
	struct dugum *sonraki;                             //Bir sonraki dugumun adresini tutar
};

struct dugum* baslangic=NULL;           
struct dugum* q=NULL;
int enBuyuk=0;
int enKucuk=0;

int say(char *deneme1){                                 //Gonderilen kelime fonksiyon icinde olusturulan metin belgesindeki
FILE *f;                                                //kelimelerle teker teker karsilastirilarak kelimenin adeti bulunur
f=fopen("Deneme.txt", "r");             
char *charPointer =(char *)malloc(sizeof(char)*1000);
int sayi=0;
while (fgets(charPointer,1000,f)!=NULL) {
    char *kelime=NULL;
    kelime = strtok (charPointer," ");
    while (kelime != NULL){
        if(strcmp(deneme1,kelime)==0){
            sayi++;}
        kelime = strtok (NULL, " ");
    }}
return sayi;
}

int ozelMi(char *kelime){                                //Gonderilen kelime bagli listedeki dugumlerle karsilastirilir
q=baslangic;                                             //Kelime bagli listede bulunuyorsa 0 degeri gonderilir
if(q==NULL){                                             //Kelime bagli listede bulunmuyorsa 1 degeri gonderilir
    return 1;}
if(strcmp(q->S_kelime,kelime)==0){
		return 0;}
if(q->sonraki==NULL){
		return 1;}
if(strcmp(q->sonraki->S_kelime,kelime)==0){
		return 0;}
while(q->sonraki!=NULL ){
    if(strcmp(q->S_kelime,kelime)==0){
        return 0;}
		q=q->sonraki;}
return 1;
}

void basaEkle( char *kelime){                            //Alinan kelimenin degerlerini  olusturulan baslangic dugumune atamasi yapilir
struct dugum *basa_eklenecek_dugum=(struct dugum*)malloc(sizeof(struct dugum));
basa_eklenecek_dugum->S_kelime=(char *)malloc(sizeof(char)*20);
for(int i=0;*(kelime+i)!='\0';i++){                      //Alinan kelimenin harflerini teker teker adrese atamasi yapilir
    if(*(kelime+i)!='\n' && *(kelime+i)!=' '){           //Bosluk veya satir sonunda donguden cikar
        *(basa_eklenecek_dugum->S_kelime+i)=*(kelime+i);}
    *(basa_eklenecek_dugum->S_kelime+i+1)='\0';          
	}
basa_eklenecek_dugum->adet=say(kelime);
basa_eklenecek_dugum->sonraki=baslangic;
baslangic=basa_eklenecek_dugum;
}

void arayaEkle(char *kelime){                            //Alinan kelimenin degerlerini kelimenin adet sayisi buyuklugne gore atamasi yapilir
struct dugum* araya_eklenecek_dugum=(struct dugum*)malloc(sizeof(struct dugum));
araya_eklenecek_dugum->S_kelime=(char *)malloc(sizeof(char)*20);
for(int i=0;*(kelime+i)!='\0';i++){                      //Alinan kelimenin harflerini teker teker adrese atamasi yapilir
    if(*(kelime+i)!='\n' && *(kelime+i)!=' '){           //Bosluk veya satir sonunda donguden cikar
        *(araya_eklenecek_dugum->S_kelime+i)=*(kelime+i);}
    *(araya_eklenecek_dugum->S_kelime+i+1)='\0';}
	araya_eklenecek_dugum->adet=say(kelime);
	q=baslangic;
	while(q->sonraki->adet>=say(kelime)){                //Kelimenin adet sayisinin buyuklugunun karsilastirilmasiyla gereken konum bulunur
		q=q->sonraki;}
	struct dugum* onune=(struct dugum*)malloc(sizeof(struct dugum));
	onune=q->sonraki;
	q->sonraki=araya_eklenecek_dugum;
	araya_eklenecek_dugum->sonraki=onune;
}

void sonaEkle(char *kelime){                             //Alinan kelimenin degerlerini  olusturulan son dugume atamasi yapilir
struct dugum* sona_eklenecek_dugum = (struct dugum*)malloc(sizeof(struct dugum));
sona_eklenecek_dugum->S_kelime=(char *)malloc(sizeof(char)*20);
for(int i=0;*(kelime+i)!='\0';i++){                      //Alinan kelimenin harflerini teker teker adrese atamasi yapilir
    if(*(kelime+i)!='\n' && *(kelime+i)!=' '){           //Bosluk veya satir sonunda donguden cikar
        *(sona_eklenecek_dugum->S_kelime+i)=*(kelime+i);}
    *(sona_eklenecek_dugum->S_kelime+i+1)='\0';}
sona_eklenecek_dugum->adet=say(kelime);
sona_eklenecek_dugum->sonraki=NULL;
if(baslangic==NULL){                                     //Baslangic dugumu yoksa alinan kelimeyi baslangic degerine atar
    baslangic=sona_eklenecek_dugum;}
else{
    q=baslangic;
while(q->sonraki!=NULL){
    q=q->sonraki;}
q->sonraki=sona_eklenecek_dugum;}
}

void ekle(char *kelime1){                                                    //Alinan kelime yapilan degerlendirmeler sonucu bagli listeye eklemesi yapilir	
    if(ozelMi(kelime1) && say(kelime1)>=1){                                 //Kelimenin bagli listede olup olmadigina bakilir                                   
            if( say(kelime1)>enBuyuk){                                       //Alinan kelimenin adet sayisi alinan en buyuk adet sayisiyla kiyaslanir
                basaEkle(kelime1);
                enBuyuk=say(kelime1);                                       //En buyuk deger atama yapilir  
                if(enKucuk==0){
                    enKucuk=say(kelime1);}		                             //Bagli listenin olusturulduktan sonraki en kucuk deger atama yapilir        
            }else if( say(kelime1)<=enKucuk){	                              //Alinan kelimenin adet sayisi alinan en kucuk adet sayisiyla kiyaslanir
                sonaEkle(kelime1);
                enKucuk=say(kelime1);                                            //En kucuk deger atama yapilir  
            }else if(say(kelime1)>enKucuk &&  say(kelime1)<=enBuyuk){            //Kelimenin adet sayisinin istenilen aralikta 
                arayaEkle(kelime1);}}                                            //olup olmadigina bakilir
}

void yazdir(){                                                       //Bagli listenin dugumlerinin istenilen degerleri yazdirilir
	q=baslangic;
	int i=1;
	while(q->sonraki!=NULL){
		printf("%d-)%s => %d\n ",i,q->S_kelime,q->adet);
		q=q->sonraki;
		i++;}
	printf("%d-)%s => %d\n ",i,q->S_kelime,q->adet);
}
int main(){
	
FILE *f;
FILE *f1;
f=fopen("Deneme.txt", "r");
f1=fopen("Deneme1.txt", "w");
char *charPtr =(char *)malloc(sizeof(char)*1000);
while (fgets(charPtr,1000,f)!=NULL) {                    //Alinan metin duzenlenerek tekrardan baska bir metin belgesine atilir
    char *kelime=NULL;
    kelime = strtok (charPtr," ");
    while (kelime != NULL){
        fprintf(f1,"%s \n",kelime);
        kelime = strtok (NULL, " ");}}
fclose(f);
fclose(f1);
f1=fopen("Deneme1.txt", "r");
char *kelime1=NULL; 
while (fgets(charPtr,1000,f1)!=NULL) {                  //Olusturulan metin belgesindeki kelimeler islem yapilmasi icin fonksiyonlara                                   //gonderilir
kelime1 = strtok (charPtr," ");
ekle(kelime1);}
fclose(f1);	
yazdir();
return 0;
}
