
#include "user.h"

static int  count_ ;
static int  led_data_ ;

static void update_led_data_(void) {
	if ( led_data_ & 0x0001 )  HAL_GPIO_WritePin( GPIOC, GPIO_PIN_8  , GPIO_PIN_RESET );
	else                       HAL_GPIO_WritePin( GPIOC, GPIO_PIN_8  , GPIO_PIN_SET   );
	if ( led_data_ & 0x0002 )  HAL_GPIO_WritePin( GPIOC, GPIO_PIN_9  , GPIO_PIN_RESET );
	else                       HAL_GPIO_WritePin( GPIOC, GPIO_PIN_9  , GPIO_PIN_SET   );
	if ( led_data_ & 0x0004 )  HAL_GPIO_WritePin( GPIOC, GPIO_PIN_10 , GPIO_PIN_RESET );
	else                       HAL_GPIO_WritePin( GPIOC, GPIO_PIN_10 , GPIO_PIN_SET   );
	if ( led_data_ & 0x0008 )  HAL_GPIO_WritePin( GPIOC, GPIO_PIN_11 , GPIO_PIN_RESET );
	else                       HAL_GPIO_WritePin( GPIOC, GPIO_PIN_11 , GPIO_PIN_SET   );
	if ( led_data_ & 0x0010 )  HAL_GPIO_WritePin( GPIOC, GPIO_PIN_12 , GPIO_PIN_RESET );
	else                       HAL_GPIO_WritePin( GPIOC, GPIO_PIN_12 , GPIO_PIN_SET   );
	if ( led_data_ & 0x0020 )  HAL_GPIO_WritePin( GPIOC, GPIO_PIN_13 , GPIO_PIN_RESET );
	else                       HAL_GPIO_WritePin( GPIOC, GPIO_PIN_13 , GPIO_PIN_SET   );
	if ( led_data_ & 0x0040 )  HAL_GPIO_WritePin( GPIOC, GPIO_PIN_14 , GPIO_PIN_RESET );
	else                       HAL_GPIO_WritePin( GPIOC, GPIO_PIN_14 , GPIO_PIN_SET   );
	if ( led_data_ & 0x0080 )  HAL_GPIO_WritePin( GPIOC, GPIO_PIN_15 , GPIO_PIN_RESET );
	else                       HAL_GPIO_WritePin( GPIOC, GPIO_PIN_15 , GPIO_PIN_SET   );

	HAL_GPIO_WritePin( GPIOD, GPIO_PIN_2  , GPIO_PIN_SET   );
	HAL_GPIO_WritePin( GPIOD, GPIO_PIN_2  , GPIO_PIN_RESET );
}

void LED_init(void) {
	count_ = 0 ;
	led_data_ = 0 ;
	update_led_data_();
}

void LED_proc(void) {
	count_++;
	if ( count_ & 0x0001 ) LED_enable(0);  else  LED_disable(0);
//	if ( count_ & 0x0002 ) LED_enable(1);  else  LED_disable(1);
//	if ( count_ & 0x0004 ) LED_enable(2);  else  LED_disable(2);
//	if ( count_ & 0x0008 ) LED_enable(3);  else  LED_disable(3);
//	if ( count_ & 0x0010 ) LED_enable(4);  else  LED_disable(4);
//	if ( count_ & 0x0020 ) LED_enable(5);  else  LED_disable(5);
//	if ( count_ & 0x0040 ) LED_enable(6);  else  LED_disable(6);
//	if ( count_ & 0x0080 ) LED_enable(7);  else  LED_disable(7);
}

void LED_enable(int index) {
	led_data_ |= ( 1 << index );
	update_led_data_();
}

void LED_disable(int index) {
	led_data_ &= ~( 1 << index );
	update_led_data_();
}

