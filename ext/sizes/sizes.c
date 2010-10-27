#include "ruby.h"

static VALUE sizeof_char(VALUE self)               { return INT2FIX(sizeof(char)); }
static VALUE sizeof_unsigned_char(VALUE self)      { return INT2FIX(sizeof(unsigned char)); }
static VALUE sizeof_signed_char(VALUE self)        { return INT2FIX(sizeof(signed char)); }
static VALUE sizeof_signed_int(VALUE self)         { return INT2FIX(sizeof(signed int)); }
static VALUE sizeof_signed_short_int(VALUE self)   { return INT2FIX(sizeof(signed short int)); }
static VALUE sizeof_long_int(VALUE self)           { return INT2FIX(sizeof(long int)); }
static VALUE sizeof_unsigned_int(VALUE self)       { return INT2FIX(sizeof(unsigned int)); }
static VALUE sizeof_unsigned_short_int(VALUE self) { return INT2FIX(sizeof(unsigned short int)); }
static VALUE sizeof_unsigned_long_int(VALUE self)  { return INT2FIX(sizeof(unsigned long int)); }
static VALUE sizeof_float(VALUE self)              { return INT2FIX(sizeof(float)); }
static VALUE sizeof_double(VALUE self)             { return INT2FIX(sizeof(double)); }
static VALUE sizeof_long_double(VALUE self)        { return INT2FIX(sizeof(long double)); }

void Init_sizes()
{
  VALUE mSizes = rb_define_module("Sizes");
  
  rb_define_module_function(mSizes, "sizeof_char",               sizeof_char,               0);
  rb_define_module_function(mSizes, "sizeof_unsigned_char",      sizeof_unsigned_char,      0);
  rb_define_module_function(mSizes, "sizeof_signed_char",        sizeof_signed_char,        0);
  rb_define_module_function(mSizes, "sizeof_signed_int",         sizeof_signed_int,         0);
  rb_define_module_function(mSizes, "sizeof_signed_short_int",   sizeof_signed_short_int,   0);
  rb_define_module_function(mSizes, "sizeof_long_int",           sizeof_long_int,           0);
  rb_define_module_function(mSizes, "sizeof_unsigned_int",       sizeof_unsigned_int,       0);
  rb_define_module_function(mSizes, "sizeof_unsigned_short_int", sizeof_unsigned_short_int, 0);
  rb_define_module_function(mSizes, "sizeof_unsigned_long_int",  sizeof_unsigned_long_int,  0);
  rb_define_module_function(mSizes, "sizeof_float",              sizeof_float,              0);
  rb_define_module_function(mSizes, "sizeof_double",             sizeof_double,             0);
  rb_define_module_function(mSizes, "sizeof_long_double",        sizeof_long_double,        0);
}
