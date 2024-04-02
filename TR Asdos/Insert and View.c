#include <stdio.h>
#include <string.h>

struct Data{
    long long int NoKamar,Hari;
    int tipe,total;
    char Nama[100],Fasilitas[30];
}saldos [100];

void tambah(int jml,int i){
    system("cls");
    int biayaSB=50000,biayaDB=75000,biayaPS=100000;
    printf("\n\n\n\n");
    printf("\t\t\t\t<======================================================>\n");
    printf("\n\t\t\t\t\t- - - Program Database Hotel SALDOS - - -");
    printf("\n\t\t\t\t\t\t- - - INSERT DATA - - -\n");
    printf("\n\t\t\t\t<=======================================================>\n");
    printf("\n\t\t\t\t|\t\t\t\t\t\t\t|");
    printf("\n\t\t\t\t|\t Masukkan Jumlah Data (Maks 5) : ");
    scanf("%d", &jml);
    if(jml > 5 || jml < 1){
        printf("\t\t\t\t\t Maks Input Hanya 5!");
        getch();
        main();
    }

    for(i = 1 ; i <= jml ; i++){
        system("cls");
        printf("\n\n\n\n");
        printf("\t\t\t\t<======================================================>\n");
        printf("\n\t\t\t\t\t- - - Program Database Hotel SALDOS - - -");
        printf("\n\t\t\t\t\t\t- - - INSERT DATA - - -\n");
        printf("\t\t\t\t\t\t- - - DATA KE - %d - - -\n", i);
        printf("\n\t\t\t\t<=======================================================>\n");
        printf("\n\t\t\t\t|\t\t\t\t\t\t\t|");
        printf("\n\t\t\t\t|\t Tipe Kamar :\t\t\t\t\t|");
        printf("\n\t\t\t\t|\t 1. Single Bed (SB)\t\t\t\t|");
        printf("\n\t\t\t\t|\t 2. Double Bed (DB)\t\t\t\t|");
        printf("\n\t\t\t\t|\t 3. President Suite (PS)\t\t\t|");
        printf("\n\t\t\t\t|\t Pilih Tipe Kamar  : ");
        scanf("%d", &saldos[jml].tipe);
        switch(saldos[jml].tipe){
        case 1:
             printf("n\t\t\t\t|\t Masukkan No Kamar : ");
             scanf("%d", &saldos[jml].NoKamar);
             printf("\t\t\t\t|\t Masukkan Nama Pemesan : ");
             scanf("%s", &saldos[jml].Nama);
             printf("\t\t\t\t|\t Jumlah hari Pemesanan : ");
             scanf("%d", &saldos[jml].Hari);
             printf("\t\t\t\t|\t Fasilitas Tambahan : ");
             scanf("%s", &saldos[jml].Fasilitas);
             saldos[jml].total = biayaSB*saldos[jml].Hari;
             printf("\t\t\t\t|\t Total Biaya adalah : %d ", saldos[jml].total);
             printf("\n\t\t\t\t|\t Kamar SB-%lld Berhasil dipesan !", saldos[jml].NoKamar);
             if(jml==i){
             getch();
             main();
             }
             else{
                getch();
             }
             break;
        case 2:
             printf("\t\t\t\t|\t Masukkan No Kamar : ");
             scanf("%lld", &saldos[jml].NoKamar);
             printf("\t\t\t\t|\t Masukkan Nama Pemesan : ");
             scanf("%s", &saldos[jml].Nama);
             printf("\t\t\t\t|\t Jumlah hari Pemesanan : ");
             scanf("%lld", &saldos[jml].Hari);
             printf("\t\t\t\t|\t Fasilitas Tambahan : ");
             scanf("%s", &saldos[jml].Fasilitas);
             saldos[jml].total = biayaDB*saldos[jml].Hari;
             printf("\t\t\t\t|\t Total Biaya adalah : %d ", saldos[jml].total);
             printf("\n\t\t\t\t|\t Kamar DB-%lld Berhasil dipesan !", saldos[jml].NoKamar);
             if(jml==i){
             getch();
             main();
             }
             else{
                getch();
             }
             break;
        case 3:
             printf("\t\t\t\t|\t Masukkan No Kamar : ");
             scanf("%lld", &saldos[jml].NoKamar);
             printf("\t\t\t\t|\t Masukkan Nama Pemesan : ");
             scanf("%s", &saldos[jml].Nama);
             printf("\t\t\t\t|\t Jumlah hari Pemesanan : ");
             scanf("%lld", &saldos[jml].Hari);
             printf("\t\t\t\t|\t Fasilitas Tambahan : ");
             scanf("%s", &saldos[jml].Fasilitas);
             saldos[jml].total = biayaPS*saldos[jml].Hari;
             printf("\t\t\t\t|\t Total Biaya adalah : %d ", saldos[jml].total);
             printf("\n\t\t\t\t|\t Kamar PS-%lld Berhasil dipesan !", saldos[jml].NoKamar);
             if(jml==i){
             getch();
             main();
             }
             else{
                getch();
             }
             break;
        default :
             printf("\t\t\t\t|\t Tidak ada Tipe Kamar !");
             getch ();
             main();
             break;
        }
    }
}


