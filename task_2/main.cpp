#include <cstring>
#include <iostream>

void deposit(long long& balance) {
  long long amount = 0;
  std::cin >> amount;

  if (std::cin.fail() || amount <= 0) {
    std::cin.clear();
    std::cout << "error\n";
    return;
  }

  balance += amount;
}

void withdraw(long long& balance) {
  long long amount = 0;
  std::cin >> amount;

  if (std::cin.fail() || amount <= 0 || amount > balance) {
    std::cin.clear();
    std::cout << "error\n";
    return;
  }

  balance -= amount;
}

void show_balance(long long& balance) { std::cout << balance << '\n'; }

void reset(long long& balance) { balance = 0; }

void inc(long long& balance) { ++balance; }

void skip_line() {
  char symbol;
  while (std::cin.get(symbol)) {
    if (symbol == '\n') {
      break;
    }
  }
}

struct Command {
  const char* name;

  void (*function)(long long&);
};

int main() {
  long long balance = 0;
  const int kCommandBufferSize = 67;
  char command[kCommandBufferSize];

  const Command commands[] = {
      {"deposit", &deposit},
      {"withdraw", &withdraw},
      {"balance", &show_balance},
      {"reset", &reset},
      {"inc", &inc},
  };

  while (true) {
    std::cin >> command;
    if (std::cin.fail()) {
      break;
    }
    if (std::strcmp(command, "stop") == 0) {
      break;
    }
    bool found = false;
    for (const Command& entry : commands) {
      if (std::strcmp(command, entry.name) == 0) {
        entry.function(balance);
        found = true;
        break;
      }
    }
    if (!found) {
      std::cout << "error\n";
    }
    skip_line();
  }
}