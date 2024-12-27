#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Siswa {
    string nama;
    string nis;
    string kelas;
};

vector<Siswa> dataSiswa;


void tampilkanMenuUtama() {
    cout << "------------------------------------------\n";
    cout << "            PROJEK MANAJEMEN DATA SEKOLAH            \n";
    cout << "------------------------------------------\n";
    cout << "1. Data Siswa\n";
    cout << "2. Data Guru\n";
    cout << "3. Data Kelas\n";
    cout << "4. Keluar\n";
    cout << "Input Menu: ";
}


void tampilkanMenuSiswa() {
    cout << "\nData Siswa:\n";
    cout << "1. Cetak Data\n";
    cout << "2. Tambah Data\n";
    cout << "3. Hapus Data\n";
    cout << "4. Ubah Data\n";
    cout << "5. Kembali ke menu utama\n";
    cout << "Input Menu: ";
}


void tambahDataSiswa() {
    Siswa siswaBaru;
    cout << "Masukkan Nama Siswa: "; cin >> siswaBaru.nama;
    cout << "Masukkan NIS: "; cin >> siswaBaru.nis;
    cout << "Masukkan Kelas: "; cin >> siswaBaru.kelas;
    dataSiswa.push_back(siswaBaru);
    cout << "Data siswa berhasil ditambahkan!\n";
}


void cetakDataSiswa() {
    if (dataSiswa.empty()) {
        cout << "Belum ada data siswa yang ditambahkan.\n";
    } else {
        cout << "\nDaftar Siswa:\n";
        cout << "NIS\tNama\tKelas\n";
        for (size_t i = 0; i < dataSiswa.size(); i++) {
            cout << dataSiswa[i].nis << "\t" << dataSiswa[i].nama << "\t" << dataSiswa[i].kelas << endl;
        }
    }
}


void hapusDataSiswa() {
    string nis;
    cout << "Masukkan NIS siswa yang ingin dihapus: ";
    cin >> nis;

    for (size_t i = 0; i < dataSiswa.size(); i++) {
        if (dataSiswa[i].nis == nis) {
            dataSiswa.erase(dataSiswa.begin() + i);
            cout << "Data siswa berhasil dihapus!\n";
            return;
        }
    }
    cout << "Data siswa dengan NIS tersebut tidak ditemukan.\n";
}


void ubahDataSiswa() {
    string nis;
    cout << "Masukkan NIS siswa yang ingin diubah: ";
    cin >> nis;

    for (size_t i = 0; i < dataSiswa.size(); i++) {
        if (dataSiswa[i].nis == nis) {
            cout << "Masukkan Nama Baru: "; cin >> dataSiswa[i].nama;
            cout << "Masukkan Kelas Baru: "; cin >> dataSiswa[i].kelas;
            cout << "Data siswa berhasil diubah!\n";
            return;
        }
    }
    cout << "Data siswa dengan NIS tersebut tidak ditemukan.\n";
}

int main() {
    int pilihanUtama, pilihanSiswa;

    do {
        tampilkanMenuUtama();
        cin >> pilihanUtama;

        switch (pilihanUtama) {
        case 1: // Menu Data Siswa
            do {
                tampilkanMenuSiswa();
                cin >> pilihanSiswa;

                switch (pilihanSiswa) {
                case 1:
                    cetakDataSiswa();
                    break;
                case 2:
                    tambahDataSiswa();
                    break;
                case 3:
                    hapusDataSiswa();
                    break;
                case 4:
                    ubahDataSiswa();
                    break;
                case 5:
                    cout << "Kembali ke menu utama...\n";
                    break;
                default:
                    cout << "Pilihan tidak valid. Coba lagi.\n";
                }
            } while (pilihanSiswa != 5);
            break;
        case 2:
            cout << "Fitur Data Guru belum tersedia.\n";
            break;
        case 3:
            cout << "Fitur Data Kelas belum tersedia.\n";
            break;
        case 4:
            cout << "Keluar dari program...\n";
            break;
        default:
            cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (pilihanUtama != 4);

    return 0;
}