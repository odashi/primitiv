# This script generates HEX formatted char array from input file.
#
# Usage:
#   cmake -P generate_char_array.cmake <output file> <input file 1> <input file 2> ...
#
# Example of input file:
#   This is a test\n
#
# Example of output file:
#   0x54, 0x68, 0x69, 0x73, 0x20, 0x69, 0x73, 0x20, 0x61, 0x20, 0x74, 0x65, 0x73, 0x74, 0x0a,
#
file(WRITE ${CMAKE_ARGV3} "/* Generated by generate_char_array.cmake */\n")
MATH(EXPR itermax "${CMAKE_ARGC}-1")
foreach(i RANGE 3 ${itermax})
  file(READ ${CMAKE_ARGV${i}} hex_data HEX)
  string(REGEX REPLACE "([0-9a-f][0-9a-f])" "0x\\1, " hex_split ${hex_data})
  file(APPEND ${CMAKE_ARGV3} ${hex_split})
endforeach(i)
