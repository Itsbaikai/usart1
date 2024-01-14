
#include "user.h"

static int  b1_data_, b2_data_, b3_data_, b4_data_ ;
static int  b1_mark_, b2_mark_, b3_mark_, b4_mark_ ;

static void b1_pressed_(void) {
	if ( ++b1_mark_ & 1 ) LED_enable(4); else LED_disable(4);
}
static void b2_pressed_(void) {
	if ( ++b2_mark_ & 1 ) LED_enable(5); else LED_disable(5);
}
static void b3_pressed_(void) {
	if ( ++b3_mark_ & 1 ) LED_enable(6); else LED_disable(6);
}
static void b4_pressed_(void) {
	if ( ++b4_mark_ & 1 ) LED_enable(7); else LED_disable(7);
}

void KEY_init(void) {
	b1_data_ = b2_data_ = b3_data_ = b4_data_ = 0 ;
	b1_mark_ = b2_mark_ = b3_mark_ = b4_mark_ = 0 ;
}

void KEY_proc(void) {
	b1_data_ <<= 1 ;
	b2_data_ <<= 1 ;
	b3_data_ <<= 1 ;
	b4_data_ <<= 1 ;
	if ( HAL_GPIO_ReadPin( GPIOB, GPIO_PIN_0 ) == 0 ) b1_data_ |= 1 ;
	if ( HAL_GPIO_ReadPin( GPIOB, GPIO_PIN_1 ) == 0 ) b2_data_ |= 1 ;
	if ( HAL_GPIO_ReadPin( GPIOB, GPIO_PIN_2 ) == 0 ) b3_data_ |= 1 ;
	if ( HAL_GPIO_ReadPin( GPIOA, GPIO_PIN_0 ) == 0 ) b4_data_ |= 1 ;
	if ( ( b1_data_ & 7 ) == 3 ) b1_pressed_();
	if ( ( b2_data_ & 7 ) == 3 ) b2_pressed_();
	if ( ( b3_data_ & 7 ) == 3 ) b3_pressed_();
	if ( ( b4_data_ & 7 ) == 3 ) b4_pressed_();
}

