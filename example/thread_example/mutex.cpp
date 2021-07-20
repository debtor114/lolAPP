#include <cstdio>
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

int counts = 0;

void counter(mutex &m) {
    for (int i = 0; i < 10000; i++) {
        // lock, unlock을 자동으로 해주는 객체
        lock_guard<mutex> lock(m);
        counts++;
    }
}

int main() {
    vector <thread> t;
    mutex m;
    for (int i = 0; i < 5; i++)
        t.push_back(thread(counter, ref(m)));

    for (int i = 0; i < 5; i++)
        t[i].join();

    cout << "count: " << counts << "\n";
    return 0;
}
