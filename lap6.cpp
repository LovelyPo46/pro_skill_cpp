#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int M, N, K;
    cin >> M >> N >> K;
    vector<string> a(M);
    for (int i = 0; i < M; i++) cin >> a[i];

    for (int i = 0; i < M; i++) {
        string line = "";
        for (int j = 0; j < N; j++) {
            for (int r = 0; r < K; r++) line += a[i][j];
        }
        for (int r = 0; r < K; r++) cout << line << "\n";
    }
}
