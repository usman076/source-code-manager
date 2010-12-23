#ifndef _FILE_LIST_H
#define _FILE_LIST_H
#include "strings.h"
#include "sha.h"
struct _file;
typedef struct _file *File;
typedef struct _file  FileData;

struct _file
{
	String filename;
	uint32_t mode, mtime, size;
	ShaBuffer sha;
};


File File_Create(void);
void File_Delete(File f);
bool File_SetFileData(File f, const char *filename, const bool computeSha);

/*Converts the file data into machine independent form
 * and places the output in buffer.
 * Return the size of data written into buffer */
int File_Serialize(File f, char * const buffer, const int bufferSize);
bool File_DeSerialize(File f, const char *data, const int dataSize);

/*Public API's for FileList*/
struct _filelist;
typedef struct _filelist *FileList;

FileList FileList_Create(void);
void FileList_Delete(FileList f);

File* FileList_GetListDetails(const FileList f, uint32_t * const listLength);
bool FileList_InsertFileToSortedList(FileList f, const char* filename, const bool computeSha);
bool FileList_MergeSortedList(FileList masterList, const FileList newList);
bool FileList_GetDirectoryConents(FileList f, const char *path);
void FileList_PrintList(const FileList f);
#endif
