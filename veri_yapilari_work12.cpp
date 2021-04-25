// Odev 1
// Ogrenci1 No: 1030516450
// Ogrenci1 Ismý: MEHMET BÖYÜK

// Ogrenci2 No: 1030520733
// Ogrenci2 Ismý: ÝHSAN KONARGÖÇER

//Ogrenci3 No: 1030522950	
//Ogrenci3 Ismi: ÖMER FARUK ERENLER

//Ogrenci4 No: 1030520678
//Ogrenci4 Ismi: SUZAN ÖZDOÐAN

//Ders Kodu: BZ205
//Dosya Ismi: veri_yapilari_work12


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
//PROGRAMLAMA
struct n {
	int data;
	char *ders;
	char *ad;
	char *soyad;
	int numara;
	char *bolum;
	int alinmaSayisi;
	n * sol;
	n * sag;
	n * next;
	n * prev;
};
typedef n node;
//VERI YAPILARI
struct m {
	int x;
	char *ders;
	char *ad;
	char *soyad;
	int numara;
	char *bolum;
	int alinmaSayisi;
	m * next;
	m * prev;
	m * svc;
	m * sol;
	m * s1;
	m * s2;
	m * sag;
	
};
typedef m bnode;
int silSay(bnode * r)
{
	int i=0;
	while(r!=NULL)
	{
		i++;
		r=r->next;
	}
	return i;
}
int say(bnode * r)
{
	int i=0;
	while(r!=NULL)
	{
		i++;
		r=r->next;			
	}
	return i;
	
}
void bbastir(bnode * r)
{
	while(r!=NULL)
	{
		printf("%d \n",r->numara);
		r=r->next;	
	}
	
}
bnode * dugumBol(bnode * r)
{														//kokOlustur fonsiyonundan b+ agaci alinir.
	bnode * yenikok;									//Burada bolme islemi usulune gore yapilir.
	bnode * l;											//Elde edilen yeni agac dondurulur.
	l=yenikok;
	l=NULL;
	yenikok=NULL;
	if(say(yenikok)!=0)// burasý hatalý burayý çöz en son
	{		
		bnode * k;		
		k=yenikok->s1;
		yenikok->next=(bnode *)malloc(sizeof(bnode));		
		yenikok->next=k->next->next;
		yenikok->s2=k->next->next;
		yenikok->s2->next=k->next->next->next;
		printf("\n----%d-------\n",yenikok->s2->x);
		return yenikok;
		 
	}
	else
	{	
		yenikok=(bnode *)malloc(sizeof(bnode));
		yenikok=r->next->next;
		yenikok->sol=r;
		yenikok->sol->next=r->next;
		yenikok->s1=r->next->next;
		yenikok->s1->next=r->next->next->next;
		return yenikok;
		
	}

}
bnode * kokOlustur(bnode * r,int x,char * bolum)
{	
//	node * iter;										//Oncelikle main fonsiyonundan b+ agacini, eklencek degerleri aliyoruz.
	bnode * iter2;										//Eger kok bos ise bellekte yer tahsis ediyoruz ve verileri 
	iter2=r;											//tahsis edilen yere atiyoruz.
	if(r==NULL)											//Eger kok dolu ise iki durum karsimiza cikiyor.
	{													//1. eklenecek eleman eklenen elemandan buyuk
	//	printf("list bossa\n");							//2. eklenecek eleman eklenen elemandan kucuk
		r=(bnode *)malloc(sizeof(bnode));				//1. durumda kok dolana kadar kucukten buyuge dogru ekleme islemi yapiliyor.
		r->numara=x;									//2. durumda ise duzenlenerek ekleme islemi yapiliyor.
		r->bolum=bolum;									//Eger kok doldu ise dugumBol'e kok gonderiliyor.
		//iter=r;										//Eleman gedikce ekleme islemi devam ediyor.
		r->next=NULL;									//Koku dolma durumu ise say fonsiyonuna kok gonderilerek ogrenilir.
		//iter=r;
		return r;
	}
	
	else //if(r->next==NULL)
	{	
		if(r->numara>x)
		{
			bnode * temp=(bnode *)malloc(sizeof(bnode));
			temp->numara=x;
			temp->bolum=bolum;
			temp->next=r;
			return temp;
	
		}
		else
		{
			bnode * iter=r;
				
			while(iter->next!=NULL&& iter->next->numara<x)
			{
				iter=iter->next;
			}
			bnode * temp=(bnode *)malloc(sizeof(bnode));
			temp->next=iter->next;
			iter->next=temp;
			temp->numara=x;
			
			temp->bolum=bolum;
			//return r; buraya bak
			
		
			if(say(r)==4)
			{
				dugumBol(r);
				return r;
			}
			else
			{
				return r;	
			}		
		}
			
	}
	
}
bnode * dugumBirlestir(bnode * r)
{												//bSil fonksiyonundan gelen b+ agacýnda az olan dugumler birlestirilir.
	bnode * yenikok;							
	yenikok=r;									
	yenikok->sol=r;								
	yenikok->sol->next=r->next;
	yenikok->s1=r->next->next;
	yenikok->s1->next=r->next->next->next;
	yenikok=r->next->next;	
	return yenikok;
}
bnode * bSil(bnode * r,int x)
{												//b+ agaci ve silinecek eleman b+ agacinda bulunur.
	bnode * temp;								//Temp degiskeni olusturulur.
	bnode * iter=r;								//Temp degiskeni silinecek elemandan sonraki elemana baglanir.
	bnode * k;									//Eleman silinir.
	if(r->numara==x)							//Eger agacta istenilenden az eleman kaldi ise
	{											//Dugum birlestir fonkisiyonuna b+ agaci gonderilir 
		temp=r;									//ve dugum birlestirme islemi yapilir.
		r=r->next;								//Yine silinecek eleman bulunamssa 'sayi bulumadi' uyarisi verir.
		free(temp);
		k=r;
	//	k->next=NULL;
		if(silSay(k)==0)
		{
			printf("****");
			r=dugumBirlestir(r);
			return r;
		}
		return r;
	}
	while(iter->next !=NULL && iter->next->x!=x)
	{
		iter=iter->next;
	}
	if(iter->next==NULL)
	{
		printf("sayi bulunamadi\n");
		return r;
	}
	temp=iter->next;
	iter->next=iter->next->next;
	free(temp);
	if(iter->next!=NULL)
	{
		iter->next->prev=iter;	
	}
	return r;
}
void bkontrol(bnode * iter)
{
	int i,j;									//Her iki derside birden fazla kez alan ogrencileri listelemek icin kullanilir.			
	bnode * iter2;								//b+ agacinin her bir elamni kendisi haric tum elemanlar ile karsilastirilir.
	iter2=iter->next;							//Eger ayni eleman var ise bu ogrenci bu dersi birden fazla kez almistir.
	while(iter->next!=NULL)						//Bu ogrenciler bastirilir.
	{
		while(iter2!=NULL)
		{
			if(iter->numara==iter2->numara)
			{
				printf("%d\n",iter->numara);
				iter2=iter2->next;
			}
			else
			{
				
				iter2=iter2->next;
			}
		}
		iter=iter->next;
		iter2=iter->next;
	}
}

