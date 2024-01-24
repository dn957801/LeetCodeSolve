#include <iostream>
#include <vector>
using namespace std;

vector<int> calculateProduct (vector<int>& input) {
  int n = input.size();
  int product = 1;
  vector<int> answer(n,1);

  /* First calculate LHS product for each index */
  for(int i=0; i<n; i++) {
    answer[i] = product;
    product *= input[i];
  }

  /* Now calculate RHS product for each index from other end
     But, while updating the answer, make sure the multiply with
     product as that is how we calculate the final result
  */
  product = 1; //reinitialize product to 1 to recalculate
  for(int i=n-1; i>=0; i--) {
    answer[i] *= product;
    product *= input[i];
  }

  return answer;
}

int main() {

  vector<int> firstVector = {1,2,3,4};
  vector<int> secondVector = {-1,1,0,-3,3};
  vector<int> firstProduct;
  vector<int> secondProduct;

  firstProduct = calculateProduct(firstVector);
  cout<<"Product of 1st vector is : ";
  for(auto value:firstProduct) {
    cout<<value<<" ";
  }
  cout<<endl;

  secondProduct = calculateProduct(secondVector);
  cout<<"Product of 2nd vector is : ";
  for(auto value:secondProduct) {
    cout<<value<<" ";
  }
  cout<<endl;
  return 0;
}