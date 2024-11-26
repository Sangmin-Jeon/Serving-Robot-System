// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from b4_serv_robot_interface:srv/Order.idl
// generated code does not contain a copyright notice

#ifndef B4_SERV_ROBOT_INTERFACE__SRV__DETAIL__ORDER__STRUCT_HPP_
#define B4_SERV_ROBOT_INTERFACE__SRV__DETAIL__ORDER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__b4_serv_robot_interface__srv__Order_Request __attribute__((deprecated))
#else
# define DEPRECATED__b4_serv_robot_interface__srv__Order_Request __declspec(deprecated)
#endif

namespace b4_serv_robot_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Order_Request_
{
  using Type = Order_Request_<ContainerAllocator>;

  explicit Order_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->table_num = "";
    }
  }

  explicit Order_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : table_num(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->table_num = "";
    }
  }

  // field types and members
  using _table_num_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _table_num_type table_num;
  using _order_info_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _order_info_type order_info;

  // setters for named parameter idiom
  Type & set__table_num(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->table_num = _arg;
    return *this;
  }
  Type & set__order_info(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->order_info = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    b4_serv_robot_interface::srv::Order_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const b4_serv_robot_interface::srv::Order_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<b4_serv_robot_interface::srv::Order_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<b4_serv_robot_interface::srv::Order_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      b4_serv_robot_interface::srv::Order_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<b4_serv_robot_interface::srv::Order_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      b4_serv_robot_interface::srv::Order_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<b4_serv_robot_interface::srv::Order_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<b4_serv_robot_interface::srv::Order_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<b4_serv_robot_interface::srv::Order_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__b4_serv_robot_interface__srv__Order_Request
    std::shared_ptr<b4_serv_robot_interface::srv::Order_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__b4_serv_robot_interface__srv__Order_Request
    std::shared_ptr<b4_serv_robot_interface::srv::Order_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Order_Request_ & other) const
  {
    if (this->table_num != other.table_num) {
      return false;
    }
    if (this->order_info != other.order_info) {
      return false;
    }
    return true;
  }
  bool operator!=(const Order_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Order_Request_

// alias to use template instance with default allocator
using Order_Request =
  b4_serv_robot_interface::srv::Order_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace b4_serv_robot_interface


#ifndef _WIN32
# define DEPRECATED__b4_serv_robot_interface__srv__Order_Response __attribute__((deprecated))
#else
# define DEPRECATED__b4_serv_robot_interface__srv__Order_Response __declspec(deprecated)
#endif

namespace b4_serv_robot_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Order_Response_
{
  using Type = Order_Response_<ContainerAllocator>;

  explicit Order_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_order = false;
    }
  }

  explicit Order_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_order = false;
    }
  }

  // field types and members
  using _is_order_type =
    bool;
  _is_order_type is_order;

  // setters for named parameter idiom
  Type & set__is_order(
    const bool & _arg)
  {
    this->is_order = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    b4_serv_robot_interface::srv::Order_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const b4_serv_robot_interface::srv::Order_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<b4_serv_robot_interface::srv::Order_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<b4_serv_robot_interface::srv::Order_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      b4_serv_robot_interface::srv::Order_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<b4_serv_robot_interface::srv::Order_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      b4_serv_robot_interface::srv::Order_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<b4_serv_robot_interface::srv::Order_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<b4_serv_robot_interface::srv::Order_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<b4_serv_robot_interface::srv::Order_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__b4_serv_robot_interface__srv__Order_Response
    std::shared_ptr<b4_serv_robot_interface::srv::Order_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__b4_serv_robot_interface__srv__Order_Response
    std::shared_ptr<b4_serv_robot_interface::srv::Order_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Order_Response_ & other) const
  {
    if (this->is_order != other.is_order) {
      return false;
    }
    return true;
  }
  bool operator!=(const Order_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Order_Response_

// alias to use template instance with default allocator
using Order_Response =
  b4_serv_robot_interface::srv::Order_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace b4_serv_robot_interface

namespace b4_serv_robot_interface
{

namespace srv
{

struct Order
{
  using Request = b4_serv_robot_interface::srv::Order_Request;
  using Response = b4_serv_robot_interface::srv::Order_Response;
};

}  // namespace srv

}  // namespace b4_serv_robot_interface

#endif  // B4_SERV_ROBOT_INTERFACE__SRV__DETAIL__ORDER__STRUCT_HPP_
