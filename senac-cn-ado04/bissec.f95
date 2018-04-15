program raiz_bissec
	implicit none

	real :: entrada,limite_inferior,limite_superior,temp,precisao,argumento,convertido
	integer :: num_exato
	character(len=100) :: arg
 	call getarg(1,arg)
 	read (arg,*) argumento
 	!print *, argumento


	entrada = argumento
	limite_inferior = 0.0
	limite_superior = entrada
	precisao = 0.00001

	do while (limite_inferior <= limite_inferior)
		temp = (limite_superior + limite_inferior)/2
		if ((temp**2) < entrada) then
			limite_inferior = temp
		else 
			limite_superior = temp
		end if

		if(abs(limite_superior-limite_inferior) < precisao) exit

	end do

	!print * ,"Raiz de ",entrada,"equivale a",limite_superior," ",limite_inferior

	convertido = nint(limite_superior)

	if(abs(limite_superior-convertido) < 0.0001) then
		num_exato = int (convertido)
		write(*, fmt="(i0)", advance="no")  num_exato
	else
		write(*, fmt="(f6.3)", advance="no")  limite_superior
	end if

end program raiz_bissec