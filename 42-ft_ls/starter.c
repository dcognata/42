#include "ft_ls.h"

int					main(int argc, char *argv[])
{
    struct stat		*buf;
	struct passwd	*pw;
	struct group	*gp;
	char			*part_name;

	if ((buf = (struct stat *)malloc(sizeof(struct stat))) != NULL)
    {
		if ((stat(argv[1], buf)) != -1) {
    		int len = ft_count_words(argv[1], '/');
 			part_name = (len > 0) ? ft_strsplit(argv[1], '/')[len - 1] : argv[1];
			pw = getpwuid(buf->st_uid);
			gp = getgrgid(buf->st_gid);

			ft_printf("Nom: %s\n", part_name);

			ft_printf("Type: ");
			if (S_ISREG(buf->st_mode))
		    	ft_printf("Fichier\n");
			if (S_ISDIR(buf->st_mode))
		    	ft_printf("Répertoire\n");
			if (S_ISLNK(buf->st_mode))
		    	ft_printf("Lien symbolique\n");

			ft_printf("Modes: ");
		    ft_printf( (S_ISDIR(buf->st_mode)) ? "d" : "-");
		    ft_printf( (buf->st_mode & S_IRUSR) ? "r" : "-");
		    ft_printf( (buf->st_mode & S_IWUSR) ? "w" : "-");
		    ft_printf( (buf->st_mode & S_IXUSR) ? "x" : "-");
		    ft_printf( (buf->st_mode & S_IRGRP) ? "r" : "-");
		    ft_printf( (buf->st_mode & S_IWGRP) ? "w" : "-");
		    ft_printf( (buf->st_mode & S_IXGRP) ? "x" : "-");
		    ft_printf( (buf->st_mode & S_IROTH) ? "r" : "-");
		    ft_printf( (buf->st_mode & S_IWOTH) ? "w" : "-");
		    ft_printf( (buf->st_mode & S_IXOTH) ? "x\n" : "-\n");

			ft_printf("Nombre de liens: %d\n", buf->st_nlink);
			ft_printf("Proprietaire: %s\n", pw->pw_name);
			ft_printf("Groupe: %s\n", gp->gr_name);
			ft_printf("Taille: %o octets\n", buf->st_size);
			ft_printf("Date de derniere modification: %s %s %s\n", ft_strsub(ctime(&buf->st_ctime), 4, 3), ft_strsub(ctime(&buf->st_ctime), 8, 2), ft_strsub(ctime(&buf->st_ctime), 11, 5));
		} else {
			ft_printf("FAIL\n");    	
		}
    }

	return (0);
}

int					main(int argc, char *argv[])
{
    struct dirent	*pDirent;
    DIR				*pDir;

	if (argc > 1)
		ft_printf("argc: %d\nname: %s\n", argc, argv[0]);
	else
	{
		if ((pDir = opendir(".")) != NULL)
		{
	        while ((pDirent = readdir(pDir)) != NULL)
	        {
	        	if (pDirent->d_type == DT_DIR)
		            ft_printf("Dir: %s\n", pDirent->d_name);
	        	else if (pDirent->d_type == DT_REG)
		            ft_printf("File: %s\n", pDirent->d_name);
	        	else if (pDirent->d_type == DT_LNK)
		            ft_printf("Link: %s\n", pDirent->d_name);
	        }
			closedir(pDir);
		}
		else
			ft_printf("Impossible d'ouvrir le repertoire courrant.");
	}

	return (0);
}