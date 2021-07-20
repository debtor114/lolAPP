#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

atomic<int> counter;

void worker() {
  for (int i = 0; i < 10000; i++) {
    counter++;
  }
}

int main() {

  vector<thread> workers;
  for (int i = 0; i < 4; i++) {
    workers.push_back(thread(worker));
  }

  for (int i = 0; i < 4; i++) {
    workers[i].join();
  }

  cout << "Counter 최종 값 : " << counter << endl;
}