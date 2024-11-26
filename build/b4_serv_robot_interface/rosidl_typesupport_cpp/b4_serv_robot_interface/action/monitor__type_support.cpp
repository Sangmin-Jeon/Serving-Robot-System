// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from b4_serv_robot_interface:action/Monitor.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "b4_serv_robot_interface/action/detail/monitor__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace b4_serv_robot_interface
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Monitor_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Monitor_Goal_type_support_ids_t;

static const _Monitor_Goal_type_support_ids_t _Monitor_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Monitor_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Monitor_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Monitor_Goal_type_support_symbol_names_t _Monitor_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, b4_serv_robot_interface, action, Monitor_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, b4_serv_robot_interface, action, Monitor_Goal)),
  }
};

typedef struct _Monitor_Goal_type_support_data_t
{
  void * data[2];
} _Monitor_Goal_type_support_data_t;

static _Monitor_Goal_type_support_data_t _Monitor_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Monitor_Goal_message_typesupport_map = {
  2,
  "b4_serv_robot_interface",
  &_Monitor_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_Monitor_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_Monitor_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Monitor_Goal_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Monitor_Goal_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace b4_serv_robot_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<b4_serv_robot_interface::action::Monitor_Goal>()
{
  return &::b4_serv_robot_interface::action::rosidl_typesupport_cpp::Monitor_Goal_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, b4_serv_robot_interface, action, Monitor_Goal)() {
  return get_message_type_support_handle<b4_serv_robot_interface::action::Monitor_Goal>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "b4_serv_robot_interface/action/detail/monitor__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace b4_serv_robot_interface
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Monitor_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Monitor_Result_type_support_ids_t;

static const _Monitor_Result_type_support_ids_t _Monitor_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Monitor_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Monitor_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Monitor_Result_type_support_symbol_names_t _Monitor_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, b4_serv_robot_interface, action, Monitor_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, b4_serv_robot_interface, action, Monitor_Result)),
  }
};

typedef struct _Monitor_Result_type_support_data_t
{
  void * data[2];
} _Monitor_Result_type_support_data_t;

static _Monitor_Result_type_support_data_t _Monitor_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Monitor_Result_message_typesupport_map = {
  2,
  "b4_serv_robot_interface",
  &_Monitor_Result_message_typesupport_ids.typesupport_identifier[0],
  &_Monitor_Result_message_typesupport_symbol_names.symbol_name[0],
  &_Monitor_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Monitor_Result_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Monitor_Result_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace b4_serv_robot_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<b4_serv_robot_interface::action::Monitor_Result>()
{
  return &::b4_serv_robot_interface::action::rosidl_typesupport_cpp::Monitor_Result_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, b4_serv_robot_interface, action, Monitor_Result)() {
  return get_message_type_support_handle<b4_serv_robot_interface::action::Monitor_Result>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "b4_serv_robot_interface/action/detail/monitor__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace b4_serv_robot_interface
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Monitor_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Monitor_Feedback_type_support_ids_t;

static const _Monitor_Feedback_type_support_ids_t _Monitor_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Monitor_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Monitor_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Monitor_Feedback_type_support_symbol_names_t _Monitor_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, b4_serv_robot_interface, action, Monitor_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, b4_serv_robot_interface, action, Monitor_Feedback)),
  }
};

typedef struct _Monitor_Feedback_type_support_data_t
{
  void * data[2];
} _Monitor_Feedback_type_support_data_t;

static _Monitor_Feedback_type_support_data_t _Monitor_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Monitor_Feedback_message_typesupport_map = {
  2,
  "b4_serv_robot_interface",
  &_Monitor_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_Monitor_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_Monitor_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Monitor_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Monitor_Feedback_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace b4_serv_robot_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<b4_serv_robot_interface::action::Monitor_Feedback>()
{
  return &::b4_serv_robot_interface::action::rosidl_typesupport_cpp::Monitor_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, b4_serv_robot_interface, action, Monitor_Feedback)() {
  return get_message_type_support_handle<b4_serv_robot_interface::action::Monitor_Feedback>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "b4_serv_robot_interface/action/detail/monitor__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace b4_serv_robot_interface
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Monitor_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Monitor_SendGoal_Request_type_support_ids_t;

static const _Monitor_SendGoal_Request_type_support_ids_t _Monitor_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Monitor_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Monitor_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Monitor_SendGoal_Request_type_support_symbol_names_t _Monitor_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, b4_serv_robot_interface, action, Monitor_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, b4_serv_robot_interface, action, Monitor_SendGoal_Request)),
  }
};

typedef struct _Monitor_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _Monitor_SendGoal_Request_type_support_data_t;

