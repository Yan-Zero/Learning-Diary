import os

if __name__ == "__main__":
  # change the working directory
  root = os.path.join(os.path.dirname(__file__), "Tools")
  os.chdir(root)
  for dir in os.listdir(root):
    build = os.path.join(root, dir, "build")
    if not os.path.exists(build):
      continue
    os.system('cd {} && cmake -G "MinGW Makefiles" ../ && mingw32-make'.format(build))
    if os.path.exists(os.path.join(build, "Release", dir + ".exe")):
      os.system('cd {} && copy /Y "Release/{}.exe" "../../{}.exe"'.format(build, dir))
    else:
      os.system('cd {} && copy /Y "*.exe" "../../{}.exe"'.format(build, dir))

