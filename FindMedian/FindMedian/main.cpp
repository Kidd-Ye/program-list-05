//
//  main.cpp
//  Findm
//
//  Created by kidd on 2018/9/8.
//  Copyright © 2018年 Kidd. All rights reserved.
//

#include <iostream>
int FindMedian(int a[], int b[], int length){
    int s_a = 0, e_a = length-1, m_a;
    int s_b = 0, e_b = length-1, m_b;
    
    while (s_a != e_a || s_b != e_b) {
        m_a = (s_a + e_a)/2;
        m_b = (s_b + e_b)/2;
        
        if (a[m_a] == b[m_b]) {
            return a[m_a];
        }
        
        if (a[m_a] < b[m_b]) {
            if ((s_a + e_a)%2 == 0) { //若元素个数为奇数
                s_a = m_a; // 舍弃A中间点以前的部分并保留中间点
                e_b = m_b; // 舍弃B中间点以后的部分并保留中间点
            }else{
                s_a = m_a + 1; // 舍弃A中间点以及中间点以前的部分
                e_b = m_b;
            }
        }else{
            if ((s_b + e_b)%2 == 0) { //若元素个数为奇数
                e_a = m_a; // 舍弃A中间点以后的部分并保留中间点
                s_b = m_b; // 舍弃B中间点以前的部分并保留中间点
            }else{
                e_a = m_a;
                s_b = m_b + 1; // 舍弃B中间点以及中间点以前的部分
            }
        }
    }
    return a[s_a] < b[s_b] ? a[s_a] : b[s_b];
}

int main(int argc, const char * argv[]) {
    
    int a[] = {1,3,5,7,8};
    int b[] = {2,4,6,10,11};
    
    printf("中位数是: %d\n", FindMedian(a, b, 5));
    return 0;
}
