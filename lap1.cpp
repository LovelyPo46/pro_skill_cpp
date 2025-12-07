#include <iostream>
#include <algorithm>
using namespace std;

int overlap(int ax1, int ay1, int ax2, int ay2,
            int bx1, int by1, int bx2, int by2) {
    int x1 = max(ax1, bx1);
    int y1 = max(ay1, by1);
    int x2 = min(ax2, bx2);
    int y2 = min(ay2, by2);
    if (x1 >= x2 || y1 >= y2) return 0;
    return (x2 - x1) * (y2 - y1);
}

int area(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (y2 - y1);
}

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int b1x1, b1y1, b1x2, b1y2;
    int b2x1, b2y1, b2x2, b2y2;
    int tx1, ty1, tx2, ty2;

    cin >> b1x1 >> b1y1 >> b1x2 >> b1y2;
    cin >> b2x1 >> b2y1 >> b2x2 >> b2y2;
    cin >> tx1 >> ty1 >> tx2 >> ty2;

    int visible1 = area(b1x1, b1y1, b1x2, b1y2)
                 - overlap(b1x1, b1y1, b1x2, b1y2,
                           tx1, ty1, tx2, ty2);

    int visible2 = area(b2x1, b2y1, b2x2, b2y2)
                 - overlap(b2x1, b2y1, b2x2, b2y2,
                           tx1, ty1, tx2, ty2);

    cout << visible1 + visible2 << "\n";
    return 0;
}