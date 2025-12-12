add_rules("mode.debug", "mode.release")

target("c12")
    set_kind("binary")
    add_files("src/*.cpp")
    add_includedirs("include")

