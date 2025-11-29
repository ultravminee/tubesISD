#include "header.h"

// Membuat node data peminjaman
addressChild alokasiChild(DataChild x) {
    addressChild c = (addressChild) malloc(sizeof(DataChild));
    c->next = NULL;
    strcpy(c->nip, x.nip);
    strcpy(c->tglPinjam, x.tglPinjam);
    strcpy(c->tujuan, x.tujuan);
    strcpy(c->tglKembali, x.tglKembali);
    c->durasi = x.durasi;
    return c;
}

// Menambah data peminjaman pertama
void insertFirstChild(addressParent parent, DataChild x) {
    addressChild c = alokasiChild(x);
    c->next = parent->firstChild;
    parent->firstChild = c;
}

// Menambah data peminjaman terakhir
void insertLastChild(addressParent parent, DataChild x) {
    if(parent->firstChild == NULL) {
        insertFirstChild(parent, x);
    } else {
        addressChild last = parent->firstChild;
        while(last->next != NULL)
            last = last->next;

        last->next = alokasiChild(x);
    }
}

// Hapus child pertama
void deleteFirstChild(addressParent parent) {
    if(parent->firstChild != NULL) {
        addressChild del = parent->firstChild;
        parent->firstChild = del->next;
        free(del);
    }
}

// Hapus child terakhir
void deleteLastChild(addressParent parent) {
    if(parent->firstChild != NULL) {
        if(parent->firstChild->next == NULL)
            deleteFirstChild(parent);
        else {
            addressChild q = parent->firstChild;
            while(q->next->next != NULL)
                q = q->next;
            free(q->next);
            q->next = NULL;
        }
    }
}

// Hapus semua peminjaman pada mobil tertentu
void deleteAllChild(addressParent parent) {
    while(parent->firstChild != NULL)
        deleteFirstChild(parent);
}

void sortChildByNIP(addressParent parent) {
    addressChild p, q;
    DataChild temp;

    if (parent->firstChild != NULL) {
        p = parent->firstChild;
        while (p != NULL) {
            q = p->next;
            while (q != NULL) {

                if (strcmp(p->nip, q->nip) > 0) {
                    temp = *p;
                    *p = *q;
                    *q = temp;

                    addressChild tmp = p->next;
                    p->next = q->next;
                    q->next = tmp;
                }

                q = q->next;
            }
            p = p->next;
        }
    }
}
