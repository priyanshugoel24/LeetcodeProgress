// Last updated: 02/05/2026, 22:46:09
class Stack {
private:
    int* stackList;
    int topIndex;
    int capacity;

    void resize() {
        int newCapacity = capacity * 2;
        int* newStackList = new int[newCapacity];
        for (int i = 0; i < capacity; i++) {
            newStackList[i] = stackList[i];
        }
        delete[] stackList;
        stackList = newStackList;
        capacity = newCapacity;
    }

public:
    Stack() {
        capacity = 10;
        stackList = new int[capacity];
        topIndex = -1;
    }

    ~Stack() { delete[] stackList; }

    bool isEmpty() const { return topIndex == -1; }

    int top() const {
        if (isEmpty()) {
            return -1; // or handle the error as appropriate
        }
        return stackList[topIndex];
    }

    void push(int value) {
        if (topIndex + 1 == capacity) {
            resize();
        }
        stackList[++topIndex] = value;
    }

    int pop() {
        if (isEmpty()) {
            return -1; // or handle the error as appropriate
        }
        return stackList[topIndex--];
    }
};

class MyQueue {
private:
    Stack stack1;
    Stack stack2;

public:
    MyQueue() {}

    void push(int x) {
        // Transfer all elements from stack1 to stack2
        while (!stack1.isEmpty()) {
            stack2.push(stack1.pop());
        }

        // Push the new element to stack1
        stack1.push(x);

        // Transfer all elements back from stack2 to stack1
        while (!stack2.isEmpty()) {
            stack1.push(stack2.pop());
        }
    }

    int pop() { return stack1.pop(); }

    int peek() { return stack1.top(); }

    bool empty() { return stack1.isEmpty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */