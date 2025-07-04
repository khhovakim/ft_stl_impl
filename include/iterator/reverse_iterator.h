#ifndef   __FT_REVERSE_ITERATOR__
# define  __FT_REVERSE_ITERATOR__

# include "iterator_base_types.h" // For iterator tags

namespace ft {

  /// @brief Reverse iterator for iterators.
  /// This class provides a reverse iterator that iterates over a given iterator type in reverse order.
  /// It is designed to work with any iterator type that meets the requirements of a bidirectional iterator.
  template <typename _Iter>
  class reverse_iterator
  {
    public:
      using iterator_type     = _Iter;                      ///< The type of the underlying iterator.
      using value_type        = value_type_t<_Iter>;        ///< The type of the value pointed to by the iterator.
      using difference_type   = difference_type_t<_Iter>;   ///< The type used for representing the difference between two iterators.
      using pointer           = pointer_t<_Iter>;           ///< Pointer type to the value.
      using reference         = reference_t<_Iter>;         ///< Reference type to the value.
      using iterator_category = iterator_category_t<_Iter>; ///< The category of the iterator.

    public:
      /// @brief Default constructor.
      constexpr
      reverse_iterator() : m_current{ } { }

      /// @brief Constructor that takes an iterator.
      /// @param __x The iterator to be reversed.
      explicit constexpr
      reverse_iterator(iterator_type __x) : m_current{ __x } { }

      /// @brief Copy constructor.
      /// @param __x The reverse iterator to copy from.
      template <typename _Iter2>
      constexpr
      reverse_iterator(const reverse_iterator<_Iter2>& __x)
        : m_current{ __x.base() } { }

      /// @brief Assignment operator.
      /// @param __x The reverse iterator to assign from.
      /// @return A reference to this reverse iterator.
      template <typename _Iter2>
      constexpr reverse_iterator&
      operator=(const reverse_iterator<_Iter2>& __x)
      {
        if ( this == &__x ) {
          return *this;
        }
        m_current = __x.base();
        return *this;
      }

    public:
      /// @brief Returns the base iterator.
      /// @return The base iterator.
      constexpr iterator_type
      base() const { return m_current; }

    public:
      /// @brief Dereference operator.
      /// @return A reference to the value pointed to by the iterator.
      constexpr reference
      operator*() const
      {
        iterator_type __tmp = m_current;
        --__tmp;
        return *__tmp;
      }

      /// @brief Arrow operator.
      /// @return A pointer to the value pointed to by the iterator.
      constexpr pointer
      operator->() const { return &this->operator*(); }

    public:
      /// @brief Pre-increment operator.
      /// @return A reference to the reverse iterator after incrementing.
      constexpr reverse_iterator&
      operator++()
      {
        --m_current;
        return *this;
      }
      
      /// @brief Post-increment operator.
      /// @return A copy of the reverse iterator before incrementing.
      constexpr reverse_iterator
      operator++(int)
      {
        reverse_iterator __tmp = *this;
        --m_current;
        return __tmp;
      }

      /// @brief Pre-decrement operator.
      /// @return A reference to the reverse iterator after decrementing.
      constexpr reverse_iterator&
      operator--()
      {
        ++m_current;
        return *this;
      }

      /// @brief Post-decrement operator.
      /// @return A copy of the reverse iterator before decrementing.
      constexpr reverse_iterator
      operator--(int)
      {
        reverse_iterator __tmp = *this;
        ++m_current;
        return __tmp;
      }

    public:
      /// @brief Addition operator.
      /// @param __n The number of positions to move forward.
      /// @return A new reverse iterator moved forward by __n positions.
      constexpr reverse_iterator
      operator+(difference_type __n) const
      {
        return reverse_iterator(m_current - __n);
      }
      
      /// @brief Subtraction operator.
      /// @param __n The number of positions to move backward.
      /// @return A new reverse iterator moved backward by __n positions.
      constexpr reverse_iterator
      operator-(difference_type __n) const
      {
        return reverse_iterator(m_current + __n);
      }

      /// @brief Addition assignment operator.
      /// @param __n The number of positions to move forward.
      /// @return A reference to this reverse iterator after moving forward.
      constexpr reverse_iterator&
      operator+=(difference_type __n)
      {
        m_current -= __n;
        return *this;
      }

