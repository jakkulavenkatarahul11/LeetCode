class Solution {
public:
    //  ******nvdpsaluja******
    
    bool dfs(string recipe, unordered_map<string, vector<string>>& mpp,unordered_set<string>& visited, unordered_map<string, bool>& ans) {
        // if this recipe has already been visited, return the stored result
        if (visited.find(recipe) != visited.end()) return ans[recipe];

        visited.insert(recipe);
        bool check = true;

        for (auto& ingredient : mpp[recipe]) {
            // if an ingredient is not found in the map, it means we cannot create it
            if (mpp.find(ingredient) == mpp.end()) return false;

            // recursively check if the ingredient can be made
            check &= (dfs(ingredient, mpp, visited, ans));
        }
        ans[recipe] = check;
        return check;
    }

    vector<string> findAllRecipes(vector<string>& recipes,vector<vector<string>>& ingredients,vector<string>& supplies) {
        int n = recipes.size();

        // map mpp stores each recipe and its required ingredients
        unordered_map<string, vector<string>> mpp;

        // map ans stores whether it is possible to create a given recipe
        unordered_map<string, bool> ans;

        for (int i = 0; i < n; i++) {
            mpp[recipes[i]] = ingredients[i];
        }

        // add supplies as leaf nodes with empty ingredient lists
        // this helps in marking them as available for making recipes
        for (int i = 0; i < supplies.size(); i++) {
            mpp[supplies[i]] = {};
        }

        // set to keep track of visited recipes to avoid redundant calculations
        unordered_set<string> visited;

        // res vector to store the recipes that can be made
        vector<string> res;

        // Check each recipe using DFS
        for (int i = 0; i < n; i++) {
            if (dfs(recipes[i], mpp, visited, ans)) {
                res.push_back(recipes[i]);
            }
        }
        return res;
    }
};