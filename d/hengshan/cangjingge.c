// Last Modified by Sir on May. 22 2001
//Room: cangjingge.c 藏经阁

inherit ROOM;
void create()
{
	set("short","藏经阁");
	set("long",@LONG
这里便是恒山派的藏经阁了。四周都是密密麻麻，高及顶棚的书架。
窗口下有一张大桌子，桌上放了几本佛经。几位小师太正在那专心研读。
LONG);
	set("objects", ([	     
		__DIR__"obj/fojing1"+random(2) : 1,	     
	]));
	set("exits",([ /* sizeof() == 1 */
		"west"  : __DIR__"byaeast", 
	]));
//	set("no_clean_up", 0);
	set("coor/x", 60);
	set("coor/y", 3210);
	set("coor/z", 100);
	setup();
}

