# generated from rosidl_generator_py/resource/_idl.py.em
# with input from auv:msg/JoystickChaos.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_JoystickChaos(type):
    """Metaclass of message 'JoystickChaos'."""

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
                'auv.msg.JoystickChaos')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__joystick_chaos
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__joystick_chaos
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__joystick_chaos
            cls._TYPE_SUPPORT = module.type_support_msg__msg__joystick_chaos
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__joystick_chaos

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


class JoystickChaos(metaclass=Metaclass_JoystickChaos):
    """Message class 'JoystickChaos'."""

    __slots__ = [
        '_header',
        '_shift_horizontal_correction',
        '_shift_vertical_correction',
        '_shift_twist_correction',
        '_shift_lever_correction',
        '_magnitude_horizontal_correction',
        '_magnitude_vertical_correction',
        '_magnitude_twist_correction',
        '_magnitude_lever_correction',
        '_lag_seconds',
        '_kill_thruster',
        '_unkill_thruster',
        '_thruster',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'shift_horizontal_correction': 'float',
        'shift_vertical_correction': 'float',
        'shift_twist_correction': 'float',
        'shift_lever_correction': 'float',
        'magnitude_horizontal_correction': 'float',
        'magnitude_vertical_correction': 'float',
        'magnitude_twist_correction': 'float',
        'magnitude_lever_correction': 'float',
        'lag_seconds': 'float',
        'kill_thruster': 'boolean',
        'unkill_thruster': 'boolean',
        'thruster': 'string',
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
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.shift_horizontal_correction = kwargs.get('shift_horizontal_correction', float())
        self.shift_vertical_correction = kwargs.get('shift_vertical_correction', float())
        self.shift_twist_correction = kwargs.get('shift_twist_correction', float())
        self.shift_lever_correction = kwargs.get('shift_lever_correction', float())
        self.magnitude_horizontal_correction = kwargs.get('magnitude_horizontal_correction', float())
        self.magnitude_vertical_correction = kwargs.get('magnitude_vertical_correction', float())
        self.magnitude_twist_correction = kwargs.get('magnitude_twist_correction', float())
        self.magnitude_lever_correction = kwargs.get('magnitude_lever_correction', float())
        self.lag_seconds = kwargs.get('lag_seconds', float())
        self.kill_thruster = kwargs.get('kill_thruster', bool())
        self.unkill_thruster = kwargs.get('unkill_thruster', bool())
        self.thruster = kwargs.get('thruster', str())

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
        if self.shift_horizontal_correction != other.shift_horizontal_correction:
            return False
        if self.shift_vertical_correction != other.shift_vertical_correction:
            return False
        if self.shift_twist_correction != other.shift_twist_correction:
            return False
        if self.shift_lever_correction != other.shift_lever_correction:
            return False
        if self.magnitude_horizontal_correction != other.magnitude_horizontal_correction:
            return False
        if self.magnitude_vertical_correction != other.magnitude_vertical_correction:
            return False
        if self.magnitude_twist_correction != other.magnitude_twist_correction:
            return False
        if self.magnitude_lever_correction != other.magnitude_lever_correction:
            return False
        if self.lag_seconds != other.lag_seconds:
            return False
        if self.kill_thruster != other.kill_thruster:
            return False
        if self.unkill_thruster != other.unkill_thruster:
            return False
        if self.thruster != other.thruster:
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
    def shift_horizontal_correction(self):
        """Message field 'shift_horizontal_correction'."""
        return self._shift_horizontal_correction

    @shift_horizontal_correction.setter
    def shift_horizontal_correction(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'shift_horizontal_correction' field must be of type 'float'"
        self._shift_horizontal_correction = value

    @property
    def shift_vertical_correction(self):
        """Message field 'shift_vertical_correction'."""
        return self._shift_vertical_correction

    @shift_vertical_correction.setter
    def shift_vertical_correction(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'shift_vertical_correction' field must be of type 'float'"
        self._shift_vertical_correction = value

    @property
    def shift_twist_correction(self):
        """Message field 'shift_twist_correction'."""
        return self._shift_twist_correction

    @shift_twist_correction.setter
    def shift_twist_correction(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'shift_twist_correction' field must be of type 'float'"
        self._shift_twist_correction = value

    @property
    def shift_lever_correction(self):
        """Message field 'shift_lever_correction'."""
        return self._shift_lever_correction

    @shift_lever_correction.setter
    def shift_lever_correction(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'shift_lever_correction' field must be of type 'float'"
        self._shift_lever_correction = value

    @property
    def magnitude_horizontal_correction(self):
        """Message field 'magnitude_horizontal_correction'."""
        return self._magnitude_horizontal_correction

    @magnitude_horizontal_correction.setter
    def magnitude_horizontal_correction(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'magnitude_horizontal_correction' field must be of type 'float'"
        self._magnitude_horizontal_correction = value

    @property
    def magnitude_vertical_correction(self):
        """Message field 'magnitude_vertical_correction'."""
        return self._magnitude_vertical_correction

    @magnitude_vertical_correction.setter
    def magnitude_vertical_correction(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'magnitude_vertical_correction' field must be of type 'float'"
        self._magnitude_vertical_correction = value

    @property
    def magnitude_twist_correction(self):
        """Message field 'magnitude_twist_correction'."""
        return self._magnitude_twist_correction

    @magnitude_twist_correction.setter
    def magnitude_twist_correction(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'magnitude_twist_correction' field must be of type 'float'"
        self._magnitude_twist_correction = value

    @property
    def magnitude_lever_correction(self):
        """Message field 'magnitude_lever_correction'."""
        return self._magnitude_lever_correction

    @magnitude_lever_correction.setter
    def magnitude_lever_correction(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'magnitude_lever_correction' field must be of type 'float'"
        self._magnitude_lever_correction = value

    @property
    def lag_seconds(self):
        """Message field 'lag_seconds'."""
        return self._lag_seconds

    @lag_seconds.setter
    def lag_seconds(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'lag_seconds' field must be of type 'float'"
        self._lag_seconds = value

    @property
    def kill_thruster(self):
        """Message field 'kill_thruster'."""
        return self._kill_thruster

    @kill_thruster.setter
    def kill_thruster(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'kill_thruster' field must be of type 'bool'"
        self._kill_thruster = value

    @property
    def unkill_thruster(self):
        """Message field 'unkill_thruster'."""
        return self._unkill_thruster

    @unkill_thruster.setter
    def unkill_thruster(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'unkill_thruster' field must be of type 'bool'"
        self._unkill_thruster = value

    @property
    def thruster(self):
        """Message field 'thruster'."""
        return self._thruster

    @thruster.setter
    def thruster(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'thruster' field must be of type 'str'"
        self._thruster = value
