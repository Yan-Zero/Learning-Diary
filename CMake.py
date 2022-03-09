import os

if __name__ == "__main__":
  # change the working directory
  root = os.path.join(os.path.dirname(__file__), "Tools")
  os.chdir(root)
  for dir in os.listdir(root):
    build = os.path.join(root, dir, "build")
    if not os.path.exists(build):
      continue
    os.system(f'cd {build} && cmake -G "MinGW Makefiles" ../ && mingw32-make')
    if os.path.exists(os.path.join(build, "Release", dir + ".exe")):
      os.system(f'cd {build} && copy /Y "Release/{dir}.exe" "../../{dir}.exe"')
    else:
      os.system(f'cd {build} && copy /Y "*.exe" "../../{dir}.exe"')

