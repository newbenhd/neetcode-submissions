struct DoubleLinkedList {
    int key;
    int value;
    DoubleLinkedList* next;
    DoubleLinkedList* prev;
    DoubleLinkedList(int k, int v, DoubleLinkedList* n, DoubleLinkedList* p)
        : key(k), value(v), next(n), prev(p) {};
};

class LRUCache {
   public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->cache = unordered_map<int, DoubleLinkedList*>();
        this->head = nullptr;
        this->tail = nullptr;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            DoubleLinkedList* temp = cache[key];
            int value = temp->value;
            if (temp != head) {
                DoubleLinkedList* prev = temp->prev;
                DoubleLinkedList* next = temp->next;
                if (temp == this->tail) this->tail = prev;
                if (prev != nullptr) prev->next = next;
                if (next != nullptr) next->prev = prev;
                this->head->prev = temp;
                temp->next = this->head;
                temp->prev = nullptr;
                this->head = temp;
            }
            return value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (this->head == nullptr) {
            this->head = new DoubleLinkedList(key, value, nullptr, nullptr);
            this->tail = head;
            this->cache[key] = this->head;
            this->size++;
        } else if (cache.find(key) != cache.end())  // no size update
        {
            DoubleLinkedList* temp = cache[key];

            if (temp != this->head) {
                if (this->tail == temp)  // tail update
                {
                    this->tail = temp->prev;
                }
                DoubleLinkedList* prev = temp->prev;
                DoubleLinkedList* next = temp->next;
                if (prev != nullptr) prev->next = next;
                if (next != nullptr) next->prev = prev;
                temp->prev = nullptr;
                temp->next = this->head;
                this->head->prev = temp;
                this->head = temp;
            }
            temp->value = value;
        } else {
            cache[key] = new DoubleLinkedList(key, value, this->head, nullptr);
            this->head->prev = cache[key];
            this->head = cache[key];
            this->size++;
        }
        if (this->size > this->capacity) {
            DoubleLinkedList* temp = this->tail;
            cache.erase(temp->key);
            this->tail = temp->prev;
            if (this->tail)
                tail->next = nullptr;
            else
                head = nullptr;
            delete temp;
            this->size--;
        }
    }

   private:
    unordered_map<int, DoubleLinkedList*> cache;
    int capacity;
    int size;
    DoubleLinkedList* head;
    DoubleLinkedList* tail;
};
