#include <cstring>
#include <iostream>

void clear(char board[5][10]) {
  for (int row = 0; row < 5; ++row) {
    for (int column = 0; column < 10; ++column) {
      board[row][column] = ' ';
    }
  }
}

bool inside(int x, int y) { return x >= 0 && x < 10 && y >= 0 && y < 5; }

bool put(char board[5][10], int x, int y, char symbol) {
  if (!inside(x, y)) {
    return false;
  }

  board[y][x] = symbol;
  return true;
}

bool text(char board[5][10], int x, int y, const char* word) {
  if (!inside(x, y)) {
    return false;
  }

  int length = 0;
  while (word[length] != '\0') {
    ++length;
  }

  if (length > 10 - x) {
    return false;
  }

  for (int i = 0; i < length; ++i) {
    put(board, x + i, y, word[i]);
  }

  return true;
}

void print(const char board[5][10]) {
  for (int row = 0; row < 5; ++row) {
    for (int column = 0; column < 10; ++column) {
      std::cout << board[row][column];
    }
    std::cout << '\n';
  }
}

void skip_line() {
  char symbol;
  while (std::cin.get(symbol)) {
    if (symbol == '\n') {
      break;
    }
  }
}

int main() {
  char board[5][10];
  clear(board);

  char command[10];

  while (true) {
    std::cin >> command;
    if (std::cin.fail()) {
      break;
    }

    if (std::strcmp(command, "quit") == 0) {
      break;
    }

    if (std::strcmp(command, "clear") == 0) {
      clear(board);
    } else if (std::strcmp(command, "put") == 0) {
      int x = 0;
      int y = 0;
      char symbol = ' ';
      std::cin >> x >> y >> symbol;

      if (std::cin.fail() || !put(board, x, y, symbol)) {
        std::cin.clear();
        std::cout << "error\n";
      }
    } else if (std::strcmp(command, "text") == 0) {
      int x = 0;
      int y = 0;
      char word[12];
      std::cin >> x >> y >> word;

      if (std::cin.fail() || !text(board, x, y, word)) {
        std::cin.clear();
        std::cout << "error\n";
      }
    } else if (std::strcmp(command, "print") == 0) {
      print(board);
    } else {
      std::cout << "error\n";
    }

    skip_line();
  }
}
