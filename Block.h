//
// Created by Adilet Kemelkhan on 02.11.2021.
//

#include "TransactionData.h"
#include <bits/stdc++.h>

using namespace std;

#ifndef UNTITLED5_BLOCK_H
#define UNTITLED5_BLOCK_H

class Block{
private:
    int index;
    TransactionData transaction_data;
    size_t block_hash;
    size_t prev_hash;
public:
    int getIndex(){
        return this->index;
    }
    TransactionData getTransactionData(){
        return this->transaction_data;
    }
    size_t getBlockHash(){
        return this->block_hash;
    }
    size_t getPrevHash(){
        return this->prev_hash;
    }
    size_t generateHash(){
        string toHashS = to_string(transaction_data.amount) + transaction_data.receiverKey + transaction_data.senderKey + to_string(transaction_data.timestamp);
        hash<string> tDataHash;
        hash<string> prevHash;
        return tDataHash(toHashS) ^ (prevHash(to_string(prev_hash)) << 1);
    }
    Block(int index, TransactionData transaction_data, size_t prev_hash){
        this->index = index;
        this->transaction_data = transaction_data;
        this->prev_hash = prev_hash;
        this->block_hash = generateHash();
    }

};

#endif //UNTITLED5_BLOCK_H
