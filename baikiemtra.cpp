#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Khai bao cau truc du lieu
typedef struct TuDien {
    char tiengAnh[50];
    char tiengViet[50];
} DATA;

struct Node {
    DATA info;
    struct Node* next;
};

typedef struct Node NODE;

// Ham tao mot node moi
NODE* createNode(char anh[], char viet[]) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    strcpy(newNode->info.tiengAnh, anh);
    strcpy(newNode->info.tiengViet, viet);
    newNode->next = NULL;
    return newNode;
}

// 2. Them mot tu vao cuoi danh sach
void insertLast(NODE** head, char anh[], char viet[]) {
    NODE* newNode = createNode(anh, viet);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    NODE* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 3. In danh sach
void printList(NODE* head) {
    if (head == NULL) {
        printf("Danh sach trong.\n");
        return;
    }
    NODE* temp = head;
    while (temp != NULL) {
        printf("%s: %s\n", temp->info.tiengAnh, temp->info.tiengViet);
        temp = temp->next;
    }
}

// 4. Tim mot tu x
int findWord(NODE* head, char x[]) {
    NODE* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->info.tiengAnh, x) == 0) return 1;
        temp = temp->next;
    }
    return 0;
}

// 5. Hien thi den tu "hello"
void printToHello(NODE* head) {
    NODE* temp = head;
    while (temp != NULL) {
        printf("%s: %s\n", temp->info.tiengAnh, temp->info.tiengViet);
        if (strcmp(temp->info.tiengAnh, "hello") == 0) break;
        temp = temp->next;
    }
}

// 6. Xoa cac tu bat dau bang chu 'c'
void deleteCharC(NODE** head) {
    NODE *temp = *head, *prev = NULL;
    while (temp != NULL) {
        if (temp->info.tiengAnh[0] == 'c' || temp->info.tiengAnh[0] == 'C') {
            if (prev == NULL) {
                *head = temp->next;
                free(temp);
                temp = *head;
            } else {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

// 7. Sap xep tang dan (Interchange Sort)
void sortList(NODE* head) {
    for (NODE* i = head; i != NULL && i->next != NULL; i = i->next) {
        for (NODE* j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->info.tiengAnh, j->info.tiengAnh) > 0) {
                DATA temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }
}

// 8. Chuong trinh chinh
int main() {
    NODE* list = NULL;
    char x[50];

    // Tao 10 tu
    insertLast(&list, "apple", "qua tao");
    insertLast(&list, "cat", "con meo");
    insertLast(&list, "banana", "qua chuoi");
    insertLast(&list, "car", "xe hoi");
    insertLast(&list, "hello", "xin chao");
    insertLast(&list, "dog", "con cho");
    insertLast(&list, "computer", "may tinh");
    insertLast(&list, "egg", "qua trung");
    insertLast(&list, "fan", "cai quat");
    insertLast(&list, "girl", "co gai");

    printf("--- Tu dien vua tao ---\n");
    printList(list);

    printf("\nNhap tu can tim: ");
    scanf("%s", x);
    if (findWord(list, x)) printf("Co tu '%s' trong tu dien.\n", x);
    else printf("0 (Khong tim thay)\n");

    printf("\n--- Tu dau den 'hello' ---\n");
    printToHello(list);

    printf("\n--- Xoa tu bat dau bang 'c' va sap xep ---\n");
    deleteCharC(&list);
    sortList(list);
    printList(list);

    return 0;
}
