# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from mavros_msgs/GlobalPositionTarget.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import geometry_msgs.msg
import std_msgs.msg

class GlobalPositionTarget(genpy.Message):
  _md5sum = "076ded0190b9e045f9c55264659ef102"
  _type = "mavros_msgs/GlobalPositionTarget"
  _has_header = True #flag to mark the presence of a Header object
  _full_text = """# Message for SET_POSITION_TARGET_GLOBAL_INT
#
# Some complex system requires all feautures that mavlink
# message provide. See issue #402, #415.

std_msgs/Header header

uint8 coordinate_frame
uint8 FRAME_GLOBAL_INT = 5
uint8 FRAME_GLOBAL_REL_ALT = 6
uint8 FRAME_GLOBAL_TERRAIN_ALT = 11

uint16 type_mask
uint16 IGNORE_LATITUDE = 1	# Position ignore flags
uint16 IGNORE_LONGITUDE = 2
uint16 IGNORE_ALTITUDE = 4
uint16 IGNORE_VX = 8	# Velocity vector ignore flags
uint16 IGNORE_VY = 16
uint16 IGNORE_VZ = 32
uint16 IGNORE_AFX = 64	# Acceleration/Force vector ignore flags
uint16 IGNORE_AFY = 128
uint16 IGNORE_AFZ = 256
uint16 FORCE = 512	# Force in af vector flag
uint16 IGNORE_YAW = 1024
uint16 IGNORE_YAW_RATE = 2048

float64 latitude
float64 longitude
float32 altitude	# in meters, AMSL or above terrain
geometry_msgs/Vector3 velocity
geometry_msgs/Vector3 acceleration_or_force
float32 yaw
float32 yaw_rate

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z"""
  # Pseudo-constants
  FRAME_GLOBAL_INT = 5
  FRAME_GLOBAL_REL_ALT = 6
  FRAME_GLOBAL_TERRAIN_ALT = 11
  IGNORE_LATITUDE = 1
  IGNORE_LONGITUDE = 2
  IGNORE_ALTITUDE = 4
  IGNORE_VX = 8
  IGNORE_VY = 16
  IGNORE_VZ = 32
  IGNORE_AFX = 64
  IGNORE_AFY = 128
  IGNORE_AFZ = 256
  FORCE = 512
  IGNORE_YAW = 1024
  IGNORE_YAW_RATE = 2048

  __slots__ = ['header','coordinate_frame','type_mask','latitude','longitude','altitude','velocity','acceleration_or_force','yaw','yaw_rate']
  _slot_types = ['std_msgs/Header','uint8','uint16','float64','float64','float32','geometry_msgs/Vector3','geometry_msgs/Vector3','float32','float32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       header,coordinate_frame,type_mask,latitude,longitude,altitude,velocity,acceleration_or_force,yaw,yaw_rate

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(GlobalPositionTarget, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.coordinate_frame is None:
        self.coordinate_frame = 0
      if self.type_mask is None:
        self.type_mask = 0
      if self.latitude is None:
        self.latitude = 0.
      if self.longitude is None:
        self.longitude = 0.
      if self.altitude is None:
        self.altitude = 0.
      if self.velocity is None:
        self.velocity = geometry_msgs.msg.Vector3()
      if self.acceleration_or_force is None:
        self.acceleration_or_force = geometry_msgs.msg.Vector3()
      if self.yaw is None:
        self.yaw = 0.
      if self.yaw_rate is None:
        self.yaw_rate = 0.
    else:
      self.header = std_msgs.msg.Header()
      self.coordinate_frame = 0
      self.type_mask = 0
      self.latitude = 0.
      self.longitude = 0.
      self.altitude = 0.
      self.velocity = geometry_msgs.msg.Vector3()
      self.acceleration_or_force = geometry_msgs.msg.Vector3()
      self.yaw = 0.
      self.yaw_rate = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_BH2df6d2f().pack(_x.coordinate_frame, _x.type_mask, _x.latitude, _x.longitude, _x.altitude, _x.velocity.x, _x.velocity.y, _x.velocity.z, _x.acceleration_or_force.x, _x.acceleration_or_force.y, _x.acceleration_or_force.z, _x.yaw, _x.yaw_rate))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.velocity is None:
        self.velocity = geometry_msgs.msg.Vector3()
      if self.acceleration_or_force is None:
        self.acceleration_or_force = geometry_msgs.msg.Vector3()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 79
      (_x.coordinate_frame, _x.type_mask, _x.latitude, _x.longitude, _x.altitude, _x.velocity.x, _x.velocity.y, _x.velocity.z, _x.acceleration_or_force.x, _x.acceleration_or_force.y, _x.acceleration_or_force.z, _x.yaw, _x.yaw_rate,) = _get_struct_BH2df6d2f().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_BH2df6d2f().pack(_x.coordinate_frame, _x.type_mask, _x.latitude, _x.longitude, _x.altitude, _x.velocity.x, _x.velocity.y, _x.velocity.z, _x.acceleration_or_force.x, _x.acceleration_or_force.y, _x.acceleration_or_force.z, _x.yaw, _x.yaw_rate))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.velocity is None:
        self.velocity = geometry_msgs.msg.Vector3()
      if self.acceleration_or_force is None:
        self.acceleration_or_force = geometry_msgs.msg.Vector3()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 79
      (_x.coordinate_frame, _x.type_mask, _x.latitude, _x.longitude, _x.altitude, _x.velocity.x, _x.velocity.y, _x.velocity.z, _x.acceleration_or_force.x, _x.acceleration_or_force.y, _x.acceleration_or_force.z, _x.yaw, _x.yaw_rate,) = _get_struct_BH2df6d2f().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_3I = None
def _get_struct_3I():
    global _struct_3I
    if _struct_3I is None:
        _struct_3I = struct.Struct("<3I")
    return _struct_3I
_struct_BH2df6d2f = None
def _get_struct_BH2df6d2f():
    global _struct_BH2df6d2f
    if _struct_BH2df6d2f is None:
        _struct_BH2df6d2f = struct.Struct("<BH2df6d2f")
    return _struct_BH2df6d2f
