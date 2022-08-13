// f(x) = xe^0.5x + 1.2x - 5
// f'(x) = 0.5e^(0.5x)x+e^0.5x+1.2 

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

int main(){

	int i = 1, num_it;
	float *v, *ep, pto_inicial, epsilon; 
	float e = 2.718281828459045235360287;
	
	printf("Calculo iterativo pelo metodo de Newton-Raphson\n"); 
	printf("ZERO DA FUNCAO: x*e^(0.5x) + 1.2*x - 5\n");	

	printf("\nNumero de iteracoes maximo: ");
  		scanf("%d", &num_it);

	printf("Digite o valor para x0: ");
		scanf("%f", &pto_inicial);

	printf("Entre com a precisao: ");
		scanf("%f", &epsilon);
		printf("\n");
	
	v = (float *) malloc(num_it * sizeof(float));
	ep = (float *) malloc(num_it * sizeof(float));
	
	v[0] = pto_inicial;

	for (i = 1; i <= num_it; i++) {
		v[i] = v[i-1] - (v[i-1]*pow(e,0.5*v[i-1]) + 1.2*v[i-1] - 5) / (0.5*pow(e,0.5*v[i-1])*v[i-1]+pow(e,0.5*v[i-1])+1.2);
		ep[i] = fabs(v[i]-v[i-1]);
		printf("Valor da %da iteracao eh: %f, com erro de %f\n", i, v[i], ep[i]);
			if (ep[i] < epsilon) {
				printf("\nO erro calculado eh menor que a precisao (%f)\n\n", epsilon);
				break;
			} else if (i == num_it) {
				printf("\nNumero maximo de iteracoes (%d) atingido\n\n", num_it);
				break;
			}
	}
	free(v);
	free(ep);
	getchar();
}
