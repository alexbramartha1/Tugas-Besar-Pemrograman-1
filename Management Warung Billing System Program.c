//Library standar yang digunakan pada bahasa C
#include <stdio.h> 	 //Library dalam bahasa pemrograman C yang berfungsi sebagai input-output
#include <math.h> 	 //Library dalam bahasa pemrograman C yang berfungsi sebagai mendefinisikan fungsi matematika dan makro
#include <stdlib.h> 	 //Library dalam bahasa pemrograman C yang berfungsi sebagai operasi pembanding dan operasi konversi
#include <string.h> 	 //Library dalam bahasa pemrograman C yang berfungsi sebagai tempat penyimpanan fungsi-fungsi yang digunakan untuk menangani string ataupun substring
#include <time.h> 	 //Library dalam bahasa pemrograman C yang berfungsi sebagai mengkonversi antara waktu berbagai format tanggal
#define BUFFER_SIZE 1000 //Mendefine variabel BUFFER_SIZE dengan nilai 1000

//Deklarasi variabel global yang dipakai pada program ini.
int banyak;			//Variabel banyak dengan tipe data integer yang digunakan untuk menyimpan input user mengenai jumlah produk yang dibeli pada kasir offline dan online
int i;				//Variabel i dengan tipe data integer yang digunakan untuk menyimpan nilai increment pada proses looping yang terdapat pada beberapa fungsi nanti
int total_bar[1000];		//Variabel total_bar dengan tipe data integer yang digunakan untuk menyimpan input user mengenai total per masing-masing produk yang dibeli pada kasir offline dan online
double harga_bar[1000];		//Variabel harga_bar dengan tipe data double yang digunakan untuk menyimpan input user mengenai harga per masing-masing produk yang dibeli pada kasir offline dan online		
double uang;			//Variabel uang dengan tipe data double yang digunakan untuk menyimpan input user mengenai jumlah uang customer yang dibayarkan pada saat di kasir offline dan online
double hasil;			//Variabel hasil dengan tipe data double yang digunakan untuk menyimpan hasil operasi dari variabel harga_bar yang akan dikali dengan variabel total_bar
double hasil2;			//Variabel hasil2 dengan tipe data double yang digunakan untuk menyimpan hasil operasi dari variabel uang yang akan dikurangi dengan variabel hasil
char nama_bar[100][100];	//Variabel nama_bar dengan tipe data char yang digunakan untuk menyimpan input dari user mengenai nama produk yang dibeli di kasir offline dan online
char pegawai[100];		//Variabel pegawai dengan tipe data char yang digunakan untuk menyimpan input dari user mengenai nama pegawai yang melayani pembelian di kasir offline dan online
char customer[100];		//Variabel customer dengan tipe data char yang digunakan untuk menyimpan input dari user mengenai nama customer yang melakukan pembelian di kasir offline dan online
char type[25];			//Variabel type dengan tipe data char yang digunakan untuk menyimpan input dari user mengenai tipe pembelian jika di offline apakah Take Away atau Dine In sedangkan di online apakah dari aplikasi gojek, shopee food, atau grab food
char pengemudi[100];		//Variabel pengemudi dengan tipe data char yang digunakan untuk menyimpan input dari user mengenai siapa pengemudi yang memesan di kasir online
time_t waktuserver;		//Variabel waktuserver yang digunakan untuk mengambil waktu dari sistem

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

void pilihan_menu();			//Merupakan fungsi yang digunakan untuk menampilkan halaman menu utama dari program ini
void kasir_offline();			//Merupakan fungsi yang digunakan untuk menampilkan halaman kasir offline dari program ini
void kasir_online();			//Merupakan fungsi yang digunakan untuk menampilkan halaman kasir online dari program ini

void waktu();				//Merupakan fungsi yang digunakan untuk menampilkan waktu yang diambil dari sistem	
void struk();				//Merupakan fungsi yang digunakan untuk menampilkan inputan dari fungsi kasir_offline
void struk2();				//Merupakan fungsi yang digunakan untuk menampilkan inputan dari fungsi kasir_online

