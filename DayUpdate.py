import os
import datetime
from win10toast import ToastNotifier

def Yesterday():
  return datetime.date.today() - datetime.timedelta(days = 1)
def MoveFile(src, dst):
  if not os.path.exists(os.path.dirname(dst)):
    os.makedirs(os.path.dirname(dst))
  elif os.path.exists(dst):
    MoveFile(dst, os.path.dirname(dst) + "bak." + os.path.basename(dst))
  os.rename(src, dst)
def ReadTimeFromFile(path):
  with open(path, "r", encoding='utf-8') as f:
    return f.readline()[4 : -3]

if __name__ == "__main__":
  tm = datetime.date.today().strftime("%Y-%m-%d")
  _t = ReadTimeFromFile('Doc\\DayTODO.md')
  if _t == tm:
    exit(0)
  
  ToastNotifier().show_toast(title = "每日更新",
    msg = "今天是 " + tm + "，继续加油！",
    threaded = True, duration = 2)

  for src, dst in [
      ("Doc\\DayTODO.md", "History\\" + _t.replace("-", "\\") + ".md")]:
    if os.path.exists(src):
      MoveFile(src, dst)
      os.system("git add " + dst)

  for src, dst in [
      ("Resources\\day_todo.md", "Doc\\DayTODO.md")]:
    os.system(f"copy /Y {src} {dst}")
    with open(dst, 'r+', encoding="utf-8") as f:
      content = f.read()
      f.seek(0, 0)
      f.write(content.replace("$__time__", tm))
    os.system("git add " + dst)
  
  exit(1)
