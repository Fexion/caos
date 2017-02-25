.text
.global main

main:
    xorl %ebx, %ebx

input:
    call readi32
    jc exit
    add %eax, %ebx
    jno input

overflow:
    xorl %ebx, %ebx
    not %ebx
    shl $31, %ebx
    not %ebx

    shr  $31, %eax
    add  %eax, %ebx
exit:
    mov  %ebx, %eax
    call writei32
    call nl
    call finish
