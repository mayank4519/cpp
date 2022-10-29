#include <iostream>
#include <algorithm>
#include <queue>
#include <pthread.h>
#include <unistd.h>

using namespace std;

void Task1(void) { cout << "Task1 " << endl; }
void Task2(void) { cout << "Task2 " << endl; }
void Task3(void) { cout << "Task3 " << endl; }
void Task4(void) { cout << "Task4 " << endl; }
void Task5(void) { cout << "Task5 " << endl; }

class Task{
    bool timer_enable;
    bool periodic;
    uint32_t curr_time_tracker;
    uint32_t retry;
    void (*callback)(void);
public:
    Task() : timer_enable(false), periodic(false), curr_time_tracker(0xFFFFFFFF), retry(0xFFFFFFFF) {}

    //GETTERS
    bool get_timer_enable() {return timer_enable;}
    uint32_t get_curr_time_tracker() {return curr_time_tracker;}
    bool get_periodicity() {return periodic;}
    uint32_t get_retry() {return retry;}
    void execute_callback() {callback();}
    void decrease_curr_time_tracker() {curr_time_tracker--;}

    //SETTERS
    void set_callback(void(*fptr)(void)) {callback = fptr;}
    void set_periodicity(bool val) {periodic = val;}
    void set_retry(uint32_t val) {retry = val;}
    void set_curr_time_tracker(uint32_t val) {curr_time_tracker = val;}
    void set_timer_enable(bool const& enable) {timer_enable = enable;}
    

};

#define MAX_TASK 5
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
queue<int32_t> task_queue;
Task task[MAX_TASK];

void TimerInterrupt() {
    pthread_mutex_lock(&mutex);

    for(int t_idx = 0 ; t_idx < MAX_TASK; t_idx++) {
        if (true == task[t_idx].get_timer_enable()) {
            if (0 == task[t_idx].get_curr_time_tracker()) {
                if (true == task[t_idx].get_periodicity())
                    task[t_idx].set_curr_time_tracker(task[t_idx].get_retry());
                else
                    task[t_idx].set_timer_enable(false);

                task_queue.push(t_idx);
            }
            else
                task[t_idx].decrease_curr_time_tracker();
        }
    }
    pthread_mutex_unlock(&mutex);
}

void *timer_interrupt(void* arg) {
    static uint32_t counter = 0;
    while(1) {
        cout << "counter " << counter++ << endl;
        TimerInterrupt();
        sleep(1);
    }

}

void *run_task(void *arg) {
    while(1) {
        pthread_mutex_lock(&mutex);
        if(!task_queue.empty()) {
            int tid = task_queue.front();
            task_queue.pop();
            task[tid].execute_callback();
        }
        pthread_mutex_unlock(&mutex);
    }
} 

void timer_start(uint32_t *timer, void(*pcallback)(void), uint32_t timeout, bool periodic) {

    pthread_mutex_lock(&mutex);
    for(int t_idx = 0 ; t_idx < MAX_TASK; t_idx++) {
        if (false == task[t_idx].get_timer_enable()) {
            task[t_idx].set_timer_enable(true);
            task[t_idx].set_curr_time_tracker(timeout);
            task[t_idx].set_retry(timeout);
            task[t_idx].set_periodicity(periodic);
            task[t_idx].set_callback(pcallback);
            *timer = t_idx;
            break;
        }
    }
    pthread_mutex_unlock(&mutex);
}

int main(int argc, char **argv) {
    
    pthread_t t1,t2;
    pthread_create(&t1, NULL, &timer_interrupt,NULL);
    pthread_create(&t2, NULL, &run_task,NULL);

    uint32_t timer_id1, timer_id2, timer_id3;
    timer_start(&timer_id1, Task1, 3, true);
    timer_start(&timer_id2, Task2, 5, true);
    timer_start(&timer_id2, Task3, 10, false);


    sleep(60);

    pthread_cancel(t1);
    pthread_cancel(t2);

}