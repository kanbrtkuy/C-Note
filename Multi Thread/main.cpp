#include <iostream>
#include <thread>

using namespace std;

void func() {
    int i = 0;
    while(i < 10) {
        cout << "Hello world" << endl;
        this_thread::sleep_for(chrono::microseconds(50));
        i++;
    }
}

int main() {

    int a = 0;
    thread thread1(func);

    thread1.join(); //阻塞，直到子线程执行完毕
    //thread1.detach(); //分离子线程和主线程，尽量少用，分离开在后台运行，也就是守护线程

//    while(a < 5) {
//        cout << "Cat" << endl;
//        this_thread::sleep_for(chrono::microseconds(50));
//        a++;
//    }

    return 0;
}
