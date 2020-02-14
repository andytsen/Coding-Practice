// priority queue
// add O(logN)
// find O(1)

#include <list>
#include <priority_queue>
#include <iostream>

class MedianFinder
{
    private:
        std::priority_queue<int> data;
        std::priority_queue<int>::iterator medium_ptr;
        bool flag; // tells us if its odd or not
    public:
        MedianFinder() : flag(0) 
        {
        }

        void addNum(int num) 
        {
            if(data.size() == 0)
            {
                data.push_back(num); 
                medium_ptr = data.front();
                flag = 1;
            }
            else {
                if (*medium_ptr > num)
                {
                     

                }
            }

        }

        double findMedian() 
        {

        }
}


int main()
{
    MedianFinder mf;
    mf.addNum(2);
    mf.addNum(3);
    mf.addNum(4);
    std::cout << mf.findMedian() << std::endl;
    return 0;
}
