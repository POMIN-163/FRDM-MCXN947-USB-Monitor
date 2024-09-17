import os
import sys
import rtconfig
import scons_compiledb

if os.getenv('RTT_ROOT'):
    RTT_ROOT = os.getenv('RTT_ROOT')
else:
    RTT_ROOT = os.path.normpath(os.getcwd() + '/../../../../..')

sys.path = sys.path + [os.path.join(RTT_ROOT, 'tools')]
try:
    from building import *
except:
    print('Cannot found RT-Thread root directory, please check RTT_ROOT')
    print(RTT_ROOT)
    exit(-1)

TARGET = 'rtthread.' + rtconfig.TARGET_EXT

if rtconfig.PLATFORM == 'armcc':
    env = Environment(tools = ['mingw'],
        AS = rtconfig.AS, ASFLAGS = rtconfig.AFLAGS,
        CC = rtconfig.CC, CFLAGS = rtconfig.CFLAGS,
        CXX = rtconfig.CXX, CXXFLAGS = rtconfig.CXXFLAGS,
        AR = rtconfig.AR, ARFLAGS = '-rc',
        LINK = rtconfig.LINK, LINKFLAGS = rtconfig.LFLAGS,
        # overwrite cflags, because cflags has '--C99'
        CXXCOM = '$CXX -o $TARGET --cpp -c $CXXFLAGS $_CCCOMCOM $SOURCES')
else:
    env = Environment(tools = ['mingw'],
        AS = rtconfig.AS, ASFLAGS = rtconfig.AFLAGS,
        CC = rtconfig.CC, CFLAGS = rtconfig.CFLAGS,
        CXX = rtconfig.CXX, CXXFLAGS = rtconfig.CXXFLAGS,
        AR = rtconfig.AR, ARFLAGS = '-rc',
        LINK = rtconfig.LINK, LINKFLAGS = rtconfig.LFLAGS,
        CXXCOM = '$CXX -o $TARGET -c $CXXFLAGS $_CCCOMCOM $SOURCES')

env.PrependENVPath('PATH', rtconfig.EXEC_PATH)
scons_compiledb.enable(env)
env.CompileDb()

if rtconfig.PLATFORM in ['iccarm']:
    env.Replace(CCCOM = ['$CC $CFLAGS $CPPFLAGS $_CPPDEFFLAGS $_CPPINCFLAGS -o $TARGET $SOURCES'])
    env.Replace(ARFLAGS = [''])
    env.Replace(LINKCOM = env["LINKCOM"] + ' --map rtthread.map')

Export('RTT_ROOT')
Export('rtconfig')

SDK_ROOT = os.path.abspath('./')

if os.path.exists(SDK_ROOT + '/Libraries'):
    libraries_path_prefix = SDK_ROOT + '/Libraries'
else:
    libraries_path_prefix = os.path.dirname(SDK_ROOT) + '/Libraries'

SDK_LIB = libraries_path_prefix
Export('SDK_LIB')

# prepare building environment
objs = PrepareBuilding(env, RTT_ROOT, has_libcpu=False)

objs.extend(SConscript(os.path.join(libraries_path_prefix, 'drivers', 'SConscript')))

# include cmsis
objs.extend(SConscript(os.path.join(libraries_path_prefix, rtconfig.BSP_LIBRARY_TYPE, 'SConscript')))

# make a building
DoBuilding(TARGET, objs)
