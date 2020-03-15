#include <vector>
#include <unordered_map>

using namespace std;

class Cashier
{
    private:
        int total_customers;
        int cashier_n;
        int cashier_discount;
        unordered_map<int,int> product_prices;
    public:
        Cashier(const int n, const int discount, vector<int>&, products, vector<int>& prices) :
            total_customers(0),
            cashier_n(n),
            cashier_discount(discount)
        {
            for (int i = 0; i < products.size(); ++i)
            {
                product_prices[products[i]] = prices[i];
            }
        }

        double getBill(vector<int>& product, vector<int>& amount)
        {
            double total = 0.0;
            for (int i = 0; i < product.size(); ++i)
            {
                total += 1.0 * product_prices[product[i]] * amount[i]; 
            }
            total_customers++;
            if (total_customers % cashier_n == 0) 
            {
                total -= (discount * total)/100
            }
            total_customers %= cashier_n;
            return total;
        }
};
