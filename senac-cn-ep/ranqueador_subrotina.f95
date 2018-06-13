subroutine ranquear (matriz_entrada_original,dimensao,vetor_resultado)

	!dimensoes de entrada, sempre devem ser iguais
	integer, intent(in) :: dimensao
    double precision, intent(in) :: matriz_entrada_original(dimensao,dimensao)
    double precision, intent(out) :: vetor_resultado(dimensao,1)
	integer :: i , j , counter
	
	!matriz de entrada  |  matriz 1/dimensao  |  vetor dimensao_1
	double precision, dimension(:,:), allocatable :: matriz_entrada, matriz_s, vetor_pesos,vetor_pesos_aux
	double precision :: m = 0.15
	double precision :: precisao = 0.00001, normalizador = 0.0
	double precision :: valor_antigo = 1

	!Recebe a matriz do python ou le de um arquivo
	! dimensao = 4
	!Aloca dinamicamente a matriz com as dimensoes da matriz recebida
	allocate ( matriz_entrada(dimensao,dimensao) )
	allocate ( matriz_s(dimensao,dimensao) )
	allocate ( vetor_pesos(dimensao,1) )
	allocate ( vetor_pesos_aux(dimensao,1) )

    matriz_entrada = matriz_entrada_original

	! Multiplica os valores da matriz_entrada por (1-m)
	do i=1,dimensao
		do j=1,dimensao
			matriz_entrada(i,j) = matriz_entrada(i,j) * (1.0-m) 
		end do
	end do



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





    vetor_resultado = vetor_pesos_aux

	deallocate( matriz_entrada )
	deallocate( matriz_s )
	deallocate( vetor_pesos )
	deallocate( vetor_pesos_aux )
end subroutine ranquear