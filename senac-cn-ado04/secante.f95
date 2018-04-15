program raiz_newton
	implicit none
	real :: entrada,precisao,xn,xn1,temp,erro,argumento,convertido
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
		temp = xn1
		xn1 = calcular_xn(xn,xn1,entrada)
		xn = temp
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

!Aproximacao da derivada
real function calcular_secante(xn,xn1,entrada,b)
	implicit none
	real , intent(in) :: xn,xn1,entrada,b
	calcular_secante = ((xn1**2-entrada) - (xn**2-entrada))/b
end function calcular_secante


real function calcular_xn (xn,xn1,entrada)
	implicit none
	real , intent(in) :: xn,xn1,entrada
	real :: m,resultado,a,b
	b = xn1-xn

	if(xn1 == entrada) then
		!print *,"IF 1 ", a ," / ", b
		m = calcular_secante(xn,xn1-1,entrada,b)
	else if(xn == entrada) then
		!print *,"IF 2 ", a ," / ", b
		m = calcular_secante(xn-1,xn1,entrada,b)
	else
		!print *,"ELSE ", a ," / ", b
		m = calcular_secante(xn,xn1,entrada,b)
	end if

	resultado = xn1 - (((xn1**2)-entrada))/m

	!print *, "Valor de m: ",m," Valor de resultado: ",resultado
	calcular_xn = resultado
end function calcular_xn

end program