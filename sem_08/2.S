    .text
    .global A
    .global B
    .global C
    .global D
    .global R
    .global process

process:
    mov A, %eax
    imull B
    mov %eax, %ebx

    mov C, %eax
    imull D

    sub %eax, %ebx
    mov %ebx, R

    ret

.data
A:
    .int 0
B:
    .int 0
C:
    .int 0
D:
    .int 0
R:
    .int 0
