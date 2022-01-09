#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class LRUCache
{
public:
    struct Node
    {
        int key, val;
        Node *prev, *next;

        Node() : key(-1), val(-1), prev(nullptr), next(nullptr) {}
        Node(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr) {}
    };

    unordered_map<int, Node*> _hash;
    Node *head = new Node(), *tail = new Node();
    int size = 0;
    LRUCache(int capacity)
    {
        size = capacity;
        _hash = unordered_map<int, Node*>();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
       if (_hash.count(key) == 0) return -1;
       else {
           Node *curr = _hash[key];
           _delete(curr);
           _push_back(curr);
           return curr->val;
       }
    }

    void put(int key, int value)
    {
        
        Node *curr; 
        if (_hash.count(key) == 0) {
            curr = new Node(key, value);
            _hash[key] = curr;
            if (_hash.size() > size) {
                Node *tmp = head->next;
                _delete(tmp);
                _hash.erase(tmp->key);
                delete tmp;
            }   
            
        } else {
            curr = _hash[key];
            curr->val = value;
            _delete(curr);
        }

        
        _push_back(curr);
    }

    void _delete(Node* curr) {
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
    }

    void _push_back(Node* curr) {
        tail->prev->next = curr;
        curr->prev = tail->prev;
        curr->next = tail;
        tail->prev = curr;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
    }
    return 0;
}