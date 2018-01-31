#include <node.h>
#include "../markdown.h"

namespace blackfriday {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

const char* ToCString(const String::Utf8Value& value) {
  return *value ? *value : "<string conversion failed>";
}

void Method(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  String::Utf8Value str(args[0]);
  const char* cstr = ToCString(str);
  char * charstr = const_cast<char *>(cstr);
  char* result = Markdown(charstr);
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, result));
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "markdown", Method);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace blackfriday