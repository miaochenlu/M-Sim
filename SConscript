import os
Import('env')
env = env.Clone()

cpps = Glob("*.cpp")

for subdir in ['insn']:
    cpp_in_dir = SConscript('./%s/SConscript' % subdir, exports='env')
    cpps += cpp_in_dir

env.Program("simulator", source=cpps + ['main.cc'])