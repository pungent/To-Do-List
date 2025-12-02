/*
 * C++ To-Do List
 * By: Pungent
 *
 */

#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <string>
#include <vector>

int main() {
  std::string userTask;
  std::string userChoice;
  std::vector<std::string> toDoItems;
  int itemIndex;

  while (true) {
    std::cout << "[Ctrl + C to quit]\nTo-Do List:\n\t";
    for (int i = 0; i < toDoItems.size(); i++) {
      std::cout << "[" << i << "]." << "\t" << toDoItems[i]
                << "\n\n\t"; // [0]. Task1
    }
    std::cout << "To remove a task, type [ \"remove\" ]. To add a task, type "
                 "[ \"add\" ].\n\t-> ";

    std::cin >> userChoice;
    // Get Lowercase
    std::transform(userChoice.begin(), userChoice.end(), userChoice.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    if (userChoice == "remove" &&
        toDoItems.size() >
            0) { // Prevent removing when there's nothing to remove
      std::cout << "\nEnter the number of the task you wish to remove. "
                   "E.g [ 0 ]\n\t-> ";
      std::cin >> itemIndex;
      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
      }
      if (itemIndex < 0 ||
          itemIndex >=
              static_cast<int>(toDoItems.size())) { // Handle out of bounds
        system("clear");
        std::cout << "Requested task does not exist.\n\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
      }

      toDoItems.erase(toDoItems.begin() + itemIndex);
      system("clear");
    } else if (userChoice == "add") {
      std::cout << "\tEnter your task.\n\t-> ";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                      '\n'); // clear chars from buffer
      getline(std::cin, userTask);
      toDoItems.push_back(userTask);
      system("clear");
    } else {
      system("clear");
      std::cout << "You either tried to delete a task that doesn't exist, or "
                   "tried to put letters where they don't belong.\n\n";
    }
  }
}
