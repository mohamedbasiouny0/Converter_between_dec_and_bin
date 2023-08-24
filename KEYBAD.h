/*
 * KEYBAD.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Mohamed
 */

#ifndef KEYBAD_H_
#define KEYBAD_H_

#define  NO_KEY   'T'
#define  k_port   PORT_B

void keybad_inti(void);
u8 keybad_PressKey(void);
#endif /* KEYBAD_H_ */
