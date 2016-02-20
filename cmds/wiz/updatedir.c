// updatedir.c 
inherit F_CLEAN_UP;

#include "/doc/help.h" 

 
int updatefile(object me,string file); 
int main(object me, string arg) 
{ 
	int i, j; 
	string dir; 
	mixed *file; 

	seteuid( geteuid(me) ); 

	dir = resolve_path(me->query("cwd"), arg); 
	if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/"; 
	file = get_dir(dir, -1); 
	if( !sizeof(file) ) 
	{
		if (file_size(dir) == -2) return notify_fail("目录是空的。\n"); 
		else return notify_fail("没有这个目录。\n"); 
	}
	i = sizeof(file); 
	while(i--)
	{ 
		if (file[i][1]==-2) file[i][0] += "/"; 
	} 
	write("目录：" + dir + "\n"); 

	if (sizeof(file)) 
		for(i=0, j = sizeof(file); i<j; i++) 
		{ 
		       	if (file[i][1]!=-2 && sscanf(file[i][0], "%*s.c")  
       				&& file[i][0][strlen(file[i][0])-1]=="c"[0] 
				&& file[i][0][strlen(file[i][0])-2]=="."[0]) 
				updatefile(me,dir+file[i][0]);  
			else
				if (file[i][1]==-2)
				call_other(__FILE__,"main", me,dir+file[i][0]); 
		} 
	else write("没有任何档案。\n"); 
	write("\n"); 

	return 1; 
} 

int updatefile(object me,string file) 
{ 
	object obj,*inv; 
	int i; 
	string err; 
	me->set("cwf", file); 

	if (obj = find_object(file))
	{
		if( obj==environment(me) )
		{
			if( file_name(obj)==VOID_OB ) 
				return notify_fail("你不能在 VOID_OB 里重新编译 VOID_OB。\n"); 
			inv = all_inventory(obj); 
			i = sizeof(inv); 
			while(i--) 
				if( userp(inv[i]) ) inv[i]->move(VOID_OB, 1); 
				else inv[i] = 0; 
		} 
		destruct(obj); 
	}
	if (obj) return notify_fail("无法清除旧程式码。\n"); 

	write("重新编译 " + file + "："); 
	err = catch( call_other(file, "???") ); 
	if (err) 
		printf( "发生错误：\n%s\n", err ); 
	else { 
		write("成功！\n"); 
	}
	if( (i=sizeof(inv)) && (obj = find_object(file)))
	{
		while(i--) 
		{
			if( inv[i] && userp(inv[i]) ) inv[i]->move(obj, 1); 
		} 
	} 
} 

int help(object me) 
{ 
write(@HELP 
指令格式: updatedir [<路径名>] 
  
将目录下所有的子目录及档案, 如果没有指定目录, 则使用当前目录。

  
范例: 
'updatedir /adm' 会将所有位於根/adm目录下的档案编译更新. 
  
HELP 
); 
return 1; 
} 

