/*****************************************************************************
 * FFT3DFilter.h
 *****************************************************************************
 * Lite version of fftw header on base of fftw3.h
 * some needed fftwf typedefs added for delayed loading
 *
 * Copyright (C) 2004-2006 A.G.Balakhnin aka Fizick <bag@hotmail.ru> http://avisynth.org.ru
 * Copyright (C) 2015      Yusuke Nakamura, <muken.the.vfrmaniac@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *****************************************************************************/

#ifndef __FFTWLITE_H__
#define __FFTWLITE_H__
using fftwf_complex = float [2];
using fftwf_plan    = struct fftwf_plan_s *;
using fftwf_malloc_proc            = fftwf_complex * (*)( size_t n );
using fftwf_free_proc              = void (*)( void *ppp );
using fftwf_plan_dft_r2c_2d_proc   = fftwf_plan (*)( int winy, int winx, float *realcorrel, fftwf_complex *correl, int flags );
using fftwf_plan_dft_c2r_2d_proc   = fftwf_plan (*)( int winy, int winx, fftwf_complex *correl, float *realcorrel, int flags );
using fftwf_plan_many_dft_r2c_proc = fftwf_plan (*)( int rank, const int *n, int howmany, float *in, const int *inembed, int istride, int idist, fftwf_complex *out, const int *onembed, int ostride, int odist, unsigned flags );
using fftwf_plan_many_dft_c2r_proc = fftwf_plan (*)( int rank, const int *n, int howmany, fftwf_complex *out, const int *inembed, int istride, int idist, float *in, const int *onembed, int ostride, int odist, unsigned flags );
using fftwf_destroy_plan_proc      = void (*)( fftwf_plan );
using fftwf_execute_dft_r2c_proc   = void (*)( fftwf_plan, float *realdata, fftwf_complex *fftsrc );
using fftwf_execute_dft_c2r_proc   = void (*)( fftwf_plan, fftwf_complex *fftsrc, float *realdata );
#define FFTW_MEASURE (0U)
#define FFTW_ESTIMATE (1U << 6)
using fftwf_init_threads_proc       = int (*)();
using fftwf_plan_with_nthreads_proc = void (*)( int nthreads );
#endif
