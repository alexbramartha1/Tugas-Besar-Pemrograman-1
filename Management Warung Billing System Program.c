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

int main(){
    /*ungsi untuk mengubah warna background terminal menjadi putih dan font menjadi hitam
      F untuk background putih dan 0 untuk font hitam*/
    system("color F0");
	
    //Memanggil fungsi header
    header();
	
    system("cls");
}

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
	printf("\t\t\t\t\t    1. I Gede Alex Bramartha	        (2105551024)        \n");
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

//=======================================================================//
//Nama Fungsi     : Sign Up                       		         //
//Input Argumen   : char l.username[20], char l.password[20],            //
//                  char l.no_hp[15], dan char l.nama[100]               //
//Output Argumen  : char l.nama[100]                                     //
//Deskripsi       : Fungsi yang ditujukan untuk menginput nama, nomor hp,//
//                  password, dan username yang disimpan ke file         //
//                  Login User.txt yang nantinya akan divalidasi saat    //
//                  Sign In ke program           		 	 //
//Tgl             : 23-12-2021                                           //
//Oleh            : I Gede Alex Bramartha                                //
//NIM		  : 2105551024						 //
//Kelas           : A                                                    //
//=======================================================================//
void sign_up(){
    //Membuat pointer daftar untuk file "Login User.txt"
    FILE *daftar;

    //Membuka file "Login User.txt" dengan mode "w" (write)
    daftar = fopen(login_file,"w");
    
    //Mengecek apakah pointer daftar menunjuk kepada file yang dituju ("Login User.txt")
    if(daftar == NULL){
        printf("Maaf Penyimpanan File TIDAK TERSEDIA");
        exit(1);
    }
	
    //Instruksi untuk menginput data diri user
    printf("\t\t\t\t\t=========================================================  \n");
    printf("\t\t\t\t\t               Silahkan Isi Data Diri Anda	         \n");
    printf("\t\t\t\t\t---------------------------------------------------------  \n");
    getch();
    printf("\t\t\t\t\t Nama Lengkap    : ");
    scanf("\n%[^\n]s", l.nama);
    printf("\t\t\t\t\t Nomor Handphone : ");
    scanf("%s", l.no_hp);
	
    //Instruksi untuk menginput username dan password dari user
    printf("\n\t\t\t\t\t---------------------------------------------------------\n");
    printf("\t\t\t\t\t Hey %s!\n", l.nama);
    printf("\t\t\t\t\t Buat username dan password anda\n");
    printf("\t\t\t\t\t---------------------------------------------------------  \n");
    getch();
    printf("\t\t\t\t\t Enter Username : ");
    scanf("\n%s", l.username);
    printf("\t\t\t\t\t Enter Password : ");
    scanf("%s", l.password);

    //Menulis seluruh input pengguna kedalam file "Login User.txt"
    fwrite(&l, sizeof(l), 1, daftar);
    fclose(daftar);
    printf("\n\t\t\t\t\t Sign Up Success!");
    printf("\n\t\t\t\t\t Akun anda sudah dibuat!");
    printf("\n\t\t\t\t\t=========================================================\n");
    getch();
    
    //Membersihkan layar terminal
    system("cls");
     
    //Memanggil Fungsi Sign In
    sign_in();
}

//=======================================================================//
//Nama Fungsi     : Sign In                       		         //
//Input Argumen   : char l.username[20] dan char l.password[20]          //
//Output Argumen  : -                                                    //
//Deskripsi       : Fungsi yang ditujukan untuk menginput username dan   //
//                  password agar bisa melanjutkan program ke menu       //
//                  selanjutnya                                          //
//Tgl             : 23-12-2021                                           //
//Oleh            : I Gede Alex Bramartha                                //
//NIM		  : 2105551024						 //
//Kelas           : A                                                    //
//=======================================================================//
void sign_in(){
    /*Variabel username[20] dengan tipe data char yang digunakan untuk menyimpan input 
      username oleh pengguna. Inputan tersebut akan digunakan untuk validasi username 
      yang sudah terdaftar pada file Login User.txt*/
    char username[20];

    /*Variabel password[20] dengan tipe data char yang digunakan untuk menyimpan input 
      password oleh pengguna. Inputan tersebut akan digunakan untuk validasi password 
      yang sudah terdaftar pada file Login User.txt*/
    char password[20];
	
    //Variabel pilihan dengan tipe data integer yang digunakan untuk menyimpan pilihan user antara Sign In, Sign Up, dan Exit
    int pilihan;

    //Membuat pointer login untuk file "Login User.txt"
    FILE *login;
    
    //Membuka file "Login User.txt" dengan mode "r" (read)
    login = fopen (login_file, "r");
	
    //Mengecek apakah pointer login menunjuk kepada file yang dituju ("Login User.txt")
    if(login == NULL){
        printf("Maaf Penyimpanan File TIDAK TERSEDIA\n");
        sign_up();
    }
    
    //Instruksi untuk menginput username dan password dari user
    printf("\t\t\t\t\t=========================================================\n");
    printf("\t\t\t\t\t\t                   Sign In	                       \n");
    printf("\t\t\t\t\t---------------------------------------------------------\n");
    printf("\t\t\t\t\t	Username : ");
    scanf("%s", username);
    printf("\t\t\t\t\t	Password : ");
    scanf("%s", password);

    system("cls");
    
    //Membeaca file "Login User.txt"
    while(fread(&l, sizeof(l), 1, login)){
	    
        /*Compare username dan password yang diinput user kedalam fungsi
          sign_in dengan username serta password yang sudah terdaftar saat di
	  menu Sign Up*/
        if(strcmp(username, l.username)==0 && strcmp(password, l.password)==0){
		printf("\t\t\t\t\t=========================================================\n");
		printf("\t\t\t\t\t                    Sign In SUCCESS!	                   \n");
		printf("\t\t\t\t\t---------------------------------------------------------\n");
		getch();
		system("cls");	
        }
        else{
		
		/*Jika akun tidak ada di Login User.txt maka akan diberikan pilihan Sign Up atau keluar dari program
		dan Sign In kembali jika misalkan ada kesalahan pada pengetikan tadi*/
		printf("\t\t\t\t\t=========================================================\n");
		printf("\t\t\t\t\t                 Akun Anda BELUM TERDAFTAR	           \n");
		start:
		printf("\t\t\t\t\t---------------------------------------------------------\n");
		printf("\t\t\t\t\t    1. Sign In		                           \n");
		printf("\t\t\t\t\t    2. Sign Up			                   \n");
		printf("\t\t\t\t\t    3. Exit					           \n");
	        printf("\t\t\t\t\t---------------------------------------------------------\n");
            	printf("\t\t\t\t\t  Pilihan : ");
           	scanf("%d", &pilihan);
            
             	system("cls");
           
            	if(pilihan == 1){
                     sign_in();
            	} 
            	else if(pilihan == 2){
                     sign_up();
            	} 
            	else if(pilihan == 3){
		     printf("\t\t\t\t\t=========================================================\n");
	             printf("\t\t\t\t\t        Terima Kasih Sudah Menggunakan Program Ini       \n");
		     printf("\t\t\t\t\t---------------------------------------------------------\n");
		     getch();
	             system("cls");	
		     exit(0);
            	} 
            	else{
                     printf("\t\t\t\t\t=========================================================\n");
	             printf("\t\t\t\t\t                    SOMETHING WRONG!                     \n");
		     printf("\t\t\t\t\t---------------------------------------------------------\n");
                     goto start;
                }
        }
    }
    fclose(login);
    return;
}
