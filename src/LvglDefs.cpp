#include "LvglDefs.h"
#include <stdio.h>

#define DEAULT_PATH_PREFIX "spiffs"
/**
 * @brief 将用户提供的路径映射为 lvgl 中所选择文件系统中可访问的路径
 *
 * @param inPath: 待映射的路径
 * @param outPath: 映射后的路径，需要比输入路径长 10 个字符，存放可能增加的前缀。可以和 inPath 是同一块区域
 * 
 * @return 映射后的路径
 */
char *mapFsPath(char *inPath, char *outPath){
  int len = strlen(inPath) + strlen(DEAULT_PATH_PREFIX) + 4;
  char *fsPath = (char *)malloc(len);
  for(int i = strlen(inPath); i < len; i++){
    fsPath[i] = 0;
  }
  //Is it in sdcard?
  char *start = strstr(inPath, "sdcard");
  char fs_prefix =
#if LV_USE_FS_STDIO
    LV_FS_STDIO_LETTER;
#elif LV_USE_FS_POSIX
    LV_FS_POSIX_LETTER;
#elif LV_USE_FS_WIN32
    LV_FS_WIN32_LETTER;
#elif LV_USE_FS_FATFS
    LV_FS_FATFS_LETTER;
#endif

  if(!start){
    //No, then append the default path
    bool relativePath = inPath[0] != '/';
    sprintf(fsPath, "%c:%s%s%s%s", fs_prefix, relativePath?"":"/", 
      DEAULT_PATH_PREFIX, relativePath?"/":"", inPath);
  } else {
    //Otherwise just insert the filesystem letter
    sprintf(fsPath, "%c:%s", fs_prefix, inPath);
  }
  memcpy(outPath, fsPath, strlen(fsPath) + 1);
  free(fsPath);
  return outPath;
}