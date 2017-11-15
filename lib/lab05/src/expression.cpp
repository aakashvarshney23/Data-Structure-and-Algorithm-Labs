#include <iostream>
#include "../inc/expression.h"
namespace lab5 {
    /****Auxillary Function prototypes ****/
    bool is_number(std::string);
    bool is_operator(std::string substring);
    int get_number(std::string substring,std::string::iterator& position);
    std::string get_operator(std::string);
    int operator_precedence(std::string operator_in);
    int binary_calculate(std::string basic_string, int lhs, int rhs);
/****end function prototypes****/


    expression::expression() = default;

    expression::expression(std::string &input_expression) {
        parse_to_infix(input_expression);
        convert_to_postfix(input_expression);
    }

    void expression::convert_to_postfix(std::string &input_expression) {
        queue tmp_infix = infix;
        std::string equation_item, tmp_item;
        stack operator_stack;

        while (!(tmp_infix.isEmpty())) {
            equation_item = tmp_infix.top();

            if (is_number(equation_item)) {
                postfix.enqueue(equation_item);
            } else if (is_operator(equation_item)) {
                if (operator_stack.isEmpty() || equation_item[0] == '(') {
                    operator_stack.push(equation_item);
                } else if (equation_item[0] != ')') {
                    while (!operator_stack.isEmpty() && (operator_precedence(equation_item) <=
                                                         operator_precedence(operator_stack.top()))) {
                        tmp_item = operator_stack.top();
                        postfix.enqueue(tmp_item);
                        operator_stack.pop();
                    }
                    operator_stack.push(equation_item);
                } else if (equation_item[0] == ')') {
                    while (operator_stack.top()[0] != '(') {
                        tmp_item = operator_stack.top();
                        postfix.enqueue(tmp_item);
                        operator_stack.pop();
                    }
                    operator_stack.pop();
                }
            }
            tmp_infix.dequeue();
        }
        while (!operator_stack.isEmpty()) {
            tmp_item = operator_stack.top();
            postfix.enqueue(tmp_item);
            operator_stack.pop();
        }
    }

    void expression::parse_to_infix(std::string &input_expression) {
        std::string::iterator position=input_expression.begin(),string_end=input_expression.end();
        std::string data;

        while(position!= string_end) {
            while (isspace(*position)) ++position;

            if (is_number(std::string(position, position + 1))) {
                data = std::to_string(get_number(std::string(position, string_end), position));
                infix.enqueue(data);
            } else if (is_operator(std::string(position, position + 1))) {
                data = get_operator(std::string(position, position + 1));
                infix.enqueue(data);
            } else { throw 2; }
            ++position;
        }
    }

    int expression::calculate_postfix() {
        stack number_stack;
        queue temp_postfix(postfix);
        std::string equation_item, binary_solution;
        int lhs, rhs;

        while(!temp_postfix.isEmpty()){
            equation_item=temp_postfix.top();
            temp_postfix.dequeue();
            if(is_number(equation_item)){
                number_stack.push(equation_item);
            }
            else if(is_operator(equation_item)){
                rhs = std::stoi(number_stack.top());
                number_stack.pop();
                lhs = std::stoi(number_stack.top());
                number_stack.pop();
                binary_solution=std::to_string(binary_calculate(equation_item, lhs, rhs));
                number_stack.push(binary_solution);
            }
        }
        return std::stoi(number_stack.top());
    }

    void expression::print_infix() {
        queue tmp_infix=infix;

        if (!tmp_infix.isEmpty()) {
            std::cout << tmp_infix.top();
            tmp_infix.dequeue();
        }

        while(!tmp_infix.isEmpty()){
            std::cout << " " << tmp_infix.top();
            tmp_infix.dequeue();
        }
        std::cout.flush();
    }

    void expression::print_postfix() {
        queue tmp_postfix=postfix;

        if (!tmp_postfix.isEmpty()) {
            std::cout << tmp_postfix.top();
            tmp_postfix.dequeue();
        }


        while(!tmp_postfix.isEmpty()){
            std::cout << " " << tmp_postfix.top();
            tmp_postfix.dequeue();
        }
        std::cout.flush();
    }

    std::istream &operator>>(std::istream &steam, expression &RHS) {
        std::string input_data;
        steam >> input_data;
        expression tmp(input_data);
        RHS.postfix = tmp.postfix;
        RHS.infix = tmp.infix;
    }




//auxillary functions



    bool is_number(std::string substring){
        return (substring[0]>='0' && substring[0]<='9');
    }

    bool is_operator(std::string substring){
        return  (substring[0]=='+'||substring[0]=='-'||substring[0]=='*'||substring[0]=='/'||substring[0]=='('||substring[0]==')');
    }

    int get_number(std::string substring,std::string::iterator& position){
        int number=0;

        while(position != substring.end() && is_number(std::string(position,position+1))){
            number*=10;
            number+=*position-'0';
            ++position;
        }
        --position;//set position to last digit
        return number;
    }

    std::string get_operator(std::string substring){
        return substring;
    }

    int operator_precedence(std::string operator_in){
        switch (operator_in[0]){
            case '+':
                return 2;
            case '-':
                return 2;
            case '*':
                return 3;
            case '/':
                return 3;
            default:
                return 0;
        }
    }

    int binary_calculate(std::string operator_in, int lhs, int rhs) {
        switch (operator_in[0]){
            case '+':
                return lhs+rhs;
            case '-':
                return lhs-rhs;
            case '*':
                return lhs*rhs;
            case '/':
                return lhs/rhs;
            default:
                return 0;
        }
    }
}