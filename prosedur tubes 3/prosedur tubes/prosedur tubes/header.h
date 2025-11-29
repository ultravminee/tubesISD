#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

typedef char string[50];

typedef struct Peminjaman *addressChild;
typedef struct Mobil *addressParent;
typedef struct Staf *addressStaf;

// ================= CHILD =================
typedef struct Peminjaman {
    string nip;
    string tglPinjam;
    int durasi;
    string tujuan;
    string tglKembali;
    addressChild next;
} DataChild;

// ================= PARENT =================
typedef struct Mobil {
    string plat;
    string merk;
    string warna;
    int status;         
    addressChild firstChild;
    addressParent next;
} DataParent;

// ================= STAF =================
typedef struct Staf {
    string nip;
    string nama;
    string tglMasuk;
    string telp;
    addressStaf next;
} DataStaf;

// ================= MULTILIST =================
typedef struct {
    addressParent firstParent;
    addressStaf firstStaf;
} Multilist;

// ===================== UI ====================
void loadingAnimation();
void tampilEtalaseMobil(Multilist L);
void printMenuUtama(int opsi);
void printMenuKelolaMobil(int opsi, Multilist L);
int hitungMobilByStatus(addressParent firstParent, int status);

// ===================== CHILD =================
addressChild alokasiChild(DataChild x);
void insertFirstChild(addressParent parent, DataChild x);
void insertLastChild(addressParent parent, DataChild x);
void deleteFirstChild(addressParent parent);
void deleteLastChild(addressParent parent);
void deleteAllChild(addressParent parent);

// ===================== PARENT =================
void createEmpty(Multilist *L);
addressParent alokasiParent(DataParent x);
void insertFirstParent(Multilist *L, DataParent x);
void insertLastParent(Multilist *L, DataParent x);
void deleteFirstParent(Multilist *L);
void deleteLastParent(Multilist *L);
void deleteAtParent(Multilist *L, string plat);
addressParent findParent(Multilist L, string plat);
void sortParentByPlat(Multilist *L);
void sortParentByMerk(Multilist *L);

// ===================== STAF ===================
addressStaf alokasiStaf(DataStaf x);
void insertLastStaf(Multilist *L, DataStaf x);
void deleteStaf(Multilist *L, string nip);
addressStaf findStaf(Multilist L, string nip);
void sortStafByNIP(Multilist *L);
void sortStafByNama(Multilist *L);

// ===================== LAPORAN (ARRAY) =========
void sortLaporanByPlat(string plat[], int n);
void sortJumlahPinjam(int total[], string nip[], int n);

// ===================== LAPORAN (MULTILIST) =====
void laporanMobilByNIP(Multilist L, string nip);
void laporanStaffPinjamMobil(Multilist L, string plat);
void laporanJumlahPinjam(Multilist L);
