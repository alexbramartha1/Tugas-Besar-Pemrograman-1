//Library standar yang digunakan pada bahasa C
#include <stdio.h> //Library dalam bahasa pemrograman C yang berfungsi sebagai input-output
#include <math.h> //Library dalam bahasa pemrograman C yang berfungsi sebagai mendefinisikan fungsi matematika dan makro
#include <stdlib.h> //Library dalam bahasa pemrograman C yang berfungsi sebagai operasi pembanding dan operasi konversi
#include <string.h> //Library dalam bahasa pemrograman C yang berfungsi sebagai tempat penyimpanan fungsi-fungsi yang digunakan untuk menangani string ataupun substring
#include <time.h> //Library dalam bahasa pemrograman C yang berfungsi sebagai mengkonversi antara waktu berbagai format tanggal

void header();



  //=======================================================================//
  //Nama Fungsi     : Header Program                                       //
  //Input Argumen   : -                                                    //
  //Output Argumen  : -                                                    //
  //Deskripsi       : Menampilkan Header Nama Kelompok saat pertama kali   //
  //                  menjalankan program Management Warung Billing System //
  //                  Program ini.                                         //
  //Tgl             : 12-12-2021                                           //
  //Oleh            : I Made Satya Rama Sai Natha                          //
  //Kelas           : B                                                    //
  //=======================================================================//

//Menampilkan header nama kelompok pada saat memulai program Management Warung Billing System System Program
void header(){
    system ("cls");
	printf("\t\t\t\t\t=========================================================\n");
	printf("\t\t\t\t\t                  Management Warung                 \n");
	printf("\t\t\t\t\t               Billing System Program               \n");
	printf("\t\t\t\t\t---------------------------------------------------------\n");
	printf("\t\t\t\t\t       Program dibuat berkelompok 2 orang oleh:     \n");
	printf("\t\t\t\t\t    1. I Gede Alex Bramartha		    (2105551024)    \n");
	printf("\t\t\t\t\t    2. I Made Satya Rama Sai Natha	(2105551039)    \n");
	printf("\t\t\t\t\t---------------------------------------------------------\n");
	printf("\t\t\t\t\t       Selamat Datang di Program Management Warung  \n");
	printf("\t\t\t\t\t=========================================================\n");
	printf("\t\t\t\t\t       	 Tekan ENTER untuk memulai program \n");
	getch();
    system("cls");
    menu_log();

