#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n=0;
  cin>>n;
  int* arr = new int[n];
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }

  int min = 100000;
  int t = 0;
  for(int i=1; i<=100; i++) {
    int total = 0;
    for(int j=0; j<n; j++){
      int diff = abs(arr[j]-i);
      diff = (diff>1)?diff-1:0;
      total+=diff;
    }
    if(total<min){
      min = total;
      t = i;
    }
  }
  cout<<t<<" "<<min;
  return 0;
}