section .text
global daxpy_asm

; RCX = z
; RDX = x
; R8  = y
; R9  = &a (pointer to double)
; [rsp+40] = int n (5th argument) due to shadow space

daxpy_asm:
    movsd   xmm0, xmm3            
    mov     r10, 0                ; i = 0
    mov     r11d, dword [rsp + 40] ; load n (fifth argument)

.loop:
    cmp     r10, r11
    jge     .done

    movsd   xmm1, [rdx + r10*8]
    mulsd   xmm1, xmm0

    movsd   xmm2, [r8 + r10*8]
    addsd   xmm1, xmm2

    movsd   [rcx + r10*8], xmm1

    inc     r10
    jmp     .loop

.done:
    ret
