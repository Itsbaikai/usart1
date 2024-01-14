
#include "user.h"
#include <stdio.h>

static UART_HandleTypeDef *pUsart_ ;
static int  count_ ;

void USART1_init(UART_HandleTypeDef *pUsart) {
	pUsart_ = pUsart ;
	count_ = 0 ;
}

void USART1_proc(void) {
	count_++;
	char buffer[128];
	int  length = sprintf( buffer, "USART1 Query %d\n", count_ );
	USART1_send( buffer, length );
}

int  USART1_send(const char *buf,int len) {
	HAL_UART_Transmit( pUsart_, (const uint8_t *)buf, len, 100 );
	return len ;
}

int  USART1_recv(char *buf) {
	return 0;
}

