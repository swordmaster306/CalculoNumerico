program ranqueador
implicit none

	!dimensoes de entrada, sempre devem ser iguais
	integer :: dimensao
	integer :: i , j , counter
	
	!matriz de entrada  |  matriz 1/dimensao  |  vetor dimensao_1
	double precision, dimension(:,:), allocatable :: matriz_entrada, matriz_s, vetor_pesos,vetor_pesos_aux
	double precision :: m = 0.15
	double precision :: precisao = 0.00001, normalizador = 0.0
	double precision :: valor_antigo = 1

	!Recebe a matriz do python ou le de um arquivo
	dimensao = 4

	!Aloca dinamicamente a matriz com as dimensoes da matriz recebida
	allocate ( matriz_entrada(dimensao,dimensao) )
	allocate ( matriz_s(dimensao,dimensao) )
	allocate ( vetor_pesos(dimensao,1) )
	allocate ( vetor_pesos_aux(dimensao,1) )


	matriz_entrada(1,1) = 0
	matriz_entrada(1,2) = 0
	matriz_entrada(1,3) = 1.0
	matriz_entrada(1,4) = 1.0/2
	matriz_entrada(2,1) = 1.0/3
	matriz_entrada(2,2) = 0
	matriz_entrada(2,3) = 0
	matriz_entrada(2,4) = 0
	matriz_entrada(3,1) = 1.0/3
	matriz_entrada(3,2) = 1.0/2
	matriz_entrada(3,3) = 0
	matriz_entrada(3,4) = 1.0/2
	matriz_entrada(4,1) = 1.0/3
	matriz_entrada(4,2) = 1.0/2
	matriz_entrada(4,3) = 0
	matriz_entrada(4,4) = 0



	! Multiplica os valores da matriz_entrada por (1-m)
	do i=1,dimensao
		do j=1,dimensao
			matriz_entrada(i,j) = matriz_entrada(i,j) * (1.0-m) 
		end do
	end do

	!Atribui para todos os elementos da matriz o valor 1/dimensão e multiplica por m
	! do i=1,dimensao
	! 	do j=1,dimensao
	! 		matriz_s(i,j) = (1.0/dimensao) * m
	! 	end do
	! end do

	! do i=1,dimensao
	! 	do j=1,dimensao
	! 		matriz_entrada(i,j) = matriz_entrada(i,j) + matriz_s(i,j)
	! 	end do
	! end do

	!Inicializa o vetor vetor_pesos com valores 1/dimensao
	do i=1,dimensao
		vetor_pesos(i,1) = (1.0/dimensao) * m
		vetor_pesos_aux(i,1) = 1.0/dimensao
	end do


	


	counter = 0
	! Multiplica a matriz_entrada por vetor_pesos até um threshold
	do while (ABS(valor_antigo-vetor_pesos_aux(1,1)) > precisao )
		valor_antigo = vetor_pesos_aux(1,1)
		vetor_pesos_aux = matmul(matriz_entrada,vetor_pesos_aux) 
		do i=1,dimensao
			vetor_pesos_aux(i,1) = vetor_pesos_aux(i,1) + vetor_pesos(i,1)
		end do
		counter = counter + 1
	end do


	do i=1,dimensao
		print *,vetor_pesos_aux(i,1)
	end do

	print *, counter


	deallocate( matriz_entrada )
	deallocate( matriz_s )
	deallocate( vetor_pesos )
	deallocate( vetor_pesos_aux )
end program ranqueador