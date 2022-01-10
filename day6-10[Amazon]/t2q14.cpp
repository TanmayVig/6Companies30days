#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution
{
public:
    Node *mapfunc(Node *root, int t, map<Node *, Node *> &map)
    {
        if (root == NULL)
            return root;
        queue<Node *> q;
        q.push(root);
        Node *res;
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp->data == t)
                res = temp;
            if (temp->left != NULL)
            {
                q.push(temp->left);
                map[temp->left] = temp;
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
                map[temp->right] = temp;
            }
        }
        return res;
    }
    int minTime(Node *root, int target)
    {
        map<Node *, Node *> parent_map;
        Node *tar = mapfunc(root, target, parent_map);
        int t = 0;
        set<Node *> visited;
        queue<Node *> q;
        q.push(tar);
        visited.insert(tar);
        while (!q.empty())
        {
            // queue<Node*> temp;
            int sz = q.size();
            int fl = 0;
            while (sz--)
            {
                Node *top = q.front();
                q.pop();
                if (parent_map.count(top) == 1 && visited.find(parent_map[top]) == visited.end())
                {
                    fl = 1;
                    visited.insert(parent_map[top]);
                    q.push(parent_map[top]);
                }
                if (top->left != NULL && visited.find(top->left) == visited.end())
                {
                    fl = 1;
                    visited.insert(top->left);
                    q.push(top->left);
                }
                if (top->right != NULL && visited.find(top->right) == visited.end())
                {
                    fl = 1;
                    visited.insert(top->right);
                    q.push(top->right);
                }
            }
            if (fl)
                t++;
        }
        return t;
    }
};

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();
    }

    return 0;
}