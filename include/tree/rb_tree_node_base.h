#ifndef   __FT_RB_TREE_NODE_BASE__
# define  __FT_RB_TREE_NODE_BASE__

namespace ft {

  /// @brief Enum class representing the color of a red-black tree node.
  /// @details This enum class defines two possible colors for nodes in a red-black tree:
  /// - `red`: Represents a red node in the tree.
  /// - `black`: Represents a black node in the tree.
  ///
  /// Usage:
  /// - Use `rb_tree_color::red` to indicate a red node.
  /// - Use `rb_tree_color::black` to indicate a black node.
  ///
  /// Example:
  /// ```cpp
  /// rb_tree_color color = rb_tree_color::red;
  /// ```
  ///
  /// This enum class is used to maintain the properties of red-black trees,
  /// where nodes are colored either red or black to ensure balanced tree structure.
  /// The color of a node is crucial for the algorithms that maintain the balance of the tree during insertions and deletions.
  ///

  enum class rb_tree_color {
    red   = false, ///< Represents a red node in the tree.
    black = true   ///< Represents a black node in the tree.
  };

  /// @brief Base class for red-black tree nodes.
  /// @details This class provides the basic structure for nodes in a red-black tree,
  /// including pointers to parent, left, and right children, as well as the color of the node.
  /// It also includes static methods to find the minimum and maximum nodes in a subtree.
  /// @note The color of the node is represented as an enum class for better type safety.
  ///
  /// Usage:
  /// - Create a derived class that includes a value field.
  /// - Use the static methods to find minimum and maximum nodes in a subtree.
  /// - The color of the node can be set to either red or black.
  ///
  /// Example:
  /// ```cpp
  /// class MyNode : public ft::rb_tree_node_base {
  ///     int value; // Additional value field
  /// };
  /// ```
  ///
  /// This class is designed to be used as a base class for red-black tree nodes,
  /// providing essential functionality for tree operations such as insertion, deletion, and traversal.
  ///
  /// The static methods `minimum` and `maximum` can be used to retrieve the leftmost and rightmost nodes
  /// in a subtree, respectively, which are crucial for maintaining the properties of the red-black tree.
  ///
  /// The `color` member variable indicates whether the node is red or black, which is essential for
  /// maintaining the balance of the tree during insertions and deletions.
  ///
  /// The `parent`, `left`, and `right` pointers allow for easy navigation through the tree structure,
  /// enabling efficient search, insertion, and deletion operations.
  ///
  /// This class is part of the `ft` namespace, which is a custom implementation of the C++ Standard Library.
  /// It is designed to be used in conjunction with other components of the `ft` library, such as iterators and algorithms.
  ///

  struct rb_tree_node_base {
    using base_ptr       =       rb_tree_node_base*; ///< Pointer to base node type.
    using const_base_ptr = const rb_tree_node_base*; ///< Const pointer to base node type.
    
    rb_tree_color m_color ; ///< Color of the node (red or black).
    base_ptr      m_parent; ///< Pointer to the parent node.
    base_ptr      m_left  ; ///< Pointer to the left child node.
    base_ptr      m_right ; ///< Pointer to the right child node.

    /// @brief Get the minimum node in the subtree rooted at x.
    /// @param x Pointer to the node from which to start searching for the minimum.
    /// @return Pointer to the leftmost node in the subtree, which is the minimum.
    /// @details
    /// This function traverses the left children of the given node until it finds
    /// the leftmost node, which is the minimum in the subtree.
    static base_ptr
    minimum(base_ptr __x) noexcept
    {
      if ( __x == nullptr ) return nullptr; // Handle null case

      while ( __x->m_left != nullptr ) __x = __x->m_left;
      return __x;
    }

    /// @brief Get the maximum node in the subtree rooted at x.
    /// @param x Pointer to the node from which to start searching for the maximum.
    /// @return Pointer to the rightmost node in the subtree, which is the maximum.
    /// @details
    /// This function traverses the right children of the given node until it finds
    /// the rightmost node, which is the maximum in the subtree.
    static base_ptr
    maximum(base_ptr __x) noexcept
    {
      if ( __x == nullptr ) return nullptr; // Handle null case

      while ( __x->m_right != nullptr ) __x = __x->m_right;
      return __x;
    }

    /// @brief Get the minimum node in the subtree rooted at x (const version).
    /// @param x Const pointer to the node from which to start searching for the minimum.
    /// @return Const pointer to the leftmost node in the subtree, which is the minimum.
    static const_base_ptr
    minimum(const_base_ptr __x) noexcept
    {
      if ( __x == nullptr ) return nullptr; // Handle null case

      while ( __x->m_left != nullptr ) __x = __x->m_left;
      return __x;
    }

    /// @brief Get the maximum node in the subtree rooted at x (const version).
    /// @param x Const pointer to the node from which to start searching for the maximum.
    /// @return Const pointer to the rightmost node in the subtree, which is the maximum.
    static const_base_ptr
    maximum(const_base_ptr __x) noexcept
    {
      if ( __x == nullptr ) return nullptr; // Handle null case

      while ( __x->m_right != nullptr ) __x = __x->m_right;
      return __x;
    }
  };
}

#endif // _FT_RB_TREE_NODE_BASE__