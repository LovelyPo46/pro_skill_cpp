#include <stdio.h>
#include <stdlib.h>

// ฟังก์ชันสำหรับหาค่าสูงสุด (Max) และต่ำสุด (Min) เนื่องจาก <algorithm> ไม่มีใน C
long long max_val(long long a, long long b) {
    return (a > b) ? a : b;
}

long long min_val(long long a, long long b) {
    return (a < b) ? a : b;
}

// ฟังก์ชันหลักในการแก้ปัญหา
void solve() {
    // Lawnmower Billboard (L) coordinates
    long long x_L1, y_L1, x_L2, y_L2;
    // Cow Feed Billboard (C) coordinates
    long long x_C1, y_C1, x_C2, y_C2;

    // 1. อ่านค่าพิกัดป้าย Lawnmower
    if (scanf("%lld %lld %lld %lld", &x_L1, &y_L1, &x_L2, &y_L2) != 4) return;
    // 2. อ่านค่าพิกัดป้าย Cow Feed
    if (scanf("%lld %lld %lld %lld", &x_C1, &y_C1, &x_C2, &y_C2) != 4) return;

    // คำนวณขนาดของป้าย Lawnmower (L)
    long long W_L = x_L2 - x_L1; // ความกว้าง
    long long H_L = y_L2 - y_L1; // ความสูง
    long long total_area_L = W_L * H_L; // พื้นที่ทั้งหมดของ L

    // 3. คำนวณการทับซ้อน (Intersection)
    
    // X-overlap interval
    long long x_overlap_start = max_val(x_L1, x_C1);
    long long x_overlap_end = min_val(x_L2, x_C2);
    
    // Y-overlap interval
    long long y_overlap_start = max_val(y_L1, y_C1);
    long long y_overlap_end = min_val(y_L2, y_C2);

    // ความกว้างและความสูงของการทับซ้อน (Intersection Dimensions)
    long long W_I = max_val(0, x_overlap_end - x_overlap_start);
    long long H_I = max_val(0, y_overlap_end - y_overlap_start);
    
    // 4. คำนวณพื้นที่ของผ้าใบ (Tarp Area) ขั้นต่ำ
    
    long long reduction_area = 0;

    // Case 1: ป้าย C ครอบคลุมความกว้างทั้งหมดของป้าย L (W_I == W_L)
    // หมายความว่า ป้าย L ถูกบังเต็มความกว้าง แต่ไม่ใช่ความสูง
    if (W_I == W_L) {
        // สามารถลดขนาดพื้นที่ที่ต้องใช้ผ้าใบลงตามความสูงที่บัง (H_I)
        reduction_area = W_L * H_I;
    } 
    // Case 2: ป้าย C ครอบคลุมความสูงทั้งหมดของป้าย L (H_I == H_L)
    // หมายความว่า ป้าย L ถูกบังเต็มความสูง แต่ไม่ใช่ความกว้าง
    else if (H_I == H_L) {
        // สามารถลดขนาดพื้นที่ที่ต้องใช้ผ้าใบลงตามความกว้างที่บัง (W_I)
        reduction_area = W_I * H_L;
    }
    // Case 3: การบังเป็นการบังส่วนกลางหรือมุมเล็กๆ (ไม่เต็มด้านใดด้านหนึ่ง)
    // ต้องใช้ผ้าใบที่มีขนาดเท่ากับพื้นที่ทั้งหมดของป้าย L 
    else {
        reduction_area = 0; 
    }

    // พื้นที่ผ้าใบขั้นต่ำ = พื้นที่ Lawnmower ทั้งหมด - พื้นที่ที่ลดได้
    long long min_tarp_area = total_area_L - reduction_area;

    // 5. แสดงผลลัพธ์
    printf("%lld\n", min_tarp_area);
}

int main() {
    // เนื่องจากโจทย์ไม่มีข้อกำหนดเรื่องการอ่านไฟล์ (file I/O) ที่ซับซ้อน
    // จึงสามารถเรียกใช้ solve() โดยตรงได้เลย
    solve();

    return 0;
}