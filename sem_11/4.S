#include <asm/unistd_32.h>
#define max_size 4*1024

.data
array:
    .space max_size, 0
array_size:
    .int 0


.text
.global writechar
.global flush

writechar:
    movl array_size, %ecx
    movb %eax, array(, %ecx, 1)
    addl $1, array_size

    movl $max_size, %ecx
    cmp  array_size, %ecx
    jg end
    call flush
end:
    ret

flush:
    movl $__NR_write, %eax
    movl $1, %ebx
    movl $array, %ecx
    movl array_size, %edx
    int $0x80

    movl $0, array_size
    ret
