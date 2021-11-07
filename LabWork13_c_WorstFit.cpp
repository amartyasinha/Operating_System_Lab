//
// Created by amartya on 05/11/21.
//

#include<iostream>
using namespace std;

int main() {
    cout << "It is a Program to implement Worst Fit\n";
    int  totalProcess, totalBlock, blockSize[10], processSize[10], allocation[20], flag, temp, temp1;

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

    //worst fit
    for (int y = 1; y <= totalBlock; y++) {
        for (int z = y; z <= totalBlock; z++) {
            if (blockSize[y] < blockSize[z]) {
                temp = blockSize[y];
                blockSize[y] = blockSize[z];
                blockSize[z] = temp;
                temp1 = allocation[y];
                allocation[y] = allocation[z];
                allocation[z] = temp1;
            }
        }
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