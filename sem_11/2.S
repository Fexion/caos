#include <asm/unistd_32.h>
#define max_size 4*1024

.data
array:
    .space max_size, 0
array_size:
    .int 0

cur_el:
    .int 0

flag_eof:
    .int 0

nc:
    .int 0

.text
.global nextchar
.global nc

nextchar:
    pushl %ebx
    cmp   $0, flag_eof
    jnz   eof

    movl  array_size, %eax
    cmp   cur_el, %eax
    jnz   end

    movl    $__NR_read , %eax
    movl    $0, %ebx
    movl    $array , %ecx
    movl    $max_size, %edx
    int     $0x80

    cmp $-1, %eax
    jz  eof
    cmp $0, %eax
    jz  eof

    movl %eax, array_size
    movl $0, cur_el

end:
    movl cur_el, %eax
    movzbl array(,%eax,1), %eax
    movl %eax, nc
    addl  $1, cur_el
    popl %ebx
    ret
eof:
    movl $-1, %eax
    movl $-1, nc
    movl $1, flag_eof
    popl %ebx
    ret
