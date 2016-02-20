// wg_shufang.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
这是武馆馆主的书房，房内很静，几缕阳光从窗外的绿荫中直射进
来，屋内靠窗放着一个大书架，显然都是些主人常看的书。墙上高悬着
几个大字“少壮不努力，老大徒伤悲”。
LONG);
	set("exits", ([
		"north" : __DIR__"wg_lang5",
	]));
	set("objects", ([
		__DIR__"npc/wg_lingxiaodizi" : 1,					
	]));	
	set("coor/x", 31);
	set("coor/y", -50);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
