#ifndef   __FT_RB_TREE_HEADER__
# define  __FT_RB_TREE_HEADER__

# include <cstddef> // For std::size_t

# include "rb_tree_node_base.h" // For rb_tree_node_base, rb_tree_color

namespace ft {

  /// @brief A header for red-black trees.
  /// @details This class provides a header for red-black trees, which includes
  /// the root node and keeps track of the number of nodes in the tree.
  struct rb_tree_header
  {
    rb_tree_node_base m_header;    ///< The root node of the red-black tree.
    std::size_t       m_nodeCount; ///< The number of nodes in the tree.

    /// @brief Default constructor.
    /// @details Initializes the header with a red color and resets the tree.
    rb_tree_header() noexcept
      : m_header{ },
        m_nodeCount{ 0 }
    {
      m_header.m_color = rb_tree_color::red; // Set the header color to red
      __reset();
    }

    /// @brief Move constructor.
    /// @details Moves the data from another rb_tree_header instance.
    rb_tree_header(rb_tree_header&& __x) noexcept
    {
      if ( __x.m_header.m_parent != nullptr ) {
        __move_data(__x);
      } else {
        m_header.m_color = rb_tree_color::red; // Set the header color to red
        __reset();
      }
    }

    /// @brief Move data from another rb_tree_header instance.
    /// @param __from The rb_tree_header instance from which to move data.
    void
    __move_data(rb_tree_header& __from) noexcept
    {
      m_header.m_color  = __from.m_header.m_color ;
      m_header.m_parent = __from.m_header.m_parent;
      m_header.m_left   = __from.m_header.m_left  ;
      m_header.m_right  = __from.m_header.m_right ;

      m_header.m_parent->m_parent = &m_header; // Update parent pointer
      m_nodeCount = __from.m_nodeCount;

      __from.__reset(); // Reset the source header
    }

    /// @brief Reset the tree header.
    /// @details Resets the header to its initial state, with no nodes.
    void
    __reset() noexcept
    {
      m_header.m_parent = nullptr;   // No parent node
      m_header.m_left   = &m_header; // Leftmost node points to itself
      m_header.m_right  = &m_header; // Rightmost node points to itself
      m_nodeCount       = 0;         // No nodes in the tree
    }
  };

} // namespace ft

#endif // __FT_RB_TREE_HEADER__