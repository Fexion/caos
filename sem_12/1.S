.data
.align  16
.global process, end_process, scanp, printp

process:// write your code here
    pushl %ebp
    movl %esp, %ebp

    pushl %ebx
    pushl %esi
    pushl %edi
    call f

f:
    popl %eax
    movl %eax, %ebx
    movl %eax, %esi
    movl %eax, %edi

    addl $A - f, %ebx
    addl $B - f, %esi
    addl $str - f, %eax
    addl $str2 - f, %edi

    pushl %ebx //A
    pushl %esi //B
    pushl %eax //str

scanp:
    call    scanf
    addl  $12, %esp //3x pushl

    movl (%ebx), %ebx
    addl %ebx, (%esi) //B+=A

    pushl (%esi)  // B
    pushl %edi //str2

printp:
    call    printf

    addl $8, %esp //2x

    popl %edi
    popl %esi
    popl %ebx

    movl %ebp, %esp
    popl %ebp

    ret

str:    .asciz  "%d%d"
str2:   .asciz  "%d\n"
        .align  4
A:      .int    0
B:      .int    0
end_process:
