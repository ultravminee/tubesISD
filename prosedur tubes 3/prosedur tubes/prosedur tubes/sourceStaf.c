#include "header.h"

// ================= ALOKASI STAF =========================
addressStaf alokasiStaf(DataStaf x) {
    addressStaf s = (addressStaf) malloc(sizeof(DataStaf));
    strcpy(s->nip, x.nip);
    strcpy(s->nama, x.nama);
    strcpy(s->tglMasuk, x.tglMasuk);
    strcpy(s->telp, x.telp);
    s->next = NULL;
    return s;
}

// ================= INSERT STAF ==========================
void insertLastStaf(Multilist *L, DataStaf x) {
    if(L->firstStaf == NULL)
        L->firstStaf = alokasiStaf(x);
    else {
        addressStaf last = L->firstStaf;
        while(last->next != NULL)
            last = last->next;

        last->next = alokasiStaf(x);
    }
}

// ================= CARI STAF ============================
addressStaf findStaf(Multilist L, string nip) {
    addressStaf s = L.firstStaf;
    while (s != NULL && strcmp(s->nip, nip) != 0) {
        s = s->next;
    }
    return s;
}

// ================= HAPUS STAF ===========================
void deleteStaf(Multilist *L, string nip) {
    addressStaf p, q;

    if (L->firstStaf != NULL) {
        if (strcmp(L->firstStaf->nip, nip) == 0) {
            p = L->firstStaf;
            L->firstStaf = p->next;
            free(p);
        } else {
            p = L->firstStaf;
            while (p->next != NULL && strcmp(p->next->nip, nip) != 0) {
                p = p->next;
            }
            if (p->next != NULL) {
                q = p->next;
                p->next = q->next;
                free(q);
            }
        }
    }
}

// ================= SORT STAF ============================
void sortStafByNIP(Multilist *L) {
    addressStaf p, q;
    DataStaf temp;

    if (L->firstStaf == NULL) return;

    p = L->firstStaf;
    while (p != NULL) {
        q = p->next;
        while (q != NULL) {
            if (strcmp(p->nip, q->nip) > 0) {
                temp = *p;
                *p = *q;
                *q = temp;

                addressStaf t = p->next;
                p->next = q->next;
                q->next = t;
            }
            q = q->next;
        }
        p = p->next;
    }
}

void sortStafByNama(Multilist *L) {
    addressStaf p, q;
    DataStaf temp;

    if (L->firstStaf == NULL) return;

    p = L->firstStaf;
    while (p != NULL) {
        q = p->next;
        while (q != NULL) {
            if (strcmp(p->nama, q->nama) > 0) {
                temp = *p;
                *p = *q;
                *q = temp;

                addressStaf t = p->next;
                p->next = q->next;
                q->next = t;
            }
            q = q->next;
        }
        p = p->next;
    }
}


void sortLaporanByPlat(string plat[], int n) {
    int i, j;
    string temp;

    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(strcmp(plat[i], plat[j]) > 0) {
                strcpy(temp, plat[i]);
                strcpy(plat[i], plat[j]);
                strcpy(plat[j], temp);
            }
        }
    }
}

// Sorting jumlah pinjaman terbanyak (descending)
void sortJumlahPinjam(int total[], string nip[], int n) {
    int i, j, tmp;
    string nipTemp;

    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(total[i] < total[j]) {
                tmp = total[i];
                total[i] = total[j];
                total[j] = tmp;

                strcpy(nipTemp, nip[i]);
                strcpy(nip[i], nip[j]);
                strcpy(nip[j], nipTemp);
            }
        }
    }
}

