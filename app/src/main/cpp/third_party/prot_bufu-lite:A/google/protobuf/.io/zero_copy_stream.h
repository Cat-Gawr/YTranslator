// ZeroCopyInputStream example:
//   // Read in a file and print its contents to stdout.
//   int fd = open("myfile", O_RDONLY);
//   ZeroCopyInputStream* input = new FileInputStream(fd);
//
//   const void* buffer;
//   int size;
//   while (input->Next(&buffer, &size)) {
//     cout.write(buffer, size);
//   }
//
//   delete input;
//   close(fd);
//
// ZeroCopyOutputStream example:
//   // Copy the contents of "infile" to "outfile", using plain read() for
//   // "infile" but a ZeroCopyOutputStream for "outfile".
//   int infd = open("infile", O_RDONLY);
//   int outfd = open("outfile", O_WRONLY);
//   ZeroCopyOutputStream* output = new FileOutputStream(outfd);
//
//   void* buffer;
//   int size;
//   while (output->Next(&buffer, &size)) {
//     int bytes = read(infd, buffer, size);
//     if (bytes < size) {
//       // Reached EOF.
//       output->BackUp(size - bytes);
//       break;
//     }
//   }
//
//   delete output;
//   close(infd);
//   close(outfd);

#ifndef GOOGLE_PROTOBUF_IO_ZERO_COPY_STREAM_H__
#define GOOGLE_PROTOBUF_IO_ZERO_COPY_STREAM_H__


#include <string>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/port_def.inc>


namespace google {
namespace protobuf {
namespace io {

// Defined in this file.
class ZeroCopyInputStream;
class ZeroCopyOutputStream;

// Abstract interface similar to an input stream but designed to minimize
// copying.
class PROTOBUF_EXPORT ZeroCopyInputStream {
 public:
  ZeroCopyInputStream() {}
  virtual ~ZeroCopyInputStream() {}

  // Obtains a chunk of data from the stream.
  //
  // Preconditions:
  // * "size" and "data" are not NULL.
  //
  // Postconditions:
  // * If the returned value is false, there is no more data to return or
  //   an error occurred.  All errors are permanent.
  // * Otherwise, "size" points to the actual number of bytes read and "data"
  //   points to a pointer to a buffer containing these bytes.
  // * Ownership of this buffer remains with the stream, and the buffer
  //   remains valid only until some other method of the stream is called
  //   or the stream is destroyed.
  // * It is legal for the returned buffer to have zero size, as long
  //   as repeatedly calling Next() eventually yields a buffer with non-zero
  //   size.
  virtual bool Next(const void** data, int* size) = 0;

  // Backs up a number of bytes, so that the next call to Next() returns
  // data again that was already returned by the last call to Next().  This
  // is useful when writing procedures that are only supposed to read up
  // to a certain point in the input, then return.  If Next() returns a
  // buffer that goes beyond what you wanted to read, you can use BackUp()
  // to return to the point where you intended to finish.
  //
  // Preconditions:
  // * The last method called must have been Next().
  // * count must be less than or equal to the size of the last buffer
  //   returned by Next().
  //
  // Postconditions:
  // * The last "count" bytes of the last buffer returned by Next() will be
  //   pushed back into the stream.  Subsequent calls to Next() will return
  //   the same data again before producing new data.
  virtual void BackUp(int count) = 0;

  // Skips a number of bytes.  Returns false if the end of the stream is
  // reached or some input error occurred.  In the end-of-stream case, the
  // stream is advanced to the end of the stream (so ByteCount() will return
  // the total size of the stream).
  virtual bool Skip(int count) = 0;

  // Returns the total number of bytes read since this object was created.
  virtual int64_t ByteCount() const = 0;


 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(ZeroCopyInputStream);
};

// Abstract interface similar to an output stream but designed to minimize
// copying.
class PROTOBUF_EXPORT ZeroCopyOutputStream {
 public:
  ZeroCopyOutputStream() {}
  virtual ~ZeroCopyOutputStream() {}

  // Obtains a buffer into which data can be written.  Any data written
  // into this buffer will eventually (maybe instantly, maybe later on)
  // be written to the output.
  //
  // Preconditions:
  // * "size" and "data" are not NULL.
  //
  // Postconditions:
  // * If the returned value is false, an error occurred.  All errors are
  //   permanent.
  // * Otherwise, "size" points to the actual number of bytes in the buffer
  //   and "data" points to the buffer.
  // * Ownership of this buffer remains with the stream, and the buffer
  //   remains valid only until some other method of the stream is called
  //   or the stream is destroyed.
  // * Any data which the caller stores in this buffer will eventually be
  //   written to the output (unless BackUp() is called).
  // * It is legal for the returned buffer to have zero size, as long
  //   as repeatedly calling Next() eventually yields a buffer with non-zero
  //   size.
  virtual bool Next(void** data, int* size) = 0;

  // Backs up a number of bytes, so that the end of the last buffer returned
  // by Next() is not actually written.  This is needed when you finish
  // writing all the data you want to write, but the last buffer was bigger
  // than you needed.  You don't want to write a bunch of garbage after the
  // end of your data, so you use BackUp() to back up.
  //
  // Preconditions:
  // * The last method called must have been Next().
  // * count must be less than or equal to the size of the last buffer
  //   returned by Next().
  // * The caller must not have written anything to the last "count" bytes
  //   of that buffer.
  //
  // Postconditions:
  // * The last "count" bytes of the last buffer returned by Next() will be
  //   ignored.
  virtual void BackUp(int count) = 0;

  // Returns the total number of bytes written since this object was created.
  virtual int64_t ByteCount() const = 0;

  // Write a given chunk of data to the output.  Some output streams may
  // implement this in a way that avoids copying. Check AllowsAliasing() before
  // calling WriteAliasedRaw(). It will GOOGLE_CHECK fail if WriteAliasedRaw() is
  // called on a stream that does not allow aliasing.
  //
  // NOTE: It is caller's responsibility to ensure that the chunk of memory
  // remains live until all of the data has been consumed from the stream.
  virtual bool WriteAliasedRaw(const void* data, int size);
  virtual bool AllowsAliasing() const { return false; }


 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(ZeroCopyOutputStream);
};

}  // namespace io
}  // namespace protobuf
}  // namespace google

#include <google/protobuf/port_undef.inc>

#endif  // GOOGLE_PROTOBUF_IO_ZERO_COPY_STREAM_H__
