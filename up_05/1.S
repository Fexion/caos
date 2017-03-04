.text
.global extract

extract:
        pushl   %ebp
        movl    %esp, %ebp

        cmpl    $0, 12(%ebp)
        jne     forward
        cmpl    $32, 16(%ebp)
        jne     forward
        movl    8(%ebp), %eax

        movl    %ebp, %esp
        popl    %ebp
        ret
forward:
        movl    12(%ebp), %eax
        movl    %eax, %ecx
        shrl    %cl, 8(%ebp)

        movl    16(%ebp), %eax
        movl    8(%ebp), %edx
        movl    %eax, %ecx
        shrl    %cl, %edx

        movl    16(%ebp), %eax
        movl    %eax, %ecx

        sall    %cl, %edx
        movl    8(%ebp), %eax

        subl    %edx, %eax

        movl    %ebp, %esp
        popl    %ebp
        ret
