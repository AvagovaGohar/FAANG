#include<iostream>
#include<string>
using namespace std;

int jump_search(int* arr, int size,int num) {
    int jump_size = 3;
    int j = 0;
    bool t = true;
    for (int i = 0;t ; ) {
        if (i + jump_size > size - 1) {
            t = false;
            i = j;
            j = size - 1;
        }
        else {
            i = j;
            j = i + jump_size;
        }
            
        if (arr[j] > num) {
            for (int k = i; k <= j; ++k) {
                if (arr[k] == num)
                    return num;
            }
            break;
        }
            
    }
    return -1;
}
int interpolation_search(int* arr, int size, int num) {
    int low = 0;
    while (low<size) {
        int pos = low + (num - arr[low]) * (size - low) / (arr[size] - arr[low]);
        if (arr[pos] == num)
            return pos;
        else if (arr[pos]>num) {
            size = pos - 1;
        }
        else {
            low = pos + 1;
        }
    }
    return -1;
}
