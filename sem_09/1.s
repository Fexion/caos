.global print_fib
.data
output:
    .string "%d %d %d\n"

.text
print_fib:
    pushl %ebp
    movl  %esp, %ebp

    mov A, %eax
    add B, %eax
    mov B, %ecx
    add %eax, %ecx
    mov %eax, %edx
    add %ecx, %edx

    push %edx
    push %ecx
    push %eax
    push $output
    call printf

    add $16, %esp
    
    movl  %ebp, %esp
    popl  %ebp
    ret
