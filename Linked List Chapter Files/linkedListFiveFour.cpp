#include <string>
#include <iostream>
#include "linkedlist.hpp"
#include "declaration.hpp"

namespace LinkedListChapter {
    namespace OrderedListDemo {
        void demo() {
            LinkedList::OrderedLinkedList<std::string> orderedList = LinkedList::OrderedLinkedList<std::string>();
            orderedList.add("d");
            orderedList.add("c");
            orderedList.add("b");
            orderedList.add("z");
            orderedList.add("a");
            orderedList.add("e");

            for (int i = 0; i < orderedList.length(); ++i) {
                std::cout << orderedList.get(i) << "\n";
            }
        }
    }
}