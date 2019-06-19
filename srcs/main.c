/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:47:41 by srossi            #+#    #+#             */
/*   Updated: 2019/06/19 13:55:00 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_md5.h"

int ft_check_command(char *command){

    if (ft_strcmp(command, "md5") == 0){
        ft_printf("Command is OK: %s\n", command);
        return (0);
    }

    ft_printf("Wrong command: %s\n", command);
    return (-1);
    //Check command and set command to info
}

//void ft_get_options(int argc, char **argv){
//    int i;
//
//    i = 1;
//    while (i < argc && argv[i][0] == '-'){
//        ft_printf("Option : %s\n", argv[i]);
//        //deconstruire pour avoir plusieurs options en une fois
//        i++;
//    }
//}

void ft_get_command_args(char *argv, t_info *info){
//    if (info->i == argc){
//        ft_printf("Pas de fichier ou de string, lire entree clavier\n");
//    }
    ft_printf("argv recu: %s", argv);
    if (info->options & OPT_STRING){
        ft_printf("L'argument doit etre une string car option -s\n");
    }
    else{
        ft_printf("L'argument doit etre un fichier\n");
        ft_printf("Essayer d'ouvrir le fichier\n");
    }

}

int	main(int argc, char **argv)
{
	t_info	info;
	char	*tab[argc];
	int i;

    i = 0;
	ft_bzero(&info, sizeof(t_info));
	ft_bzero(&tab, sizeof(tab));

	if (argc == 1 || ft_check_command(argv[1]) != 0)
		    ft_print_usage();
	else
	{
        if (argc > 2){
            while (i < argc){
                ft_printf("%s\n", argv[i]);

                if (info.options & OPT_STRING){
                    ft_printf("string : %s\n", argv[i]);
                    info.options = info.options ^ OPT_STRING;
                }
                if (argv[i][0] == '-'){
                    if (ft_strlen(argv[i]) == 2)
                        ft_get_options(argv[i][1], &info);
                    else
                        ft_error_option()
                }


//                if (ft_strcmp(argv[i], "-s") == 0){
//                    info.options = info.options | OPT_STRING;
//                }

                i++;
            }

//                ft_get_command_args(argv[argc - 1], &info);
            //si -s il faut une string
            //sinon : si element
        }




//	    while (++i < argc){
//            if (argv[i][0] == '-')
//                ft_printf("option : %s\n", argv[i]);
//	        else
//	            ft_printf("arg : %s\n", argv[i]);
//
//	    }

//		info.f_error = ft_check_argv_all(argc, &argv[info.index_i]);
//		while (info.index_i < argc && argv[info.index_i][0] == '-')
//			ft_get_options(argv[info.index_i++], &info);
//		if (info.index_i == argc)
//			ft_list_current_dir(&info, argv);
//		else
//			ft_list_dirs(&info, argc, argv, tab);
	}
	//ft_del_char_tab(tab);
	//ft_print_buff(info.buff);
	//ft_strdel(&info.full_path);
	return (0);
}
