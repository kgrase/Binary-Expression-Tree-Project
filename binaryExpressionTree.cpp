#include "binaryExpressionTree.h"

void binaryExpressionTree::buildExpressionTree(const std::string& postfixExpression) {
    char* expression = new char[postfixExpression.length()+1];
    strcpy(expression, postfixExpression.c_str());

    std::stack<nodeType<std::string>*> stk;

    char* token = strtok(expression, " ");
    while (token != nullptr) {
        if (std::regex_match(token, std::regex("^\\d*$"))) {
            nodeType<std::string>* node = new nodeType<std::string>;
            node->info = std::string(token);
            stk.push(node);
        }
        else if (std::regex_match(token, std::regex("^[+-/*]$"))) {
            nodeType<std::string>* node;
            nodeType<std::string>* rLink;
            nodeType<std::string>* lLink;

            if (!stk.empty()) {
                rLink = stk.top();
                stk.pop();
                if (!stk.empty()) {
                    lLink = stk.top();
                    stk.pop();
                }
                else {
                    // Error – Stack is empty
                    delete rLink;
                    std::cout << "Error - Stack is empty." << std::endl;
                    return;

                }

                node = new nodeType<std::string>;
                node->info = std::string(token);

                node->lLink = lLink;
                node->rLink = rLink;
                stk.push(node);
            }
            else {
                // Error – Stack is empty
                std::cout << "Error – Stack is empty." << std::endl;
                return;
            }
        }
        else {
            // Error – unsupported token
            while (!stk.empty()) {delete stk.top(); stk.pop();}
            std::cout << "Error – unsupported token." << std::endl;
            return;
        }

        token = strtok(nullptr, " ");
    }

    if (!stk.empty()) {
        this->root = stk.top();
        stk.pop();
    }

    if (!stk.empty()) {
        // There was an error
        std::cout << "Error - There was an error creating expression tree." << std::endl;
        this->destroyTree();
        return;
    }

    delete[] expression;
}

double binaryExpressionTree::evaluateExpressionTree() {
    if (root != nullptr) {
        return evaluateExpressionTree(root);
    }
    else {
        std::cout << "Error - Cannot evaluate empty tree." << std::endl;
    }

    return 0;
}

double binaryExpressionTree::evaluateExpressionTree(nodeType<std::string>* node) {
    if (std::regex_match(node->info, std::regex("^\\d*$"))) {
        return std::stod(node->info);
    }

    double lvalue = evaluateExpressionTree(node->lLink);
    double rvalue = evaluateExpressionTree(node->rLink);


    if (node->info == "+")
        return lvalue + rvalue;
    if (node->info == "-")
        return lvalue - rvalue;
    if (node->info == "*")
        return lvalue * rvalue;
    if (node->info == "/")
        return lvalue / rvalue;

    return 0;
}

