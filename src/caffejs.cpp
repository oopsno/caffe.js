#include <node/node.h>
#include "predict.hpp"

namespace caffejs {

using V8Arg = v8::FunctionCallbackInfo<v8::Value>;

/**
 * Wraps predict
 */
void predict(V8Arg &args) {

}


}

void init(v8::Local<v8::Object> exports) {
  NODE_SET_METHOD(exports, "predict", predict);
}

NODE_MODULE(caffejs, init);
