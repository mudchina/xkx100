// map.c
inherit F_CLEAN_UP;


#include "ansi.h"
#include "/doc/help.h"


string clean_color(string arg);
string make_color(string map);
string *dirs = ({
	"north",
	"south",
	"east",
	"west",
	"northup",
	"southup",
	"eastup",
	"westup",
	"northdown",
	"southdown",
	"eastdown",
	"westdown",
	"northeast",
	"northwest",
	"southeast",
	"southwest",
	"up",
	"down",
	"enter",
	"out",
});
int main(object me, string arg)
{
	int i, j, jj = 0, k, kk = 0;
	string file,map,name,dest,*search;
	mapping exit1, exit2, exit3;
	object room1, room2, room3, room4;

	seteuid(getuid());
	if (!arg || arg == "here")
	{
		if( !file = environment(me)->query("outdoors"))
		{
			room1 = environment(me);
			if( mapp(exit1 = room1->query("exits")))
			{
				for (i=0; i<sizeof(dirs); i++)
				{
					if(dest = exit1[dirs[i]])
					{
						if(!(room2 = find_object(dest)))
							room2=load_object(dest);
						if(file=room2->query("outdoors"))
							break;
						else
						{
							if( mapp(exit2 = room2->query("exits")))
							{
								for (j=0; j<sizeof(dirs); j++)
								{
									if(dest = exit2[dirs[j]])
									{
										if(!( room3 = find_object(dest)) )
											room3 = load_object(dest);
										if( file = room3->query("outdoors"))
										{
											jj = 1;
											break; 
										}
										else
											if( mapp(exit3 = room3->query("exits")))
											{
												for (k=0; k<sizeof(dirs); k++)
												{
													if(dest = exit3[dirs[k]])
													{
														if(!( room4 = find_object(dest)) )
															room4 = load_object(dest);
														if( file = room4->query("outdoors"))
														{
															kk = 1;
															break; 
														}
													}
												}
											}
										if (kk == 1)
										{
											jj = 1;
											break;
										}
									}
								}
							}
						}
						if (jj == 1) break;
					}
				}
			}
			if (i==sizeof(dirs))
				return notify_fail(HIG"这里不能查看地图，请到室外。\n"NOR);
		}
		name = clean_color(environment(me)->query("short"));
		if( file_size("/doc/map/" + file)>0 ) 
		{
			if(stringp(map = read_file("/doc/map/" + file)))
			{
				map = make_color(map);
				map = replace_string(map, name, HIR+name+NOR);
				me->start_more(map);
				return 1;
			}
		}
		return notify_fail(HIY"暂时还没有开放这里的地图查询。\n"NOR);
	}
	else
	{
		if( file_size("/doc/map/" + arg)>0 ) 
		{
			if(stringp(map = read_file("/doc/map/" + arg)))
			{
				map = make_color(map);
				me->start_more(map);
				return 1;
			}
		}
		return notify_fail(HIR"没有你指定的地图查询。请map map查询地图册。\n"NOR);
	}
}
string clean_color(string arg)
{
	if(!arg) return "";
	arg = replace_string(arg, BLK, "");
	arg = replace_string(arg, RED, "");
	arg = replace_string(arg, GRN, "");
	arg = replace_string(arg, YEL, "");
	arg = replace_string(arg, BLU, "");
	arg = replace_string(arg, MAG, "");
	arg = replace_string(arg, CYN, "");
	arg = replace_string(arg, WHT, "");
	arg = replace_string(arg, HIR, "");
	arg = replace_string(arg, HIG, "");
	arg = replace_string(arg, HIY, "");
	arg = replace_string(arg, HIB, "");
	arg = replace_string(arg, HIM, "");
	arg = replace_string(arg, HIC, "");
	arg = replace_string(arg, HIW, "");
	arg = replace_string(arg, NOR, "");
	arg = replace_string(arg, BLINK,"");
	return arg;
}

string make_color(string map)
{
	map = replace_string(map, "★", HIR"★"NOR);
	map = replace_string(map, "≈", HIC"≈"NOR);
	map = replace_string(map, "～", HIC"～"NOR);
	map = replace_string(map, "∧", HIG"∧"NOR);
	map = replace_string(map, "ψ", GRN"ψ"NOR);
	map = replace_string(map, "♀", HIR"♀"NOR);
	map = replace_string(map, "±", HIM"±"NOR);
	map = replace_string(map, "＋", HIG"＋"NOR);
	map = replace_string(map, "∴", YEL"∴"NOR);
	map = replace_string(map, "∷", YEL"∷"NOR);
	map = replace_string(map, "≌", HIW"≌"NOR);
	map = replace_string(map, "＊", MAG"＊"NOR);
	map = replace_string(map, "—", HIY"—"NOR);
	map = replace_string(map, "｜", HIY"｜"NOR);
	map = replace_string(map, "＼", HIY"＼"NOR);
	map = replace_string(map, "／", HIY"／"NOR);
	map = replace_string(map, "↑", HIY"↑"NOR);
	map = replace_string(map, "↓", HIY"↓"NOR);
	map = replace_string(map, "→", HIY"→"NOR);
	map = replace_string(map, "←", HIY"←"NOR);
	map = replace_string(map, "─", HIY"─"NOR);
	map = replace_string(map, "│", HIY"│"NOR);
	map = replace_string(map, "┼", HIY"┼"NOR);
	map = replace_string(map, "┌", HIY"┌"NOR);
	map = replace_string(map, "┐", HIY"┐"NOR);
	map = replace_string(map, "└", HIY"└"NOR);
	map = replace_string(map, "┘", HIY"┘"NOR);
	map = replace_string(map, "┬", HIY"┬"NOR);
	map = replace_string(map, "┴", HIY"┴"NOR);
	map = replace_string(map, "├", HIY"├"NOR);
	map = replace_string(map, "┤", HIY"┤"NOR);
	map = replace_string(map, "-", HIY"-"NOR);
	map = replace_string(map, "~", HIC"~"NOR);
	map = replace_string(map, "|", HIC"|"NOR);
	map = replace_string(map, "@", HIW"@"NOR);
	map = replace_string(map, "*", GRN"@"NOR);
	map = replace_string(map, "<", GRN"<");
	map = replace_string(map, ">", ">"NOR);
	map = replace_string(map, "【", YEL"【");
	map = replace_string(map, "】", "】"NOR);
	map = replace_string(map, "〖", CYN"〖"NOR);
	map = replace_string(map, "〗", CYN"〗"NOR);
	return map;
}

int help(object me)
{
	write(@HELP
指令格式：map <参量>

    这个指令用来显示指定的地图。地图册，请用map map查询。
    不带参数或带的参数是here，则显示你所在地的地图。亮红色表示你所
处之地。

HELP
	);
	return 1;
}

