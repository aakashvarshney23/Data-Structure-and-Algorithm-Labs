#include "../inc/expression.h"
#include <iostream>

namespace lab5 {
    /****Auxillary Function prototypes ****/
    bool is_number(std::string input_string);

    bool is_operator(std::string input_string);

    int get_number(std::string input_string);

    std::string get_operator(std::string input_string);

    bool is_left_parenthesis(std::string in);

    bool is_right_parenthesis(std::string in);

    int operator_priority(std::string operator_in);

    bool iswhitespace(std::string in);

    std::string calculate_operation(std::string &operate, std::string &operand, std::string &oper2);

    /****end function prototypes****/

    expression::expression() {
    }

    expression::expression(std::string &input_expression) {
        parse_to_infix(input_expression);
    }

    void expression::convert_to_postfix(std::string &input_expression) {
        stack operators;
        queue input = infix;
        std::string symbol;
        std::string oper;
        while (!input.isEmpty()) {
            symbol = input.top();
            if (is_number(symbol)) {
                postfix.enqueue(symbol);
            }
            if (is_operator(symbol)) {
                while (!operators.isEmpty() && operator_priority(operators.top()) >= operator_priority(symbol)) {
                    //pop stack operator onto output
                    oper = operators.top();
                    postfix.enqueue(oper);
                    operators.pop();
                }
                operators.push(symbol);
            }
            if (is_left_parenthesis(symbol)) {
                operators.push(symbol);
            }
            if (is_right_parenthesis(symbol)) {
                while (!is_left_parenthesis(operators.top())) {
                    oper = operators.top();
                    postfix.enqueue(oper);
                    operators.pop();
                }
                operators.pop();
            }
            input.dequeue();

        }
        while (!operators.isEmpty()) {
            oper = operators.top();
            postfix.enqueue(oper);
            operators.pop();
        }

    }

    void expression::parse_to_infix(std::string &input_expression) {
        //variable to store each character in the string so it can be input to queue
        std::string inputchar;
        std::string nextchar;
        std::string space = " ";
        int j = 0;
        int i = 0;
        //for loop used to enter in string into the infix queue
        while (i < input_expression.length()) {
            inputchar = input_expression[i];
            nextchar = input_expression[i + 1];
            //case for when it is white space
            if (iswhitespace(inputchar)) {
                //increases i and continues loop
                i++;
                continue;
            } else if (is_number(inputchar)) {
                while (is_number(nextchar)) {
                    inputchar += nextchar;
                    i++;
                    nextchar = input_expression[i + 1];
                }
            }
            infix.enqueue(inputchar);
            if (i + 1 != input_expression.length()) {
                infix.enqueue(space);
            }
            i++;
        }

    }

    int expression::calculate_postfix() {
        queue input = infix;
        std::string text = "";
        while (!input.isEmpty()) {
            text += input.top();
            input.dequeue();

        }
        convert_to_postfix(text);
        //variables needed to calculate postfix result
        queue output = postfix;
        stack s;
        std::string symbol;
        std::string operand;
        std::string operand2;
        std::string result;
        //while there is still symbols to be read from postfix
        while (!output.isEmpty()) {
            //read the value from the queue
            symbol = output.top();
            //push symbol to stack if it is a number
            //ignore white space
            if (iswhitespace(symbol)) {
                output.dequeue();
                continue;
            }
            if (is_number(symbol)) {
                s.push(symbol);
                output.dequeue();
            } else if (is_operator(symbol)) {
                //get the two operands
                operand = s.top();
                s.pop();
                operand2 = s.top();
                s.pop();
                //get result of calculation
                result = calculate_operation(symbol, operand2, operand);
                //push result to stack
                s.push(result);
                output.dequeue();
            }

        }
        //return the answer
        int value = atoi(s.top().c_str());
        return value;

    }

    void expression::print_infix() {
        queue temp = infix;
        while (!temp.isEmpty()) {
            std::cout << temp.top();
            temp.dequeue();
        }
    }

    void expression::print_postfix() {
        std::string text;
        queue input = infix;
        while (!input.isEmpty()) {
            text += input.top();
            input.dequeue();
        }
        convert_to_postfix(text);
        queue output = postfix;
        int i = 0;
        int holder = output.queueSize();
        while (i < holder) {
            std::cout << output.top();
            if (i + 1 != holder) {
                std::cout << " ";
            }

            output.dequeue();
            i++;
        }

    }

    std::istream &operator>>(std::istream &steam, expression &RHS) {
        std::string input;
        steam >> input;
        expression test(input);
        RHS = test;
        return steam;
    }

    bool is_number(std::string input_string) {
        if (input_string >= "0" && input_string <= "9") {
            return true;
        } else {
            return false;
        }
    }

    bool is_operator(std::string input_string) {
        if (input_string.compare("+") == 0) {
            return true;
        } else if (input_string.compare("-") == 0) {
            return true;
        } else if (input_string.compare("*") == 0) {
            return true;
        } else if (input_string.compare("/") == 0) {
            return true;
        } else if (input_string.compare("^") == 0) {
            return true;
        } else {
            return false;
        }
    }

    int get_number(std::string input_string) {
    }

    std::string get_operator(std::string input_string) {
    }

    bool is_left_parenthesis(std::string in) {
        if (in.compare("(") == 0) {
            return true;
        } else {
            return false;
        }
    }

    bool is_right_parenthesis(std::string in) {
        if (in.compare(")") == 0) {
            return true;
        } else {
            return false;
        }
    }

    int operator_priority(std::string operator_in) {
        if (operator_in.compare("+") == 0) {
            return 2;
        } else if (operator_in.compare("-") == 0) {
            return 2;
        } else if (operator_in.compare("*") == 0) {
            return 3;
        } else if (operator_in.compare("/") == 0) {
            return 3;
        } else if (operator_in.compare("^") == 0) {
            return 4;
        }
    }

    bool iswhitespace(std::string in) {
        if (in.compare(" ") == 0) {
            return true;
        }
        return false;
    }

    std::string calculate_operation(std::string &operate, std::string &operand, std::string &oper2) {

        int value;
        std::string result;


        if (operate.compare("+") == 0) {
            value = atoi(operand.c_str()) + atoi(oper2.c_str());
        }
        if (operate.compare("-") == 0) {
            value = atoi(operand.c_str()) - atoi(oper2.c_str());
        }
        if (operate.compare("*") == 0) {
            value = atoi(operand.c_str()) * atoi(oper2.c_str());
        }
        if (operate.compare("/") == 0) {
            value = atoi(operand.c_str()) / atoi(oper2.c_str());
        }
        if (operate.compare("^") == 0) {
            if (atoi(oper2.c_str()) == 0) {
                value = 1;
            }
            if (atoi(oper2.c_str()) == 1) {
                value = atoi(operand.c_str());
            } else {
                value = atoi(operand.c_str()) * atoi(operand.c_str());
                for (int i = 2; i < atoi(oper2.c_str()); i++) {
                    value = value * atoi(operand.c_str());
                }

            }
        }
        result = std::to_string(value);

        return result;
    }
}
//