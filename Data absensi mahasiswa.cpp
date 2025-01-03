#include <iostream>
#include <cstring>
using namespace std;

class Mahasiswa {
public:
    char nim[20];
    char nama[50];
    char kehadiran[10]; 
    int NIM;
    int hadir;
    float persen;

    // Konstruktor untuk inisialisasi
    Mahasiswa() : hadir(0) {
        memset(kehadiran, '-', sizeof(kehadiran));
    }

    // Input data 
    void inputData(int i) {
        cout << "Input Data Mahasiswa Ke-" << i + 1 << endl;
        cout <<  "NIM: ";
        cin.getline(nim, 20);
        cout << "Nama: ";
        cin.getline(nama, 50);
    }

    // Presensi kehadiran perminggu
    void presensi(int minggu) {
        if (minggu < 0 || minggu >= 10) {
            cout << "Minggu tidak valid!\n";
            return;
        }

        char status;
        cout << nim << "\t" << nama << "\tKehadiran [H/A/I/S]: ";
        cin >> status;

        // Validasi input
        if (status == 'H' || status == 'A' || status == 'I' || status == 'S') {
            kehadiran[minggu] = status;
            if (status == 'H') {
                hadir++; 
            }
        } else {
            cout << "Input tidak valid! Harap masukkan [H/A/I/S].\n";
        }
    }

    // Rekapitulasi data 
    void rekapData(int totalMinggu) {
        persen = (float)hadir * 100 / totalMinggu; // Menghitung persentase kehadiran
        cout << "NIM: " << nim << "\tNama: " << nama 
             << "\tPersentase Kehadiran: " << persen << "%" << endl;
    }
};

int main() {
    const int MAX_MAHASISWA = 5; // Jumlah mahasiswa (misal absensi 5 mahasiswa perminggu)
    const int MAX_MINGGU = 10;  // Maksimum jumlah minggu (absensi)
    Mahasiswa mhs[MAX_MAHASISWA];

    // Input data mahasiswa
    for (int i = 0; i < MAX_MAHASISWA; i++) {
        mhs[i].inputData(i);
    }

    // Presensi
    int minggu = 0;
    char lagi;
    do {
        cout << "\nAbsensi Minggu ke-" << minggu + 1 << endl;
        for (int x = 0; x < MAX_MAHASISWA; x++) {
            mhs[x].presensi(minggu);
        }
        minggu++;
        if (minggu >= MAX_MINGGU) {
            cout << "Maksimum minggu presensi tercapai.\n";
            break;
        }
        cout << "Absensi Minggu Berikutnya [Y/N]? ";
        cin >> lagi;
    } while ((lagi == 'Y' || lagi == 'y') && minggu < MAX_MINGGU);

    // Rekap Data
    cout << "\n=====Rekap Data Kehadiran:=====\n";
    for (int i = 0; i < MAX_MAHASISWA; i++) {
        mhs[i].rekapData(minggu); 
    }

    return 0;
}
