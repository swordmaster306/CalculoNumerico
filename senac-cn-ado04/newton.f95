program raiz_newton
	implicit none
	real :: entrada,precisao,xn,xn1,erro,argumento,convertido
	integer :: num_exato
	character(len=100) :: arg
 	call getarg(1,arg)
 	read (arg,*) argumento
 	!print *, argumento


	entrada = argumento
	xn = 1
	xn1 = entrada
	erro = 0.001

	do while((abs(xn-xn1))>precisao)
		if(xn1 /= entrada)then
			xn = xn1
		end if
		xn1 = calcular_xn(xn,entrada)
		!print *, "Valor de xn:",xn, " Valor de xn1:",xn1
	end do

	!print * ,"Raiz de ",entrada ," eh ",xn1

	convertido = nint(xn1)

	if(abs(xn1-convertido) < 0.0001) then
		num_exato = int (convertido)
		write(*, fmt="(i0)", advance="no")  num_exato
	else
		write(*, fmt="(f6.3)", advance="no")  xn1
	end if

contains

real function calcular_xn (x,entrada)
	implicit none
	real , intent(in) :: x,entrada
	real :: resultado

	resultado = x - ((x**2)-entrada)/(2*x)
	calcular_xn = resultado
end function calcular_xn

end program