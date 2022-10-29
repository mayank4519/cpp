#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bits/stdc++.h>
#include <thread>
#include <mutex>
// using namespace std;

std::mutex mtx;
std::map<int,int> mp;

struct range_s{
    int spos;
    int epos;
    int *p;
};

void* func(void *arg) {
    mtx.lock();

    struct range_s *temp = (struct range_s*)arg;

    for (int i = temp->spos; i < temp->epos; i++) {
        std::map<int,int>::iterator it;
        
        it = mp.find(temp->p[i]);

        if (it == mp.end()) {
            mp.insert({temp->p[i], 1});
        } else {
            it->second++;
        }
    }

    mtx.unlock();
}

void non_repeat_num(int arr[], int N, int T) {

    int start = 0, end = start + (T/N) -1;
    std::thread thread[T];

    for(int i = 0; i < T; i++) {

        struct range_s *arg = new range_s();
        arg->spos = start;
        arg->epos = end;
        arg->p = arr;

        thread[i] = std::thread(func, (void*)arg);
        //pthread_create(&thread[i], NULL, func, (void*)arg);

        start = end + 1;
        end = start + (N/T) - 1;

        if (i == T-2)
            end = N-1;
    }

    for (int i = 0; i < T; i++) {
        thread[i].join();
    }

    for (auto it : mp) {
        if (it.second == 1)
            std::cout  << it.first << std::endl;
    }
}

int main()
{
    int arr[] = {1,1,4,4,5,5,7,8,9,10};
    int sz = sizeof(arr)/sizeof(arr[0]);
    int T = 3;
    non_repeat_num(arr,sz,T);
    return 0;
}