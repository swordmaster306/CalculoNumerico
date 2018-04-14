program raiz_newton
	implicit none
	real :: entrada,precisao,xn,xn1,erro
	
	entrada = 144
	xn = 1
	xn1 = entrada
	erro = 0.001

	do while((abs(xn-xn1))>precisao)
		if(xn1 /= entrada)then
			xn = xn1
		end if
		xn1 = calcular_xn(xn,entrada)
		print *, "Valor de xn:",xn, " Valor de xn1:",xn1
	end do

	print * ,"Raiz de ",entrada ," eh ",xn1
contains

real function calcular_xn (x,entrada)
	implicit none
	real , intent(in) :: x,entrada
	real :: resultado

	resultado = x - ((x**2)-entrada)/(2*x)
	calcular_xn = resultado
end function calcular_xn

end program