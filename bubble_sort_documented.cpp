/**
 * @file bubble_sort.hpp
 * @brief Berisi sebuah program dengan algoritma Bubble Sort untuk mengurutkan
 * tinggi badan siswa.
 * @author Citra, Naura, Aliyya
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * Variable TINGGI_MIN sebagai batas minimal tinggi siswa.
 * Variable TINGGI_MAX sebagai batas maksimal tinggi siswa.
*/ 
const int TINGGI_MIN = 50; 
const int TINGGI_MAX = 250;

/**
 * @struct Siswa sebagai struktur data yang
 * menampung berbagai macam tipe data, dalam program ini berupa
 * nama siswa dan tinggi badan.
 */
struct Siswa {
    string nama;
    int tinggi;
};

/**
 * Function validasi untuk melakukan validasi terhadap data tinggi badan
 * yang berada diluar range (50cm sampai 250cm)
 * 
 * @param barisan adalah kumpulan data dari struct Siswa dalam bentuk vector.
 * 
 * @param pesan adalah variabel untuk menampung pesan peringatan
 * jika data tinggi badan yang tersedia bukanlah data yang valid.
*/
bool validasi(const vector<Siswa>& barisan, string& pesan) {
    /**
     * Sebuah blok kode validasi untuk memeriksa ketersediaan baris data.
     * Jika barisannya kosong, maka pesan peringatan akan muncul
     * untuk memberi tahu bahwa baris data yang disediakan dalam keadaan
     * kosong, sehingga tidak ada data yang perlu diurutkan, dan program akan dihentikan.
    */
    if (barisan.empty()) {
        /**
         * Muncul sebuah pesan peringatan kalau baris datanya kosong. Kemudian
         * program akan mengembalikan nilai false.
         */
        pesan = "Barisan kosong, tidak ada yang diurutkan.";
        return false;
    }
    /**
     * Deklarasi perulangan untuk memeriksa data tinggi badan siswa
     * apakah berada di dalam range yang sesuai atau tidak. Jika tidak,
     * sebuah pesan peringatan akan muncul untuk memberi tahu bahwa
     * data tinggi badan yang disediakan bukanlah data yang valid, karena
     * berada di luar range yang sudah ditentukan sebelumnya melalui
     * variabel TINGGI_MIN dan TINGGI_MAX, dan program akan dihentikan.
     * 
     * @param s dideklarasikan sebagai parameter data yang mewakili
     * barisan data Siswa. parameter ini digunakan untuk
     * proses validasi data tinggi badan siswa yang disediakan.
     */
    for (const auto& s : barisan) {
        /**
         * Pemeriksaan lebih lanjut apakah data tinggi badan berada di dalam
         * range yang sudah ditentukan. Jika tinggi badan di luar range, maka
         * akan muncul pesan peringatan bahwa data tidak valid, dan program
         * mengembalikan nilai false.
         */
        if (s.tinggi < TINGGI_MIN || s.tinggi > TINGGI_MAX) {
            pesan = "Tinggi tidak valid untuk " + s.nama + " (" + to_string(s.tinggi) +
                    " cm). Harus " + to_string(TINGGI_MIN) + "-" + to_string(TINGGI_MAX) + " cm.";
            return false;
        }
    }

    /**
     * Jika semua data sudah diperiksan dan hasilnya adalah valid,
     * data dapat diproses dengan algoritma Bubble Sort untuk mengurutkan
     * tinggi badan siswa. Nilai true akan dkembalikan sehingga
     * program bisa dilanjutkan
     */
    return true;
}

/**
 * Deklarasi funcion bubbleSortSiswa untuk mengurutkan tinggi badan siswa
 * dari yang terpendek sampai tertinggi.
 * 
 * @param barisan adalah sebuah parameter pada function bubbleSortSiswa
 * berupa kumpulan data dari struct Siswa dalam bentuk vector. Function bubbleSortSiswa
 * akan mengambil tinggi badan siswa untuk diurutkan.
 */ 
