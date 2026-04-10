#include <iostream>
#include <string>

using namespace std;

struct Node {
    string maMonHoc;
    float diemSo;
    Node* tiepTheo;
};

void khoiTao(Node* &dau) {
    dau = NULL;
}

void themVaoDau(Node* &dau, string ma, float diem) {
    Node* nutMoi = new Node;
    nutMoi->maMonHoc = ma;
    nutMoi->diemSo = diem;
    nutMoi->tiepTheo = dau;
    dau = nutMoi;
}

void inDanhSach(Node* dau) {
    if (dau == NULL) {
        cout << "Danh sach trong!" << endl;
        return;
    }
    Node* tam = dau;
    while (tam != NULL) {
        cout << " + Ma mon: " << tam->maMonHoc << " | Diem: " << tam->diemSo << endl;
        tam = tam->tiepTheo;
    }
}

int demMonDiemThapNhat(Node* dau) {
    if (dau == NULL) return 0;

    float diemThapNhat = dau->diemSo;
    Node* tam = dau->tiepTheo;
    while (tam != NULL) {
        if (tam->diemSo < diemThapNhat) {
            diemThapNhat = tam->diemSo;
        }
        tam = tam->tiepTheo;
    }

    int soLuong = 0;
    tam = dau;
    while (tam != NULL) {
        if (tam->diemSo == diemThapNhat) {
            soLuong++;
        }
        tam = tam->tiepTheo;
    }
    return soLuong;
}

void xoaMonDuoiTrungBinh(Node* &dau) {
    Node* hienTai = dau;
    Node* phiaTruoc = NULL;

    while (hienTai != NULL) {
        if (hienTai->diemSo < 5) {
            Node* nutCanXoa = hienTai;
            if (phiaTruoc == NULL) {
                dau = hienTai->tiepTheo;
                hienTai = dau;
            } else {
                phiaTruoc->tiepTheo = hienTai->tiepTheo;
                hienTai = phiaTruoc->tiepTheo;
            }
            delete nutCanXoa;
        } else {
            phiaTruoc = hienTai;
            hienTai = hienTai->tiepTheo;
        }
    }
}

int main() {
    Node* danhSachDiem;
    khoiTao(danhSachDiem);

    themVaoDau(danhSachDiem, "TRIET_HOC", 4.5);
    themVaoDau(danhSachDiem, "TIN_DAI_CUONG", 8.2);
    themVaoDau(danhSachDiem, "VAT_LY_1", 3.5);
    themVaoDau(danhSachDiem, "TOAN_CAO_CAP", 7.0);
    themVaoDau(danhSachDiem, "TIENG_ANH_1", 3.5);

    cout << "=== DANH SACH DIEM BAN DAU ===" << endl;
    inDanhSach(danhSachDiem);

    cout << "\nSo luong mon hoc co diem thap nhat: " << demMonDiemThapNhat(danhSachDiem) << endl;

    xoaMonDuoiTrungBinh(danhSachDiem);

    cout << "\n=== DANH SACH SAU KHI XOA DIEM < 5 ===" << endl;
    inDanhSach(danhSachDiem);

    return 0;
}
