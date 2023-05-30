#ifndef MY_TREE_H
#define MY_TREE_H
#include<iostream>
#include <vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
template <class T>
struct Node {
    T data;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(T data) : data(data) {}
    // Add the constructors you want
};

template <class T>
class MyTree{
private:
    int size;
    int height;
    Node<T>* root;
    Node<T>*createBST(vector<T>v,int start,int end) {
        if (start > end)
            return nullptr;
        int mid;
        //calculating the mid
        if ((end-start+1) % 2 == 0) {
            //calculating the mid and choosing the second mid if the numbers are even
            mid = (start + end) / 2 + 1;
        }else {
            mid = (start + end) / 2;
        }
        Node<T> *newNode = new Node<T>(v[mid]);
        //creating nodes left of the root
        newNode->left = createBST(v, start, mid - 1);
       // calculating nodes right of the root
        newNode->right = createBST(v, mid + 1, end);
        return newNode;
    }

    bool isBstUtility(Node<T>*subRoot,int min,int max) {
        //base condition
        if (subRoot == nullptr)
            return true;
        if (subRoot->data < min || subRoot->data > max)
            return 0;
        return isBstUtility(subRoot->left, min, subRoot->data - 1) &&
               isBstUtility(subRoot->right, subRoot->data + 1, max);
    }
    //calculating the size of the tree
    int computeSize(Node<T>*node) {
        if (node == nullptr)
            return 0;
        return (computeSize(node->left) + 1 + computeSize(node->right));
    }
    //calculating the height of the tree
    int computeHeight(Node<T>*node) {
        if (node == nullptr)
            return -1;
        else {
            //computing height on left of the tree
            int lHeight = computeHeight(node->left);
            //calculating height on right of the tree
            int rHeight = computeHeight(node->right);
            //choosing the taller side
            if (lHeight > rHeight)
                return (lHeight + 1);
            else
                return (rHeight + 1);
        }
    }
    //utility function to traverse the tree in inorder traversal and storing the elements in a vector
    void utilityVectorInOrder(Node<T>*subRoot,vector<T>&a) {
        //base condition
        if (subRoot == nullptr)
            return;
        utilityVectorInOrder(subRoot->left,a);
        a.push_back(subRoot->data);
        utilityVectorInOrder(subRoot->right,a);

    }
   // utility function to traverse the tree in a preorder traversal
    void utilityVectorPreOrder(Node<T>*subRoot,vector<T>&a) {
        if (subRoot == nullptr)
            return;
        a.push_back(subRoot->data);
        utilityVectorPreOrder(subRoot->left,a);
        utilityVectorPreOrder(subRoot->right,a);
    }
    //utility function to traverse the tree in a postorder traversal
    void utilityVectorPostOrder(Node<T>*subRoot,vector<T>&a) {
        if (subRoot == nullptr)
            return;
        utilityVectorPostOrder(subRoot->left,a);
        utilityVectorPostOrder(subRoot->right,a);
        a.push_back(subRoot->data);
    }
    //utility function to traverse the tree iteratively in inorder traversal
    void utilityVectorInorderIterative(Node<T>*subRoot,vector<T>&a) {
        //creating a stack
        stack < Node<T> * > s;
        Node<T> *curr = subRoot;
        while (curr != nullptr || s.empty() == false) {
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            a.push_back(curr->data);
            curr = curr->right;
        }
    }
    void utilityVectorPreorderIterative(Node<T>*subRoot,vector<T>&a) {
        if (subRoot == nullptr)
            return ;
        stack < Node<T> * > s;
        s.push(subRoot);
        while (!s.empty()) {
            Node<T> *curr = s.top();
            s.pop();
            a.push_back(curr->data);
            if (curr->right) {
                s.push(curr->right);
            }
            if (curr->left) {
                s.push(curr->left);
            }
        }
    }
    void utilityVectorPostorderIterative(Node<T>*subRoot,vector<T>&a) {
        if (subRoot == nullptr)
            return;
        stack < Node<T> * > s1, s2;
        s1.push(subRoot);
        Node<T> *curr;
        while (!s1.empty()) {
            curr = s1.top();
            s1.pop();
            s2.push(curr);
            if (curr->left)
                s1.push(curr->left);
            if (curr->right)
                s1.push(curr->right);
        }
        while (!s2.empty()) {
            curr = s2.top();
            s2.pop();
            a.push_back(curr->data);
        }
    }
    void clearTree(Node<T>*&subRoot) {
        if (subRoot != nullptr) {
            clearTree(subRoot->left);
            clearTree(subRoot->right);
            delete subRoot;
            subRoot = nullptr;
        }
    }

    void insert2(Node<T>*subRoot,int key){
        if(subRoot== nullptr)
            Node<T>*newNode=new Node<T>(key);
        if(subRoot->data>key)
            subRoot->right=insert(subRoot->right,key);
        else if(subRoot->data>key)
            subRoot->left=insert(subRoot->left,key);
    }

