#include<iostream>
#include<iterator>
#include<algorithm>


int search_linear_iterative(int* arr, int size,int num){
    for(int i = 0; i<size; ++i){
        if(arr[i]==num)
        return i;
    }
    return -1;
}
int search_linear_recursive(int* arr,int start,int end,int num){
    if(start>=end)
    return -1;
    if(arr[start]==num)
    return start;
    return search_linear_recursive(arr,start+1,end,num);
}
int search_binary_iterative(int* arr, int start,int end,int num){
    int mid;
    while(start<=end){
        mid = (start+end)/2;
        if(arr[mid] == num)
            return mid;
        if(arr[mid]>num)
            end = mid-1;
        else if(arr[mid]<num)
            start = mid+1;  
    }
    return -1;
}
int search_binary_recursive(int* arr,int start,int end, int num){
    if(start>end)
        return -1;
    int mid = (start+end)/2;
    if(arr[mid]==num)
        return mid;
    if(arr[mid]>num){
        return search_binary_recursive(arr,start,end-1,num);
    }
    else if(arr[mid]<num){
        return search_binary_recursive(arr,start+1,end,num);
    }
    return -1;
}


int main(){
    int array[10] = {5,7,8,-1,2,9,11,45,-99,4};
    std::sort(std::begin(array),std::end(array));
    std::copy(std::begin(array),std::end(array), std::ostream_iterator<int>(std::cout,"  "));

    std::cout<<'\n'<<search_binary_recursive(array,0,10,4);

}
