
#ifndef CORE_USER_USER_H__
#define CORE_USER_USER_H__

#include "stm32g4xx_hal.h"

void USER_init(void);
void USER_proc(void);
void USER_waitTo(uint32_t tick);

void LED_init(void);
void LED_proc(void);
void LED_enable(int index);
void LED_disable(int index);

void KEY_init(void);
void KEY_proc(void);

void USART1_init(UART_HandleTypeDef *pUsart);
void USART1_proc(void);
int  USART1_send(const char *buf,int len);
int  USART1_recv(char *buf);


#endif /* CORE_USER_USER_H__ */
