#include <vector>
#include <list>
#include <iostream>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
using namespace std;
// Iterators
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int>::iterator it = v.begin();
    it++;
    cout << *(it) << " ";
    // here it will print 2
    vector<int>::iterator it = v.end();
    // here it will point out element afer last element.

    // These are very rarely used.
    //  vector<int>::iterator it = v.rend();
    //  vector<int>::iterator it = v.rbegin();

    // Accessing the first element using at()
    cout << "First element using at(): " << v.at(0) << endl;

    // Accessing the first element using []
    cout << "First element using []: " << v[0] << endl;
    // v.at(0) and v[0] return the first element of the vector, which is 10. However, if you try to access an index out of bounds (e.g., v.at(10) when the vector has only 3 elements), v.at(10) will throw an exception, while v[10] will lead to undefined behavior.
    cout << v.back() << " "; // it will print last element
    // How to print vector
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }
    // let make the syntax bit easy , we will be using auto here.It will automatically auto assign the datatype based on the data stored.
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it);
    }

    // using  for each for   printing vector
    for (auto it : v)
    {
        cout << it << " ";
    }

    // how deleting  vector actually happens

    //{10,20,30,40}
    v.erase(v.begin() + 1);
    // now it will erase the "20" and new array would be {10,20,30,40}

    // if we want to delete multiple elements then
    //{10,20,30,40,50,60 ,70 ,80}
    v.erase(v.begin() + 1, v.begin() + 3);
    // now it will erase the "20 and 30 ".new  vector arr would be {10,40,50,60,70,80}
    // In this we have to give start and  one more then the end. [start,end)

    // Insert function
    vector<int> v(2, 100);                         // {100,100}
    v.insert(v.begin(), 300);                      // {300,100,100}
    vector<int> copy(2, 50);                       // {50,50}
    v.insert(v.begin(), copy.begin(), copy.end()); //{50,50,300,100,100}
    // size
    //{10,20}
    cout << v.size(); // 2

    //{10,20}
    v.pop_back(); //{10}  will remove last  elemnent

    // v1 -> {10,20}
    // v2 -> {30,40}
    // v1.swap(v2)
    // then v2 -> {10,20} and v1 would be {30,40}
    v.clear(); // clear entire  vector
    cout << v.empty();
}
// list
void explainList()
{
    list<int> ls;
    ls.push_back(2);    //{2}
    ls.emplace_back(4); // {2,4}
    ls.push_front(5);   // {5,2,4} // pushfront is less costlier to insert in vector.
    ls.emplace_front(); //{2,4}
    // rest functions are same as vector
    // begin,end,rbgin,rend,clear,insert,size,swap
}
// dq
void explainDeque()
{
    deque<int> dq;
    dq.push_back(1);    //{1}
    dq.push_back(2);    //{2}
    dq.emplace_back(4); // {2,4}
    dq.push_front(5);   // {5,2,4} // pushfront is less costlier to insert in vector.
    dq.emplace_front(); //{2,4}
    // rest functions are same as vector
    // begin,end,rbgin,rend,clear,insert,size,swap
}
// stack is basically lifo which means "last in first out"
void explainStack()
{
    stack<int> st;
    st.push(1);        // {1}
    st.push(2);        //{2,1}
    st.push(3);        // {3,2,1}
    st.push(4);        // {4,3,2,1}
    st.emplace(5);     //{5,4,3,2,1}
    cout << st.top();  // print 5 ,  "st[2] is invalid here index based printing is not possible "
    cout << st.size(); // 4
    cout << st.empty();
    stack<int> st1, st2;
    st1.swap(st2);
}
// queue data strucuture but it follow fifo that is first in first out
void explainQueue()
{
    queue<int> q;
    q.push(1);    //{1}
    q.push(3);    //{1,3}
    q.push(4);    // {1,3,4}
    q.emplace(5); //{1,3,4,5}
    q.back() += 5;
    cout << q.back(); // print 9
    // q is {1,2,9}
    cout << q.front(); // print 1
    q.pop();
    // print 1 as it will pop first element
    cout << q.front(); // prints 2
    // size swap empty is same as stack
    // All the operation are happening in cosntant time
}

