#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>

using namespace std;

int main() {
	int step = 1;
	int displayNext = step;
	int percent = 0;
    int totalImagesCount = 3545545;

	cout << "Processing... " << endl;

	for (int i = 0; i < totalImagesCount ; ++i) {		
		percent = (100 * (i + 1)) / totalImagesCount ;
		if (percent >= displayNext) {
			cout << "\r" << "[" << string(percent / 5, 'o') << string(100 / 5 - percent / 5, ' ') << "]";
			cout << " " <<percent << "%";
			cout.flush();
			displayNext += step;
		}
        sleep(3);
	}
}