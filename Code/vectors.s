.globl vectorizedCopy
vectorizedCopy:
  pushq %rbp
  movq  %rsp, %rbp

  cmpq  $4, %rdx
  jl    above2
  
  movq  %rdx, %rcx
  shrq  $2,   %rcx
  leaq  (%rdx, %rcx, 4),  %rdx  
multsOf4:
  vmovupd  (%rdi), %ymm0
  vmovupd  %ymm0,  (%rsi)
  addq  $32,  %rdi
  addq  $32,  %rsi
  loop  multsOf4

above2:
  cmpq  $2, %rdx
  jb    checkOdd

  movupd  (%rdi), %xmm0
  movupd  %xmm0,  (%rsi)
  addq  $16,  %rdi
  addq  $16,  %rsi

  subq  $2, %rdx
checkOdd:
  cmpq  $0, %rdx
  je    done

  movsd (%rdi), %xmm0
  movsd %xmm0,  (%rsi)

done:
  leave
  ret
