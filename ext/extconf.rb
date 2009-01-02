
require 'mkmf'

$CFLAGS << " -O3"
if ENV['DEBUG']
  puts "setting debug flags"
  $CFLAGS << " -ggdb -DHAVE_DEBUG"
end

create_makefile 'rbfnv'
