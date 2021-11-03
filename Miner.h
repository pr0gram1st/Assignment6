//
// Created by Adilet Kemelkhan on 03.11.2021.
//

#include <bits/stdc++.h>
#include "TransactionData.h"
#include "Block.h"
#include "Blockchain.h"

using namespace std;

#ifndef UNTITLED5_MINER_H
#define UNTITLED5_MINER_H

class Miner{
public:
    Blockchain mine(Blockchain &blockchain, TransactionData &data){
        srand(time(NULL));
        int x = rand() % 10;
        int y = rand() % 10;
        int randmo = rand() % 3;
        char arr[] = {'+', '-', '*'};
        cout << "Solve " << x << " " << arr[randmo] << " " << y << "\nYour answer: ";
        int z;
        cin >> z;
        bool flag = 0;
        if(randmo == 0){
            if(x + y == z){
                flag = 1;
            }
        }
        if(randmo == 1){
            if(x - y == z){
                flag = 1;
            }
        }
        if(randmo == 2){
            if(x * y == z){
                flag = 1;
            }
        }
        if(flag){
            blockchain.addblock(data);
        }
        return blockchain;
    }
};

#endif //UNTITLED5_MINER_H
