program hello
	implicit none

	real :: entrada,limite_inferior,limite_superior,temp,precisao

	entrada = 9
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

	print * ,"Raiz de ",entrada,"equivale a",limite_superior," ",limite_inferior
end program hello