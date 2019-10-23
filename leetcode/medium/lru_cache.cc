// LRU Cache Implementation


// keep track of current capacity
// put - remove pointer from Linked List - add new value at the end, evicting form map is O(1)
// get - O(1) Unordered_map

// 3 -> 3
// 4 -> 4

#include <unordered_map>
#include <list>
#include <memory>
#include <iostream>

class lru_cache
{
    typedef std::list<std::pair<int,int>> node_list;
    
    int max_capacity = 0;
    int cur_capacity = 0;
    std::list<std::pair<int,int>> values;
    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> iter_map;

public:
    lru_cache(int capacity) : max_capacity(capacity) 
    {

    }

    ~lru_cache()
    {
        
    }

    void put(int key, int val)
    {
        if (cur_capacity == max_capacity)
        {
            iter_map[values.front().first] = values.end();
            values.erase(values.begin()); 
        }
        else 
        {
            cur_capacity++;
        }
        iter_map[key] = values.insert(values.end(), std::pair<int,int>(key,val));
    }

    int get(int key)
    {
        // get value from values list 
        // remove it from the list and put it in the front
        if(iter_map[key] == values.end())
        {
            return -1;
        }
        else 
        {
            values.erase(iter_map[key]);
            values.insert(values.end(), *iter_map[key]);
            return (*(iter_map[key])).second;
        }
    }

    void put_test_func(int key, int val)
    {
        std::cout << "put (" << key << "," << val << ")" << std::endl;
        put(key,val);
    }

    int get_test_func(int key)
    {
        int results =  get(key);
        std::cout << "get (" << key << ") >> "  << results << std::endl;
        return results;
    }
};

int main()
{
    lru_cache* inst = new lru_cache(3);

    inst->put_test_func(1,1);
    inst->put_test_func(2,2);
    inst->put_test_func(3,3);
    inst->get_test_func(2);
    inst->put_test_func(4,4);
    inst->get_test_func(1);
    inst->put_test_func(5,5);
    inst->get_test_func(3);
    inst->get_test_func(2);
    inst->get_test_func(4);
    inst->get_test_func(5);

    delete inst;
}
