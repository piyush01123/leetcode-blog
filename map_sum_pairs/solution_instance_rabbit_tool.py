class MapSum:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.hashPairs = {}
        

    def insert(self, key, val):
        """
        :type key: str
        :type val: int
        :rtype: void
        """
        self.hashPairs[key] = val
        

    def sum(self, prefix):
        """
        :type prefix: str
        :rtype: int
        """
        print(self.hashPairs)
        # matches = []
        sum=0
        for k in self.hashPairs:
            # if len(k) < len(prefix):
            #     pass
            if k[:len(prefix)]==prefix:
                # matches.apped(k)
                sum += self.hashPairs[k]
        return sum

                # sum = 0
        # for k in matches:
        #     sum+=
        


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)