    Node<T>*minValueNode(Node<T>*node){
        Node<T>*current=node;
        while(current&&current->left!= nullptr)
            current=current->left;
        return current;
    }
    Node<T>*deleteUtility(Node<T>*subRoot,const Node<T>*node){
        if(subRoot== nullptr)
            return subRoot;
        if(node->data<subRoot->key) {
            subRoot->left = deleteUtility(subRoot->left, node->data);
        }
        else if(node->data>subRoot->key){
            subRoot->right= deleteUtility(subRoot->right,node->data);
        }
        else {
            if (subRoot->left == nullptr && subRoot->right == nullptr)
                return nullptr;
            else if (subRoot->left == nullptr) {
                Node<T> *temp = subRoot->right;
                delete subRoot;
                return temp;
            } else if (subRoot->right == nullptr) {
                Node<T> *temp = subRoot->left;
                delete subRoot;
                return temp;
            }
            Node<T> *temp = minValueNode(subRoot->right);
            subRoot->data = temp->data;
            subRoot->right = deleteUtility(subRoot->right, temp->data);
            return subRoot;
        }

    }
public:
    MyTree() {
        root = nullptr;
        size = 0;
        height = 0;
    }

    MyTree(std::vector<T> elements) {
        sort(elements.begin(), elements.end());
        root = createBST(elements, 0, elements.size() - 1);

    }

    void insert(T key) {
        Node<T> *newNode = new Node<T>(key);
        Node<T> *temp = root;
        Node<T> *prev = nullptr;
        while (temp) {
            prev = temp;
            if (key < temp->data) {
                temp = temp->left;
            } else
                temp = temp->right;
        }
        if (prev == nullptr) {
            prev = newNode;  root=newNode;
        }
        else if (key < prev->data) {
            prev->left = newNode;
        } else
            prev->right = newNode;


    }

    void insert(const Node<T> node) {
        Node<T> *temp = root;
        Node<T> *prev = nullptr;
        if (temp == nullptr)
            prev = node;
        while (temp) {
            prev = temp;
            if (node.data < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if (node.key < prev->data) {
            prev->left = node;
        } else
            prev->right = node;

    }

    const Node<T>* search(T key) {
        Node<T> *temp = root;
        if (temp == nullptr)
            return 0;
        while (temp) {
            if (temp->data == key)
                break;
            if (temp->data < key) {
                temp = temp->right;
            } else
                temp = temp->left;
        }
        return temp;

    }

    const Node<T>* delete_node(T key) {
        Node<T> *temp = root;
        Node<T> *prev = nullptr;
        while (temp && temp->data != key) {
            prev = temp;
            if (key < temp->data) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        //check again
        if (temp == nullptr) {
            return root;
        }
        if (temp->left == nullptr || temp->right == nullptr) {
            Node<T> *store_deleted;
            if (temp->left == nullptr)
                store_deleted = temp->right;
            else
                store_deleted = temp->left;
            if (prev == nullptr) {
                return store_deleted;
            }
            if (temp == prev->left)
                prev->left = store_deleted;
            else
                prev->right = store_deleted;
            delete temp;
        }
        else {
            Node<T> *p = nullptr;
            Node<T> *t;
            t = temp->right;
            while (t->left != nullptr) {
                p = t;
                t = t->left;
            }
            if (p != nullptr)
                p->left = t->right;
            else
                temp->right = t->right;
            temp->data = t->data;
            delete t;
        }
        return root;

    }

    const Node<T>* delete_node(const Node<T> node) {
        deleteUtility(root, node);

    }

    bool isBST() {
        return isBstUtility(root, INT32_MIN, INT32_MAX);
    }

    std::vector<T> inorder_rec() {
        vector <T> a;
        utilityVectorInOrder(root,a);
        return a;
    }

    std::vector<T> preorder_rec() {
        vector <T> a;
        utilityVectorPreOrder(root,a);
        return a;
    }

    std::vector<T> postorder_rec() {
        vector <T> a;
        utilityVectorPostOrder(root,a);
        return a;
    }

    std::vector<T> inorder_it() {
        vector <T> a;
        utilityVectorInorderIterative(root,a);
        return a;
    }

    std::vector<T> preorder_it() {
        vector <T> a;
        utilityVectorPreorderIterative(root,a);
        return a;
    }

    std::vector<T> postorder_it() {
        vector <T> a;
        utilityVectorPostorderIterative(root,a);
        return a;
    }

    std::vector<T> breadth_traversal() {
        vector <T> a;
        if (root == nullptr)
            return a;
        queue < Node<T> * > q;
        q.push(root);
        while (!q.empty()) {
            Node<T> *current = q.front();
            a.push_back(current->data);
            q.pop();
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
            height++;
        }
        return a;
    }

    int get_size() {
        //calculating the size
        return computeSize(root);
    }

    int get_height() {
        //calculating the height
        return computeHeight(root);
    }

    void clear() {
        //clearing the tree
        clearTree(root);
    }

    ~MyTree() {
        delete root;
        root= nullptr;
    }
};

#endif