#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int xEnd,yEnd;
int count=0;

void xy (int,int);
int pilihan;

//Inisialisasi Struct
struct Data{
    long long int NoKamar, Hari, Biaya;
    int tipe,nomor;
    char Nama[100], Fasilitas[30], opId[20];
};
Data saldos[100];

void gotoxy(int x, int y){
    COORD coord;
   	coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void password (){
	int a, b;
	int check = 0, i = 0;
 	char hide;
 	char user[10];
 	char pass[10];

 	do {
  		system ("cls");
  		time_t t;
    	time(&t);
  		gotoxy (17,5); 
		printf("Date : %s", ctime(&t));
  		gotoxy (40,9);
  		printf("Selamat Datang di Database Hotel SalDos !!");
  		gotoxy (38,11);
  		printf("+============================================+");
		gotoxy (41,12);
		printf("MASUKKAN USERNAME (admin)	: "); 
		scanf("%s", user);
  		printf("\n");
  		gotoxy (41,13);
		printf("MASUKKAN PASSWORD	 	: ");
  		while((hide = _getch())!=13){
   			pass[i] = hide;
   			i++;
   			printf("*");
  		}
  	
		if(strcmp(pass,"admin")==0 && strcmp(user,"admin")==0) {
   			gotoxy (38,15);
			printf ("SELAMAT ANDA BERHASIL LOGIN\n");
   			gotoxy (38,17);
			printf ("TEKAN SEMBARANG TOMBOL UNTUK LANJUT...");
   			getch();
   			break;
	  	}
		else {
   			i=0;
   			gotoxy (38,15);
   			printf("LOGIN TIDAK BERHASIL COBA LAGI");
   			getch();
   			if(check==2){
   				gotoxy (38,17);
   				printf("MAAF ANDA MEMASUKKAN USERNAME ATAU PASSWORD YANG SALAH SEBANYAK 3 KALI !! ");
   				getch ();
   				exit (0);
   			}
   			system("cls");
   			for(a=1; a<=3; a++){
    			for(b=1; b<=22; b++){
     				if(b==2 && a==2){
      					printf("===== LOGIN FORM =====");
     				}	
     				else if(a==1 || a==3){
       					printf("=");
      				}
    			}
   				printf("\n");
   			}
   			printf("\n\n\n");
  			check++;
  		}
 	}	
	while(check < 3);
}

void loadingA (){
	int loop = 0;
	int c = 3;
	int d = 2;
	
	system("color 0B");
	gotoxy (40,10); printf ("+-------------------+");
	gotoxy (45,12); printf ("Loading");
	gotoxy (40,14); printf ("+-------------------+");
	while(loop<c){ //c nya bisa diganti brpapun diatas (loop titik2)
		for(int i=0;i<d;i++){ //d bisa diganti diatas (jumlah titik2)
			xy(52+i,12);
			printf("."); //yang diganti 7 ama 0 nya aja sesuain ama lokasi
			Sleep(500); // waktu bisa di cepetin / lambatin
			if(i==d-1){
				for(int j=0;j<d;j++){
					xy(52+j,12);
					printf(" "); //yang diganti 7 ama 0 nya aja sesuain ama lokasi
				}
			}
		}
		if(loop==c-1){
			for(int k=0;k<d;k++){
					xy(52+k,12);
					printf(".");//yang diganti 7 ama 0 nya aja sesuain ama lokasi
				}
		}
		loop++;
	}
}

void defDisplay (){
	system ("cls");
	gotoxy (31,5); printf  ("+======================================================+");
	gotoxy (42,7); printf ("~ Program Database Hotel SalDos ~");
	gotoxy (31,10); printf ("+------------------------------------------------------+");
	gotoxy (31,25); printf  ("+======================================================+");
}

void menuUtama (){
	system ("cls");
	gotoxy (31,6); printf  ("+======================================================+");
	gotoxy (42,8); printf ("~ Program Database Hotel SalDos ~");
	gotoxy (50,9); printf ("~ Daftar Menu ~");
	gotoxy (31,11); printf ("+------------------------------------------------------+");
	gotoxy (31,23); printf  ("+======================================================+");
	//Menu Utama
	gotoxy (40,13); printf ("Tekan 1. Menambahkan Data Hotel SalDos\n");
	gotoxy (40,14); printf ("Tekan 2. Menampilkan Data Hotel SalDos\n");
	gotoxy (40,15); printf ("Tekan 3. Menghapus Data Hotel SalDos\n");
	gotoxy (40,16); printf ("Tekan 4. Mengedit Data Hotel SalDos\n");
	gotoxy (40,17); printf ("Tekan 5. Mencari Data Hotel SalDos\n");
	gotoxy (40,18); printf ("Tekan 6. Mengurutkan Data Hotel SalDos\n");
	gotoxy (40,19); printf ("Tekan 7. Keluar Program");
	
	gotoxy (40,21); printf ("Masukkan Pilihan Anda : ");
	scanf ("%d", &pilihan);
}

void menuPertama (){
	back :
	defDisplay ();
	gotoxy (50,9); printf ("~ Insert Data ~");
	int biayaSB = 50000, biayaDB = 75000, biayaPS = 100000;
	int jml;
	gotoxy (42,11);
	printf ("Masukkan Jumlah Data (Maks 5) : ");
	scanf ("%d", &jml);
	
	if(jml > 5 || jml < 1){
        gotoxy (49,12); printf("Maks Input Hanya 5!");
        getch();
        goto back;
    }
    
    int i;
    for(i = 0 ; i < jml ; i++){
    	defDisplay ();
    	gotoxy (50,8); printf ("~ Insert Data ~");
    	gotoxy (50,9); printf ("~ DATA KE - %d ~", i+1);
        gotoxy (48,12); printf("Tipe Kamar : ");
        gotoxy (48,13); printf("1. Single Bed (SB)");
        gotoxy (48,14); printf("2. Double Bed (DB)");
        gotoxy (48,15); printf("3. President Suite (PS)");
        gotoxy (48,17); printf("Pilih Tipe Kamar  : ");
        scanf("%d", &saldos[i].tipe);
        switch (saldos[i].tipe){
        case 1:
             gotoxy (48,18);
			 printf("Masukkan No Kamar : ");
             scanf("%d", &saldos[i].NoKamar);
             for(int j=0;j<99;j++){
             	int check=0;
             	if(saldos[j].tipe==saldos[i].tipe && j!=i){
             		check++;
             		if(saldos[j].NoKamar==saldos[i].NoKamar){
             			gotoxy (48,19);
             			printf("Kamar SB-%d Telah dipesan!",saldos[i].NoKamar);
             			getch();
             			xEnd=48;yEnd=20;
             			goto skip;
					 }
				 }else if (saldos[j].tipe==saldos[i].tipe && j==i && check!=0){
				 	if(saldos[j].NoKamar==saldos[i].NoKamar){
             			gotoxy (48,19);
             			printf("Kamar SB-%d Telah dipesan!",saldos[i].NoKamar);
             			getch();
             			xEnd=48;yEnd=20;
             			goto skip;
					 }
				 }
			 }
             gotoxy (48,19);
			 printf("Masukkan Nama Pemesan : ");
             scanf("%s", &saldos[i].Nama);
             gotoxy (48,20);
			 printf("Jumlah Hari Pemesanan : ");
             scanf("%d", &saldos[i].Hari);
             gotoxy (48,21);
             printf("Fasilitas Tambahan : ");
             scanf("%s", &saldos[i].Fasilitas);
             saldos[i].Biaya = biayaSB * saldos[i].Hari;
             gotoxy (48,22);
             printf("Total Biaya adalah : %d", saldos[i].Biaya);
             gotoxy (48,23);
			 printf("Kamar SB-%d Berhasil dipesan !", saldos[i].NoKamar);count++;
			 if(i!=jml-1) getch();
             xEnd=48;yEnd=24;
			 skip :
             break;
        case 2:
        	gotoxy (48,18);
            printf("Masukkan No Kamar : ");
            scanf("%d", &saldos[i].NoKamar);
            for(int j=0;j<99;j++){
             	int check=0;
             	if(saldos[j].tipe==saldos[i].tipe && j!=i){
             		check++;
             		if(saldos[j].NoKamar==saldos[i].NoKamar){
             			gotoxy (48,19);
             			printf("Kamar DB-%d Telah dipesan!",saldos[i].NoKamar);
             			getch();
             			xEnd=48;yEnd=20;
             			goto skip2;
					 }
				 }else if (saldos[j].tipe==saldos[i].tipe && j==i && check!=0){
				 	if(saldos[j].NoKamar==saldos[i].NoKamar){
             			gotoxy (48,19);
             			printf("Kamar DB-%d Telah dipesan!",saldos[i].NoKamar);
             			getch();
             			xEnd=48;yEnd=20;
             			goto skip2;
					 }
				 }
			 }
            gotoxy (48,19);
			printf("Masukkan Nama Pemesan : ");
            scanf("%s", &saldos[i].Nama);
            gotoxy (48,20);
			printf("Jumlah hari Pemesanan : ");
            scanf("%d", &saldos[i].Hari);
            gotoxy (48,21);
            printf("Fasilitas Tambahan : ");
            scanf("%s", &saldos[i].Fasilitas);
            saldos[i].Biaya = biayaDB*saldos[i].Hari;
            gotoxy (48,22);
            printf("Total Biaya adalah : %d ", saldos[i].Biaya);
            gotoxy (48,23);
            printf("Kamar DB-%d Berhasil dipesan !", saldos[i].NoKamar);count++;
            if(i!=jml-1) getch();
            xEnd=48;yEnd=24;
			skip2 :
            break;
        case 3:
        	gotoxy (48,18);
            printf("Masukkan No Kamar : ");
            scanf("%d", &saldos[i].NoKamar);
            for(int j=0;j<99;j++){
             	int check=0;
             	if(saldos[j].tipe==saldos[i].tipe && j!=i){
             		check++;
             		if(saldos[j].NoKamar==saldos[i].NoKamar){
             			gotoxy (48,19);
             			printf("Kamar PS-%d Telah dipesan!",saldos[i].NoKamar);
             			getch();
             			xEnd=48;yEnd=20;
             			goto skip3;
					 }
				 }else if (saldos[j].tipe==saldos[i].tipe && j==i && check!=0){
				 	if(saldos[j].NoKamar==saldos[i].NoKamar){
             			gotoxy (48,19);
             			printf("Kamar PS-%d Telah dipesan!",saldos[i].NoKamar);
             			getch();
             			xEnd=48;yEnd=20;
             			goto skip3;
					 }
				 }
			 }
            gotoxy (48,19);
            printf("Masukkan Nama Pemesan : ");
            scanf("%s", &saldos[i].Nama);
            gotoxy (48,20);
            printf("Jumlah hari Pemesanan : ");
            scanf("%d", &saldos[i].Hari);
            gotoxy (48,21);
            printf("Fasilitas Tambahan : ");
            scanf("%s", &saldos[i].Fasilitas);
            saldos[i].Biaya = biayaPS*saldos[i].Hari;
            gotoxy (48,22);
            printf("Total Biaya adalah : %d ", saldos[i].Biaya);
            gotoxy (48,23);
            printf("Kamar PS-%d Berhasil dipesan !", saldos[i].NoKamar);count++;
            if(i!=jml-1) getch();
            xEnd=48;yEnd=24;
			skip3 :
            break;
        default :
            printf("Tidak ada Tipe Kamar !");
            getch();
            break;
    	}
    }	
}

void menuKedua (){
	defDisplay ();
	int line=16;
	gotoxy (50,9); printf ("~ Read Data ~");
	gotoxy (15,12); printf ("ID KAMAR");
	gotoxy (31,12); printf ("NO KAMAR");
	gotoxy (47,12); printf ("TIPE");
	gotoxy (55,12); printf ("NAMA PEMESAN");
	gotoxy (71,12); printf ("FASILITAS TAMBAHAN");
	gotoxy (96,12); printf ("HARI");
	gotoxy (105,12); printf ("BIAYA");
	gotoxy(5,13);
	for(int i=0;i<99;i++){
		printf("=");
	}
	if(count==0){
		gotoxy (54,14); printf("= = = TIDAK ADA DATA = = =");
		xEnd=49;yEnd=16;
	}else{
	char kode[3]="AB";
	char id[count][100];
	for(int i=0;i<count;i++){
		for(int i=0;i<count;i++){
		if(saldos[i].tipe==1){
			kode[0]='S';
			kode[1]='B';
			saldos[i].nomor=100+saldos[i].NoKamar;
			sprintf(id[i],"%s-%d",kode,saldos[i].NoKamar);
		}else if(saldos[i].tipe==2){
			kode[0]='D';
			kode[1]='B';
			saldos[i].nomor=200+saldos[i].NoKamar;
			sprintf(id[i],"%s-%d",kode,saldos[i].NoKamar);
		}else if(saldos[i].tipe==3){
			kode[0]='P';
			kode[1]='S';
			saldos[i].nomor=300+saldos[i].NoKamar;
			sprintf(id[i],"%s-%d",kode,saldos[i].NoKamar);
	  	}
		gotoxy (15,14+i); printf ("%s",id[i]);
		gotoxy (31,14+i); printf ("%d",saldos[i].NoKamar);
		gotoxy (47,14+i); printf ("%d",saldos[i].tipe);
		gotoxy (55,14+i); printf ("%s",saldos[i].Nama);
		gotoxy (71,14+i); printf ("%s",saldos[i].Fasilitas);
		gotoxy (96,14+i); printf ("%d",saldos[i].Hari);
		gotoxy (105,14+i); printf ("%d",saldos[i].Biaya);
		line++;
		}xEnd=55;yEnd=line;
	}
	}
}

void menuKetiga (){
	system ("cls");
	gotoxy (31,5); printf ("+======================================================+");
	gotoxy (42,7); printf ("~ Program Database Hotel SalDos ~");
	gotoxy (50,9); printf ("~ Delete Data ~");
	gotoxy (31,10); printf ("+------------------------------------------------------+");
	gotoxy (31,11); printf ("List No Kamar");
	char kode[3]="AB";
	char id[count][100];
	int Opsi,num;
	char opId[100];
	char yesno[2];
	for(int i=0;i<count;i++){
		if(saldos[i].tipe==1){
			kode[0]='S';
			kode[1]='B';
			saldos[i].nomor=100+saldos[i].NoKamar;
			sprintf(id[i],"%s-%d",kode,saldos[i].NoKamar);
		}else if(saldos[i].tipe==2){
			kode[0]='D';
			kode[1]='B';
			saldos[i].nomor=200+saldos[i].NoKamar;
			sprintf(id[i],"%s-%d",kode,saldos[i].NoKamar);
		}else if(saldos[i].tipe==3){
			kode[0]='P';
			kode[1]='S';
			saldos[i].nomor=300+saldos[i].NoKamar;
			sprintf(id[i],"%s-%d",kode,saldos[i].NoKamar);
	  	}
	  	gotoxy (31,11+i); printf("%d. %s-%d / %d",i+1,kode,saldos[i].NoKamar,saldos[i].nomor);
	}
	if(count==0){
		gotoxy (54,11); printf("= = = TIDAK ADA DATA = = =");
		xEnd=54;yEnd=13;
	}
	else{
	gotoxy (54,11); printf("= = = MENU CARI DATA = = =");
	gotoxy (49,13); printf("Cari Data Hotel SalDos Berdasarkan : ");
	gotoxy (49,14); printf("1. ID Kamar Hotel");
	gotoxy (49,15); printf("2. Nomor Kamar Hotel");
	gotoxy (49,17); printf("Masukkan Pilihan : "); scanf("%d",&Opsi);
	if(Opsi==1){
		gotoxy (49,18); printf("Masukkan ID Kamar Hotel yang dicari : ");scanf("%s",&opId);
			for(int i=0;i<count;i++){
				if(strcmp(opId,id[i])==0){
					gotoxy (54,20); printf("= = = DATA DITEMUKAN = = =");
					gotoxy (49,22); printf("ID Kamar\t\t: %s",id[i]);
					gotoxy (49,23); printf("No Kamar\t\t: %d",saldos[i].nomor);
					gotoxy (49,24); printf("Tipe Kamar\t\t: %d",saldos[i].tipe);
					gotoxy (49,25); printf("Nama Pemesan\t\t: %s",saldos[i].Nama);
					gotoxy (49,26); printf("Fasilitas\t\t: %s",saldos[i].Fasilitas);
					gotoxy (49,27); printf("Total Hari\t\t: %d",saldos[i].Hari);
					gotoxy (49,28); printf("Total Biaya\t\t: %d",saldos[i].Biaya);
					gotoxy (49,30); printf("Ingin Menghapus data? (y/n) : ");scanf("%s",&yesno);
					if(strcmp(yesno,"y")==0){
						gotoxy (49,31); printf("Data %s Berhasil dihapus",id[i]);
						xEnd=49;yEnd=32;
						for(int j=i;j<count;j++){
							count=count-1;
							if(j==count-1){
								continue;
							}
							saldos[j]=saldos[j+1];
						}
					}else{
						gotoxy (49,31); printf("Terimakasih atas konfirmasinya");
						xEnd=49;yEnd=32;
					}
				}else{
					gotoxy (54,20); printf("Data %s tidak ditemukan",opId);
					xEnd=54;yEnd=21;
				}
			}
	}else if(Opsi==2){
		gotoxy (49,18); printf("Masukkan No Kamar Hotel yang dicari : ");scanf("%d",&num);
			for(int i=0;i<count;i++){
				if(num==saldos[i].nomor){
					gotoxy (54,20); printf("= = = DATA DITEMUKAN = = =");
					gotoxy (49,22); printf("ID Kamar\t\t: %s",id[i]);
					gotoxy (49,23); printf("No Kamar\t\t: %d",saldos[i].nomor);
					gotoxy (49,24); printf("Tipe Kamar\t\t: %d",saldos[i].tipe);
					gotoxy (49,25); printf("Nama Pemesan\t\t: %s",saldos[i].Nama);
					gotoxy (49,26); printf("Fasilitas\t\t: %s",saldos[i].Fasilitas);
					gotoxy (49,27); printf("Total Hari\t\t: %d",saldos[i].Hari);
					gotoxy (49,28); printf("Total Biaya\t\t: %d",saldos[i].Biaya);
					gotoxy (49,30); printf("Ingin Menghapus data? (y/n) : ");scanf("%s",&yesno);
					if(strcmp(yesno,"y")==0){
						gotoxy (49,31); printf("Data %s Berhasil dihapus",id[i]);
						xEnd=49;yEnd=32;
						for(int j=i;j<count;j++){
							count=count-1;
							if(j==count-1){
								continue;
							}
							saldos[j]=saldos[j+1];
						}
					}else{
						gotoxy (49,31); printf("Terimakasih atas konfirmasinya");
						xEnd=49;yEnd=32;
					}
				}else{
					gotoxy (54,20); printf("Data %d tidak ditemukan",num);
					xEnd=54;yEnd=21;
				}
			}
	}else{
		gotoxy (49,18); printf("Pilihan Tidak ada...");
		xEnd=49;yEnd=19;
	}
	}
}

void menuKeempat (){
	system ("cls");
	gotoxy (31,5); printf  ("+======================================================+");
	gotoxy (42,7); printf ("~ Program Database Hotel SalDos ~");
	gotoxy (50,9); printf ("~ Edit Data ~");
	gotoxy (31,10); printf ("+------------------------------------------------------+");
	gotoxy (31,11); printf ("List No Kamar");
	char kode[3]="AB";
	char id[count][100];
	int Opsi,num;
	char opId[100];
	int yesno;
	for(int i=0;i<count;i++){
		if(saldos[i].tipe==1){
			kode[0]='S';
			kode[1]='B';
			saldos[i].nomor=100+saldos[i].NoKamar;
			sprintf(id[i],"%s-%d",kode,saldos[i].NoKamar);
		}else if(saldos[i].tipe==2){
			kode[0]='D';
			kode[1]='B';
			saldos[i].nomor=200+saldos[i].NoKamar;
			sprintf(id[i],"%s-%d",kode,saldos[i].NoKamar);
		}else if(saldos[i].tipe==3){
			kode[0]='P';
			kode[1]='S';
			saldos[i].nomor=300+saldos[i].NoKamar;
			sprintf(id[i],"%s-%d",kode,saldos[i].NoKamar);
	  	}
	  	gotoxy (31,11+i); printf("%d. %s-%d / %d",i+1,kode,saldos[i].NoKamar,saldos[i].nomor);
	}
	if(count==0){
		gotoxy (54,11); printf("= = = TIDAK ADA DATA = = =");
		xEnd=54;yEnd=13;
	}
	else{
	gotoxy (54,11); printf("= = = MENU CARI DATA = = =");
	gotoxy (49,13); printf("Cari Data Hotel SalDos Berdasarkan : ");
	gotoxy (49,14); printf("1. ID Kamar Hotel");
	gotoxy (49,15); printf("2. Nomor Kamar Hotel");
	gotoxy (49,17); printf("Masukkan Pilihan : "); scanf("%d",&Opsi);
	if(Opsi==1){
		gotoxy (49,18); printf("Masukkan ID Kamar Hotel yang dicari : ");scanf("%s",&opId);
			for(int i=0;i<count;i++){
				if(strcmp(opId,id[i])==0){
					gotoxy (49,20); printf("Edit data %s berdasarkan : ",id[i]);
						gotoxy (49,21); printf("1. Tipe Kamar");
						gotoxy (49,22); printf("2. No Pemesan");
						gotoxy (49,23); printf("3. Nama Pemesan");
						gotoxy (68,21); printf("4. Fasilitas");
						gotoxy (68,22); printf("5. Jumlah Hari");
						gotoxy (49,24); printf("Masukkan Pilihan : ");scanf("%d",&yesno);
					if(yesno==1){
						gotoxy (49,29); printf("EDIT DATA BERDASARKAN : TIPE KAMAR");
						gotoxy (49,30); printf("Tipe Kamar Sebelumnya : %d",saldos[i].tipe);
						gotoxy (49,31); printf("1. Single Bed (SB)");
       			 		gotoxy (49,32); printf("2. Double Bed (DB)");
    			 	   	gotoxy (49,33); printf("3. President Suite (PS)");
    				    gotoxy (49,34); printf("Masukkan Pilihan : "); scanf("%d",&saldos[i].tipe);
    				    gotoxy (49,35); printf("Data Berhasil diubah");
    				    xEnd=49;yEnd=36;		
					}else if(yesno==2){
						gotoxy (49,29); printf("EDIT DATA BERDASARKAN : NOMOR KAMAR");
						gotoxy (49,30); printf("Nomor Kamar Sebelumnya : %d",saldos[i].NoKamar);
						gotoxy (49,32); printf("Masukkan Nomor Kamar Terbaru : ");scanf("%d",&saldos[i].NoKamar);
						gotoxy (49,33); printf("Data Berhasil diubah");
						xEnd=49;yEnd=34;
					}else if(yesno==3){
						gotoxy (49,29); printf("EDIT DATA BERDASARKAN : NAMA PEMESAN");
						gotoxy (49,30); printf("Nama Pemesan Sebelumnya : %s",saldos[i].Nama);
						gotoxy (49,32); printf("Masukkan Nama Pemesan Terbaru : ");scanf("%s",&saldos[i].Nama);
						gotoxy (49,33); printf("Data Berhasil diubah");
						xEnd=49;yEnd=34;
					}else if(yesno==4){
						gotoxy (49,29); printf("EDIT DATA BERDASARKAN : FASILITAS");
						gotoxy (49,30); printf("Fasilitas Sebelumnya : %s",saldos[i].Fasilitas);
						gotoxy (49,32); printf("Masukkan Fasilitas Terbaru : ");scanf("%s",&saldos[i].Fasilitas);
						gotoxy (49,33); printf("Data Berhasil diubah");
						xEnd=49;yEnd=34;
					}else if(yesno==5){
						gotoxy (49,29); printf("EDIT DATA BERDASARKAN : Jumlah Hari");
						gotoxy (49,30); printf("Jumlah hari Sebelumnya : %d",saldos[i].Hari);
						gotoxy (49,32); printf("Masukkan jumlah hari Terbaru : ");scanf("%d",&saldos[i].Hari);
						gotoxy (49,33); printf("Data Berhasil diubah");
						xEnd=49;yEnd=34;
					}else{
						gotoxy (49,29); printf("Pilihan Tidak ada...");
						xEnd=49;yEnd=30;
					}
				}else{
					gotoxy (54,20); printf("Data %s tidak ditemukan",opId);
					xEnd=54;yEnd=21;
				}
			}
	}else if(Opsi==2){
		gotoxy (49,18); printf("Masukkan No Kamar Hotel yang dicari : ");scanf("%d",&num);
			for(int i=0;i<count;i++){
				if(num==saldos[i].nomor){
						gotoxy (49,20); printf("Edit data %s berdasarkan : ",id[i]);
						gotoxy (49,21); printf("1. Tipe Kamar");
						gotoxy (49,22); printf("2. No Pemesan");
						gotoxy (49,23); printf("3. Nama Pemesan");
						gotoxy (68,21); printf("4. Fasilitas");
						gotoxy (68,22); printf("5. Jumlah Hari");
						gotoxy (49,24); printf("Masukkan Pilihan : ");scanf("%d",&yesno);
					if(yesno==1){
						gotoxy (49,29); printf("EDIT DATA BERDASARKAN : TIPE KAMAR");
						gotoxy (49,30); printf("Tipe Kamar Sebelumnya : %d",saldos[i].tipe);
						gotoxy (49,31); printf("1. Single Bed (SB)");
       			 		gotoxy (49,32); printf("2. Double Bed (DB)");
    			 	   	gotoxy (49,33); printf("3. President Suite (PS)");
    				    gotoxy (49,34); printf("Masukkan Pilihan : "); scanf("%d",&saldos[i].tipe);
    				    gotoxy (49,35); printf("Data Berhasil diubah");
    				    xEnd=49;yEnd=36;		
					}else if(yesno==2){
						gotoxy (49,29); printf("EDIT DATA BERDASARKAN : NOMOR KAMAR");
						gotoxy (49,30); printf("Nomor Kamar Sebelumnya : %d",saldos[i].NoKamar);
						gotoxy (49,32); printf("Masukkan Nomor Kamar Terbaru : ");scanf("%d",&saldos[i].NoKamar);
						gotoxy (49,33); printf("Data Berhasil diubah");
						xEnd=49;yEnd=34;
					}else if(yesno==3){
						gotoxy (49,29); printf("EDIT DATA BERDASARKAN : NAMA PEMESAN");
						gotoxy (49,30); printf("Nama Pemesan Sebelumnya : %s",saldos[i].Nama);
						gotoxy (49,32); printf("Masukkan Nama Pemesan Terbaru : ");scanf("%s",&saldos[i].Nama);
						gotoxy (49,33); printf("Data Berhasil diubah");
						xEnd=49;yEnd=34;
					}else if(yesno==4){
						gotoxy (49,29); printf("EDIT DATA BERDASARKAN : FASILITAS");
						gotoxy (49,30); printf("Fasilitas Sebelumnya : %s",saldos[i].Fasilitas);
						gotoxy (49,32); printf("Masukkan Fasilitas Terbaru : ");scanf("%s",&saldos[i].Fasilitas);
						gotoxy (49,33); printf("Data Berhasil diubah");
						xEnd=49;yEnd=34;
					}else if(yesno==5){
						gotoxy (49,29); printf("EDIT DATA BERDASARKAN : Jumlah Hari");
						gotoxy (49,30); printf("Jumlah hari Sebelumnya : %d",saldos[i].Hari);
						gotoxy (49,32); printf("Masukkan jumlah hari Terbaru : ");scanf("%d",&saldos[i].Hari);
						gotoxy (49,33); printf("Data Berhasil diubah");
						xEnd=49;yEnd=34;
					}else{
						gotoxy (49,29); printf("Pilihan Tidak ada...");
						xEnd=49;yEnd=30;
					}
				}else{
					gotoxy (54,20); printf("Data %s tidak ditemukan",opId);
					xEnd=54;yEnd=21;
				}
			}
	}else{
		gotoxy (49,18); printf("Pilihan Tidak ada...");
		xEnd=49;yEnd=19;
	}
	}
}

void menuKelima (){
	system ("cls");
	gotoxy (31,5); printf ("+======================================================+");
	gotoxy (42,7); printf ("~ Program Database Hotel SalDos ~");
	gotoxy (50,9); printf ("~ Delete Data ~");
	gotoxy (31,10); printf ("+------------------------------------------------------+");
	gotoxy (31,11); printf ("List No Kamar");
	char kode[3]="AB";
	char id[count][100];
	int Opsi,num;
	char opId[100];
	for(int i=0;i<count;i++){
		if(saldos[i].tipe==1){
			kode[0]='S';
			kode[1]='B';
			saldos[i].nomor=100+saldos[i].NoKamar;
			sprintf(id[i],"%s-%d",kode,saldos[i].NoKamar);
		}else if(saldos[i].tipe==2){
			kode[0]='D';
			kode[1]='B';
			saldos[i].nomor=200+saldos[i].NoKamar;
			sprintf(id[i],"%s-%d",kode,saldos[i].NoKamar);
		}else if(saldos[i].tipe==3){
			kode[0]='P';
			kode[1]='S';
			saldos[i].nomor=300+saldos[i].NoKamar;
			sprintf(id[i],"%s-%d",kode,saldos[i].NoKamar);
	  	}
	  	gotoxy (31,11+i); printf("%d. %s-%d / %d",i+1,kode,saldos[i].NoKamar,saldos[i].nomor);
	}
	if(count==0){
		gotoxy (54,11); printf("= = = TIDAK ADA DATA = = =");
		xEnd=54;yEnd=13;
	}
	else{
	gotoxy (54,11); printf("= = = MENU CARI DATA = = =");
	gotoxy (49,13); printf("Cari Data Hotel SalDos Berdasarkan : ");
	gotoxy (49,14); printf("1. ID Kamar Hotel");
	gotoxy (49,15); printf("2. Nomor Kamar Hotel");
	gotoxy (49,17); printf("Masukkan Pilihan : "); scanf("%d",&Opsi);
	if(Opsi==1){
		gotoxy (49,18); printf("Masukkan ID Kamar Hotel yang dicari : ");scanf("%s",&opId);
			for(int i=0;i<count;i++){
				if(strcmp(opId,id[i])==0){
					gotoxy (54,20); printf("= = = DATA DITEMUKAN = = =");
					gotoxy (49,22); printf("ID Kamar\t\t: %s",id[i]);
					gotoxy (49,23); printf("No Kamar\t\t: %d",saldos[i].nomor);
					gotoxy (49,24); printf("Tipe Kamar\t\t: %d",saldos[i].tipe);
					gotoxy (49,25); printf("Nama Pemesan\t\t: %s",saldos[i].Nama);
					gotoxy (49,26); printf("Fasilitas\t\t: %s",saldos[i].Fasilitas);
					gotoxy (49,27); printf("Total Hari\t\t: %d",saldos[i].Hari);
					gotoxy (49,28); printf("Total Biaya\t\t: %d",saldos[i].Biaya);
				}
				else{
					gotoxy (54,20); printf("Data %s tidak ditemukan",opId);
					xEnd=54;yEnd=21;
				}
			}	
		}
	else if(Opsi==2){
		gotoxy (49,18); printf("Masukkan No Kamar Hotel yang dicari : ");scanf("%d",&num);
			for(int i=0;i<count;i++){
				if(num==saldos[i].nomor){
					gotoxy (54,20); printf("= = = DATA DITEMUKAN = = =");
					gotoxy (49,22); printf("ID Kamar\t\t: %s",id[i]);
					gotoxy (49,23); printf("No Kamar\t\t: %d",saldos[i].nomor);
					gotoxy (49,24); printf("Tipe Kamar\t\t: %d",saldos[i].tipe);
					gotoxy (49,25); printf("Nama Pemesan\t\t: %s",saldos[i].Nama);
					gotoxy (49,26); printf("Fasilitas\t\t: %s",saldos[i].Fasilitas);
					gotoxy (49,27); printf("Total Hari\t\t: %d",saldos[i].Hari);
					gotoxy (49,28); printf("Total Biaya\t\t: %d",saldos[i].Biaya);
				}
				else{
					gotoxy (54,20); printf("Data %d tidak ditemukan",num);
					xEnd=54;yEnd=21;
				}
			}
		}
	}
}

void menuKeenam (){
	system ("cls");
	gotoxy (31,5); printf ("+======================================================+");
	gotoxy (42,7); printf ("~ Program Database Hotel SalDos ~");
	gotoxy (50,9); printf ("~ Sorting Data ~");
	gotoxy (31,10); printf ("+------------------------------------------------------+");
	gotoxy (31,11); printf ("List No Kamar");
	char kode[3]="AB";
	char id[count][100];
	int Opsi,num;
	char opId[100];
	Data temp;
	for(int i=0;i<count;i++){
		if(saldos[i].tipe==1){
			kode[0]='S';
			kode[1]='B';
			saldos[i].nomor=100+saldos[i].NoKamar;
			sprintf(id[i],"%s-%d",kode,saldos[i].NoKamar);
		}else if(saldos[i].tipe==2){
			kode[0]='D';
			kode[1]='B';
			saldos[i].nomor=200+saldos[i].NoKamar;
			sprintf(id[i],"%s-%d",kode,saldos[i].NoKamar);
		}else if(saldos[i].tipe==3){
			kode[0]='P';
			kode[1]='S';
			saldos[i].nomor=300+saldos[i].NoKamar;
			sprintf(id[i],"%s-%d",kode,saldos[i].NoKamar);
	  	}
	  	gotoxy (31,11+i); printf("%d. %s-%d / %d",i+1,kode,saldos[i].NoKamar,saldos[i].nomor);
	}
	if(count==0){
		gotoxy (54,11); printf("= = = TIDAK ADA DATA = = =");
		xEnd=54;yEnd=13;
	}
	else{
	gotoxy (54,11); printf("= = = MENU CARI DATA = = =");
	gotoxy (49,13); printf("Cari Data Hotel SalDos Berdasarkan : ");
	gotoxy (49,14); printf("1. Nomor Kamar Hotel");
	gotoxy (49,16); printf("Masukkan Pilihan : "); scanf("%d",&Opsi);
	if(Opsi == 1){
		for(int i = 0 ; i < count ; i++){
			for(int j = 0 ; j < count-1-i ; j++){
				if((saldos[j].NoKamar < saldos[j+1].NoKamar) > 0){
					temp=saldos[j];
					saldos[j]=saldos[j+1];
					saldos[j+1]=temp;
				}
			}
		}
	}
	printf ("Sorting Berhasil");
	printf ("Lihat Hasil Sorting di Menu 2\n");
	}
}

int main(){
	system ("color 0A");
	loadingA();
	password ();
	back :
	menuUtama ();
	switch (pilihan){
		case 1 :
			menuPertama ();
			gotoxy (xEnd,yEnd);
			printf ("Tekan Apapun Untuk Melanjutkan. . .");
			getch ();
			goto back;
			break;
		case 2 :
			menuKedua ();
			gotoxy (xEnd,yEnd);
			printf ("Tekan Apapun Untuk Melanjutkan. . .");
			getch ();
			goto back;
			break;
		case 3 :
			menuKetiga ();
			gotoxy (xEnd,yEnd);
			printf ("Tekan Apapun Untuk Melanjutkan. . .");
			getch ();
			goto back;
			break;
		case 4 :
			menuKeempat ();
			gotoxy (xEnd,yEnd);
			printf ("Tekan Apapun Untuk Melanjutkan. . .");
			getch ();
			goto back;
			break;
		case 5 :
			menuKelima ();
			printf ("Tekan Apapun Untuk Melanjutkan. . .");
			getch ();
			goto back;
			break;
		case 6 :
			menuKeenam ();
			printf ("Tekan Apapun Untuk Melanjutkan. . .");
			getch ();
			goto back;
			break;
		case 7 :
			exit (0);
		default :
			printf ("Pilihan Tidak Ada !");
			printf ("Tekan Apapun Untuk Melanjutkan . . .");
			getch ();
			system("cls");
			main ();
	}
}

void xy(int x, int y){ 
 	CursorPosition.X = x; 
 	CursorPosition.Y = y; 
 	SetConsoleCursorPosition(console,CursorPosition); 
}