void bastir(node * r)
{
	while(r!=NULL)
	{
		printf("%s %s %d %s \n",r->ad,r->soyad,r->numara,r->bolum);
		r=r->next;	
	}
	
}

node * siraliEkle(node * r,int x,char *ad, char *soyad,char * bolum)
{

	if(r==NULL)													
	{											//Main fonksiyonundan root,ad,soyad,bolum bilgileriniz aliyoruz.
		r=(node *)malloc(sizeof(node));			//Eger kok bos ise bellekte yer tahsis ediyoruz.
		r->next=NULL;							//Tahsis ettigimiz yerin next'i NULL ve prev'i NULL oluyor.(cift yonlu bagli liste oldugu icin)
		r->prev=NULL;							//Eger kok dolu ise gelen degerin kokun gosterdigi degerden buyuk olma durumu kontrol ediliyor.
		r->numara=x;							//Eger gelen deger kokten kucuk ise en basa ekliyor, yani r'nin gosterdigi deger degisiyor.
		r->ad=ad;								//Eger gelen deger buyuk ise 2 durum karsimiza cikiyor.1.ortaya ekleme 2.sona ekleme.
		r->soyad=soyad;							//Ortaya eklenecekse; bellekten yer tahsis ediliyor ve tahsis edilen yer
		r->bolum=bolum;							//Onceki degere baglaniyor, tahsis edilen yer ise sonraki degere baglaniyor.												
		return r;								//2.durumda ise en sona ekliyor ve eklenen degerin next'ini NULL yapiyor.
	}											//Boylece sirali ekleme islemimiz tamamalanmis oluyor.
	if(r->numara>x)//basa ekleniyor
	{
		node * temp=(node *)malloc(sizeof(node));
		temp->numara=x;
		temp->ad=ad;
		temp->soyad=soyad;
		temp->bolum=bolum;
		
		temp->next=r;
		return temp;
	}
	node * iter=r;
	while(iter->next!=NULL&& iter->next->numara<x)
	{
		iter=iter->next;
	}
	node * temp=(node *)malloc(sizeof(node));
	temp->next=iter->next;
	iter->next=temp;
	temp->numara=x;
	temp->ad=ad;
	temp->soyad=soyad;
	temp->bolum=bolum;
	
	
	
	return r;
	
}
node * sil(node*r,int x)
{
	node * temp;										//Main foksiyonundan root'u ve silinecek degeri aliyoruz.
	node * iter=r;										//Eger silinecek deger kok ise temp diye bir degisken olusturuyoruz.
	if(r->numara==x)									//Koku bir sonraki degere bagliyoruz ve bagladigimiz degerden onceki degeri
	{													//free komutu ile bellekten siliyoruz.
		temp=r;											//Gelen deger koke esit degil ise yine temp degiskenini olusturuyoruz.
		r=r->next;										//temp'i silinecek elemanin oncesine bagliyoruz.
		free(temp);										//iteri de silinecek elemandan sonraki elemana bagliyoruz.
		return r;										//Elemani free komutu ile siliyoruz ve temp'i iter'e bagliyoruz.
	}													//Bu islem r esit NULL olana kadar devam ediyor.
	while(iter->next !=NULL && iter->next->numara!=x)
	{
		iter=iter->next;
	}
	if(iter->next==NULL)
	{
		printf("sayi bulunamadi\n");
		return r;
	}
	temp=iter->next;
	iter->next=iter->next->next;
	free(temp);
	if(iter->next!=NULL)
	{
		iter->next->prev=iter;	
	}
	
	return r;
}
void kontrol(node * iter)
{												//Her iki derside birden fazla kez alan ogrencileri listelemek icin kullanilir
	int i,j;									//Listenin her elemani kendisi disindaki elemanlar ile
	node * iter2;								//karsilastirilir.
	iter2=iter->next;							//Eger ayni eleman var ise bu ogrenci bu dersi birden fazla kez
	while(iter->next!=NULL)						//aliyor demektir.
	{											//bu ogrenciler yazdiririlir.
		while(iter2!=NULL)
		{
			if(iter->numara==iter2->numara)
			{
				printf("%s\n",iter->ad);
				iter2=iter2->next;
			}
			else
			{
				
				iter2=iter2->next;
			}
		}
		iter=iter->next;
		iter2=iter->next;
	}
	/*
	for(i=0;iter!=NULL;i++)
	{
		for(j=i+1;iter2!=NULL;j++)
		{
			if(iter->numara==iter2->numara)
			{
				printf("sjdf\n");
				iter2=iter2->next;
				
			//	printf("%s\n",iter->ad);//burasý TAM OTURMADI ÝYÝ OTURTTTTTTTTTTTTTTTTTTTTTT	
			}
			else
			{
				printf("%d\n",sayac+1);
				sayac++;
				iter2=iter2->next;
			}
		}
		
		iter=iter->next;
		iter2=iter->next;
	}*/
}
void herikiders(node * iter,bnode * iter2)
{
	int i,j;													//Burada baglantili listeyi ve b+ agacini main fonsiyonundan aliyoruz.
	bnode * iter3;												//Dongulerimiz liste ve agacin sonuna gelene kadar donuyor.	
	iter3=iter2;												//Eger degerler birbirine esit olursa ve bolumleride BM den farkli olursa
	while(iter!=NULL)											//Her iki dersi alan ve baska bolum ogrencisi olan ogrenciler ortaya cikmis oluyor.
	{															//listenin her bir elemani b+ agacinin her bir elemani ile esitligi kontrol ediliyor. 
		while(iter2!=NULL)										//Olasi her ihtimal dongulerimiz sayesinde kontrole tabi tutuluyor.
		{
			if(iter->numara==iter2->numara )
			{
				if(iter->bolum!="BM")
				{
					if(iter2->bolum!="BM")
					{
						printf("++++%d++++\n",iter->numara);
						iter2=iter2->next;		
					}
					else
					{
						iter2=iter2->next;		
					}
					
				}
				else
				{
					iter2=iter2->next;	
				}	
			}
			else
			{
				iter2=iter2->next;
			}
		}
		iter=iter->next;
		iter2=iter3;
		iter2=iter2->next;
	}

}
int  blistBulma(node * r, int x)
{
	while(r!=NULL)
	{
		if(r->numara==x)
		{
			r=r->next;
			return 1;
		}
		else
		r=r->next;
	}
	return 0;
}
int  bulma(bnode * r, int x)
{												//B+ agaci ve listenin elemani sadecebilgisiyar fonsiyonundan aliniyor
	while(r!=NULL)								//Dongu b+ agaci sonlanana kadar devam ediyor.
	{											//Eger b+ agacinin degeri gonderilen degere esit oluyor ise
		if(r->numara==x)						//1 degeri donduruluyor
		{										//Aksi durumda ise 0 donderiliyor.
			r=r->next;
			return 1;
		}
		else
		r=r->next;
	}
	return 0;
}
void sadecebigisayar(node * iter,bnode * iter2)
{												//Sadece bilgisayar programlama dersini alan ogrencileri bulmak icin,
	while(iter!=NULL)							//Listemizi ve B+ agacini main fonksiyonundan aliyoruz.
	{											//Dongumuz listemiz bos olana kadar devam ediyor.
		if(bulma(iter2,iter->numara)!=1)		//bulma fonksiyonuna b+ agacini ve listenin ilk elemanini gonderiyoruz.
		{										//Gelen deger 1 den farkli ise ogrenci veri yapilari dersini almiyordur.
			printf("%d\n",iter->numara);		//Gelen deger 1 ise ogrenci veri yapilari dersini almiyordur ve bu durumda
			iter=iter->next;					//bu degeri ekrana bastiririz.
		}
		else
		iter=iter->next;

	}
	
}
void quickSorttt(node * r,int first,int last)
{
	node * iter;//i
	node * iter2;//j
	node * pivot;
	node * temp;
	iter=r;// iter ilk elaman
	while(iter2!=NULL)
	{
		iter2=iter2->next;//iter2 son eleman
	}
	pivot->numara=first;
	if(last>first)
	{
		pivot->numara=first;
		iter->numara=first;
		iter2->numara=last;
		while(iter->numara<iter2->numara)
		{
			while(iter->numara<=iter->next->numara && iter->numara<last && iter2->numara>iter->numara)// kontrolu dogru yap
			{
				iter=iter->next;
			}
			while(iter2->numara>=iter2->next->numara && iter2->numara>=first && iter2->numara>=iter->numara)
			{
				iter2->next=iter2;
			}
			if(iter2->numara>iter->numara)
			{
				temp->numara=iter->numara;//iter->numarasi olup  olmadigini kontrol et
				iter->numara=iter2->numara;
				iter2->numara=temp->numara;
			}
		}
		
		temp=iter2;
		iter2->numara=iter2->next->numara;
		iter2->next->numara=temp->numara;
		quickSorttt(r,first,iter2->numara);
        quickSorttt(r,iter2->numara,last);
	}
	
	
}
void ABbastir(node * r,node * k)
{														//Grunba ayirdan A ve B listelerini aliyoruz.
	printf("A grubu\n\n");								//Dongumuz listenin sonuna gelene kadar devam edecek.
	while(r->next!=NULL)								//Liste de adim adim ilerleme durumu,
	{													//r=r->next ifadesi ile yapiliyor.
		printf("%s\n",r->next->ad);
		r=r->next;
	}
	printf("B grubu\n\n");
	while(k->next!=NULL)
	{
		printf("%s\n",k->next->ad);
		k=k->next;
	}
}
void grubaAyir(node * r)
{														//Main fonsiyonundan liste aliniyor.
	node * iter;										//Bellekte A ve B isimli 2 yer tahsis ediliyor.
	node * iter2;										//Dongumuz listemiz sonlanana kadar devam ediyor.
	node * A;											//Eger ogrencinin adi l'den kucuk ise
	node * B;											//A isimli listemize ekleniyor.
	A=(node *)malloc(sizeof(node));						//Eger l'den buyuk ve esit ise
	B=(node *)malloc(sizeof(node));						//B isimli listemize ekleniyor.
	iter=A;												//Dongu bittikten sonra ABbastir fonksiyonuna
	iter2=B;											//A ve B listemizi gonderiyoruz.
	
	while(r!=NULL)
	{
		char *ad=r->ad;
		if(*ad<'l')
		{		
			iter->next=(node *)malloc(sizeof(node));
			iter->next->ad=r->ad;
			iter=iter->next;
			iter->next=NULL;
			r=r->next;
		}
		else if(*ad>='l')
		{
			iter2->next=(node *)malloc(sizeof(node));
			iter2->next->ad=r->ad;
			iter2=iter2->next;
			iter2->next=NULL;
			r=r->next;		
		}	
	}
	ABbastir(A,B);
}
/*node * heapSort(node * r)
{
	node * k;
	k=r;
	node * heap;
	node * iter;
	node * iter2;
	heap=(node *)malloc(sizeof(node));
	heap->numara=k->numara;
	iter=heap;
	iter2=heap;
	heap->sag=NULL;
	heap->sol=NULL;
	int i=0;
	//itersag=heap;
	while(i!=5)//r->next=NULL byuyuk ihtimalle k->next->next!=NULL
	{
		//if(heap!=NULL )
	//	{
			if(heap->sag!=NULL && heap->sag!=NULL)
			{
				printf("asd\n");
				k=k->next;
				iter->sol=(node *)malloc(sizeof(node));
				iter->sol->numara=k->numara;
				iter->sag=(node *)malloc(sizeof(node));
				iter->sag->numara=k->next->numara;
				k=k->next;
				iter2->sol=(node *)malloc(sizeof(node));
				iter2->sol->numara=k->next->numara;
				iter2->sag=(node *)malloc(sizeof(node));
				iter2->sag->numara=k->next->next->numara;
			//	iter=iter->sol;
			//	iter2=iter2->sag;
			i++;
			}
			else
			{
			
				printf("qqq\n");
				k=k->next;
				iter->sol=(node *)malloc(sizeof(node));
				iter->sol->numara=k->numara;
				iter->sag=(node *)malloc(sizeof(node));
				iter->sag->numara=k->next->numara;
				iter=iter->sol;	
				iter2=iter2->sag;
				k=k->next;
				i++;
			}	
			i++;
	}	
	printf("lll\n");
	/*while(heap!=NULL)
	{
		printf("%d > %d > %d > %d > ",iter2->sag->numara,iter2->sol->numara,iter->sag->numara,iter->sol->numara);
		free(iter2->sol);
		free(iter2->sag);
		free(iter->sag);
		free(iter->sol);
		printf("%d > %d",iter2->numara,iter->numara);
		free(iter2);
		free(iter);
		printf("> %d",heap->numara);
		free(heap);
//	}

}*/
node * heapSort(node * r)
{
	node * heap;
	node * temp;
	node * iter;
	node * iter2;
	heap=(node *)malloc(sizeof(node));
	heap->numara=r->numara;
	iter=heap;
	int i=0;
	while(i!=1)
	{
		i++;
		iter->sol=(node *)malloc(sizeof(node));
		iter->sol->numara=r->next->numara;
		if(heap->numara<iter->sol->numara)
		{
			printf("ali\n");
			iter=iter->sol;
			iter->sol=heap;
			heap=iter;	
			r=r->next;
		}
		iter->sag=(node *)malloc(sizeof(node));
		iter->sag->numara=r->next->numara;
		if(heap->numara<iter->sag->numara)
		{
			iter=iter->sag;
			iter->sag=heap;
			heap=iter;
			r=r->next;
		}
		
	}
	printf("%d\n",heap->numara);
	printf("%d\n",heap->sol->numara);
	printf("%d\n",heap->sag->numara);

}
void swap ( int* a, int* b )
{   int t = *a;      *a = *b;       *b = t;   }

 node *lastNode(node *root)
{
    while (root && root->next)
        root = root->next;
    return root;
}

