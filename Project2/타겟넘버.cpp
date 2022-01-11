#include <string>
#include <vector>

int res(0);
using namespace std;

void DFS(vector<int> numbers, int target, int sum, int n)
{
    if (n >= numbers.size())
    {
        if (target == sum) res++;
        return;
    }

    DFS(numbers, target, sum + numbers[n], n + 1);
    DFS(numbers, target, sum - numbers[n], n + 1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    DFS(numbers, target, +numbers[0], 1);
    DFS(numbers, target, -numbers[0], 1);

    answer = res;

    return answer;
}