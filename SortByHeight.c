// Definition for arrays:
// typedef struct arr_##name {
//   int size;
//   type *arr;
// } arr_##name;
//
// arr_##name alloc_arr_##name(int len) {
//   arr_##name a = {len, len > 0 ? malloc(sizeof(type) * len) : NULL};
//   return a;
// }
//
//

int partition(arr_integer a,int low, int high){
     int left = low;
     int right = high;
     int tempValue=0;
     int *pivotValue;
     pivotValue=&(a.arr[high]);
     while(true){
          while(a.arr[left]==-1){
               left++;
          }
          while(a.arr[right]==-1){
               right--;
          }
          while(a.arr[left]<(*pivotValue)){
               left++;
          }
          while(a.arr[right]>(*pivotValue)){
               right--;
          }
          if(a.arr[left]>=(*pivotValue) && a.arr[right]<=(*pivotValue)){
               tempValue=a.arr[left];
               a.arr[left]=a.arr[right];
               a.arr[right]=tempValue;
               left++;
          }
          if(left>=right){
           break;    
          }
     }
     return high;
}
void quickSort(arr_integer a,int low, int high){
   int pivotIndex=0;
   if(low<high){
        pivotIndex= partition(a,low,high);
        quickSort(a,low,pivotIndex-1);
        quickSort(a,pivotIndex+1,high);
   }     
}

arr_integer sortByHeight(arr_integer a) {
     int arrayLength=a.size;
     quickSort(a,0,arrayLength-1);
     return a;
}
