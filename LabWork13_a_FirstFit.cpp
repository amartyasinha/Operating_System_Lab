//
// Created by amartya on 05/11/21.
//

#include<iostream>
using namespace std;

int main() {
    cout << "It is a program to implement First Fit\n";
    int  totalProcess, totalBlock, blockSize[10], processSize[10], allocation[20], flag;

    //input
    cout << "Enter Number of Memory Block: ";
    cin >> totalBlock;
    for (int i = 1; i <= totalBlock; i++) {
        cout << "\nEnter Memory Size for Block [" << i << "]: ";
        cin >> blockSize[i];
        allocation[i] = i;
    }
    cout << "\nEnter Number of Process: ";
    cin >> totalProcess;
    for (int i = 1; i <= totalProcess; i++) {
        cout << "\nEnter Memory Size for Process [" << i << "]: ";
        cin >> processSize[i];
    }

    //print
    for (int i = 1; i <= totalProcess; i++) {
        flag = 1;
        for (int j = 1; j <= totalBlock; j++) {
            if (processSize[i] <= blockSize[j]) {
                cout << "\nProcess [" << i << "] of Size " << processSize[i] << "KB allocated at Memory Block " << allocation[j];
                blockSize[j] = blockSize[j] - processSize[i];
                break;
            } else {
                flag++;
            }
        }
        if (flag > totalBlock) {
            cout << "\nProcess [" << i << "] of Size " << processSize[i] << "KB can't be allocated";
        }
    }
    return 0;
}