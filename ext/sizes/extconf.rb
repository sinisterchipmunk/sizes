require 'mkmf'

have_header("stddef.h")
have_header("stdlib.h")
have_header("stdint.h")

create_makefile("sizes")
