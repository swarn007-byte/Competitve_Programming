// class Solution {
// public:
//     int maximumSaleItems(vector<vector<int>>& items, int budget) {
//         int n = items.size();
        
//         vector<int> free(n, 0);
//         for(int i = 0; i < n; i++)
//             for(int j = 0; j < n; j++)
//                 if(i != j && items[j][0] % items[i][0] == 0)
//                     free[i]++;
        
//         int minPrice = INT_MAX;
//         for(auto& it : items) minPrice = min(minPrice, it[1]);
        
//         vector<int> x(budget + 1, -1);
//         x[0] = 0;
        
//         for(int i = 0; i < n; i++){
//             int p = items[i][1];
//             int val = 1 + free[i];
//             for(int c = budget; c >= p; c--)
//                 if(x[c - p] >= 0)
//                     x[c] = max(x[c], x[c - p] + val);
//         }
        
//         int ans = 0;
//         for(int c = 0; c <= budget; c++)
//             if(x[c] >= 0)
//                 ans = max(ans, x[c] + (budget - c) / minPrice);
        
//         return ans;
//     }
// };