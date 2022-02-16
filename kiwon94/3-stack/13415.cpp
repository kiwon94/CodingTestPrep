#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cstdlib>
using namespace std;

int N;
int K;
int set_size = 0;

int main()
{

    cin >> N;
    int *num = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    cin >> K;
    deque<int> sort_set;
    //cout<<K<<endl;
    for (int i = 0; i < K; i++)
    {
        //cout<<"debug"<<endl;
        int a, b;
        cin >> a >> b;
        //b=-b;
        int iter = 0;
        if (set_size == 0)
        {
            // 최초의 세트 삽입
            if (a <= b)
            {
                // 내림차순만 필요
                // 내림차는 sort_set에 음수로 저장함.
                b = -b;
                sort_set.push_back(b);
                set_size++;
            }
            else
            {
                //cout<<"debug"<<endl;
                // 오름차 후 내림차 정렬
                // 따라서 순서대로 sort_set에 삽입
                sort_set.push_back(a);
                set_size++;
                b = -b;
                sort_set.push_back(b);
                set_size++;
            }
        }
        else
        {
            // 이후의 경우
            if (a <= b)
            {
                // 내림차순만 필요
                // sort_set에서 b보다 작은 수가 나올 때까지 b를 갱신
                /*while (abs(sort_set[iter]) > b)
                {
                    iter++;
                }
                if (iter == set_size)
                {
                    // 끝까지 다돌아도 없을 경우 새로 추가
                    //b = -b;
                    sort_set.push_back(-b);
                    set_size++;
                }
                else
                {
                    // 중간에 b보다 작거나 같은 지점을 찾음.
                    // sort_set[iter]를 -b로 바꾸고, set_size를 iter+1로 변경
                    //b = -b;
                    sort_set[iter] = -b;
                    set_size = iter + 1;
                }*/

                // 내림차순만 필요
                // sort_set에서 b보다 큰 수가 나올 때까지 pop_back을 실행
                while(abs(sort_set.back())<=b)
                {
                    sort_set.pop_back();
                }
                sort_set.push_back(-b);
            }
            else
            {
                // 올림 삽입 후 내림 삽입
                while (abs(sort_set[iter]) > a)
                {
                    iter++;
                }
                if (iter == set_size)
                {
                    // 끝까지 다돌아도 없을 경우 새로 추가
                    // 오름차 후 내림차 정렬
                    // 따라서 순서대로 sort_set에 삽입
                    sort_set.push_back(a);
                    set_size++;
                   // b = -b;
                    sort_set.push_back(-b);
                    set_size++;
                }
                else
                {
                    // 중간에 a보다 작거나 같은 지점을 찾음.
                    // sort_set[iter]를 a로
                    // sort_set[iter+1]를 -b로 바꾸고, set_size를 iter+2로 변경
                    // 만약 iter+1이 set_size면 (마지막지점에서 a와 교환된 경우) b는 새로 삽입

                    sort_set[iter] = a;
                    //b = -b;
                    if (iter + 1 == set_size)
                    {
                        sort_set.push_back(-b);
                        set_size++;
                    }
                    else
                    {
                        sort_set[iter + 1] = -b;
                        set_size = iter + 2;
                    }
                }
            }
        }
    }

    for (int i = 0; i < set_size; i++)
    {

        //cout << "sort_set[" << i << "]: " << sort_set[i] << endl;
        if (sort_set[i] > 0)
        {
            sort(num, num + sort_set[i]);
          
        }
        else
        {
            sort(num, num - sort_set[i], greater<int>());
        }
    }

    for (int i = 0; i < N-1; i++)
    {
        cout << num[i] << " ";
    }
    cout<<num[N-1];
}