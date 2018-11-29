#ifndef _LINKED_STACK
#define _LINKED_STACK

#include "StackInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedStack : public StackInterface<ItemType>
{
private:
    Node<ItemType>* topPtr;    // Pointer to first node in chain;

public:
    LinkedStack();
    LinkedStack(const LinkedStack<ItemType>* aStack);
    virtual ~LinkedStack();
// Stack operations:
    bool isEmpty() const;
    bool push(const ItemType& newItem);
    bool pop();
    ItemType peek() const;
};
#include "LinkedStack.cpp"
#endif
