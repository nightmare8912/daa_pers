#include <iostream>
using namespace std;

struct node
{
    char data;
    bool isProcessed;
    int freq;
    node *left, *right, *quNext;
};

class queue
{
public:
    node *head;
    queue() { head = NULL; }

    node *createNode(char data, int freq)
    {
        node *newnode = new node;
        newnode->data = data;
        newnode->left = newnode->right = NULL;
        newnode->quNext = NULL;
        newnode->freq = freq;
        
        return newnode;
    }

    void enqueue(node *newnode)
    {
        newnode->quNext = head;
        head = newnode;
    }

    int unprocessedCount()
    {
        int unp = 0;
        for (node *temp = head; temp != NULL; temp = temp->quNext)
        {
            if (temp->isProcessed == false)
                unp++;
        }
        return unp;
    }
    
    void print()
    {
        for (node *temp = head; temp != NULL; temp = temp->quNext)
            cout << temp->data << " : " << temp->freq << endl; 
    }

    node *extractMin()
    {
        node *minNode = new node;
        minNode->freq = 999999;
        for (node *temp = head; temp != NULL; temp = temp->quNext)
        {
            if (temp->isProcessed == false && temp->freq < minNode->freq)
                minNode = temp;
        }
        minNode->isProcessed = true;
        return minNode;
    }
};

class huffman
{
public:
    node *root;
    queue q;
    huffman(queue q)
    {
        root = NULL;
        this->q = q;
    }

    void preorder(node *temp)
    {
        if (temp == NULL)
            return;
        cout << "(" <<temp->data << " " << temp->freq << ") ";
        preorder(temp->left);
        preorder(temp->right);
    }   

    void printRes(node *temp, string res)
    {
        if (temp->left == NULL && temp->right == NULL)
        {
            cout << "(" <<temp->data << " " << res << ") ";
            return;
        }  
        printRes(temp->left, res + "0");
        printRes(temp->right, res + "1");
    }

    void buildHuffmanTree()
    {
        for (node *temp = q.head; temp != NULL; temp = temp->quNext)
            temp->isProcessed = false;
            
        while(q.unprocessedCount() != 1)
        {
            node *min1 = q.extractMin();
            node *min2 = q.extractMin();
            cout << min1->data << " " << min2->data << endl;
            node *newnode = new node;
            newnode->data = '*';
            newnode->left = min1;
            newnode->right = min2;
            newnode->freq = min1->freq + min2->freq;
            newnode->isProcessed = false;
            q.enqueue(newnode);
        }
        root = q.extractMin();
        preorder(root);
        cout << "\n\nResults\n\n";
        printRes(root, "");
    }
};

int main()
{
    int n;
    queue q;
    cout << "Enter number of characters: ";
    cin >> n;
    for (int i = 0; i < n; i++)
        q.enqueue(q.createNode(rand() % 26 + 65, rand() % 10));
    q.print();
    huffman h(q);
    h.buildHuffmanTree();   
}