/*
 * salut_template.h - Statically Allocated Look-Up Table (SALUT) template
 * 
 * Copyright (c) 2025 Laurent Mailloux-Bourassa
 * 
 * This file is part of the Statically Allocated Look-Up Table (SALUT) library.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * To use:
 *     #define LUT_NAME    my_lut          // base identifier
 *     #define LUT_TYPE    float           // element type
 *     #define LUT_SIZE    100             // number of entries
 *     #define LUT_FUNC(i) (0.05f*(i)+1)  // any expression in i, where i is the index
 *     #include "salut_template.h"
 *
 *     // Now you have:
 *     //   static const LUT_TYPE my_lut[LUT_SIZE];
 *     //   inline LUT_TYPE my_lut_get(size_t index);
 *
 *     // These macros are undefined to make the template reusable for another LUT
 *     #undef LUT_NAME
 *     #undef LUT_TYPE
 *     #undef LUT_SIZE
 *     #undef LUT_FUNC
 */

#ifndef SALUT_H
    #include "salut.h"
#endif
#ifndef LUT_NAME
	#error "Must define LUT_NAME before including salut_template.h"
#endif
#ifndef LUT_TYPE
	#error "Must define LUT_TYPE before including salut_template.h"
#endif
#ifndef LUT_SIZE
	#error "Must define LUT_SIZE before including salut_template.h"
#endif
#ifndef LUT_FUNC
	#error "Must define LUT_FUNC(i) before including salut_template.h"
#endif

#define _LUT_OFF15  0
#if _LUT_HAS_BIT(15)
	#define _LUT_OFF14	(_LUT_OFF15 + (1<<15))
#else
	#define _LUT_OFF14	_LUT_OFF15
#endif

#if _LUT_HAS_BIT(14)
	#define _LUT_OFF13	(_LUT_OFF14 + (1<<14))
#else
	#define _LUT_OFF13	_LUT_OFF14
#endif

#if _LUT_HAS_BIT(13)
	#define _LUT_OFF12	(_LUT_OFF13 + (1<<13))
#else
	#define _LUT_OFF12	_LUT_OFF13
#endif

#if _LUT_HAS_BIT(12)
	#define _LUT_OFF11	(_LUT_OFF12 + (1<<12))
#else
	#define _LUT_OFF11	_LUT_OFF12
#endif

#if _LUT_HAS_BIT(11)
	#define _LUT_OFF10	(_LUT_OFF11 + (1<<11))
#else
	#define _LUT_OFF10 	_LUT_OFF11
#endif

#if _LUT_HAS_BIT(10)
	#define _LUT_OFF9	(_LUT_OFF10 + (1<<10))
#else
	#define _LUT_OFF9	_LUT_OFF10
#endif

#if _LUT_HAS_BIT(9)
	#define _LUT_OFF8	(_LUT_OFF9 + (1<<9))
#else
	#define _LUT_OFF8	_LUT_OFF9
#endif

#if _LUT_HAS_BIT(8)
	#define _LUT_OFF7	(_LUT_OFF8 + (1<<8))
#else
	#define _LUT_OFF7	_LUT_OFF8
#endif

#if _LUT_HAS_BIT(7)
	#define _LUT_OFF6	(_LUT_OFF7 + (1<<7))
#else
	#define _LUT_OFF6	_LUT_OFF7
#endif

#if _LUT_HAS_BIT(6)
	#define _LUT_OFF5	(_LUT_OFF6 + (1<<6))
#else
	#define _LUT_OFF5	_LUT_OFF6
#endif

#if _LUT_HAS_BIT(5)
	#define _LUT_OFF4	(_LUT_OFF5 + (1<<5))
#else
	#define _LUT_OFF4	_LUT_OFF5
#endif

#if _LUT_HAS_BIT(4)
	#define _LUT_OFF3	(_LUT_OFF4 + (1<<4))
#else
	#define _LUT_OFF3	_LUT_OFF4
#endif

#if _LUT_HAS_BIT(3)
	#define _LUT_OFF2	(_LUT_OFF3 + (1<<3))
#else
	#define _LUT_OFF2	_LUT_OFF3
#endif

#if _LUT_HAS_BIT(2)
	#define _LUT_OFF1	(_LUT_OFF2 + (1<<2))
#else
	#define _LUT_OFF1	_LUT_OFF2
#endif

#if _LUT_HAS_BIT(1)
	#define _LUT_OFF0	(_LUT_OFF1 + (1<<1))
#else
	#define _LUT_OFF0	_LUT_OFF1
#endif

// Build the table
static const LUT_TYPE LUT_NAME[LUT_SIZE] =
{
#if _LUT_HAS_BIT(15)
	_LUT_EMIT(15)
#endif
#if _LUT_HAS_BIT(14)
	_LUT_EMIT(14)
#endif
#if _LUT_HAS_BIT(13)
	_LUT_EMIT(13)
#endif
#if _LUT_HAS_BIT(12)
	_LUT_EMIT(12)
#endif
#if _LUT_HAS_BIT(11)
	_LUT_EMIT(11)
#endif
#if _LUT_HAS_BIT(10)
	_LUT_EMIT(10)
#endif
#if _LUT_HAS_BIT(9)
	_LUT_EMIT(9)
#endif
#if _LUT_HAS_BIT(8)
	_LUT_EMIT(8)
#endif
#if _LUT_HAS_BIT(7)
	_LUT_EMIT(7)
#endif
#if _LUT_HAS_BIT(6)
	_LUT_EMIT(6)
#endif
#if _LUT_HAS_BIT(5)
	_LUT_EMIT(5)
#endif
#if _LUT_HAS_BIT(4)
	_LUT_EMIT(4)
#endif
#if _LUT_HAS_BIT(3)
	_LUT_EMIT(3)
#endif
#if _LUT_HAS_BIT(2)
	_LUT_EMIT(2)
#endif
#if _LUT_HAS_BIT(1)
	_LUT_EMIT(1)
#endif
#if _LUT_HAS_BIT(0)
	_LUT_EMIT(0)
#endif
};

// Create the accessor
_LUT_ACCESSOR(LUT_NAME, LUT_TYPE, LUT_SIZE)

// Clean up internal helpers
#undef _LUT_OFF0
#undef _LUT_OFF1
#undef _LUT_OFF2
#undef _LUT_OFF3
#undef _LUT_OFF4
#undef _LUT_OFF5
#undef _LUT_OFF6
#undef _LUT_OFF7
#undef _LUT_OFF8
#undef _LUT_OFF9
#undef _LUT_OFF10
#undef _LUT_OFF11
#undef _LUT_OFF12
#undef _LUT_OFF13
#undef _LUT_OFF14
#undef _LUT_OFF15

// Clean up user macros so we can generate another LUT
#undef LUT_NAME
#undef LUT_TYPE
#undef LUT_SIZE
#undef LUT_FUNC

/* salut_template.h - EOF */
