#include "header.h"

// ================= ETALASE MOBIL =========================
void tampilEtalaseMobil(Multilist L) {
    addressParent p;
    int total = 0;
    int tersedia = 0;
    int dipinjam = 0;
    int i;

    p = L.firstParent;
    while (p != NULL) {
        total++;
        if (p->status == 0)
            tersedia++;
        else
            dipinjam++;
        p = p->next;
    }

    printf("\t===============================================================\n");
    printf("\t||                    A T M A P R O T E C T                  ||\n");             
    printf("\t===============================================================\n");
    printf("\t||            SISTEM INFORMASI PEMINJAMAN MOBIL DINAS        ||\n");
    printf("\t---------------------------------------------------------------\n");
    printf("\t||                    [ ETALASE MOBIL DINAS ]                ||\n");
    printf("\t||              Status Mobil: Tersedia / Dipinjam            ||\n");
    printf("\t---------------------------------------------------------------\n\n");
 
    if (total == 0) {
        printf("Belum ada data mobil.\n");
        printf("Silakan masuk ke menu Kelola Mobil untuk menambah data.\n\n");
    } else {
        printf("Ringkasan:\n");
        printf(" - Total Mobil   : %d\n", total);
        printf(" - Tersedia      : %d\n", tersedia);
        printf(" - Dipinjam      : %d\n\n", dipinjam);

        printf("---------------------------------------------------------------\n");

        p = L.firstParent;
        i = 1;
        while (p != NULL) {
            printf("(%d) No. Plat : %s\n", i, p->plat);
            printf("     Merk     : %s\n", p->merk);
            printf("     Warna    : %s\n", p->warna);
            printf("     Status   : %s\n\n", (p->status == 0 ? "Tersedia" : "Dipinjam"));
            p = p->next;
            i++;
        }
    }

    printf("---------------------------------------------------------------\n");
}

void loadingAnimation() {
    int i;
    char loading[] = "|/-\\";

	printf("\n\n\033[32m"); 
    printf("\n\t\tLoading ");
    for (i = 0; i < 20; i++) {
        printf("%c", loading[i % 4]);
        Sleep(100);
        printf("\b");
    }
    printf("Done!\033[0m\n"); 
}

// ================= MENU UTAMA ============================
void printMenuUtama(int opsi) {
    int i, total;
    string menu[] = {
        "Kelola Data Mobil",
        "Kelola Data Staf",
        "Peminjaman Mobil",
        "Pengembalian Mobil",
        "Daftar Mobil Dinas",
        "Daftar Staf",
        "Laporan Peminjaman Mobil",
        "Keluar Program"
    };

    total = 8;

    system("cls");
    printf("\n==================== MENU UTAMA =====================\n\n");

    for (i = 0; i < total; i++) {
        if (i == opsi) {
            printf("\033[1;34m>> %s\033[0m\n", menu[i]);

        } else {
            printf("   %s\n", menu[i]);
        }
    }

    printf("\nGunakan [W] Atas  [S] Bawah. ENTER untuk pilih.\n");
    printf("======================================================\n");
}

// ================= MENU KELOLA MOBIL ===================
void printMenuKelolaMobil(int opsi, Multilist L) {
    int i, total;
    string menu[] = {
        "Tambah Data Mobil",
        "Edit Data Mobil",
        "Hapus Data Mobil",
        "Tampilkan Semua Mobil",
        "Kembali"
    };

    total = 5;

    system("cls");
    tampilEtalaseMobil(L);

    printf("\n==================== KELOLA DATA MOBIL ====================\n\n");

    for (i = 0; i < total; i++) {
        if (opsi == i) {
            printf("\033[1;34m>> %s\033[0m\n", menu[i]);
        } else {
            printf("   %s\n", menu[i]);
        }
    }

    printf("\nGunakan [W] Atas  [S] Bawah. ENTER untuk pilih.\n");
    printf("===========================================================\n");
}

// ================= LIST MULTILIST =======================
void createEmpty(Multilist *L) {
    L->firstParent = NULL;
    L->firstStaf   = NULL;
}

// ================= ALOKASI PARENT =======================
addressParent alokasiParent(DataParent x) {
    addressParent p = (addressParent) malloc(sizeof(DataParent));
    p->next = NULL;
    p->firstChild = NULL;
    strcpy(p->plat, x.plat);
    strcpy(p->merk, x.merk);
    strcpy(p->warna, x.warna);
    p->status = x.status;
    return p;
}

// ================= INSERT PARENT ========================
void insertFirstParent(Multilist *L, DataParent x) {
    addressParent p = alokasiParent(x);
    p->next = L->firstParent;
    L->firstParent = p;
}

void insertLastParent(Multilist *L, DataParent x) {
    if(L->firstParent == NULL)
        insertFirstParent(L, x);
    else {
        addressParent last = L->firstParent;
        while(last->next != NULL)
            last = last->next;

        last->next = alokasiParent(x);
    }
}

// ================= CARI PARENT ==========================
addressParent findParent(Multilist L, string plat) {
    addressParent p = L.firstParent;
    while (p != NULL && strcmp(p->plat, plat) != 0) {
        p = p->next;
    }
    return p;
}

// ================= DELETE PARENT ========================
void deleteFirstParent(Multilist *L) {
    addressParent del = L->firstParent;
    if(del != NULL) {
        deleteAllChild(del);
        L->firstParent = del->next;
        free(del);
    }
}

void deleteLastParent(Multilist *L) {
    if(L->firstParent != NULL) {
        if(L->firstParent->next == NULL)
            deleteFirstParent(L);
        else {
            addressParent q = L->firstParent;
            while(q->next->next != NULL)
                q = q->next;
            deleteAllChild(q->next);
            free(q->next);
            q->next = NULL;
        }
    }
}

void deleteAtParent(Multilist *L, string plat) {
    if(L->firstParent != NULL) {
        if(strcmp(L->firstParent->plat, plat) == 0)
            deleteFirstParent(L);
        else {
            addressParent q = L->firstParent;
            while(q->next != NULL && strcmp(q->next->plat, plat) != 0)
                q = q->next;

            if(q->next != NULL) {
                addressParent del = q->next;
                q->next = del->next;
                deleteAllChild(del);
                free(del);
            }
        }
    }
}

// ================= SORT PARENT ==========================

void sortParentByPlat(Multilist *L) {
    addressParent p, q;
    DataParent temp;

    if (L->firstParent == NULL) {
		return;
	}
	
    p = L->firstParent;
    
    while (p != NULL) {
        q = p->next;
        while (q != NULL) {
            if (strcmp(p->plat, q->plat) > 0) {
                // swap data (bukan pointer)
                temp = *p;
                *p = *q;
                *q = temp;

                // kembalikan pointer next
                addressParent t = p->next;
                p->next = q->next;
                q->next = t;
            }
            q = q->next;
        }
        p = p->next;
    }
}

void sortParentByMerk(Multilist *L) {
    addressParent p, q;
    DataParent temp;

    if (L->firstParent == NULL) return;

    p = L->firstParent;
    while (p != NULL) {
        q = p->next;
        while (q != NULL) {
            if (strcmp(p->merk, q->merk) > 0) {
                temp = *p;
                *p = *q;
                *q = temp;

                addressParent t = p->next;
                p->next = q->next;
                q->next = t;
            }
            q = q->next;
        }
        p = p->next;
    }
}

