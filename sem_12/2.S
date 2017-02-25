.text
.global process
process:
    pushl %ebp
    movl  %esp, %ebp
    pushl %ebx

    call  geteip
    addl  $_GLOBAL_OFFSET_TABLE_, %ebx

    mov   A@GOT(%ebx), %eax //A
    movsd (%eax), %xmm0

    mov   B@GOT(%ebx), %eax  //B
    addsd (%eax), %xmm0  //A+B

    call  f
f:
    popl  %eax
    addl  $D - f, %eax

    divsd (%eax), %xmm0 // (A+B)/2

    mov   C@GOT(%ebx), %eax
    movsd %xmm0, (%eax)

    popl  %ebx
    movl  %ebp, %esp
    popl  %ebp
    ret

geteip:
    movl  (%esp), %ebx
    ret

.data
.align 16
D:
    .double 2.0
