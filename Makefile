all: *.c *.h
	gcc main.c cd_func.c echo_func.c find_func.c location_func.c ls_func.c pinfo_func.c prompt_func.c pwd_func.c relative_path_func.c syscmnds_func.c history_func.c add_to_history.c pipe_func.c setenv_func.c unsetenv_func.c jobs_func.c kjobs_func.c bg_func.c fg_func.c overkill_func.c quit_func.c cronjob_func.c -lreadline
	

