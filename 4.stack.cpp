#include <iostream>
#include <stack>
#include <cmath>

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to perform arithmetic operations
int performOperation(char operation, int operand1, int operand2) {
    switch (operation) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        default:  return 0;  // Invalid operator (should not occur in this example)
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(const std::string& expression) {
    std::stack<int> operandStack;

    for (char c : expression) {
        if (isdigit(c)) {
            operandStack.push(c - '0');  // Convert char to integer and push to the stack
        } else if (isOperator(c)) {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();
            int result = performOperation(c, operand1, operand2);
            operandStack.push(result);
        }
    }

    return operandStack.top();
}

// Function to evaluate a prefix expression
int evaluatePrefix(const std::string& expression) {
    std::stack<int> operandStack;

    for (int i = expression.size() - 1; i >= 0; --i) {
        char c = expression[i];
        if (isdigit(c)) {
            operandStack.push(c - '0');  // Convert char to integer and push to the stack
        } else if (isOperator(c)) {
            int operand1 = operandStack.top();
            operandStack.pop();
            int operand2 = operandStack.top();
            operandStack.pop();
            int result = performOperation(c, operand1, operand2);
            operandStack.push(result);
        }
    }

    return operandStack.top();
}

int main() {
    // Example postfix expression: "23*5+"
    std::string postfixExpression = "23*5+";
    int resultPostfix = evaluatePostfix(postfixExpression);
    std::cout << "Result of postfix expression: " << resultPostfix << std::endl;

    // Example prefix expression: "+*235"
    std::string prefixExpression = "+*235";
    int resultPrefix = evaluatePrefix(prefixExpression);
    std::cout << "Result of prefix expression: " << resultPrefix << std::endl;

    return 0;
}
//code by Kur Athuai
