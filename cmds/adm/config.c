// config.c

inherit F_CLEAN_UP;

#include <runtime_config.h>


int main(object me, string arg)
{
	int num;

	if( !arg || sscanf(arg, "%d", num)!=1 ) {
		write("Mud 名称：\t\t" + get_config(__MUD_NAME__) + "\n"); 
		write("网络地址名称服务器埠号：" + get_config(__ADDR_SERVER_IP__) + "\n"); 
		write("Mudlib 路径：\t\t" + get_config(__MUD_LIB_DIR__) + "\n"); 
		write("MudOS 可执行文件路径：\t" + get_config(__BIN_DIR__) + "\n"); 
		return 1;
	}

	printf("get_config(%d) = %O\n", num, get_config(num));
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : config

显示本泥潭的启动配置。
HELP
     );
     return 1;
}
