import os
env = Environment()
env['project_root'] = os.getcwd()
print(env['project_root'] )
env['project_name'] = 'msim'

env.Append(CPPPATH=['/usr/include', './insn/', '.'])
env.Append(LIBPATH=['./usr/lib/'])

env.SConscript(
    dirs = '.',
    exports = 'env',
    variant_dir = 'build',
    duplicate = 1
)