//Library standar yang digunakan pada bahasa C
#include <stdio.h> 	//Library dalam bahasa pemrograman C yang berfungsi sebagai input-output
#include <math.h> 	//Library dalam bahasa pemrograman C yang berfungsi sebagai mendefinisikan fungsi matematika dan makro
#include <stdlib.h> 	//Library dalam bahasa pemrograman C yang berfungsi sebagai operasi pembanding dan operasi konversi
#include <string.h> 	//Library dalam bahasa pemrograman C yang berfungsi sebagai tempat penyimpanan fungsi-fungsi yang digunakan untuk menangani string ataupun substring
#include <time.h> 	//Library dalam bahasa pemrograman C yang berfungsi sebagai mengkonversi antara waktu berbagai format tanggal

// Struct Login untuk menyimpan beberapa data user yaitu nama, username, password, dan nomor handphone
typedef struct{
    char nama[100];
    char username[20];
    char password[20];
    char no_hp[15];
}Login;

Login l; //Mendeklarasikan variabel l di struct Login

void header();				//Merupakan fungsi yang digunakan untuk menampilkan halaman perkenalan pembuat program ini
void menu_log();			//Merupakan fungsi yang digunakan untuk menampilkan halaman login berisi Sign In, Sign Up, dan Exit
void sign_in();				//Merupakan fungsi yang digunakan untuk Sign In atau masuk ke aplikasi menggunakan username dan password yang telah dibuat di menu Sign Up tadi dan akan lanjut ke Menu Utamanya
void sign_up();				//Merupakan fungsi yang digunakan untuk menyimpan perintah-perintah Sign Up (pendaftaran user) dan nantinya akan menyimpan nama, nomor handphone, username, dan password
char login_file[] = "Login User.txt";	//Assign login_file agar menyimpan string "Login User.txt"



//=======================================================================//
//Nama Fungsi     : Header Program                                       //
//Input Argumen   : -                                                    //
//Output Argumen  : -                                                    //
//Deskripsi       : Menampilkan Header Nama Kelompok saat pertama kali   //
//                  menjalankan program Management Warung Billing System //
//                  Program ini.                                         //
//Tgl             : 22-12-2021                                           //
//Oleh            : I Made Satya Rama Sai Natha                          //
//NIM		  : 2105551039						 //
//Kelas           : B                                                    //
//=======================================================================//

//Menampilkan header nama kelompok pada saat memulai program Management Warung Billing System System Program
void header(){
    system ("cls");
	printf("\t\t\t\t\t========================================================= \n");
	printf("\t\t\t\t\t                  Management Warung                       \n");
	printf("\t\t\t\t\t               Billing System Program                     \n");
	printf("\t\t\t\t\t--------------------------------------------------------- \n");
	printf("\t\t\t\t\t       Program dibuat berkelompok 2 orang oleh:           \n");
	printf("\t\t\t\t\t    1. I Gede Alex Bramartha		    (2105551024)    \n");
	printf("\t\t\t\t\t    2. I Made Satya Rama Sai Natha	(2105551039)        \n");
	printf("\t\t\t\t\t--------------------------------------------------------- \n");
	printf("\t\t\t\t\t       Selamat Datang di Program Management Warung  \n");
	printf("\t\t\t\t\t========================================================= \n");
	printf("\t\t\t\t\t       	 Tekan ENTER untuk memulai program \n");
	getch();
    system("cls");
    menu_log();
}


//=======================================================================//
//Nama Fungsi     : Menu Login                        		         //
//Input Argumen   : int pilihan                                          //
//Output Argumen  : -                                                    //
//Deskripsi       : Menampilkan menu pilihan cara masuk ke program ini   //
//                  didalamnya berisi pilihan Sign In jika sudah punya   //
//                  akun, lalu Sign Up untuk daftar membuat akun dan     //
//		    exit untuk keluar program			 	 //
//Tgl             : 23-12-2021                                           //
//Oleh            : I Gede Alex Bramartha                                //
//NIM		  : 2105551024						 //
//Kelas           : A                                                    //
//=======================================================================//

//Menampilkan Menu Login untuk memilih cara masuk ke program ini
void menu_log(){
    //Variabel pilihan dengan tipe data integer yang digunakan untuk menyimpan pilihan user antara Sign In, Sign Up, dan Exit
    int pilihan;	

    //start sebagai penanda lokasi mulai
    start:		
	printf("\t\t\t\t\t=========================================================\n");
	printf("\t\t\t\t\t                    Pilih Cara Masuk	                   \n");
	printf("\t\t\t\t\t---------------------------------------------------------\n");
	printf("\t\t\t\t\t    1. Sign In			                   \n");
	printf("\t\t\t\t\t    2. Sign Up					   \n");
	printf("\t\t\t\t\t    3. Exit       					   \n");
	printf("\t\t\t\t\t---------------------------------------------------------\n");
	printf("\t\t\t\t\t        Welcome to Program Management Warung 	           \n");
	printf("\t\t\t\t\t---------------------------------------------------------\n");
  	printf("\t\t\t\t\t      Masukkan angka pilihan untuk melanjutkan = ");
	scanf("%d", &pilihan);
     
    //Membersihkan layar terminal
    system("cls");
    
    /*Percabangan Switch dengan kondisi nilai yang disimpan pada variabel pilihan 
    jika user menuliskan 1 maka yang akan dipanggil adalah fungsi sign_in()
    jika pengguna menuliskan 2 maka akan dipanggil fungsi sign_up(), jika 3 maka akan keluar dari program,
    dan jika selain dari itu akan secara otomatis pergi ke label start*/
    switch(pilihan){
    	case 1:
		//Jika pengguna menginput angka 1 maka dipanggil fungsi Sign In
        	sign_in();
       		break;
    	case 2:
		//Jika pengguna menginput angka 2 maka dipanggil fungsi Sign Up
        	sign_up();
        	break;
    	case 3:
		//Jika pengguna menginput angka 3 maka akan muncul output berikut
		printf("\t\t\t\t\t=========================================================\n");
		printf("\t\t\t\t\t        Terima Kasih Sudah Menggunakan Program Ini       \n");
		printf("\t\t\t\t\t---------------------------------------------------------\n");
        	
		//Fungsi untuk menangkap karakter
		getch();
	  	
		system("cls");
		
		//Fungsi keluar dari program
		exit(0); 
        	break;
    	default:
		//Kembali ke label start jika terjadi kesalahan dalam menginput pilihan
        	goto start;
        	break;
    }
}
