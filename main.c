/*
** Projeto: servomotor lib PWM
** Autor: Evandro Teixeira
*/
#include "pwm.h"
#include "MKL25Z4.h"
 
#define TPM_MODULE 3275
#define DUTY_MIN 165
#define DUTY_MAX 325
 
uint16_t i = 0;
uint16_t x = 0;
 
int main(void)
{
	x = DUTY_MIN;
	// Inicializa TPM
	pwm_tpm_Init(TPM1_BASE_PTR, TPM_PLLFLL, TPM_MODULE, TPM_CLK, PS_128, EDGE_PWM);
	// Inicializa I/O com o sinal do PWM
	pwm_tpm_Ch_Init(TPM1, 0, TPM_PWM_H,GPIOB,0);
	// Set valor Duty Cycle
	pwm_tpm_CnV(TPM1, 0, x);
 
	for (;;)
	{
		// delay
		for(i=0;i<10000;i++); 
		// Set valor Duty Cycle
		pwm_tpm_CnV(TPM1, 0,x);
		// Incrementa o valor de x
		x++;
		if(x >= DUTY_MAX) x = DUTY_MIN;
	}
	return 0;
}