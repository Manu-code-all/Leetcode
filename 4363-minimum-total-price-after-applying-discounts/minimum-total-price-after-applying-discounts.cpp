class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        std::sort(prices.begin(), prices.end(), std::greater<int>());
        std::sort(discounts.begin(), discounts.end(), std::greater<int>());
        double minsum=0.0;
        int count=0;
        for(int i=0;i<prices.size() && i<discounts.size();i++)
            {
                count++;
                minsum += prices[i]*(100.0-discounts[i])/100.0;
            }
        while(count<prices.size())
            {
                minsum+=prices[count];
                count++;
            }
        
        return minsum;
    }
};