static _Monitor_SendGoal_Request_type_support_data_t _Monitor_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Monitor_SendGoal_Request_message_typesupport_map = {
  2,
  "b4_serv_robot_interface",
  &_Monitor_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Monitor_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Monitor_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Monitor_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Monitor_SendGoal_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace b4_serv_robot_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<b4_serv_robot_interface::action::Monitor_SendGoal_Request>()
{
  return &::b4_serv_robot_interface::action::rosidl_typesupport_cpp::Monitor_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, b4_serv_robot_interface, action, Monitor_SendGoal_Request)() {
  return get_message_type_support_handle<b4_serv_robot_interface::action::Monitor_SendGoal_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "b4_serv_robot_interface/action/detail/monitor__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace b4_serv_robot_interface
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Monitor_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Monitor_SendGoal_Response_type_support_ids_t;

static const _Monitor_SendGoal_Response_type_support_ids_t _Monitor_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Monitor_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Monitor_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Monitor_SendGoal_Response_type_support_symbol_names_t _Monitor_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, b4_serv_robot_interface, action, Monitor_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, b4_serv_robot_interface, action, Monitor_SendGoal_Response)),
  }
};

typedef struct _Monitor_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _Monitor_SendGoal_Response_type_support_data_t;

static _Monitor_SendGoal_Response_type_support_data_t _Monitor_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Monitor_SendGoal_Response_message_typesupport_map = {
  2,
  "b4_serv_robot_interface",
  &_Monitor_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Monitor_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Monitor_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Monitor_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Monitor_SendGoal_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace b4_serv_robot_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<b4_serv_robot_interface::action::Monitor_SendGoal_Response>()
{
  return &::b4_serv_robot_interface::action::rosidl_typesupport_cpp::Monitor_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, b4_serv_robot_interface, action, Monitor_SendGoal_Response)() {
  return get_message_type_support_handle<b4_serv_robot_interface::action::Monitor_SendGoal_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "b4_serv_robot_interface/action/detail/monitor__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace b4_serv_robot_interface
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Monitor_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Monitor_SendGoal_type_support_ids_t;

static const _Monitor_SendGoal_type_support_ids_t _Monitor_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Monitor_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Monitor_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Monitor_SendGoal_type_support_symbol_names_t _Monitor_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, b4_serv_robot_interface, action, Monitor_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, b4_serv_robot_interface, action, Monitor_SendGoal)),
  }
};

typedef struct _Monitor_SendGoal_type_support_data_t
{
  void * data[2];
} _Monitor_SendGoal_type_support_data_t;

static _Monitor_SendGoal_type_support_data_t _Monitor_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Monitor_SendGoal_service_typesupport_map = {
  2,
  "b4_serv_robot_interface",
  &_Monitor_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_Monitor_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_Monitor_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Monitor_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Monitor_SendGoal_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace b4_serv_robot_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<b4_serv_robot_interface::action::Monitor_SendGoal>()
{
  return &::b4_serv_robot_interface::action::rosidl_typesupport_cpp::Monitor_SendGoal_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "b4_serv_robot_interface/action/detail/monitor__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace b4_serv_robot_interface
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Monitor_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Monitor_GetResult_Request_type_support_ids_t;

static const _Monitor_GetResult_Request_type_support_ids_t _Monitor_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Monitor_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Monitor_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Monitor_GetResult_Request_type_support_symbol_names_t _Monitor_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, b4_serv_robot_interface, action, Monitor_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, b4_serv_robot_interface, action, Monitor_GetResult_Request)),
  }
};

typedef struct _Monitor_GetResult_Request_type_support_data_t
{
  void * data[2];
} _Monitor_GetResult_Request_type_support_data_t;

static _Monitor_GetResult_Request_type_support_data_t _Monitor_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Monitor_GetResult_Request_message_typesupport_map = {
  2,
  "b4_serv_robot_interface",
  &_Monitor_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Monitor_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Monitor_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Monitor_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Monitor_GetResult_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace b4_serv_robot_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<b4_serv_robot_interface::action::Monitor_GetResult_Request>()
{
  return &::b4_serv_robot_interface::action::rosidl_typesupport_cpp::Monitor_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, b4_serv_robot_interface, action, Monitor_GetResult_Request)() {
  return get_message_type_support_handle<b4_serv_robot_interface::action::Monitor_GetResult_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "b4_serv_robot_interface/action/detail/monitor__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace b4_serv_robot_interface
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Monitor_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Monitor_GetResult_Response_type_support_ids_t;

static const _Monitor_GetResult_Response_type_support_ids_t _Monitor_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Monitor_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Monitor_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Monitor_GetResult_Response_type_support_symbol_names_t _Monitor_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, b4_serv_robot_interface, action, Monitor_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, b4_serv_robot_interface, action, Monitor_GetResult_Response)),
  }
};

