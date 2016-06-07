#include <node/node.h>
#include "predict.hpp"

namespace caffejs {

/**
 * Wraps predict
 */
void predict(const v8::FunctionCallbackInfo<v8::Value> &args) {

}

}

void init(v8::Local<v8::Object> exports) {
  NODE_SET_METHOD(exports, "predict", caffejs::predict);
}

NODE_MODULE(caffejs, init);
