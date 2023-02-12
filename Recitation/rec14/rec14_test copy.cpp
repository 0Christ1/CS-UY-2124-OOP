// rec14_test.cpp
// Haoran Chen

#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <string>      // task 21
#include <set>         // task 22
#include <map>         // task 23
using namespace std;

// 9. Write a function that is passed in a list of ints and prints the list using iterators
void func9(const list<int>& lst) {
//    for (list<int>::iterator iter = lst.begin(); iter != lst.end(); ++iter){
//        cout << *iter << ' ';
//    }
    for (list<int>::const_iterator iter = lst.begin(); iter != lst.end(); ++iter){
        cout << *iter << ' ';
    }
    cout << endl;
}

// 10. Repeat the previous task of printing the list, but this time instead of using iterators, use a ranged for.
void func10(const list<int>& lst) {
    for (int each: lst) {
        cout << each << ' ';
    }
    cout << endl;
}

// 11. write a function that will print every other item in the list using auto
void func11(const list<int>& lst) {
    for (auto iter = lst.begin(); iter != lst.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
}

// 12. Write a function to find an item in the list, returning an iterator for where it is
list<int>::const_iterator func12(const list<int>& lst, int n){
    for (list<int>::const_iterator iter = lst.begin(); iter!=lst.end(); ++iter) {
        if (*iter == n) {
            return iter;
        }
    }
    return lst.end();
}

// 13. modify the for loop to use auto. That works, great
auto func13(const list<int>& lst, int n) {
    for (auto iter = lst.begin(); iter != lst.end(); ++iter) {
        if (*iter == n) {
            return iter;
        }
    }
    return lst.end();
}

// 15. Use the algorithm find_if to locate the first even number in the vector and in the list and print them out.
bool func15(int n) {
    return n%2==0;
}

// 16. use a functor for the problem of defining the function to decide if an int is even
struct func16{
    bool operator() (int n) const {return n%2==0;}
};

// 19. Implement your own version of the find algorithm
list<int>::iterator ourFind(list<int>::iterator start, list<int>::iterator stop, int target){
    for (list<int>::iterator p = start; p!= stop; ++p){
        if (*p == target) {
            return p;
        }
    }
    return stop;
}

// 20. Rewrite ourFind as a function template.
template<typename T, typename U>
T ourFind(T start, T stop, U target){
    for (T p = start; p!= stop; ++p){
        if (*p == target) {
            return p;
        }
    }
    return stop;
}

int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
    vector<int> odd={9, 1, 7, 3, 5, 10};
    for (int each: odd) {
        cout << each << " ";
    }
    cout << "\n=======\n";

    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
    list<int> list_odd(odd.begin(), odd.end());
    for (int each: list_odd) {
        cout << each << " ";
    }
    cout << "\n=======\n";

    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    sort(odd.begin(), odd.end());
    for (int each: odd) {
        cout << each << ' ';
    }
    cout << "\n=======\n";

    // 4. print every other element of the vector.
    cout << "Task 4:\n";
    for (size_t i = 0; i < odd.size(); i+=2 ){
        cout << odd[i] << ' ';
    }
    cout << "\n=======\n";

    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
//    for (size_t i = 0; i < list_odd.size(); ++i) {
//        cout << list_odd[i] << ' ';
//    }
    cout << "\n=======\n";
    //
    // Iterators
    //

    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
    for (vector<int>::iterator iter = odd.begin(); iter < odd.end(); iter+=2) {
        cout << *iter << ' ';
    }
    cout << "\n=======\n";

    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
    for (list<int>::iterator iter = list_odd.begin(); iter != list_odd.end(); ++++iter){
        cout << *iter << ' ';
    }
    cout << "\n=======\n";

    // 8. Sorting a list
    cout << "Task 8:\n";
    list_odd.sort();
    for (int each: list_odd) {
        cout << each << ' ';
    }
    cout << "\n=======\n";

    // 9. Calling the function to print the list
    cout << "Task 9:\n";
    func9(list_odd);

    cout << "=======\n";

    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
    func10(list_odd);
    cout << "=======\n";

    //
    // Auto
    //

    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
    func11(list_odd);
    cout << "=======\n";

    
    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
    list<int>::const_iterator iter12 = func12(list_odd, 5);
    if (iter12 == list_odd.end()) {
        cout << "Not Found" << endl;
    } else {
        cout << *iter12;
    }
    cout << "=======\n";

    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
    auto iter13 = func13(list_odd, 5);
    if (iter13 == list_odd.end()) {
        cout << "Not Found" << endl;
    } else {
        cout << *iter13;
    }
    cout << "=======\n";

    //
    // Generic Algorithms
    //

    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    list<int>::iterator iter14 = find(list_odd.begin(), list_odd.end(), 5);
    if (iter14 != list_odd.end()) {
        cout << "Found the value: " << *iter14 << endl;
    }else {
        cout << "Not find" << endl;
    }
    cout << "=======\n";

    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    list<int>::iterator iter15 = find_if(list_odd.begin(), list_odd.end(),func15);
    if (iter15 != list_odd.end()) {
        cout << "Found the value: " << *iter15 << endl;
    }else {
        cout << "Not find" << endl;
    }
    cout << "=======\n";

    // 16. Functor
    cout << "Task 16:\n";
    list<int>::iterator iter16 = find_if(list_odd.begin(), list_odd.end(), func16());
    if (iter16 != list_odd.end()) {
        cout << "Found the value: " << *iter16 << endl;
    }else {
        cout << "Not find" << endl;
    }
    cout << "=======\n";
    
    // 17. Lambda
    cout << "Task 17:\n";
    list<int>::iterator iter17 = find_if(list_odd.begin(), list_odd.end(), [](int n){return n%2==0;});
    if (iter17 != list_odd.end()) {
        cout << "Found the value: " << *iter17 << endl;
    }else {
        cout << "Not find" << endl;
    }
    cout << "=======\n";

    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";
    int* arr = new int[odd.size()];
    copy(list_odd.begin(), list_odd.end(), arr);
    for (size_t i = 0; i < list_odd.size(); ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    int* ptr = find(arr, arr+list_odd.size(), 2);
    if (ptr != arr+list_odd.size()) {
        cout << "Found the value: " << *ptr << endl;
    } else {
        cout << "Not find" << endl;
    }
    delete[] arr;
    cout << "=======\n";

    //
    // Templated Functions
    //

    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
    list<int>::iterator iter19 = ourFind(list_odd.begin(), list_odd.end(), 2);
    if (iter19 != list_odd.end()) {
        cout << "Found the value: " << *iter19 << endl;
    }else {
        cout << "Not find" << endl;
    }
    cout << "=======\n";
    
    // 20. Implement find as a templated function
    cout << "Task 20:\n";
    list<int>::iterator iter20 = ourFind(list_odd.begin(), list_odd.end(), 5);
    if (iter20 != list_odd.end()) {
        cout << "Found the value: " << *iter20 << endl;
    }else {
        cout << "Not find" << endl;
    }
    cout << "=======\n";

    //
    // Associative collections
    //

    // 21. Using a vector of strings, print a line showing the number
    //     of distinct words and the words themselves.
    cout << "Task 21:\n";
    vector<string> vec;
    string token;
    ifstream ifs("pooh-nopunc.txt");
    if (!ifs) {cerr << "Not Found"; exit(1);}
    while (ifs >> token) {
        if (find(vec.begin(), vec.end(), token) == vec.end()) {
            vec.push_back(token);
        }
    }
    ifs.close();
    cout << "size: " << vec.size() << endl;
    for (size_t i = 0; i < vec.size(); ++i){
        cout << vec[i] << ' ';
    }
    cout << "\n=======\n";

    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";
    set<string> sets;
    string token2;
    ifstream ifs2("pooh-nopunc.txt");
    if (!ifs2) {cerr << "Not Found"; exit(1);}
    while (ifs2 >> token2) {
        sets.insert(token2);
    }
    ifs2.close();
    cout << "size: " << sets.size() << endl;
    for (const string& each: sets) {
        cout << each << endl;
    }
    cout << "=======\n";

    // 23. Word co-occurence using map
    cout << "Task 23:\n";
    map<string, vector<int>> maps;
    string token3;
    int index = 0;
    ifstream ifs3("pooh-nopunc.txt");
    if (!ifs3) {cerr << "Not Found"; exit(1);}
    while (ifs3 >> token3) {
        maps[token3].push_back(index);
        ++index;
    }
    ifs3.close();
    cout << "size: " << maps.size() << endl;
    for (const auto& m: maps) {
        cout << m.first << ", ";
        for (size_t i = 0; i < m.second.size(); ++i) {
            cout << m.second[i] << endl;
        }
    }
    cout << "=======\n";
}
