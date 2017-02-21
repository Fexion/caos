
.text
.global extract
extract:
    mov 8(%esp), %eax
    mov 12(%esp), %ecx
    mov 16(%esp), %edx

    shl %ecx, %eax
    mov %eax, %ecx
    shl %edx, %ecx
    shr %edx, %ecx
    sub %ecx, %eax

    ret
