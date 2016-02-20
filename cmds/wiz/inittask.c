inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int hard;

	if (!sscanf(arg, "%d", hard))
		hard = 0;
	else
		hard = 1;

	TASK_D->init_dynamic_quest(hard);
	return 1;
}

