// f(x) = xe^0.5x + 1.2x - 5

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

int main(){

	int i = 1, num_it;
	float *x, *ep, pto_inicial, epsilon;
	float e = 2.718281828459045235360287;

	printf("Calculo iterativo pelo metodo das secantes\n");
	printf("ZERO DA FUNCAO: x*e^(0.5x) + 1.2*x - 5\n");

	printf("\nNumero de iteracoes maximo: ");
  		scanf("%d", &num_it);

	printf("Digite o valor para x0: ");
		scanf("%f", &pto_inicial);

	printf("Entre com a precisao: ");
		scanf("%f", &epsilon);
		printf("\n");

	x = (float *) malloc(num_it * sizeof(float));
	ep = (float *) malloc(num_it * sizeof(float));

	x[0] = pto_inicial;
	x[1] = pto_inicial + 0.1;

	printf("Valor aproximado com 6 casas decimais: 1.504988\n");
	printf("Para x0 = %f e x1 = %f, temos: \n", x[0], x[1]);
	for (i = 1; i <= num_it; i++) {
		x[i+1] = (x[i-1]*(x[i]*pow(e,0.5*x[i]) + 1.2*x[i] - 5) - (x[i]*(x[i-1]*pow(e,0.5*x[i-1]) + 1.2*x[i-1] - 5))) / ((x[i]*pow(e,0.5*x[i]) + 1.2*x[i] - 5) - (x[i-1]*pow(e,0.5*x[i-1]) + 1.2*x[i-1] - 5));
		ep[i+1] = fabs(x[i+1]-x[i]);
		printf("Valor da %da iteracao (x%d) eh: %f, com erro de %f (|x%d - x%d|)\n", i, i+1, x[i+1], ep[i+1], i+1, i);
			if (ep[i+1] < epsilon) {
				printf("\nO erro calculado eh menor que a precisao (%f)\n\n", epsilon);
				break;
			} else if (i == num_it) {
				printf("\nNumero maximo de iteracoes (%d) atingido\n\n", num_it);
				break;
			}
	}
	free(x);
	getchar();
}
