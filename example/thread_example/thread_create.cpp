#include <cstdio>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;


void worker(int start, int end, int* result) {
  int sum = 0;
  for (int i = start; i < end; ++i) {
    sum += i;
  }
    // 쓰레드의 id 를 구한다.
  thread::id this_id = this_thread::get_id();
  printf("쓰레드 %x 에서 %d 부터 %d 까지 계산한 결과 : %d \n", this_id, start, (end - 1), sum);

 *result = sum;
}

int main() {

    int data[10000];
    int partial_sums[4];
    vector<thread> workers;

    for (int i = 0; i < 10000; i++) 
        data[i] = i;

    for (int i = 0; i < 4; i++) {
        workers.push_back(thread(worker, data[0] + i * 2500, data[0] + (i+1) * 2500, &partial_sums[i]));
    }

    for (int i = 0; i < 4; i++) {
        workers[i].join();
    }

    int total = 0;
    for (int i = 0; i < 4; i++) {
        total += partial_sums[i];
    }

    cout << "전체 합 : " << total << "\n";
    return 0;
}