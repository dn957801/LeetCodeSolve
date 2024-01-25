#include<iostream>
#include<vector>

using namespace std;

vector<int> twoSumUsingVectorPairAndPointers(vector<int>& arr, int target) {
  vector<int> indices;

  for(int i=0; i<arr.size(); i++) {
    for(int j = i+1; j<arr.size(); j++) {
      if(arr[i] + arr[j] == target) {
        /* we have two indices resulting in target sum */
        indices.push_back(i);
        indices.push_back(j);
        break;
      }
    }
  }
  return indices;
}

int main() {
  vector<int> v1 = {2,7,11,15};
  vector<int> v2 = {-1, 6, 2, -5, 3, 7, 9, 11, 15};
  int target1 = 9, target2 = 11;

  cout<<"For v1, the target indices are : ";
  vector<int> res1;
  res1 = twoSumUsingVectorPairAndPointers(v1, target1);
  for (auto r:res1) {
    cout<<r<<" ";
  }
  cout<<endl<<"For v2, the target indices are : ";
  vector<int> res2;
  res2 = twoSumUsingVectorPairAndPointers(v2, target2);
  for (auto r:res2) {
    cout<<r<<" ";
  }
  cout<<"\nThe End"<<endl;
  return 0;
}