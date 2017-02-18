.text
.global satsum

satsum:
    pushl %ebp
    movl  %esp, %ebp

    mov 8(%esp), %eax
    add 12(%esp), %eax
    jnc end

    mov $4294967295, %eax
end:
    movl  %ebp, %esp
    popl  %ebp
    ret
