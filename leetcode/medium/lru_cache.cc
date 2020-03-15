// LRU Cache Implementation


// keep track of current capacity
// put - remove pointer from Linked List - add new value at the end, evicting form map is O(1)
// get - O(1) Unordered_map


#include <list>
#include <unordered_map>
#include <iostream>

using namespace std;

// redo
class LRUCache 
{
private:
    int cap;
    int cur;
    list<int> eviction_queue;
    unordered_map<int, std::pair<int, list<int>::iterator>> data;

public:
    LRUCache(int capacity) : cap(capacity), cur(0) {}

    int get(int key)
    {
        if (data.find(key) != data.end())
        {
            eviction_queue.erase(eviction_queue.begin());
            auto it = eviction_queue.insert(eviction_queue.end(), data[key].first);
            data[key].second = it;
            return data[key].first;
        } 
        return -1;
    }

    void put(int key, int value)
    {
        if (cur == cap)
        {
            // evict someone
            auto it = eviction_queue.begin();
            data.erase(*it);
            eviction_queue.erase(eviction_queue.begin());
            cur--;
        }
        // do the adding/setup
        auto it = eviction_queue.insert(eviction_queue.end(), value);
        data[key] = std::pair<int, list<int>::iterator>(value, it);
        cur++;
    }

};

int main()
{
    LRUCache _cache(2);
    _cache.put(1,1);
    _cache.put(2,2);
    std::cout << "get(1) = " << _cache.get(1) << std::endl;
    _cache.put(3,3);
    std::cout << "get(2) = " << _cache.get(2) << std::endl;
    _cache.put(4,4);
    std::cout << "get(1) = " << _cache.get(1) << std::endl;
    std::cout << "get(3) = " << _cache.get(3) << std::endl;
    std::cout << "get(4) = " << _cache.get(4) << std::endl;
}




