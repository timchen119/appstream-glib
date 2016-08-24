as_util_cargs = ['-DG_LOG_DOMAIN="As"']

if get_option('enable-builder')
  appstream_builder = executable(
    'appstream-builder',
    sources : 'as-builder.c',
    include_directories : [
      include_directories('..'),
      asglib_incdir,
      asbuilder_incdir,
    ],
    dependencies : [
      glib,
      gdkpixbuf,
      soup,
      libarchive
    ],
    link_with : [
      asglib,
      asbuilder
    ],
    c_args : as_util_cargs
  )
endif

appstream_util = executable(
  'appstream-util',
  sources : 'as-util.c',
  include_directories : [
    include_directories('@0@/..'.format(meson.current_build_dir())),
    asglib_incdir,
  ],
  dependencies : [
    glib,
    gdkpixbuf,
    soup,
    libarchive
  ],
  link_with : asglib,
  c_args : as_util_cargs
)
