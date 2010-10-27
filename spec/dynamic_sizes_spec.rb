require File.expand_path(File.dirname(__FILE__) + '/spec_helper')

# These tests iterate through all known types (see Sizes#STRING_COPIES) and compile a small C program
# for each; the C program prints out the size of the type for this machine, and the test passes
# if the sizes match.

describe "Sizes" do
  # inline hashes the method names so that they aren't double-compiled -- but this sucks if
  # we want to reuse the same method name, so instead we'll tack a global counter onto
  # the end of the method name to ensure they're all unique.
  $inline_counter = 0
  
  begin
    require "inline"
    include Sizes
    
    def real_sizeof(type_name)
      sizeof_test = Class.new do
        inline :C do |builder|
          builder.include "<stdint.h>"
          builder.c <<-end_c_code
            int size#{$inline_counter += 1}()
            {
              int size = sizeof(#{type_name});
              return size;
            }
          end_c_code
        end
      end
      
      sizeof_test.new.send(:"size#{$inline_counter}")
    end
    
    (Sizes::STRING_COPIES.keys - Sizes::C99_TYPES).each do |type_name|
      it "should generate correct size for :#{type_name}" do
        sizeof(type_name).should == real_sizeof(type_name.gsub(/_/, ' '))
      end
    end
    
    Sizes::C99_TYPES.each do |type_name|
      it "should generate correct size for C99 type :#{type_name}" do
        sizeof(type_name).should == real_sizeof("#{type_name}_t")
      end
    end
  rescue LoadError
    it "doesn't have RubyInline" do
      fail "Can't run dynamic test suite without the RubyInline gem"
    end
  end
end
