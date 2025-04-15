#include <iostream>
using namespace std; // use std namespace

/******************************* char & string ********************************/
#include <string>
#include <sstream>

char c = 'a';
char* char_ptr = "abc";
char char_arr[] = "abc";

string str = "abc";
string str2("def");                           // string using constructor
string str3(n, c);                            // constructs string with n (int) characters of c
string str4(char_arr);                        // constructs string from char array
string str5(char_ptr);                        // constructs string from char pointer 

char c = str[i];                              // random char access
size_t str_size = str.size();                 // returns string size, same as str.length()
bool is_empty = str.empty();                  // checks if string is empty, returns bool

// returns position of first occurrence of "ab" in str, or string::npos if not found
// Time complexity: O(N)
size_t pos = str.find("ab");

// returns 0 if str == str2, 1 if str > str2, -1 if str < str2 lexicographically
// Time complexity: O(N)
int comp = str.compare(str2);

// Following functions return string and do not modify str
string subs = str.substr(start);              // [start, )
string subs = str.substr(start, len);         // [start, start + len - 1], complexity O(len)

// Following functions modify str and return a reference to the modified string
str.append(str2);                  // appends to str, same as str += str2, O(len of str2) 
str.append(str2, pos, len);        // appends length len to str from position pos
str.insert(pos, "sz");             // insert supplied characters from position pos (not after)
str.replace(pos, len, "abc");      // replaces substring starting from pos with the supplied string

#include <algorithm>
// Following functions modify str and return void
sort(str.begin(), str.end());                 // sorts string in ascending order, complexity O(NlogN)
sort(str.end(), str.begin());                 // sorts string in descending order
reverse(str.begin(), str.end());              // reverses the string, complexity O(N)
str.clear();                                  // removes all characters

// erase() returns an iterator pointing to the character immediately following the last character erased, 
// or str.end() if the last character was erased
str.erase();                                  // removes all characters
str.erase(pos);                               // erases substring starting from pos [pos, )
str.erase(pos, len);                          // erase length len starting from position pos

// Tokenization
string input = "abc,def,ghi";
istringstream ss(input);
string temp;
while (getline(ss, temp, ',')) {
    cout << temp << endl;                     // split string by comma
}

/******************************* int & modulus ********************************/
bool is_true = true;                          // boolean, 1 byte
// All integers are signed by default, use unsigned to make them unsigned
// eg., unsigned int, unsigned short, unsigned long
// All int types can be defined with intN_t or uintN_t, where N is the number of bits
// e.g., int8_t, int16_t, int32_t, int64_t, uint8_t, uint16_t, uint32_t, uint64_t
short s_num = 123;                            // short, 2 bytes, 2^16 values
int num = 123;                                // int, 4 bytes, 2^32 values
long l_num = 1234567890;                      // long, 4 or 8 bytes
long long ll_num = 1234567890123456789;       // long long, 8 bytes, 2^64 values
size_t size = str.size();                     // unsigned int type for object sizes
double d_num = static_cast<double>(num);      // cast int as double

// 0 <= rem < k and k * N + rem = num (if rem = 0, then num is divisible by k)
// If num < k, then num % k = num
int k = 10, rem = num % k;

/**************************** string/char <-> int *****************************/
string string_num = to_string(num);           // int -> string
int int_num = stoi(string_num);               // string -> int, complexity O(len of string_num)  

char char_digit = '5';
int int_digit = char_digit - '0';             // char -> int, + '0' to convert back 

char char_alpha = 'z';
int int_alpha = char_alpha - 'a';             // alphabetical char -> int [0, 25], + 'a' to convert back

bool is_digit = isdigit(c);                   // check if char is digit
bool is_alpha = isalpha(c);                   // check if char is alphabet

// Manually convert multi-digit string to int
string str_num = "12345";
int string_to_int(string& str_num) {
    int num = 0;
    for (auto digit : str_num) {
        num = num * 10;                       // shift the existing digits left
        num = num + (digit - '0');            // add the numeric value of the current digit
    }
    return num;
}

// Extracts digits from an int one by one
int num = 12345;
vector<int> extract_digits(int num) {
    vector<int> digits;
    while (num > 0) {
        int digit = num % 10;                 // extract the least significant digit
        digits.push_back(digit);              // add the extracted digit to the vector
        num = num / 10;                       // shift digits right eliminating the least significant digit
    }
    return digits;
}

/****************************** bit manipulation ******************************/
#include <bitset>
int bin_num = 0b101010;                       // binary literal, C++14 and later 
bitset<8> bin_num(num);                       // 8-bit binary representation of num

bool is_set = ((1 << i) & num) != 0;          // gets the i-th bit of num
int num = num | (1 << i);                     // sets the i-th bit of num to 1
int num = num & ~(1 << i);                    // clears the i-th bit of num to 0
int num = num ^ (1 << i);                     // toggles the i-th bit of num
bool is_even = (num & 1) == 0;                // nums is even if last bit is 0
// num - 1 flips all bits after the rightmost 1 in num, including the rightmost 1.
// If num is a power of 2, ie., has only one 1 bit, ANDing num with num - 1 yields 0.
bool is_power_of_2 = (num & (num - 1)) == 0;

