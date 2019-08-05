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
        return cur_snap_id++;
    }

    int get(int index, int snap_id) {
        if(index >= size)
        {
            std::cout << "get failed\n";
            return -1;
        }

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

    void print()
    {
        for(int i = 0; i < cur_snap_id; ++i) 
        {
            
        }
    }

};













int main() 
{
    {
        SnapshotArray* arr = new SnapshotArray(3);
        std::cout << "setting 0 to 5\n";
        arr->set(0,5);
        std::cout << "snapshotting\n";
        int snap_now = arr->snap();
        std::cout << "at snap id: " << snap_now << " \\ arr[" << 0 << "] = " << arr->get(0, snap_now) << "\n";
        arr->set(1,5);
        std::cout << std::endl;
    }

    {
        SnapshotArray* arr = new SnapshotArray(4);
    }


}
