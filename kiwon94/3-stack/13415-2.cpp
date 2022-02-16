#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cstdlib>
using namespace std;

int N;
int K;
const int MAX = 100001;
int num[MAX], res[MAX];

int main()
{

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
    }
    scanf("%d", &K);
    deque<int> sort_set;
    for (int i = 0; i < K; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if (sort_set.size() == 0)
        {
            // 최초의 세트 삽입
            if (a <= b)
            {
                sort_set.push_back(-b);
            }
            else
            {
                sort_set.push_back(a);
                sort_set.push_back(-b);
            }
        }
        else
        { ///  9       10  8
            // 이후의 경우
            if (a <= b)
            {
                // 내림차순만 필요
                // sort_set에서 b보다 큰 수가 나올 때까지 pop_back을 실행
                while (!sort_set.empty() && (sort_set.back()) <= b)
                {
                    sort_set.pop_back();
                }
                sort_set.push_back(-b);
            }
            else
            {
                // 올림 삽입 후 내림 삽입
                // sort_set에서 a보다 큰 수가 나올 때까지 pop_back을 실행
                while (!sort_set.empty() && abs(sort_set.back()) <= a)
                {
                    sort_set.pop_back();
                }
                sort_set.push_back(a);
                sort_set.push_back(-b);
            }
        }
    }

    int end = sort_set.front();

    sort(num, num + abs(end));
    for (int i = 0; i < N; i++)
    {
        res[i] = num[i];
    }

    int final_idx = abs(end)-1;
    int asc_idx = final_idx;
    int desc_idx = 0;

    while (!sort_set.empty())
    {
        int start;
        sort_set.pop_front();

        if (sort_set.empty())
            start = 1 ;
        // 10 7 6 5 4 3 2 1
        // 1  2 3 4 5 6 7 10
        // 3  4 5 6 2 1 7 10
        else
            start = sort_set.front();
        int start_point = abs(start);
        int end_point = abs(end);
        int len = end_point - start_point;
        if (end < 0)
        {
            //start ~ end -1

            for (int i = 0; i < len; i++)
            {
                res[final_idx--] = num[desc_idx++];
            }
        }
        else
        {
            for (int i = 0; i < len; i++)
            {
                res[final_idx--] = num[asc_idx--];
            }
        }
        end = start;
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", res[i]);
    }
    return 0;
}