#include <stdio.h>
#include <string.h>


struct Data{
    long long int NoKamar,Hari;
    char Nama[100],Fasilitas[30];
};

int main(){
    int pilih, pemesan=-1,tipe,total;
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

    struct Data saldos [100];
    if(pilih==1){
        int jml,biayaSB=50000,biayaDB=75000,biayaPS=100000;
    system("cls");
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

    for(int i = 1 ; i <= jml ; i++){
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
        scanf("%d", &tipe);
        switch(tipe){
        case 1:
             printf("n\t\t\t\t|\t Masukkan No Kamar : ");
             scanf("%d", &saldos[pemesan].NoKamar);
             printf("\t\t\t\t|\t Masukkan Nama Pemesan : ");
             scanf("%s", &saldos[pemesan].Nama);
             printf("\t\t\t\t|\t Jumlah hari Pemesanan : ");
             scanf("%d", &saldos[pemesan].Hari);
             printf("\t\t\t\t|\t Fasilitas Tambahan : ");
             scanf("%s", &saldos[pemesan].Fasilitas);
             total = biayaSB*saldos[pemesan].Hari;
             printf("\t\t\t\t|\t Total Biaya adalah : %d ", total);
             printf("\n\t\t\t\t|\t Kamar SB-%lld Berhasil dipesan !", saldos[pemesan].NoKamar);
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
             scanf("%lld", &saldos[pemesan].NoKamar);
             printf("\t\t\t\t|\t Masukkan Nama Pemesan : ");
             scanf("%s", &saldos[pemesan].Nama);
             printf("\t\t\t\t|\t Jumlah hari Pemesanan : ");
             scanf("%lld", &saldos[pemesan].Hari);
             printf("\t\t\t\t|\t Fasilitas Tambahan : ");
             scanf("%s", &saldos[pemesan].Fasilitas);
             total = biayaDB*saldos[pemesan].Hari;
             printf("\t\t\t\t|\t Total Biaya adalah : %d ", total);
             printf("\n\t\t\t\t|\t Kamar DB-%lld Berhasil dipesan !", saldos[pemesan].NoKamar);
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
             scanf("%lld", &saldos[pemesan].NoKamar);
             printf("\t\t\t\t|\t Masukkan Nama Pemesan : ");
             scanf("%s", &saldos[pemesan].Nama);
             printf("\t\t\t\t|\t Jumlah hari Pemesanan : ");
             scanf("%lld", &saldos[pemesan].Hari);
             printf("\t\t\t\t|\t Fasilitas Tambahan : ");
             scanf("%s", &saldos[pemesan].Fasilitas);
             total = biayaPS*saldos[pemesan].Hari;
             printf("\t\t\t\t|\t Total Biaya adalah : %d ", total);
             printf("\n\t\t\t\t|\t Kamar PS-%lld Berhasil dipesan !", saldos[pemesan].NoKamar);
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


    else if(pilih==2){
        system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t\t<======================================================================>\n");
    printf("\n\t\t\t\t\t- - - Program Database Hotel SALDOS - - -");
    printf("\n\t\t\t\t\t\t- - - VIEW DATA - - -\n");
    printf("\+------------------------------------------------------------------------------------------------------+\n");
    printf("\t\tID KAMAR\t|NO KAMAR\t|NAMA PEMESAN\t|FASILITAS TAMBAHAN\t|HARI\t|BIAYA");
    printf("\n+-------------------------------------------------------------------------------------------------------+");
    for(int i =1; i<=saldos;i++){
    printf("\t\t|-%d", saldos[pemesan].NoKamar);
    printf("|%d%d\t",tipe,saldos[pemesan].NoKamar);
    printf("|%d\t", tipe);
    printf("|%s\t",saldos[pemesan].Nama);
    printf("|%s\t", saldos[pemesan].Fasilitas);
    printf("|%d",saldos[pemesan].Hari);
    printf("|%d",total);
    }
    printf("\n\nTekan ENTER untuk Melanjutkan...");
    getch();
    main();

    }


    else{
        printf("\n\t\t\t\t|\t\t Pilihan Tidak ada... \t\t\t|");
        printf("\n\t\t\t\t|\t Tekan ENTER untuk melanjutkan....");
        getch();
        main();
    }

    return 0;
}
