inspect - ruby ruby ruby
========================
This small header gives you the superpower of inspecting any kind of value in
C++11, providing output similar to Ruby's `#inspect`.

If you define `std::string inspect (void)` as method in your class, it will use
the whole output when inspecting.

If you define `std::string to_string (void)` as method in your class, it will use
its output in this manner `#<*type*: *output*>`.

If you define `std::ostream& operator << (std::ostream& on, *type* value)` for your
class, it will act as it were a `to_string` method.

The available functions are `inspect::value` and `inspect::type`, you can guess
what they do by their name, can't you?

test.cpp output
---------------
```
"34"
#<foo:0x7ffff5e038c0>
#<bar: dabbah>
#<wat: I like trains>
#<union omg:0x7ffff5e03890>
23
#<enum derp: omg>
1.04719755
[[1, 2], [3, 4]]
(float*) 0x156
"\tlol\n\x01\"\xc3\x9f"
"\tlol\n\u0001\"\u00df"
true
#<function void(int): main::$_0>
#<function void(float): 0x4023d0>
#<function std::string(): @bar>
#<function void(): #<main::$_1: 1>>
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
