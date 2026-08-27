#include <iostream>
using namespace std;

struct Node {
  int key;
  int count;
  struct Node* next; 

  Node (int val) : key(val), count(1), next(nullptr) {}
};

class HashMap {
private:
  static const int TABLE_SIZE = 4001;
  Node* table[TABLE_SIZE];

  int hashFunction(int key) {
    return (key % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE;
  }

public:
  HashMap() {
    for (int i = 0; i < TABLE_SIZE; i++) {
      table[i] = nullptr;
    }
  }

  ~HashMap() {
    for (int i = 0; i < TABLE_SIZE; i++) {
      Node* x = table[i];
    
      while(x != nullptr) {
        Node* temp = x;
        x = x->next;
        delete(temp);
      }
    }
  } 

  void increment(int key) {
    int idx = hashFunction(key); 
    Node* x = table[idx];

    while(x != nullptr) {
      if (x->key == key) {
        x->count++;
        return;
      }
      x = x->next;
    }

    Node* z = new Node(key);
    z->next = table[idx];
    table[idx] = z;
  }

  void print() {
    for(int i = 0; i < TABLE_SIZE; i++) {
      Node* x = table[i];

      while (x != nullptr) {
        cout << x->key << " aparece " << x->count << " vez(es)\n";
        x = x->next;
      }
    }
  }
};



int main() {
  HashMap dict;
  int n, x; 

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> x; 
    dict.increment(x);
  }
  
  dict.print();

  return 0;
}
