//radix
#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>

using namespace std;
template<typename U>
void countSort(int rank, U& cont) {
    U cont2 = cont;
    int arr[10]{};
    auto start_ = cont.begin();
    auto end = cont.end();
    while (start_ != end) {
        ++arr[(*start_ / rank) % 10];
        ++start_;
    }
    for (int i = 1; i < 10; i++)
    {
        arr[i] += arr[i - 1];
    }
    start_ = cont.end();
    --start_;
    auto start = cont.begin();
    
    while (start_ != start) {
        cont2[--arr[(*start_ / rank) % 10]] = *start_;
        --start_;
    }
    cont2[arr[(*start_ / rank) % 10]--] = *start_;
    cont = cont2;
}

template<typename T,typename U>
T GetMax(U& cont) {
    T max = *(cont.begin());
    auto tmp = cont.begin();
    ++tmp;
    while (tmp != cont.end()) {
        if (*tmp > max) {
            max = *tmp;
        }
        ++tmp;
    }
    return max;

}
template<typename T,typename U>
void radix_sort(U& cont) {
    int a = GetMax<T>(cont);
    for (int i = 1; (a/i)>0; i *= 10) {
        countSort(i,cont);
    }
}

//quick
template<typename T,typename U>
int quick_pivot(U& start,U& end){
    auto ind = start;
    int i = 0;
    while(start!=end){
        if(*start<*end){
            ++i;
            T tmp = *ind;
            *ind = *start;
            *start = tmp;
            ++ind;
        }
        ++start;
    }
    T tmp = *ind;
    *ind = *end;
    *end = tmp;

    return i;
}

template<typename U,typename T>
void quick_sort(int start,int end,T& container){
    if(start>=end)return;
    auto start_ = container.begin();
    auto end_ = container.begin();
    std::advance(start_,start);
    std::advance(end_,end-1);
    int mid = quick_pivot<int>(start_,end_) + start;
    quick_sort<int>(start,mid-1,container);
    quick_sort<int>(mid+1,end,container);
}

//merge
template<typename U,typename T>
void merge(T start, T mid, T end,int start_,int mid_,int end_){
    const int arr1_s = mid_-start_+1;
    const int arr2_s = end_-mid_;
    U* arr1 = new U[arr1_s];
    U* arr2 = new U[arr2_s];
    auto tmp = start;
    int i = 0;
    ++mid;
    ++end;
    while(tmp!=mid){
        arr1[i] = *tmp;
        ++tmp;
        ++i;
    }
    i = 0;
    while(tmp!=end){
        arr2[i]=*tmp;
        ++tmp;
        ++i;
    }
    int j = 0;
    i = 0;
    tmp = start;
    while(i!=arr1_s && j!=arr2_s){
        if(arr1[i]<=arr2[j]){
            *tmp = arr1[i];
            ++i;
        }else{
            *tmp = arr2[j];
            ++j;
        }
        ++tmp;
    }
    while(i!=arr1_s){
        *tmp = arr1[i];
        ++tmp;
        ++i;
    }
    while(j!=arr2_s){
        *tmp = arr2[j];
        ++tmp;
        ++j;
    }
}

template<typename U,typename T>
void merge_sort(int start, int end, T&cont){
    if(start>=end)return;
    int mid = (start+end)/2;
    merge_sort<int>(start,mid,cont);
    merge_sort<int>(mid+1,end,cont);

    auto start_ = cont.begin();
    std::advance(start_,start);
    auto end_ = cont.begin();
    std::advance(end_,end);
    auto mid_ = cont.begin();
    std::advance(mid_,mid);
    
    merge<int>(start_,mid_,end_,start,mid,end);
}
