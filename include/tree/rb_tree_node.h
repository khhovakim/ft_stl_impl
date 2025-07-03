#ifndef   __FT_RB_TREE_NODE__
# define  __FT_RB_TREE_NODE__

# include <memory> // For std::addressof

# include "rb_tree_node_base.h" // For rb_tree_node_base, rb_tree_color

namespace ft {

  /// @brief class representing a node in a red-black tree.
  /// @details This class inherits from `rb_tree_node_base` and adds a value field.
  /// It provides methods to access the value and manage the node's memory.
  /// The class is designed to be used as a base class for red-black tree nodes,
  /// allowing for efficient insertion, deletion, and traversal operations.
  template<typename ValueType>
  struct rb_tree_node : public rb_tree_node_base
  {
    using link_type = rb_tree_node<ValueType>*; ///< Pointer type for the node.

    ValueType m_valueField; ///< The value stored in the node.

    /// @brief Default constructor.
    /// @details Initializes the node with default values.
    rb_tree_node() noexcept
      : rb_tree_node_base{ }, m_valueField{ } {}
    
    /// @brief Constructor with a value.
    /// @param value The value to initialize the node with.
    rb_tree_node(const ValueType& value) noexcept
      : rb_tree_node_base{ }, m_valueField{ value } {}
    
    /// @brief Pointer to the value field.
    /// @return A pointer to the value stored in the node.
    ValueType*
    __valptr() noexcept { return std::addressof(m_valueField); }

    /// @brief Const pointer to the value field.
    /// @return A const pointer to the value stored in the node.
    const ValueType*
    __valptr() const noexcept { return std::addressof(m_valueField); }

    /// @brief Get the value stored in the node.
    /// @return A reference to the value stored in the node.
    ValueType&
    __value() noexcept { return m_valueField; }

    /// @brief Get the const value stored in the node.
    /// @return A const reference to the value stored in the node.
    const ValueType&
    __value() const noexcept { return m_valueField; }
  };

} // namespace ft

#endif // __FT_RB_TREE_NODE__