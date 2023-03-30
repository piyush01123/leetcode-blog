class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        items = set(supplies)
        while True:
            a = len(items)
            for i, recipe in enumerate(recipes):
                if all([item in items for item in ingredients[i]]):
                    items.add(recipe)
            b = len(items)
            if a==b:
                break
        return list(items.intersection(recipes))