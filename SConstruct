import os
env = Environment()
env['project_root'] = os.getcwd()
env['project_name'] = 'simulator'
env['install_root'] = './_external/'
env['install_prefix'] = '/usr/local'
env['depend_prefix'] = ["./_external/usr/local", "./_external/usr"]

env.Append(CPPPATH=[env['depend_prefix'][0]+'/include/server_proto', '/usr/local/systemc-2.3.3/include', '/usr/include'])
env.Append(LIBPATH=[env['depend_prefix'][0]+'/lib64', './usr/lib/', '/usr/local/systemc-2.3.3/lib-linux64/'])
env.Alias('install', './_external/')

env.SConscript(
    dirs = '.',
    exports = 'env',
    variant_dir = 'build',
    duplicate = 1
)