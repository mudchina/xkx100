// Room: nanheqiaow.c
// Date: Feb.14 1998 by Java
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;
void create()
{
	set("short","南河桥");
	set("long",@LONG
这里是成都西门外南河桥。府河和南河夹城流过，呵护着这个天
府之国的首府之地。河水清新碧透。
LONG);
	set("outdoors", "chengdu");
	set("exits",([ /* sizeof() == 1 */	    
		"east" : __DIR__"westgate",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8100);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

