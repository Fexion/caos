#include <asm/unistd_32.h>
.text
.global _start

_start:
    sub $4, %esp

main:
    call read
    cmp $0, %eax
    jz end
    cmp $'0', (%esp)
    jb write
    cmp $'9', (%esp)
    ja write
    movl $'0' , (%esp)
    jmp write

read:
    movl    $__NR_read , %eax // или $3, %eax, если заголовочный файл не найден
    movl    $0, %ebx        // первый аргумент (0 - стандартный поток ввода) в %ebx
    addl    $4, %esp
    movl    %esp , %ecx        // второй аргумент (адрес переменной c) в %ecx
    subl    $4, %esp
    movl    $1, %edx        // третий аргумент (размер переменной c) в %edx
    int     $0x80
    ret


write:
    movl $__NR_write, %eax
    movl $1, %ebx
    movl %esp, %ecx
    movl $1, %edx
    int $0x80
    jmp main

end:
    add $4, %esp
    movl    $__NR_exit, %eax
    xorl    %ebx, %ebx
    int     $0x80
