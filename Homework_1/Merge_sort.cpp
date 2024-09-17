#include <iostream>
#include <thread>
#include <vector>
void merge_sort(int l, int r, std::vector<int>& vec);
void merge(int l, int mid, int r, std::vector<int>& vec);
int main() {
    std::vector<int> vec;
    int n;
    std::cin >> n;
    vec.resize(n);
    for(size_t i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }
    int l = 0;
    int r = n - 1;
    merge_sort(l, r, vec);
    for(size_t i = 0; i < n; ++i) {
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;
}

void merge_sort(int l, int r, std::vector<int>& vec) {
    if(l < r) {
        int mid = l + (r - l) / 2;
        std::thread left_thread(merge_sort, l, mid, std::ref(vec));
        std::thread right_thread(merge_sort, mid + 1, r, std::ref(vec));
        left_thread.join();
        right_thread.join();
        merge(l, mid, r, vec);
    }
}

void merge(int l, int mid, int r, std::vector<int>& vec) {
    int size_1 = mid - l + 1;
    int size_2 = r - mid;
    std::vector<int> vec_1;
    vec_1.resize(size_1);
    std::vector<int> vec_2;
    vec_2.resize(size_2);
    for(size_t i = 0; i < size_1; ++i) {
        vec_1[i] = vec[l + i];
    }
    for(size_t i = 0; i < size_2; ++i) {
        vec_2[i] = vec[mid + 1 + i];
    }
    size_t i = 0, j = 0, k = l; 
    while(i < size_1 && j < size_2) {
        if(vec_1[i] <= vec_2[j]) {
            vec[k] = vec_1[i];
            ++i;
        }
        else {
            vec[k] = vec_2[j];
            ++j;
        }
        ++k;
    }
    while(i < size_1) {
        vec[k] = vec_1[i];
        ++i;
        ++k;
    }
    while(j < size_2) {
        vec[k] = vec_2[j];
        ++j;
        ++k;
    }
}