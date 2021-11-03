#include <bits/stdc++.h>
#include "TransactionData.h"
#include "Block.h"
#include "Blockchain.h"
#include "Miner.h"

using namespace std;

double getTotalVolume(Blockchain &chain){
    double totalamount = 0;
    for(Block to : chain.getchain()){
        totalamount += to.getTransactionData().amount;
    }
    return totalamount;
}

void firstThread(Blockchain *blockchain, TransactionData data, Miner miner){
    miner.mine(*blockchain, data);
    blockchain->addblock(data);
}

void secondThread(Blockchain *blockchain, TransactionData data, Miner miner){
    miner.mine(*blockchain, data);
    blockchain->addblock(data);

}

int main(){
    Blockchain *blockchain = new Blockchain();

    blockchain->addblock(*new TransactionData(100, "Adik", "Nurgiss", time(NULL)));
    blockchain->addblock(*new TransactionData(50, "Sandu", "Taskibayev", time(NULL)));
    blockchain->addblock(*new TransactionData(150, "Adilet", "Kemelkhan", time(NULL)));
    TransactionData data = *new TransactionData(1000, "Kemelkhan", "Nurgiss", time(NULL));
    TransactionData data1 = *new TransactionData(500, "Adal", "Taskibayev", time(NULL));
    Miner miner;
    thread th(firstThread, blockchain, data, miner);

    th.join();
}