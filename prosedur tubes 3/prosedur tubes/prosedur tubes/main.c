#include "header.h"

int main() {
    Multilist L;
    int opsi = 0;
    int subOpsi = 0;
    char tombol;

    createEmpty(&L);

    // Landing
    printf("\n [*] Terima kasih [*]\n");
    
    //cobadoangggyaa
    printf("HAIIAIIA");
    
    system("cls");
    tampilEtalaseMobil(L);
    printf("Tekan tombol apapun untuk masuk ke Menu Utama...\n");
    getch();
    loadingAnimation();
    Sleep(300);
    system("cls");

    while (1) {

        printMenuUtama(opsi);
        tombol = toupper(getch());

        // Navigasi menu utama
        if (tombol == 'W') {
            opsi = (opsi == 0 ? 7 : opsi - 1);
        } else if (tombol == 'S') {
            opsi = (opsi == 7 ? 0 : opsi + 1);
        } else if (tombol == 13) {    // ENTER

            // Keluar Program
            if (opsi == 7) {
                system("cls");
                printf("\n [*] Terima kasih [*]\n");
                break;
            }

            // KELOLA DATA MOBIL
            if (opsi == 0) {

                subOpsi = 0;

                while (1) {
                    printMenuKelolaMobil(subOpsi, L);
                    tombol = toupper(getch());

                    if (tombol == 'W') {
                        subOpsi = (subOpsi == 0 ? 4 : subOpsi - 1);
                    } else if (tombol == 'S') {
                        subOpsi = (subOpsi == 4 ? 0 : subOpsi + 1);
                    } else if (tombol == 13) {

                        // Tambah Mobil
                        if (subOpsi == 0) {
                            DataParent M;

                            system("cls");
                            printf("\n>> Tambah Data Mobil\n\n");
                            fflush(stdin);

                            printf("Nomor Plat : ");
                            gets(M.plat);

                            printf("Merk       : ");
                            gets(M.merk);

                            printf("Warna      : ");
                            gets(M.warna);

                            M.status = 0;
                            M.firstChild = NULL;

                            insertLastParent(&L, M);
                            printf("\n>> Mobil berhasil ditambahkan!\n");
                            printf("Tekan tombol apapun...");
                            getch();
                        }

                        // Edit Mobil
                        else if (subOpsi == 1) {
                            string plat;
                            addressParent P;

                            system("cls");
                            printf("\n>> Edit Data Mobil\n\n");
                            fflush(stdin);

                            printf("Masukkan Nomor Plat: ");
                            gets(plat);

                            P = findParent(L, plat);
                            if (P == NULL) {
                                printf("\n>> Mobil tidak ditemukan!\n");
                            } else {
                                printf("\nData lama:\n");
                                printf("Merk  : %s\n", P->merk);
                                printf("Warna : %s\n", P->warna);

                                printf("\nMerk baru  : ");
                                gets(P->merk);

                                printf("Warna baru : ");
                                gets(P->warna);

                                printf("\n>> Data mobil berhasil diperbarui!\n");
                            }
                            printf("Tekan tombol apapun...");
                            getch();
                        }

                        // Hapus Mobil
                        else if (subOpsi == 2) {
                            string plat;
                            addressParent P;

                            system("cls");
                            printf("\n>> Hapus Data Mobil\n\n");
                            fflush(stdin);

                            printf("Masukkan Nomor Plat: ");
                            gets(plat);

                            P = findParent(L, plat);
                            if (P == NULL) {
                                printf("\n>> Mobil tidak ditemukan!\n");
                            } else {
                                deleteAtParent(&L, plat);
                                printf("\n>> Mobil berhasil dihapus!\n");
                            }
                            printf("Tekan tombol apapun...");
                            getch();
                        }

                        // Tampilkan Semua Mobil
                        else if (subOpsi == 3) {
                            addressParent P = L.firstParent;

                            system("cls");
                            printf("\n==================== DAFTAR MOBIL DINAS ====================\n\n");

                            if (P == NULL) {
                                printf("Belum ada data mobil.\n");
                            } else {
                                while (P != NULL) {
                                    printf("Plat   : %s\n", P->plat);
                                    printf("Merk   : %s\n", P->merk);
                                    printf("Warna  : %s\n", P->warna);
                                    printf("Status : %s\n", (P->status == 0 ? "Tersedia" : "Dipinjam"));
                                    printf("------------------------------------------------------------\n");
                                    P = P->next;
                                }
                            }
                            printf("Tekan tombol apapun...");
                            getch();
                        }

                        // Kembali
                        else if (subOpsi == 4) {
                            break;
                        }
                    }
                } // end while submenu
            }

            // Menu lain (sementara belum diimplementasi)
            else {
                system("cls");
                printf("\nMenu belum diimplementasi.\n");
                printf("Tekan tombol apapun...");
                getch();
            }
        }
    }

    return 0;
}

