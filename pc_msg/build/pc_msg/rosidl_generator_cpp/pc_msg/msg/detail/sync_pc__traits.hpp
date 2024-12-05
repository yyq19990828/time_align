// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pc_msg:msg/SyncPc.idl
// generated code does not contain a copyright notice

#ifndef PC_MSG__MSG__DETAIL__SYNC_PC__TRAITS_HPP_
#define PC_MSG__MSG__DETAIL__SYNC_PC__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pc_msg/msg/detail/sync_pc__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'pointclouds'
#include "sensor_msgs/msg/detail/point_cloud2__traits.hpp"

namespace pc_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const SyncPc & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: pointclouds
  {
    if (msg.pointclouds.size() == 0) {
      out << "pointclouds: []";
    } else {
      out << "pointclouds: [";
      size_t pending_items = msg.pointclouds.size();
      for (auto item : msg.pointclouds) {
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
  const SyncPc & msg,
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

  // member: pointclouds
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.pointclouds.size() == 0) {
      out << "pointclouds: []\n";
    } else {
      out << "pointclouds:\n";
      for (auto item : msg.pointclouds) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SyncPc & msg, bool use_flow_style = false)
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

}  // namespace pc_msg

namespace rosidl_generator_traits
{

[[deprecated("use pc_msg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const pc_msg::msg::SyncPc & msg,
  std::ostream & out, size_t indentation = 0)
{
  pc_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pc_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const pc_msg::msg::SyncPc & msg)
{
  return pc_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pc_msg::msg::SyncPc>()
{
  return "pc_msg::msg::SyncPc";
}

template<>
inline const char * name<pc_msg::msg::SyncPc>()
{
  return "pc_msg/msg/SyncPc";
}

template<>
struct has_fixed_size<pc_msg::msg::SyncPc>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<pc_msg::msg::SyncPc>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<pc_msg::msg::SyncPc>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PC_MSG__MSG__DETAIL__SYNC_PC__TRAITS_HPP_
