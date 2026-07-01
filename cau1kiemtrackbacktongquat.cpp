#include <iostream>
#include <string>
#include <vector>

using namespace std;

// =========================================================================
// a) (1 diem) Khai bao cau truc du lieu cay tong quat
// =========================================================================
struct Node {
    string ten;
    float kichThuoc; // Tinh bang MB. Thu muc thi kich thuoc = 0
    vector<Node*> con; // Danh sach cac nut con (Su dung vector chua con tro)
};

// Ham ho tro: Tao mot nut moi
Node* taoNut(string ten, float kichThuoc) {
    Node* p = new Node;
    p->ten = ten;
    p->kichThuoc = kichThuoc;
    return p;
}

// Ham ho tro: Tim mot nut co ten x trong cay
Node* timNut(Node* goc, string x) {
    if (goc == NULL) return NULL;
    if (goc->ten == x) return goc;
    
    // Duyet qua cac nut con de tim kiem
    for (int i = 0; i < (int)goc->con.size(); i++) {
        Node* ketQua = timNut(goc->con[i], x);
        if (ketQua != NULL) return ketQua;
    }
    return NULL;
}

// =========================================================================
// b) (1 diem) Them 1 tep tin/thu muc lam con cua thu muc ten x
// =========================================================================
void themNut(Node* goc, string tenThuMucCha, string tenMoi, float kichThuocMoi) {
    Node* cha = timNut(goc, tenThuMucCha);
    if (cha != NULL) {
        if (cha->kichThuoc == 0) { // Chi cho phep them vao thu muc (kich thuoc = 0)
            Node* moi = taoNut(tenMoi, kichThuocMoi);
            cha->con.push_back(moi);
            cout << "Da them '" << tenMoi << "' vao '" << tenThuMucCha << "'." << endl;
        } else {
            cout << "Loi: '" << tenThuMucCha << "' la tep tin, khong the chua nut con!" << endl;
        }
    } else {
        cout << "Loi: Khong tim thay thu muc '" << tenThuMucCha << "' de them!" << endl;
    }
}

// =========================================================================
// c) (1 diem) Ham kiem tra xem tep/thu muc ten x co ton tai hay khong
// =========================================================================
bool kiemTraTonTai(Node* goc, string x) {
    return timNut(goc, x) != NULL;
}

// =========================================================================
// d) (1 diem) Liet ke cac tep tin co kich thuoc lon nhat trong cay
// =========================================================================
// Buoc 1: Tim kich thuoc lon nhat
void timKichThuocLonNhat(Node* goc, float& maxSize) {
    if (goc == NULL) return;
    if (goc->kichThuoc > maxSize) {
        maxSize = goc->kichThuoc;
    }
    for (int i = 0; i < (int)goc->con.size(); i++) {
        timKichThuocLonNhat(goc->con[i], maxSize);
    }
}

// Buoc 2: In cac tep tin co kich thuoc bang voi maxSize
void inTepKichThuocMax(Node* goc, float maxSize) {
    if (goc == NULL) return;
    if (goc->kichThuoc == maxSize && maxSize > 0) { // Chi in tep tin, khong in thu muc rong
        cout << " - " << goc->ten << " (" << goc->kichThuoc << " MB)" << endl;
    }
    for (int i = 0; i < (int)goc->con.size(); i++) {
        inTepKichThuocMax(goc->con[i], maxSize);
    }
}

// Ham tong hop cho cau d
void lietKeTepMax(Node* goc) {
    float maxSize = 0;
    timKichThuocLonNhat(goc, maxSize);
    
    if (maxSize == 0) {
        cout << "Khong co tep tin nao hoac tat ca tep tin deu 0MB!" << endl;
    } else {
        cout << "Cac tep tin co kich thuoc lon nhat (" << maxSize << " MB):" << endl;
        inTepKichThuocMax(goc, maxSize);
    }
}

// =========================================================================
// e) (1 diem) Ham main thuc thi cac cong viec
// =========================================================================
int main() {
    // 1. Tao cay thu muc nhu hinh ben
    Node* goc = taoNut("May Tinh", 0);
    
    Node* tailieu = taoNut("Tai lieu", 0);
    Node* anh = taoNut("Anh", 0);
    goc->con.push_back(tailieu);
    goc->con.push_back(anh);
    
    Node* cv = taoNut("CV.pdf", 2);
    tailieu->con.push_back(cv);
    
    Node* dulich = taoNut("Dulich.jpg", 5);
    anh->con.push_back(dulich);
    
    cout << "--- HE THONG QUAN LY CAY THU MUC ---" << endl;
    
    // 2. Them 1 tep ten cds.docx (5MB) con cua thu muc Tai lieu
    themNut(goc, "Tai lieu", "cds.docx", 5);
    
    cout << "------------------------------------" << endl;
    
    // 3. Nhap vao ten tep tin/thu muc, cho biet co trong cay khong
    string tenCanTim;
    cout << "Nhap ten tep/thu muc can tim: ";
    getline(cin, tenCanTim); // Dung getline de ho tro doc ten co khoang trang
    
    if (kiemTraTonTai(goc, tenCanTim)) {
        cout << "=> KET QUA: '" << tenCanTim << "' CO ton tai trong he thong." << endl;
    } else {
        cout << "=> KET QUA: '" << tenCanTim << "' KHONG ton tai trong he thong." << endl;
    }
    
    cout << "------------------------------------" << endl;
    
    // 4. Liet ke tat ca cac tep tin co kich thuoc lon nhat
    lietKeTepMax(goc);
    
    cout << "------------------------------------" << endl;

    return 0;
}
