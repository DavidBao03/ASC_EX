# TODO: Implement the swap function in assembly 
# function: swap(int* a, int* b) 
# param a: %rdi 
# param b: %rsi 
# return: void 
swap:
    movl (%rdi), %eax 
    movl (%rsi), %edx 
    movl %edx, (%rdi) 
    movl %eax, (%rsi) 
    ret 
    
main:     
# TODO: Answer the question 
# 这里为什么需要 pushq %rbp 和 %rbx ? 
    pushq %rbp 
    pushq %rbx 
    
# alloc memory for the array 
# and then init the array 
    subq $56, %rsp 
    movl $10, (%rsp) 
    movl $9, 4(%rsp) 
    movl $8, 8(%rsp)
    movl $7, 12(%rsp) 
    movl $6, 16(%rsp) 
    movl $5, 20(%rsp) 
    movl $4, 24(%rsp) 
    movl $3, 28(%rsp) 
    movl $2, 32(%rsp) 
    movl $1, 36(%rsp) 
    movl $0, %ebp 
    jmp .L3 

.L4:
    movl %ebx, %eax 

.L6:
    cmpl $8, %eax 
    jg .L12 

# TODO: complete the following code

    # -------- your code start -------------- 
    # they should equals to: 
    # if(array[j] = array[j + 1]) 
    #   continue; 
    # else 
    #   swap(&array[j], &array[j + 1]); 
    
    jle .L4 # continue 
    
    # prepare parameters for swap 
    
    call swap 
    jmp .L4 
    
    # -------- your code end -------------- 
    
.L12:
    addl $1, %ebp

.L3: 
# TODO: Answer the question 
# 这里 ebp 和 eax 对应于 C 语言中的哪些变量? 
    cmpl $9, %ebp 
    jg .L13 movl $0, %eax 
    jmp .L6 
    
.L13:
    movl $0, %ebx 
    jmp .L7 
    
.L8:
    # call printf 
    movslq %ebx, %rax 
    movl (%rsp,%rax,4), %esi 
    leaq .LC0(%rip), %rdi 
    movl $0, %eax 
    call printf@PLT 
    addl $1, %ebx 
    
.L7:
    # loop and call printf to output the result 
    cmpl $9, %ebx 
    jle .L8 
    movq 40(%rsp), %rax 
    subq %fs:40, %rax 
    jne .L14 
    movl $0, %eax 
    addq $56, %rsp 
    popq %rbx 
    popq %rbp 
    ret