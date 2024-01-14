
#include "user.h"

static uint32_t  tick_ ;
static int  count_led_, count_usart_  ;

extern UART_HandleTypeDef huart1;

void USER_init(void) {
	count_led_ = 0 ;
	count_usart_ = 0 ;
	LED_init();
	KEY_init();
	USART1_init( &huart1 );
	tick_ = HAL_GetTick();
}

void USER_proc(void) {
	if ( ++count_led_ >= 50 ) {
		count_led_ = 0 ;
		LED_proc();
	}
	if ( ++count_usart_ >= 100 ) {
		count_usart_ = 0 ;
		USART1_proc();
	}
	KEY_proc();
	//HAL_Delay(10);
	USER_waitTo( tick_ += 10 );
}

void USER_waitTo(uint32_t tick) {
	while ( HAL_GetTick() < tick ) {} 
}
