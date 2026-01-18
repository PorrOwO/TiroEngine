project('tiro', 'c',
  version : '0.1',
  default_options : ['warning_level=3', 'c_std=c11'])

cc = meson.get_compiler('c')

# libm dependency
m_dep = cc.find_library('m', required: false)
# Find external dependencies
glfw_dep = dependency('glfw3')
gl_dep = dependency('gl')

inc = include_directories('src')

# Define sources
sources = files(
  'src/main.c',
  'src/shader/shader.c',
  'src/common/files.c',
)

# Create the executable
executable('tiro',
  sources,
  include_directories: inc,
  dependencies : [glfw_dep, gl_dep, m_dep],
  install : true)
