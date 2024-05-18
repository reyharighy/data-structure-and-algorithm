#include "linkedlist.hpp"
#include "declaration.hpp"
#include <string>
#include <iostream>

namespace LinkedListChapter {
    namespace DoublyLinkedListDemo {
        int demo() {
            auto list = LinkedListImplementation::DoublyLinkedList<std::string>();
            list.add("Gavis Bettel");
            list.add("Ohio Skibidi Toilet");
            list.add("Yugoslavia");
            list.add("Nintendo Wii U");
            list.forwardTraverseDemo();
            std::cout << "\n";
            list.reverseTraverseDemo();
            std::cout << "\n";
            return 0;
        }
    }
}