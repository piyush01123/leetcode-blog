In the constructor itself, I am linearizing the whole thing and storing the data in an array. We recurse inside the nested integer till we get to an integer.

```
class NestedIterator {
    vector<int> arr;
    int index = 0;
public:
    void linearize(NestedInteger nestInt, vector<int> &res)
    {
        if (nestInt.isInteger())
            res.push_back(nestInt.getInteger());
        else
            for (NestedInteger item: nestInt.getList())
                linearize(item, res);
        return;
    }
    NestedIterator(vector<NestedInteger> &nestedList) 
    {
        for (NestedInteger nestInt: nestedList)
            linearize(nestInt, arr);
    }
    
    int next() 
    {
        return arr[index++];
    }
    
    bool hasNext() 
    {
        return index < arr.size();
    }
};

```