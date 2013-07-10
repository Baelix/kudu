// Copyright (c) 2012, Cloudera, inc.

#include <boost/thread/mutex.hpp>

#include "server/oid_generator.h"
#include "gutil/stringprintf.h"

namespace kudu {

string ObjectIdGenerator::Next() {
  boost::lock_guard<LockType> l(oid_lock_);
  boost::uuids::uuid oid = oid_generator_();
  const uint8_t *uuid = oid.data;
  return StringPrintf("%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
               uuid[0], uuid[1], uuid[2], uuid[3], uuid[4], uuid[5], uuid[6], uuid[7],
               uuid[8], uuid[9], uuid[10], uuid[11], uuid[12], uuid[13], uuid[14], uuid[15]);
}

} // namespace kudu
