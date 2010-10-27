require File.join(File.dirname(__FILE__), "../ext/sizes/sizes")

module Sizes
  module_function
  
  STRING_COPIES = %w(char unsigned_char signed_char signed_int int signed_short_int signed_long_int
                     long_int long unsigned_int unsigned unsigned_short_int unsigned_short unsigned_long_int
                     unsigned_long float double long_double
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
      when :char
        sizeof_char
      when :unsigned_char
        sizeof_unsigned_char
      when :signed_char
        sizeof_signed_char
      when :signed_int, :int
        sizeof_signed_int
      when :signed_short_int, :short_int, :short
        sizeof_signed_short_int
      when :signed_long_int, :long_int, :long
        sizeof_long_int
      when :unsigned_int, :unsigned
        sizeof_unsigned_int
      when :unsigned_short_int, :unsigned_short
        sizeof_unsigned_short_int
      when :unsigned_long_int, :unsigned_long
        sizeof_unsigned_long_int
      when :float
        sizeof_float
      when :double
        sizeof_double
      when :long_double
        sizeof_long_double
      else
        raise ArgumentError, "Argument must be one of #{STRING_COPIES.values.inspect}, or a String version of the same"
    end
  end
end