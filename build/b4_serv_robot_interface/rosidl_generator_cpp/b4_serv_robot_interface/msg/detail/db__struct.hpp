// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from b4_serv_robot_interface:msg/DB.idl
// generated code does not contain a copyright notice

#ifndef B4_SERV_ROBOT_INTERFACE__MSG__DETAIL__DB__STRUCT_HPP_
#define B4_SERV_ROBOT_INTERFACE__MSG__DETAIL__DB__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__b4_serv_robot_interface__msg__DB __attribute__((deprecated))
#else
# define DEPRECATED__b4_serv_robot_interface__msg__DB __declspec(deprecated)
#endif

namespace b4_serv_robot_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DB_
{
  using Type = DB_<ContainerAllocator>;

  explicit DB_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit DB_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _order_info_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _order_info_type order_info;

  // setters for named parameter idiom
  Type & set__order_info(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->order_info = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    b4_serv_robot_interface::msg::DB_<ContainerAllocator> *;
  using ConstRawPtr =
    const b4_serv_robot_interface::msg::DB_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<b4_serv_robot_interface::msg::DB_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<b4_serv_robot_interface::msg::DB_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      b4_serv_robot_interface::msg::DB_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<b4_serv_robot_interface::msg::DB_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      b4_serv_robot_interface::msg::DB_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<b4_serv_robot_interface::msg::DB_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<b4_serv_robot_interface::msg::DB_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<b4_serv_robot_interface::msg::DB_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__b4_serv_robot_interface__msg__DB
    std::shared_ptr<b4_serv_robot_interface::msg::DB_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__b4_serv_robot_interface__msg__DB
    std::shared_ptr<b4_serv_robot_interface::msg::DB_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DB_ & other) const
  {
    if (this->order_info != other.order_info) {
      return false;
    }
    return true;
  }
  bool operator!=(const DB_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DB_

// alias to use template instance with default allocator
using DB =
  b4_serv_robot_interface::msg::DB_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace b4_serv_robot_interface

#endif  // B4_SERV_ROBOT_INTERFACE__MSG__DETAIL__DB__STRUCT_HPP_
