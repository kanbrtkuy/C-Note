#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <semaphore>
#include <future>
#include <condition_variable>
#include <math.h>
#include <future>

using namespace std;

//mutex mtx;
//condition_variable cv;

void task(int a, future<int>& b, promise<int>& ret) {
    int ret_a = pow(a, 2);
    int ret_b = pow(b.get(), 2);
    //unique_lock<mutex> lock(mtx);
    ret.set_value(ret_a + ret_b);
    //cv.notify_one();
}

int main() {

    int ret = 0;

    promise<int> p_ret;
    future<int> f_ret = p_ret.get_future();

    promise<int> p_in;
    future<int> f_in = p_in.get_future();

    thread t(task, 1, ref(f_in), ref(p_ret));

    p_in.set_value(2);

    //unique_lock<mutex> lock(mtx);

    //cv.wait(lock);

    cout << f_ret.get() << endl;
    //cout << f.get() << endl;

    t.join();
}
