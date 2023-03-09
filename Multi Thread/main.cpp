#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <condition_variable>
#include <semaphore>

using namespace std;

mutex mtx;
deque<int> q;

condition_variable cv;

void task1() {
    int i = 0;
    while(1) {
        unique_lock<mutex> lock(mtx);

        q.push_back(i);
        //this_thread::sleep_for(chrono::milliseconds(50));

        cv.notify_one();
        //cv.notify_all();
        if(i < 99999999) {
            i++;
        } else {
            i = 0;
        }
    }
}

void task2() {
    int data = 0;

    while(1) {
        unique_lock<mutex> lock(mtx);

        while (q.empty()) {
            cv.wait(lock);
            //lock.unlock();
            //cv.wait();
        }


        data = q.front();
        q.pop_front();
        cout << data << endl;

    }
}

void task3() {
    int data = 0;

    while(1) {
        unique_lock<mutex> lock(mtx);

        while (q.empty()) {
            cv.wait(lock);
            //lock.unlock();
            //cv.wait();
        }


        data = q.front();
        q.pop_front();
        cout << data << endl;

    }
}

int main() {
    thread t1(task1);
    thread t2(task2);
    thread t3(task3);

    t1.join();
    t2.join();
    t3.join();
}