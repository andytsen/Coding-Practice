
#include <vector>
#include <iostream>

using namespace std;


struct node {
    int data;
    node* next;

    node(int v) : data(v), next(nullptr) {}

};


node* foo(vector<int>& arr) {
    if(arr.size() == 0) return nullptr;
    node* front = new node(arr[0]);;
    node* back = front;

    for(int i = 1; i < arr.size(); ++i) {
        node* n = new node(arr[i]);
        if(arr[i] % 2 == 0) {
            back->next = n;  
            back = n;
        } else {
            n->next = front;
            front = n;
        }
    }
    return front;
}


vector<int>& foo2(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while(left < right) {
        if(arr[left] % 2 == 0) {
            if(arr[right] % 2 == 1) {
                swap(arr[left], arr[right]);
                left++;
            }     
            right--;
        }
        else {
            if(arr[right] % 2 == 0) {
                left++;
            }
            right--;
        }
    } 


    return arr;
}




int main() {

    vector<int> v1 = {1,2,3,6,8};
    v1 = foo2(v1);
    for(int i : v1) cout << i << " ";
    cout << endl;

    vector<int> v2 = {10,2,4,6,8};
    v2 = foo2(v2);
    for(int i : v2) cout << i << " ";
    cout << endl;

    vector<int> v3 = {1,7,6,3,8,12};
    v3 = foo2(v3);
    for(int i : v3) cout << i << " ";
    cout << endl;


}
