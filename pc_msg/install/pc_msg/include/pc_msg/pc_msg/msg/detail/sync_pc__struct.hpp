// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pc_msg:msg/SyncPc.idl
// generated code does not contain a copyright notice

#ifndef PC_MSG__MSG__DETAIL__SYNC_PC__STRUCT_HPP_
#define PC_MSG__MSG__DETAIL__SYNC_PC__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'pointclouds'
#include "sensor_msgs/msg/detail/point_cloud2__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pc_msg__msg__SyncPc __attribute__((deprecated))
#else
# define DEPRECATED__pc_msg__msg__SyncPc __declspec(deprecated)
#endif

namespace pc_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SyncPc_
{
  using Type = SyncPc_<ContainerAllocator>;

  explicit SyncPc_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit SyncPc_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _pointclouds_type =
    std::vector<sensor_msgs::msg::PointCloud2_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sensor_msgs::msg::PointCloud2_<ContainerAllocator>>>;
  _pointclouds_type pointclouds;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__pointclouds(
    const std::vector<sensor_msgs::msg::PointCloud2_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sensor_msgs::msg::PointCloud2_<ContainerAllocator>>> & _arg)
  {
    this->pointclouds = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pc_msg::msg::SyncPc_<ContainerAllocator> *;
  using ConstRawPtr =
    const pc_msg::msg::SyncPc_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pc_msg::msg::SyncPc_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pc_msg::msg::SyncPc_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pc_msg::msg::SyncPc_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pc_msg::msg::SyncPc_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pc_msg::msg::SyncPc_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pc_msg::msg::SyncPc_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pc_msg::msg::SyncPc_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pc_msg::msg::SyncPc_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pc_msg__msg__SyncPc
    std::shared_ptr<pc_msg::msg::SyncPc_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pc_msg__msg__SyncPc
    std::shared_ptr<pc_msg::msg::SyncPc_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SyncPc_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->pointclouds != other.pointclouds) {
      return false;
    }
    return true;
  }
  bool operator!=(const SyncPc_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SyncPc_

// alias to use template instance with default allocator
using SyncPc =
  pc_msg::msg::SyncPc_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pc_msg

#endif  // PC_MSG__MSG__DETAIL__SYNC_PC__STRUCT_HPP_
