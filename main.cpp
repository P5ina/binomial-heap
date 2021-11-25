#include <iostream>
#include <vector>

class BinomialHeap {
private:
    class Node {
    private:
        int _value;
        int _degree;
        Node* _parent;
        Node* _child;
        Node* _sibling;
    public:
        Node(int value) : _value(value) {
            _degree = 0;
            _parent = nullptr;
            _child = nullptr;
            _sibling = nullptr;
        }

        int GetValue() {
            return _value;
        }

        int GetDegree() {
            return _degree;
        }

        Node* GetSiblingNode() {
            return _sibling;
        }

        // same as Binomial Link
        void LinkChild(Node* child) {
            child->_parent = this;
            child->_sibling = _child;
            _child = child;
            _degree++;
        }
    };

    Node* _head;
    size_t _size;

    // Merge another heap to this
    // TODO: Merge method
    void Merge(BinomialHeap heap) {
        Node* h1 = _head;
        Node* h2 = heap._head;

        Node* currentNode;

        if (h1->GetDegree() > h2->GetDegree()) {
            currentNode = h2;
        }
        else {
            currentNode = h1;
        }

        while (h1->GetSiblingNode() != nullptr && h2->GetSiblingNode() != nullptr) {
            Node* h1Sibling = h1->GetSiblingNode();
            Node* h2Sibling = h2->GetSiblingNode();
            if (h1Sibling->GetDegree() < h2Sibling->GetDegree()) {

            }
        }
    }
public:
    BinomialHeap() {
        _head = nullptr;
        _size = 0;
    }

    int Min() {
        if (_head == nullptr) {
            throw std::out_of_range("The heap is empty!");
        }

        int minValue = _head->GetValue();
        Node* next = _head;

        while (next != nullptr) {
            if (next->GetValue() < minValue) {
                minValue = next->GetValue();
            }

            next = next->GetSiblingNode();
        }

        return minValue;
    }
};

int main() {
    BinomialHeap heap;
    std::cout << heap.Min() << std::endl;

    return 0;
}
