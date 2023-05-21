#include <vector>
#include <queue>

int kth_largest(std::vector<int> values, int k)
{
    std::priority_queue<int> queue;

    // check for each index in the vector of values 
    for(auto& index: values)
    {
        // push it 
        queue.push(index);
    }

    if(k > 1)
    {
        // if k is not 1, i.e. 2nd largest etc
        for (int i = 0; i < k-1; i++)
        {
            // keep goind and pop it out 
            queue.pop();
        }
    }
    return queue.top();
}
