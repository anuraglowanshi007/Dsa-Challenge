 #include<iostream>
 using namespace std;

 void Reverse(int arr[],int start,int end){
      while(start<end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
      }
 }

 void Rotateleft(int arr[], int n , int k){
      //Reverse for only n-k element 
      Reverse(arr,0,n-k-1);

      // Reverse for only n-k to n-1 element 
      Reverse(arr,n-k,n-1);

      //Reverse for whole array element
      Reverse(arr,0,n-1);

 }

 int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int n = 7;
  int k = 3;
 Rotateleft(arr, n, k);
  cout << "After Rotating the k elements to right ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}