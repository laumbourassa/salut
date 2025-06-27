/*
 * salut.h - Statically Allocated Look Up Table (SALUT) core
 * 
 * Copyright (c) 2025 Laurent Mailloux-Bourassa
 * 
 * This file is part of the Statically Allocated Look Up Table (SALUT) library.
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
#define SALUT_H

#include <stddef.h>

// Single-entry macro
#define _LUT_E(i)	[i] = (LUT_FUNC(i)),

// Check if the nth bit is set (1)
#define _LUT_HAS_BIT(n) ((LUT_SIZE) & (1u << (n)))

// Helper to invoke a block
#define _LUT_EMIT(n)    _LUT_BEXP##n(_LUT_OFF##n)

// Helper macro to paste the accessor function name together
#define _LUT_PASTE(a,b)  a##b

// Inline accessor
#define _LUT_ACCESSOR(name, type, size)						\
	static inline type _LUT_PASTE(name,_get)(size_t index)  \
	{														\
		return (index < size) ? name[index] : (type)0;		\
	}

// Power-of-two blocks built recursively
#define _LUT_BEXP0(s)   _LUT_E(s)
#define _LUT_BEXP1(s)   _LUT_BEXP0(s)   _LUT_BEXP0(((s)+1))
#define _LUT_BEXP2(s)   _LUT_BEXP1(s)   _LUT_BEXP1(((s)+2))
#define _LUT_BEXP3(s)   _LUT_BEXP2(s)   _LUT_BEXP2(((s)+4))
#define _LUT_BEXP4(s)   _LUT_BEXP3(s)   _LUT_BEXP3(((s)+8))
#define _LUT_BEXP5(s)   _LUT_BEXP4(s)   _LUT_BEXP4(((s)+16))
#define _LUT_BEXP6(s)   _LUT_BEXP5(s)   _LUT_BEXP5(((s)+32))
#define _LUT_BEXP7(s)   _LUT_BEXP6(s)   _LUT_BEXP6(((s)+64))
#define _LUT_BEXP8(s)   _LUT_BEXP7(s)   _LUT_BEXP7(((s)+128))
#define _LUT_BEXP9(s)   _LUT_BEXP8(s)   _LUT_BEXP8(((s)+256))
#define _LUT_BEXP10(s)  _LUT_BEXP9(s)   _LUT_BEXP9(((s)+512))
#define _LUT_BEXP11(s)  _LUT_BEXP10(s)  _LUT_BEXP10(((s)+1024))
#define _LUT_BEXP12(s)  _LUT_BEXP11(s)  _LUT_BEXP11(((s)+2048))
#define _LUT_BEXP13(s)  _LUT_BEXP12(s)  _LUT_BEXP12(((s)+4096))
#define _LUT_BEXP14(s)  _LUT_BEXP13(s)  _LUT_BEXP13(((s)+8192))
#define _LUT_BEXP15(s)  _LUT_BEXP14(s)  _LUT_BEXP14(((s)+16384))

#endif /* salut.h */
