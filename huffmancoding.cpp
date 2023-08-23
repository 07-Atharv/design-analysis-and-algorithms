#include <bits/stdc++.h>
using namespace std;
// These is the single node structure in the huffman tree
struct Node
{
    // These is used to store the char
    char c;
    // These is used to store  the freq of each character
    int frq;
    // These is the child node for the current parent node
    Node *left, *right;
    // Making the constructor for assigning values for the each node
    Node(char c, int frq)
    {
        left = right = NULL;
        this->c = c;
        this->frq = frq;
    }
};

// These is used to compare the two heap nodes
struct Compare
{
    bool operator()(Node *left, Node *right)
    {
        // If left is greater and right is small then change will happen and return true
        return (left->frq > right->frq);
    }
};
// These isused to print the code for the string which has been valid
void printCode(struct Node *root, string str)
{
    // If root is null then reuturn true
    if (root == NULL)
    {
        return;
    }
    // If char is $ then we will stop printing  the character
    if (root->c != '$')
    {
        cout << root->c << "=" << str << endl;
    }
    // Assign left side with 0
    printCode(root->left, str + "0");
    // Assign right side with 1
    printCode(root->right, str + "1");
}

void HuffmanCode(char data[], int frq[], int size)
{
    // These is newly created left right and top
    struct Node *left, *right, *top;
    // Priority queue with Node vector and custom comparator
    priority_queue<Node *, vector<Node *>, Compare> ms;
    // Push all the nodes in the min heap and comparator will arrange that according to foll constraint
    for (int i = 0; i < size; i += 1)
    {
        ms.push(new Node(data[i], frq[i]));
    }
    // Until the heap gets single element we will continue the merging the elements
    while (ms.size() > 1)
    {

        // Get the first min
        left = ms.top();
        ms.pop();

        // Get the Second min
        right = ms.top();
        ms.pop();
        // Add both and make the internal node
        top = new Node('$', left->frq + right->frq);
        // Make the left and right which are used for creating the internal node and internal node as the parent
        top->left = left;
        top->right = right;
        // Push the node in the heap for further calculations
        ms.push(top);
    }
    // After completing all the tree we will push the top and the variable length code is assigned to the each char from top to bottom
    printCode(ms.top(), "");
}
int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCode(arr, freq, size);

    return 0;
}