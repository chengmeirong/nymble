#include "nymble_pseudonym_wrap.h"

VALUE rb_pseudonym_unmarshall(VALUE rb_self, VALUE rb_bytes)
{
  char* bytes = (char*) RSTRING_PTR(rb_bytes);
  Pseudonym* pseudonym = Pseudonym::unmarshall(bytes);
  
  if (pseudonym == NULL) {
    return Qnil;
  }
  
  return Data_Wrap_Struct(rb_self, NULL, rb_pseudonym_delete, pseudonym);
}

VALUE rb_pseudonym_marshall(VALUE rb_self)
{
  Check_Type(rb_self, T_DATA);
  Check_Class(rb_self, rb_cPseudonym);
  
  Pseudonym* pseudonym = (Pseudonym*) DATA_PTR(rb_self);
  u_int bytes_len = pseudonym->marshall();
  char bytes[bytes_len];
  
  pseudonym->marshall(bytes);
  
  return rb_str_new(bytes, bytes_len);
}

void rb_pseudonym_delete(Pseudonym* pseudonym)
{
  delete pseudonym;
}