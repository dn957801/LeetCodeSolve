#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> twoSumUsingVectorPairAndPointers(vector<int>& arr, int target) {
  vector<int> indices;
  vector<pair<int, int>> vecPair;
  for(int i=0; i<arr.size(); i++) {
    vecPair.push_back(make_pair(arr[i], i));
  }
  sort(vecPair.begin(), vecPair.end());
  auto ptr1 = vecPair.data();
  auto ptr2 = vecPair.data()+vecPair.size()-1;

  while(ptr1<ptr2) {
    int result = ptr1->first + ptr2->first;
    if(result == target) {
      indices.push_back(ptr1->second);
      indices.push_back(ptr2->second);
      break;
    }
    else if(result < target) {
      ptr1 = ptr1 + 1;
    }
    else {
      ptr2 = ptr2 - 1;
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
