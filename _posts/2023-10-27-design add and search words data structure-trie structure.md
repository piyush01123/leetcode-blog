---
layout: mypost
title: "Design Add and Search Words Data Structure - Trie structure"
tags: ["String", "Depth-First Search", "Design", "Trie", "C++", "Medium"]
---
# Problem Statement:
<p>Design a data structure that supports adding new words and finding if a string matches any previously added string.</p>

<p>Implement the <code>WordDictionary</code> class:</p>

<ul>
	<li><code>WordDictionary()</code>&nbsp;Initializes the object.</li>
	<li><code>void addWord(word)</code> Adds <code>word</code> to the data structure, it can be matched later.</li>
	<li><code>bool search(word)</code>&nbsp;Returns <code>true</code> if there is any string in the data structure that matches <code>word</code>&nbsp;or <code>false</code> otherwise. <code>word</code> may contain dots <code>&#39;.&#39;</code> where dots can be matched with any letter.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example:</strong></p>

<pre>
<strong>Input</strong>
[&quot;WordDictionary&quot;,&quot;addWord&quot;,&quot;addWord&quot;,&quot;addWord&quot;,&quot;search&quot;,&quot;search&quot;,&quot;search&quot;,&quot;search&quot;]
[[],[&quot;bad&quot;],[&quot;dad&quot;],[&quot;mad&quot;],[&quot;pad&quot;],[&quot;bad&quot;],[&quot;.ad&quot;],[&quot;b..&quot;]]
<strong>Output</strong>
[null,null,null,null,false,true,true,true]

<strong>Explanation</strong>
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord(&quot;bad&quot;);
wordDictionary.addWord(&quot;dad&quot;);
wordDictionary.addWord(&quot;mad&quot;);
wordDictionary.search(&quot;pad&quot;); // return False
wordDictionary.search(&quot;bad&quot;); // return True
wordDictionary.search(&quot;.ad&quot;); // return True
wordDictionary.search(&quot;b..&quot;); // return True
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 25</code></li>
	<li><code>word</code> in <code>addWord</code> consists of lowercase English letters.</li>
	<li><code>word</code> in <code>search</code> consist of <code>&#39;.&#39;</code> or lowercase English letters.</li>
	<li>There will be at most <code>2</code> dots in <code>word</code> for <code>search</code> queries.</li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <code>addWord</code> and <code>search</code>.</li>
</ul>

# Solution:
We use the standard Trie data structure. We modify the `search` method to handle the case when the search term contains `.`.

 {% highlight cpp %} 
class Trie
{
    vector<Trie*> children;
    bool isEnd;
public:
    Trie(){children = vector<Trie*>(26,NULL); isEnd=false;}
    void add(string word, int index)
    {
        if (index==word.length()) {isEnd=true; return;}
        int pos = word[index]-'a';
        if (children[pos]==NULL) children[pos] = new Trie();
        children[pos]->add(word, index+1);
    }
    bool search(string word, int index)
    {
        if (index==word.length()) return isEnd;
        if (word[index]=='.')
        {
            for(int i=0; i<26; i++) if(children[i]!=NULL && \
                children[i]->search(word,index+1)) return true;
            return false;
        }
        int pos = word[index]-'a';
        if (children[pos]==NULL) return false;
        return children[pos]->search(word, index+1);
    }
};

class WordDictionary {
    Trie *trie;
public:
    WordDictionary() {trie = new Trie();}    
    void addWord(string word) {trie->add(word,0);}    
    bool search(string word) {return trie->search(word,0);}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
 {% endhighlight %}