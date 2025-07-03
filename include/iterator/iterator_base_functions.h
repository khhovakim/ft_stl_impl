#ifndef   __FT_ITERATOR_BASE_FUNCS__
# define  __FT_ITERATOR_BASE_FUNCS__

# include "iterator_base_types.h" // For iterator tags, iterator_traits

namespace ft {

  /// @brief A function to get the iterator category of an iterator.
  /// @details This function returns the iterator category of the given iterator.
  template <typename _Iter>
  inline constexpr iterator_category_t<_Iter>
  iterator_category(const _Iter&)
  {
    return iterator_category_t<_Iter>();
  }

  /// @brief A helper function to calculate the distance between two iterators.
  template <typename _InputIterator>
  inline constexpr
  difference_type_t<_InputIterator>
  __distance(_InputIterator __first, _InputIterator __last,
             input_iterator_tag)
  {
    difference_type_t<_InputIterator> __n = 0;

    while ( __first != __last )
    {
      ++__first;
      ++__n;
    }

    return __n;
  }

  /// @brief A helper function to calculate the distance between two random access iterators.
  template <typename _RandomAccessIterator>
  inline constexpr
  difference_type_t<_RandomAccessIterator>
  __distance(_RandomAccessIterator __first, _RandomAccessIterator __last,
             random_access_iterator_tag)
  {
    return __last - __first;
  }

  /// @brief A function to calculate the distance between two iterators.
  /// @details This function computes the number of increments needed to go from the first iterator to the second.
  /// It is a generalization of pointer arithmetic.
  template <typename _InputIterator>
  inline constexpr
  difference_type_t<_InputIterator>
  distance(_InputIterator __first, _InputIterator __last)
  {
    return ft::__distance(__first, __last, ft::__iterator_category(__first));
  }

  /// @brief A function to advance an iterator by a specified number of steps.
  /// @details This function modifies the iterator by moving it forward or backward by the specified number of steps.
  template <typename _InputIterator, typename _Distance>
  inline constexpr void
  __advance(_InputIterator& __i, _Distance __n, input_iterator_tag)
  {
    while ( __n-- > 0 )
      ++__i;
  }

  /// @brief A function to advance a bidirectional iterator by a specified number of steps.
  /// @details This function modifies the iterator by moving it forward or backward by the specified number of steps.
  template <typename _BidirectionalIterator, typename _Distance>
  inline constexpr void
  __advance(_BidirectionalIterator& __i, _Distance __n, bidirectional_iterator_tag)
  {
    if ( __n > 0 ) {
      while ( __n-- > 0 ) ++__i;
    } else {
      while ( __n++ < 0 ) --__i;
    }
  }

  /// @brief A function to advance a random access iterator by a specified number of steps.
  /// @details This function modifies the iterator by moving it forward or backward by the specified number of steps.
  template <typename _RandomAccessIterator, typename _Distance>
  inline constexpr void
  __advance(_RandomAccessIterator& __i, _Distance __n, random_access_iterator_tag)
  {
    __i += __n;
  }

  /// @brief A function to advance an iterator by a specified number of steps.
  /// @details This function modifies the iterator by moving it forward or backward by the specified number of steps.
  template <typename _InputIterator, typename _Distance>
  inline constexpr void
  advance(_InputIterator& __i, _Distance __n)
  {
    ft::__advance(__i, __n, ft::__iterator_category(__i));
  }

  /// @brief A function to get the next iterator.
  /// @details This function returns an iterator that is advanced by one step from the given iterator.
  template <typename _InputIterator>
  inline constexpr _InputIterator
  next(_InputIterator __x, difference_type_t<_InputIterator> __n = 1)
  {
    ft::advance(__x, __n);
    return __x;
  }

  /// @brief A function to get the previous iterator.
  /// @details This function returns an iterator that is moved back by one step from the given iterator.
  template <typename _BidirectionalIterator>
  inline constexpr _BidirectionalIterator
  prev(_BidirectionalIterator __x, difference_type_t<_BidirectionalIterator> __n = 1)
  {
    ft::advance(__x, -__n);
    return __x;
  }

} // namespace ft

#endif // __FT_ITERATOR_BASE_FUNCS__