void add();
void display();
char recordInven[] = "Penampungan.txt"
int main(){
    /*fungsi untuk mengubah warna background terminal menjadi putih dan font menjadi hitam
      F untuk background putih dan 0 untuk font hitam*/
    system("color F0");
	
    //Memanggil fungsi header
    header();
	
    system("cls");
    return(0);
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
        printf("\t\t\t\t\t=========================================================\n");
	printf("\t\t\t\t\t          FILE IS NOT FOUND IN YOUR DIRECTORY	           \n");
	printf("\t\t\t\t\t---------------------------------------------------------\n");
	getch();
	system("cls");
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
    printf("\n\t\t\t\t\t Sign Up SUCCESS!");
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
        printf("\t\t\t\t\t=========================================================\n");
	printf("\t\t\t\t\t          FILE IS NOT FOUND IN YOUR DIRECTORY	           \n");
	printf("\t\t\t\t\t---------------------------------------------------------\n");
	getch();
	system("cls");
	
	//Ke fungsi Sign Up jika tidak ada file di directory
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
    
    //Membaca file "Login User.txt"
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

//=======================================================================//
//Nama Fungsi     : Pilihan Menu                       		         //
//Input Argumen   : int pilihan						 //
//Output Argumen  : -                                                    //
//Deskripsi       : Menu utama program Management Warung Billing System  //
//		    program yang memuat berbagai fungsi sesuai dengan na-//
//                  ma atau judul yang tertera 				 //
//                                                            		 //
//Tgl             : 23-12-2021                                           //
//Revisi          : 1                                          		 //
//Oleh            : I Made Satya Rama Sai Natha                          //
//NIM		  : 2105551039						 //
//Kelas           : B                                                    //
//=======================================================================//

/*Menampilkan Pilihan Menu yang ingin dijalankan dan terdapat beberapa pilihan yang tersedia seperti 
Kasir Offline, Kasir Online, Tambah Barang, Display Barang, dan juga pilihan Exit untuk keluar dari program*/
void pilihan_menu(){
	/*Variabel pilihan dengan tipe data integer yang digunakan untuk menyimpan pilihan user antara Kasir Online,
	Kasir Offline, Tambah Barang, Display Barang, Exit*/
	int pilihan;
	
	/*statemen DO akan dijalankan secara berulang selama kondisi syarat pada WHILE masih terpenuhi atau bernilai benar. 
	Perulangan akan berhenti jika kondisi syarat pada WHILE bernilai salah. Pada perulangan DO WHILE, statemen program 
	akan dijalankan setidaknya sekali sebelum mengecek kondisi syarat pada WHILE */
	do{
		//menampilkan beberapa pilihan pada menu utama yang ingin digunakan atau dijalankan oleh user
		system("cls");
		printf("\t\t\t\t\t=========================================================\n");
		printf("\t\t\t\t\t                 Menu Plihan Pembayaran	           \n");
		printf("\t\t\t\t\t---------------------------------------------------------\n");
		printf("\t\t\t\t\t    1. Kasir Offline   				   \n");
		printf("\t\t\t\t\t    2. Kasir Online			       	           \n");
		printf("\t\t\t\t\t    3. Tambah Produk					   \n");
		printf("\t\t\t\t\t    4. Display Produk					   \n");
		printf("\t\t\t\t\t    5. Delete Produk					   \n");
		printf("\t\t\t\t\t    6. Exit					           \n");
		printf("\t\t\t\t\t---------------------------------------------------------\n");
  		printf("\t\t\t\t\t      Masukkan angka pilihan untuk melanjutkan = ");
		//meng scan apa yang dipilih oleh user dengan tipe data integer
		scanf("%d", &pilihan);
    		//fungsi system("cls") digunakan untuk menghilangkan tampilan program sebelumnya agar terlihat lebih rapi 
		system("cls");
		
	/* fungsi switch case yaitu sebuah tahap dimana program akan melakukan pengecekan kondisi. Seleksi bisa digunakan 
	untuk menentukan bagian program/statement mana yang akan dijalankan jika kondisi tertentu terpenuhi*/
	switch(pilihan){
    		case 1:
			//jika user memilih case 1 akan dibawa kepada void kasir_offline
    			kasir_offline();
        		break;
    		case 2:
			//jika user memilih case 2 akan dibawa kepada void kasir_online
    			kasir_online();
        		break;
    		case 3:
			//jika user memilih case 3 akan dibawa kepada void add
			add();
        		break;
		case 4:
			//jika user memilih case 4 akan dibawa kepada void display
			display();
			break;	
		case 5:
			//jika user memilih case 5 akan dibawa kepada void delete
			delete();
			break;
		case 6:
			/*jika user memilih case 6 akan dibawa kepada output yang berisikan akhir dari program karena
			case 5 merupakan pilihan untuk Exit dari program*/
			system("cls");
			printf("\t\t\t\t\t=========================================================\n");
			printf("\t\t\t\t\t        Terima Kasih Sudah Menggunakan Program Ini       \n");
			printf("\t\t\t\t\t---------------------------------------------------------\n");
			getch();
			system("cls");	
			exit(0);
			break;
   		}	
	}
	//ketika pilihan case 5 fungsi dari While akan berjalan setelah selesai dari case 5
	while(pilihan != 6);
	system("cls");
}

//=======================================================================//
//Nama Fungsi     : Kasir Offline                       		 //
//Input Argumen   : char pegawai[100], char costumer[100], char type[25] // 
//		    int banyak, float uang				 //
//Output Argumen  : hasil, hasil2                                        //
//Deskripsi       : salah satu dari 5 fitur yang ada. ini merupakan fitur//
//		    kasir offline yang digunakan user untuk menyetak str-//
//                  uk yang melakukan pembelian secara offline		 //
//                                                            		 //
//Tgl             : 23-12-2021                                           //
//Revisi          : 0                                          		 //
//Oleh            : I Made Satya Rama Sai Natha                          //
//NIM		  : 2105551039						 //
//Kelas           : B                                                    //
//=======================================================================//

// Menampilkan void kasir_offline jika void kasir_offline di panggil saat pilihan_menu case 1
void kasir_offline(){
	/*Variabel pilihan dengan tipe data integer yang digunakan untuk menyimpan pilihan user antara Kasir,
	Display Barang, Kembali ke Menu Pembayaran*/
	int pilihan;
	/*Tipe data char di dalam bahasa C digunakan untuk menampung 1 digit karakter, pada pilih1, pilih2, pilih 4, utama. 
	Variabel yang didefinisikan untuk menampung tipe data char membutuhkan 1 byte memory*/
	char pilih1, pilih2, pilih4, utama;
	
	/*menampilkan tampilan dari kasir Offline yang memiliki beberapa pilihan seperti Kasir
	dan Kembali ke Menu Pembayaran*/
	printf("\t\t\t\t\t=========================================================\n");
	printf("\t\t\t\t\t                      Kasir Offline                      \n");
	printf("\t\t\t\t\t---------------------------------------------------------\n");	
	printf("\t\t\t\t\t    1. Kasir          				   \n");
	printf("\t\t\t\t\t    2. Kembali ke Menu Pembayaran			   \n");
	printf("\t\t\t\t\t---------------------------------------------------------\n");
	//user diwajibkan untuk memasukan angka pilihan untuk melanjutkan program Kasir Offline
  	printf("\t\t\t\t\t      Masukkan angka pilihan untuk melanjutkan = ");
	//meng scan apa yang dipilih oleh user dengan tipe data integer
	scanf("%d", &pilihan);
	
	//Menjalankan pilihan sesuai perintah user
	switch(pilihan){
   		case 1:
			system("cls");
   			start:
   			printf("\t\t\t\t\t=========================================================\n");
			printf("\t\t\t\t\t                    Input Data Pembelian                 \n");
			printf("\t\t\t\t\t---------------------------------------------------------\n");
			
			//Pilihan untuk user apakah ingin mendisplay produk yang tersedia atau tidak
			printf("\n\t\t\t\t\tApakah ingin mendisplay produk? (y/t) ");
			scanf("\n%c", &pilih4);
			
			//Jika user menginputkan y maka program akan memanggil fungsi display dan lanjut ke pengisian data 
			if(pilih4 == 'y'){
				getch();
				display();
			}
			
			//Jika user menginputkan t maka user akan langsung dibawa ke start3
			else{
				goto start3;
			}
			
			/*start digunakan untuk kondisi pada saat awal perulangan berisi perintah untuk memberikan nilai kepada variabel counter*/
   			start3:
   			printf("\n\t\t\t\t\tNama Pegawai Kasir => ");
			//user menginput nama pegawai 
			scanf("\n%[^\n]s", &pegawai);
			
			printf("\t\t\t\t\tNama Customer      => ");
			//user menginput nama costumer
			scanf("\n%[^\n]s", &customer);
			
			printf("\n\t\t\t\t\tPilih Tipe Pembelian (Take Away / Dine In)\n");
			printf("\t\t\t\t\tTipe Pembelian     => ");
			//user menginput type pembelian (Take Away/Dine In)
			scanf("\n%[^\n]s", &type);			
  		
		   	printf("\n\t\t\t\t\tBerapa produk yang dibeli? \n");
			printf("\t\t\t\t\t=> ");
			//user menginput total barang yang dibeli
			scanf("%d", &banyak);
			
			/*Penggunaan perulangan FOR untuk menampilkan output printf dari program sebanyak yang di inputkan user
			pada variable banyak. Pada perulangan FOR, inisialisasi variabel, syarat dan operasi bilangan ditulis dalam satu kelompok dan 
			terpisah dari statemen program yang akan dijalankan */
			for(i = 0; i < banyak; i++){
				printf("\n\t\t\t\t\tProduk yang Dibeli => ");
				scanf("\n%[^\n]s", &nama_bar[i]);

				printf("  \t\t\t\t\tHarga Produk       => Rp. ");
				scanf("%lf", &harga_bar[i]);
				
				printf("  \t\t\t\t\tTotal Produk       => ");
				scanf("%d", &total_bar[i]);
				
				//menampilkan total harga dikali total barang, sehingga mengeluarkan total hasil yang dibayarkan oleh costumer 
				hasil += harga_bar[i] * total_bar[i];
			}		
			
			//start2 digunakan untuk memulai kembali jika perintah if berjalan (uang < hasil)
			start2:
			printf("\n\t\t\t\t\tUang Customer      => Rp. ");
			//mengscan Uang Costumer yang di inputkan oleh user
			scanf("%f", &uang);
			
			//perhitungan hasil2 sebagai kembalian yang diterima oleh costumer
			hasil2 = uang - hasil;
			
			//fungsi if yang berjalan jika uang < hasil
			if(uang < hasil){
				system("cls");
				printf("\t\t\t\t\t=========================================================\n");
				printf("\t\t\t\t\t                  MAAF TIDAK TERIMA BON!                 \n");
				printf("\t\t\t\t\t---------------------------------------------------------\n");
				getch();
				//go to start2 untuk melanjutkan menginput uang dengan benar atau uang=> hasil)
				goto start2;
			}
			
			//else digunakan jika uang => hasil
			else{
				printf("\n\t\t\t\t\tApakah yakin ingin mencetak struk? (y/t) ");
				scanf("\n%c", &pilih2);
				
				//jika memilih character 'y' 
				if(pilih2 == 'y'){
					getch();
					system("cls");
					//mencetak struk dengan void struk
					struk();
					getch();
					
					//Meng assign jika variabel hasil lebih dari 0, maka hasil assign 0
					if(hasil > 0){
						hasil = 0;
					}
					
					system("cls");
				}
				//jika memilih character selain 'y'
				else{
					system("cls");
					//user akan dibawa kepada fungsi start
					goto start;
				}	
			}
			
			//program menanyakan ingin ke menu utama?
			printf("\n\t\t\t\t\tApakah ingin ke Menu Utama? (y/t) ");
			scanf("\n%c", &utama);
			
			//jika memilih character 'y' 
			if(utama == 'y'){
				getch();
				system("cls");
				pilihan_menu();
			}
			//jika memilih character selain 'y'
			else{
				system("cls");
				printf("\t\t\t\t\t=========================================================\n");
				printf("\t\t\t\t\t        Terima Kasih Sudah Menggunakan Program Ini       \n");
				printf("\t\t\t\t\t---------------------------------------------------------\n");
				getch();
				system("cls");	
				exit(0);
			}	
		   	break;
		   	
   		case 2:
			pilihan_menu();
       			break;
   	}	
	
        getch();
        system("cls");
}

//=======================================================================//
//Nama Fungsi     : Kasir Online	                       		 //
//Input Argumen   : char pegawai[100], char pengemudi[100], char costumer//
//		    [100], char type[25], int banyak, float uang	 //				 
//Output Argumen  : -                                                    //
//Deskripsi       : salah satu dari 5 fitur yang ada. ini merupakan fitur//
//		    kasir online yang digunakan user untuk menyetak str- //
//                  uk yang melakukan pembelian secara online dan memil- //
//		    iki komisi masing-masing aplikasi			 //
//                                                            		 //
//Tgl             : 24-12-2021                                           //
//Revisi          : 0                                          		 //
//Oleh            : I Made Satya Rama Sai Natha                          //
//NIM		  : 2105551039						 //
//Kelas           : B                                                    //
//=======================================================================//
// Menampilkan void kasir_online jika void kasir_online di panggil saat pilihan_menu case 2
void kasir_online(){
	/*Variabel pilihan dengan tipe data integer yang digunakan untuk menyimpan pilihan user antara Kasir,
	Display Barang, Kembali ke Menu Pembayaran*/
	int pilihan;
	/*Tipe data char di dalam bahasa C digunakan untuk menampung 1 digit karakter, pada pilih1, pilih2, pilih4, utama. 
	Variabel yang didefinisikan untuk menampung tipe data char membutuhkan 1 byte memory*/
	char pilih1, pilih2, pilih4, utama;
	
	/*menampilkan tampilan dari Kasir Online yang memiliki beberapa pilihan seperti Kasir, Display Barang
	dan Kembali ke Menu Pembayaran*/
	printf("\t\t\t\t\t=========================================================\n");
	printf("\t\t\t\t\t                      Kasir Online                       \n");
	printf("\t\t\t\t\t---------------------------------------------------------\n");	
	printf("\t\t\t\t\t    1. Kasir          				   \n");
	printf("\t\t\t\t\t    2. Kembali ke Menu Pembayaran			   \n");
	printf("\t\t\t\t\t---------------------------------------------------------\n");
	//user diwajibkan untuk memasukan angka pilihan untuk melanjutkan program Kasir Online
  	printf("\t\t\t\t\t      Masukkan angka pilihan untuk melanjutkan = ");
	//meng scan apa yang dipilih oleh user dengan tipe data integer
	scanf("%d", &pilihan);
	
	//Menjalankan pilihan sesuai perintah user
	switch(pilihan){
   		case 1:
			system("cls");
   			start:
   			printf("\t\t\t\t\t=========================================================\n");
			printf("\t\t\t\t\t                    Input Data Pembelian                 \n");
			printf("\t\t\t\t\t---------------------------------------------------------\n");
			
			//Pilihan untuk user apakah ingin mendisplay produk yang tersedia atau tidak
			printf("\n\t\t\t\t\tApakah ingin mendisplay barang? (y/t) ");
			scanf("\n%c", &pilih4);
			
			//Jika user menginputkan y maka program akan memanggil fungsi display dan lanjut ke pengisian data
			if(pilih4 == 'y'){
				getch();
				display();
			}
			
			//Jika user menginputkan t maka user akan langsung dibawa ke start3
			else{
				goto start3;
			}	
			
			/*start digunakan untuk kondisi pada saat awal perulangan berisi perintah untuk memberikan nilai kepada variabel counter*/
   			start3:
   			printf("\n\t\t\t\t\tNama Pegawai Kasir   => ");
			//user menginput nama pegawai 
			scanf("\n%[^\n]s", &pegawai);
			
			printf("\t\t\t\t\tNama Pengemudi       => ");
			//user menginput nama pengemudi
			scanf("\n%[^\n]s", &pengemudi);
			
			printf("\t\t\t\t\tNama Customer        => ");
			//user menginput nama costumer
			scanf("\n%[^\n]s", &customer);
			
			printf("\n\t\t\t\t\tPilih Aplikasi (GoFood / GrabFood / ShopeeFood\n");
			printf("\t\t\t\t\tAplikasi Pemesanan   => ");
			//user menginput tipe aplikasi (GoFood / GrabFood / ShopeeFood)
			scanf("\n%[^\n]s", &type);			
  		
		   	printf("\n\t\t\t\t\tBerapa produk yang dibeli? \n");
			printf("\t\t\t\t\t=> ");
			//user menginput total barang yang dibeli
			scanf("%d", &banyak);
			getchar();
			
			/*Penggunaan perulangan FOR untuk menampilkan output printf dari program sebanyak yang di inputkan user
			pada variable banyak. Pada perulangan FOR, inisialisasi variabel, syarat dan operasi bilangan ditulis dalam satu kelompok dan 
			terpisah dari statemen program yang akan dijalankan */
			for(i = 0; i < banyak; i++){
				printf("\n\t\t\t\t\tProduk yang Dibeli => ");
				scanf("\n%[^\n]s", &nama_bar[i]);

				printf("  \t\t\t\t\tHarga Produk       => Rp. ");
				scanf("%lf", &harga_bar[i]);
				
				printf("  \t\t\t\t\tTotal Produk       => ");
				scanf("%d", &total_bar[i]);
				
				/*menampilkan total harga dikali total barang, dan harga barang *20% karena biaya komisi dari aplikasi tersebut
				agar user tidak dirugikan oleh komisi. Setelah itu meng output total hasil yang dibayarkan oleh costumer*/ 
				hasil += (harga_bar[i] + (harga_bar[i] * 0.2)) * total_bar[i];
			}
			//start2 digunakan untuk memulai kembali jika perintah if berjalan (uang < hasil)
			start2:
			printf("\n\t\t\t\t\tUang Customer      => Rp. ");
			//mengscan Uang Costumer yang di inputkan oleh user
			scanf("%f", &uang);
			
			//perhitungan hasil2 sebagai kembalian yang diterima oleh costumer
			hasil2 = uang - hasil;
			
			//fungsi if yang berjalan jika uang < hasil
			if(uang < hasil){
				system("cls");
				printf("\t\t\t\t\t=========================================================\n");
				printf("\t\t\t\t\t                  MAAF TIDAK TERIMA BON!                 \n");
				printf("\t\t\t\t\t---------------------------------------------------------\n");
				getch();
				//go to start2 untuk melanjutkan menginput uang dengan benar atau uang=> hasil)
				goto start2;
			}
			//else digunakan jika uang => hasil
			else{
				printf("\n\t\t\t\t\tApakah yakin ingin mencetak struk? (y/t) ");
				scanf("\n%c", &pilih2);
				
				//jika memilih character 'y
				if(pilih2 == 'y'){
					getch();
					system("cls");
					struk2();
					getch();
					
					//Meng assign jika variabel hasil lebih dari 0, maka hasil assign 0
					if(hasil > 0){
						hasil = 0;
					}
					
					system("cls");
				}
				//jika memilih character selain 'y'
				else{
					system("cls");
					goto start;
				}	
			}
			
			printf("\n\t\t\t\t\tApakah ingin ke Menu Utama? (y/t) ");
			scanf("\n%c", &utama);
			
			if(utama == 'y'){
				getch();
				system("cls");
				pilihan_menu();
			}
			
			else{
				system("cls");
				printf("\t\t\t\t\t=========================================================\n");
				printf("\t\t\t\t\t        Terima Kasih Sudah Menggunakan Program Ini       \n");
				printf("\t\t\t\t\t---------------------------------------------------------\n");
				getch();
				system("cls");	
				exit(0);
			}	
		   	break;
       		
   		case 2:
			/*jika memilih case 2 yang berarti keluar ke menu utama dari Kasir Online*/
			pilihan_menu();
       			break;
   	}	
	
    getch();
    system("cls");
}

//=======================================================================//
//Nama Fungsi     : Waktu		                       		 //
//Input Argumen   : -							 //		 
//Output Argumen  : -                                                    //
//Deskripsi       : Fungsi ini digunakan untuk mengambil dan menampilkan //
//		    tanggal dan waktu dari sistem pada saat terjadi      //
//		    transaksi nanti					 //
//                                                            		 //
//Tgl             : 27-12-2021                                           //
//Oleh            : I Gede Alex Bramartha                                //
//NIM		  : 2105551024						 //
//Kelas           : A                                                    //
//=======================================================================//
void waktu(){
    time(&waktuserver);
    struct tm *waktu = localtime (&waktuserver);
    printf("%i/%i/%i-%d:%d", waktu -> tm_mday, waktu -> tm_mon + 1, waktu -> tm_year + 1900, waktu -> tm_hour,  waktu -> tm_min);
} 

//=======================================================================//
//Nama Fungsi     : Struk dan Struk2                       		 //
//Input Argumen   : -							 //		 
//Output Argumen  : pegawai, customer, type, waktu(), acak_id(),         //
//                  pengemudi, nama_bar, total_bar, harga_bar, komisi,   //
//		    hasil, uang, dan hasil2                              //
//Deskripsi       : Fungsi ini digunakan untuk menampilkan struk yang 	 //
//		    berisi data-data user yang telah diinputkan pada     //
//		    menu kasir    					 //
//Tgl             : 27-12-2021                                           //
//Oleh            : I Gede Alex Bramartha                                //
//NIM		  : 2105551024						 //
//Kelas           : A                                                    //
//=======================================================================//

//Fungsi struk ini digunakan untuk menampilkan rincian pembelian pada kasir offline
void struk(){
	printf("\t\t\t\t\t=================================================\n");
	printf("\t\t\t\t\t                 RINCIAN PEMBELIAN               \n");
	printf("\t\t\t\t\t-------------------------------------------------\n");
	
	//Memanggil isi dari variabel pegawai, fungsi waktu, dan fungsi untuk menampilkan id acak
	printf("\t\t\t\t\t%s - ", strupr(pegawai)); waktu(); //Fungsi strupr() agar output string menjadi Uppercase
	printf("\n\t\t\t\t\tID : "); acak_id();
	printf("\t\t\t\t\t-------------------------------------------------\n");
	
	//Memanggil isi dari variabel customer dan type yang telah diinputkan oleh user
	printf("\t\t\t\t\tCUSTOMER - %s", strupr(customer));
	printf("\n\t\t\t\t\tTIPE %s", strupr(type));
	
	//Memanggil seluruh produk yang disimpan pada variabel nama_bar, total_bar, dan harga_bar dengan looping
	printf("\n\n\t\t\t\t\tPRODUK YANG DIBELI: \n");

	for(i = 0; i < banyak; i++){
		printf("\t\t\t\t\t- %-20s \t  x%1d \t   RP. %3.lf \n", strupr(nama_bar[i]), total_bar[i], harga_bar[i]);
	}
	
	//Memanggil isi dari variabel hasil, uang, dan hasil2 yang telah di assign pada kasir offline
	printf("\n\t\t\t\t\t-------------------------------------------------\n");
	printf("\t\t\t\t\tTOTAL HARGA      		=> RP. %.lf\n", hasil);
	printf("\t\t\t\t\tUANG CUSTOMER    		=> RP. %.lf\n", uang);	
	printf("\t\t\t\t\tKEMBALIAN       		=> RP. %.lf\n", hasil2);
	printf("\t\t\t\t\t=================================================\n");
}

//Fungsi struk ini digunakan untuk menampilkan rincian pembelian pada kasir online
void struk2(){
	printf("\t\t\t\t\t=================================================\n");
	printf("\t\t\t\t\t                 RINCIAN PEMBELIAN               \n");
	printf("\t\t\t\t\t-------------------------------------------------\n");	
	printf("\t\t\t\t\t%s - ", strupr(pegawai)); waktu(); 
	printf("\n\t\t\t\t\tID : "); acak_id();
	printf("\t\t\t\t\t-------------------------------------------------\n");

	printf("\t\t\t\t\tCUSTOMER - %s", strupr(customer));
	printf("\n\t\t\t\t\tTIPE %s", strupr(type));
	
	//Memanggil isi dari variabel pengemudi agar ditampilkan
	printf("\n\t\t\t\t\tPENGEMUDI - %s", strupr(pengemudi));
	
	printf("\n\n\t\t\t\t\tPRODUK YANG DIBELI: \n");

	for(i = 0; i < banyak; i++){
		printf("\t\t\t\t\t- %-20s \t  x%1d \t   RP. %3.lf \n", strupr(nama_bar[i]), total_bar[i], harga_bar[i]);
	}
	
	printf("\n\t\t\t\t\t-------------------------------------------------\n");
	
	//Deklarasi lokal dengan variabel komisi bertipe data char yang berisi value 20% untuk di tampilkan pada komisi
	char komisi[] = {"20%"};
	printf("\t\t\t\t\tKOMISI APLIKASI  		=> %s \n", komisi);
	printf("\t\t\t\t\tTOTAL HARGA      		=> RP. %.lf\n", hasil);
	printf("\t\t\t\t\tUANG CUSTOMER    		=> RP. %.lf\n", uang);	
	printf("\t\t\t\t\tKEMBALIAN       		=> RP. %.lf\n", hasil2);
	printf("\t\t\t\t\t=================================================\n");
}
//=======================================================================//
//Nama Fungsi     : Tambah Produk                       		 //
//Input Argumen   : t.name , t.price					 //		 
//Output Argumen  : t.name, t.price         				 //
//Deskripsi       : Fungsi ini digunakan untuk menambahkan produk yang a-//
//		    da dan disimpan pada file untuk ditampilkan pada dis-//
//		    play						 //
//Tgl             : 28-12-2021                                           //
//Oleh            : I Made Satya Rama Sai Natha                          //
//NIM		  : 2105551039						 //
//Kelas           : B                                                    //
//=======================================================================//
/*Void add ini digunakan untuk menambahkan value barang yang ingin ditambahkan pada aplikasi*/
void add(){
	system("cls");
	//menampilkan tampilan tambah produk
	printf("\t\t\t\t\t=========================================================\n");
	printf("\t\t\t\t\t                     Tambah Produk                \n");
	printf("\t\t\t\t\t---------------------------------------------------------\n");
	
	//perintah untuk menginput berapa barang yang ingin ditambahkan
	printf("\n\t\t\t\t\tBerapa barang yang ingin ditambahkan? \n");
	printf("\t\t\t\t\t=> ");
	scanf("%d", &no);
	
	//Operasi FILE dalam Bahasa C berguna untuk menyimpan atau membaca data langsung ke sebuah file. Dengan demikian, data kita akan selalu ada dalam suatu file
	//File di inisialisasi sebagai *fp
	FILE *fp;
	
	//fopen digunakan untuk membuka file.txt dari recordInvend dan fungsi append berfungsi untuk menambahkan atau ADD value pada file tersebut 
	fp = fopen (recordInven, "a");
	
	//fungsi perulangan untuk menampilkan seberapa banyak barang yang kita tambahkan
	for(i = 0; i < no; i++){
		printf("  \t\t\t\t\tNama Produk   : ");
		scanf("\n%[^\n]s", t.name);
		
		printf("  \t\t\t\t\tHarga Produk  : Rp. ");
		scanf("%d", &t.price);
	
	//fprintf digunakan untuk menulis value yang di input ke dalam file
	fprintf(fp, "\t\t\t\t\t%-20s \t\tRp. %3d    \n", t.name, t.price);
	}	
	
	fclose(fp);
	getch();
	system("cls");
	//pilihan_menu fungsi untuk kenbali ke void pilihan_menu
	pilihan_menu();
}
//=======================================================================//
//Nama Fungsi     : Display Barang                       		 //
//Input Argumen   : 							 //		 
//Output Argumen  : c		         				 //
//Deskripsi       : Fungsi ini digunakan untuk menampilkan barang yang s-//
//		    udah ditambahkan dan mendisplay dengan meng open File//
//		    yang sudah dibuat					 //
//Tgl             : 28-12-2021                                           //
//Oleh            : I Made Satya Rama Sai Natha                          //
//NIM		  : 2105551039						 //
//Kelas           : B                                                    //
//=======================================================================//
//void display digunakan untuk menampilkan display barang yang sudah ter record oleh void add
void display(){
	char pilihan;
	//FILE di inisialisasi dengan *fp
	FILE *fp;
	
	//membuka fp dengan fopen recordInven dari add degann "r" atau read 
	fp = fopen (recordInven, "r");
	
	//menampilkan produk yang tersedia beserta harga
	printf("\t\t\t\t\t=========================================================\n");
	printf("\t\t\t\t\t                     Produk Tersedia                \n");
	printf("\t\t\t\t\t---------------------------------------------------------\n");
	printf("\t\t\t\t\t|   Nama Produk                 |   Harga     \n");
	printf("\t\t\t\t\t---------------------------------------------------------\n");
	//Perulangan while untuk mencetak isi dari File yang telah di inputkan sebelumnya pada void 
	while((c = getc(fp)) != EOF){	
		printf("%c", c);
	}
	printf("\t\t\t\t\t---------------------------------------------------------\n");
	fclose(fp);
	getch();
}
//=======================================================================//
//Nama Fungsi     : Acak Id                      		 	 //
//Input Argumen   : 							 //		 
//Output Argumen  : char		         			 //
//Deskripsi       : Fungsi yang digunakan untuk menampilkan Id yang diac-//
//		    ak yang sudah ditentukan				 //	
//Tgl             : 28-12-2021                                           //
//Oleh            : I Made Satya Rama Sai Natha                          //
//NIM		  : 2105551039						 //
//Kelas           : B                                                    //
//=======================================================================//

//void acak_id digunakan sebagai pencetak id pada struk
void acak_id(){
    //static const char yang berfungsi untuk mendefinisikan sebuah variable yang nilainya tak dapat di rubah atau sudah di tetapkan oleh user
    static const char huruf[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    //menampilkan jumlah pencetakan yang ditetapkan
    const size_t jumlah = sizeof(huruf) - 27; 
    size_t i, j;

    srand(time(NULL));

    for(i = 0; i < 1; i++) {
        for(j = 0; j < jumlah; j++) {
            char random_char;
	    //fungsi untuk mengacak character yang sudah ditetapkan
            int random_index = (double)rand() / RAND_MAX * jumlah;
            
	    //fungsi untuk memanggil secara random pada huruf[random_index] 
            random_char = huruf[random_index];
            printf("%c", random_char);
        }
        printf("\n");
    }
}

//=======================================================================//
//Nama Fungsi     : Delete                      		 	 //
//Input Argumen   : - 							 //		 
//Output Argumen  : -		         			         //
//Deskripsi       : Fungsi yang digunakan untuk menghapus baris pada     //
//		    File penyimpanan.txt 				 //	
//Tgl             : 28-12-2021                                           //
//Oleh            : I Gede Alex Bramartha                                //
//NIM		  : 2105551024						 //
//Kelas           : A                                                    //
//=======================================================================//
int delete(){
    FILE *srcFile;
    FILE *tempFile;

    int line;

    //Menginput baris keberapa yang ingin dihapus
	printf("\t\t\t\t\t=========================================================\n");
	printf("\t\t\t\t\t                      Hapus Produk                \n");
	printf("\t\t\t\t\t---------------------------------------------------------\n");
	display();
    printf("\t\t\t\t\tMasukkan baris keberapa produk yang ingin dihapus!");
    printf("\n\t\t\t\t\t=> ");
    scanf("%d", &line);


    //Membuka kedua file
    srcFile  = fopen(recordInven, "r");
    tempFile = fopen("delete-line.tmp", "w");

    //Jika tidak ada file akan muncul tampilan seperti dibawah
    if (srcFile == NULL || tempFile == NULL)
    {
      	printf("\t\t\t\t\t=========================================================\n");
		printf("\t\t\t\t\t          FILE IS NOT FOUND IN YOUR DIRECTORY	           \n");
		printf("\t\t\t\t\t---------------------------------------------------------\n");
		getch();
		system("cls");
        pilihan_menu();
    }

    //Pindah ke pointer diawal yaitu srcFile
    rewind(srcFile);

    //Fungsi untuk menghapus baris yang diinput
    deleteLine(srcFile, tempFile, line);


    //Menutup kedua file
    fclose(srcFile);
    fclose(tempFile);


    //Menghapus file asli dan mengubah nama file temp dengan nama asli
    remove(recordInven);
    rename("delete-line.tmp", recordInven);


    printf("\n\t\t\t\t\tBerikut adalah Rincian Produk setelah menghapus baris ke-%d!\n", line);

    //Membuka file untuk di display
    srcFile = fopen(recordInven, "r");
    display();
    fclose(srcFile);
    
    pilihan_menu();
}
//mencetak konten file.
void printFile(FILE *fptr)
{
    char ch;

    while((ch = fgetc(fptr)) != EOF)
        putchar(ch);
}

//fungsi untuk menghapus baris yang telah di input
void deleteLine(FILE *srcFile, FILE *tempFile, const int line)
{
    char buffer[BUFFER_SIZE];
    int count = 1;

    while ((fgets(buffer, BUFFER_SIZE, srcFile)) != NULL)
    {
  
        if (line != count)
            fputs(buffer, tempFile);
        count++;
    }
}