      /// @brief Subtraction assignment operator.
      /// @param __n The number of positions to move backward.
      /// @return A reference to this reverse iterator after moving backward.
      constexpr reverse_iterator&
      operator-=(difference_type __n)
      {
        m_current += __n;
        return *this;
      }

    private:
      iterator_type m_current; ///< The current position of the reverse iterator.

  };
  /// @brief Returns a reverse iterator from a given iterator.
  /// @param __x The iterator to be reversed.
  /// @return A reverse iterator pointing to the same element as __x.
  template <typename _Iter>
  constexpr reverse_iterator<_Iter>
  make_reverse_iterator(_Iter __x)
  {
    return reverse_iterator<_Iter>(__x);
  }

  /// @brief Returns a reverse iterator from a given const iterator.
  /// @param __x The const iterator to be reversed.
  /// @return A reverse iterator pointing to the same element as __x.
  template <typename _Iter>
  constexpr reverse_iterator<const _Iter>
  make_reverse_iterator(const _Iter __x)
  {
    return reverse_iterator<const _Iter>(__x);
  }

  /// @brief boolean operator for reverse iterator equality.
  /// @param __x The reverse iterator to compare with.
  /// @return True if the iterators are equal, false otherwise.
  template <typename _Iter1, typename _Iter2>
  constexpr bool
  operator==(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
  {
    return __x.base() == __y.base();
  }

  /// @brief boolean operator for reverse iterator inequality.
  /// @param __x The reverse iterator to compare with.
  /// @return True if the iterators are not equal, false otherwise.
  template <typename _Iter1, typename _Iter2>
  constexpr bool
  operator!=(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
  {
    return !(__x == __y);
  }

  /// @brief Less than operator for reverse iterators.
  /// @param __x The reverse iterator to compare with.
  /// @return True if this iterator is less than the other, false otherwise.
  template <typename _Iter1, typename _Iter2>
  constexpr bool
  operator<(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
  {
    return __y.base() < __x.base();
  }

  /// @brief Greater than operator for reverse iterators.
  /// @param __x The reverse iterator to compare with.
  /// @return True if this iterator is greater than the other, false otherwise.
  template <typename _Iter1, typename _Iter2>
  constexpr bool
  operator>(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
  {
    return __y.base() > __x.base();
  }

  /// @brief Less than or equal to operator for reverse iterators.
  /// @param __x The reverse iterator to compare with.
  /// @return True if this iterator is less than or equal to the other, false otherwise.
  template <typename _Iter1, typename _Iter2>
  constexpr bool
  operator<=(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
  {
    return !(__y < __x);
  }

  /// @brief Greater than or equal to operator for reverse iterators.
  /// @param __x The reverse iterator to compare with.
  /// @return True if this iterator is greater than or equal to the other, false otherwise.
  template <typename _Iter1, typename _Iter2>
  constexpr bool
  operator>=(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
  {
    return !(__y > __x);
  }

  /// @brief Addition operator for reverse iterators.
  /// @param __x The reverse iterator to add to.
  /// @param __n The number of positions to move forward.
  /// @return A new reverse iterator moved forward by __n positions.
  template <typename _Iter>
  constexpr reverse_iterator<_Iter>
  operator+(const reverse_iterator<_Iter>& __x, typename reverse_iterator<_Iter>::difference_type __n)
  {
    return reverse_iterator<_Iter>(__x.base() - __n);
  }

  /// @brief Subtraction operator for reverse iterators.
  /// @param __x The reverse iterator to subtract from.
  /// @param __n The number of positions to move backward.
  /// @return A new reverse iterator moved backward by __n positions.
  template <typename _Iter>
  constexpr reverse_iterator<_Iter>
  operator-(const reverse_iterator<_Iter>& __x, typename reverse_iterator<_Iter>::difference_type __n)
  {
    return reverse_iterator<_Iter>(__x.base() + __n);
  }

  /// @brief Difference between two reverse iterators.
  /// @param __x The first reverse iterator.
  /// @param __y The second reverse iterator.
  /// @return The difference in positions between the two iterators.
  template <typename _Iter1, typename _Iter2>
  constexpr typename reverse_iterator<_Iter1>::difference_type
  operator-(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
  {
    return __y.base() - __x.base();
  }

  /// @brief Addition assignment operator for reverse iterators.
} // namespace ft
#endif // __FT_REVERSE_ITERATOR__