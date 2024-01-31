#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> fourSumToZero(vector<int>& nums, int target) {
  int numSize = nums.size();
    vector<vector<int>> retValues;
    if(numSize < 4) {
        return retValues;
    }
    sort(nums.begin(), nums.end());
    for(int i=0; i<numSize; i++) {
        if((i>0) && nums[i] == nums[i-1]) {
        continue;
        }
        for(int j = i+1; j<numSize; j++) {
            if(j>(i+1) && nums[j] == nums[j-1]) {
                continue;
            }
            int nextIndex = j+1;
            int lastIndex = numSize - 1;
            while(nextIndex < lastIndex) {
                long long sum = nums[i] + nums[j];
                sum += nums[nextIndex] + nums[lastIndex];
                if(sum == target) {
                    retValues.push_back({nums[i], nums[j], nums[nextIndex], nums[lastIndex]});
                    nextIndex++;
                    lastIndex--;
                    while(nextIndex < lastIndex && nums[nextIndex] == nums[nextIndex-1]) {
                        nextIndex++;
                    }
                    while(nextIndex < lastIndex && nums[lastIndex] == nums[lastIndex+1]) {
                        lastIndex--;
                    }
                }
                else if(sum < target) {
                    nextIndex++;
                }
                else {
                    lastIndex--;
                }
            }
        }
    }
    return retValues;
}


int main() {
  vector<int> v1 = {1,0,-1,0,-2,2};
  vector<int> v2 = {2,2,2,2,2};
  vector<int> v3 = {-3,-1,0,2,4,5};

  cout<<"For v1, the target indices sums up to zero are : ";
  vector<vector<int>> res1;
  res1 = fourSumToZero(v1, 0);
  for (auto r:res1) {
    for(auto v:r) {
      cout<<v<<" ";
    }
    cout<<endl;
  }
  cout<<endl<<"For v2, the target indices sums up to zero are : ";
  vector<vector<int>> res2;
  res2 = fourSumToZero(v2, 8);
  for (auto r:res2) {
    for(auto v:r) {
      cout<<v<<" ";
    }
    cout<<endl;
  }

  cout<<endl<<"For v3, the target indices sums up to zero are : ";
  vector<vector<int>> res3;
  res3 = fourSumToZero(v3, 0);
  for (auto r:res3) {
    for(auto v:r) {
      cout<<v<<" ";
    }
    cout<<endl;
  }
  cout<<"\nThe End"<<endl;
  return 0;
}
