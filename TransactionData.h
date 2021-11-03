//
// Created by Adilet Kemelkhan on 02.11.2021.
//

#include <bits/stdc++.h>

using namespace std;

#ifndef UNTITLED5_TRANSACTIONDATA_H
#define UNTITLED5_TRANSACTIONDATA_H

struct TransactionData {
    double amount;
    string senderKey, receiverKey;
    time_t timestamp;

    TransactionData(double amount, string senderKey, string receiverKey, time_t timestamp) {
        this->amount = amount;
        this->senderKey = senderKey;
        this->receiverKey = receiverKey;
        this->timestamp = timestamp;
    }

    TransactionData() {}

    friend ostream &operator<<(ostream &out, TransactionData &t) {
        out << "Amount: " << t.amount << "\nSender Key: " << t.senderKey << "\nReceiver Key: " << t.receiverKey
            << "\nTime: " << t.timestamp << "\n";
    }
};

#endif //UNTITLED5_TRANSACTIONDATA_H
