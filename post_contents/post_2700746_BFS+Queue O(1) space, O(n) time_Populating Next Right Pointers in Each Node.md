We will use a queue. The children of the level nodes are stored in queue. Then one by one we go over the queue. 
# Puzzle
Note that we are iterating in the queue in reverse in the line         `for (int i=Q.size()-1; i>=0; --i)`. Can you tell why?

# Code: 
 ```
Node* connect(Node* root) 
{
    if (!root) return NULL;
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *curr=NULL, *prev=NULL;
        for (int i=Q.size()-1; i>=0; --i)
        {
            curr = Q.front();
            if (prev) prev->next = curr;
            Q.pop();
            if (curr->left) Q.push(curr->left);
            if (curr->right) Q.push(curr->right);
            prev = curr;
        }
        curr->next = NULL;
    }
    return root;
}
```

Answer to puzzle is that because the queue size is increasing on the go, so we can not iterate forwards or else the loop will not end when we want it to end, so we must iterate in reverse.