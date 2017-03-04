.data
.align 16
one:
    .double 1.0

.text
.global myexp

myexp:
    pushl   %ebp
    movl    %esp, %ebp

    movsd 8(%ebp), %xmm0 //x
    movsd one, %xmm1    //
    movsd one, %xmm2    //next
    movsd one, %xmm3    //div
calc:
    mulsd %xmm0, %xmm2
    divsd %xmm3, %xmm2

    movsd %xmm1, %xmm4
    addsd %xmm2, %xmm1

    addsd one, %xmm3

    comisd %xmm4, %xmm1
    jne calc

    mov   16(%ebp), %eax
    movsd %xmm1, (%eax)

    movl  %ebp, %esp
    popl  %ebp
    ret
