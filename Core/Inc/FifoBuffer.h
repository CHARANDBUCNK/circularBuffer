/*
 * FifoBuffer.h
 *
 *	CIRCULAR FIFO BUFFER
 *
 *	!!!!!!!!!!!!!!!!!!!!!!!!!!this not a dynamic cast Buffer being careful
 *
 *  Created on: Dec 17, 2024
 *      Author: JOSE RODOLFO
 */

#ifndef INC_FIFOBUFFER_H_
#define INC_FIFOBUFFER_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef uint16_t 	itrBuffer_t ;
typedef itrBuffer_t sizeBuffer;

typedef struct Buffer_t buffer_t;

//read A element From buffer
#define READ_BUFFER( buffer , dataType) (*((dataType*)ReadBuffer(buffer)))

//write a element to buffer
#define WRITE_BUFFER ( buffer , dataType ) WriteBuffer( buffer ,  dataType  )

/**
  * @brief  crea un buffer de forma dinamica
  * @param  numberOfElements , el numero de elementos que tendra el buffer
  * @param	kindBuffer el tipo de dato, int, float etc.....
  * @retval retorna un puntero de una estructura
  * example code : TempVariable = CreateBuffer( 10 , sizeof(int)); muy importante sizeof
  * NOTE:
  */
buffer_t* CreateBuffer(sizeBuffer numberOfElements ,size_t kindBuffer );

/**
  * @brief  escribe dentro del buffer si se desborda regresa al origen
  * @param  pSBuffer, puntero a la estruta
  * @param	pElement es el valor a guardar en el buffer  int , floar ,char etc ...
  * @retval
  * example code : void WriteBuffer( pointer name , Variable pointer  )
  * NOTE: 	puede utilizar la macro WriteBuffer
  */
void WriteBuffer( buffer_t* pSBuffer , void* pElement );


/**
  * @brief  lee del buffer un valor y retorna el valor
  * @param  pSBuffer, puntero a la estructura
  * @retval retorna un puntero void que debe ser casteado para poder ser utilizado
  * example code : (*((dataType*)ReadBuffer(buffer)))
  * NOTE: 	puede utilizar la macro READ_BUFFER es mas amigable
  * example code  : char data  = READ_BUFFER( pointerBuffer , char) envez de char puede ser float ,int etc .....
  */
void* ReadBuffer( buffer_t* pSBuffer );


/**
  * @brief  borra el buffer y la estrucura que se crearon por malloc , no debe utilizarse,
  * 		si se creo con memoria estatica
  * @param  pParameters, puntero a la estructura
  * @retval void
  */
void EraseBuffer( buffer_t* pParameters );

#endif /* INC_FIFOBUFFER_H_ */
