#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int M;
        cin >> M;

        int x1, y1, x2, y2;
 
        int left_max = -100000;
        int bottom_max = -100000;
        int right_min = 100000;
        int top_min = 100000;

        for (int i = 0; i < M; i++) {
            cin >> x1 >> y1 >> x2 >> y2;
            left_max = max(left_max, x1);
            bottom_max = max(bottom_max, y1);
            right_min = min(right_min, x2);
            top_min = min(top_min, y2);
        }

        int width = right_min - left_max;
        int height = top_min - bottom_max;
        int area = 0;
        if (width > 0 && height > 0) {
            area = width * height;
        }

        cout << "Case " << t << ": " << area << endl;
    }
    return 0;
}