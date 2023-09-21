/**
 * @brief Graph implementation
 *
 */
#include <stdio.h>

#include <vector>
#include <unordered_map>

#include "logging.h"

LOG_TAG("Graph");

class graph {
  public:
    typedef struct _node_s {
        std::vector<struct _node_s*> children;
        uint8_t val;
    } node_s;

  private:
    size_t sz{};
    std::unordered_map<node_s*, std::vector<node_s*>> adj_list{};

  public:
    /* constructors */
    graph() {}
    ~graph() {}

    node_s* new_node(uint8_t val) {
        node_s* out = (node_s*) calloc(sizeof(node_s*), 1u);
    }

    void graph_insert(uint8_t val, std::vector<node_s*>& children) {
        node_s* insert = new_node(val);

        adj_list.insert(std::pair{});
    }
};

int main(int argc, char** argv) {
    LOG_INFO("Hello World");

    graph my_graph{};

    return 0;
}