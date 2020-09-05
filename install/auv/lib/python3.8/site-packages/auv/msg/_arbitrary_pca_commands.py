# generated from rosidl_generator_py/resource/_idl.py.em
# with input from auv:msg/ArbitraryPcaCommands.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ArbitraryPcaCommands(type):
    """Metaclass of message 'ArbitraryPcaCommands'."""

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
                'auv.msg.ArbitraryPcaCommands')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__arbitrary_pca_commands
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__arbitrary_pca_commands
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__arbitrary_pca_commands
            cls._TYPE_SUPPORT = module.type_support_msg__msg__arbitrary_pca_commands
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__arbitrary_pca_commands

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


class ArbitraryPcaCommands(metaclass=Metaclass_ArbitraryPcaCommands):
    """Message class 'ArbitraryPcaCommands'."""

    __slots__ = [
        '_header',
        '_set_thruster',
        '_set_channel_pwm',
        '_set_channel_pwm_send_count',
        '_kill_thruster',
        '_unkill_thruster',
        '_thruster',
        '_channel',
        '_count',
        '_pwm',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'set_thruster': 'boolean',
        'set_channel_pwm': 'boolean',
        'set_channel_pwm_send_count': 'boolean',
        'kill_thruster': 'boolean',
        'unkill_thruster': 'boolean',
        'thruster': 'string',
        'channel': 'uint8',
        'count': 'uint16',
        'pwm': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.set_thruster = kwargs.get('set_thruster', bool())
        self.set_channel_pwm = kwargs.get('set_channel_pwm', bool())
        self.set_channel_pwm_send_count = kwargs.get('set_channel_pwm_send_count', bool())
        self.kill_thruster = kwargs.get('kill_thruster', bool())
        self.unkill_thruster = kwargs.get('unkill_thruster', bool())
        self.thruster = kwargs.get('thruster', str())
        self.channel = kwargs.get('channel', int())
        self.count = kwargs.get('count', int())
        self.pwm = kwargs.get('pwm', float())

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
        if self.set_thruster != other.set_thruster:
            return False
        if self.set_channel_pwm != other.set_channel_pwm:
            return False
        if self.set_channel_pwm_send_count != other.set_channel_pwm_send_count:
            return False
        if self.kill_thruster != other.kill_thruster:
            return False
        if self.unkill_thruster != other.unkill_thruster:
            return False
        if self.thruster != other.thruster:
            return False
        if self.channel != other.channel:
            return False
        if self.count != other.count:
            return False
        if self.pwm != other.pwm:
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
    def set_thruster(self):
        """Message field 'set_thruster'."""
        return self._set_thruster

    @set_thruster.setter
    def set_thruster(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'set_thruster' field must be of type 'bool'"
        self._set_thruster = value

    @property
    def set_channel_pwm(self):
        """Message field 'set_channel_pwm'."""
        return self._set_channel_pwm

    @set_channel_pwm.setter
    def set_channel_pwm(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'set_channel_pwm' field must be of type 'bool'"
        self._set_channel_pwm = value

    @property
    def set_channel_pwm_send_count(self):
        """Message field 'set_channel_pwm_send_count'."""
        return self._set_channel_pwm_send_count

    @set_channel_pwm_send_count.setter
    def set_channel_pwm_send_count(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'set_channel_pwm_send_count' field must be of type 'bool'"
        self._set_channel_pwm_send_count = value

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

    @property
    def channel(self):
        """Message field 'channel'."""
        return self._channel

    @channel.setter
    def channel(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'channel' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'channel' field must be an unsigned integer in [0, 255]"
        self._channel = value

    @property
    def count(self):
        """Message field 'count'."""
        return self._count

    @count.setter
    def count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'count' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'count' field must be an unsigned integer in [0, 65535]"
        self._count = value

    @property
    def pwm(self):
        """Message field 'pwm'."""
        return self._pwm

    @pwm.setter
    def pwm(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pwm' field must be of type 'float'"
        self._pwm = value
