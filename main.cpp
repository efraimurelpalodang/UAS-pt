#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip> // Untuk std::setw

using namespace std;

//! DATA KELAS
struct Kelas {
    string idKelas;
    string namaKelas;
    string waliKelas;
    int jumlahSiswa;
    string tahunAjaran;
};
vector<Kelas> dataKelas; // Membuat vector dari data kelas

//! DATA SISWA
struct Siswa {
    string nama;
    string nis;
    string kelas;
};

vector<Siswa> dataSiswa; // Membuat vector dari data siswa

//! Fungsi untuk mengambil data dari file
void ambilData(const string& file) {
    ifstream data(file);  // Membuka file untuk dibaca
    if (!data.is_open()) { // Memastikan file berhasil dibuka
        cout << "File tidak ditemukan!" << endl;
        return;
    }

    string id, nama, val1, val3;
    int val2;

    // Membaca data dari file
    while (data >> id >> ws) {  // Membaca ID dan mengabaikan whitespace
        getline(data, nama, '\t');  // Membaca nama kelas hingga tab
        data >> val1 >> ws;          // Membaca wali kelas dan mengabaikan whitespace
        data >> val2 >> ws;          // Membaca jumlah siswa dan mengabaikan whitespace
        getline(data, val3);         // Membaca tahun ajaran (sampai akhir baris)

        // Menambahkan data ke vector dataKelas
        dataKelas.push_back({id, nama, val1, val2, val3});
    }

    data.close();  // Menutup file setelah selesai
}

// Fungsi untuk mencetak data
template <typename T>
void cetakData(const vector<T>& data) {
    if (data.empty()) {
        cout << "Tidak ada Data yang tersedia!" << endl;
        return;
    }

    if (is_same<T, Kelas>::value) {
        cout << "\nDATA KELAS YANG SUDAH DI TEMBAHKAN !!\n";
        cout << string(85, '-') << endl; // Garis pemisah
        cout << left << setw(15) << "ID Kelas"
                << setw(20) << "Nama Kelas"
                << setw(20) << "Wali Kelas"
                << setw(15) << "Jumlah Siswa"
                << setw(15) << "Tahun Ajaran" << endl;
        cout << string(85, '-') << endl; // Garis pemisah

        for (const auto& kelas : data) {
            cout << setw(15) << kelas.idKelas
                    << setw(20) << kelas.namaKelas
                    << setw(20) << kelas.waliKelas
                    << setw(15) << kelas.jumlahSiswa
                    << setw(15) << kelas.tahunAjaran << endl;
        }
        cout << string(85, '-') << endl; // Garis pemisah
    }
}

// Fungsi menambahkan data
void tambahData(vector<Kelas>& data) {
    Kelas d; // membuat variable dari referensi objek kelas
    cin.ignore(); // Mengabaikan newline yang tersisa di buffer
    cout << "Masukkan ID Kelas: "; getline(cin, d.idKelas);
    cout << "Masukkan Nama Kelas: "; getline(cin, d.namaKelas);
    cout << "Masukkan Wali Kelas: "; getline(cin, d.waliKelas);
    cout << "Masukkan Jumlah Siswa Kelas: "; cin >> d.jumlahSiswa;
    cin.ignore(); // Mengabaikan newline yang tersisa di buffer
    cout << "Masukkan Tahun Ajaran: "; getline(cin, d.tahunAjaran);
    data.push_back(d);
    cout << "Data Berhasil Ditambahkan!" << endl;
}

// Fungsi untuk mengubah data
void ubahData(vector<Kelas>& dataKelas) {
    if (dataKelas.empty()) {
        cout << "Tidak ada data yang tersedia untuk diubah." << endl;
        return;
    }
    cetakData(dataKelas);

    int index;
    cout << "Masukkan nomor data yang ingin diubah (mulai dari 1): ";
    cin >> index;

    if (index < 1 || index > dataKelas.size()) {
        cout << "Nomor tidak Valid!" << endl;
        return;
    }
    Kelas& d = dataKelas[index - 1];

    cin.ignore(); // Mengabaikan newline yang tersisa di buffer
    cout << "Masukkan ID Kelas: "; getline(cin, d.idKelas);
    cout << "Masukkan Nama Kelas: "; getline(cin, d.namaKelas);
    cout << "Masukkan Wali Kelas: "; getline(cin, d.waliKelas);
    cout << "Masukkan Jumlah Siswa: "; cin >> d.jumlahSiswa;
    cin.ignore(); // Mengabaikan newline yang tersisa di buffer
    cout << "Masukkan Tahun Ajaran: "; getline(cin, d.tahunAjaran);
    cout << "Data berhasil di Ubah!" << endl;
}

// Fungsi untuk menghapus data
void hapusData(vector<Kelas>& dataKelas) {
    if (dataKelas.empty()) {
        cout << "Tidak ada data untuk dihapus!!" << endl;
        return;
    }
    cetakData(dataKelas);
    int index;
    cout << "Masukkan data yang ingin dihapus (mulai dari 1): ";
    cin >> index;
    if (index < 1 || index > dataKelas.size()) {
        cout << "Nomor tidak valid" << endl;
        return;
    }

    dataKelas.erase(dataKelas.begin() + index - 1);
    cout << "Data Berhasil Dihapus, jangan lupa simpan perubahan!!" << endl;
}

// Fungsi untuk menyimpan data ke file
template <typename T>
void simpanData(const vector<T>& data, const string& save) {
    ofstream file(save);

    for (const auto& item : data) {
        if (is_same<T, Kelas>::value) {
            // Jika T adalah struct Kelas
            file << item.idKelas << "\t"
                    << item.namaKelas << "\t"
                    << item.waliKelas << "\t"
                    << item.jumlahSiswa << "\t"
                    << item.tahunAjaran << endl;
        }
    }

    file.close();
    cout << "Data Berhasil Disimpan kedalam file " << save << "!!" << endl;
}

// Fungsi CRUD untuk Data Kelas
template <typename A>
void dataCrud(const string& judul, vector<A>& data, const string& file) {
    int pilihan;
    ambilData(file);

    do {
        cout << "\nMenu Pengelolaan Data " << judul << endl;
        cout << "------------------------------" << endl;
        cout << "1. Tambah Data " << judul << endl;
        cout << "2. Ubah Data " << judul << endl;
        cout << "3. Hapus Data " << judul << endl;
        cout << "4. Tampilkan Data " << judul << endl;
        cout << "5. Simpan Perubahan Data ke File" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahData(data);
                break;
            case 2:
                ubahData(data);
                break;
            case 3:
                hapusData(data);
                break;
            case 4:
                cetakData(data);
                break;
            case 5:
                simpanData(data, file);
                break;
            case 6:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "PILIHAN TIDAK VALID SILAHKAN COBA LAGI!!" << endl;
        }
    } while (pilihan != 6);
}

//! program Utama
int main() {
    cout << "\n===============================\n";
    cout << "PROJEK MANAJEMEN DATA SEKOLAH";
    cout << "\n===============================\n";
    int pilih;
    cout << "1. Data Siswa\n2. Data Guru\n3. Data Kelas\n4. Keluar\nPilih Menu [1-4] : "; cin >> pilih;
    switch(pilih) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            dataCrud("Kelas", dataKelas, "data/kelas.txt");
            break;
        default:
            break;
    }

    return 0;
}
