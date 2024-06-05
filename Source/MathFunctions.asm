section .bss
    original_cw: resq 1
section .text

global f1
global f1_deriv

global f2
global f2_deriv

global f3
global f3_deriv

;https://stackoverflow.com/questions/4638473/how-to-powreal-real-in-x86
f1:
    finit
    push ebp
    mov ebp, esp
    sub esp, 6

    fstcw word [ebp-2]
    or word [ebp-2], 0b110000000000
    fldcw word [ebp-2]

    fld qword [ebp+8]
    fld1
    fld1
    faddp
    fyl2x

    fist dword [ebp-6]

    fild dword [ebp-6]
    fsub
    f2xm1
    fld1
    fadd
    fild dword [ebp-6]
    fxch
    fscale
    fld1
    faddp

    mov esp, ebp
    pop ebp
    ret

f1_deriv:
    call f1
    fld1
    fchs
    faddp
    fldln2
    fmulp
    ret

f2:
    finit
    fld qword [esp+4]
    fld qword [esp+4]
    fld qword [esp+4]
    fld qword [esp+4]
    fld qword [esp+4]
    fmulp
    fmulp
    fmulp
    fmulp
    ret

f2_deriv:
    finit
    fld qword [esp+4]
    fld qword [esp+4]
    fld qword [esp+4]
    fld qword [esp+4]
    push 3
    fild dword [esp]
    add esp, 4
    fmulp
    fmulp
    fmulp
    fmulp
    ret

f3:
    finit
    fld qword [esp+4]
    fchs
    fld1
    faddp
    push 3
    fild dword [esp]
    add esp, 4
    fdivp
    ret

f3_deriv:
    finit
    push -1
    push 3
    fild dword [esp]
    fild dword [esp+4]
    add esp, 8
    fdivp
    ret