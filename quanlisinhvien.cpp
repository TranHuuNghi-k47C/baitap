#include <iostream>
#include <string>
#include <iomanip> // Thu vien de can le thong tin cho dep

using namespace std;

// 1. Khai bao cau truc Sinh Vien
struct SinhVien {
    string maSV;
    string hoTen;
    float diemTB;
};

struct Node {
    SinhVien info;
    Node* next;
};

// Ham tao node moi
Node* createNode(string ma, string ten, float diem) {
    Node* newNode = new Node;
    newNode->info.maSV = ma;
    newNode->info.hoTen = ten;
    newNode->info.diemTB = diem;
    newNode->next = NULL;
    return newNode;
}

// 2. Them sinh vien vao DAU danh sach (insertFirst)
void insertFirst(Node*& head, string ma, string ten, float diem) {
    Node* newNode = createNode(ma, ten, diem);
    newNode->next = head;
    head = newNode;
}

// 3. In danh sach sinh vien
void printList(Node* head) {
    if (head == NULL) {
        cout << "Danh sach trong!" << endl;
        return;
    }
    cout << left << setw(10) << "Ma SV" << setw(25) << "Ho Ten" << setw(10) << "Diem TB" << endl;
    cout << "---------------------------------------------" << endl;
    Node* temp = head;
    while (temp != NULL) {
        cout << left << setw(10) << temp->info.maSV 
             << setw(25) << temp->info.hoTen 
             << setw(10) << temp->info.diemTB << endl;
        temp = temp->next;
    }
}

// 4. Loc sinh vien co Diem TB >= 8.0
void printGioi(Node* head) {
    cout << "\n--- Danh sach Sinh Vien Gioi (DTB >= 8.0) ---" << endl;
    Node* temp = head;
    bool coSV = false;
    while (temp != NULL) {
        if (temp->info.diemTB >= 8.0) {
            cout << temp->info.hoTen << " - Diem: " << temp->info.diemTB << endl;
            coSV = true;
        }
        temp = temp->next;
    }
    if (!coSV) cout << "Khong co sinh vien gioi." << endl;
}

// 5. Tinh diem trung binh cong cua ca lop
float tinhTBC(Node* head) {
    if (head == NULL) return 0;
    float sum = 0;
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        sum += temp->info.diemTB;
        count++;
        temp = temp->next;
    }
    return sum / count;
}

int main() {
    Node* list = NULL;

    // Them sinh vien (Them vao dau nen nguoi nhap sau cung se hien len dau)
    insertFirst(list, "SV001", "Tran Huu Nghi", 8.5);
    insertFirst(list, "SV002", "Nguyen Van A", 4.5);
    insertFirst(list, "SV003", "Le Thi B", 9.0);
    insertFirst(list, "SV004", "Pham Van C", 7.2);
    insertFirst(list, "SV005", "Hoang Thi D", 5.0);

    cout << "--- Danh sach sinh vien toan lop ---" << endl;
    printList(list);

    printGioi(list);

    cout << "\n--- Thong ke ---" << endl;
    cout << "Diem trung binh cong cua lop: " << fixed << setprecision(2) << tinhTBC(list) << endl;

    return 0;
}
