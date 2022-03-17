#include "path.h"

using namespace std;

#ifdef _WIN32
#include <io.h>

void getFiles(const string &path, vector<string>& files )  
{  
    //文件句柄  
    //long hFile = 0;  //win7
    intptr_t hFile = 0;   //win10
    //文件信息  
    struct _finddata_t fileinfo;  
    string p;  
    if((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) !=  -1)  
    // "\\*"是指读取文件夹下的所有类型的文件，若想读取特定类型的文件，以png为例，则用“\\*.png”
    {  
        do  
        {  
            //如果是目录,迭代之  
            //如果不是,加入列表  
            if((fileinfo.attrib &  _A_SUBDIR))  
            {  
                if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)  
                    getFiles( p.assign(path).append("\\").append(fileinfo.name), files );  
            }  
            else  
            {  
                files.push_back(path + "\\" + fileinfo.name);  
            }  
        }while(_findnext(hFile, &fileinfo)  == 0);  
        _findclose(hFile);  
    }  
}

#endif

std::string joinPath(const std::string &path1, const std::string &path2)
{
  if (path1[path1.length() - 1] == '/')
    return path1 + path2;
  else
    return path1 + "/" + path2;
};