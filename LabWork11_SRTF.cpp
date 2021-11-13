//
// Created by amartya on 06/11/21.
//

#include <iostream>
using namespace std;

class sched {
public:
    int n, burstTime[10], arrivalTime[10], turnAroundTime[10], waitingTime[10], remainingBurstTime[10], finish[10], totalWaitingTime, totalTurnAroundTime, processID[10], total;

    void readData();
    void computeSRT();
    void Init();
    void dispTime();
    int getNextProcess(int);
};

void sched::readData() {
    cout << "Enter no. of processes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "\nEnter the Burst Time for Process: [" << i + 1 << "]: ";
        cin >> burstTime[i];
        cout << "Enter the Arrival Time for Process: [" << i + 1 << "]: ";
        cin >> arrivalTime[i];
        processID[i] = i + 1;
    }
}

void sched::Init() {
    total = 0;
    totalWaitingTime = 0;
    totalTurnAroundTime = 0;
    for (int i = 0; i < n; i++) {
        remainingBurstTime[i] = burstTime[i];
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
    cout << "\n-----------------------------------------------------\n";
    cout << "Gantt Chart\n ";
    for (time = 0; time < total; time++) {
        old = next;
        next = getNextProcess(time);
        if (old != next || time == 0) {
            cout << "(" << time << ")|==P" << next + 1 << "==|";
        }
        remainingBurstTime[next] = remainingBurstTime[next] - 1;
        if (remainingBurstTime[next] == 0) {
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
            if (remainingBurstTime[i] < remainingBurstTime[low] && arrivalTime[i] <= time)
                low = i;
    return low;

}

void sched::dispTime() {
    //printing waiting time, turnaround time for these processes
    cout << "\n--------------------------------------------------------------------\n";
    cout << "Process | Arrival Time | Burst Time | Waiting Time | TurnAround Time\n";
    cout << "--------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        turnAroundTime[i] = waitingTime[i] + burstTime[i];
        totalTurnAroundTime += turnAroundTime[i];
        cout << " " << processID[i]<< "\t\t\t" << arrivalTime[i] << "\t\t\t\t" << burstTime[i] << "\t\t\t" << waitingTime[i] << "\t\t\t\t" << turnAroundTime[i] << endl;
    }
    cout << "--------------------------------------------------------------------\n";
    cout << "Average Waiting Time: " << totalWaitingTime / (double)n;
    cout << "\nAverage Turnaround Time: " << totalTurnAroundTime / (double)n << endl;    cout << "Scheduling complete\n";
}

int main() {
    sched s;
    s.computeSRT();
}