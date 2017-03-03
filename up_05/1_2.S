.data
bit:
    .int 0
l:
    .int 0
.text
.global extract1
extract1:
    movl 8(%esp), %eax
    movl 12(%esp), %ecx
    movl 16(%esp), %edx
    
    shl %eax
    mov %eax, %ecx
    shl %ecx
    shr %ecx
    sub %ecx, %eax

    ret
