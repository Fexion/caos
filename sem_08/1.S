	.text
	.global main
	.type   main, @function

main:
    call readi32
	movl %eax, %ebx
	call readi32
	addl %eax, %ebx
	movl %ebx, %eax
    call writei32
    call nl
    call finish
