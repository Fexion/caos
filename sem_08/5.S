.text
.global main

main:
    xorl %ebx, %ebx //even
    xorl %esi, %esi //odd

input:
    call readi32
    jc exit

    testl $1, %eax
    je even
    addl %eax, %esi
    jmp input
even:
    addl %eax, %ebx
    jmp input

exit:
    movl %ebx, %eax
    call writei32
    call nl
    movl %esi, %eax
    call writei32
    call nl
    call finish
