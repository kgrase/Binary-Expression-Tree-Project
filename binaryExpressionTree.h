#ifndef __BINARY_EXPRESSION_TREE_H__
#define __BINARY_EXPRESSION_TREE_H__

#include "binaryTree.h"
#include <string>
#include <stack>
#include <cstring>
#include <regex>

class binaryExpressionTree : public binaryTreeType<std::string> {
    public:
    bool search(const std::string& searchItem) const override {return true;}
    void insert(const std::string& insertItem) override {}
    void deleteNode(const std::string& deleteItem) override {}

    public:
    void buildExpressionTree(const std::string& postfixExpression);
    double evaluateExpressionTree();

    private:
    double evaluateExpressionTree(nodeType<std::string>* node);
};

#endif

