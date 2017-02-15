.text
.global main
main:
call    readi32
cmpl    $0, %eax
je      write_0
jle     end
mov     %eax, %ecx
print_n:
mov     %ecx, %eax
push    %ecx
call    writei32
call    nl
pop     %ecx
loop    print_n
write_0:
mov     $0, %eax
call    writei32
pushl   $'\n'
call    putchar
popl    %eax
end:
call finish
