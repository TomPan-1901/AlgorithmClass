#include <iostream>
#include <algorithm>
using namespace std;
struct job
{
    int deadline;
    int weight;
    job()
    {}
    job(int _deadline, int _weight) :
        deadline(_deadline), weight(_weight)
    {}
    int operator<(job right)
    {
        return weight > right.weight;
    }
};

int main()
{
    int T;
    cin >> T;
    for (int i = 0;i < T;i++)
    {
        int N;
        cin >> N;
        job jobs[50001] = {};
        for (int j = 0;j < N;j++)
        {
            int d, p;
            cin >> d >> p;
            jobs[j] = job(d, p);
        }
        int headptr = 0;
        while (headptr < N)
        {
            int tempptr = headptr;
            while (jobs[tempptr].deadline == jobs[headptr].deadline && tempptr < N)
            {
                tempptr++;
            }
            sort(jobs + headptr, jobs + tempptr);
            headptr = tempptr;
        }
        int k = 1;
        int head = 0;
        uint64_t result = 0;
        while (k <= jobs[N - 1].deadline)
        {
            if (jobs[head].deadline >= k)
            {
                result += jobs[head].weight;
                head++;
            }
            else
            {
                int tempptr = head;
                while (jobs[tempptr].deadline == jobs[head].deadline && tempptr < N)
                {
                    tempptr++;
                }
                head = tempptr;
                if (jobs[head].deadline >= k)
                {
                    result += jobs[head].weight;
                    head++;
                }
            }
            k++;
        }
        std::cout << result << endl;
    }
}