#include <iostream>
#include <string>

using namespace std;

struct Node {
    string tiengAnh;
    string tiengViet;
    Node* tiepTheo;
};

void khoiTao(Node* &dau) {
    dau = NULL;
}

void themVaoCuoi(Node* &dau, string anh, string viet) {
    Node* nutMoi = new Node;
    nutMoi->tiengAnh = anh;
    nutMoi->tiengViet = viet;
    nutMoi->tiepTheo = NULL;

    if (dau == NULL) {
        dau = nutMoi;
    } else {
        Node* tam = dau;
        while (tam->tiepTheo != NULL) {
            tam = tam->tiepTheo;
        }
        tam->tiepTheo = nutMoi;
    }
}

void inTuDien(Node* dau) {
    if (dau == NULL) {
        cout << "Tu dien trong!" << endl;
        return;
    }
    Node* tam = dau;
    while (tam != NULL) {
        cout << " + " << tam->tiengAnh << ": " << tam->tiengViet << endl;
        tam = tam->tiepTheo;
    }
}

int timTu(Node* dau, string x) {
    Node* tam = dau;
    while (tam != NULL) {
        if (tam->tiengAnh == x) {
            cout << "Tim thay: " << tam->tiengAnh << " -> " << tam->tiengViet << endl;
            return 1;
        }
        tam = tam->tiepTheo;
    }
    return 0;
}

void inDenTuHello(Node* dau) {
    Node* tam = dau;
    bool timThay = false;
    while (tam != NULL) {
        cout << " + " << tam->tiengAnh << ": " << tam->tiengViet << endl;
        if (tam->tiengAnh == "hello") {
            timThay = true;
            break;
        }
        tam = tam->tiepTheo;
    }
    if (!timThay) cout << "(Khong co tu 'hello')" << endl;
}

void xoaTuBatDauBangC(Node* &dau) {
    Node* hienTai = dau;
    Node* phiaTruoc = NULL;
    while (hienTai != NULL) {
        if (!hienTai->tiengAnh.empty() && (hienTai->tiengAnh[0] == 'c' || hienTai->tiengAnh[0] == 'C')) {
            Node* tamXoa = hienTai;
            if (phiaTruoc == NULL) {
                dau = hienTai->tiepTheo;
                hienTai = dau;
            } else {
                phiaTruoc->tiepTheo = hienTai->tiepTheo;
                hienTai = phiaTruoc->tiepTheo;
            }
            delete tamXoa;
        } else {
            phiaTruoc = hienTai;
            hienTai = hienTai->tiepTheo;
        }
    }
}

void sapXepTuDien(Node* dau) {
    for (Node* i = dau; i != NULL && i->tiepTheo != NULL; i = i->tiepTheo) {
        for (Node* j = i->tiepTheo; j != NULL; j = j->tiepTheo) {
            if (i->tiengAnh > j->tiengAnh) {
                swap(i->tiengAnh, j->tiengAnh);
                swap(i->tiengViet, j->tiengViet);
            }
        }
    }
}

int main() {
    Node* tuDien;
    khoiTao(tuDien);

    themVaoCuoi(tuDien, "apple", "qua tao");
    themVaoCuoi(tuDien, "cat", "con meo");
    themVaoCuoi(tuDien, "banana", "qua chuoi");
    themVaoCuoi(tuDien, "dog", "con cho");
    themVaoCuoi(tuDien, "hello", "xin chao");
    themVaoCuoi(tuDien, "car", "xe hoi");
    themVaoCuoi(tuDien, "elephant", "con voi");
    themVaoCuoi(tuDien, "candy", "keo");
    themVaoCuoi(tuDien, "fish", "con ca");
    themVaoCuoi(tuDien, "bird", "con chim");

    cout << "=== TU DIEN ===" << endl;
    inTuDien(tuDien);

    cout << "\n=== TIM KIEM ===" << endl;
    string x;
    cout << "Nhap tu: "; cin >> x;
    if (timTu(tuDien, x) == 0) cout << "0" << endl;

    cout << "\n=== DEN HELLO ===" << endl;
    inDenTuHello(tuDien);

    cout << "\n=== XOA CHU C ===" << endl;
    xoaTuBatDauBangC(tuDien);
    inTuDien(tuDien);

    cout << "\n=== SAP XEP ===" << endl;
    sapXepTuDien(tuDien);
    inTuDien(tuDien);

    return 0;
}
