---
layout: mypost
title: "Design HashSet - Hashing using modulo"
tags: ["Array", "Hash Table", "Linked List", "Design", "Hash Function", "C++", "Easy"]
---
# Problem Statement:
<p>Design a HashSet without using any built-in hash table libraries.</p>

<p>Implement <code>MyHashSet</code> class:</p>

<ul>
	<li><code>void add(key)</code> Inserts the value <code>key</code> into the HashSet.</li>
	<li><code>bool contains(key)</code> Returns whether the value <code>key</code> exists in the HashSet or not.</li>
	<li><code>void remove(key)</code> Removes the value <code>key</code> in the HashSet. If <code>key</code> does not exist in the HashSet, do nothing.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;MyHashSet&quot;, &quot;add&quot;, &quot;add&quot;, &quot;contains&quot;, &quot;contains&quot;, &quot;add&quot;, &quot;contains&quot;, &quot;remove&quot;, &quot;contains&quot;]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
<strong>Output</strong>
[null, null, null, true, false, null, true, null, false]

<strong>Explanation</strong>
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // return False, (already removed)</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= key &lt;= 10<sup>6</sup></code></li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <code>add</code>, <code>remove</code>, and <code>contains</code>.</li>
</ul>

# Solution:
Here we use modulo operator as the hashing function and M is chosen to be a big enough prime.
 {% highlight cpp %} 
class Node {
    public:
    int val;
    Node *next;
    Node(int v, Node *n){val=v;next=n;}
};
class MyHashSet {
public:
    vector<Node *>nodes;
    int N;
    MyHashSet(int n=99991) {
        nodes = vector<Node *>(n,NULL);
        N = n;
    }
    
    void add(int key) {
        if (contains(key)) return;
        int h = key%N;
        if (nodes[h]==NULL) nodes[h]=new Node(key,NULL);
        else
        {
            Node *curr=nodes[h];
            while (curr->next!=NULL) curr=curr->next;
            curr->next=new Node(key,NULL);
        }
    }
    
    void remove(int key) {
        if (!contains(key)) return;
        int h=key%N;
        if (nodes[h]->val==key) 
        {
            nodes[h]=nodes[h]->next;
            return;
        }
        Node *curr=nodes[h];
        while (curr->next!=NULL && curr->next->val!=key) curr=curr->next;
        curr->next = curr->next->next;
    }
    
    bool contains(int key) {
        int h=key%N;
        if (nodes[h]==NULL) return false;
        Node *curr=nodes[h];
        while (curr!=NULL) 
        {
            if (curr->val==key) return true;
            curr=curr->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
 {% endhighlight %}