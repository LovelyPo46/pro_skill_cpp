#include <iostream>
using namespace std;

int main(){
    freopen("billboard.in","r",stdin);
    freopen("billboard.out","w",stdout);
    
    int ax1, ay1, ax2, ay2;
    int bx1, by1, bx2, by2;
    cin >> ax1 >> ay1 >> ax2 >> ay2;
    cin >> bx1 >> by1 >> bx2 >> by2;

    int totalW = ax2 - ax1;
    int totalH = ay2 - ay1;
    int area = totalW * totalH;

    int ox1 = max(ax1, bx1);
    int oy1 = max(ay1, by1);
    int ox2 = min(ax2, bx2);
    int oy2 = min(ay2, by2);

    if (ox1 < ox2 && oy1 < oy2) {
        int interW = ox2 - ox1;
        int interH = oy2 - oy1;

        if (interW == totalW && (oy1 == ay1 || oy2 == ay2)) {
            area -= interH * interW;
        }
        else if (interH == totalH && (ox1 == ax1 || ox2 == ax2)) {
            area -= interH * interW;
        }
    }

    cout << area;
    return 0;
}