/******************************* array & vector *******************************/
#include <vector>
int nums[26] = {0};                           // initializes a fixed-size array of 0's
vector<int> vec(&nums[0], &nums[25]);         // constructs a vector from an array
vector<int> v[10];                            // creates a fixed-size array of vectors

vector<int> v;                                // creates an empty, non-initialized vector
vector<int> v(s);                             // creates a vector of size s, initialized to 0's
vector<int> v(s, n);                          // creates vector with of size s, initialized to n's
vector<vector<int>> matrix;                   // creates an empty, non-initialized 2D matrix
vector<vector<int>> matrix(N, vector<int>(M));// creates a 2D matrix of N by M, initialized to 0's

int val = v[i];                               // random access
int val = v.front();                          // returns the first element
int val = v.back();                           // returns the last element

bool is_empty = v.empty();                    // checks if vector is empty, returns bool

// The following functions return void
v.push_back(num);                             // inserts num at the end, amortized complexity O(1)
v.pop_back();                                 // deletes the last element, complexity O(1)
v.clear();                                    // clears all elements
v.resize(num);                                // resize vector to length num
v.resize(num, val);                           // resize vector, padding with val (default is 0)

vector<int>::iterator itr = v.begin();        // return iterator pointing to first element
vector<int>::iterator end_itr = v.end();      // return iterator pointing to null behind last element
// The following functions modify the vector and return an iterator.
// Instead of pre-defining the iterator, v.begin() and v.end() can be used.
// The iterator can also be incremented or decremented using + and - operators,
// e.g. v.end() - 1 or v.begin() + 1
// The elements are shifted to the right or left appropriately.
v.insert(itr, num);                           // insert num at the position itr, complexity O(N)
v.insert(itr, 5, num);                        // insert 5 num's at position itr
v.erase(end_itr);                             // deletes the element at iterator
v.erase(it, end_it);                          // deletes elements in range [it, end_it), complexity O(N)

#include <algorithm>
#include <functional> // for greater<int>
sort(v.begin(), v.end());                     // sort vector in ascending order, complexity O(NlogN), non-stable sort
sort(v.end(), v.begin());                     // sort vector in descending order using iterator manipulation
sort(v.begin(), v.end(), greater<int>());     // sort vector in descending order using functor
// Custom sort using lambda function.
// Note the pass by reference to avoid copying, especially for large objects.
// Const can also be added to avoid modifying the original object.
sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {    
    return a.first < b.first;                 // if true, a comes before b (ascending order)
});

/****************************** map & set (hash tables) ***********************/
#include <unordered_map>
#include <map>
map<int, string> om;                          // O(logN) for insert/find/erase, uses a balanced tree data structure to keep elements sorted
unordered_map<int, string> m;                 // O(1) average for insert/find/erase, O(N) worst-case, unsorted
m = {{1, "one"}, {2, "two"}, {3, "three"}};   // initialize map

// The following access method creates the key value pair if it does not exist in the map.
// The value would be default construced, e.g. 0 for int, "" for string, etc...
string one = m[1];                            // key access using operator[]
m[4] = "four";                                // adds key/value pair using operator[]
m.insert({5, "five"});                        // adds key/value pair using insert()
unordered_map<int, string>::iterator itr = m.find(1); // returns iterator to key/value pair if found, or map.end() if not found
if (m.find(1) != m.end()) {                   // quickly checks if a key exists in the map
    cout << m[1] << endl;
}
m.erase(2);                                   // deletes by key, returns the number of elements erased, 0 or 1
m.erase(itr);                                 // deletes by iterator, returns iterator to the next element or map.end()
m.clear();                                    // clears all elements, returns void
size_t map_size = m.size();                   // returns size of map
bool is_empty = m.empty();                    // checks if map is empty

// Iterates through the map, processing key/value pairs. The iterator is pre-incremented
// for efficiency, post-incrementing creates a temporary copy of the iterator each time.
for (unordered_map<int, string>::iterator itr = m.begin(); itr != m.end(); ++itr) {
    cout << itr->first << ": " << itr->second << endl;
}
for (const auto& pair : m) {                  // C++11 and later, using range-based for loop
    cout << pair.first << ": " << pair.second << endl;
}
for (const auto& [k, v] : m) {                // C++17 and later, using structured binding
    cout << k << ": " << v << endl;
}

