require File.expand_path(File.dirname(__FILE__) + '/spec_helper')

# These tests describe correct values for my machine. YMMV.
# To check correct values for your machine, compile and run spec/support/dump_sizes.cpp.

describe "Sizes" do
  include Sizes
  
  it "should work as a module function" do
    Sizes.sizeof(:char).should == 1
  end

  context "should report correct size:" do
    it "char" do
      sizeof(:char).should == 1
    end

    it "unsigned char" do
      sizeof(:unsigned_char).should == 1
    end

    it "signed char" do
      sizeof(:signed_char).should == 1
    end

    it "signed int" do
      sizeof(:signed_int).should == 4
    end

    it "int" do
      sizeof(:int).should == 4
    end

    it "signed short int" do
      sizeof(:signed_short_int).should == 2
    end

    it "signed long int" do
      sizeof(:signed_long_int).should == 8
    end

    it "long int" do
      sizeof(:long_int).should == 8
    end

    it "long" do
      sizeof(:long).should == 8
    end

    it "unsigned int" do
      sizeof(:unsigned_int).should == 4
    end

    it "unsigned" do
      sizeof(:unsigned).should == 4
    end

    it "unsigned short int" do
      sizeof(:unsigned_short_int).should == 2
    end

    it "unsigned short" do
      sizeof(:unsigned_short).should == 2
    end

    it "unsigned long int" do
      sizeof(:unsigned_long_int).should == 8
    end

    it "unsigned long" do
      sizeof(:unsigned_long).should == 8
    end

    it "float" do
      sizeof(:float).should == 4
    end

    it "double" do
      sizeof(:double).should == 8
    end

    it "long double" do
      sizeof(:long_double).should == 16
    end
  end
end
