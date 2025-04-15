#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
public:
    char letter;
    bool is_word;
    vector<TrieNode*> children; // Can use hashmap.

    TrieNode(char l) : letter(l), is_word(false), children({}) {}
    // TODO: Implement destructore to avoid memory leaks.
};

// Pass node pointer by reference, as we need the modified pointer.
bool TraverseTrie(TrieNode*& node, string str) {
    for (auto letter : str) {
        bool found = false;
        for (auto child : node->children) {
            if (child->letter == letter) {
                node = child;
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        } 
    }
    return true;
}

bool HasPrefix(TrieNode* root, string str) {
    TrieNode* node = root;
    return TraverseTrie(node, str);
}

bool Search(TrieNode* root, string str) {
    TrieNode* node = root;
    // root will point to the last TrieNode after TraverseTrie().
    return (TraverseTrie(node, str) && node->is_word);
}

void Insert(TrieNode* root, string word) {
    TrieNode* node = root;
    for (auto letter : word) {
        bool found = false;
        for (auto child : node->children) {
            if (child->letter == letter) {
                node = child;
                found = true;
                break;
            }
        }
        if (!found) {
            TrieNode* new_node = new TrieNode(letter);
            node->children.push_back(new_node);
            node = new_node;
        }
    }
    node->is_word = true;
}

int main() {
    TrieNode* root = new TrieNode('\0');
    
    Insert(root, "apple");
    Insert(root, "app");
    Insert(root, "banana");
    Insert(root, "bat");

    cout << "HasPrefix 'appl': " << (HasPrefix(root, "appl") ? "Found" : "Not Found") << endl;
    cout << "HasPrefix 'apt': " << (HasPrefix(root, "apt") ? "Found" : "Not Found") << endl;
    cout << "HasPrefix 't': " << (HasPrefix(root, "t") ? "Found" : "Not Found") << endl;
    cout << "Search 'apple': " << (Search(root, "apple") ? "Found" : "Not Found") << endl;
    cout << "Search 'app': " << (Search(root, "app") ? "Found" : "Not Found") << endl;
    cout << "Search 'bat': " << (Search(root, "bat") ? "Found" : "Not Found") << endl;
    cout << "Search 'banana': " << (Search(root, "banana") ? "Found" : "Not Found") << endl;
    cout << "Search 'ban': " << (Search(root, "ban") ? "Found" : "Not Found") << endl;

    return 0;
}
