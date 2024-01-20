#include <iostream>
#include <vector>

class Solution {
public:
    void reverseString(std::vector<char>& s)
    {
        std::reverse(s.begin(),s.end());
    }
};

int main()
{
    std::cout << "Hello world!" << std::endl;
    Solution ques;
    std::vector<char> str;
    str.push_back('h');
    str.push_back('e');
    str.push_back('l');
    str.push_back('l');
    str.push_back('o');
    std::cout<<"The original str is : ";
    for(auto a:str) std::cout<<a;
    std::cout<<std::endl;
    ques.reverseString(str);
    std::cout<<"The reversed str is : ";
    for(auto a:str) std::cout<<a;
    std::cout<<std::endl;
    return 0;
}
