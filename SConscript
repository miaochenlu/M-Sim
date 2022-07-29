import os
Import('env')
env = env.Clone()

cpps = Glob("*.cpp")

env['simulator_libs'] = ['systemc']

env.Program("simulator", source=cpps, LIBS=env['simulator_libs'])