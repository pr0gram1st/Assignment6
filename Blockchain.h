//
// Created by Adilet Kemelkhan on 03.11.2021.
//

#ifndef UNTITLED5_BLOCKCHAIN_H
#define UNTITLED5_BLOCKCHAIN_H

#include "Block.h"
#include <bits/stdc++.h>

class Blockchain{
private:
    vector < Block > chain;
public:
    vector < Block > getchain(){
        return this->chain;
    }
    Block createFirstBlock(){
        time_t current;
        TransactionData dataFirstBlock(0, "FirstBlock", "FirstBlock", time(&current));
        Block firstBlock(0, dataFirstBlock, 0);
        return firstBlock;
    }
    Blockchain(){
        Block firstblock = createFirstBlock();
        chain.push_back(firstblock);
    }
    Block *getLatestBlock(){
        return &chain.back();
    }
    void addblock(TransactionData data){
        int index = (int)chain.size();
        size_t previousHash = getLatestBlock()->getBlockHash();
        Block newBlock(index, data, previousHash);
        chain.push_back(newBlock);
    }
    void printBlockChain(){
        for(vector < Block > :: iterator it = chain.begin(); it != chain.end(); ++it){
            Block cur = *it;
            TransactionData x = cur.getTransactionData();
            cout << "Index: " << cur.getIndex() << "\n" << x;
        }
    }
    bool isBlockchainValid(){
        for(vector < Block > :: iterator it = chain.begin(); it != chain.end(); ++it){
            Block cur = *it;
            if(cur.generateHash() != cur.getBlockHash()){
                return 0;
            }
        }
        return 1;
    }
};

#endif //UNTITLED5_BLOCKCHAIN_H
