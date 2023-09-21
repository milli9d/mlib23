/**
 * @brief 3.6 Animal Shelter
 *
 * An animal shelter, which holds only dogs and cats, operates on a strictly"first in, first out" basis.
 *
 * People must adopt either the"oldest" (based on arrival time) of all animals at the shelter, or they can select
 * whether they would prefer a dog or a cat (and will receive the oldest animal of that type).
 *
 * They cannot select which specific animal they would like.
 *
 * Create the data structures to maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog,
 * and dequeueCat. You may use the built-in Linkedlist data structure.
 *
 */
// BUDT

#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <memory>

#include "logging.h"
LOG_TAG(EX3_6);

namespace ctci {

class animal {
  protected:
    uint64_t id;

  public:
    animal(uint64_t id) : id(id) {}
    uint64_t get_id() {
        return id;
    }
};

class dog: public animal {};
class cat: public animal {};

class animal_shelter {
  private:
    /* stack<pair{seq, animal}> x_stack */
    std::stack<std::pair<size_t, cat>> cat_stack{};
    std::stack<std::pair<size_t, dog>> dog_stack{};
    size_t sz{};
    size_t seq{};

  public:
    void enqueue(dog& dog) {
        dog_stack.push({ seq++, dog });
        sz++;
    }

    void enqueue(cat& cat) {
        cat_stack.push({ seq++, cat });
        sz++;
    }

    bool empty(void) {
        return sz == 0u;
    }

    void dequeue_dog(void) {
        /* early return */
        if (dog_stack.empty()) {
            LOG_ERR("No more dogs in shelter");
            return;
        }

        /* dequeue top dog */
        LOG_INFO("Dequeued dog id = %d seq = %d", dog_stack.top().second.get_id(), dog_stack.top().first);
        dog_stack.pop();
        sz--;
    }

    void dequeue_cat(void) {
        /* early return */
        if (cat_stack.empty()) {
            LOG_ERR("No more cats in shelter");
            return;
        }

        /* dequeue top dog */
        LOG_INFO("Dequeued cat id = %d seq = %d", cat_stack.top().second.get_id(), cat_stack.top().first);
        cat_stack.pop();
        sz--;
    }

    void dequeue_any(void) {
        if (sz == 0u) {
            LOG_ERR("Empty shelter.");
            return;
        }

        /* find top sequence */
        if (cat_stack.empty() || dog_stack.top().first >= cat_stack.top().first) {
            dequeue_dog();
        } else if (dog_stack.empty() || dog_stack.top().first < cat_stack.top().first) {
            dequeue_cat();
        }
    }
};

} // namespace ctci

int main(int argc, char** argv) {
    /* test cases */
    ctci::animal_shelter shelter{};

    shelter.enqueue(*std::make_unique<ctci::dog>(10u));
    shelter.enqueue(*std::make_unique<ctci::dog>(30u));
    shelter.enqueue(*std::make_unique<ctci::cat>(20u));
    shelter.enqueue(*std::make_unique<ctci::cat>(20u));
    shelter.enqueue(*std::make_unique<ctci::cat>(20u));
    shelter.enqueue(*std::make_unique<ctci::dog>(30u));
    shelter.enqueue(*std::make_unique<ctci::dog>(30u));
    shelter.enqueue(*std::make_unique<ctci::cat>(20u));
    shelter.enqueue(*std::make_unique<ctci::dog>(30u));

    while (!shelter.empty()) { shelter.dequeue_any(); }
    shelter.dequeue_any();
    shelter.dequeue_dog();
    shelter.dequeue_cat();

    LOG_PASS("Animal Shelter Passed!");

    return 0;
}