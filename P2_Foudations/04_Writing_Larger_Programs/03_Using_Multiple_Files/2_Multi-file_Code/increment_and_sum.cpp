#include <vector>
using std::vector;

int IncrementAndComputeVectorSum(vector<int> v) {
    int total = 0;

    for (auto i: v) {
        total += 2*i;
    }

    return total;
}
