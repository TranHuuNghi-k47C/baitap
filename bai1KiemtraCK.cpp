#include<iostream>
#include<string>
using namespace std;
struct Sach{
    string tenSach;
    int soTrang;
};
struct Node{
	Sach data;
	Node* left;
	Node* right;
};
typedef Node* Tree;
void ThemSach(Node *&root, Sach data) {
if (root == NULL) {
  root = new Node;
  root->data=data;
  root->left = root->right = NULL;
} else if (data.soTrang < root->data.soTrang) {
    ThemSach(root->left, data);
} else if (data.soTrang > root->data.soTrang) {
     ThemSach(root->right, data);
  }
}
void LietKe(Node *root){
	if(root==NULL) return;
	LietKe(root->left);
	if(root->data.soTrang<200 ||root->data.soTrang>400)
	cout<< root->data.tenSach<< root->data.soTrang<< endl;
	LietKe(root->right);
}
bool tra(Node* root, string x){
	if(root==NULL) return false;
	if(root->data.tenSach==x) return true;
	return tra(root->left,x) || tra (root->right,x);
}

int main() {
    Node* root = NULL;

    // 1. T?o d? li?u m?u và thêm vào cây
    Sach s1 = {"Lap trinh C++", 150};
    Sach s2 = {"Cau truc du lieu", 350};
    Sach s3 = {"Giai thuat nang cao", 500};
    Sach s4 = {"Toan roi rac", 180};

    ThemSach(root, s1);
    ThemSach(root, s2);
    ThemSach(root, s3);
    ThemSach(root, s4);

    // 2. Ki?m tra hàm Li?t kê (K?t qu? mong d?i: hi?n th? các sách 150, 180, 500 trang)
    cout << "--- DANH SACH SACH (<200 hoac >400 TRANG) ---" << endl;
    LietKe(root);
    cout << endl;

    // 3. Ki?m tra hàm tra c?u theo tên
    string tenCanTim = "Lap trinh C++";
    cout << "--- KET QUA TIM KIEM ---" << endl;
    if (tra(root, tenCanTim)) {
        cout << "Tim thay sach: " << tenCanTim << endl;
    } else {
        cout << "Khong tim thay sach: " << tenCanTim << endl;
    }

    return 0;
}
