/*
 * salut_core.h - Statically Allocated Look-Up Table (SALUT) core
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
 */

#ifndef SALUT_CORE_H
#define SALUT_CORE_H

#include <stddef.h>

// Size extremums
#define _LUT_SIZE_MIN	(1)
#define _LUT_SIZE_MAX	(65535)

// Single-entry macro
#define _LUT_E(i)	[i] = (LUT_FUNC(i)),

// Check if the nth bit is set (1)
#define _LUT_HAS_BIT(n)	((LUT_SIZE) & (1u << (n)))

// Helper to invoke a block
#define _LUT_EMIT(n)	_LUT_BEXP##n(_LUT_OFF##n)

// Helper macro to paste the accessor function name together
#define _LUT_PASTE(a,b)	a##b

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

#endif /* SALUT_CORE_H */