void bubbleSortSiswa(vector<Siswa>& barisan) {
    /**
     * Sebuah variabel n dideklarasikan untuk mewakili panjang
     * vector dari vector barisan. Sebuah nilai juga diinisiasikan
     * berupa besaran dari vector barisan.
     */
    int n = barisan.size();

    /**
     * Deklarasi perulangan for untuk mengurutkan tinggi badan siswa
     * dari kumpulan data yang diberikan melalui vector barisan.
     */
    for (int i = 0; i < n - 1; i++) {
        /**
         * Deklarasi variabel swapped dengan inisiasi nilai false. Ini sebagai
         * status apakah nilai data yang acak sudah ditukar sehingga hasilnya adalah
         * data yang terurut.
         */
        bool swapped = false;

        /**
         * Sebuah perulangan for untuk melakukan pertukaran data siswa
         * berdasarkan tinggi badan siswa.
         */
        for (int j = 0; j < n - i - 1; j++) {
            /**
             * Dua buah nilai dari tinggi badan siswa akan dibandingkan
             * satu sama lain. Nilai yang lebih besar atau siswa yang memiliki
             * ukuran badan yang lebih tinggi akan ditukar posisinya. Diikuti
             * dengan perubahan status atau nilai swapped menjadi true.
             */
            if (barisan[j].tinggi > barisan[j + 1].tinggi) {
                swap(barisan[j], barisan[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

/**
 * Deklarasi function tampilkan untuk menampilkan hasil akhir
 * dari algoritma bubble sort yang berupa data tinggi badan siswa
 * yang sudah diurutkan
 * 
 * @param barisan dituliskan sebagai parameter yang berisi data siswa
 * yang sudah diurutkan berdasarkan tinggi badannya.
 */
void tampilkan(const vector<Siswa>& barisan) {
    for (const auto& s : barisan)
        cout << s.nama << " (" << s.tinggi << " cm)" << endl;
}

/**
 * Function ini dideklarasikan untuk menjalankan keseluruhan
 * function kecil secara berurutan. Pertama, barisan data Siswa
 * akan divalidasi tinggi badannya, kemudian Siswa diurutkan berdasarkan
 * tinggi badannya mulai dari yang terkecil. Setelah itu, hasil akhir
 * akan ditampilkan berupa data yang sudah diurutkan.
 * 
 * @param kode adalah parameter untuk penanda identitas testcase yang
 * sedang dijalankan
 * 
 * @param judul adalah parameter untuk identifikasi judul dari suatu testcase yang
 * sedang dijalankan
 * 
 * @param b adalah parameter berupa struktur data vector untuk mewakili barisan
 * data Siswa untuk diurutkan tinggi badannya dengan algoritma Bubble Sort. 
 */
void jalankan(string kode, string judul, vector<Siswa> b) {
    /**
     * Sebuah output untuk menampilkan kode dan judul dari
     * testcase yang sedang dijalankan, dengan mengambil variabel
     * kode dan judul
    */
    
    cout << "[" << kode << "] " << judul << endl;
    /**
     * Deklarasi variabel pesan sebagai wadah untuk menyimpan pesan
     * peringatan jika terdapat data yang tidak valid
    */
    string pesan;
    
    /**
     * Jika hasil validasi berupa nilai false, maka program akan berhenti
     * dan memunculkan pesan ERROR yang diikuti dengan pesan peringatan
     * berdasarkan hasil dari validasi data sebelumnya.
    */
    if (!validasi(b, pesan)) {
       cout << "ERROR: " << pesan << endl << endl;
       return;
    }

    /**
     * Data tinggi badan yang sudah divalidasi kemudian diurutkan
     * dengan algoritma Bubble Sort. Sebuah function Bubble Sort
     * dipanggil dengan parameter b.
    */
    bubbleSortSiswa(b);

    /**
     * Data tinggi badan yang sudah diurutkan akan ditampilkan hasilnya
     * melalui pemanggilan function tampilkan,
    */
    tampilkan(b);
    cout << endl;
}

/**
 * Function main sebagai bagian utama pada program, yang membungkus
 * keseluruhan function atau seluruh bagian kode.
 * 
 * Di dalamnya, terdapat pemanggilan function jalankan untuk menjalankan
 * proses validasi data, pengurutan tinggi badan siswa, hingga menampilkan hasilnya.
 */
int main() {
    cout << "===== KODE BARU =====" << endl << endl;
    /**
     * Menjalankan kode dengan testcase berupa data yang teracak.
     */
    jalankan("P1", "Data acak", {{"Budi",165},{"Siti",150},{"Andi",172},{"Dewi",158},{"Rina",145}});
    
    /**
     * Menjalankan kode dengan testcase berupa data yang sudah dalam bentuk terurut.
     */
    jalankan("P2", "Sudah terurut", {{"Rina",145},{"Siti",150},{"Dewi",158},{"Budi",165},{"Andi",172}});
    
    /**
     * Menjalankan kode dengan testcase berupa masukan data dalam urutan yang terbalik.
     */
    jalankan("P3", "Urutan terbalik", {{"Andi",172},{"Budi",165},{"Dewi",158},{"Siti",150},{"Rina",145}});
    
    /**
     * Menjalankan kode dengan testcase berupa masukan data dengan nilai negatif.
     */
    jalankan("N1", "Tinggi negatif", {{"Budi",-165},{"Siti",150},{"Andi",172}});
    
    /**
     * Menjalankan kode dengan testcase berupa masukan data dengan nilai
     * tinggi badan berupa 0.
     */
    jalankan("N2", "Tinggi nol", {{"Budi",165},{"Siti",0},{"Andi",172}});
    
    /**
     * Menjalankan kode dengan testcase berupa masukan data dengan nilai
     * tinggi badan yang tidak masuuk akal, atau berada di luar batas tinggi siswa.
     */
    jalankan("N3", "Tinggi tidak masuk akal", {{"Budi",165},{"Siti",150},{"Andi",500}});
    
    /**
     * Menjalankan kode dengan testcase berupa masukan data kosong.
     */
    jalankan("A1", "Barisan kosong", {});
    
    /**
     * Menjalankan kode dengan testcase berupa masukan data tunggal, yaitu hanya
     * ada satu data siswa yang diproses.
     */
    jalankan("A2", "Hanya 1 siswa", {{"Budi",165}});
    
    /**
     * Menjalankan kode dengan testcase berupa masukan data yang mana setiap siswa
     * memiliki tinggi badan yang sama, yaitu 160cm.
     */
    jalankan("A3", "Semua tinggi sama", {{"Budi",160},{"Siti",160},{"Andi",160},{"Dewi",160}});
    return 0;
}
