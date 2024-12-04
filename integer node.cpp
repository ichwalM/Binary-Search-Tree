#include <iostream>
#include <string>

using namespace std;

struct Node {
    string nama;
    string nip;
    string alamat;
    Node *next;
    Node *prev;
};

Node *head = NULL, *tail = NULL, *n = NULL, *x = NULL;

void buatNodeBaru(string nama, string nip, string alamat) {
    n = new Node;
    n->nama = nama;
    n->nip = nip;
    n->alamat = alamat;
    n->next = NULL;
    n->prev = NULL;
    head = n;
    tail = n;
    cout << "dosen " << nama << " berhasil ditambahkan di awal.\n";
}

void tambahDiBelakang(string  nama, string  nip, string  alamat) {
    n = new Node;
    n->nama = nama;
    n->nip = nip;
    n->alamat = alamat;
    n->prev = tail;
    n->next = NULL;
    tail->next = n;
    tail = n;
    cout << "dosen " << nama << " berhasil ditambahkan di belakang.\n";
}

void tambahDiDepan(string  nama, string  nip, string  alamat) {
    n = new Node;
    n->nama = nama;
    n->nip = nip;
    n->alamat = alamat;
    n->next = head;
    n->prev = NULL;
    head->prev = n;
    head = n;
    cout << "dosen " << nama << " berhasil ditambahkan di depan.\n";
}




void tambahDiTengah( string  nama, string  nip,   string  alamat,   string  after_nip) {
    x = head;
    while (x != NULL  && x->nip != after_nip) {
        x = x->next;
    }
    
    if (x == NULL) {
        cout << "dosen dengan NIP " << after_nip << " tidak ditemukan.\n";
        return;
    }
	
    n = new Node;
    n->nama = nama;
    n->nip = nip;
    n->alamat = alamat;
    n->next = x->next;
    n->prev = x;
    if (x->next != NULL) {
        x->next->prev = n;
    } else {
        tail = n;
    }
    x->next = n;
    cout << "Data dosen " << nama << " berhasil ditambahkan setelah NIP " << after_nip << ".\n";
	
}

void hapusDiDepan() {
    Node *temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL;
    }
    cout << "dosen " << temp->nama << " berhasil dihapus depan.\n";
    delete temp;
}

void hapusDiBelakang() {
    Node *temp = tail;
    tail = tail->prev;
    if (tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL;
    }
    cout << "Data dosen " << temp->nama << " berhasil dihapus dari belakang.\n";
    delete temp;
}

void hapusDiTengah(  string nip) {
    x = head;
    while (x != NULL && x->nip != nip) {
        x = x->next;
    }
    if (x == NULL) {
        cout << "dosen dengan NIP " << nip << " tidak ditemukan.\n";
        return;
    }
        x->prev->next = x->next;
        x->next->prev = x->prev;
        cout << "Data dosen " << x->nama << " berhasil dihapusd ditengah.\n";
        delete x;
}

void tampilDariDepan() {
    Node *temp = head;
    cout << "Data dosen dari depan:\n";
    while (temp != NULL) {
        cout <<"Nama: " << temp->nama << "\n";
		cout<<"NIP: " << temp->nip << "\n"; 
		cout<<"Alamat: " << temp->alamat << "\n\n";
        temp = temp->next;
    }
}

void tampilDariBelakang() {
    Node *temp = tail;
    cout << "Data dari belakang:\n";
    while (temp != NULL) {
        cout <<"Nama: " << temp->nama << "\n";
		cout<<"NIP: " << temp->nip << "\n"; 
		cout<<"Alamat: " << temp->alamat << "\n\n";
        temp = temp->prev;
    }
}

void editDataDosen(string& nip) {
    Node *current = head;
    while (current != NULL && current->nip != nip) {
        current = current->next;
    }
    if (current == NULL) {
        cout << "Data dosen dengan NIP " << nip << " tidak ditemukan.\n";
        return;
    }
    cout << "Masukkan data baru untuk dosen dengan NIP " << nip << ":\n";
    cout << "Nama: "; getline(cin, current->nama);
    cout << "NIP: "; getline(cin, current->nip);
    cout << "Alamat: "; getline(cin, current->alamat);
    cout << "Data dosen berhasil diperbarui.\n";
}

int hitungJumlahDosen() {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
bool search(string src){
	x=head;
	while(x!=NULL){
		if(x->nama==src){
			return true;
		}
		x=x->next;
	}return false;
}