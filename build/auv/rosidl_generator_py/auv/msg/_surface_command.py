# generated from rosidl_generator_py/resource/_idl.py.em
# with input from auv:msg/SurfaceCommand.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SurfaceCommand(type):
    """Metaclass of message 'SurfaceCommand'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('auv')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'auv.msg.SurfaceCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__surface_command
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__surface_command
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__surface_command
            cls._TYPE_SUPPORT = module.type_support_msg__msg__surface_command
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__surface_command

            from auv.msg import IoRequest
            if IoRequest.__class__._TYPE_SUPPORT is None:
                IoRequest.__class__.__import_type_support__()

            from auv.msg import Trajectory
            if Trajectory.__class__._TYPE_SUPPORT is None:
                Trajectory.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SurfaceCommand(metaclass=Metaclass_SurfaceCommand):
    """Message class 'SurfaceCommand'."""

    __slots__ = [
        '_header',
        '_desired_trajectory',
        '_io_requests',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'desired_trajectory': 'auv/Trajectory',
        'io_requests': 'sequence<auv/IoRequest>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['auv', 'msg'], 'Trajectory'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['auv', 'msg'], 'IoRequest')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        from auv.msg import Trajectory
        self.desired_trajectory = kwargs.get('desired_trajectory', Trajectory())
        self.io_requests = kwargs.get('io_requests', [])

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.desired_trajectory != other.desired_trajectory:
            return False
        if self.io_requests != other.io_requests:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @property
    def desired_trajectory(self):
        """Message field 'desired_trajectory'."""
        return self._desired_trajectory

    @desired_trajectory.setter
    def desired_trajectory(self, value):
        if __debug__:
            from auv.msg import Trajectory
            assert \
                isinstance(value, Trajectory), \
                "The 'desired_trajectory' field must be a sub message of type 'Trajectory'"
        self._desired_trajectory = value

    @property
    def io_requests(self):
        """Message field 'io_requests'."""
        return self._io_requests

    @io_requests.setter
    def io_requests(self, value):
        if __debug__:
            from auv.msg import IoRequest
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, IoRequest) for v in value) and
                 True), \
                "The 'io_requests' field must be a set or sequence and each value of type 'IoRequest'"
        self._io_requests = value