typedef struct _Monitor_GetResult_Response_type_support_data_t
{
  void * data[2];
} _Monitor_GetResult_Response_type_support_data_t;

static _Monitor_GetResult_Response_type_support_data_t _Monitor_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Monitor_GetResult_Response_message_typesupport_map = {
  2,
  "b4_serv_robot_interface",
  &_Monitor_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Monitor_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Monitor_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Monitor_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Monitor_GetResult_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace b4_serv_robot_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<b4_serv_robot_interface::action::Monitor_GetResult_Response>()
{
  return &::b4_serv_robot_interface::action::rosidl_typesupport_cpp::Monitor_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, b4_serv_robot_interface, action, Monitor_GetResult_Response)() {
  return get_message_type_support_handle<b4_serv_robot_interface::action::Monitor_GetResult_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "b4_serv_robot_interface/action/detail/monitor__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace b4_serv_robot_interface
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Monitor_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Monitor_GetResult_type_support_ids_t;

static const _Monitor_GetResult_type_support_ids_t _Monitor_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Monitor_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Monitor_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Monitor_GetResult_type_support_symbol_names_t _Monitor_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, b4_serv_robot_interface, action, Monitor_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, b4_serv_robot_interface, action, Monitor_GetResult)),
  }
};

typedef struct _Monitor_GetResult_type_support_data_t
{
  void * data[2];
} _Monitor_GetResult_type_support_data_t;

static _Monitor_GetResult_type_support_data_t _Monitor_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Monitor_GetResult_service_typesupport_map = {
  2,
  "b4_serv_robot_interface",
  &_Monitor_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_Monitor_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_Monitor_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Monitor_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Monitor_GetResult_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace b4_serv_robot_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<b4_serv_robot_interface::action::Monitor_GetResult>()
{
  return &::b4_serv_robot_interface::action::rosidl_typesupport_cpp::Monitor_GetResult_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "b4_serv_robot_interface/action/detail/monitor__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace b4_serv_robot_interface
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Monitor_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Monitor_FeedbackMessage_type_support_ids_t;

static const _Monitor_FeedbackMessage_type_support_ids_t _Monitor_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Monitor_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Monitor_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Monitor_FeedbackMessage_type_support_symbol_names_t _Monitor_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, b4_serv_robot_interface, action, Monitor_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, b4_serv_robot_interface, action, Monitor_FeedbackMessage)),
  }
};

typedef struct _Monitor_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _Monitor_FeedbackMessage_type_support_data_t;

static _Monitor_FeedbackMessage_type_support_data_t _Monitor_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Monitor_FeedbackMessage_message_typesupport_map = {
  2,
  "b4_serv_robot_interface",
  &_Monitor_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_Monitor_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_Monitor_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Monitor_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Monitor_FeedbackMessage_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace b4_serv_robot_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<b4_serv_robot_interface::action::Monitor_FeedbackMessage>()
{
  return &::b4_serv_robot_interface::action::rosidl_typesupport_cpp::Monitor_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, b4_serv_robot_interface, action, Monitor_FeedbackMessage)() {
  return get_message_type_support_handle<b4_serv_robot_interface::action::Monitor_FeedbackMessage>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/srv/cancel_goal.hpp"
// already included above
// #include "b4_serv_robot_interface/action/detail/monitor__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_typesupport_cpp/action_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"

namespace b4_serv_robot_interface
{

namespace action
{

namespace rosidl_typesupport_cpp
{

static rosidl_action_type_support_t Monitor_action_type_support_handle = {
  NULL, NULL, NULL, NULL, NULL};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace b4_serv_robot_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
get_action_type_support_handle<b4_serv_robot_interface::action::Monitor>()
{
  using ::b4_serv_robot_interface::action::rosidl_typesupport_cpp::Monitor_action_type_support_handle;
  // Thread-safe by always writing the same values to the static struct
  Monitor_action_type_support_handle.goal_service_type_support = get_service_type_support_handle<::b4_serv_robot_interface::action::Monitor::Impl::SendGoalService>();
  Monitor_action_type_support_handle.result_service_type_support = get_service_type_support_handle<::b4_serv_robot_interface::action::Monitor::Impl::GetResultService>();
  Monitor_action_type_support_handle.cancel_service_type_support = get_service_type_support_handle<::b4_serv_robot_interface::action::Monitor::Impl::CancelGoalService>();
  Monitor_action_type_support_handle.feedback_message_type_support = get_message_type_support_handle<::b4_serv_robot_interface::action::Monitor::Impl::FeedbackMessage>();
  Monitor_action_type_support_handle.status_message_type_support = get_message_type_support_handle<::b4_serv_robot_interface::action::Monitor::Impl::GoalStatusMessage>();
  return &Monitor_action_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp
