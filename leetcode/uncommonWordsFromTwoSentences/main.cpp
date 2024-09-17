
#include <iostream>
#include <string>
#include <vector>

class TestCases {
public:
  struct Sample {
    std::string s1;
    std::string s2;
  };

  Sample testA() {
    Sample obj;
    obj.s1 = "this apple is sweet";
    obj.s2 = "this apple is sour";

    return obj;
  }

  Sample testB() {
    Sample obj;
    obj.s1 = "apple apple";
    obj.s2 = "banana";

    return obj;
  }
};

class Solution {
public:
  std::vector<std::string> uncommonFromSentences(std::string s1,
                                                 std::string s2) {
    std::vector<std::string> unique;

    return unique;
  }
};

int main() {
  TestCases testCur = TestCases();
  Solution solCur = Solution();

  TestCases::Sample input{testCur.testA()};
  std::vector<std::string> output{
      solCur.uncommonFromSentences(input.s1, input.s2)};

  return 0;
}
