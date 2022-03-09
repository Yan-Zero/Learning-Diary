
_time = "2022-03-09"

import os
import time
from win10toast import ToastNotifier

if __name__ == "__main__":
  if _time == time.strftime("%Y-%m-%d", time.localtime()):
    exit(0)
  
  print("Day Update")
  toaster = ToastNotifier()
  toaster.show_toast(title = "每日更新",
    msg = "今天是 " + time.strftime("%Y-%m-%d", time.localtime()) + "，继续加油！",
    threaded = True, duration = 2)

  with open(r"DayUpdate.py", "r+", encoding="utf-8") as f:
    content = f.read()
    f.seek(0, 0)
    f.write(content.replace(_time, time.strftime("%Y-%m-%d", time.localtime())))

  _time = time.strftime("%Y-%m-%d", time.localtime())

  # move the file
  mv_list = [
    ("Doc\\DayTODO.md", f"History\\TODO\\{_time}.md"),
  ]
  for src, dst in mv_list:
    if os.path.exists(src):
      os.system("git mv " + src + " " + dst)

  recreat = [
    ("Libs\\day_todo.md", "Doc\\DayTODO.md"),
  ]
  for src, dst in recreat:
    os.system(f"copy /Y {src} {dst}")
    with open(dst, 'r+', encoding="utf-8") as f:
      content = f.read()
      f.seek(0, 0)
      f.write(content.replace("$__time__", _time))
  
  exit(1)