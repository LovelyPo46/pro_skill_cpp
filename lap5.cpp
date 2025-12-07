#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    vector<long long> numbers(7); 
    
    for (int i = 0; i < 7; ++i) {
        if (!(cin >> numbers[i])) return;
    }

    sort(numbers.begin(), numbers.end());

    long long A = numbers[0];
    
    long long B = numbers[1];
    
    long long Sum_ABC = numbers[6];
    
    long long C = Sum_ABC - A - B;

    cout << A << " " << B << " " << C << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}