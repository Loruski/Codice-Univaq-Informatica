addiu $1, $1, 4095
addiu $2, $2, 41
addiu $3, $3, 33
addiu $6, $6, 29041
div $5, $6, $1
mul $4, $5, $3
addiu $3, $3, 113
div $5, $3, 3
rem $3, $5, 5
mul $2, $2, 52
div $2, $3
mflo $1
mfhi $2
