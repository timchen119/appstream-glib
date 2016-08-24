asb_plugins_cargs = ['-DG_LOG_DOMAIN="Asb"']

asb_plugins = [
  ['gettext',      'asb-plugin-gettext.c',      []],
  ['hardcoded',    'asb-plugin-hardcoded.c',    []],
  ['desktop',      'asb-plugin-desktop.c',      []],
  ['appdata',      'asb-plugin-appdata.c',      []],
  ['font',         'asb-plugin-font.c',         [gdk, freetype, fontconfig]],
]

foreach i : asb_plugins
  shared_library('libasb_plugin_@0@'.format(i.get(0)),
    sources : i.get(1),
    include_directories: [
      top_build_incdir,
      asbuilder_incdir,
      asglib_incdir,
    ],
    dependencies : [
      glib, gdkpixbuf, soup,
      i.get(2),
    ],
    link_with : asbuilder,
    c_args : asb_plugins_cargs
  )
endforeach
