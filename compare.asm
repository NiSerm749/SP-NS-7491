section .text
global compare
compare:
    push rbp
    mov rbp, rsp
    mov rax, qword [rdi] ; загружаем элемент из первого массива
    mov rbx, qword [rsi] ; загружаем элемент из второго массива
    cmp rax, rbx         ; сравниваем элементы
    jl greater           ; если первый элемент меньше, переходим на метку greater
    mov qword [rdx], rbx ; если второй элемент больше или равен, записываем его в третий массив
    jmp end
greater:
    mov qword [rdx], rax ; записываем первый элемент в третий массив
end:
    add rdi, 8           ; увеличиваем указатели на размер элемента
    add rsi, 8
    add rdx, 8
    mov rsp, rbp
    pop rbp
    ret

