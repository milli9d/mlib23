/**
 * @brief Binary tree implementation
 *
 */

#include <stdio.h>
#include <cstdint>
#include <iostream>
#include <sstream>

#include <vector>

#include "logging.h"
LOG_TAG(binary_tree);

namespace trees {

/* =========================================== */
/* binary_tree.hpp */
/* =========================================== */

/* class definition */
class binary_tree {
  public:
    typedef struct node_s {
        uint32_t val;
        struct node_s* left;
        struct node_s* right;

        /**
         * @brief allocate a new node
         */
        static struct node_s* new_node(uint8_t val) {
            struct node_s* out = (node_s*) calloc(sizeof(struct node_s), 1u);
            out->val = val;
            return out;
        }
    } node_s;

  private:
    size_t sz = 0;
    node_s* root{};

  public:
    /* constructor */
    binary_tree();

    /* destructor */
    ~binary_tree();

    node_s*& get_root() {
        return root;
    }

    void set_root(node_s* root) {
        this->root = root;
    }

    /* breadth first search */
    void print_bfs();
    void print_bfs(node_s* root, std::vector<std::string>& out, uint32_t level);
};

/* =========================================== */
/* binary_tree.cpp */
/* =========================================== */

/**
 * @brief
 */
binary_tree::binary_tree() {
    /* init tree */
    LOG_PASS("Binary tree inited");
}

/**
 * @brief
 */
binary_tree::~binary_tree() {}

/**
 * @brief
 */
void binary_tree::print_bfs() {
    std::vector<std::string> arr{};
    print_bfs(root, arr, 0u);

    for (auto str: arr) { std::cout << str << std::endl; }
}

/**
 * @brief
 * @param root
 * @param out
 * @param level
 */
void binary_tree::print_bfs(node_s* root, std::vector<std::string>& out, uint32_t level) {
    if (root == NULL) {
        return;
    }

    try {
        out.at(level) = out.at(level) + std::to_string(root->val) + " ";
    } catch (std::out_of_range const& exc) {
        out.push_back(std::string());
        out.at(level) = out.at(level) + std::to_string(root->val) + " ";
    }

    print_bfs(root->left, out, level + 1);
    print_bfs(root->right, out, level + 1);
}

/* =========================================== */
/* binary_tree_main.cpp */
/* =========================================== */

} /* namespace trees */

/**
 * @brief test bench
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char** argv) {
    trees::binary_tree tree;

    trees::binary_tree::node_s* a = trees::binary_tree::node_s::new_node(10u);
    trees::binary_tree::node_s* b = trees::binary_tree::node_s::new_node(20u);
    trees::binary_tree::node_s* c = trees::binary_tree::node_s::new_node(30u);
    trees::binary_tree::node_s* d = trees::binary_tree::node_s::new_node(40u);
    trees::binary_tree::node_s* e = trees::binary_tree::node_s::new_node(50u);
    trees::binary_tree::node_s* f = trees::binary_tree::node_s::new_node(60u);
    trees::binary_tree::node_s* g = trees::binary_tree::node_s::new_node(70u);

    tree.set_root(a);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;
    e->left = g;

    tree.print_bfs();

    free(a);
    free(b);
    free(c);
    free(d);
    free(e);
    free(f);
    free(g);

    return 0;
}
