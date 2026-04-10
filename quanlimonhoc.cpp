#include <iostream>
#include <string>

using namespace std;

// 1. Khai bao cau truc Mon Hoc
struct MonHoc {
    string maMon;
    string tenMon;
    int soTinChi;
};

struct Node {
    MonHoc info;
    Node* next;
};

Node* createNode(string ma, string ten, int stc) {
    Node* newNode = new Node;
    newNode->info.maMon = ma;
    newNode->info.tenMon = ten;
    newNode->info.soTinChi = stc;
    newNode->next = NULL;
    return newNode;
}

// Ham them vao cuoi de tao danh sach ban dau
void insertLast(Node*& head, string ma, string ten, int stc) {
    Node* newNode = createNode(ma, ten, stc);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

// 2. Chen sau mot Ma Mon chi dinh
void insertAfter(Node* head, string maTim, string maMoi, string tenMoi, int stcMoi) {
    Node* temp = head;
    while (temp != NULL && temp->info.maMon != maTim) {
        temp = temp->next;
    }
    
    if (temp != NULL) {
        Node* newNode = createNode(maMoi, tenMoi, stcMoi);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Da chen mon " << maMoi << " sau mon " << maTim << endl;
    } else {
        cout << "Khong tim thay ma mon " << maTim << " de chen." << endl;
    }
}

// 3. Tim kiem theo Ten Mon
void searchByName(Node* head, string tenTim) {
    Node* temp = head;
    bool found = false;
    while (temp != NULL) {
        if (temp->info.tenMon == tenTim) {
            cout << "Tim thay: " << temp->info.maMon << " - " << temp->info.tenMon << " (" << temp->info.soTinChi << " tin chi)" << endl;
            found = true;
        }
        temp = temp->next;
    }
    if (!found) cout << "Khong tim thay mon hoc co ten: " << tenTim << endl;
}

// 4. Xoa mon hoc co So tin chi bang 0
void deleteZeroSTC(Node*& head) {
    // Xu ly xoa o dau danh sach
    while (head != NULL && head->info.soTinChi == 0) {
        Node* del = head;
        head = head->next;
        delete del;
    }
    
    // Xu ly xoa o giua va cuoi
    if (head == NULL) return;
    Node* temp = head;
    while (temp->next != NULL) {
        if (temp->next->info.soTinChi == 0) {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
        } else {
            temp = temp->next;
        }
    }
}

// In danh sach
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "- " << temp->info.maMon << " | " << temp->info.tenMon << " | " << temp->info.soTinChi << " TC" << endl;
        temp = temp->next;
    }
}

int main() {
    Node* list = NULL;

    insertLast(list, "IT01", "Lap trinh C", 3);
    insertLast(list, "IT02", "Cau truc du lieu", 0); // Mon co 0 tin chi de xoa
    insertLast(list, "IT03", "Mang may tinh", 4);
    insertLast(list, "IT04", "Toan roi rac", 0);   // Mon co 0 tin chi de xoa

    cout << "--- Danh sach mon hoc ban dau ---" << endl;
    printList(list);

    cout << "\n--- Thuc hien chen sau mon IT01 ---" << endl;
    insertAfter(list, "IT01", "IT05", "Co so du lieu", 3);
    printList(list);

    cout << "\n--- Tim kiem mon 'Mang may tinh' ---" << endl;
    searchByName(list, "Mang may tinh");

    cout << "\n--- Xoa cac mon co 0 tin chi ---" << endl;
    deleteZeroSTC(list);
    printList(list);

    return 0;
}
