require File.join(File.dirname(__FILE__), "../ext/sizes/sizes")

module Sizes
  module_function
  C99_TYPES = %w(int8 int16 int32 int64 uint8 uint16 uint32 uint64 int_least8 int_least16 int_least32
                 int_least64 uint_least8 uint_least16 uint_least32 uint_least64 int_fast8 int_fast16 int_fast32
                 int_fast64 uint_fast8 uint_fast16 uint_fast32 uint_fast64 intptr uintptr intmax uintmax size
                 wchar)
  
  STRING_COPIES = (
                    %w(char unsigned_char signed_char signed_int int signed_short_int signed_long_int
                       long_int long unsigned_int unsigned unsigned_short_int unsigned_short unsigned_long_int
                       unsigned_long float double long_double) + C99_TYPES
                  ).inject({}) { |hash,key| hash[key] = key.to_sym; hash }.freeze
    
  def sizeof(symbol_or_string)
    # I could just use send("sizeof_#{symbol_or_string}") but that would be slower, and negate any advantage of using
    # symbols. Not sure how much the speed difference really matters, but it couldn't hurt, right?
    
    case symbol_or_string
      when String
        if sym = STRING_COPIES[symbol_or_string]
          sizeof(sym)
        else
          raise ArgumentError, "Argument must be one of #{STRING_COPIES.values.inspect}, or a String version of the same"
        end
      when :char                                 then sizeof_char
      when :unsigned_char                        then sizeof_unsigned_char
      when :signed_char                          then sizeof_signed_char
      when :signed_int, :int                     then sizeof_signed_int
      when :signed_short_int, :short_int, :short then sizeof_signed_short_int
      when :signed_long_int, :long_int, :long    then sizeof_long_int
      when :unsigned_int, :unsigned              then sizeof_unsigned_int
      when :unsigned_short_int, :unsigned_short  then sizeof_unsigned_short_int
      when :unsigned_long_int, :unsigned_long    then sizeof_unsigned_long_int
      when :float                                then sizeof_float
      when :double                               then sizeof_double
      when :long_double                          then sizeof_long_double
      when :int8                                 then sizeof_int8
      when :int16                                then sizeof_int16
      when :int32                                then sizeof_int32
      when :int64                                then sizeof_int64
      when :uint8                                then sizeof_uint8
      when :uint16                               then sizeof_uint16
      when :uint32                               then sizeof_uint32
      when :uint64                               then sizeof_uint64
      when :int_least8                           then sizeof_int_least8
      when :int_least16                          then sizeof_int_least16
      when :int_least32                          then sizeof_int_least32
      when :int_least64                          then sizeof_int_least64
      when :uint_least8                          then sizeof_uint_least8
      when :uint_least16                         then sizeof_uint_least16
      when :uint_least32                         then sizeof_uint_least32
      when :uint_least64                         then sizeof_uint_least64
      when :int_fast8                            then sizeof_int_fast8
      when :int_fast16                           then sizeof_int_fast16
      when :int_fast32                           then sizeof_int_fast32
      when :int_fast64                           then sizeof_int_fast64
      when :uint_fast8                           then sizeof_uint_fast8
      when :uint_fast16                          then sizeof_uint_fast16
      when :uint_fast32                          then sizeof_uint_fast32
      when :uint_fast64                          then sizeof_uint_fast64
      when :intptr                               then sizeof_intptr
      when :uintptr                              then sizeof_uintptr
      when :intmax                               then sizeof_intmax
      when :uintmax                              then sizeof_uintmax
      when :size_t, :size                        then sizeof_size
      when :wchar_t, :wchar                      then sizeof_wchar
      else
        raise ArgumentError, "Argument must be one of #{STRING_COPIES.values.inspect}, or a String version of the same"
    end
  end
end