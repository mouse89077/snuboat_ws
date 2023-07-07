// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from snuboat_msgs:msg/Obstacles.idl
// generated code does not contain a copyright notice

#ifndef SNUBOAT_MSGS__MSG__DETAIL__OBSTACLES__BUILDER_HPP_
#define SNUBOAT_MSGS__MSG__DETAIL__OBSTACLES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "snuboat_msgs/msg/detail/obstacles__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace snuboat_msgs
{

namespace msg
{

namespace builder
{

class Init_Obstacles_y
{
public:
  explicit Init_Obstacles_y(::snuboat_msgs::msg::Obstacles & msg)
  : msg_(msg)
  {}
  ::snuboat_msgs::msg::Obstacles y(::snuboat_msgs::msg::Obstacles::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::snuboat_msgs::msg::Obstacles msg_;
};

class Init_Obstacles_x
{
public:
  explicit Init_Obstacles_x(::snuboat_msgs::msg::Obstacles & msg)
  : msg_(msg)
  {}
  Init_Obstacles_y x(::snuboat_msgs::msg::Obstacles::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Obstacles_y(msg_);
  }

private:
  ::snuboat_msgs::msg::Obstacles msg_;
};

class Init_Obstacles_phi
{
public:
  explicit Init_Obstacles_phi(::snuboat_msgs::msg::Obstacles & msg)
  : msg_(msg)
  {}
  Init_Obstacles_x phi(::snuboat_msgs::msg::Obstacles::_phi_type arg)
  {
    msg_.phi = std::move(arg);
    return Init_Obstacles_x(msg_);
  }

private:
  ::snuboat_msgs::msg::Obstacles msg_;
};

class Init_Obstacles_r
{
public:
  explicit Init_Obstacles_r(::snuboat_msgs::msg::Obstacles & msg)
  : msg_(msg)
  {}
  Init_Obstacles_phi r(::snuboat_msgs::msg::Obstacles::_r_type arg)
  {
    msg_.r = std::move(arg);
    return Init_Obstacles_phi(msg_);
  }

private:
  ::snuboat_msgs::msg::Obstacles msg_;
};

class Init_Obstacles_label
{
public:
  Init_Obstacles_label()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Obstacles_r label(::snuboat_msgs::msg::Obstacles::_label_type arg)
  {
    msg_.label = std::move(arg);
    return Init_Obstacles_r(msg_);
  }

private:
  ::snuboat_msgs::msg::Obstacles msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::snuboat_msgs::msg::Obstacles>()
{
  return snuboat_msgs::msg::builder::Init_Obstacles_label();
}

}  // namespace snuboat_msgs

#endif  // SNUBOAT_MSGS__MSG__DETAIL__OBSTACLES__BUILDER_HPP_
