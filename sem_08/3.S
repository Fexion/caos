.text
.global main
main:
    call readi32
print_n:
    cmpl $0, %eax
    jl end
    push %eax

    call writei32
    call nl

    pop %eax
    sub $1, %eax

    jmp print_n
end:
    call finish
