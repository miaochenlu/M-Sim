import os
Import('env')
env = env.Clone()

cpps = Glob("*.cpp")

env['simulator_libs'] = ['systemc']
env.Program("simulator", source=cpps + ['main.cc'], LIBS=env['simulator_libs'])

for subdir in ['tb']:
    cpp_in_dir = SConscript('./%s/SConscript' % subdir, exports='env')
    cpps += cpp_in_dir

env.Program("reg_test", source=cpps + ['reg_test.cc'], LIBS=env['simulator_libs'])