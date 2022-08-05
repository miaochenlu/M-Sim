import os
env = Environment()
env['project_root'] = os.getcwd()
env['project_name'] = 'simulator'

env.Append(CPPPATH=['/usr/local/systemc-2.3.3/include', '/usr/include', './tb/', '.'])
env.Append(LIBPATH=['./usr/lib/', '/usr/local/systemc-2.3.3/lib-linux64/'])

env.SConscript(
    dirs = '.',
    exports = 'env',
    variant_dir = 'build',
    duplicate = 1
)