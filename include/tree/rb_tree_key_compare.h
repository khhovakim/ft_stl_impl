#ifndef   __FT_RB_TREE_KEY_COMPARE__
# define  __FT_RB_TREE_KEY_COMPARE__

# include <type_traits>  // For std::is_nothrow_default_constructible, std::is_nothrow_move_constructible
# include <utility>      // For std::move

namespace ft {

  /// @brief A key comparison class for red-black trees.
  /// @details This class provides a way to compare keys in a red-black tree.
  /// It is used to maintain the order of elements in the tree.
  /// The class is designed to be default constructible and copyable.
  template<typename KeyCompare>
  struct rb_tree_key_compare
  {
    KeyCompare m_keyCompare; ///< The key comparison function.
    
    /// @brief Default constructor.
    rb_tree_key_compare() noexcept(std::is_nothrow_default_constructible<KeyCompare>::value)
      : m_keyCompare{ } {}
    
    /// @brief Constructor with a key comparison function.
    /// @param __comp The key comparison function to use.
    rb_tree_key_compare(const KeyCompare& __comp)
      : m_keyCompare{ __comp } {}

    /// @brief Copy constructor.
    /// @param __x The instance to copy from.
    rb_tree_key_compare(const rb_tree_key_compare& __x) = default;

    /// @brief Move constructor.
    /// @param __x The instance to move from.
    rb_tree_key_compare(rb_tree_key_compare&& __x) noexcept(std::is_nothrow_move_constructible<KeyCompare>::value)
      : m_keyCompare{ std::move(__x.m_keyCompare) } {}
  };
}

#endif // __FT_RB_TREE_KEY_COMPARE__