#include <iostream>
using namespace std;

void Merg(int arr[],int begin, int end) {
 int i = begin;
 int mid = begin + (end - begin)/2;
 int j = mid + 1;
 int k = 0;
 int d[5];     // массив куда будем складывать элементы после слияния
 while (i<= mid && j<= end){
        if (arr[i] <= arr[j]){
            d[k] = arr[i]; i++;
        }
        else {
             d[k] = arr[j]; j++;
        }
        k++;
 }
 while (i<=mid){
        d[k] = arr[i];
        i++; k++;
 }
 while (j <= end){
        d[k] = arr[j];
        j++;k++;
 }
}
void MergSort (int * arr, int left, int right){
 int temp = 0;
 if (left < right )
     if (right - left == 1) {
        if (arr[left] > arr[right]){
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
      }
      else {
           MergSort(arr,left,left+(right - left)/2);
           MergSort(arr,left+(right- left)/2,right);
           Merg(arr,left,right);
      }
}
 void input(int *m,int &n){
cout << "Введите количество элементов массива ";
  cin >> n;
  for (int i = 0; i < n; i++){
       cout << "a[" << i << "]=";
       cin >> m[i];
  }
}
 void print(int*m,int n){
  for (int i = 0; i<n;i++){
      cout << m[i] << " ";
      cout << endl;
  }
 }
 int main() {
  int n, arr[5];
  input(arr,n);
  cout << " Исходный массив " << endl;
  print (arr,n);

  MergSort (arr,0,n-1);

  cout << " Отсортированный массив " << endl;
  print (arr,n);
}
