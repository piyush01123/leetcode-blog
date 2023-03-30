class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        inDegrees = defaultdict(int)
        G = defaultdict(list)
        for recipe, itemList in zip(recipes, ingredients):
            for item in itemList:
                G[item].append(recipe)
                inDegrees[recipe] += 1
        S = supplies
        L = []
        while len(S)>0:
            s_node = S.pop()
            L.append(s_node)
            for t_node in G[s_node]:
                inDegrees[t_node] -= 1
                if inDegrees[t_node]==0:
                    S.append(t_node)
        return list(set(L).intersection(set(recipes)))