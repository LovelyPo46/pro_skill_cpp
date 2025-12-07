#include <iostream>
using namespace std;

int main() {
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    int N, K;
    cin >> N >> K;
    int used = 0;

    for (int i = 0; i < N; i++) {
        string w;
        cin >> w;
        if (used == 0) {
            cout << w;
            used = w.size();
        } else if (used + w.size() <= K) {
            cout << " " << w;
            used += w.size();
        } else {
            cout << "\n" << w;
            used = w.size();
        }
    }
}