#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

vector<vector<int>> threeSumToZero(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  int numSize = nums.size();
  vector<vector<int>> indices;
  int i = 0, ele = 0, targetSum = 0;
  for(i = 0; i<numSize - 2; i++){
    ele = nums[i];
    targetSum = -ele;
    int nextIndex = i+1;
    int lastIndex = numSize -1;
    while(nextIndex < lastIndex) {
      if((nums[nextIndex] + nums[lastIndex]) == targetSum) {
        indices.push_back({nums[i], nums[nextIndex], nums[lastIndex]});
        // Skip Duplicates
        while(nextIndex < lastIndex && nums[nextIndex] == nums[nextIndex+1]) {
            nextIndex++;
        }
        while(nextIndex < lastIndex && nums[lastIndex] == nums[lastIndex-1]) {
            lastIndex--;
        }
        nextIndex++;
        lastIndex--;
      }
      else if((nums[nextIndex] + nums[lastIndex]) < targetSum) {
        nextIndex++;
      }
      else {
        lastIndex--;
      }
    }
    while((i+1 < numSize) && nums[i] == nums[i+1]) i++;
  }
  return indices;
}

int main() {
  vector<int> v1 = {-1,0,1,2,-1,-4};
  vector<int> v2 = {0,0,0,0};

  cout<<"For v1, the target indices sums up to zero are : ";
  vector<vector<int>> res1;
  res1 = threeSumToZero(v1);
  for (auto r:res1) {
    for(auto v:r) {
      cout<<v<<" ";
    }
    cout<<endl;
  }
  cout<<endl<<"For v2, the target indices sums up to zero are : ";
  vector<vector<int>> res2;
  res2 = threeSumToZero(v2);
  for (auto r:res2) {
    for(auto v:r) {
      cout<<v<<" ";
    }
    cout<<endl;
  }
  cout<<"\nThe End"<<endl;
  return 0;
}
