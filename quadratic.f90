PROGRAM Quadratic
  IMPLICIT NONE
  INTEGER :: i
  REAL :: x, y
  INTEGER, PARAMETER :: n = 10

  ! Loop over a range of x values
  DO i = 0, n
     x = REAL(i)
     y = x**2
     CALL Print_C_Compatible(x, y)
  END DO

CONTAINS

  ! Subroutine to print in a format that is compatible with C
  SUBROUTINE Print_C_Compatible(x, y)
    REAL, INTENT(IN) :: x, y
    PRINT *, "x=", x, ", y=", y
  END SUBROUTINE Print_C_Compatible

END PROGRAM Quadratic
