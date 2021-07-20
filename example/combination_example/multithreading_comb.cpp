#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

#include <atomic>
#include <thread>
#include <mutex>

using namespace std;

vector <int> res[52];
int N, M;

vector <string> v;

recursive_mutex m1, m2;

// string을 어떻게 atomic하고 safe하게 잘 처리하는가
void combination(int index, int thread_index) {
    if(res[thread_index].size() == M) {
        string str;
        for(int i = 0; i < res[thread_index].size(); i++) {
            m1.lock();
            str.append(to_string(res[thread_index][i]));
            m1.unlock();
        }
        m2.lock();
        v.push_back(str);
        m2.unlock();

        return;
    }

    for(int i = index; i < N; i++) {
        res[thread_index].push_back(i);
        combination(i+1, thread_index);
        res[thread_index].pop_back();
        if (res[thread_index].size() == 0) {
            return;
        }   
    }
}

int main() {  
    scanf("%d %d", &N, &M);
    vector <thread> threads;

    for (int i = 0; i < N-M+1; i++) {
        threads.push_back(thread(combination, i, i));
    }

    for (int i = 0; i < threads.size(); i++)
        if (threads[i].joinable()) {
            threads[i].join();
        }


    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "\n";

    return 0;
}