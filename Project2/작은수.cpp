#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> stringnum;

bool comp(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer;
    int ansnum(0);

    for (int i = 0; i < numbers.size(); i++)
    {
        stringnum.push_back(to_string(numbers[i]));
    }

    sort(stringnum.begin(), stringnum.end(), comp);

    for (int i = 0; i < stringnum.size(); i++)
    {
        answer += stringnum[i];
        ansnum += stoi(stringnum[i]); // 이거하기 전에 coredump 낫음 와이.
    }

    if (ansnum == 0) return "0";
    else return answer;
}