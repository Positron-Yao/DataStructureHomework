add_rules("mode.debug", "mode.release")

includes("~/.xmake")
includes("../libs")

target("c7")
    set_kind("binary")
    add_files("src/main.cpp")
    add_deps("dsh")
    add_links("dsh")

    before_run(function ()
        import("core.project.task")
        task.run("sentr", {}, "基本操作")
    end)

target("t1")
    set_kind("binary")
    add_files("src/t1.cpp")
    add_deps("dsh")
    add_links("dsh")

    before_run(function ()
        import("core.project.task")
        task.run("sentr", {}, "Reverse")
    end)

target("t2")
    set_kind("binary")
    add_files("src/t2.cpp")
    add_deps("dsh")
    add_links("dsh")

    before_run(function ()
        import("core.project.task")
        task.run("sentr", {}, "Count SubStr")
    end)

