.text
.global process

process:
 pushl %ebp
 movl  %esp, %ebp
 pushl %edi


 movl A, %eax
 movl A + 4, %edx
 addl %eax, %eax
 adcl %edx, %edx

 movl B, %edi
 movl B + 4, %ecx
 shr %ecx
 rcr %edi

 subl %edi, %eax
 sbbl %ecx, %edx


 pushl %edx
 pushl %eax
 pushl $print

 call printf

 popl %eax
 popl %eax
 popl %eax

 popl %edi
 movl  %ebp, %esp
 popl  %ebp
 ret

.data
print:
 .string "%llu\n"
