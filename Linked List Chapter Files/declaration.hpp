#include "linkedlist.hpp"
#include "implementations.hpp"
#include <string>

// the following namespaces are for problems that implement the linked list.
namespace LinkedListChapter {
    namespace ReverseString {
        void reverseString(std::string str);
        void demo();
    }
    namespace StackDemo {
        void display(Implementations::Queue<std::string> q);
        void demo();
    }
    namespace QueueDemo {
        int demo();
    }
    namespace OrderedListDemo {
        void demo();
    }
}