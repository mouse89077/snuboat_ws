// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from snuboat_msgs:msg/Obstacles.idl
// generated code does not contain a copyright notice

#ifndef SNUBOAT_MSGS__MSG__DETAIL__OBSTACLES__TRAITS_HPP_
#define SNUBOAT_MSGS__MSG__DETAIL__OBSTACLES__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "snuboat_msgs/msg/detail/obstacles__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace snuboat_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Obstacles & msg,
  std::ostream & out)
{
  out << "{";
  // member: label
  {
    if (msg.label.size() == 0) {
      out << "label: []";
    } else {
      out << "label: [";
      size_t pending_items = msg.label.size();
      for (auto item : msg.label) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: r
  {
    if (msg.r.size() == 0) {
      out << "r: []";
    } else {
      out << "r: [";
      size_t pending_items = msg.r.size();
      for (auto item : msg.r) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: phi
  {
    if (msg.phi.size() == 0) {
      out << "phi: []";
    } else {
      out << "phi: [";
      size_t pending_items = msg.phi.size();
      for (auto item : msg.phi) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: x
  {
    if (msg.x.size() == 0) {
      out << "x: []";
    } else {
      out << "x: [";
      size_t pending_items = msg.x.size();
      for (auto item : msg.x) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: y
  {
    if (msg.y.size() == 0) {
      out << "y: []";
    } else {
      out << "y: [";
      size_t pending_items = msg.y.size();
      for (auto item : msg.y) {
        rosidl_generator_traits::value_to_yaml(item, out);
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
  const Obstacles & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: label
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.label.size() == 0) {
      out << "label: []\n";
    } else {
      out << "label:\n";
      for (auto item : msg.label) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.r.size() == 0) {
      out << "r: []\n";
    } else {
      out << "r:\n";
      for (auto item : msg.r) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: phi
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.phi.size() == 0) {
      out << "phi: []\n";
    } else {
      out << "phi:\n";
      for (auto item : msg.phi) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.x.size() == 0) {
      out << "x: []\n";
    } else {
      out << "x:\n";
      for (auto item : msg.x) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.y.size() == 0) {
      out << "y: []\n";
    } else {
      out << "y:\n";
      for (auto item : msg.y) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Obstacles & msg, bool use_flow_style = false)
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

}  // namespace snuboat_msgs

namespace rosidl_generator_traits
{

[[deprecated("use snuboat_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const snuboat_msgs::msg::Obstacles & msg,
  std::ostream & out, size_t indentation = 0)
{
  snuboat_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use snuboat_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const snuboat_msgs::msg::Obstacles & msg)
{
  return snuboat_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<snuboat_msgs::msg::Obstacles>()
{
  return "snuboat_msgs::msg::Obstacles";
}

template<>
inline const char * name<snuboat_msgs::msg::Obstacles>()
{
  return "snuboat_msgs/msg/Obstacles";
}

template<>
struct has_fixed_size<snuboat_msgs::msg::Obstacles>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<snuboat_msgs::msg::Obstacles>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<snuboat_msgs::msg::Obstacles>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SNUBOAT_MSGS__MSG__DETAIL__OBSTACLES__TRAITS_HPP_
