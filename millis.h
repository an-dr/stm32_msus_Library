/*
 * @file millis.h
 *
 * @breaf millis.h  millis implementation. For the base was givven a cool idea from here http://micromouseusa.com/?p=296
 * 
 * @date Jan 6, 2019
 * @author Andrey Gramakov
 */

#ifndef MILLIS_H_
#define MILLIS_H_
/*                   */
#ifdef __cplusplus
extern "C"
{
#endif
    /*                   */

#include "main.h" // hal, cmsis, etc.
#include "stdbool.h"

    /*
     *
     */

    bool millis_Init(void);
    void millisInc();
    uint32_t millis(void);
    uint32_t micros(void);

/*                   */
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MILLIS_H_ */
