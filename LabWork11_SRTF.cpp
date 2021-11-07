//
// Created by amartya on 06/11/21.
//

#include <iostream>
using namespace std;

class sched {
public:
    int n, burstTime[10], arrivalTime[10], turnAroundTime[10], waitingTime[10], rt[10], finish[10], totalWaitingTime, totalTurnAroundTime, total;

    void readData();
    void computeSRT();
    void Init();
    void dispTime();
    int getNextProcess(int);
};

void sched::readData() {
    cout << "Enter no. of processes\n";
    cin >> n;
    cout << "Enter the burst times in order :\n";
    for (int i = 0; i < n; i++)
        cin >> burstTime[i];
    cout << "Enter the arrival times in order:\n";
    for (int i = 0; i < n; i++)
        cin >> arrivalTime[i];
}

void sched::Init() {
    total = 0;
    totalWaitingTime = 0;
    totalTurnAroundTime = 0;
    for (int i = 0; i < n; i++) {
        rt[i] = burstTime[i];
        finish[i] = 0;
        waitingTime[i] = 0;
        turnAroundTime[i] = 0;
        total += burstTime[i];
    }
}

void sched::computeSRT() {
    readData();
    Init();
    int time, next = 0, old, i;
    cout << "Gantt Chart\n ";
    for (time = 0; time < total; time++) {
        old = next;
        next = getNextProcess(time);
        if (old != next || time == 0) {
            cout << "(" << time << ")|==P" << next + 1 << "==|";
        }
        rt[next] = rt[next] - 1;
        if (rt[next] == 0) {
            finish[next] = 1;
        }

        for (i = 0; i < n; i++)
            if (i != next && finish[i] == 0 && arrivalTime[i] <= time)
                waitingTime[i]++;
    }
    cout << "(" << total << ")" << endl;
    for (i = 0; i < n; i++)
        if (!finish[i]) {
            cout << "Scheduling failed, cannot continue\n";
            return;
        }
    dispTime();
}

int sched::getNextProcess(int time) {
    int i, low;
    for (i = 0; i < n; i++)
        if (finish[i] == 0) {
            low = i;
            break;
        }
    for (i = 0; i < n; i++)
        if (finish[i] != 1)
            if (rt[i] < rt[low] && arrivalTime[i] <= time)
                low = i;
    return low;

}

void sched::dispTime() {
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        turnAroundTime[i] = waitingTime[i] + burstTime[i];
        totalTurnAroundTime += turnAroundTime[i];
        cout << "Waiting time for P" << (i + 1) << " = " << waitingTime[i] << ", Turnaround time = " << turnAroundTime[i] << endl;
    }
    cout << "Avg Waiting time = " << (double) totalWaitingTime / n << " and Avg Turnaround time = " << (double) totalTurnAroundTime / n << endl;
    cout << "Scheduling complete\n";
}

int main() {
    sched s;
    s.computeSRT();
}