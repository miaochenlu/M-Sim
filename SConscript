import os
Import('env')
env = env.Clone()

cpps = Glob("*.cpp")


for subdir in ['tb']:
    cpp_in_dir = SConscript('./%s/SConscript' % subdir, exports='env')
    cpps += cpp_in_dir

env['simulator_libs'] = ['systemc']
env.Program("simulator", source=cpps + ['main.cc'], LIBS=env['simulator_libs'])
env.Program("reg_file_test", source=cpps + ['reg_file_test.cc'], LIBS=env['simulator_libs'])
env.Program("reg_pc_test",   source=cpps + ['reg_pc_test.cc'],   LIBS=env['simulator_libs'])
# env.Program("decode",   source=cpps + ['insn_decode.cc'],   LIBS=env['simulator_libs'])