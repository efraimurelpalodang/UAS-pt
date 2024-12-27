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
    string jumlahSiswa;
    string tahunAjaran;
};
vector<Kelas> dataKelas; // Membuat vector dari data kelas

//! DATA SISWA
struct Siswa {
    string nama;
    string nis;
    string kelas;
    string ttl;
    string jk;
};

vector<Siswa> dataSiswa; // Membuat vector dari data siswa

//! Fungsi untuk mengambil data dari file
void ambilData(const string& file) {
    ifstream data(file);  // Membuka file untuk dibaca
    if (!data.is_open()) { // Memastikan file berhasil dibuka
        cout << "File tidak ditemukan!" << endl;
        return;
    }

    string val1, val2, val3, val4, val5;

    // Membaca data dari file
    while (data >> val1 >> ws) {  // Membaca ID dan mengabaikan whitespace
        getline(data, val2, '\t');  // Membaca nama kelas hingga tab
        data >> val3 >> ws;          // Membaca wali kelas dan mengabaikan whitespace
        data >> val4 >> ws;          // Membaca jumlah siswa dan mengabaikan whitespace
        getline(data, val5);         // Membaca tahun ajaran (sampai akhir baris)

        // Menambahkan data ke vector dataKelas
        dataKelas.push_back({val1, val2, val3, val4, val5});
    }

    data.close();  // Menutup file setelah selesai
}

// Fungsi untuk mencetak data
template <typename T>
void cetakData(vector<T>& data) {
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
    else if (is_same<T, Siswa>::value) {
        cout << "\nDATA SISWA YANG SUDAH DI TEMBAHKAN !!\n";
        cout << string(85, '-') << endl; // Garis pemisah
        cout << left << setw(20) << "Nama Siswa"
                << setw(15) << "NIS"
                << setw(10) << "Kelas"
                << setw(15) << "TTL"
                << setw(15) << "Jenis Kelamin" << endl;
        cout << string(85, '-') << endl; // Garis pemisah

        for (const auto& siswa : data) {
            cout << setw(20) << siswa.nama
                    << setw(15) << siswa.nis
                    << setw(10) << siswa.kelas
                    << setw(15) << siswa.ttl
                    << setw(15) << siswa.jk << endl;
        }
        cout << string(85, '-') << endl; // Garis pemisah
    }
}

// Fungsi menambahkan data
template <typename B>
void tambahData(vector<B>& data) {
    if (is_same<B, Kelas>::value) {
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
    else if (is_same<B, Siswa>::value) {
        Siswa d; // membuat variable dari referensi objek kelas
        cin.ignore(); // Mengabaikan newline yang tersisa di buffer
        cout << "Masukkan Nama Siswa: "; getline(cin, d.nama);
        cout << "Masukkan NIS: "; getline(cin, d.nis);
        cout << "Masukkan Kelas: "; getline(cin, d.kelas);
        cout << "Masukkan TTL [tgl-bln-thn]: "; cin >> d.ttl;
        cin.ignore(); // Mengabaikan newline yang tersisa di buffer
        cout << "Masukkan Jenis Kelamin: "; getline(cin, d.jk);
        data.push_back(d);
        cout << "Data Berhasil Ditambahkan!" << endl;
    }
}

// Fungsi untuk mengubah data
template <typename C>
void ubahData(vector<C>& data) {
    if (data.empty()) {
        cout << "Tidak ada data yang tersedia untuk diubah." << endl;
        return;
    }
    cetakData(data);

    int index;
    cout << "Masukkan nomor data yang ingin diubah (mulai dari 1): ";
    cin >> index;

    if (index < 1 || index > data.size()) {
        cout << "Nomor tidak Valid!" << endl;
        return;
    }
    C& d = data[index - 1];

    if (is_same<C, Kelas>::value) {
        cin.ignore(); // Mengabaikan newline yang tersisa di buffer
        cout << "Masukkan ID Kelas: "; getline(cin, d.idKelas);
        cout << "Masukkan Nama Kelas: "; getline(cin, d.namaKelas);
        cout << "Masukkan Wali Kelas: "; getline(cin, d.waliKelas);
        cout << "Masukkan Jumlah Siswa: "; cin >> d.jumlahSiswa;
        cin.ignore(); // Mengabaikan newline yang tersisa di buffer
        cout << "Masukkan Tahun Ajaran: "; getline(cin, d.tahunAjaran);
        cout << "Data berhasil di Ubah!" << endl;
    }
    else if (is_same<C, Siswa>::value) {
        cin.ignore(); // Mengabaikan newline yang tersisa di buffer
        cout << "Masukkan Nama Siswa: "; getline(cin, d.nama);
        cout << "Masukkan NIS: "; getline(cin, d.nis);
        cout << "Masukkan Kelas: "; getline(cin, d.kelas);
        cout << "Masukkan TTL [tgl-bln-thn]: "; cin >> d.ttl;
        cin.ignore(); // Mengabaikan newline yang tersisa di buffer
        cout << "Masukkan Jenis Kelamin: "; getline(cin, d.jk);
        cout << "Data Berhasil Diubah!" << endl;
    }

}

// Fungsi untuk menghapus data
template <typename D>
void hapusData(vector<D>& data) {
    if (data.empty()) {
        cout << "Tidak ada data untuk dihapus!!" << endl;
        return;
    }
    cetakData(data);
    int index;
    cout << "Masukkan data yang ingin dihapus (mulai dari 1): ";
    cin >> index;
    if (index < 1 || index > data.size()) {
        cout << "Nomor tidak valid" << endl;
        return;
    }

    data.erase(data.begin() + index - 1);
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
        else if (is_same<T, Siswa>::value) {
            // Jika T adalah struct Kelas
            file << item.nama << "\t"
                    << item.nis << "\t"
                    << item.kelas << "\t"
                    << item.ttl << "\t"
                    << item.jk << endl;
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
