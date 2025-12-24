import shutil, sys, os
try:
    if os.path.isdir(sys.argv[1]):
        shutil.copytree(sys.argv[1], sys.argv[2], dirs_exist_ok=True)
    else:
        shutil.copy2(sys.argv[1], sys.argv[2])
except shutil.SameFileError:
    pass