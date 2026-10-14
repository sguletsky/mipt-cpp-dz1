#include <iostream>

int main() {
  // Задача: сохранить показания датчиков в комнатах и вывести общий отчёт.
  // int*** хранит три уровня: этажи, комнаты и массивы показаний датчиков.
  // Размеры задаются при вводе; массивы на каждом уровне создаём через new.
  // Таблица отчёта содержит название (char*) и показания комнат (int*).
  // void* позволяет хранить эти разные указатели в общей таблице.
  // Массив types определяет тип записи для правильного приведения при выводе.

  char building_name[32];
  int floors = 0;
  int rooms = 0;
  int sensors = 0;
  std::cin >> building_name >> floors >> rooms >> sensors;

  if (floors <= 0 || rooms <= 0 || sensors <= 0) {
    std::cout << "error\n";
    return 0;
  }

  int*** temperatures = new int**[floors];
  int entry_count = floors * rooms + 1;
  void** report = new void*[entry_count];
  int* types = new int[entry_count];
  report[0] = building_name;
  types[0] = 0;
  int entry_index = 1;

  for (int floor = 0; floor < floors; ++floor) {
    temperatures[floor] = new int*[rooms];

    for (int room = 0; room < rooms; ++room) {
      temperatures[floor][room] = new int[sensors];

      for (int sensor = 0; sensor < sensors; ++sensor) {
        std::cin >> temperatures[floor][room][sensor];
      }
      report[entry_index] = temperatures[floor][room];
      types[entry_index] = 1;
      ++entry_index;
    }
  }

  for (int i = 0; i < entry_count; ++i) {
    void* data = report[i];
    if (types[i] == 0) {
      std::cout << "Building: " << static_cast<char*>(data);
    } else {
      int floor = (i - 1) / rooms + 1;
      int room = (i - 1) % rooms + 1;
      std::cout << "Room " << floor << ' ' << room << ": ";

      int* readings = static_cast<int*>(data);
      for (int sensor = 0; sensor < sensors; ++sensor) {
        if (sensor > 0) {
          std::cout << ' ';
        }
        std::cout << readings[sensor];
      }
    }

    std::cout << '\n';
  }

  delete[] report;
  delete[] types;
  for (int floor = 0; floor < floors; ++floor) {
    for (int room = 0; room < rooms; ++room) {
      delete[] temperatures[floor][room];
    }
    delete[] temperatures[floor];
  }
  delete[] temperatures;
}
