#ifndef   __FT_PAIR__
# define  __FT_PAIR__

namespace ft {

  /// @brief Pair class template.
  /// @details This class template represents a pair of values, which can be of different types.
  /// It provides a simple way to store two related values together.
  /// 
  /// Usage:
  /// - Create a pair using `ft::pair<Type1, Type2>`.
  /// - Access the first and second elements using `first` and `second` members.
  template <typename T1, typename T2>
  struct pair {
    T1 first;  ///< The first element of the pair.
    T2 second; ///< The second element of the pair.

    /// @brief Default constructor.
    constexpr
    pair()
      : first{ }, second{ } { }

    /// @brief Constructor that initializes the pair with given values.
    /// @param a The first value.
    /// @param b The second value.
    constexpr
    pair(const T1& a, const T2& b)
      : first{ a }, second{ b } { }

    /// @brief Constructor that initializes the pair with given values of different types.
    /// @param a The first value of type U1.
    /// @param b The second value of type U2.
    template <typename U1, typename U2>
    constexpr
    pair(const U1& a, const U2& b)
      : first{ a }, second{ b } { }
  
    /// @brief Copy constructor.
    /// @param __x The pair to copy from.
    constexpr
    pair(const pair& __x)
      : first{ __x.first }, second{ __x.second } { }

    /// @brief Move constructor.
    /// @param __x The pair to move from.
    constexpr
    pair(pair&& __x) noexcept
      : first{ std::move(__x.first) }, second{ std::move(__x.second) } { }

    /// @brief Assignment operator.
    /// @param __x The pair to assign from.
    /// @return A reference to this pair.
    constexpr pair&
    operator=(const pair& __x)
    {
      if ( this == &__x ) {
        return *this;
      }
      first  = __x.first;
      second = __x.second;
      return *this;
    }

    /// @brief Move assignment operator.
    /// @param __x The pair to move from.
    /// @return A reference to this pair.
    constexpr pair&
    operator=(pair&& __x) noexcept
    {
      if ( this == &__x ) {
        return *this;
      }
      first  = std::move(__x.first);
      second = std::move(__x.second);
      return *this;
    }

  };

  /// @brief Comparison operator for pairs.
  /// @details Compares two pairs for equality.
  /// @param lhs The first pair.
  /// @param rhs The second pair.
  /// @return True if both pairs are equal, false otherwise.
  template <typename T1, typename T2>
  constexpr bool
  operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
  {
    return (lhs.first == rhs.first && lhs.second == rhs.second);
  }

  /// @brief Inequality operator for pairs.
  /// @details Compares two pairs for inequality.
  /// @param lhs The first pair.
  /// @param rhs The second pair.
  /// @return True if the pairs are not equal, false otherwise.
  template <typename T1, typename T2>
  constexpr bool
  operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
  {
    return !(lhs == rhs);
  }

  /// @brief Less than operator for pairs.
  /// @details Compares two pairs lexicographically.
  /// @param lhs The first pair.
  /// @param rhs The second pair.
  /// @return True if the first pair is less than the second, false otherwise.
  template <typename T1, typename T2>
  constexpr bool
  operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
  {
    if ( lhs.first < rhs.first ) {
      return true;
    } else if ( rhs.first == lhs.first ) {
      return (lhs.second < rhs.second);
    }
    return false;
  }

  /// @brief Greater than operator for pairs.
  /// @details Compares two pairs lexicographically.
  /// @param lhs The first pair.
  /// @param rhs The second pair.
  /// @return True if the first pair is greater than the second, false otherwise.
  template <typename T1, typename T2>
  constexpr bool
  operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
  {
    return (rhs < lhs);
  }
  
  /// @brief Less than or equal to operator for pairs.
  /// @details Compares two pairs lexicographically.
  /// @param lhs The first pair.
  /// @param rhs The second pair.
  /// @return True if the first pair is less than or equal to the second, false otherwise.
  template <typename T1, typename T2>
  constexpr bool
  operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
  {
    return !(rhs < lhs);
  }
  
  /// @brief Greater than or equal to operator for pairs.
  /// @details Compares two pairs lexicographically.
  /// @param lhs The first pair.
  /// @param rhs The second pair.
  /// @return True if the first pair is greater than or equal to the second, false otherwise.
  template <typename T1, typename T2>
  constexpr bool
  operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
  {
    return !(lhs < rhs);
  }

  /// @brief Make a pair.
  /// @details Creates a pair from two values.
  /// @param a The first value.
  /// @param b The second value.
  /// @return A pair containing the two values.
  template <typename T1, typename T2>
  constexpr pair<T1, T2>
  make_pair(const T1& a, const T2& b)
  {
    return pair<T1, T2>(a, b);
  }

} // namespace ft

#endif // __FT_PAIR__