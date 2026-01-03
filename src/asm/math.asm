global add
global compute_time

section .note.GNU-stack

section .data
; empty

section .bss
; empty

section .text

; double add(double a, double b)
add:
	addsd xmm0, xmm1
	ret

; double compute_time(double distance, double speed)
; time = distance / speed
compute_time:
	divsd xmm0, xmm1
	ret
