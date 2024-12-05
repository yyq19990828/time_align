// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from stamp_markerarray:msg/StampedMarkerArray.idl
// generated code does not contain a copyright notice

#ifndef STAMP_MARKERARRAY__MSG__DETAIL__STAMPED_MARKER_ARRAY__STRUCT_HPP_
#define STAMP_MARKERARRAY__MSG__DETAIL__STAMPED_MARKER_ARRAY__STRUCT_HPP_

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
// Member 'markers'
#include "visualization_msgs/msg/detail/marker__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__stamp_markerarray__msg__StampedMarkerArray __attribute__((deprecated))
#else
# define DEPRECATED__stamp_markerarray__msg__StampedMarkerArray __declspec(deprecated)
#endif

namespace stamp_markerarray
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct StampedMarkerArray_
{
  using Type = StampedMarkerArray_<ContainerAllocator>;

  explicit StampedMarkerArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit StampedMarkerArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _markers_type =
    std::vector<visualization_msgs::msg::Marker_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<visualization_msgs::msg::Marker_<ContainerAllocator>>>;
  _markers_type markers;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__markers(
    const std::vector<visualization_msgs::msg::Marker_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<visualization_msgs::msg::Marker_<ContainerAllocator>>> & _arg)
  {
    this->markers = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    stamp_markerarray::msg::StampedMarkerArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const stamp_markerarray::msg::StampedMarkerArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<stamp_markerarray::msg::StampedMarkerArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<stamp_markerarray::msg::StampedMarkerArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      stamp_markerarray::msg::StampedMarkerArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<stamp_markerarray::msg::StampedMarkerArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      stamp_markerarray::msg::StampedMarkerArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<stamp_markerarray::msg::StampedMarkerArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<stamp_markerarray::msg::StampedMarkerArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<stamp_markerarray::msg::StampedMarkerArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__stamp_markerarray__msg__StampedMarkerArray
    std::shared_ptr<stamp_markerarray::msg::StampedMarkerArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__stamp_markerarray__msg__StampedMarkerArray
    std::shared_ptr<stamp_markerarray::msg::StampedMarkerArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StampedMarkerArray_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->markers != other.markers) {
      return false;
    }
    return true;
  }
  bool operator!=(const StampedMarkerArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StampedMarkerArray_

// alias to use template instance with default allocator
using StampedMarkerArray =
  stamp_markerarray::msg::StampedMarkerArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace stamp_markerarray

#endif  // STAMP_MARKERARRAY__MSG__DETAIL__STAMPED_MARKER_ARRAY__STRUCT_HPP_
