#include "ruby.h"

#if HAVE_STDDEF_H
  #include <stddef.h>
#endif

#if HAVE_STDLIB_H
  #include <stdlib.h>
#endif

#if HAVE_INTTYPES_H
  #include <inttypes.h>
#endif

/* I almost wonder if I should have just generated this file with Ruby. Ah, well... */

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

/* C99 types */
#if HAVE_STDDEF_H || HAVE_STDLIB_H
  static VALUE sizeof_size(VALUE self)        { return INT2FIX(sizeof(size_t)); }
  static VALUE sizeof_wchar(VALUE self)       { return INT2FIX(sizeof(wchar_t)); }
#endif

#if HAVE_INTTYPES_H
  static VALUE sizeof_int8(VALUE self)          { return INT2FIX(sizeof(int8_t));   }
  static VALUE sizeof_int16(VALUE self)         { return INT2FIX(sizeof(int16_t));  }
  static VALUE sizeof_int32(VALUE self)         { return INT2FIX(sizeof(int32_t));  }
  static VALUE sizeof_int64(VALUE self)         { return INT2FIX(sizeof(int64_t));  }
  static VALUE sizeof_uint8(VALUE self)         { return INT2FIX(sizeof(uint8_t));  }
  static VALUE sizeof_uint16(VALUE self)        { return INT2FIX(sizeof(uint16_t)); }
  static VALUE sizeof_uint32(VALUE self)        { return INT2FIX(sizeof(uint32_t)); }
  static VALUE sizeof_uint64(VALUE self)        { return INT2FIX(sizeof(uint64_t)); }

  static VALUE sizeof_int_least8(VALUE self)    { return INT2FIX(sizeof(int_least8_t));   }
  static VALUE sizeof_int_least16(VALUE self)   { return INT2FIX(sizeof(int_least16_t));  }
  static VALUE sizeof_int_least32(VALUE self)   { return INT2FIX(sizeof(int_least32_t));  }
  static VALUE sizeof_int_least64(VALUE self)   { return INT2FIX(sizeof(int_least64_t));  }
  static VALUE sizeof_uint_least8(VALUE self)   { return INT2FIX(sizeof(uint_least8_t));  }
  static VALUE sizeof_uint_least16(VALUE self)  { return INT2FIX(sizeof(uint_least16_t)); }
  static VALUE sizeof_uint_least32(VALUE self)  { return INT2FIX(sizeof(uint_least32_t)); }
  static VALUE sizeof_uint_least64(VALUE self)  { return INT2FIX(sizeof(uint_least64_t)); }

  static VALUE sizeof_int_fast8(VALUE self)     { return INT2FIX(sizeof(int_fast8_t));   }
  static VALUE sizeof_int_fast16(VALUE self)    { return INT2FIX(sizeof(int_fast16_t));  }
  static VALUE sizeof_int_fast32(VALUE self)    { return INT2FIX(sizeof(int_fast32_t));  }
  static VALUE sizeof_int_fast64(VALUE self)    { return INT2FIX(sizeof(int_fast64_t));  }
  static VALUE sizeof_uint_fast8(VALUE self)    { return INT2FIX(sizeof(uint_fast8_t));  }
  static VALUE sizeof_uint_fast16(VALUE self)   { return INT2FIX(sizeof(uint_fast16_t)); }
  static VALUE sizeof_uint_fast32(VALUE self)   { return INT2FIX(sizeof(uint_fast32_t)); }
  static VALUE sizeof_uint_fast64(VALUE self)   { return INT2FIX(sizeof(uint_fast64_t)); }

  static VALUE sizeof_intptr(VALUE self)        { return INT2FIX(sizeof(intptr_t));  }
  static VALUE sizeof_uintptr(VALUE self)       { return INT2FIX(sizeof(uintptr_t)); }
  static VALUE sizeof_intmax(VALUE self)        { return INT2FIX(sizeof(intmax_t));  }
  static VALUE sizeof_uintmax(VALUE self)       { return INT2FIX(sizeof(uintmax_t)); }
#endif

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
  
  /* C99 types */
  #if HAVE_STDDEF_H || HAVE_STDLIB_H
    rb_define_module_function(mSizes, "sizeof_size",        sizeof_size,        0);
    rb_define_module_function(mSizes, "sizeof_wchar",       sizeof_wchar,       0);
  #endif
  
  #if HAVE_STDINT_H
    rb_define_module_function(mSizes, "sizeof_int8",        sizeof_int8,        0);
    rb_define_module_function(mSizes, "sizeof_int16",       sizeof_int16,       0);
    rb_define_module_function(mSizes, "sizeof_int32",       sizeof_int32,       0);
    rb_define_module_function(mSizes, "sizeof_int64",       sizeof_int64,       0);
    rb_define_module_function(mSizes, "sizeof_uint8",       sizeof_uint8,       0);
    rb_define_module_function(mSizes, "sizeof_uint16",      sizeof_uint16,      0);
    rb_define_module_function(mSizes, "sizeof_uint32",      sizeof_uint32,      0);
    rb_define_module_function(mSizes, "sizeof_uint64",      sizeof_uint64,      0);

    rb_define_module_function(mSizes, "sizeof_int_least8",  sizeof_int_least8,  0);
    rb_define_module_function(mSizes, "sizeof_int_least16", sizeof_int_least16, 0);
    rb_define_module_function(mSizes, "sizeof_int_least32", sizeof_int_least32, 0);
    rb_define_module_function(mSizes, "sizeof_int_least64", sizeof_int_least64, 0);
    rb_define_module_function(mSizes, "sizeof_uint_least8", sizeof_uint_least8, 0);
    rb_define_module_function(mSizes, "sizeof_uint_least16",sizeof_uint_least16,0);
    rb_define_module_function(mSizes, "sizeof_uint_least32",sizeof_uint_least32,0);
    rb_define_module_function(mSizes, "sizeof_uint_least64",sizeof_uint_least64,0);

    rb_define_module_function(mSizes, "sizeof_int_fast8",   sizeof_int_fast8,   0);
    rb_define_module_function(mSizes, "sizeof_int_fast16",  sizeof_int_fast16,  0);
    rb_define_module_function(mSizes, "sizeof_int_fast32",  sizeof_int_fast32,  0);
    rb_define_module_function(mSizes, "sizeof_int_fast64",  sizeof_int_fast64,  0);
    rb_define_module_function(mSizes, "sizeof_uint_fast8",  sizeof_uint_fast8,  0);
    rb_define_module_function(mSizes, "sizeof_uint_fast16", sizeof_uint_fast16, 0);
    rb_define_module_function(mSizes, "sizeof_uint_fast32", sizeof_uint_fast32, 0);
    rb_define_module_function(mSizes, "sizeof_uint_fast64", sizeof_uint_fast64, 0);

    rb_define_module_function(mSizes, "sizeof_intptr",      sizeof_intptr,      0);
    rb_define_module_function(mSizes, "sizeof_uintptr",     sizeof_uintptr,     0);
    rb_define_module_function(mSizes, "sizeof_intmax",      sizeof_intmax,      0);
    rb_define_module_function(mSizes, "sizeof_uintmax",     sizeof_uintmax,     0);
  #endif
}
