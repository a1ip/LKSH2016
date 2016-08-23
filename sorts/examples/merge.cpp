#include <iostream>
#include <cstdio>

void merge_help(int *a, int la, int *b, int lb, int *t) {
    int ia = 0;
    int ib = 0; 
    int it = 0;
    int *l;
    int r = la + lb;
    
    while (ia < la && ib < lb) {
        if (a[ia] < b[ib]) {
            t[it++] = a[ia++];
            l = b + ib;
            --r;
        } else {
            t[it++] = b[ib++];
            l = a + ia;
            --r;
        }
    }
    
    for (int i = 0; i < r; ++i, ++it) {
        t[it] = l[i];
    }

    for (int i = 0; i < la + lb;  ++i) {
        a[i] = t[i];
    }
}

void merge_sort_impl(int *a, int len, int *t) {
    if (len == 1) {
        return;
    } else if (len == 2) {
        if (a[0] > a[1]) {
           std::swap(a[0], a[1]);
        }
    } else {
        merge_sort_impl(a, len / 2, t);
        merge_sort_impl(a + len / 2, len - len / 2, t + len / 2);
    	merge_help(a, len / 2, a + len / 2, len - len / 2, t);
    }
}


void merge_sort(int *a, int len) {
    int *t = new int[len];
    merge_sort_impl(a, len, t);
    delete[] t;
}


int main() {
    int a[5] = { 5, 3, 2, 4, 1 };

    for (int i = 0; i < 5; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';

    merge_sort(a, 5);

    for (int i = 0; i < 5; ++i) {
        std::cout << a[i] << ' ';
    }

    return 0;
}

