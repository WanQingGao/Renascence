/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: proto/GPDAG.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "proto/GPDAG.pb-c.h"
void   gp__point__init
                     (GP__Point         *message)
{
  static GP__Point init_value = GP__POINT__INIT;
  *message = init_value;
}
size_t gp__point__get_packed_size
                     (const GP__Point *message)
{
  assert(message->base.descriptor == &gp__point__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t gp__point__pack
                     (const GP__Point *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &gp__point__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t gp__point__pack_to_buffer
                     (const GP__Point *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &gp__point__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
GP__Point *
       gp__point__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (GP__Point *)
     protobuf_c_message_unpack (&gp__point__descriptor,
                                allocator, len, data);
}
void   gp__point__free_unpacked
                     (GP__Point *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &gp__point__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   gp__point_group__init
                     (GP__PointGroup         *message)
{
  static GP__PointGroup init_value = GP__POINT_GROUP__INIT;
  *message = init_value;
}
size_t gp__point_group__get_packed_size
                     (const GP__PointGroup *message)
{
  assert(message->base.descriptor == &gp__point_group__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t gp__point_group__pack
                     (const GP__PointGroup *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &gp__point_group__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t gp__point_group__pack_to_buffer
                     (const GP__PointGroup *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &gp__point_group__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
GP__PointGroup *
       gp__point_group__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (GP__PointGroup *)
     protobuf_c_message_unpack (&gp__point_group__descriptor,
                                allocator, len, data);
}
void   gp__point_group__free_unpacked
                     (GP__PointGroup *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &gp__point_group__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   gp__func_info__init
                     (GP__FuncInfo         *message)
{
  static GP__FuncInfo init_value = GP__FUNC_INFO__INIT;
  *message = init_value;
}
size_t gp__func_info__get_packed_size
                     (const GP__FuncInfo *message)
{
  assert(message->base.descriptor == &gp__func_info__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t gp__func_info__pack
                     (const GP__FuncInfo *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &gp__func_info__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t gp__func_info__pack_to_buffer
                     (const GP__FuncInfo *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &gp__func_info__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
GP__FuncInfo *
       gp__func_info__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (GP__FuncInfo *)
     protobuf_c_message_unpack (&gp__func_info__descriptor,
                                allocator, len, data);
}
void   gp__func_info__free_unpacked
                     (GP__FuncInfo *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &gp__func_info__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   gp__parallel_type__init
                     (GP__ParallelType         *message)
{
  static GP__ParallelType init_value = GP__PARALLEL_TYPE__INIT;
  *message = init_value;
}
size_t gp__parallel_type__get_packed_size
                     (const GP__ParallelType *message)
{
  assert(message->base.descriptor == &gp__parallel_type__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t gp__parallel_type__pack
                     (const GP__ParallelType *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &gp__parallel_type__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t gp__parallel_type__pack_to_buffer
                     (const GP__ParallelType *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &gp__parallel_type__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
GP__ParallelType *
       gp__parallel_type__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (GP__ParallelType *)
     protobuf_c_message_unpack (&gp__parallel_type__descriptor,
                                allocator, len, data);
}
void   gp__parallel_type__free_unpacked
                     (GP__ParallelType *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &gp__parallel_type__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   gp__dagpoint__init
                     (GP__DAGPoint         *message)
{
  static GP__DAGPoint init_value = GP__DAGPOINT__INIT;
  *message = init_value;
}
size_t gp__dagpoint__get_packed_size
                     (const GP__DAGPoint *message)
{
  assert(message->base.descriptor == &gp__dagpoint__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t gp__dagpoint__pack
                     (const GP__DAGPoint *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &gp__dagpoint__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t gp__dagpoint__pack_to_buffer
                     (const GP__DAGPoint *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &gp__dagpoint__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
GP__DAGPoint *
       gp__dagpoint__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (GP__DAGPoint *)
     protobuf_c_message_unpack (&gp__dagpoint__descriptor,
                                allocator, len, data);
}
void   gp__dagpoint__free_unpacked
                     (GP__DAGPoint *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &gp__dagpoint__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   gp__dag__connection__init
                     (GP__DAG__Connection         *message)
{
  static GP__DAG__Connection init_value = GP__DAG__CONNECTION__INIT;
  *message = init_value;
}
void   gp__dag__init
                     (GP__DAG         *message)
{
  static GP__DAG init_value = GP__DAG__INIT;
  *message = init_value;
}
size_t gp__dag__get_packed_size
                     (const GP__DAG *message)
{
  assert(message->base.descriptor == &gp__dag__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t gp__dag__pack
                     (const GP__DAG *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &gp__dag__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t gp__dag__pack_to_buffer
                     (const GP__DAG *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &gp__dag__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
GP__DAG *
       gp__dag__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (GP__DAG *)
     protobuf_c_message_unpack (&gp__dag__descriptor,
                                allocator, len, data);
}
void   gp__dag__free_unpacked
                     (GP__DAG *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &gp__dag__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCEnumValue gp__point__type__enum_values_by_number[5] =
{
  { "FUNCTION", "GP__POINT__TYPE__FUNCTION", 0 },
  { "INPUT", "GP__POINT__TYPE__INPUT", 1 },
  { "PARALLEL", "GP__POINT__TYPE__PARALLEL", 2 },
  { "ADF", "GP__POINT__TYPE__ADF", 3 },
  { "OUTPUT", "GP__POINT__TYPE__OUTPUT", 4 },
};
static const ProtobufCIntRange gp__point__type__value_ranges[] = {
{0, 0},{0, 5}
};
static const ProtobufCEnumValueIndex gp__point__type__enum_values_by_name[5] =
{
  { "ADF", 3 },
  { "FUNCTION", 0 },
  { "INPUT", 1 },
  { "OUTPUT", 4 },
  { "PARALLEL", 2 },
};
const ProtobufCEnumDescriptor gp__point__type__descriptor =
{
  PROTOBUF_C__ENUM_DESCRIPTOR_MAGIC,
  "GP.Point.TYPE",
  "TYPE",
  "GP__Point__TYPE",
  "GP",
  5,
  gp__point__type__enum_values_by_number,
  5,
  gp__point__type__enum_values_by_name,
  1,
  gp__point__type__value_ranges,
  NULL,NULL,NULL,NULL   /* reserved[1234] */
};
static const ProtobufCEnumValue gp__point__paralleltpye__enum_values_by_number[3] =
{
  { "MAP", "GP__POINT__PARALLELTPYE__MAP", 0 },
  { "REDUCE", "GP__POINT__PARALLELTPYE__REDUCE", 1 },
  { "PAL_FUNCTION", "GP__POINT__PARALLELTPYE__PAL_FUNCTION", 2 },
};
static const ProtobufCIntRange gp__point__paralleltpye__value_ranges[] = {
{0, 0},{0, 3}
};
static const ProtobufCEnumValueIndex gp__point__paralleltpye__enum_values_by_name[3] =
{
  { "MAP", 0 },
  { "PAL_FUNCTION", 2 },
  { "REDUCE", 1 },
};
const ProtobufCEnumDescriptor gp__point__paralleltpye__descriptor =
{
  PROTOBUF_C__ENUM_DESCRIPTOR_MAGIC,
  "GP.Point.PARALLELTPYE",
  "PARALLELTPYE",
  "GP__Point__PARALLELTPYE",
  "GP",
  3,
  gp__point__paralleltpye__enum_values_by_number,
  3,
  gp__point__paralleltpye__enum_values_by_name,
  1,
  gp__point__paralleltpye__value_ranges,
  NULL,NULL,NULL,NULL   /* reserved[1234] */
};
static const GP__Point__TYPE gp__point__type__default_value = GP__POINT__TYPE__INPUT;
static const ProtobufCFieldDescriptor gp__point__field_descriptors[5] =
{
  {
    "type",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_ENUM,
    0,   /* quantifier_offset */
    offsetof(GP__Point, type),
    &gp__point__type__descriptor,
    &gp__point__type__default_value,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "input_variable",
    2,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(GP__Point, n_input_variable),
    offsetof(GP__Point, input_variable),
    &gp__point__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "parallel_type",
    3,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_ENUM,
    offsetof(GP__Point, has_parallel_type),
    offsetof(GP__Point, parallel_type),
    &gp__point__paralleltpye__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "content",
    4,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(GP__Point, content),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "output_names",
    6,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_STRING,
    offsetof(GP__Point, n_output_names),
    offsetof(GP__Point, output_names),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned gp__point__field_indices_by_name[] = {
  3,   /* field[3] = content */
  1,   /* field[1] = input_variable */
  4,   /* field[4] = output_names */
  2,   /* field[2] = parallel_type */
  0,   /* field[0] = type */
};
static const ProtobufCIntRange gp__point__number_ranges[2 + 1] =
{
  { 1, 0 },
  { 6, 4 },
  { 0, 5 }
};
const ProtobufCMessageDescriptor gp__point__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "GP.Point",
  "Point",
  "GP__Point",
  "GP",
  sizeof(GP__Point),
  5,
  gp__point__field_descriptors,
  gp__point__field_indices_by_name,
  2,  gp__point__number_ranges,
  (ProtobufCMessageInit) gp__point__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor gp__point_group__field_descriptors[1] =
{
  {
    "formulas",
    1,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(GP__PointGroup, n_formulas),
    offsetof(GP__PointGroup, formulas),
    &gp__point__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned gp__point_group__field_indices_by_name[] = {
  0,   /* field[0] = formulas */
};
static const ProtobufCIntRange gp__point_group__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor gp__point_group__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "GP.PointGroup",
  "PointGroup",
  "GP__PointGroup",
  "GP",
  sizeof(GP__PointGroup),
  1,
  gp__point_group__field_descriptors,
  gp__point_group__field_indices_by_name,
  1,  gp__point_group__number_ranges,
  (ProtobufCMessageInit) gp__point_group__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor gp__func_info__field_descriptors[2] =
{
  {
    "formula",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(GP__FuncInfo, formula),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "parameters",
    2,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_DOUBLE,
    offsetof(GP__FuncInfo, n_parameters),
    offsetof(GP__FuncInfo, parameters),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned gp__func_info__field_indices_by_name[] = {
  0,   /* field[0] = formula */
  1,   /* field[1] = parameters */
};
static const ProtobufCIntRange gp__func_info__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor gp__func_info__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "GP.FuncInfo",
  "FuncInfo",
  "GP__FuncInfo",
  "GP",
  sizeof(GP__FuncInfo),
  2,
  gp__func_info__field_descriptors,
  gp__func_info__field_indices_by_name,
  1,  gp__func_info__number_ranges,
  (ProtobufCMessageInit) gp__func_info__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor gp__parallel_type__field_descriptors[1] =
{
  {
    "function",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(GP__ParallelType, function),
    &gp__func_info__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned gp__parallel_type__field_indices_by_name[] = {
  0,   /* field[0] = function */
};
static const ProtobufCIntRange gp__parallel_type__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor gp__parallel_type__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "GP.ParallelType",
  "ParallelType",
  "GP__ParallelType",
  "GP",
  sizeof(GP__ParallelType),
  1,
  gp__parallel_type__field_descriptors,
  gp__parallel_type__field_indices_by_name,
  1,  gp__parallel_type__number_ranges,
  (ProtobufCMessageInit) gp__parallel_type__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCEnumValue gp__dagpoint__type__enum_values_by_number[4] =
{
  { "FUNCTION", "GP__DAGPOINT__TYPE__FUNCTION", 0 },
  { "TRANSMIT", "GP__DAGPOINT__TYPE__TRANSMIT", 1 },
  { "INPUT", "GP__DAGPOINT__TYPE__INPUT", 2 },
  { "OUTPUT", "GP__DAGPOINT__TYPE__OUTPUT", 3 },
};
static const ProtobufCIntRange gp__dagpoint__type__value_ranges[] = {
{0, 0},{0, 4}
};
static const ProtobufCEnumValueIndex gp__dagpoint__type__enum_values_by_name[4] =
{
  { "FUNCTION", 0 },
  { "INPUT", 2 },
  { "OUTPUT", 3 },
  { "TRANSMIT", 1 },
};
const ProtobufCEnumDescriptor gp__dagpoint__type__descriptor =
{
  PROTOBUF_C__ENUM_DESCRIPTOR_MAGIC,
  "GP.DAGPoint.TYPE",
  "TYPE",
  "GP__DAGPoint__TYPE",
  "GP",
  4,
  gp__dagpoint__type__enum_values_by_number,
  4,
  gp__dagpoint__type__enum_values_by_name,
  1,
  gp__dagpoint__type__value_ranges,
  NULL,NULL,NULL,NULL   /* reserved[1234] */
};
static const ProtobufCFieldDescriptor gp__dagpoint__field_descriptors[4] =
{
  {
    "id",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(GP__DAGPoint, id),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "type",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_ENUM,
    0,   /* quantifier_offset */
    offsetof(GP__DAGPoint, type),
    &gp__dagpoint__type__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "position",
    3,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_UINT32,
    offsetof(GP__DAGPoint, has_position),
    offsetof(GP__DAGPoint, position),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "function",
    4,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(GP__DAGPoint, function),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned gp__dagpoint__field_indices_by_name[] = {
  3,   /* field[3] = function */
  0,   /* field[0] = id */
  2,   /* field[2] = position */
  1,   /* field[1] = type */
};
static const ProtobufCIntRange gp__dagpoint__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 4 }
};
const ProtobufCMessageDescriptor gp__dagpoint__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "GP.DAGPoint",
  "DAGPoint",
  "GP__DAGPoint",
  "GP",
  sizeof(GP__DAGPoint),
  4,
  gp__dagpoint__field_descriptors,
  gp__dagpoint__field_indices_by_name,
  1,  gp__dagpoint__number_ranges,
  (ProtobufCMessageInit) gp__dagpoint__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor gp__dag__connection__field_descriptors[4] =
{
  {
    "srcPoint",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(GP__DAG__Connection, srcpoint),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "dstPoint",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(GP__DAG__Connection, dstpoint),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "get_src",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(GP__DAG__Connection, get_src),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "put_dst",
    4,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(GP__DAG__Connection, put_dst),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned gp__dag__connection__field_indices_by_name[] = {
  1,   /* field[1] = dstPoint */
  2,   /* field[2] = get_src */
  3,   /* field[3] = put_dst */
  0,   /* field[0] = srcPoint */
};
static const ProtobufCIntRange gp__dag__connection__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 4 }
};
const ProtobufCMessageDescriptor gp__dag__connection__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "GP.DAG.Connection",
  "Connection",
  "GP__DAG__Connection",
  "GP",
  sizeof(GP__DAG__Connection),
  4,
  gp__dag__connection__field_descriptors,
  gp__dag__connection__field_indices_by_name,
  1,  gp__dag__connection__number_ranges,
  (ProtobufCMessageInit) gp__dag__connection__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor gp__dag__field_descriptors[2] =
{
  {
    "points",
    1,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(GP__DAG, n_points),
    offsetof(GP__DAG, points),
    &gp__dagpoint__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "connections",
    2,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(GP__DAG, n_connections),
    offsetof(GP__DAG, connections),
    &gp__dag__connection__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned gp__dag__field_indices_by_name[] = {
  1,   /* field[1] = connections */
  0,   /* field[0] = points */
};
static const ProtobufCIntRange gp__dag__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor gp__dag__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "GP.DAG",
  "DAG",
  "GP__DAG",
  "GP",
  sizeof(GP__DAG),
  2,
  gp__dag__field_descriptors,
  gp__dag__field_indices_by_name,
  1,  gp__dag__number_ranges,
  (ProtobufCMessageInit) gp__dag__init,
  NULL,NULL,NULL    /* reserved[123] */
};
