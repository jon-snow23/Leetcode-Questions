#include <vector>
#include <list>
#include <utility>

class MyHashMap {
private:
    const int size = 10000;
    std::vector<std::list<std::pair<int, int>>> hashMap;

public:
    MyHashMap() {
        // Initialize the vector of lists
        hashMap.resize(size);
    }

    void put(int key, int value) {
        int index = key % size;
        auto& list = hashMap[index];

        // Check if the key already exists, update the value
        for (auto& entry : list) {
            if (entry.first == key) {
                entry.second = value;
                return;
            }
        }

        // If key doesn't exist, add a new key-value pair
        list.emplace_back(key, value);
    }

    int get(int key) {
        int index = key % size;
        auto& list = hashMap[index];

        // Check if the key exists, return the corresponding value
        for (const auto& entry : list) {
            if (entry.first == key) {
                return entry.second;
            }
        }

        // If key not found, return -1
        return -1;
    }

    void remove(int key) {
        int index = key % size;
        auto& list = hashMap[index];

        // Find the key and remove the entry from the list
        list.remove_if([key](const std::pair<int, int>& entry) {
            return entry.first == key;
        });
    }
};



/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */