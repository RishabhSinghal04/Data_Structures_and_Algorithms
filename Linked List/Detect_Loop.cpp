
#include <iostream>
#include <conio.h>

template <typename T>
struct Node
{
    T data;
    Node<T> *next = nullptr;

    Node()
        : Node({}) {}
    Node(const T &data)
        : data{data}, next{nullptr} {}
};

template <typename T>
class Linked_List
{
    Node<T> *head = nullptr;
    size_t size = 0ULL;

public:
    Linked_List()
        : head{nullptr}, size{0ULL} {}

    ~Linked_List()
    {
        clear();
        std::cout << "\nEXIT\n";
    }

    bool empty() const { return head == nullptr; }

    /* __Getters__ */
    Node<T> *get_head() const { return head; }
    const T get_size() const { return size; }

    /* _Add Nodes_ */
    void push(const T &data)
    {
        Node<T> *new_node = new Node<T>(data);
        new_node->next = head;
        head = new_node;
        ++size;
    }

    void push_back(const T &data)
    {
        Node<T> *new_node = new Node<T>(data);
        Node<T> *last_node = head;
        new_node->next = nullptr;

        if (empty())
        {
            return push(data);
        }

        while (last_node->next != nullptr)
        {
            last_node = last_node->next;
        }
        last_node->next = new_node;
        ++size;
    }

    void insert_at(const size_t &index, const T &data)
    {
        if (empty() || index > size)
        {
            return;
        }
        if (index == 0ULL)
        {
            return push(data);
        }
        if (index == size)
        {
            return push_back(data);
        }

        Node<T> *node = new Node<T>(data);
        Node<T> *prev_node = head;

        for (size_t i = 1ULL; i < index; ++i)
        {
            prev_node = prev_node->next;
        }

        node->next = prev_node->next;
        prev_node->next = node;
        ++size;
    }

    /* _Delete Nodes_ */
    void clear()
    {
        Node<T> *next = nullptr;
        while (head != nullptr)
        {
            next = head->next;
            head = nullptr;
            head = next;
        }
        size = 0ULL;
    }

    void delete_first_element()
    {
        if (empty())
        {
            return;
        }

        Node<T> *first_node = head;
        head = first_node->next;
        --size;
        free_memory(first_node);
    }

    void delete_last_element()
    {
        if (size < 2ULL)
        {
            return empty() ? (void)0 : delete_first_element();
        }

        Node<T> *second_last_node = head;

        while (second_last_node->next->next != nullptr)
        {
            second_last_node = second_last_node->next;
        }
        delete_next_node(second_last_node);
    }

    void delete_at(const size_t &index)
    {
        if (head == NULL)
        {
            return;
        }
        if (index == 0ULL)
        {
            return delete_first_element();
        }

        Node<T> *prev_node = head;

        for (size_t i = 1; i < index; ++i)
        {
            prev_node = prev_node->next;
        }
        delete_next_node(prev_node);
    }

    void delete_element(const T &key)
    {
        if (empty())
        {
            return;
        }

        auto equal = []<typename V>(const V &data, const V &key)
        {
            const double PRECISION = 1e-2;
            return (std::is_floating_point_v<V>)
                       ? fabs(data - key) < PRECISION
                       : data == key;
        };

        if (equal(head->data, key))
        {
            return delete_first_element();
        }

        Node<T> *prev_node = head;

        while (prev_node->next != nullptr && !equal(prev_node->next->data, key))
        {
            prev_node = prev_node->next;
        }

        if (prev_node->next == nullptr)
        {
            return;
        }
        delete_next_node(prev_node);
    }

    void display()
    {
        Node<T> *current = head;
        while (current != NULL)
        {
            std::cout << current->data << "-> ";
            current = current->next;
        }
        std::cout << "\b\b\b  \b\b";
        delete current;
        current = nullptr;
    }

private:
    void delete_next_node(Node<T> *prev_node)
    {
        Node<T> *node = prev_node->next;
        prev_node->next = node->next;
        --size;
        free_memory(node);
    }

    void free_memory(Node<T> *node)
    {
        delete node;
        node = nullptr;
    }
};

template <typename T>
bool detect_loop(const Linked_List<T> &linked_list)
{
    Node<T> *current = linked_list.get_head();
    Node<T> *temp = new Node<T>;

    while (current != NULL)
    {
        if (current->next == nullptr)
        {
            return false;
        }
        if (current->next == temp)
        {
            return true;
        }

        Node<T> *next = current->next;
        current->next = temp;
        current = next;
    }
    return false;
}

int main()
{
    using namespace std;

    Linked_List<int> integers;

    integers.push(-1);
    for (size_t index = 0; index <= 5; ++index)
    {
        integers.push_back(index);
    }

    Node<int> *h = integers.get_head();

    h->next->next->next->next->next->next->next = h->next->next->next;

    detect_loop(integers)
        ? cout << "Loop is present\n"
        : cout << "Loop is not present\n";

    getch();
    return 0;
}