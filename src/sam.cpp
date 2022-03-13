#include "sam.h"

void sam::init() {
    this->states.emplace_back(state());
    this->last = 0;
    this->id = 0;
}
void sam::extend_c(char c) {
    state node;
    node.len = this->states[this->last].len + 1;
    this->states.emplace_back(node);
    int p = this->last;
    auto cur = this->last + 1;
    while (p != -1 && this->states[p].next.count(c)) {
        this->states[p].next[c] = cur;
        p = this->states[p].link;
    }

    if (p == -1) {
        this->states[cur].link = 0;
    } else {
        auto another = this->states[p].next[c];
        if (this->states[p].len + 1 == this->states[another].len) {
            this->states[cur].link = another;
        } else {
            state nodeNew;
            nodeNew.len = this->states[p].len + 1;
            nodeNew.next = this->states[another].next;
            nodeNew.link = this->states[another].link;

            while (this->states[p] != -1 && this->states.next[c] == another) {
                this->states[p].next[c] = another;
                p = this->states[p].link;
            }
            this->states[cur].link = nodeNew;
            this->states[another].link = nodeNew;
        }

    }
    this->last = cur;
}


