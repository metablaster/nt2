//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_BLAS_DETAILS_BLAS2_HPP_INCLUDED
#define NT2_BLAS_DETAILS_BLAS2_HPP_INCLUDED

#include <nt2/blas/details/wrapper.hpp>


extern "C"
{
  // Real, double precision
  void NT2_F77NAME(dger)(const nt2_la_int* M, const nt2_la_int* N, const double* alpha,
                         const double* dx, const nt2_la_int* incx, const double* dy,
                         const nt2_la_int* incy, double* A, const nt2_la_int* lda);

  void NT2_F77NAME(dsyr)(const char* uplo, const nt2_la_int* N, const double* alpha,
                         const double* dx, const nt2_la_int* incx, double* A,
                         const nt2_la_int* lda);

  void NT2_F77NAME(dspr)(const char* uplo, const nt2_la_int* N, const double* alpha,
                         const double* dx, const nt2_la_int* incx, double* A);

  void NT2_F77NAME(dsyr2)(const char* uplo, const nt2_la_int* N, const double* alpha,
                          const double* dx, const nt2_la_int* incx, const double* dy,
                          const nt2_la_int* incy, double* A, const nt2_la_int* lda);

  void NT2_F77NAME(dspr2)(const char* uplo, const nt2_la_int* N, const double* alpha,
                          const double* dx, const nt2_la_int* incx, const double* dy,
                          const nt2_la_int* incy, double* A);
  void NT2_F77NAME(dgemv)(const char* trans, const nt2_la_int* M, const nt2_la_int* N,
                          const double* alpha, const double* A, const nt2_la_int* lda,
                          const double* dx, const nt2_la_int* incx, const double* beta,
                          double* dy, const nt2_la_int* incy);

  void NT2_F77NAME(dgbmv)(const char* trans, const nt2_la_int* M, const nt2_la_int* N,
                          const nt2_la_int* kl, const nt2_la_int* ku, const double* alpha,
                          const double* A, const nt2_la_int* lda, const double* dx,
                          const nt2_la_int* incx, const double* beta, double* dy,
                          const nt2_la_int* incy);

  void NT2_F77NAME(dsymv)(const char* uplo, const nt2_la_int* N, const double* alpha,
                          const double* A, const nt2_la_int* lda, const double* dx,
                          const nt2_la_int* incx, const double* beta, double* dy,
                          const nt2_la_int* incy);

  void NT2_F77NAME(dsbmv)(const char* uplo, const nt2_la_int* N, const nt2_la_int* k,
                          const double* alpha, const double* A, const nt2_la_int* lda,
                          const double* dx, const nt2_la_int* incx, const double* beta,
                          double* dy, const nt2_la_int* incy);

  void NT2_F77NAME(dspmv)(const char* uplo, const nt2_la_int* N, const double* alpha,
                          const double* A, const double* dx, const nt2_la_int* incx,
                          const double* beta, double* dy, const nt2_la_int* incy);

  void NT2_F77NAME(dtrmv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N, const double* A, const nt2_la_int* lda,
                          double* dx, const nt2_la_int* incx);

  void NT2_F77NAME(dtpmv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N, const double* A,
                          double* dx, const nt2_la_int* incx);

  void NT2_F77NAME(dtbmv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N, const nt2_la_int* K, const double* A,
                          const nt2_la_int* lda, double* dx, const nt2_la_int* incx);

  void NT2_F77NAME(dtrsv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N, const double* A, const nt2_la_int* lda,
                          double* dx, const nt2_la_int* incx);

  void NT2_F77NAME(dtpsv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N, const double* A,
                          double* dx, const nt2_la_int* incx);

  void NT2_F77NAME(dtbsv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N, const nt2_la_int* K, const double* A,
                          const nt2_la_int* lda, double* dx, const nt2_la_int* incx);

  // Real, simple precision
  void NT2_F77NAME(sgemv)(const char* trans, const nt2_la_int* M, const nt2_la_int* N,
                          const float* alpha, const float* A, const nt2_la_int* lda,
                          const float* dx, const nt2_la_int* incx, const float* beta,
                          float* dy, const nt2_la_int* incy);

  void NT2_F77NAME(sgbmv)(const char* trans, const nt2_la_int* M, const nt2_la_int* N,
                          const nt2_la_int* kl, const nt2_la_int* ku, const float* alpha,
                          const float* A, const nt2_la_int* lda, const float* dx,
                          const nt2_la_int* incx, const float* beta, float* dy,
                          const nt2_la_int* incy);

  void NT2_F77NAME(ssymv)(const char* uplo, const nt2_la_int* N, const float* alpha,
                          const float* A, const nt2_la_int* lda, const float* dx,
                          const nt2_la_int* incx, const float* beta, float* dy,
                          const nt2_la_int* incy);

  void NT2_F77NAME(ssbmv)(const char* uplo, const nt2_la_int* N, const nt2_la_int* k,
                          const float* alpha, const float* A, const nt2_la_int* lda,
                          const float* dx, const nt2_la_int* incx, const float* beta,
                          float* dy, const nt2_la_int* incy);

  void NT2_F77NAME(sspmv)(const char* uplo, const nt2_la_int* N, const float* alpha,
                          const float* A, const float* dx, const nt2_la_int* incx,
                          const float* beta, float* dy, const nt2_la_int* incy);

  void NT2_F77NAME(strmv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N, const float* A, const nt2_la_int* lda,
                          float* dx, const nt2_la_int* incx);

  void NT2_F77NAME(stpmv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N, const float* A,
                          float* dx, const nt2_la_int* incx);

  void NT2_F77NAME(stbmv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N, const nt2_la_int* K, const float* A,
                          const nt2_la_int* lda, const float* dx, const nt2_la_int* incx);

  void NT2_F77NAME(strsv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N, const float* A, const nt2_la_int* lda, float* dx,
                          const nt2_la_int* incx);

  void NT2_F77NAME(stbsv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N, const float* A, float* dx,
                          const nt2_la_int* incx);

  void NT2_F77NAME(stbsv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N, const float* Ap, float* dx,
                          const nt2_la_int* incx);

  void NT2_F77NAME(stpsv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N, const float* Ap, float* dx,
                          const nt2_la_int* incx);

  void NT2_F77NAME(sger)(const nt2_la_int* M, const nt2_la_int* N, const float* alpha,
                         const float* dx, const nt2_la_int* incx, const float* dy,
                         const nt2_la_int* incy, float* A, const nt2_la_int* lda);

  void NT2_F77NAME(ssyr)(const char* uplo, const nt2_la_int* N, const float* alpha,
                         const float* dx, const nt2_la_int* incx, float* A,
                         const nt2_la_int* lda);

  void NT2_F77NAME(sspr)(const char* uplo, const nt2_la_int* N, const float* alpha,
                         const float* dx, const nt2_la_int* incx, float* A);

  void NT2_F77NAME(ssyr2)(const char* uplo, const nt2_la_int* N, const float* alpha,
                          const float* dx, const nt2_la_int* incx, const float* dy,
                          const nt2_la_int* incy, float* A, const nt2_la_int* lda);

  void NT2_F77NAME(sspr2)(const char* uplo, const nt2_la_int* N, const float* alpha, const float* dx,
                          const nt2_la_int* incx, const float* dy, const nt2_la_int* incy, float* A);

  // complex, double precision
  void NT2_F77NAME(zgemv)(const char* trans, const nt2_la_int* M, const nt2_la_int* N,
                          const nt2_la_complex* alpha, const nt2_la_complex* A, const nt2_la_int* lda,
                          const nt2_la_complex* dx, const nt2_la_int* incx, const nt2_la_complex* beta,
                          nt2_la_complex* dy, const nt2_la_int* incy);

  void NT2_F77NAME(zgbmv)(const char* trans, const nt2_la_int* M, const nt2_la_int* N,
                          const nt2_la_int* kl, const nt2_la_int* ku, const nt2_la_complex* alpha,
                          const nt2_la_complex* A, const nt2_la_int* lda, const nt2_la_complex* dx,
                          const nt2_la_int* incx, const nt2_la_complex* beta, nt2_la_complex* dy,
                          const nt2_la_int* incy);

  void NT2_F77NAME(zhemv)(const char* uplo, const nt2_la_int* N, const nt2_la_complex* alpha,
                          const nt2_la_complex* A, const nt2_la_int* lda, const nt2_la_complex* dx,
                          const nt2_la_int* incx, const nt2_la_complex* beta, nt2_la_complex* dy,
                          const nt2_la_int* incy);

  void NT2_F77NAME(zsymv)(const char* uplo, const nt2_la_int* N, const nt2_la_complex* alpha,
                          const nt2_la_complex* A, const nt2_la_int* lda, const nt2_la_complex* dx,
                          const nt2_la_int* incx, const nt2_la_complex* beta, nt2_la_complex* dy,
                          const nt2_la_int* incy);

  void NT2_F77NAME(zspmv)(const char* uplo, const nt2_la_int* N, const nt2_la_complex* alpha,
                          const nt2_la_complex* A, const nt2_la_complex* dx,
                          const nt2_la_int* incx, const nt2_la_complex* beta, nt2_la_complex* dy,
                          const nt2_la_int* incy);
  void NT2_F77NAME(zhbmv)(const char* uplo, const nt2_la_int* N, const nt2_la_int* k,
                          const nt2_la_complex* alpha, const nt2_la_complex* A, const nt2_la_int* lda,
                          const nt2_la_complex* dx, const nt2_la_int* incx, const nt2_la_complex* beta,
                          nt2_la_complex* dy, const nt2_la_int* incy);

  void NT2_F77NAME(zhpmv)(const char* uplo, const nt2_la_int* N, const nt2_la_complex* alpha,
                          const nt2_la_complex* A, const nt2_la_complex* dx, const nt2_la_int* incx,
                          const nt2_la_complex* beta, nt2_la_complex* dy, const nt2_la_int* incy);

  void NT2_F77NAME(ztrmv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N, const nt2_la_complex* A, const nt2_la_int* lda,
                          nt2_la_complex* dx, const nt2_la_int* incx);

  void NT2_F77NAME(ztpmv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N, const nt2_la_complex* A,
                          nt2_la_complex* dx, const nt2_la_int* incx);
  void NT2_F77NAME(ztbmv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N, const nt2_la_int* K, const nt2_la_complex* A,
                          const nt2_la_int* lda, nt2_la_complex* dx, const nt2_la_int* incx);

  void NT2_F77NAME(ztrsv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N, const nt2_la_complex* A, const nt2_la_int* lda,
                          nt2_la_complex* dx, const nt2_la_int* incx);

  void NT2_F77NAME(ztbsv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N, const nt2_la_int* K, const nt2_la_complex* A,
                          const nt2_la_int* lda, nt2_la_complex* dx, const nt2_la_int* incx);

  void NT2_F77NAME(ztpsv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N, const nt2_la_complex* Ap, nt2_la_complex* dx,
                          const nt2_la_int* incx);

  void NT2_F77NAME(zgerc)(const nt2_la_int* M, const nt2_la_int* N, const nt2_la_complex* alpha,
                          const nt2_la_complex* dx, const nt2_la_int* incx, const nt2_la_complex* dy,
                          const nt2_la_int* incy, nt2_la_complex* A, const nt2_la_int* lda);

  void NT2_F77NAME(zgeru)(const nt2_la_int* M, const nt2_la_int* N, const nt2_la_complex* alpha,
                          const nt2_la_complex* dx, const nt2_la_int* incx, const nt2_la_complex* dy,
                          const nt2_la_int* incy, nt2_la_complex* A, const nt2_la_int* lda);

  void NT2_F77NAME(zher)(const char* uplo, const nt2_la_int* N, const double* alpha,
                         const nt2_la_complex* dx, const nt2_la_int* incx, nt2_la_complex* A,
                         const nt2_la_int* lda);

  void NT2_F77NAME(zsyr)(const char* uplo, const nt2_la_int* N, const nt2_la_complex* alpha,
                         const nt2_la_complex* dx, const nt2_la_int* incx, nt2_la_complex* A,
                         const nt2_la_int* lda);

  void NT2_F77NAME(zspr)(const char* uplo, const nt2_la_int* N, const nt2_la_complex* alpha,
                         const nt2_la_complex* dx, const nt2_la_int* incx, nt2_la_complex* A);

  void NT2_F77NAME(zher2)(const char* uplo, const nt2_la_int* N, const nt2_la_complex* alpha,
                          const nt2_la_complex* dx, const nt2_la_int* incx, const nt2_la_complex* dy,
                          const nt2_la_int* incy, nt2_la_complex* A, const nt2_la_int* lda);

  void NT2_F77NAME(zspr2)(const char* uplo, const nt2_la_int* N, const nt2_la_complex* alpha,
                          const nt2_la_complex* dx, const nt2_la_int* incx, const nt2_la_complex* dy,
                          const nt2_la_int* incy, nt2_la_complex* A);

  // complex, simple precision
  void NT2_F77NAME(cgemv)(const char* trans, const nt2_la_int* M, const nt2_la_int* N,
                          const nt2_la_complex* alpha, const nt2_la_complex* A, const nt2_la_int* lda,
                          const nt2_la_complex* dx, const nt2_la_int* incx, const nt2_la_complex* beta,
                          nt2_la_complex* dy, const nt2_la_int* incy);

  void NT2_F77NAME(cgbmv)(const char* trans, const nt2_la_int* M, const nt2_la_int* N,
                          const nt2_la_int* kl, const nt2_la_int* ku, const nt2_la_complex* alpha,
                          const nt2_la_complex* A, const nt2_la_int* lda, const nt2_la_complex* dx,
                          const nt2_la_int* incx, const nt2_la_complex* beta, nt2_la_complex* dy,
                          const nt2_la_int* incy);

  void NT2_F77NAME(chemv)(const char* uplo, const nt2_la_int* N, const nt2_la_complex* alpha,
                          const nt2_la_complex* A, const nt2_la_int* lda, const nt2_la_complex* dx,
                          const nt2_la_int* incx, const nt2_la_complex* beta, nt2_la_complex* dy,
                          const nt2_la_int* incy);

  void NT2_F77NAME(csymv)(const char* uplo, const nt2_la_int* N, const nt2_la_complex* alpha,
                          const nt2_la_complex* A, const nt2_la_int* lda, const nt2_la_complex* dx,
                          const nt2_la_int* incx, const nt2_la_complex* beta, nt2_la_complex* dy,
                          const nt2_la_int* incy);

  void NT2_F77NAME(chbmv)(const char* uplo, const nt2_la_int* N, const nt2_la_int* k,
                          const nt2_la_complex* alpha, const nt2_la_complex* A, const nt2_la_int* lda,
                          const nt2_la_complex* dx, const nt2_la_int* incx, const nt2_la_complex* beta,
                          nt2_la_complex* dy, const nt2_la_int* incy);

  void NT2_F77NAME(chpmv)(const char* uplo, const nt2_la_int* N, const nt2_la_complex* alpha,
                          const nt2_la_complex* A, const nt2_la_complex* dx, const nt2_la_int* incx,
                          const nt2_la_complex* beta, nt2_la_complex* dy, const nt2_la_int* incy);

  void NT2_F77NAME(cspmv)(const char* uplo, const nt2_la_int* N, const nt2_la_complex* alpha,
                          const nt2_la_complex* A, const nt2_la_complex* dx, const nt2_la_int* incx,
                          const nt2_la_complex* beta, nt2_la_complex* dy, const nt2_la_int* incy);

  void NT2_F77NAME(ctpmv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N, const nt2_la_complex* A,
                          nt2_la_complex* dx, const nt2_la_int* incx);

  void NT2_F77NAME(ctrmv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N, const nt2_la_complex* A, const nt2_la_int* lda,
                          nt2_la_complex* dx, const nt2_la_int* incx);

  void NT2_F77NAME(ctbmv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N, const nt2_la_int* K, const nt2_la_complex* A,
                          const nt2_la_int* lda, nt2_la_complex* dx, const nt2_la_int* incx);

  void NT2_F77NAME(ctrsv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N, const nt2_la_complex* A, const nt2_la_int* lda,
                          nt2_la_complex* dx, const nt2_la_int* incx);

  void NT2_F77NAME(ctbsv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N, const nt2_la_int* K, const nt2_la_complex* A,
                          const nt2_la_int* lda, nt2_la_complex* dx, const nt2_la_int* incx);

  void NT2_F77NAME(ctpsv)(const char* uplo, const char* trans, const char* diag,
                          const nt2_la_int* N,  const nt2_la_complex* Ap, nt2_la_complex* dx,
                          const nt2_la_int* incx);

  void NT2_F77NAME(cgerc)(const nt2_la_int* M, const nt2_la_int* N, const nt2_la_complex* alpha,
                          const nt2_la_complex* dx, const nt2_la_int* incx, const nt2_la_complex* dy,
                          const nt2_la_int* incy, nt2_la_complex* A, const nt2_la_int* lda);
  void NT2_F77NAME(cgeru)(const nt2_la_int* M, const nt2_la_int* N, const nt2_la_complex* alpha,
                          const nt2_la_complex* dx, const nt2_la_int* incx, const nt2_la_complex* dy,
                          const nt2_la_int* incy, nt2_la_complex* A, const nt2_la_int* lda);

  void NT2_F77NAME(cher)(const char* uplo, const nt2_la_int* N, const float* alpha,
                         const nt2_la_complex* dx, const nt2_la_int* incx, nt2_la_complex* A,
                         const nt2_la_int* lda);

  void NT2_F77NAME(csyr)(const char* uplo, const nt2_la_int* N, const nt2_la_complex* alpha,
                         const nt2_la_complex* dx, const nt2_la_int* incx, nt2_la_complex* A,
                         const nt2_la_int* lda);

  void NT2_F77NAME(cspr)(const char* uplo, const nt2_la_int* N, const nt2_la_complex* alpha,
                         const nt2_la_complex* dx, const nt2_la_int* incx, nt2_la_complex* A);

  void NT2_F77NAME(cher2)(const char* uplo, const nt2_la_int* N, const nt2_la_complex* alpha,
                          const nt2_la_complex* dx, const nt2_la_int* incx, const nt2_la_complex* dy,
                          const nt2_la_int* incy, nt2_la_complex* A, const nt2_la_int* lda);
  void NT2_F77NAME(cspr2)(const char* uplo, const nt2_la_int* N, const nt2_la_complex* alpha,
                          const nt2_la_complex* dx, const nt2_la_int* incx, const nt2_la_complex* dy,
                          const nt2_la_int* incy, nt2_la_complex* A);
}

#endif
