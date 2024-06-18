#include <vector>
using namespace std;

vector<int> alternateNumbers(vector<int>& a) {
    int n = a.size();
    vector<int> nums(n, 0);
    int pos = 0, neg = 1;
    
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            if (neg < n) {
                nums[neg] = a[i];
                neg += 2;
            }
        } else {
            if (pos < n) {
                nums[pos] = a[i];
                pos += 2;
            }
        }
    }
    
    return nums;
}
