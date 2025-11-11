#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

template<typename T>
struct Node {
    T val;
    Node<T>* left;
    Node<T>* right;

    explicit Node(T val, Node<T>* left = nullptr, Node<T>* right = nullptr)
        : val{val}, left{left}, right{right} {}

    ~Node() {
        delete left;
        delete right;
    }
};

void pre_order_traversal(Node<int>* root) {
    if (root != nullptr) {
        std::cout << root->val << '\n';
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}
//g++ preordertraversal.cpp -std=c++20 - DRUN_PREORDER_EXAMPLES
//./a.out
void print_example(const std::string& label, Node<int>* root) {
    std::cout << label << '\n';
    pre_order_traversal(root);
}

Node<int>* build_balanced_example() {
    return new Node<int>{
        1,
        new Node<int>{
            2,
            new Node<int>{4},
            new Node<int>{5}
        },
        new Node<int>{
            3,
            nullptr,
            new Node<int>{6}
        }
    };
}

Node<int>* build_left_skewed_example() {
    return new Node<int>{
        10,
        new Node<int>{
            9,
            new Node<int>{
                8,
                new Node<int>{7},
                nullptr
            },
            nullptr
        },
        nullptr
    };
}

Node<int>* build_right_skewed_example() {
    return new Node<int>{
        5,
        nullptr,
        new Node<int>{
            12,
            nullptr,
            new Node<int>{
                20,
                nullptr,
                new Node<int>{25}
            }
        }
    };
}

void run_examples() {
    Node<int>* balanced = build_balanced_example();
    print_example("Example 1: Balanced (expect 1 2 4 5 3 6)", balanced);
    delete balanced;

    Node<int>* left_skewed = build_left_skewed_example();
    print_example("Example 2: Left-leaning chain (expect 10 9 8 7)", left_skewed);
    delete left_skewed;

    Node<int>* right_skewed = build_right_skewed_example();
    print_example("Example 3: Right-leaning chain (expect 5 12 20 25)", right_skewed);
    delete right_skewed;
}

// this function builds a tree from input
// learn more about how trees are encoded in https://algo.monster/problems/serializing_tree
template<typename T, typename Iter, typename F>
Node<T>* build_tree(Iter& it, F f) {
    std::string val = *it;
    ++it;
    if (val == "x") return nullptr;
    Node<T>* left = build_tree<T>(it, f);
    Node<T>* right = build_tree<T>(it, f);
    return new Node<T>{f(val), left, right};
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    ss >> std::boolalpha;
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

int main() {
#ifdef RUN_PREORDER_EXAMPLES
    run_examples();
#else
    std::vector<std::string> root_vec = get_words<std::string>();
    auto root_it = root_vec.begin();
    Node<int>* root = build_tree<int>(root_it, [](auto s) { return std::stoi(s); });
    pre_order_traversal(root);
    delete root;
#endif
}
