#include <iostream>
using namespace std;

bool linearSearch(int a[],int noOfElements,int numberToSearch) {
    for(int i = 0;i < noOfElements;i++){
      if(numberToSearch == a[i]){
        return true;
      }
    }
    return false;
}
int main(int argc, char *argv[]) {
  int n;
  cout << "Enter the number of elements in which you wanted to search :: " ;
  cin >> n;
  int a[n];
  cout << "Enter the elements :: " ;
  for(int i = 0;i < n;i++){
    cin >> a[i];
  }
  int k;
  cout << "Enter the element to be searched :: " ;
  cin >> k;
  bool linSer = linearSearch(a,n,k);
  cout << '\n';
  if(linSer){
    cout << "The given element is inside the given set of elements" << "\n";
  }
  else{
    cout << "The given element is not inside the given set of elements" << "\n";
  }
  return 0;
}
