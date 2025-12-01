add_rules("mode.debug", "mode.release")

includes("~/.xmake/")
includes("../libs/")

target("main")
    set_kind("binary")
    add_files("src/*.cpp")
    add_deps("dsh")
    add_links("dsh")


