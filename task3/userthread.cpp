#include <stdint.h> 
#include <stdio.h>

struct thread_t { 
    int64_t rsp; 
    int64_t pc; 
    int64_t stack[1024]; 
};

void function_a(); 
void function_b(); 
void function_c(); 
void function_d(); 

void init_thread(struct thread_t* thread, void (*func)()) { 
    //todo implementation
    //you should set rsp and pc for the thread 
}

void switch_thread(struct thread_t* from, struct thread_t* to) {
    // todo implementation 
    // you should switch the context from thread `from` to thread `to` 
    // save the rsp and pc of current thread to the stack 
    // load the rsp and pc of `to` to the register 
}

struct thread_t thread_a; 
struct thread_t thread_b; 

int main() { 
    init_thread(&thread_a, function_a); 
    init_thread(&thread_b, function_b); 
    struct thread_t self; 
    switch_thread(&self, &thread_a); 
    return 0; 
}

void function_a() {
    printf("this is function A\n"); 
    function_c(); 
}

void function_b() { 
    printf("this is function B\n"); 
    function_d(); 
}

void function_c() { 
    printf("this is function C\n"); 
    switch_thread(&thread_a, &thread_b); 
}

void function_d() { 
    printf("this is function D\n"); 
    switch_thread(&thread_b, &thread_a); 
}