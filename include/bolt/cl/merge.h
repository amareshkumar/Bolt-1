/***************************************************************************
*   � 2012,2014 Advanced Micro Devices, Inc. All rights reserved.
*
*   Licensed under the Apache License, Version 2.0 (the "License");
*   you may not use this file except in compliance with the License.
*   You may obtain a copy of the License at
*
*       http://www.apache.org/licenses/LICENSE-2.0
*
*   Unless required by applicable law or agreed to in writing, software
*   distributed under the License is distributed on an "AS IS" BASIS,
*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*   See the License for the specific language governing permissions and
*   limitations under the License.

***************************************************************************/

#if !defined( BOLT_CL_MERGE_H )
#define BOLT_CL_MERGE_H
#pragma once

#include "bolt/cl/device_vector.h"
#include "bolt/cl/functional.h"

/*! \file bolt/cl/merge.h
    \brief Returns the result of combining all the elements in the specified range using the specified.
*/



namespace bolt {
    namespace cl {

        /*! \addtogroup algorithms
         */
		
		/*! \addtogroup merging
        *   \ingroup algorithms
        */

        /*! \addtogroup CL-merge
        *   \ingroup merging
        *   \{
        */

		
        /*! \brief \p merge returns the result of combining the two sorted range [first1, last1] and [first2, last2] in
        * to a single sorted range [result , result + (last1-first1) + ( last2-first2)]
        *
        *
        * \details The \p merge operation is similar the std::merge function
        *
        * \param ctl \b Optional Control structure to control command-queue, debug, tuning.
        * \param first1 The beginning of the first input range.
        * \param last1  The end of the first input range.
        * \param first2 The beginning of the second input range.
        * \param last2  The end of the second input range.
        * \param cl_code Optional OpenCL(TM) code to be passed to the OpenCL compiler. The cl_code is inserted first in
        * the generated code, before the cl_code trait.
        * \tparam InputIterator1 An iterator that can be dereferenced for an object, and can be incremented to get to
        * the next element in a sequence.
        * \tparam InputIterator2 An iterator that can be dereferenced for an object, and can be incremented to get to
        * the next element in a sequence.
        * \tparam OutputIteratoris a model of Output Iterator
        * \return The beginning of the merge result
        *
        * \details The following code example shows the use of \p merge
        * operator.
        * \code
        * #include <bolt/cl/merge.h>
        *
        * int a[5] = {1,3, 5, 7, 9};
        * int b [5] = {2,4,6,8,10};
        * int r[10];
        * int *r_end = bolt::cl::merge(a, a+5,b,b+5,r);
        * // r = 1,2,3,4,5,6,7,8,9,10
        *  \endcode
        * \sa http://www.sgi.com/tech/stl/merge.html
        */

        template<typename InputIterator1 , typename InputIterator2 , typename OutputIterator >
        OutputIterator merge (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
        InputIterator2 last2, OutputIterator result,const std::string& cl_code="" );

        template<typename InputIterator1 , typename InputIterator2 , typename OutputIterator >
        OutputIterator merge (bolt::cl::control &ctl,InputIterator1 first1, InputIterator1 last1,
        InputIterator2 first2,InputIterator2 last2, OutputIterator result,const std::string& cl_code="" );

        /*! \brief \p merge returns the result of combining the two sorted range [first1, last1] and [first2, last2] in
        * to a single sorted range [result , result + (last1-first1) + ( last2-first2)]
        *
        *
        * \details The \p merge operation is similar the std::merge function
        *
        * \param ctl \b Optional Control structure to control command-queue, debug, tuning.
        * \param first1 The beginning of the first input range.
        * \param last1  The end of the first input range.
        * \param first2 The beginning of the second input range.
        * \param last2  The end of the second input range.
        * \param comp Comparison operator.
        * \param cl_code Optional OpenCL(TM) code to be passed to the OpenCL compiler. The cl_code is inserted first in
        * the generated code, before the cl_code trait.
        * \tparam InputIterator1 An iterator that can be dereferenced for an object, and can be incremented to get to
        * the next element in a sequence.
        * \tparam InputIterator2 An iterator that can be dereferenced for an object, and can be incremented to get to
        * the next element in a sequence.
        * \tparam OutputIteratoris a model of Output Iterator
        * \tparam StrictWeakCompare is a model of Strict Weak Ordering.
        * \return The beginning of the merge result.
        *
        * \details The following code example shows the use of \p merge
        * operator.
        * \code
        * #include <bolt/cl/merge.h>
        *
        * int a[5] = {9,7, 5, 3, 1};
        * int b [5] = {10,8,6,4,2};
        * int r[10];
        * int *r_end = bolt::cl::merge(a, a+5,b,b+5,r,bolt::cl::greater<int>());
        * // r = 10,9,8,7,6,5,4,3,2,1
        \endcode
        * \sa http://www.sgi.com/tech/stl/merge.html
        */
        template<typename InputIterator1 , typename InputIterator2 , typename OutputIterator,
            typename StrictWeakCompare>
        OutputIterator merge (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
        InputIterator2 last2, OutputIterator result,StrictWeakCompare comp, const std::string& cl_code="" );

        template<typename InputIterator1 , typename InputIterator2 , typename OutputIterator,
             typename StrictWeakCompare>
        OutputIterator merge (bolt::cl::control &ctl,InputIterator1 first1, InputIterator1 last1,
        InputIterator2 first2,InputIterator2 last2, OutputIterator result,StrictWeakCompare comp,
        const std::string& cl_code="" );

        /*!   \}  */

    };
};

#include <bolt/cl/detail/merge.inl>
#endif
