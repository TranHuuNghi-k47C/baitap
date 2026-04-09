#include <iostream>
#include <string>
#include <algorithm> // Thu vien cho ham swap

using namespace std;

// 1. Khai bao cau truc du lieu
struct TuDien {
    string tiengAnh;
    string tiengViet;
};

struct Node {
    TuDien info;
    Node* next;
};

// Ham tao node moi
Node* createNode(string anh, string viet) {
    Node* newNode = new Node;
    newNode->info.tiengAnh = anh;
    newNode->info.tiengViet = viet;
    newNode->next = NULL; 
    return newNode;
}

// 2. Them mot tu vao cuoi danh sach
void insertLast(Node*& head, string anh, string viet) {
    Node* newNode = createNode(anh, viet);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 3. In danh sach
void printList(Node* head) {
    if (head == NULL) {
        cout << "Danh sach trong." << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->info.tiengAnh << ": " << temp->info.tiengViet << endl;
        temp = temp->next;
    }
}

// 4. Tim mot tu x
int findWord(Node* head, string x) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->info.tiengAnh == x) return 1;
        temp = temp->next;
    }
    return 0;
}

// 5. Hien thi den tu "hello"
void printToHello(Node* head) {
    Node* temp = head;
    bool found = false;
    while (temp != NULL) {
        cout << temp->info.tiengAnh << ": " << temp->info.tiengViet << endl;
        if (temp->info.tiengAnh == "hello") {
            found = true;
            break;
        }
        temp = temp->next;
    }
    if (!found && head != NULL) cout << "(Khong tim thay tu hello trong danh sach)" << endl;
}

// 6. Xoa cac tu bat dau bang chu 'c'
void deleteCharC(Node*& head) {
    while (head != NULL && (head->info.tiengAnh[0] == 'c' || head->info.tiengAnh[0] == 'C')) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    if (head == NULL) return;

    Node* temp = head;
    while (temp->next != NULL) {
        if (temp->next->info.tiengAnh[0] == 'c' || temp->next->info.tiengAnh[0] == 'C') {
            Node* delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;
        } else {
            temp = temp->next;
        }
    }
}

// 7. Sap xep tang dan
void sortList(Node* head) {
    if (head == NULL) return;
    for (Node* i = head; i->next != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (i->info.tiengAnh > j->info.tiengAnh) {
                // Hoan doi thong tin giua 2 node
                TuDien tempInfo = i->info;
                i->info = j->info;
                j->info = tempInfo;
            }
        }
    }
}

// 8. Chuong trinh chinh
int main() {
    Node* list = NULL;
    string x;

    insertLast(list, "apple", "qua tao");
    insertLast(list, "cat", "con meo");
    insertLast(list, "banana", "qua chuoi");
    insertLast(list, "car", "xe hoi");
    insertLast(list, "hello", "xin chao");
    insertLast(list, "dog", "con cho");
    insertLast(list, "computer", "may tinh");
    insertLast(list, "egg", "qua trung");
    insertLast(list, "fan", "cai quat");
    insertLast(list, "girl", "co gai");

    cout << "--- Tu dien ban dau ---" << endl;
    printList(list);

    cout << "\nNhap tu tieng anh can tim: ";
    cin >> x;
    if (findWord(list, x)) cout << "Ket qua: Co trong tu dien." << endl;
    else cout << "Ket qua: 0" << endl;

    cout << "\n--- In tu dau den 'hello' ---" << endl;
    printToHello(list);

    cout << "\n--- Xoa tu bat dau bang 'c' va sap xep ---" << endl;
    deleteCharC(list);
    sortList(list);
    printList(list);

    return 0;
}
