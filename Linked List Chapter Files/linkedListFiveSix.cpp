#include "declaration.hpp"
#include <string>
#include <iostream>
#include "linkedlist.hpp"
namespace LinkedListChapter {
    namespace PostfixProcessingDemo {
        uint getPriority(char input) {
            switch (input) {
                case '(':
                    return 1;
                    break;
                case ')':
                    return 2;
                    break;
                case '+':
                case '-':
                    return 3;
                    break;
                case '*':
                case '/':
                case '%':
                    return 4;
                    break;
                case '^':
                    return 5;
                    break;
            }
            return 0;
        }

        std::string infixToPostfix(std::string input) {
            auto processStack = LinkedListImplementation::LinkedList<char>();
            std::string postfixString = "";
            input.append(")");

            processStack.add('(');
            
            char character, symbol;
            for (int i = 0; i < input.length(); i++) {
                symbol = input[i];
                uint priority = getPriority(symbol);
                switch (priority) {
                    case 1:
                        processStack.add(symbol);
                        break;
                    case 2:
                        character = processStack.take(processStack.length() - 1);
                        while (character != '(') {
                            postfixString += character;
                            character = processStack.take(processStack.length() - 1);
                        }
                        break;
                    case 3:
                    case 4:
                    case 5:
                        character = processStack.take(processStack.length() - 1);
                        while (getPriority(character) >= priority) {
                            postfixString += character;
                            character = processStack.take(processStack.length() - 1);
                        }

                        processStack.add(character);
                        processStack.add(symbol);
                        break;
                    default:
                        postfixString += symbol;
                }   
            }
            return postfixString;
        }

        int demo() {
            std::cout << "Pemrosesan Infix" << "\n";
            while (true) {
                std::cout << "Masukkan ekspresi infix (atau q untuk keluar): ";
                std::cin.ignore();
                std::string input;
                std::getline(std::cin, input);
                if (input == "q") {
                    return 0;
                }
                else {
                    std::cout << input << " = " << infixToPostfix(input) << "\n";
                }
            }
        }
    }
}