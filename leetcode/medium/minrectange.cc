// leetcode: 


#include <vector>
#include <iostream>

int min_area(vector<pair<int,int>> points) {
    unordered_map<int, vector<int>> x_list;
    unordered_map<int, vector<int>> y_list;
    int area = 40000;
    
    for(pair<int,int> p : points) {
        if(x_list.find(p.first) == x_list.end()) {
            x_list[p.first] = vector<int>();
        }
        if(y_lits.find(p.second) == y_list.end()) {
            y_list[p.second] = vector<int>();
        }


        x_list[p.first].push_back(p.second);
        y_list[p.second].push_back(p.first);

    }

    auto it = x_list.begin();
    while(it != x_list.end()) {
        ++it;
    }
}


int main() {


}
