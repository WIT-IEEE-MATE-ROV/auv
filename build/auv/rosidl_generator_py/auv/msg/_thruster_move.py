# generated from rosidl_generator_py/resource/_idl.py.em
# with input from auv:msg/ThrusterMove.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ThrusterMove(type):
    """Metaclass of message 'ThrusterMove'."""

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
                'auv.msg.ThrusterMove')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__thruster_move
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__thruster_move
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__thruster_move
            cls._TYPE_SUPPORT = module.type_support_msg__msg__thruster_move
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__thruster_move

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


class ThrusterMove(metaclass=Metaclass_ThrusterMove):
    """Message class 'ThrusterMove'."""

    __slots__ = [
        '_header',
        '_top_front',
        '_top_back',
        '_top_left',
        '_top_right',
        '_front_left',
        '_front_right',
        '_back_left',
        '_back_right',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'top_front': 'float',
        'top_back': 'float',
        'top_left': 'float',
        'top_right': 'float',
        'front_left': 'float',
        'front_right': 'float',
        'back_left': 'float',
        'back_right': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.top_front = kwargs.get('top_front', float())
        self.top_back = kwargs.get('top_back', float())
        self.top_left = kwargs.get('top_left', float())
        self.top_right = kwargs.get('top_right', float())
        self.front_left = kwargs.get('front_left', float())
        self.front_right = kwargs.get('front_right', float())
        self.back_left = kwargs.get('back_left', float())
        self.back_right = kwargs.get('back_right', float())

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
        if self.top_front != other.top_front:
            return False
        if self.top_back != other.top_back:
            return False
        if self.top_left != other.top_left:
            return False
        if self.top_right != other.top_right:
            return False
        if self.front_left != other.front_left:
            return False
        if self.front_right != other.front_right:
            return False
        if self.back_left != other.back_left:
            return False
        if self.back_right != other.back_right:
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
    def top_front(self):
        """Message field 'top_front'."""
        return self._top_front

    @top_front.setter
    def top_front(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'top_front' field must be of type 'float'"
        self._top_front = value

    @property
    def top_back(self):
        """Message field 'top_back'."""
        return self._top_back

    @top_back.setter
    def top_back(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'top_back' field must be of type 'float'"
        self._top_back = value

    @property
    def top_left(self):
        """Message field 'top_left'."""
        return self._top_left

    @top_left.setter
    def top_left(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'top_left' field must be of type 'float'"
        self._top_left = value

    @property
    def top_right(self):
        """Message field 'top_right'."""
        return self._top_right

    @top_right.setter
    def top_right(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'top_right' field must be of type 'float'"
        self._top_right = value

    @property
    def front_left(self):
        """Message field 'front_left'."""
        return self._front_left

    @front_left.setter
    def front_left(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'front_left' field must be of type 'float'"
        self._front_left = value

    @property
    def front_right(self):
        """Message field 'front_right'."""
        return self._front_right

    @front_right.setter
    def front_right(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'front_right' field must be of type 'float'"
        self._front_right = value

    @property
    def back_left(self):
        """Message field 'back_left'."""
        return self._back_left

    @back_left.setter
    def back_left(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'back_left' field must be of type 'float'"
        self._back_left = value

    @property
    def back_right(self):
        """Message field 'back_right'."""
        return self._back_right

    @back_right.setter
    def back_right(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'back_right' field must be of type 'float'"
        self._back_right = value
