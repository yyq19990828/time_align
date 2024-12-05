// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from stamp_markerarray:msg/StampedMarkerArray.idl
// generated code does not contain a copyright notice

#ifndef STAMP_MARKERARRAY__MSG__DETAIL__STAMPED_MARKER_ARRAY__TRAITS_HPP_
#define STAMP_MARKERARRAY__MSG__DETAIL__STAMPED_MARKER_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "stamp_markerarray/msg/detail/stamped_marker_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'markers'
#include "visualization_msgs/msg/detail/marker__traits.hpp"

namespace stamp_markerarray
{

namespace msg
{

inline void to_flow_style_yaml(
  const StampedMarkerArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: markers
  {
    if (msg.markers.size() == 0) {
      out << "markers: []";
    } else {
      out << "markers: [";
      size_t pending_items = msg.markers.size();
      for (auto item : msg.markers) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StampedMarkerArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: markers
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.markers.size() == 0) {
      out << "markers: []\n";
    } else {
      out << "markers:\n";
      for (auto item : msg.markers) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StampedMarkerArray & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace stamp_markerarray

namespace rosidl_generator_traits
{

[[deprecated("use stamp_markerarray::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const stamp_markerarray::msg::StampedMarkerArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  stamp_markerarray::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use stamp_markerarray::msg::to_yaml() instead")]]
inline std::string to_yaml(const stamp_markerarray::msg::StampedMarkerArray & msg)
{
  return stamp_markerarray::msg::to_yaml(msg);
}

template<>
inline const char * data_type<stamp_markerarray::msg::StampedMarkerArray>()
{
  return "stamp_markerarray::msg::StampedMarkerArray";
}

template<>
inline const char * name<stamp_markerarray::msg::StampedMarkerArray>()
{
  return "stamp_markerarray/msg/StampedMarkerArray";
}

template<>
struct has_fixed_size<stamp_markerarray::msg::StampedMarkerArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<stamp_markerarray::msg::StampedMarkerArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<stamp_markerarray::msg::StampedMarkerArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // STAMP_MARKERARRAY__MSG__DETAIL__STAMPED_MARKER_ARRAY__TRAITS_HPP_
