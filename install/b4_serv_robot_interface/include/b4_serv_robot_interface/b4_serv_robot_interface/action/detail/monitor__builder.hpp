// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from b4_serv_robot_interface:action/Monitor.idl
// generated code does not contain a copyright notice

#ifndef B4_SERV_ROBOT_INTERFACE__ACTION__DETAIL__MONITOR__BUILDER_HPP_
#define B4_SERV_ROBOT_INTERFACE__ACTION__DETAIL__MONITOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "b4_serv_robot_interface/action/detail/monitor__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace b4_serv_robot_interface
{

namespace action
{

namespace builder
{

class Init_Monitor_Goal_goal
{
public:
  Init_Monitor_Goal_goal()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::b4_serv_robot_interface::action::Monitor_Goal goal(::b4_serv_robot_interface::action::Monitor_Goal::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::b4_serv_robot_interface::action::Monitor_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::b4_serv_robot_interface::action::Monitor_Goal>()
{
  return b4_serv_robot_interface::action::builder::Init_Monitor_Goal_goal();
}

}  // namespace b4_serv_robot_interface


namespace b4_serv_robot_interface
{

namespace action
{

namespace builder
{

class Init_Monitor_Result_status
{
public:
  Init_Monitor_Result_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::b4_serv_robot_interface::action::Monitor_Result status(::b4_serv_robot_interface::action::Monitor_Result::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::b4_serv_robot_interface::action::Monitor_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::b4_serv_robot_interface::action::Monitor_Result>()
{
  return b4_serv_robot_interface::action::builder::Init_Monitor_Result_status();
}

}  // namespace b4_serv_robot_interface


namespace b4_serv_robot_interface
{

namespace action
{

namespace builder
{

class Init_Monitor_Feedback_pos
{
public:
  Init_Monitor_Feedback_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::b4_serv_robot_interface::action::Monitor_Feedback pos(::b4_serv_robot_interface::action::Monitor_Feedback::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::b4_serv_robot_interface::action::Monitor_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::b4_serv_robot_interface::action::Monitor_Feedback>()
{
  return b4_serv_robot_interface::action::builder::Init_Monitor_Feedback_pos();
}

}  // namespace b4_serv_robot_interface


namespace b4_serv_robot_interface
{

namespace action
{

namespace builder
{

class Init_Monitor_SendGoal_Request_goal
{
public:
  explicit Init_Monitor_SendGoal_Request_goal(::b4_serv_robot_interface::action::Monitor_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::b4_serv_robot_interface::action::Monitor_SendGoal_Request goal(::b4_serv_robot_interface::action::Monitor_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::b4_serv_robot_interface::action::Monitor_SendGoal_Request msg_;
};

class Init_Monitor_SendGoal_Request_goal_id
{
public:
  Init_Monitor_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Monitor_SendGoal_Request_goal goal_id(::b4_serv_robot_interface::action::Monitor_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Monitor_SendGoal_Request_goal(msg_);
  }

private:
  ::b4_serv_robot_interface::action::Monitor_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::b4_serv_robot_interface::action::Monitor_SendGoal_Request>()
{
  return b4_serv_robot_interface::action::builder::Init_Monitor_SendGoal_Request_goal_id();
}

}  // namespace b4_serv_robot_interface


namespace b4_serv_robot_interface
{

namespace action
{

namespace builder
{

class Init_Monitor_SendGoal_Response_stamp
{
public:
  explicit Init_Monitor_SendGoal_Response_stamp(::b4_serv_robot_interface::action::Monitor_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::b4_serv_robot_interface::action::Monitor_SendGoal_Response stamp(::b4_serv_robot_interface::action::Monitor_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::b4_serv_robot_interface::action::Monitor_SendGoal_Response msg_;
};

class Init_Monitor_SendGoal_Response_accepted
{
public:
  Init_Monitor_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Monitor_SendGoal_Response_stamp accepted(::b4_serv_robot_interface::action::Monitor_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Monitor_SendGoal_Response_stamp(msg_);
  }

private:
  ::b4_serv_robot_interface::action::Monitor_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::b4_serv_robot_interface::action::Monitor_SendGoal_Response>()
{
  return b4_serv_robot_interface::action::builder::Init_Monitor_SendGoal_Response_accepted();
}

}  // namespace b4_serv_robot_interface


namespace b4_serv_robot_interface
{

namespace action
{

namespace builder
{

class Init_Monitor_GetResult_Request_goal_id
{
public:
  Init_Monitor_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::b4_serv_robot_interface::action::Monitor_GetResult_Request goal_id(::b4_serv_robot_interface::action::Monitor_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::b4_serv_robot_interface::action::Monitor_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::b4_serv_robot_interface::action::Monitor_GetResult_Request>()
{
  return b4_serv_robot_interface::action::builder::Init_Monitor_GetResult_Request_goal_id();
}

}  // namespace b4_serv_robot_interface


namespace b4_serv_robot_interface
{

namespace action
{

namespace builder
{

class Init_Monitor_GetResult_Response_result
{
public:
  explicit Init_Monitor_GetResult_Response_result(::b4_serv_robot_interface::action::Monitor_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::b4_serv_robot_interface::action::Monitor_GetResult_Response result(::b4_serv_robot_interface::action::Monitor_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::b4_serv_robot_interface::action::Monitor_GetResult_Response msg_;
};

class Init_Monitor_GetResult_Response_status
{
public:
  Init_Monitor_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Monitor_GetResult_Response_result status(::b4_serv_robot_interface::action::Monitor_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Monitor_GetResult_Response_result(msg_);
  }

private:
  ::b4_serv_robot_interface::action::Monitor_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::b4_serv_robot_interface::action::Monitor_GetResult_Response>()
{
  return b4_serv_robot_interface::action::builder::Init_Monitor_GetResult_Response_status();
}

}  // namespace b4_serv_robot_interface


namespace b4_serv_robot_interface
{

namespace action
{

namespace builder
{

class Init_Monitor_FeedbackMessage_feedback
{
public:
  explicit Init_Monitor_FeedbackMessage_feedback(::b4_serv_robot_interface::action::Monitor_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::b4_serv_robot_interface::action::Monitor_FeedbackMessage feedback(::b4_serv_robot_interface::action::Monitor_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::b4_serv_robot_interface::action::Monitor_FeedbackMessage msg_;
};

class Init_Monitor_FeedbackMessage_goal_id
{
public:
  Init_Monitor_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Monitor_FeedbackMessage_feedback goal_id(::b4_serv_robot_interface::action::Monitor_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Monitor_FeedbackMessage_feedback(msg_);
  }

private:
  ::b4_serv_robot_interface::action::Monitor_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::b4_serv_robot_interface::action::Monitor_FeedbackMessage>()
{
  return b4_serv_robot_interface::action::builder::Init_Monitor_FeedbackMessage_goal_id();
}

}  // namespace b4_serv_robot_interface

#endif  // B4_SERV_ROBOT_INTERFACE__ACTION__DETAIL__MONITOR__BUILDER_HPP_
