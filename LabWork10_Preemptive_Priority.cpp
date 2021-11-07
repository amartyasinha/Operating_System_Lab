//
// Created by amartya on 26/10/21.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "enter your total no. of process";
    cin >> n;
    float total, wait[n];
    float p[n], twaiting = 0, waiting = 0;
    int proc;
    int stack[n];
    float burst[n], arrival[n], sburst, temp[n], top = n, priority[n];
    int i;

    for (i = 0; i < n; i++) {
        p[i] = i;
        stack[i] = i;
        cout << "enter arrival time :";
        cin >> arrival[i];
        cout << endl << "enter burst time:";
        cin >> burst[i];
        cout << endl << "enter priority time:";
        cin >> priority[i];
        temp[i] = arrival[i];
        sburst = burst[i] + sburst;
    }

    for (i = 0; i < sburst; i++) {
        //section 1
        proc = stack[0];
        if (temp[proc] == i)
            twaiting = 0;
        else
            twaiting = i - (temp[proc]);
        temp[proc] = i + 1;
        wait[proc] = wait[proc] + twaiting;
        waiting = waiting + (twaiting);
        burst[proc] = burst[proc] - 1;

        if (burst[proc] == 0) {
            for (int x = 0; x < top - 1; x++)
                stack[x] = stack[x + 1];
            top = top - 1;
        }

        for (int z = 0; z < top - 1; z++) {
            if ((priority[stack[0]] > priority[stack[z + 1]]) && (arrival[stack[z + 1]] <= i + 1)) {
                int t = stack[0];
                stack[0] = stack[z + 1];
                stack[z + 1] = t;
            }
        }
    }

    cout << "Average waiting time is:" << waiting / n;
    float tu = (sburst + waiting) / n;
    cout << endl << "Average turnaround time is:" << tu;
    return 0;
}