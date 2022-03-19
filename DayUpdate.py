import datetime, os
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

def UpdateCalendar(path, doc_path, _month: int | None, _day: str | None):
  if not _month:
    _month = Yesterday().month
  if not _day:
    _day = Yesterday().strftime("%d")
  with open(path, "r+", encoding='utf-8') as f:
    lines = f.readlines()
    line = 0
    while lines[line][0 : 2] != "##" or int(lines[line][3 : 5]) != _month:
      line += 1
    while lines[line].find(_day) == -1:
      line += 1
    index = lines[line].find(_day)
    index = (lines[line].rfind("|", None, index), lines[line].find("|", index))
    lines[line] = lines[line][: index[0] + 1] + f'[{_day}]({doc_path})' + lines[line][index[1] :]
    
    f.seek(0)
    f.writelines(lines)



if __name__ == "__main__":
  tm = datetime.date.today().strftime("%Y-%m-%d")
  _t = ReadTimeFromFile('Doc\\DayTODO.md')
  if _t == tm:
    exit(0)
  
  ToastNotifier().show_toast(title = "每日更新",
    msg = "今天是 " + tm + "，继续加油！",
    threaded = True, duration = 2)

  calendar_path = 'History\\2022\\2022-Calendar.md'

  for src, dst in [
      ("Doc\\DayTODO.md", "History\\" + _t.replace("-", "\\") + ".md")]:
    if os.path.exists(src):
      UpdateCalendar(calendar_path, dst[-len("xx\\xx.md"):], int(_t[5 : 7]), _t[8 :])
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
  
  os.system('git add ' + calendar_path)
  
  exit(1)
