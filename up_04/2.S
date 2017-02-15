.text
.global process

process:
    pushl %ebp
    movl  %esp, %ebp

    mov 8(%ebp), %edx // a
    mov 12(%ebp), %ecx // b

    mov %edx, %eax
    add %eax, %eax
    jo overflow
    add %edx, %eax
    jo overflow

    add %ecx, %ecx
    jo overflow

    sub %ecx, %eax
    jo overflow

    mov 16(%ebp), %edx
    mov %eax, (%edx)

    mov $1, %eax
    jmp end

overflow:
    mov $0, %eax
    jmp end

end:
    movl %ebp, %esp
    popl %ebp
    ret
