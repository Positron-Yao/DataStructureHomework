add_rules("mode.debug", "mode.release")

target("c10_Tree2")
    set_kind("binary")
    add_files("src/*.cpp")
    add_includedirs("include")

