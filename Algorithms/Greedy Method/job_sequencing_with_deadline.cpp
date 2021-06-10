#include <iostream>
using namespace std;
int main()
{
    int n, cap, prof = 0;
    cout << "Enter the number of jobs -: ";
    cin >> n;
    int pf[n], dl[n];
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter the profit and deadline for job " << i << " -: ";
        cin >> pf[i] >> dl[i];
    }
    for (int i = n; i > 1; i--)
    {
        for (int j = 1; j < i; j++)
        {
            if (pf[j] <= pf[j + 1])
            {
                int temp = pf[j];
                pf[j] = pf[j + 1];
                pf[j + 1] = temp;
            }
        }
    }
    cap = dl[1];
    for (int i = 2; i <= n; i++)
    {
        if (cap < dl[i])
        {
            cap = dl[i];
        }
    }
    int slot[cap] = {0};
    int seq[cap] = {0};
    for (int i = 1; i <= n; i++)
    {
        if (slot[dl[i]] == 0)
        {
            slot[dl[i]] = pf[i];
            seq[dl[i]] = i;
        }
        else
        {
            for (int j = dl[i] - 1; j >= 1; j--)
            {
                if (slot[j] == 0)
                {
                    slot[j] = pf[i];
                    seq[j] = i;
                    break;
                }
            }
            continue;
        }
    }
    cout << "The sequence in which the jobs will be done are -: ";
    for (int i = 1; i <= cap; i++)
    {
        // cout << slot[i] << " -> ";
        cout << seq[i] << " -> ";
        // prof += slot[i];
    }
    cout << "The total profit is -: " << prof;
    return 0;
}