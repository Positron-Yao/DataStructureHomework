add_rules("mode.debug", "mode.release")

target("c11_Graph")
    set_kind("binary")
    add_files("src/*.cpp")
    add_includedirs("include")

