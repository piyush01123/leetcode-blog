class Solution:
    # def get_subtree_size(tree, root):
    #     curr = 1
    #     if len(tree[root])==0:
    #         return curr
    #     for child in tree[root]:
    #         curr += get_subtree_size(tree, child)
    #     return curr
        

    def countHighestScoreNodes(self, parents: List[int]) -> int:
        tree_size = len(parents)
        children = [[] for _ in range(tree_size)]
        for child, parent in enumerate(parents):
            if child==0:
                continue
            children[parent].append(child)
        p_dict = collections.Counter()
        def STS(node):
            curr_sum, curr_prod = 0, 1
            for child in children[node]:
                size = STS(child)
                curr_sum += size
                curr_prod *= size
            size_parent = tree_size-1-curr_sum
            if size_parent>0:
                curr_prod = curr_prod * size_parent
            p_dict[curr_prod] += 1
            return curr_sum+1
        STS(0)
        return p_dict[max(p_dict.keys())]

        # scores = []
        # for node in range(tree_size):
        #     subtree_sizes = []
        #     for child in children[node]:
        #         subtree_sizes.append(get_subtree_size(children, child))
        #     score = 1
        #     for size in subtree_sizes:
        #         score = score * size
        #     if len(subtree_sizes)==0:
        #         size_parent = tree_size-1
        #     else:
        #         size_parent = tree_size-1-sum(subtree_sizes)
        #     if size_parent>0:
        #         score = score * size_parent
        #     scores.append(score)
        # max_score = max(scores)
        # return sum([s==max_score for s in scores])