#include <unordered_set>
#include <set>
set<int> os;                                  // O(logN) for insert/find/erase, ordered
unordered_set<int> s;                         // O(1) average for insert/find/erase, O(N) worst-case, unordered
s = {1, 2, 3};                                // initialize set
s.insert(4);                                  // adds element to set
unordered_set<int>::iterator itr = s.find(1); // returns iterator to element if found, or set.end() if not found
s.erase(2);                                   // deletes element from set
s.erase(itr);                                 // deletes element using iterator
s.clear();                                    // clears all elements, returns void
size_t set_size = s.size();                   // returns size of set
bool is_empty = s.empty();                    // checks if set is empty

int val = 1;
// Useful for finding the smallest element that is greater than/greater than or equal to a value in an ordered set.
set<int>::iterator upper_itr = o_set.upper_bound(val); // returns an iterator to the first element > val
set<int>::iterator lower_itr = o_set.lower_bound(val); // returns an iterator to the first element >= val

// Custom comparator for ordered set using lambda function
auto node_cmp = [](Node* a, Node* b) {return a->val > b->val; }; // descending order
set<Node*, decltype(node_cmp)> node_set(node_cmp);

// Custom comparator for ordered set using struct
struct cmp {
    bool operator()(Node* a, Node* b) {
        return (a->val) < (b->val);           // ascending order
    }
};
set<Node*, cmp> node_set;

node_set.insert(new Node(1));                 // push new node to the custom set

/********************** stack, queue, heap, deque *****************************/
#include <stack>
stack<int> s;                                 // O(1) for push/pop/top
s.push(val);                                  // pushes element to the top of the stack
int top = s.top();                            // peeks the top of the stack
s.pop();                                      // pops the top element, returns void
bool is_empty = s.empty();                    // checks if stack is empty

#include <queue>
queue<int> q;                                 // O(1) for push/pop/front
q.push(val);                                  // pushes element to the end of the queue
int front = q.front();                        // peeks the front of the queue
q.pop();                                      // pops the front element, returns void
bool is_empty = q.empty();                    // checks if queue is empty

priority_queue<int> pq;                       // O(logN) for push/pop, O(1) for top, max heap by default
priority_queue<int, greater<int>> min_heap_pq;// min heap using functor
pq.push(val);                                 // pushes element to the heap
int top = pq.top();                           // peeks the top of the heap
pq.pop();                                     // pops the top element, returns void
bool is_empty = pq.empty();                   // checks if heap is empty

// Custom comparator for priority queue using lambda function
auto node_cmp = [](Node* a, Node* b) {return a->val > b->val}; // min heap
priority_queue<Node*, decltype(node_cmp)> node_pq(node_cmp); 

// custom comparator for priority queue using struct
struct cmp{
  bool operator()(Node* a, Node* b){
    return a->x < b->x;                       // max heap
  }
};
priority_queue<Node*, vector<Node*>, cmp> pq; // NOTE:  the format is different for sort function!!!

pq.push(new Node(1));                         // push new node to the custom heap

#include<deque>                               // O(1) for push/pop from both ends, O(1) for access
deque<int> dq(n);                             // creates a deque of size n, initialized to 0's
dq.push_back(val);                            // push to back
dq.push_front(val);                           // push to front   
int back = dq.back();                         // peeks the back of the deque
int front = dq.front();                       // peeks the front of the deque
dq.pop_back();                                // pops the back element, returns void
dq.pop_front();                               // pops the front element, returns void

/******************************* pair / tuple *********************************/
#include <utility>
pair<int, int> pr;                            // create empty pair
pr = {1, 3};                                  // generate pair using initializer list
pr = make_pair(1, 3);                         // generate pair using make_pair
int first = pr.first;                         // access first value
int second = pr.second;                       // access second value

#include <tuple>
tuple<int,char> tpl(9,'x');                   // tuple constructor
auto tpl = make_tuple("test", 2.1, 14, 'y');  // generate tuple using make_tuple
auto element = get<i>(tpl);                   // get i-th element of tuple
get<i>(tpl) = 2;                              // set i-th element of tuple

/******************************* rand / srand *********************************/
#include <cstdlib>                            // for rand() and srand()
#include <ctime>                              // for time()
srand(time(0));                               // Seed the random number generator
int random = rand();                          // generates a random number between 0 and RAND_MAX
int random = rand() % 100;                    // random number from [0, 100)
int random = (rand() % (b - a)) + a;          // random number from [a, b)

/*********************************** math *************************************/
#include <cmath>
double rounded = round(4.5);                  // round floating value to closest integer (4.5 -> 5)
int absolute = abs(-5);                       // absolute value (-5 -> 5)
int square_root = sqrt(64);                   // square root (64 -> 8)
int res = pow(2, 5);                          // 2^5


/*********************************** Node *************************************/
class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val) : val(val) {}
};

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val) {}
};

class TrieNode{
public:
    char ch; 
    bool isWord;
    TrieNode* next;
    TrieNode(char ch) : ch(ch), isWord(false) {}
};

/********************************* pointers ***********************************/
Node* p = new Node(x, y);                     // create a new node
p->x;                                         // access class members
p->print();                                   // access class member function