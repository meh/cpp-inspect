inspect - ruby ruby ruby
========================
This small header gives you the superpower of inspecting any kind of value in
C++11, providing output similar to Ruby's `#inspect`.

If you define `std::string inspect (void)` as method in your class, it will use
the whole output when inspecting.

If you define `std::string to_string (void)` as method in your class, it will use
it's output in this manner `#<*type*: *output*>`.

If you define `std::ostream& operator << (std::ostream& on, *type* value)` for your
class, it will act as it were a `to_string` method.

The available functions are `inspect::value` and `inspect::type`, you can guess
what they do by their name, can't you?

test.cpp output
---------------
```
"34"
#<foo:0x7fff076d3e20>
#<bar: dabbah>
#<wat: I like trains>
23
#<enum derp: omg>
[[1, 2], [3, 4]]
(float*) 0x156
"lol"
true
```

Type name demangling
--------------------
By default it demangles type names using the `cxxabi.h` header, it's not
available everywhere, so if you don't have it or don't want it make sure to
define `NO_DEMANGLE`, the type names will be worse, but well, such is life.

On MSVC it uses `dbghelp.lib` and `Dbghelp.h`.

License
-------
This header is released under WTFPL, so yeah, do whatever you want with it.
