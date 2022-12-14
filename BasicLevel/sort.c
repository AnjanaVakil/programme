#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
// void swap2(int &a,int &b)
// {
//     int temp=a;
//     a=b;
//     b=temp;
// }
void bubble_sort(int arr[],int len)
{
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                // swap2(&arr[j],&arr[j+1]);
            }
        }
    }
}
void selection_sort(int arr[],int len)
{
    for(int i=0;i<len-1;i++){
        int min=i;
        for(int j=i+1;j<len;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            // int temp=arr[min];
            // arr[min]=arr[i];
            // arr[i]=temp;
            swap(&arr[min],&arr[i]);
        }
    }
}
void insertion_sort(int *arr,int len)
{
    for(int i=1;i<len;i++){
        int temp=arr[i];
        int j;
        for(j=i;j>0 && arr[j-1]>temp;j--){
            arr[j]=arr[j-1];
        }
        arr[j]=temp;
    }
}
void shell_sort(int *arr,int len)
{
    for(int gap=len>>1;gap>0;gap=gap>>1){
        for(int i=gap;i<len;i++){
            int temp=arr[i];
            int j;
            for(j=i-gap;j>=0&&arr[j]>temp;j-=gap){
                arr[j+gap]=arr[j];
            }
            arr[j+gap]=temp;
        }
    }
}

int min(int x,int y)
{
    return x<y ? x : y;
}
void merge_sort(int arr[], int len) {
    int* a = arr;
    int* b = (int*) malloc(len * sizeof(int));
    int seg, start;
    for (seg = 1; seg < len; seg += seg) {
        for (start = 0; start < len; start += seg + seg) {
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        int* temp = a;
        a = b;
        b = temp;
    }
    if (a != arr) {
        int i;
        for (i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    free(b);
}
void merge_sort_recursive(int arr[], int reg[], int start, int end) {
    if (start >= end)
        return;
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    merge_sort_recursive(arr, reg, start1, end1);
    merge_sort_recursive(arr, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}
void merge_sort2(int arr[], const int len) {
    int reg[len];
    merge_sort_recursive(arr, reg, 0, len - 1);
}

typedef struct _Range {
    int start, end;
} Range;
Range new_Range(int s, int e) {
    Range r;
    r.start = s;
    r.end = e;
    return r;
}
void quick_sort(int arr[], const int len) {
    if (len <= 0)
        return; // ??????len?????????????????????????????????Segment Fault???
    // r[]????????????,p?????????,r[p++]???push,r[--p]???pop???????????????
    Range r[len];
    int p = 0;
    r[p++] = new_Range(0, len - 1);
    while (p) {
        Range range = r[--p];
        if (range.start >= range.end)
            continue;
        int mid = arr[(range.start + range.end) / 2]; // ???????????????????????????
        int left = range.start, right = range.end;
        do
        {
            while (arr[left] < mid) ++left;   // ???????????????????????????????????????
            while (arr[right] > mid) --right; //???????????????????????????????????????
 
            if (left <= right)
            {
                swap(&arr[left],&arr[right]);
                left++;right--;               // ?????????????????????
            }
        } while (left <= right);
 
        if (range.start < right) r[p++] = new_Range(range.start, right);
        if (range.end > left) r[p++] = new_Range(left, range.end);
    }
}
void quick_sort_recursive(int arr[], int start, int end) {
    if (start >= end)
        return;
    int mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right)
            left++;
        while (arr[right] >= mid && left < right)
            right--;
        swap(&arr[left], &arr[right]);
    }
    if (arr[left] >= arr[end])
        swap(&arr[left], &arr[end]);
    else
        left++;
    if (left)
        quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}
void quick_sort2(int arr[], int len) {
    quick_sort_recursive(arr, 0, len - 1);
}
int main()
{
    int arr[]={ 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len=(int)sizeof(arr)/sizeof(*arr);

    printf("original arr:");
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }

    // bubble_sort(arr,len);
    // printf("\nbubble_sort arr:");
    // for(int i=0;i<len;i++){
    //     printf("%d ",arr[i]);
    // }

    // selection_sort(arr,len);
    // printf("\nselection_sort arr:");
    // for(int i=0;i<len;i++){
    //     printf("%d ",arr[i]);
    // } 

    // insertion_sort(arr,len);
    // printf("\ninsertion_sort arr:");
    // for(int i=0;i<len;i++){
    //     printf("%d ",arr[i]);
    // }

    // shell_sort(arr,len);
    // printf("\nshell_sort arr:");
    // for(int i=0;i<len;i++){
    //     printf("%d ",arr[i]);
    // }

    // merge_sort(arr,len);
    // // merge_sort2(arr,len);
    // printf("\nmerge_sort arr:");
    // for(int i=0;i<len;i++){
    //     printf("%d ",arr[i]);
    // }

    // quick_sort(arr,len);
    quick_sort2(arr,len);
    printf("\nquick_sort arr:");
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}