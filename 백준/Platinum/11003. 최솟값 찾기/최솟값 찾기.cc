#include <iostream>
#include <deque>
#include <vector>

struct Node {
    int index;
    int value;

    Node(int index, int value) : index(index), value(value) {}
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, l;
    std::cin >> n >> l;

    std::deque<Node> deque;

    for (int idx = 1; idx <= n; idx++) {
        int value;
        std::cin >> value;

        while (!deque.empty() && deque.back().value > value) {
            deque.pop_back();
        }
        deque.push_back(Node(idx, value));
        if (!deque.empty() && (idx - deque.front().index) >= l) {
            deque.pop_front();
        }

        std::cout << deque.front().value << " ";
    }

    return 0;
}