// Priority queue
// here data is saved based on maximum value
// It does n;t store linear data it store data in tree structure
// Maximun heap
void explainPQ()
{
    priority_queue<int> pq;
    pq.push(5);       // {5}
    pq.push(2);       // {5,2}
    pq.push(8);       // {8,5,2};
    pq.emplace(10);   // {10,8,5,2}
    cout << pq.top(); // prints 10
    pq.pop();         // {8,5,2};
    // size swap  empty functions same as others

    // Minimum heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5); // {5}
    pq.push(2); // {2,5}
    pq.push(8); // {2,5,8};
    pq.top();   //   it will target 2
    // time complexity of push and pop logn and top 0(1)
}

// set are sorted and unique
// here everything happen in logarithmic time complexity
void explainSet()
{
    set<int> st;
    st.insert(1);  // {1}
    st.emplace(2); //{1,2}
    st.insert(2);  // {1,2}
    st.insert(3);  //{1,2,3}
                   // functionality of inset in vector
    // can be  used  also ,that only increases
    // efficiency
    // begin() ,end(),swap( ),rebegin(),swap(),size()
    // empty and swap  are same as  those of above

    // {1,2,3,4,5}
    auto it = st.find(3); // it will return a iterator
    auto it = st.find(6); // if we  try to find something which is not in set then it will return the "st.end()"
                          // st.erase will work fine

    // count it will either have 1 or 0 as it is uniquq
    int cnt = st.count(3); // as count of "3" is 1
                           // range bound erase also works here suppose if we want to remove some element from one index to another

    // lower bound and upper bound functions works in same way as in vector
    // this is syntax
    auto it = st.lower_bound(2);
    auto it = st.upper_bound(3);
}

// Multiset
void explainMultiSet()
{
    // everything is same
    // only stores the  duplicate elements also
    multiset<int> ms;
    ms.insert(1); //{1}
    ms.insert(1); //{1,1}
    ms.insert(1); //{1,1,1}
    ms.insert(1); //{1,1,1,1}

    ms.erase(1); // all one  get erased
    int cnt = ms.count(1);
    ms.erase(ms.find(1)); // only single one is erased

    // ms.erase(ms.find(1), ms.find(1) + 2);
    //  will remove all element in  btw
    //  restt all are same
}

// unodered set
void explainUSet()
{
    unordered_set<int> st;
    // lower bound  and upper bound function does not work , rest all functions are same
    //  as above ,it does not stores  in any
    // particular  order  it has a better  complexity
    // than set  in most  cases ,except some when collision happens.
}

// map
void explainMap()
{
    // Map with integer keys and integer values
    map<int, int> mpp1; // Map where both key and value are integers
    mpp1[1] = 2;
    mpp1.insert({2, 4});
    mpp1.emplace(3, 1);

    // Map with integer keys and pair<int, int> values
    map<int, pair<int, int>> mpp2;
    mpp2[1] = {10, 20};
    mpp2.emplace(2, make_pair(30, 40));
    mpp2.insert({3, {50, 60}});

    // Map with pair<int, int> keys and integer values
    map<pair<int, int>, int> mpp3;
    mpp3[{1, 2}] = 10;
    mpp3[{2, 3}] = 20;
    mpp3.insert({{3, 4}, 30});
    // suppose the  map array is [{1,2} ,{3,4},{3,1}]
    for (auto it : mpp3)
    {
        //     cout << it.first << " " << it.second << endl ;

        // cout << mpp3[1]; //here it will print 2 and 1 corressponds to 2
        // auto it = mpp3.find(3);
        // cout << *(it).second; // it will answer 1
        // auto it = mpp3.find(5); //mpp3.end() as it is not present in the map array

        // //this is the syntax
        //  auto it =  mpp.lowerbound(2);
        //  auto it =  mpp.upper_bound(3);
        // erase,swap,size,empty  are same as above
    }
}