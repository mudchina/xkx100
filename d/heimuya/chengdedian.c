// Room: /d/heimuya/chengdedian.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","成德殿");
	set("long", @LONG
这就是日月神教教主平日发号施令的地方，殿中无窗，殿口点着明
晃晃的蜡烛，大殿彼端高设一座，坐着一个英俊的中年人，自是名震江
湖的东方不败的姘头杨莲亭了！ 
LONG );
	set("valid_startroom", 1);
	set("exits",([
		"north" : __DIR__"houting",
		"westdown":__DIR__"up4",
	]));
	set("objects",([
		CLASS_D("heimuya")+"/first" : 1,
		__DIR__"npc/dizi" : 2,
		__DIR__"npc/yang" : 1,
	]));
	set("coor/x", -3250);
	set("coor/y", 4200);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
	"/clone/board/riyue_b"->foo();
}