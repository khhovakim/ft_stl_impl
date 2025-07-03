#ifndef   __FT_ITERATOR_BASE_TYPES__
# define  __FT_ITERATOR_BASE_TYPES__

# include <cstddef> // For std::ptrdiff_t

namespace ft {

  /// @brief iterator_tags are empty types used to distinguish different iterators.
  /// @details Different underlying algorithms can then be used based on the different operations supported by different iterator types.
  struct input_iterator_tag { };
  struct output_iterator_tag { };
  struct forward_iterator_tag : public input_iterator_tag { };
  struct bidirectional_iterator_tag : public forward_iterator_tag { };
  struct random_access_iterator_tag : public bidirectional_iterator_tag { };

  /// @brief iterator class template.
  /// @details This class template provides a common interface for iterators.
  /// It defines the types and operations that all iterators should support.
  template <
    typename _Category,
    typename _Tp,
    typename _Distance = std::ptrdiff_t,
    typename _Pointer = _Tp*,
    typename _Reference = _Tp&
  > struct iterator
  {
    using iterator_category = _Category;  ///< The category of the iterator.
    using value_type        = _Tp;        ///< The type of the value pointed to by the iterator.
    using difference_type   = _Distance;  ///< The type used for representing the difference between two iterators.
    using pointer           = _Pointer;   ///< Pointer type to the value.
    using reference         = _Reference; ///< Reference type to the value.
  };

  /// @brief iterator_traits is a class template that provides type information about iterators.
  /// @details It defines the types that are used to represent the category, value type, difference type, pointer type, and reference type of an iterator.
  template <typename _Iter>
  struct iterator_traits
  {
    using iterator_category = typename _Iter::iterator_category; ///< The category of the iterator.
    using value_type        = typename _Iter::value_type;        ///< The type of the value pointed to by the iterator.
    using difference_type   = typename _Iter::difference_type;   ///< The type used for representing the difference between two iterators.
    using pointer           = typename _Iter::pointer;           ///< Pointer type to the value.
    using reference         = typename _Iter::reference;         ///< Reference type to the value.
  };

  /// @brief Specialization of iterator_traits for pointer types.
  /// @details This specialization provides type information for pointer types, which are treated as random access iterators.
  template <typename _Tp>
  struct iterator_traits<_Tp*>
  {
    using iterator_category = random_access_iterator_tag; ///< The category of the iterator.
    using value_type        = _Tp;                        ///< The type of the value pointed to by the iterator.
    using difference_type   = std::ptrdiff_t;             ///< The type used for representing the difference between two iterators.
    using pointer           = _Tp*;                       ///< Pointer type to the value.
    using reference         = _Tp&;                       ///< Reference type to the value.
  };
  
  /// @brief Specialization of iterator_traits for const pointer types.
  /// @details This specialization provides type information for const pointer types, which are treated as random access iterators.
  template <typename _Tp>
  struct iterator_traits<const _Tp*>
  {
    using iterator_category = random_access_iterator_tag; ///< The category of the iterator.
    using value_type        = _Tp;                        ///< The type of the value pointed to by the iterator.
    using difference_type   = std::ptrdiff_t;             ///< The type used for representing the difference between two iterators.
    using pointer           = const _Tp*;                 ///< Pointer type to the value.
    using reference         = const _Tp&;                 ///< Reference type to the value.
  };

  /// @brief A function to get the iterator category of an iterator.
  /// @details This function returns the iterator category of the given iterator.
  template <typename _Iter>
  inline constexpr typename iterator_traits<_Iter>::iterator_category
  __iterator_category(const _Iter&)
  {
    return typename iterator_traits<_Iter>::iterator_category();
  }
  
  /// @brief A type alias for the iterator category of an iterator.
  /// @details This type alias is used to simplify the syntax for getting the iterator category.
  template <typename _Iter>
  using __iterator_category_t = typename iterator_traits<_Iter>::iterator_category;

}

#endif // __FT_ITERATOR_BASE_TYPES__