node* partition(node *l, node *h)
{
    int x  = h->data;
    node *i = l->prev;
    for (node *j = l; j != h; j = j->next)
    {
        if (j->data <= x)
        {
            i = (i == NULL)? l : i->next;
 
            swap(&(i->data), &(j->data));
        }
    }
    i = (i == NULL)? l : i->next; 
    swap(&(i->data), &(h->data));
    return i;
}
void _quickSort(node* l, node *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        node *p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}
void quickSort(node *head)
{
    node *h = lastNode(head);
    _quickSort(head, h);
}
void printList(node *head)
{
    while (head)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}
 
void push(node** head_ref, int new_data)
{
    node* new_node = new node; 
    new_node->data  = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) !=  NULL)  (*head_ref)->prev = new_node ;
    (*head_ref)    = new_node;
}



int main()
{
	node * root;
	root=NULL;
	bnode * broot;
	broot=NULL;
	int islem,islem2,islem3,islem4,silinecek,aranan,bsilinecek,baranan;
	printf("YAPMAK ISTEDIGINIZ ISLEMI SECINIZ...\n\n");
	oMenu:	printf("1. CIFT YONLU BAGLANTILI LISTE...\n2. B+ AGACI...\n3. DIGER ISLEMLER...\n-1. CIKIS!!!\n");scanf("%d",&islem); 
	while(islem!=-1)
	{

		if(islem==1)
		{	//baglý liste
			printf("1. LISTEYE EKLEME...\n2. LISTEYI BASTIR...\n3. LISTEDEN SILME...\n4. ELEMAN BULMA...\n0. GERI!!!\n-1. CIKIS!!!\n");scanf("%d",&islem2);
			if(islem2==1)
			{	//listeye ekle
				system("CLS");						
				root=siraliEkle(root,100,"mehmet","boyuk","BM");
				root=siraliEkle(root,10,"ihsan","konargocer","BM");
				root=siraliEkle(root,1,"omer","faruk","BM");
				root=siraliEkle(root,100,"mehmet","boyuk","BM");
				root=siraliEkle(root,150,"zenes","tunca","MM");
				root=siraliEkle(root,10,"ihsan","konargocer","BM");
				root=siraliEkle(root,50,"amurat","orhan","EM");
				root=siraliEkle(root,5,"erkut","ergun","EEM");	
				printf("listeye ekledi\n\n");
				//break;
			}
			else if(islem2==2)
			{//lsiteden bastir
				system("CLS");	
				if(root==NULL)
				{
					printf("LISTE BOS. EKLEDIKTEN SONRA TEKRAR DENEYINIZ...\n\n");
				}
				else
				{
					bastir(root);
				}
			}
			else if(islem2==3)
			{//eleman bul
				system("CLS");
				if(root==NULL)
				{
					printf("LISTE BOS. EKLEDIKTEN SONRA TEKRAR DENEYINIZ...\n\n");
				}
				else
				{	
					printf("SILINECEK ELEMANI GIRINIZ...\n");scanf("%d",&silinecek);
					root=sil(root,silinecek);
					printf("listeden silindi\n\n");	
					printf("SILINDIKTEN SONRA...\n");
					bastir(root);	
				}
			}
			else if(islem2==4)
			{//eleman bul
				system("CLS");
				printf("ARANAN ELEMANI GIRINIZ...\n");scanf("%d",&aranan);
				if(blistBulma(root,aranan)==1)
				{
					printf("aranan eleman bulundu...\n");		
				}
				else
				{
					printf("aranan eleman bulunamadi...\n");
				}
			}
			else if(islem2==0)
			{	//onceki menu
				system("CLS");
				goto oMenu;	
			}
			else if(islem2==-1)
			{//sonlandýr
				system("CLS");
				printf("PROGRAM SONLANDI... IYI GUNLER...\n\n");
				break;
			}
			else 
			{
				system("CLS");
				printf("yanlýs islem tekrar deneyin\n\n");
			}		
		}
		else if(islem==2)
		{
			//b+ agacý
			printf("1. AGACA EKLEME...\n2. AGACI BASTIR...\n3. AGACTAN SILME...\n4. ELEMAN BULMA...\n0. GERI!!!\n-1. CIKIS!!!\n");scanf("%d",&islem3);
			if(islem3==1)
			{
				//agaca ekle
				system("CLS");
				broot=kokOlustur(broot,190,"BM");
				broot=kokOlustur(broot,19,"BM");
				broot=kokOlustur(broot,19,"BM");		
				broot=kokOlustur(broot,1900,"BM");
				broot=kokOlustur(broot,50,"EEM");
				//broot=kokOlustur(broot,5,"EEM");	
				printf("AGACA EKLEME BASARILI\n\n");
			}
			else if(islem3==2)
			{
				//agactan BASTIR
				system("CLS");
				if(broot==NULL)
				{
					printf("B+ AGACI BOS. ELEMAN EKLEDIKTEN SONRA TEKRAR DENEYINIZ...\n\n");
				}
				else
				{
					bbastir(broot);
				}
				
			}
			else if(islem3==3)
			{
				//eleman SÝL
				system("CLS");
				if(broot==NULL)
				{
					printf("B+ AGACI BOS. ELEMAN EKLEDIKTEN SONRA TEKRAR DENEYINIZ...\n\n");
				}
				else
				{	
					printf("SILINECEK ELEMANI GIRINIZ...\n");scanf("%d",&bsilinecek);
					broot=bSil(broot,bsilinecek);
					printf("b+ agacindan silindi\n\n");	
					printf("SILINDIKTEN SONRA...\n\n");
					bbastir(broot);	
				}
				
			}
			else if(islem3==4)
			{
				//eleman BUL
				system("CLS");
				if(broot==NULL)
				{
					printf("B+ AGACI BOS. ELEMAN EKLEDIKTEN SONRA TEKRAR DENEYINIZ...\n\n");
				}
				else
				{
					printf("ARNAAN ELEMANI GIRINIZ...\n");scanf("%d",&baranan);
					if(bulma(broot,baranan)==1)
					{
						printf("aranan eleman bulundu...\n\n");
					}
					else
					{
						printf("aranan eleman bulunamadi...\n\n");
					}
				}	
			}
			
			else if(islem3==0)
			{
				//onceki menu
				system("CLS");
				goto oMenu;
			}
			else if(islem3==-1)
			{
				//sonlandýdr
				system("CLS");
				printf("PROGRAM SONLANDI. IYI GUNLER...\n\n");
				break;
			}
			else
			{
				//yanlýs secim
				system("CLS");
				printf("yanlis secim tekrar deneyin\n\n");
			}
			
		}
		else if(islem==3)
		{
			//diger islmeler
			yislem: printf("1. Her iki dersi de birden fazla kez alan ogrencileri listele...\n2. Sadece Bilgisayar Programlama dersini alan ogrencileri listele...\n3. Bilgisayar Programlama A ve B grubu...\n");
			printf("4. Bilgisayar Programlama ve Veritabani Yonetim Sistemleri derslerinin her ikisini de alan ve baska bolum ogrencileri olan ogrencilerin listesi...\n");
			printf("5. Hizli siralama algoritmasi...\n6. radiks siralama algoritmasi...\n7. kumeleme siralama algoritmasi..\n");
			printf("0. GERI!!!\n-1. CIKIS!!!\n");
			scanf("%d",&islem4);
			if(islem4==1)
			{
				system("CLS");
				if(root==NULL)
				{
					printf("LISTE BOS ELEMAN EKLEDIKTEN SONRA TEKRAR DENEYINIZ...\n\n");
				}
				else
				{
					kontrol(root);
				}
				if(broot==NULL)
				{
					printf("B+ AGACI BOS. ELEMAN EKLEDIKTEN SONRA TEKRAR DENEYINIZ...\n\n");
				}
				else
				{
					
					bkontrol(broot);
				}
					
			}
			else if(islem4==2)
			{
				system("CLS");
				if(root==NULL || broot==NULL)
				{
					printf("LISTE BOS. ELEMAN EKLEDIKTEN SONTA TEKRAR DENEYINIZ...\n\n");
				}
				else
				{
					sadecebigisayar(root,broot);
				}
			}
			else if(islem4==3)
			{
				system("CLS");
				if(root==NULL)
				{
					printf("LISTE BOS. ELEMAN EKLEDIKTEN SONTA TEKRAR DENEYINIZ...\n\n");	
				}
				else
				{
					grubaAyir(root);
				}
			}
			else if(islem4==4)
			{
				system("CLS");
				if(root==NULL || broot==NULL)
				{
					printf("LISTE BOS. ELEMAN EKLEDIKTEN SONTA TEKRAR DENEYINIZ...\n\n");
				}
				else
				{
					system("CLS");
					printf("Her iki dersi de alan ve baska bolum ogrencileri olan ogrencileri listesi...\n\n");
					herikiders(root,broot);
				}
				
			}
			else if(islem4==5)
			{
				//quick sort
				system("CLS");
				if(root==NULL)
				{
					printf("LISTE BOS. ELEMAN EKLEDIKTEN SONRA TEKRAR DENEYINIZ...\n\n");
				}
				else 
				{
					
					node *a = NULL;
    				push(&a, 100);
    				push(&a, 10);
   				    push(&a, 1);
   				    push(&a, 5);
   					push(&a, 50);
    				push(&a, 150);
					printf("siralamadan once \n\n");
    				printList(a);
   					quickSort(a);
   					printf("siralamadan sonra\n\n");
    				printList(a);
				}	
			}
			else if(islem4==6)
			{//radiks
				system("CLS");
				if(broot==NULL)
				{
					printf("LISTE BOS. ELEMAN EKLEDIKTEN SONRA TEKRAR DENEYINIZ...\n\n");
				}
				else
				{
					printf("radiks\n\n");
				}
				
			}
			else if(islem4==7)
			{//kumeleme
				system("CLS");
				if(root==NULL)
				{
					printf("LISTE BOS. ELEMAN EKLEDIKTEN SONRA TEKRAR DENEYINIZ...\n\n");
				}
				else
				{
					printf("kumeleme\n\n");
				}
				
			}
			else if(islem4==0)
			{
				system("CLS");
				goto oMenu;
			}
			else if(islem4==-1)
			{
				break;
			}
			else
			{
				system("CLS");
				printf("YANLIS BIR ISLEM GERCEKLESTIRDINIZ. LUTFEN TEKRAR DENEYINIZ...\n\n");
				goto yislem;
				
			}

		}
		else
		{
			system("CLS");
			printf("YANLIS BIR ISLEM GERCEKLESTIRDINIZ. LUTFEN TEKRAR DENEYINIZ...\n\n");
			goto oMenu;
		}
	}	
}
