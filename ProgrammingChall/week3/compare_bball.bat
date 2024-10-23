@echo off
echo running

:loop
gen_bball > random.in

basketball < random.in > basketball.out
brute_force_bball < random.in > brute_force.out

fc basketball.out brute_force.out > nul
if %errorlevel% equ 0 (
    echo all good
    goto loop
) else (
    echo Mismatch found!
    type random.in
)

del basketball.out brute_force.out
pause
