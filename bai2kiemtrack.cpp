#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<vector<int> > Graph;

void inTramKetNoiTrucTiep(const Graph& G, int k) {
    if (k < 0 || k >= (int)G.size()) {
        cout << "Tram " << k << " khong hop le!" << endl;
        return;
    }
    
    int soLuong = G[k].size();
    cout << "Tram " << k << " ket noi truc tiep voi " << soLuong << " tram." << endl;
    
    if (soLuong > 0) {
        cout << "Do la nhung tram: ";
        for (int i = 0; i < soLuong; i++) {
            cout << G[k][i] << (i == soLuong - 1 ? "" : ", ");
        }
        cout << endl;
    }
}

void kiemTraKetNoiVaTrungGian(const Graph& G, int x, int y) {
    int n = G.size();
    vector<int> khoangCach(n, -1);
    vector<int> truocDo(n, -1);
    queue<int> q;

    q.push(x);
    khoangCach[x] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == y) break;

        for (int i = 0; i < (int)G[u].size(); i++) {
            int v = G[u][i];
            if (khoangCach[v] == -1) {
                khoangCach[v] = khoangCach[u] + 1;
                truocDo[v] = u;
                q.push(v);
            }
        }
    }

    if (khoangCach[y] == -1) {
        cout << "Khong co tuyen duong nao ket noi tram " << x << " va tram " << y << "." << endl;
    } else if (khoangCach[y] == 1) {
        cout << "Tram " << x << " ket noi TRUC TIEP voi tram " << y << "." << endl;
    } else {
        vector<int> duongDi;
        int hienTai = truocDo[y];
        while (hienTai != x) {
            duongDi.push_back(hienTai);
            hienTai = truocDo[hienTai];
        }
        
        reverse(duongDi.begin(), duongDi.end());

        cout << "Tram " << x << " ket noi voi tram " << y << " qua it nhat " << duongDi.size() << " tram trung gian." << endl;
        cout << "Do la nhung tram: ";
        for (size_t i = 0; i < duongDi.size(); i++) {
            cout << duongDi[i] << (i == duongDi.size() - 1 ? "" : " -> ");
        }
        cout << endl;
    }
}

void demVaInCumKetNoi(const Graph& G) {
    int n = G.size();
    vector<bool> daTham(n, false);
    int soCum = 0;

    for (int i = 0; i < n; i++) {
        if (!daTham[i]) {
            soCum++;
            cout << "- Cum ket noi thu " << soCum << " gom cac tram: ";
            
            queue<int> q;
            q.push(i);
            daTham[i] = true;
            vector<int> cacTramTrongCum;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                cacTramTrongCum.push_back(u);

                for (int k = 0; k < (int)G[u].size(); k++) {
                    int v = G[u][k];
                    if (!daTham[v]) {
                        daTham[v] = true;
                        q.push(v);
                    }
                }
            }

            sort(cacTramTrongCum.begin(), cacTramTrongCum.end());
            for (size_t j = 0; j < cacTramTrongCum.size(); j++) {
                cout << cacTramTrongCum[j] << (j == cacTramTrongCum.size() - 1 ? "" : ", ");
            }
            cout << endl;
        }
    }
    cout << "=> Tong cong khu rung co " << soCum << " cum ket noi." << endl;
}

int main() {
    int n = 7;
    Graph G(n);

    // Khoi tao mang theo kieu cu de tuong thich ca voi C++98
    int arr0[] = {1, 3}; G[0].assign(arr0, arr0 + 2);
    int arr1[] = {0, 2, 4}; G[1].assign(arr1, arr1 + 3);
    int arr2[] = {1}; G[2].assign(arr2, arr2 + 1);
    int arr3[] = {0, 5}; G[3].assign(arr3, arr3 + 2);
    int arr4[] = {1, 6}; G[4].assign(arr4, arr4 + 2);
    int arr5[] = {3, 6}; G[5].assign(arr5, arr5 + 2);
    int arr6[] = {4, 5}; G[6].assign(arr6, arr6 + 2);

    cout << "========== KET QUA THUC THI ==========" << endl;
    
    cout << "\n1. Thong tin ket noi tram 2:" << endl;
    inTramKetNoiTrucTiep(G, 2);

    cout << "\n2. Kiem tra ket noi giua tram 1 va tram 5:" << endl;
    kiemTraKetNoiVaTrungGian(G, 1, 5);

    cout << "\n3. Thong tin cac cum ket noi trong khu rung:" << endl;
    demVaInCumKetNoi(G);
    
    cout << "======================================" << endl;

    return 0;
}
