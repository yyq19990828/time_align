// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from stamp_markerarray:msg/StampedMarkerArray.idl
// generated code does not contain a copyright notice

#ifndef STAMP_MARKERARRAY__MSG__DETAIL__STAMPED_MARKER_ARRAY__BUILDER_HPP_
#define STAMP_MARKERARRAY__MSG__DETAIL__STAMPED_MARKER_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "stamp_markerarray/msg/detail/stamped_marker_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace stamp_markerarray
{

namespace msg
{

namespace builder
{

class Init_StampedMarkerArray_markers
{
public:
  explicit Init_StampedMarkerArray_markers(::stamp_markerarray::msg::StampedMarkerArray & msg)
  : msg_(msg)
  {}
  ::stamp_markerarray::msg::StampedMarkerArray markers(::stamp_markerarray::msg::StampedMarkerArray::_markers_type arg)
  {
    msg_.markers = std::move(arg);
    return std::move(msg_);
  }

private:
  ::stamp_markerarray::msg::StampedMarkerArray msg_;
};

class Init_StampedMarkerArray_header
{
public:
  Init_StampedMarkerArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StampedMarkerArray_markers header(::stamp_markerarray::msg::StampedMarkerArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_StampedMarkerArray_markers(msg_);
  }

private:
  ::stamp_markerarray::msg::StampedMarkerArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::stamp_markerarray::msg::StampedMarkerArray>()
{
  return stamp_markerarray::msg::builder::Init_StampedMarkerArray_header();
}

}  // namespace stamp_markerarray

#endif  // STAMP_MARKERARRAY__MSG__DETAIL__STAMPED_MARKER_ARRAY__BUILDER_HPP_
