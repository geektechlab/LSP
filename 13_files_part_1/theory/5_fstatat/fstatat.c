#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	struct stat sb;
	int fd;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (fstatat(AT_FDCWD, argv[1], &sb, 0) == -1) {
	//if (fstatat(AT_FDCWD, argv[1], &sb, AT_SYMLINK_NOFOLLOW) == -1) {
		perror("stat error");
		exit(EXIT_FAILURE);
	}

	printf("File Type:                  ");
	switch (sb.st_mode & S_IFMT) {
		case S_IFBLK:
			printf("block device\n");
			break;
		case S_IFCHR:
			printf("character device\n");
			break;
		case S_IFDIR:
			printf("directory\n");
			break;
		case S_IFIFO:
			printf("FIFO/pipe\n");
			break;
		case S_IFLNK:
			printf("symbolic link\n");
			break;
		case S_IFREG:
			printf("regular file\n");
			break;
		case S_IFSOCK:
			printf("socket\n");
			break;
		default:
			printf("unknown\n");
			break;
	}

	printf("I-node number:              %ld\n", (long)sb.st_ino);
	printf("Mode:                       %lo (octal)\n", 
			(unsigned long)sb.st_mode);
	printf("link count:                 %ld\n", (long)sb.st_nlink);
	printf("Ownership:                  UID=%ld    GID=%ld\n",
			(long)sb.st_uid, (long)sb.st_gid);
	printf("Preferred I/O block size:   %ld bytes\n", 
			(long)sb.st_blksize);
	printf("File size:                  %lld\n", (long long)sb.st_size);
	printf("Blocks allocated:           %lld\n", (long long)sb.st_blocks);

	/* 这里不需要加 '\n', ctime()返回的字符串中好像包含了 '\n' */
	printf("Last status change:         %s", ctime(&sb.st_ctime));
	printf("Last file access:           %s", ctime(&sb.st_atime));
	printf("Last modification:          %s", ctime(&sb.st_mtime));

	exit(EXIT_SUCCESS);
}
