// leetcode: ihttp://www.cplusplus.com/reference/set/multiset/
// Andy Tseng

#include <multiset>
#include <iostream>


class MedianFinder
{
    public:
        MedianFinder() {}

        // O(logn)
        void addNum(int num)
        {
            if (data.size() == 0)
            {
                data.insert(num);
                median_ptr = data.begin();
                flag = 0;
            }
            else
            {
                // there are more of them
                if (flag == 0)
                {
                    if (num <= *median_ptr)
                    {
                        
                    }

                }
                else
                {

                }
            }
        }

        // O(1)
        double findMedian()
        {
            return 0.0; 
        }
    private:
        std::multiset<int> data;
        std::multiset<int> :: iterator median_ptr;
        unsigned int flag;

};

int main()
{
    MedianFinder _mf;
    _mf.addNum(1);
    _mf.addNum(10);
    std::cout << _mf.findMedian() << std::endl;
    _mf.addNum(5);
    std::cout << _mf.findMedian() << std::endl;
}
