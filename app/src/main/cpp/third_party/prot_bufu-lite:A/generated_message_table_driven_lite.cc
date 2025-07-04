#include <google/protobuf/generated_message_table_driven_lite.h>

#include <type_traits>

#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/wire_format_lite.h>

namespace google {
namespace protobuf {
namespace internal {

namespace {

std::string* MutableUnknownFields(MessageLite* msg, int64 arena_offset) {
  return Raw<InternalMetadata>(msg, arena_offset)
      ->mutable_unknown_fields<std::string>();
}

struct UnknownFieldHandlerLite {
  // TODO(mvels): consider renaming UnknownFieldHandler to (TableDrivenTraits?),
  // and conflating InternalMetaData into it, simplifying the template.
  static constexpr bool IsLite() { return true; }

  static bool Skip(MessageLite* msg, const ParseTable& table,
                   io::CodedInputStream* input, int tag) {
    GOOGLE_DCHECK(!table.unknown_field_set);
    io::StringOutputStream unknown_fields_string(
        MutableUnknownFields(msg, table.arena_offset));
    io::CodedOutputStream unknown_fields_stream(&unknown_fields_string, false);

    return internal::WireFormatLite::SkipField(input, tag,
                                               &unknown_fields_stream);
  }

  static void Varint(MessageLite* msg, const ParseTable& table, int tag,
                     int value) {
    GOOGLE_DCHECK(!table.unknown_field_set);

    io::StringOutputStream unknown_fields_string(
        MutableUnknownFields(msg, table.arena_offset));
    io::CodedOutputStream unknown_fields_stream(&unknown_fields_string, false);
    unknown_fields_stream.WriteVarint32(tag);
    unknown_fields_stream.WriteVarint32(value);
  }

  static bool ParseExtension(MessageLite* msg, const ParseTable& table,
                             io::CodedInputStream* input, int tag) {
    ExtensionSet* extensions = GetExtensionSet(msg, table.extension_offset);
    if (extensions == NULL) {
      return false;
    }

    const MessageLite* prototype = table.default_instance();

    GOOGLE_DCHECK(!table.unknown_field_set);
    io::StringOutputStream unknown_fields_string(
        MutableUnknownFields(msg, table.arena_offset));
    io::CodedOutputStream unknown_fields_stream(&unknown_fields_string, false);
    return extensions->ParseField(tag, input, prototype,
                                  &unknown_fields_stream);
  }
};

}  // namespace

bool MergePartialFromCodedStreamLite(MessageLite* msg, const ParseTable& table,
                                     io::CodedInputStream* input) {
  return MergePartialFromCodedStreamImpl<UnknownFieldHandlerLite>(msg, table,
                                                                  input);
}

}  // namespace internal
}  // namespace protobuf
}  // namespace google
