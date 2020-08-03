class LL {
    public:
    // Basic CTOR
    LL();

    void add(int data);
    void addFirst(int data);
    void addInPlace(int data, unsigned int location);
    int removeLast();
    int removeFirst();
    void deleteList();
    void printList();

    private:

    class LlNode {
       public:
        LlNode* next;
        int data;
    };

    LlNode* head;
    LlNode* last;
    unsigned int size;
};
