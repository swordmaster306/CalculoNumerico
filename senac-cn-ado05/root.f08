program raiz
	implicit none
	real :: a,b,c	
	character(len=100) :: arg,arg1,arg2


	call getarg(1,arg)
	call getarg(2,arg1)
	call getarg(3,arg2)
	read (arg,*) a
	read (arg1,*) b
	read (arg2,*) c
	 
	!sPrint * , "Arg:", a," Arg2:" ,b, " Arg3: " ,c
	call calcular_delta(a,b,c)
contains 

subroutine calcular_delta(a,b,c)
	real, intent(in) :: a,b,c
	real :: delta
	delta = b**2 - (4*a*c)
	!Print *, "a: ",a,"    b:",b,"     c",c , "  delta:",delta
	call calcular_raizes(a,b,c,delta)
end subroutine calcular_delta

subroutine calcular_raizes(a,b,c,delta)
	real, intent(in) :: a,b,c,delta
	real :: x1,x2
	if (delta < 0 ) then
		x1 = (b*-1)/(2*a) ! parte real
		!Print *, "Raiz de delta:",delta," 2vezes a:",2*a
		x2 = (SQRT(delta))/(2*a) !parte imaginaria
		!Print * ,"Delta menor que zsero raiz x1: ",x1,"+",x2,"i","   x2: ",x1,"-",x2,"i"
	else if ( delta == 0) then
		x1 = (b*-1)/(2*a)
		!Print *, "Raiz real: ",x1
		write(*, fmt="(f6.3)", advance="no")  x1
	else 
		x1 = ((b*-1)+(SQRT(delta)))/(2*a)
		x2 = ((b*-1)+(-1*SQRT(delta)))/(2*a)
		!Print *, "Delta maior que zero raizes x1:",x1, " x2:",x2
		write(*, fmt="",advance="no") "r1"
		write(*, fmt="(f6.3 f6.3)", advance="no")  x1,x2
	end if
end subroutine calcular_raizes

end program raiz