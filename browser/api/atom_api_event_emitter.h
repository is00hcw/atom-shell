// Copyright (c) 2013 GitHub, Inc. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ATOM_BROWSER_API_ATOM_API_EVENT_EMITTER_H_
#define ATOM_BROWSER_API_ATOM_API_EVENT_EMITTER_H_

#include <iosfwd>

#include "browser/api/atom_api_recorded_object.h"

namespace base {
class ListValue;
}

namespace atom {

namespace api {

// Class interiting EventEmitter should assume it's a javascript object which
// interits require('events').EventEmitter, this class provides many helper
// methods to do event processing in C++.
class EventEmitter : public RecordedObject {
 public:
  virtual ~EventEmitter();

  // Emit an event and returns whether the handler has called preventDefault().
  bool Emit(const std::string& name, base::ListValue* args);

 protected:
  explicit EventEmitter(v8::Handle<v8::Object> wrapper);

 private:
  DISALLOW_COPY_AND_ASSIGN(EventEmitter);
};

}  // namespace api

}  // namespace atom

#endif  // ATOM_BROWSER_API_ATOM_API_EVENT_EMITTER_H_