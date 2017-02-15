.text
.global myhypot

myhypot:
    pushl %ebp
    movl  %esp, %ebp

    movsd 8(%esp), %xmm0 //1st
    mulsd %xmm0, %xmm0

    movsd 16(%esp), %xmm1 //2nd
    mulsd %xmm1, %xmm1

    addsd %xmm1, %xmm0
    sqrtsd %xmm0, %xmm0

    //movsd %xmm0, 24(%esp)
    mov 24(%esp), %eax //3rd
    movsd %xmm0, (%eax)

    movl  %ebp, %esp
    popl  %ebp
    ret
