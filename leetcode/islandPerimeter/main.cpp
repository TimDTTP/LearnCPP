
#include <iostream>
#include <unordered_set>
#include <vector>

std::vector<std::vector<int>> test() {
  std::vector<std::vector<int>> grid{
      {0, 1, 0, 0},
      {1, 1, 1, 0},
      {0, 1, 0, 0},
      {1, 1, 0, 0},
  };

  return grid;
}

std::vector<std::vector<int>> test1() {
  std::vector<std::vector<int>> grid{
    {1},
    {0},
  };

  return grid;
}

std::vector<std::vector<int>> test2() {
  std::vector<std::vector<int>> grid{
      {1, 1, 1, 1},
      {1, 0, 1, 1},
  };

  return grid;
}

std::vector<std::vector<int>> test3() {
  std::vector<std::vector<int>> grid{
    {0, 1, 0, 0},
    {1, 1, 1, 0},
    {0, 1, 0, 0},
    {1, 1, 0, 0},
  };

  return grid;
}

std::vector<std::vector<int>> test4() {
  std::vector<std::vector<int>> grid{
      {1, 0, 1},
      {1, 1, 1},
  };

  return grid;
}

class Solution {
public:
  int islandPerimeter(std::vector<std::vector<int>> &grid) {
    int perimeter{0};
    std::unordered_set<int> previous{};
    std::unordered_set<int> current{};

    for (int row{0}; row < grid.size(); ++row) {
      for (int col{0}; col < grid[0].size(); ++col) {
        if (grid[row][col] == 1) {
          // check if non-sequential
          if ((!current.empty()) && (current.find(col - 1) == current.end()))
            perimeter += 2;

          // if found in vector
          if (previous.find(col) != previous.end()) 
            perimeter -= 2;

          current.insert(col);
        }
      }
      
      if (current.size() != 0)
        perimeter += current.size() * 2 + 2;

      previous = current;
      current.clear();
    }

    return perimeter;
  }
};

int main() {
  Solution ans = Solution();

  std::vector<std::vector<int>> grid{test3()};

  std::cout << ans.islandPerimeter(grid) << '\n';

  return 0;
}
