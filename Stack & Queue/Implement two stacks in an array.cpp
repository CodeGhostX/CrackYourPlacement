class twoStacks {
  public:
    vector<int> temp1;
    vector<int> temp2;
    twoStacks() {}

    // Function to push an integer into the stack1.
    void push1(int x) {
        temp1.push_back(x);
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        temp2.push_back(x);
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if(temp1.size()) {
            int a = temp1.back();
            temp1.pop_back();
            return a;
        }
        return -1;
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if(temp2.size()) {
            int a = temp2.back();
            temp2.pop_back();
            return a;
        }
        return -1;
    }
};
