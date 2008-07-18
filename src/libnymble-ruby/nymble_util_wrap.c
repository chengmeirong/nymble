#include "nymble_util_wrap.h"

VALUE rb_nymble_hash(VALUE rb_self, VALUE rb_value) {
  rb_value      = rb_funcall(rb_value, rb_intern("to_s"), 0);
  u_char *value = (u_char *)RSTRING(rb_value)->ptr;
  u_int size    = RSTRING(rb_value)->len;
  
  u_char buffer[DIGEST_SIZE];
  
  hash(buffer, value, size);

  return rb_str_new((char *)&buffer, sizeof(buffer));
}

VALUE rb_nymble_random_bytes(VALUE rb_self, VALUE rb_count) {
  if (TYPE(rb_count) != T_FIXNUM) {
    return Qnil;
  }

  u_int size = NUM2UINT(rb_count);
  u_char buffer[size];
  
  random_bytes(buffer, size);
  
  return rb_str_new((char *)buffer, sizeof(buffer));
}