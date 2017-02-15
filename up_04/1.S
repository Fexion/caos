.text
.global process

process:
    pushl %ebp
    movl  %esp, %ebp

    mov A, %eax
    mov B, %ecx
    mov C, %edx

    cmp %eax, %ecx
    ja comp1

    cmp %eax, %edx
    ja comp2

    cmp %ecx, %edx
    ja comp3

    mov B, %eax
    jmp end

comp1:
    cmp %eax, %edx
    ja comp4

    mov A, %eax
    jmp end

comp2:
    mov A, %eax
    jmp end

comp3:
    mov C, %eax
    jmp end

comp4:
    cmp %edx, %ecx
    ja comp5

    mov B, %eax
    jmp end
comp5:
    mov C, %eax
    jmp end
end:
    movl %ebp, %esp
    popl %ebp
    ret
