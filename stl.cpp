#include <iostream>

// in built data structures
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>

// in built functions
#include <algorithm>

using namespace std;
// a helper module file for Standard template library briefing

void set_ds() {
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(4);

    s.insert(1); // only stores and prints unique value sized set
    cout << s.size() << endl;
}

void map_ds() {
    map<string, int> m;

    m["tv"] = 100;
    m["laptop"] = 10;
    m["headphones"] = 25;

    for(auto p: m) {
        cout << p.first << " " << p.second << " " << endl;
    }
}

void linked_list()
{
    list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_front(5);

    list<int> li = {12, 14, 15, 20};
    li.pop_back();
    li.pop_front();

    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;
}

void vector_prop()
{
    // vector - dynamic arrays
    vector<int> arr;
    int n = arr.size();

    arr.push_back(10);
    arr.push_back(20);

    arr.pop_back();
    arr.emplace_back();
    arr.clear();
}

void deque_data()
{
    deque<int> d = {1,2,3,4,5,6};

    d.push_back(10);
    // same functions as list

    // difference - list = doubly linkedlist, deque = dynamic arrays, list - no random access(indexing not possible), deque - random indexing
    cout << d[2] << endl;
}

void stack_ds() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    cout << s.size() << endl;
    
}

void queue_ds() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    cout << q.size() << endl;
}

void priority_queue_ds() {
    // heap ds - always sorts out and pops the greatest value
    
    priority_queue<int> q;
    q.push(1);
    q.push(20);
    q.push(3);
    q.push(14);
    q.push(7);

    while(!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}

void algorithms() {
    int arr[5] = {10,24,1,4,6};
    // ascending order by default
    sort(arr, arr+5);
    for(int v : arr) {
        cout << v << " ";
    } 
    cout << endl;

    // descending order
    sort(arr, arr+5, greater<int>());
    for(int v : arr) {
        cout << v << " ";
    } 
    cout << endl;


    // reverse function
    int my_arr[] = {1,2,3,4,5,6};
    reverse(my_arr, my_arr+6);
    for(int i : my_arr) {
        cout << i << " ";
    }
    cout << endl;


    //min, max, swap - already known inbuilt functions
    int i = min(3,4);
    int j = max(3,4);
    //swap
    int a = 5, b = 10;
    swap(a,b);

    // max_element, min_element - min max of arrays, vectors
    cout << *min_element(my_arr, my_arr+6) << endl;
}

int main()
{
    // vector_prop();
    // linked_list();
    //stack_ds();
    //queue_ds();
    //priority_queue_ds();
    //map_ds();
    //set_ds();

    algorithms();

    return 0;
}
