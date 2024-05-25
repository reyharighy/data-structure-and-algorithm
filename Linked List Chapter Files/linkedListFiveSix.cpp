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

        int calculate(char ope, int operand1, int operand2) {
            int result = 0;
            switch (ope) {
                case '^':
                    result = 1;
                    for (int i = 1; i <= operand2; ++i) {
                        result = result * operand1;
                    }
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '%':
                    result = operand1 % operand2;
                    break;
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
            }
            return result;
        }

        int evalPostFix(std::string postfix) {
            char character;
            int operand1, operand2;
            auto operands = LinkedListImplementation::LinkedList<int>();
            for (int i = 0; i < postfix.length(); ++i) {
                character = postfix[i];
                if ((character >= '0') && (character <= '9')) {
                    operands.add(character - '0');
                }
                else {
                    operand2 = operands.take(operands.length() - 1);
                    operand1 = operands.take(operands.length() - 1);
                    int val = calculate(character, operand1, operand2);
                    operands.add(val);
                }   
            }
            return operands.take(operands.length() - 1);
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
                    std::string postfix = infixToPostfix(input);
                    std::cout << input << " = " << postfix << "\n";
                    std::cout << "Tampilkan hasil? (y/n): ";
                    char input;
                    std::cin >> input;
                    if (input == 'y') {
                        try {
                            std::cout << postfix <<  " = " << evalPostFix(postfix) << "\n";
                        }
                        catch (const std::exception& e) {
                            std::cout << "Eror." << "\n";
                        }
                    }
                }
            }
        }
    }
}