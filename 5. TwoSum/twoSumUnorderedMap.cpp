#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> twoSumUsingVectorPairAndPointers(vector<int>& arr, int target) {
  vector<int> indices;
  unordered_map<int, int> indexMap;

  for(int i=0; i<arr.size(); i++) {
    /* Insert value and corresponding index into the unordered map */
    indexMap.insert(make_pair(arr[i], i));
  }

  for(auto& index:indexMap) {
    auto difference = target - index.first;
    auto targetIndex = indexMap.find(difference);

    if(targetIndex != indexMap.end()) {
      indices.push_back(index.second);
      indices.push_back(targetIndex->second);
      break;
    }
  }
  cout<<endl;

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