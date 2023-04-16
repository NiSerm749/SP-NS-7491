#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int SIZE = 10;
    long arr1[SIZE];
    long arr2[SIZE];
    long arr3[SIZE];
    // заполнение первых двух массивов случайными числами
    srand(time(NULL));
    for(int i = 0; i < SIZE; i++) {
        arr1[i] = rand() % 100;
        arr2[i] = rand() % 100;
    }
    // заполнение третьего массива с помощью ассемблерных вставок
    asm(
        "movq %0, %%rdi\n\t"
        "movq %1, %%rsi\n\t"
        "movq %2, %%rdx\n\t"
        "movl %3, %%ecx\n\t"
        "loop_start:\n\t"
        "movq (%%rdi), %%rax\n\t"
        "movq (%%rsi), %%rbx\n\t"
        "cmpq %%rax, %%rbx\n\t"
        "jg greater\n\t"
        "movq %%rbx, (%%rdx)\n\t"
        "jmp end\n\t"
        "greater:\n\t"
        "movq %%rax, (%%rdx)\n\t"
        "end:\n\t"
        "add $8, %%rdi\n\t"
        "add $8, %%rsi\n\t"
        "add $8, %%rdx\n\t"
        "loop loop_start\n\t"
        :
        : "r" (arr1), "r" (arr2), "r" (arr3), "r" (SIZE)
        : "%rax", "%rbx", "%rcx", "%rdi", "%rsi", "%rdx"
    );
    // вывод результатов
    cout << "Array 1: ";
    for(int i = 0; i < SIZE; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << "Array 2: ";
    for(int i = 0; i < SIZE; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    cout << "Array 3: ";
    for(int i = 0; i < SIZE; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;
    return 0;
}
