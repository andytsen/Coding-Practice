#include <vector>
#include <unordered_map>
#include <iostream>

class SnapshotArray 
{
    std::unordered_map<int, std::vector<std::pair<int,int>> > m;
    int cur_snap_id = 0;
    int size;

public:
    SnapshotArray(int len) : size(len)
    {
        for(int i = 0; i < len; ++i)
            m[i] = std::vector<std::pair<int,int>>();
    }

    void set(int index, int val) {
        if(index >= size)
        {
            std::cout << "set failed\n";
            return;
        }
        std::cout << "setting arr[" << index << "] to " << val << "\n"; 
        m[index].push_back(std::pair<int,int>(cur_snap_id, val));
    }

    int snap() {
        std::cout << "snapshot called\n";
        return cur_snap_id++;
    }

    int get(int index, int snap_id) {
        if(index >= size)
        {
            std::cout << "get failed\n";
            return -1;
        }

        std::cout << "get(%d, %d) \n";

        // do binary search here
        int h = 0;
        int t = size;

        while (h < t) 
        {
            int mid = h + ((t - h) >> 1);
            int cur = m[index][mid].first;
            if (cur == snap_id) 
            {
                return m[index][mid].second;
            }
            else if(cur > snap_id) 
            {
                t = mid; 
            }
            else 
            {
                if (mid - 1 >= 0 && m[index][mid-1].first <= snap_id)
                {
                    return m[index][mid-1].second;
                } 
                else
                {
                    h = mid;
                }
            }
        }

        return 0;
    }  

    std::vector<int> getWhole(int snap_id)
    {
        std::vector<int> res;
        for(int index = 0; index < this->size; ++index)
        {
            res.push_back(get(index, snap_id));
        }
        return res;
    }
};













int main() 
{
    {
        std::cout << "Test 1 ~~~~ \n";
        SnapshotArray* arr = new SnapshotArray(3);
        arr->set(0,5);
        int snap_now = arr->snap();
        arr->set(1,5);
        std::cout << std::endl;
    }

    {
        std::cout << "Test 2 ~~~~ \n";
        SnapshotArray* arr = new SnapshotArray(4);
        arr->set(0,3);
        arr->set(2,5);
        int snap_now = arr->snap();
        
    }


}