void tampil(int jml,int i){
    system("cls");
    if(jml==0){
        printf("\n\n\n\n");
        printf("\t\t\t<======================================================================>\n");
        printf("\n\t\t\t\t\t- - - Program Database Hotel SALDOS - - -");
        printf("\n\t\t\t\t\t\t- - - VIEW DATA - - -\n");
        printf("\n\t\t+-------------------------------------------------------------------------------------------+\n");
        printf("\t\t\t\t+TIDAK ADA DATA\t\t+");
        printf("\n\t\t+-------------------------------------------------------------------------------------------+");
        printf("\n\n\n\n\t\t\tTekan ENTER untuk Melanjutkan...");
        getch();
        main();
    }
    else if(jml > 5 || jml < 1){
    jml++;
    printf("\n\n\n\n");
    printf("\t\t\t<======================================================================>\n");
    printf("\n\t\t\t\t\t- - - Program Database Hotel SALDOS - - -");
    printf("\n\t\t\t\t\t\t- - - VIEW DATA - - -\n");
    printf("\n\t\t+-------------------------------------------------------------------------------------------+\n");
    printf("\t\tID KAMAR\t|NO KAMAR\t|TIPE\t|NAMA PEMESAN\t|FASILITAS TAMBAHAN\t|HARI\t|BIAYA");
    printf("\n\t\t+-------------------------------------------------------------------------------------------+");
    for(i =1; i<=jml;i++){
    printf("\t\t\t\t\t-%d", saldos[i].NoKamar);
    printf("\t\t|%d%d\t",saldos[i].tipe,saldos[i].NoKamar);
    printf("\t|%d\t", saldos[i].tipe);
    printf("|%s\t",saldos[i].Nama);
    printf("\t|%s\t", saldos[i].Fasilitas);
    printf("\ta\t|%d",saldos[i].Hari);
    printf("\t|%d",saldos[i].total);
    }
    printf("\n\n\n\n\t\t\tTekan ENTER untuk Melanjutkan...");
    getch();
    main();
    }

}


int main(){
    int pilih,jml,i;
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t\t<======================================================>\n");
    printf("\n\t\t\t\t\t- - - Program Database Hotel SALDOS - - -");
    printf("\n\t\t\t\t\t\t- - - DAFTAR MENU - - -\n");
    printf("\n\t\t\t\t<=======================================================>\n");
    printf("\n\t\t\t\t|\t\t\t\t\t\t\t|");
    printf("\n\t\t\t\t|\t Tekan 1. Menambahkan Data Hotel SALDOS\t\t|");
    printf("\n\t\t\t\t|\t Tekan 2. Menampilkan Data Hotel SALDOS\t\t|");
    printf("\n\t\t\t\t|\t Tekan 3. Menghapus  Data Hotel SALDOS\t\t|");
    printf("\n\t\t\t\t|\t Tekan 4. Mengedit Data Hotel SALDOS\t\t|");
    printf("\n\t\t\t\t|\t\t\t\t\t\t\t|\n");
    printf("\t\t\t\t|\t Masukkan Pilihan Anda : ");
    scanf("%d", &pilih);
    printf("\n\t\t\t\t<=======================================================>\n");

    switch(pilih){
    case 1: tambah(jml,i);break;
    case 2: tampil(jml,i);break;
    default :
        printf("\n\t\t\t\t|\t\t Pilihan Tidak ada... \t\t\t|");
        printf("\n\t\t\t\t|\t Tekan ENTER untuk melanjutkan....");
        getch();
        main();
    }
    return 0;
}

