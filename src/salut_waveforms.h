/*
 * salut_waveforms.h - Statically Allocated Look-Up Table (SALUT) waveforms
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
 
#ifndef SALUT_WAVEFORMS_H
#define SALUT_WAVEFORMS_H

#define _LUT_PI         3.14159265358979323846f
#define _LUT_FRAC(x)    ((x) - (int)(x))
#define _LUT_ABS(a)     ((a) >= 0 ? (a) : -(a))

#define _LUT_BHASKARA_SINE_UNIT(x) \
    (16.0f * ((x) * _LUT_PI) * (_LUT_PI - ((x) * _LUT_PI)) / (5.0f * _LUT_PI * _LUT_PI - 4.0f * (x) * _LUT_PI * (_LUT_PI - ((x) * _LUT_PI))))

// Sine wave, Bhaskara's approximation
#define LUT_FUNC_SINE_WAVE(i, A, dc) ( \
    (((i) < (LUT_SIZE/2)) \
        ? _LUT_BHASKARA_SINE_UNIT((2.0f * (i)) / (float)(LUT_SIZE)) \
        : -_LUT_BHASKARA_SINE_UNIT((2.0f * ((i) - (LUT_SIZE/2))) / (float)(LUT_SIZE)) ) * (A) + (dc) )

// Cosine wave, Bhaskara's approximation
#define LUT_FUNC_COSINE_WAVE(i, A, dc) \
    LUT_FUNC_SINE_WAVE((((i) + ((LUT_SIZE)/4)) % (LUT_SIZE)), A, dc)

// Square wave
#define LUT_FUNC_SQUARE_WAVE(i, A, dc, duty) \
    (((_LUT_FRAC((i)/(float)(LUT_SIZE)) < (duty)) ? 1.0f : -1.0f) * (A) + (dc))

// Triangle wave
#define LUT_FUNC_TRIANGLE_WAVE(i, A, dc) \
    ((1.0f - 4.0f * _LUT_ABS(_LUT_FRAC((i)/(float)(LUT_SIZE)) - 0.5f)) * (A) + (dc))

// Sawtooth wave
#define LUT_FUNC_SAWTOOTH_WAVE(i, A, dc) \
    ((2.0f * _LUT_FRAC((i)/(float)(LUT_SIZE)) - 1.0f) * (A) + (dc))

#endif /* SALUT_WAVEFORMS_H */