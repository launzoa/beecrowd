#include <bits/stdc++.h>
using namespace std;

class BST {
  private: 
    struct Node {
      int key;
      Node* left;
      Node* right;

      Node(int val) : key(val), left(nullptr), right(nullptr) {}
    };
  
  Node* root;

    void pre_order(Node* x) {
      if (x == nullptr) return ; 

      cout << " " << x->key;
      pre_order(x->left);
      pre_order(x->right);
    }

    void in_order(Node* x) {
      if (x == nullptr) return ; 

      in_order(x->left);
      cout << " " << x->key;
      in_order(x->right);
    }

    void pos_order(Node* x) {
      if (x == nullptr) return ;
      pos_order(x->left);
      pos_order(x->right);
      cout << " " << x->key;
    }

    void destroy(Node* x) {
      if (x == nullptr) return ;
      destroy(x->left);
      destroy(x->right);
      delete x;
    }

  public: 
    BST() : root (nullptr) {}

    ~BST() {
      destroy(root);
    }

    void insert(int val) {
      Node* x = this->root;  
      Node* y = nullptr;

      while (x != nullptr) {
        y = x;
        if (val < x->key) {
          x = x->left;
        }
        else {
          x = x->right;
        }
      }

      Node* z = new Node(val);

      if (y == nullptr) {
        this->root = z;
      }
      else if (z->key < y->key) {
        y->left = z;
      }
      else {
        y->right = z;
      }
    }
    
    void print_pre_order(){ 
      pre_order(root);
      cout << "\n";
    }

    void print_in_order() {
      in_order(root);
      cout << "\n";
    }

    void print_pos_order(){ 
      pos_order(root);
      cout << "\n";
    }
};

int main() {

  int c;

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  if(!(cin >> c)) return 0; 

  for(int i = 1; i <= c; i++) {
    int n;
    BST bst; 

    cin >> n;  
    vector<int> a(n);

    for (int j = 0; j < n; j++) {
      cin >> a[j];
    }

    for (int j = 0; j < n; j++) {
      bst.insert(a[j]);
    }

    cout << "Case " << i << ":\n";
    cout << "Pre.:";
    bst.print_pre_order(); 
    cout << "In..:";
    bst.print_in_order();
    cout << "Post:"; 
    bst.print_pos_order();
    cout << "\n";
  } 

  return 0;
}


