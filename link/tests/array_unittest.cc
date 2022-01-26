#include <iostream>

void print(int nums[][4], int row) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < 4; j++) {
      std::cout << nums[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void print(int **nums, int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      std::cout << nums[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

int main(int argc, char **argv) {
  int nums[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  print(nums, 3);

  nums[2][1]         = 22;
  (*(nums + 2))[0]   = 23;
  *(*(nums + 2) + 2) = 24;
  print(nums, 3);
}
